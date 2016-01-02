
#ifndef GPUMOND_LOGGING_H_INCLUDED
#define GPUMOND_LOGGING_H_INCLUDED 1

#include "config.h"
#include "platform.h"

struct Gpumond_Allocator;

struct Gpumond_Logging
{
	char				buf[GPUMOND_LOGGING_MAX_LINE_LEN];

	struct Gpumond_Logging_Ops	*ops;
};

struct Gpumond_Logging_Ops
{
	SInt32				(*error)(struct Gpumond_Logging *self,
					         const char *file, 
					         const char *func, 
					         SInt32 line, 
					         const char *fmt, ...);
	SInt32				(*warn )(struct Gpumond_Logging *self,
					         const char *file, 
					         const char *func, 
					         SInt32 line, 
					         const char *fmt, ...);
	SInt32				(*log  )(struct Gpumond_Logging *self,
					         const char *file, 
					         const char *func, 
					         SInt32 line, 
					         const char *fmt, ...);
	SInt32				(*debug)(struct Gpumond_Logging *self,
					         const char *file, 
					         const char *func, 
					         SInt32 line, 
					         const char *fmt, ...);
};

#define GPUMOND_LOGGING_ERROR(SELF, FMT, ...) \
		(SELF)->ops->error((SELF), __FILE__, __func__, __LINE__, FMT, ## __VA_ARGS__)
#define GPUMOND_LOGGING_WARN(SELF, FMT, ...) \
		(SELF)->ops->warn((SELF), __FILE__, __func__, __LINE__, FMT, ## __VA_ARGS__)
#define GPUMOND_LOGGING_LOG(SELF, FMT, ...) \
		(SELF)->ops->log((SELF), __FILE__, __func__, __LINE__, FMT, ## __VA_ARGS__)
#define GPUMOND_LOGGING_DEBUG(SELF, FMT, ...) \
		(SELF)->ops->debug((SELF), __FILE__, __func__, __LINE__, FMT, ## __VA_ARGS__)

struct Gpumond_File_Logging
{
	struct Gpumond_Logging		base;

					/* Allocator used to allocate the memory
					 * for this instance.
					 */
	struct Gpumond_Allocator	*alloc;

	SInt32				fd;

	char				buf[GPUMOND_LOGGING_MAX_LINE_LEN];
};

/* Log to the file.
 */
struct Gpumond_Logging *File_Logging(struct Gpumond_Allocator *alloc, SInt32 fd);

/* Log via syslog.
 */
struct Gpumond_Logging *Syslog_Logging();

#endif

