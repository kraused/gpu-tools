
/* nvutil008: Version of nvutil005 that only disables application clock restrictions.
 */

#include <stdio.h>

#include "common.h"

int main(int argc, char **argv)
{
	unsigned int count;
	unsigned int i;
	nvmlDevice_t device;
	nvmlEnableState_t enabled;

#ifndef NDEBUG
	nvml_return_handler = Nvml_Debug_Return_Handler;
#endif

	Nvml_Init();

	Nvml_DeviceGetCount(&count);
	fprintf(stdout, "device count                            : %d\n", (int )count);

	for (i = 0; i < count; ++i) {
		Nvml_DeviceGetHandleByIndex(i, &device);

		Nvml_DeviceSetAPIRestriction(device, NVML_RESTRICTED_API_SET_APPLICATION_CLOCKS, NVML_FEATURE_DISABLED);

		Nvml_DeviceGetAPIRestriction(device, NVML_RESTRICTED_API_SET_APPLICATION_CLOCKS, &enabled);
		fprintf(stdout, "device %d application clock restrictions : %s\n", i, Nvml_Convert_EnableState(enabled));
	}

	Nvml_Shutdown();
	return 0;
}

