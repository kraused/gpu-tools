
/* nvutil003: Check whether ECC is enabled for devices.
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
	nvmlEnableState_t current, pending;

#ifndef NDEBUG
	nvml_return_handler = Nvml_Debug_Return_Handler;
#endif

	Nvml_Init();

	Nvml_DeviceGetCount(&count);
	fprintf(stdout, "device count             : %d\n", (int )count);

	for (i = 0; i < count; ++i) {
		Nvml_DeviceGetHandleByIndex(i, &device);

		Nvml_DeviceGetEccMode(device, &current, &pending);
		fprintf(stdout, "device %d current ECC mode: %s\n", i, Nvml_Convert_EnableState(current));
		fprintf(stdout, "device %d current ECC mode: %s\n", i, Nvml_Convert_EnableState(pending));
	}

	Nvml_Shutdown();
	return 0;
}

