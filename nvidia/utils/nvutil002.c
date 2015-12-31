
/* nvutil002: Reset application clocks and enable auto boost.
 */

#include <stdio.h>

#include "common.h"

struct
{
	char	driver[NVML_SYSTEM_DRIVER_VERSION_BUFFER_SIZE];
	char	nvml[NVML_SYSTEM_DRIVER_VERSION_BUFFER_SIZE];
} _versions;

int main(int argc, char **argv)
{
	unsigned int count;
	unsigned int i;
	nvmlDevice_t device;

#ifndef NDEBUG
	nvml_return_handler = Nvml_Debug_Return_Handler;
#endif

	Nvml_Init();

	Nvml_DeviceGetCount(&count);
	fprintf(stdout, "device count: %d\n", (int )count);

	for (i = 0; i < count; ++i) {
		Nvml_DeviceGetHandleByIndex(i, &device);

		Nvml_DeviceResetApplicationsClocks(device);
		Nvml_DeviceSetAutoBoostedClocksEnabled(device, NVML_FEATURE_ENABLED);
	}

	Nvml_Shutdown();
	return 0;
}

