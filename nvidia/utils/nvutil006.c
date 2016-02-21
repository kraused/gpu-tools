
/* nvutil006: Query Inforom configuration checksum for devices.
 */

#include <stdio.h>

#include "common.h"

int main(int argc, char **argv)
{
	unsigned int count;
	unsigned int i;
	nvmlDevice_t device;
	unsigned int checksum;

#ifndef NDEBUG
	nvml_return_handler = Nvml_Debug_Return_Handler;
#endif

	Nvml_Init();

	Nvml_DeviceGetCount(&count);
	fprintf(stdout, "device count                    : %d\n", (int )count);

	for (i = 0; i < count; ++i) {
		Nvml_DeviceGetHandleByIndex(i, &device);

		Nvml_DeviceGetInforomConfigurationChecksum(device, &checksum);
		fprintf(stdout, "device %d inforom config checksum: %u\n", i, checksum);
	}

	Nvml_Shutdown();
	return 0;
}

