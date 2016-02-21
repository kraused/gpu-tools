
/* nvutil007: Query memory error counters.
 */

#include <stdio.h>

#include "common.h"

#undef  _
#define _(X)	{X, #X}

static struct { int i; const char *s; } errors[] = 
{
	_(NVML_MEMORY_ERROR_TYPE_CORRECTED),
	_(NVML_MEMORY_ERROR_TYPE_UNCORRECTED),
	{0, NULL}
};

static struct { int i; const char *s; } locations[] = 
{
	_(NVML_MEMORY_LOCATION_L1_CACHE),
	_(NVML_MEMORY_LOCATION_L2_CACHE),
	_(NVML_MEMORY_LOCATION_DEVICE_MEMORY),
	_(NVML_MEMORY_LOCATION_REGISTER_FILE),
	_(NVML_MEMORY_LOCATION_TEXTURE_MEMORY),
	{0, NULL};
}

int main(int argc, char **argv)
{
	unsigned int count;
	unsigned int i;
	nvmlDevice_t device;
	unsigned long long count;
	int j, k;

#ifndef NDEBUG
	nvml_return_handler = Nvml_Debug_Return_Handler;
#endif

	Nvml_Init();

	Nvml_DeviceGetCount(&count);
	fprintf(stdout, "device count             : %d\n", (int )count);

	for (i = 0; i < count; ++i) {
		Nvml_DeviceGetHandleByIndex(i, &device);

		for (j = 0; errors[j].s; ++j) {
			for (k = 0; locations[k].s; ++k) {
				Nvml_DeviceGetMemoryErrorCounter(device, errors[j].i, NVML_VOLATILE_ECC, locations[k].i, &count);
				fprintf(stdout, "device %d current (volatile) %s count at %s: %lld\n", i, errors[j].s, locations[k].s, count);
			}
		}
	}

	Nvml_Shutdown();
	return 0;
}

