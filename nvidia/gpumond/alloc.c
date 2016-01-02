
#include <stdlib.h>

#include "alloc.h"

static void *_Libc_Allocator_Alloc(struct Gpumond_Allocator *self,
                                   void *ptr,
                                   SInt64 osize,
                                   SInt64 nsize,
                                   const char *file,
                                   const char *func,
                                   SInt32 line,
                                   const char *fmt, ...)
{
	if (0 == nsize) {
		free(ptr);
		return NULL;
	}

	return realloc(ptr, nsize);
}

static struct Gpumond_Allocator_Ops _libc_allocator_ops = {
	.alloc = _Libc_Allocator_Alloc
};

static struct Gpumond_Allocator _libc_allocator = {
	.ops = &_libc_allocator_ops
};

struct Gpumond_Allocator *Libc_Allocator()
{
	return &_libc_allocator;
}

