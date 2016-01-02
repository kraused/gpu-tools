
#ifndef GPUMOND_HELPER_H_INCLUDED
#define GPUMOND_HELPER_H_INCLUDED 1

#include "config.h"
#include "platform.h"

enum
{
	GPUMOND_SYSLOG_ERROR,
	GPUMOND_SYSLOG_WARN,
	GPUMOND_SYSLOG_LOG,
	GPUMOND_SYSLOG_DEBUG
};

SInt32 Gpumond_Syslog_Open();
SInt32 Gpumond_Syslog_Close();
SInt32 Gpumond_Syslog_Write(SInt32 level, const char *fmt, ...);

/* Wrapper around write(2) that repeates until the complete buffer is
 * written (as long as no error occurs in the meantime). In case of an
 * error -errno is returned.
 * The function handles EINTR but not EAGAIN.
 */
SInt32 Gpumond_Write(SInt32 fd, const void *buf, SInt64 count);

#endif

