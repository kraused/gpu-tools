
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "logging.h"
#include "helper.h"
#include "alloc.h"

const char _file_logging_format_error[] = "Internal error: formatting bug";

static SInt32 _Logging_Print(struct Gpumond_Logging *self,
                          const char *file,
                          const char *func,
                          SInt32 line,
                          const char *fmt,
                          va_list vl)
{
	SInt32 err;
	SInt64 n;

	n   = sizeof(self->buf);
	err = vsnprintf(self->buf, n, fmt, vl);
	if (UNLIKELY(err < 0)) {
		snprintf(self->buf, n, "%s", _file_logging_format_error);
		return -1;
	} 
	if (UNLIKELY(err >= n)) {
		self->buf[n - 1] = 0;
		self->buf[n - 2] = '.';
		self->buf[n - 3] = '.';
		self->buf[n - 4] = '.';
	}

	return 0;
}

static SInt32 _File_Logging_Print(struct Gpumond_File_Logging *self,
                               const char *prefix,
                               const char *file,
                               const char *func,
                               SInt32 line,
                               const char *fmt,
                               va_list vl)
{
	SInt32 err;
	SInt64 n;

	err = _Logging_Print(&self->base, file, func, line, fmt, vl); 
	if (UNLIKELY(err < 0)) {
		Gpumond_Write(self->fd, self->base.buf, strlen(self->base.buf));
		return -1;
	} 

	n   = sizeof(self->buf);
	err = snprintf(self->buf, n, "<%s(), %s:%d> %s%s\n", func, file, line, prefix, self->base.buf);
	if (UNLIKELY(err < 0)) {
		Gpumond_Write(self->fd, _file_logging_format_error, strlen(_file_logging_format_error));
		return -1;
	} 
	if (UNLIKELY(err >= n)) {
		self->buf[n - 1] = 0;
		self->buf[n - 2] = '.';
		self->buf[n - 3] = '.';
		self->buf[n - 4] = '.';
	}

	return Gpumond_Write(self->fd, self->buf, strlen(self->buf));
}

static SInt32 _File_Logging_Error(struct Gpumond_Logging *base, 
                                  const char *file, 
                                  const char *func, 
                                  SInt32 line, 
                                  const char *fmt, ...)
{
	va_list vl;
	SInt32 err;
	struct Gpumond_File_Logging *self = (struct Gpumond_File_Logging *)base;

	va_start(vl, fmt);
	err = _File_Logging_Print(self, "Error: ", file, func, line, fmt, vl);
	va_end(vl);

	return err;
}

static SInt32 _File_Logging_Warn(struct Gpumond_Logging *base, 
                                 const char *file, 
                                 const char *func, 
                                 SInt32 line, 
                                 const char *fmt, ...)
{
	va_list vl;
	SInt32 err;
	struct Gpumond_File_Logging *self = (struct Gpumond_File_Logging *)base;

	va_start(vl, fmt);
	err = _File_Logging_Print(self, "Warn: ", file, func, line, fmt, vl);
	va_end(vl);

	return err;
}

static SInt32 _File_Logging_Log(struct Gpumond_Logging *base, 
                                const char *file, 
                                const char *func, 
                                SInt32 line, 
                                const char *fmt, ...)
{
	va_list vl;
	SInt32 err;
	struct Gpumond_File_Logging *self = (struct Gpumond_File_Logging *)base;

	va_start(vl, fmt);
	err = _File_Logging_Print(self, "Log: ", file, func, line, fmt, vl);
	va_end(vl);

	return err;
}

static SInt32 _File_Logging_Debug(struct Gpumond_Logging *base, 
                                  const char *file, 
                                  const char *func, 
                                  SInt32 line, 
                                  const char *fmt, ...)
{
	va_list vl;
	SInt32 err;
	struct Gpumond_File_Logging *self = (struct Gpumond_File_Logging *)base;

	va_start(vl, fmt);
	err = _File_Logging_Print(self, "Debug: ", file, func, line, fmt, vl);
	va_end(vl);

	return err;
}

static struct Gpumond_Logging_Ops _file_logging_ops = {
	.error = _File_Logging_Error,
	.warn  = _File_Logging_Warn,
	.log   = _File_Logging_Log,
	.debug = _File_Logging_Debug
};

static SInt32 _Syslog_Logging_Print(struct Gpumond_Logging *self,
                                    SInt32 level,
                                    const char *prefix,
                                    const char *file,
                                    const char *func,
                                    SInt32 line,
                                    const char *fmt,
                                    va_list vl)
{
	SInt32 err;

	err = _Logging_Print(self, file, func, line, fmt, vl); 
	if (UNLIKELY(err < 0)) {
		Gpumond_Syslog_Write(GPUMOND_SYSLOG_ERROR, "%s", self->buf);
		return -1;
	} 

	return Gpumond_Syslog_Write(level, "<(%s(), %s:%ld> %s%s\n", func, file, line, prefix, self->buf);
}

static SInt32 _Syslog_Logging_Error(struct Gpumond_Logging *self, 
                                    const char *file, 
                                    const char *func, 
                                    SInt32 line, 
                                    const char *fmt, ...)
{
	va_list vl;
	SInt32 err;

	va_start(vl, fmt);
	err = _Syslog_Logging_Print(self, GPUMOND_SYSLOG_ERROR, "Error: ", file, func, line, fmt, vl);
	va_end(vl);

	return err;
}

static SInt32 _Syslog_Logging_Warn(struct Gpumond_Logging *self, 
                                   const char *file, 
                                   const char *func, 
                                   SInt32 line, 
                                   const char *fmt, ...)
{
	va_list vl;
	SInt32 err;

	va_start(vl, fmt);
	err = _Syslog_Logging_Print(self, GPUMOND_SYSLOG_WARN, "Warn: ", file, func, line, fmt, vl);
	va_end(vl);

	return err;
}

static SInt32 _Syslog_Logging_Log(struct Gpumond_Logging *self, 
                                  const char *file, 
                                  const char *func, 
                                  SInt32 line, 
                                  const char *fmt, ...)
{
	va_list vl;
	SInt32 err;

	va_start(vl, fmt);
	err = _Syslog_Logging_Print(self, GPUMOND_SYSLOG_LOG, "Log: ", file, func, line, fmt, vl);
	va_end(vl);

	return err;
}

static SInt32 _Syslog_Logging_Debug(struct Gpumond_Logging *self, 
                                    const char *file, 
                                    const char *func, 
                                    SInt32 line, 
                                    const char *fmt, ...)
{
	va_list vl;
	SInt32 err;

	va_start(vl, fmt);
	err = _Syslog_Logging_Print(self, GPUMOND_SYSLOG_DEBUG, "Debug: ", file, func, line, fmt, vl);
	va_end(vl);

	return err;
}

static struct Gpumond_Logging_Ops _syslog_logging_ops = {
	.error = _Syslog_Logging_Error,
	.warn  = _Syslog_Logging_Warn,
	.log   = _Syslog_Logging_Log,
	.debug = _Syslog_Logging_Debug
};

static struct Gpumond_Logging _syslog_logging = {
	.ops = &_syslog_logging_ops
};

struct Gpumond_Logging *File_Logging(struct Gpumond_Allocator *alloc, SInt32 fd)
{
	struct Gpumond_File_Logging *self;

	self = GPUMOND_ALLOC(alloc, NULL, 0, sizeof(struct Gpumond_File_Logging), "Gpumond_File_Logging");
	if (UNLIKELY(!self))
		return NULL;	/* No way to report the error at this point. */

	memset(self, 0, sizeof(struct Gpumond_File_Logging));

	self->base.ops = &_file_logging_ops;

	self->alloc = alloc;
	self->fd    = fd;

	return (struct Gpumond_Logging *)self;
}

struct Gpumond_Logging *Syslog_Logging()
{
	return &_syslog_logging;	
}

