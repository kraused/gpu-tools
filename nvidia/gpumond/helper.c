
#include <syslog.h>
#include <unistd.h>
#include <errno.h>
#include <stdarg.h>

#include "helper.h"

SInt32 _Convert_Syslog_Level(SInt32 level)
{
	switch(level)
	{
	case GPUMOND_SYSLOG_ERROR:
		return LOG_ERR;
		break;
	case GPUMOND_SYSLOG_WARN:
		return LOG_WARNING;
		break;
	case GPUMOND_SYSLOG_LOG:
		return LOG_INFO;
		break;
	case GPUMOND_SYSLOG_DEBUG:
		return LOG_DEBUG;
		break;
	}
		
	return LOG_ERR;
}

/* Todo: Directly connect to /dev/log (Unix domain socket, SOCK_DGRAM) instead of using the
 *       glibc syslog interface.
 */

SInt32 Gpumond_Syslog_Open()
{
	openlog(GPUMOND_SYSLOG_IDENT, LOG_NDELAY | LOG_PID, LOG_DAEMON);
	/* No error code.
	 */
	return 0;
}

SInt32 Gpumond_Syslog_Close()
{
	closelog();
	/* No error code.
	 */
	return 0;
}

SInt32 Gpumond_Syslog_Write(SInt32 level, const char *fmt, ...)
{
	va_list vl;

	va_start(vl, fmt);
	vsyslog(LOG_DAEMON | _Convert_Syslog_Level(level), fmt, vl);
	va_end(vl);
	/* No error code.
	 */
	return 0;
}

SInt32 Gpumond_Write(int fd, const void *buf, SInt64 count)
{
	SInt64 err;

	while (count > 0) {
		err = write(fd, buf, count);
		if (UNLIKELY(err < 0)) {
			if (UNLIKELY(EINTR == errno))
				continue;

			return -errno;
		}

		buf   += err;
		count -= err;
	}

	return 0;
}

