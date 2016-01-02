
#ifndef GPUMOND_OUTPUT_H_INCLUDED
#define GPUMOND_OUTPUT_H_INCLUDED 1

#include "config.h"
#include "platform.h"

struct Gpumond_Allocator;
struct Gpumond_Logging;

struct Gpumond_Output
{
	struct Gpumond_Output_Ops	*ops;
};

struct Gpumond_Output_Ops
{
	SInt32				(*write)(struct Gpumond_Output *self, 
					         const char *file, 
					         const char *func, 
					         SInt32 line, 
					         const char *buf, SInt64 len);
};

#define GPUMOND_OUTPUT_WRITE(SELF, BUF, LEN) \
		(SELF)->ops->write((SELF), __FILE__, __func__, __LINE__, BUF, LEN)

struct Gpumond_File_Output
{
	struct Gpumond_Output		base;
	
					/* Allocator used to allocate the memory
					 * for this instance.
					 */
	struct Gpumond_Allocator	*alloc;

	char				path[PATH_MAX];
	int				fd;
};

/* Output to a file.
 */
struct Gpumond_Output *File_Output(struct Gpumond_Allocator *alloc, 
                                   struct Gpumond_Logging *logging,
                                   const char *path);

/* Output via syslog.
 * Due to the glibc syslog interface this returns a singleton instance.
 */
struct Gpumond_Output *Syslog_Output();

#endif

