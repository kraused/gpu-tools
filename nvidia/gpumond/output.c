
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "output.h"
#include "helper.h"
#include "alloc.h"
#include "logging.h"

static SInt32 _File_Output_Write(struct Gpumond_Output *base,
                                 const char *file,
                                 const char *func,
                                 SInt32 line,
                                 const char *buf, SInt64 len)
{
	struct Gpumond_File_Output *self = (struct Gpumond_File_Output *)base;

	return Gpumond_Write(self->fd, buf, len);
}

static struct Gpumond_Output_Ops _file_output_ops = {
	.write = _File_Output_Write
};

struct Gpumond_Output *File_Output(struct Gpumond_Allocator *alloc,
                                   struct Gpumond_Logging *logging,
                                   const char *path)
{
	struct Gpumond_File_Output *self;
	SInt32 err;

	self = GPUMOND_ALLOC(alloc, NULL, 0, sizeof(struct Gpumond_File_Output), "Gpumond_File_Output");
	if (UNLIKELY(!self)) {
		GPUMOND_LOGGING_ERROR(logging, "Memory allocation failed.");
		return NULL;
	}

	memset(self, 0, sizeof(struct Gpumond_File_Output));

	self->base.ops = &_file_output_ops;

	self->alloc = alloc;

	err = snprintf(self->path, PATH_MAX, "%s", path);
	if (UNLIKELY((err < 0) || (err >= PATH_MAX))) {
		GPUMOND_LOGGING_ERROR(logging, "snprintf() failed: path truncated");
	}

	if (!strncmp(self->path, "-", PATH_MAX)) {
		self->fd = STDOUT_FILENO;
	} else {
		self->fd = open(self->path, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	}

	if (UNLIKELY(self->fd < 0)) {
		GPUMOND_LOGGING_ERROR(logging, "open() failed with errno %d: %s", errno, strerror(errno));
		goto fail;
	}

	return (struct Gpumond_Output *)self;

fail:
	return GPUMOND_ALLOC(alloc, self, sizeof(struct Gpumond_File_Output), 0, "Gpumond_File_Output");
}

static SInt32 _Syslog_Output_Write(struct Gpumond_Output *self,
                                   const char *file,
                                   const char *func,
                                   SInt32 line,
                                   const char *buf, SInt64 len)
{
	return Gpumond_Syslog_Write(GPUMOND_SYSLOG_LOG, "%*s", len, buf);
}

static struct Gpumond_Output_Ops _syslog_output_ops = {
	.write = _Syslog_Output_Write
};

static struct Gpumond_Output _syslog_output = {
	.ops = &_syslog_output_ops
};

struct Gpumond_Output *Syslog_Output()
{
	return &_syslog_output;
}

