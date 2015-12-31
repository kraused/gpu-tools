
/* nvutil001: Report driver and NVML version.
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
#ifndef NDEBUG
	nvml_return_handler = Nvml_Debug_Return_Handler;
#endif

	Nvml_Init();

	Nvml_SystemGetDriverVersion(_versions.driver, NVML_SYSTEM_DRIVER_VERSION_BUFFER_SIZE);
	Nvml_SystemGetNVMLVersion(_versions.nvml, NVML_SYSTEM_DRIVER_VERSION_BUFFER_SIZE);

	fprintf(stdout, "driver version: %s\n", _versions.driver);
	fprintf(stdout, "NVML   version: %s\n", _versions.nvml);

	Nvml_Shutdown();
	return 0;
}

