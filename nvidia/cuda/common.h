
#ifndef NVIDIA_CUDA_COMMON_H_INCLUDED
#define NVIDIA_CUDA_COMMON_H_INCLUDED 1

#include <linux/limits.h>
#include <stdint.h>

#define LIKELY(x)       __builtin_expect(!!(x), 1)
#define UNLIKELY(x)     __builtin_expect(!!(x), 0)

typedef	uint8_t		UInt8;
typedef  int8_t 	SInt8;

typedef	uint16_t	UInt16;
typedef  int16_t 	SInt16;

typedef	uint32_t	UInt32;
typedef  int32_t 	SInt32;

typedef	uint64_t	UInt64;
typedef  int64_t 	SInt64;

#endif

