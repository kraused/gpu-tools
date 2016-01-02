
#ifndef GPUMOND_ALLOC_H_INCLUDED
#define GPUMOND_ALLOC_H_INCLUDED 1

#include "config.h"
#include "platform.h"

struct Gpumond_Allocator
{
	struct Gpumond_Allocator_Ops	*ops;
};

struct Gpumond_Allocator_Ops
{
	void				*(*alloc)(struct Gpumond_Allocator *self,
					          void *ptr,
					          SInt64 osize,
					          SInt64 nsize,
					          const char *file, 
					          const char *func, 
					          SInt32 line, 
					          const char *fmt, ...);
};

#define GPUMOND_ALLOC(SELF, PTR, OSIZE, NSIZE, FMT, ...)	\
		(SELF)->ops->alloc((SELF), (PTR), (OSIZE), (NSIZE), __FILE__, __func__, __LINE__, FMT, ## __VA_ARGS__)

/* Return an allocator based on libc malloc()/free()/realloc() functions.
 * This allocator is an singleton; multiple calls to Libc_Allocator return the
 * same pointer.
 */
struct Gpumond_Allocator *Libc_Allocator();

#endif

