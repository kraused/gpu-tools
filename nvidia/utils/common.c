
#include <stdio.h>
#include <unistd.h>

#include "common.h"

void Nvml_Default_Return_Handler(const char *caller,
                                 const char *callee,
                                 nvmlReturn_t err,
                                 const char *errstr)
{
	if (UNLIKELY(NVML_SUCCESS != err)) {
		fprintf(stderr, "%s: %s() returned %d: %s\n", caller, callee, (int )err, errstr);
		_exit(1);
	}
}

void Nvml_Debug_Return_Handler(const char *caller,
                               const char *callee,
                               nvmlReturn_t err,
                               const char *errstr)
{
	fprintf(stderr, "%s: %s() returned %d: %s\n", caller, callee, (int )err, errstr);
	if (UNLIKELY(NVML_SUCCESS != err)) {
		_exit(1);
	}
}

Nvml_Return_Handling_Function nvml_return_handler = Nvml_Default_Return_Handler;

const char *Nvml_Convert_EnableState(nvmlEnableState_t x)
{
	if (NVML_FEATURE_DISABLED == x) {
		return "disabled";
	}
	if (NVML_FEATURE_ENABLED  == x) {
		return "enabled";
	}

	return "(null)";
}

/* Wrapper around NVML library calls.
 *
 * Generated with python2 create.py --definitions
 */

void Nvml_DeviceClearAccountingPids(nvmlDevice_t a0)
{
	nvmlReturn_t err;
	err = nvmlDeviceClearAccountingPids(a0);
	nvml_return_handler("Nvml_DeviceClearAccountingPids", "nvmlDeviceClearAccountingPids", err, nvmlErrorString(err));
}

void Nvml_DeviceGetAccountingBufferSize(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetAccountingBufferSize(a0, a1);
	nvml_return_handler("Nvml_DeviceGetAccountingBufferSize", "nvmlDeviceGetAccountingBufferSize", err, nvmlErrorString(err));
}

void Nvml_DeviceGetAccountingMode(nvmlDevice_t a0, nvmlEnableState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetAccountingMode(a0, a1);
	nvml_return_handler("Nvml_DeviceGetAccountingMode", "nvmlDeviceGetAccountingMode", err, nvmlErrorString(err));
}

void Nvml_DeviceGetAccountingPids(nvmlDevice_t a0, unsigned int* a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetAccountingPids(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetAccountingPids", "nvmlDeviceGetAccountingPids", err, nvmlErrorString(err));
}

void Nvml_DeviceGetAccountingStats(nvmlDevice_t a0, unsigned int a1, nvmlAccountingStats_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetAccountingStats(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetAccountingStats", "nvmlDeviceGetAccountingStats", err, nvmlErrorString(err));
}

void Nvml_DeviceSetAccountingMode(nvmlDevice_t a0, nvmlEnableState_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetAccountingMode(a0, a1);
	nvml_return_handler("Nvml_DeviceSetAccountingMode", "nvmlDeviceSetAccountingMode", err, nvmlErrorString(err));
}

void Nvml_Init()
{
	nvmlReturn_t err;
	err = nvmlInit();
	nvml_return_handler("Nvml_Init", "nvmlInit", err, nvmlErrorString(err));
}

void Nvml_Shutdown()
{
	nvmlReturn_t err;
	err = nvmlShutdown();
	nvml_return_handler("Nvml_Shutdown", "nvmlShutdown", err, nvmlErrorString(err));
}

void Nvml_SystemGetDriverVersion(char* a0, unsigned int a1)
{
	nvmlReturn_t err;
	err = nvmlSystemGetDriverVersion(a0, a1);
	nvml_return_handler("Nvml_SystemGetDriverVersion", "nvmlSystemGetDriverVersion", err, nvmlErrorString(err));
}

void Nvml_SystemGetNVMLVersion(char* a0, unsigned int a1)
{
	nvmlReturn_t err;
	err = nvmlSystemGetNVMLVersion(a0, a1);
	nvml_return_handler("Nvml_SystemGetNVMLVersion", "nvmlSystemGetNVMLVersion", err, nvmlErrorString(err));
}

void Nvml_SystemGetProcessName(unsigned int a0, char* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlSystemGetProcessName(a0, a1, a2);
	nvml_return_handler("Nvml_SystemGetProcessName", "nvmlSystemGetProcessName", err, nvmlErrorString(err));
}

void Nvml_SystemGetHicVersion(unsigned int* a0, nvmlHwbcEntry_t* a1)
{
	nvmlReturn_t err;
	err = nvmlSystemGetHicVersion(a0, a1);
	nvml_return_handler("Nvml_SystemGetHicVersion", "nvmlSystemGetHicVersion", err, nvmlErrorString(err));
}

void Nvml_UnitGetCount(unsigned int* a0)
{
	nvmlReturn_t err;
	err = nvmlUnitGetCount(a0);
	nvml_return_handler("Nvml_UnitGetCount", "nvmlUnitGetCount", err, nvmlErrorString(err));
}

void Nvml_UnitGetDevices(nvmlUnit_t a0, unsigned int* a1, nvmlDevice_t* a2)
{
	nvmlReturn_t err;
	err = nvmlUnitGetDevices(a0, a1, a2);
	nvml_return_handler("Nvml_UnitGetDevices", "nvmlUnitGetDevices", err, nvmlErrorString(err));
}

void Nvml_UnitGetFanSpeedInfo(nvmlUnit_t a0, nvmlUnitFanSpeeds_t* a1)
{
	nvmlReturn_t err;
	err = nvmlUnitGetFanSpeedInfo(a0, a1);
	nvml_return_handler("Nvml_UnitGetFanSpeedInfo", "nvmlUnitGetFanSpeedInfo", err, nvmlErrorString(err));
}

void Nvml_UnitGetHandleByIndex(unsigned int a0, nvmlUnit_t* a1)
{
	nvmlReturn_t err;
	err = nvmlUnitGetHandleByIndex(a0, a1);
	nvml_return_handler("Nvml_UnitGetHandleByIndex", "nvmlUnitGetHandleByIndex", err, nvmlErrorString(err));
}

void Nvml_UnitGetLedState(nvmlUnit_t a0, nvmlLedState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlUnitGetLedState(a0, a1);
	nvml_return_handler("Nvml_UnitGetLedState", "nvmlUnitGetLedState", err, nvmlErrorString(err));
}

void Nvml_UnitGetPsuInfo(nvmlUnit_t a0, nvmlPSUInfo_t* a1)
{
	nvmlReturn_t err;
	err = nvmlUnitGetPsuInfo(a0, a1);
	nvml_return_handler("Nvml_UnitGetPsuInfo", "nvmlUnitGetPsuInfo", err, nvmlErrorString(err));
}

void Nvml_UnitGetTemperature(nvmlUnit_t a0, unsigned int a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlUnitGetTemperature(a0, a1, a2);
	nvml_return_handler("Nvml_UnitGetTemperature", "nvmlUnitGetTemperature", err, nvmlErrorString(err));
}

void Nvml_UnitGetUnitInfo(nvmlUnit_t a0, nvmlUnitInfo_t* a1)
{
	nvmlReturn_t err;
	err = nvmlUnitGetUnitInfo(a0, a1);
	nvml_return_handler("Nvml_UnitGetUnitInfo", "nvmlUnitGetUnitInfo", err, nvmlErrorString(err));
}

void Nvml_DeviceClearCpuAffinity(nvmlDevice_t a0)
{
	nvmlReturn_t err;
	err = nvmlDeviceClearCpuAffinity(a0);
	nvml_return_handler("Nvml_DeviceClearCpuAffinity", "nvmlDeviceClearCpuAffinity", err, nvmlErrorString(err));
}

void Nvml_DeviceGetAPIRestriction(nvmlDevice_t a0, nvmlRestrictedAPI_t a1, nvmlEnableState_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetAPIRestriction(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetAPIRestriction", "nvmlDeviceGetAPIRestriction", err, nvmlErrorString(err));
}

void Nvml_DeviceGetApplicationsClock(nvmlDevice_t a0, nvmlClockType_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetApplicationsClock(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetApplicationsClock", "nvmlDeviceGetApplicationsClock", err, nvmlErrorString(err));
}

void Nvml_DeviceGetAutoBoostedClocksEnabled(nvmlDevice_t a0, nvmlEnableState_t* a1, nvmlEnableState_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetAutoBoostedClocksEnabled(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetAutoBoostedClocksEnabled", "nvmlDeviceGetAutoBoostedClocksEnabled", err, nvmlErrorString(err));
}

void Nvml_DeviceGetBAR1MemoryInfo(nvmlDevice_t a0, nvmlBAR1Memory_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetBAR1MemoryInfo(a0, a1);
	nvml_return_handler("Nvml_DeviceGetBAR1MemoryInfo", "nvmlDeviceGetBAR1MemoryInfo", err, nvmlErrorString(err));
}

void Nvml_DeviceGetBoardId(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetBoardId(a0, a1);
	nvml_return_handler("Nvml_DeviceGetBoardId", "nvmlDeviceGetBoardId", err, nvmlErrorString(err));
}

void Nvml_DeviceGetBrand(nvmlDevice_t a0, nvmlBrandType_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetBrand(a0, a1);
	nvml_return_handler("Nvml_DeviceGetBrand", "nvmlDeviceGetBrand", err, nvmlErrorString(err));
}

void Nvml_DeviceGetBridgeChipInfo(nvmlDevice_t a0, nvmlBridgeChipHierarchy_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetBridgeChipInfo(a0, a1);
	nvml_return_handler("Nvml_DeviceGetBridgeChipInfo", "nvmlDeviceGetBridgeChipInfo", err, nvmlErrorString(err));
}

void Nvml_DeviceGetClockInfo(nvmlDevice_t a0, nvmlClockType_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetClockInfo(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetClockInfo", "nvmlDeviceGetClockInfo", err, nvmlErrorString(err));
}

void Nvml_DeviceGetComputeMode(nvmlDevice_t a0, nvmlComputeMode_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetComputeMode(a0, a1);
	nvml_return_handler("Nvml_DeviceGetComputeMode", "nvmlDeviceGetComputeMode", err, nvmlErrorString(err));
}

void Nvml_DeviceGetComputeRunningProcesses(nvmlDevice_t a0, unsigned int* a1, nvmlProcessInfo_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetComputeRunningProcesses(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetComputeRunningProcesses", "nvmlDeviceGetComputeRunningProcesses", err, nvmlErrorString(err));
}

void Nvml_DeviceGetCount(unsigned int* a0)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetCount(a0);
	nvml_return_handler("Nvml_DeviceGetCount", "nvmlDeviceGetCount", err, nvmlErrorString(err));
}

void Nvml_DeviceGetCpuAffinity(nvmlDevice_t a0, unsigned int a1, unsigned long* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetCpuAffinity(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetCpuAffinity", "nvmlDeviceGetCpuAffinity", err, nvmlErrorString(err));
}

void Nvml_DeviceGetCurrPcieLinkGeneration(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetCurrPcieLinkGeneration(a0, a1);
	nvml_return_handler("Nvml_DeviceGetCurrPcieLinkGeneration", "nvmlDeviceGetCurrPcieLinkGeneration", err, nvmlErrorString(err));
}

void Nvml_DeviceGetCurrPcieLinkWidth(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetCurrPcieLinkWidth(a0, a1);
	nvml_return_handler("Nvml_DeviceGetCurrPcieLinkWidth", "nvmlDeviceGetCurrPcieLinkWidth", err, nvmlErrorString(err));
}

void Nvml_DeviceGetCurrentClocksThrottleReasons(nvmlDevice_t a0, unsigned long long* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetCurrentClocksThrottleReasons(a0, a1);
	nvml_return_handler("Nvml_DeviceGetCurrentClocksThrottleReasons", "nvmlDeviceGetCurrentClocksThrottleReasons", err, nvmlErrorString(err));
}

void Nvml_DeviceGetDecoderUtilization(nvmlDevice_t a0, unsigned int* a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetDecoderUtilization(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetDecoderUtilization", "nvmlDeviceGetDecoderUtilization", err, nvmlErrorString(err));
}

void Nvml_DeviceGetDefaultApplicationsClock(nvmlDevice_t a0, nvmlClockType_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetDefaultApplicationsClock(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetDefaultApplicationsClock", "nvmlDeviceGetDefaultApplicationsClock", err, nvmlErrorString(err));
}

void Nvml_DeviceGetDetailedEccErrors(nvmlDevice_t a0, nvmlMemoryErrorType_t a1, nvmlEccCounterType_t a2, nvmlEccErrorCounts_t* a3)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetDetailedEccErrors(a0, a1, a2, a3);
	nvml_return_handler("Nvml_DeviceGetDetailedEccErrors", "nvmlDeviceGetDetailedEccErrors", err, nvmlErrorString(err));
}

void Nvml_DeviceGetDisplayActive(nvmlDevice_t a0, nvmlEnableState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetDisplayActive(a0, a1);
	nvml_return_handler("Nvml_DeviceGetDisplayActive", "nvmlDeviceGetDisplayActive", err, nvmlErrorString(err));
}

void Nvml_DeviceGetDisplayMode(nvmlDevice_t a0, nvmlEnableState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetDisplayMode(a0, a1);
	nvml_return_handler("Nvml_DeviceGetDisplayMode", "nvmlDeviceGetDisplayMode", err, nvmlErrorString(err));
}

void Nvml_DeviceGetDriverModel(nvmlDevice_t a0, nvmlDriverModel_t* a1, nvmlDriverModel_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetDriverModel(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetDriverModel", "nvmlDeviceGetDriverModel", err, nvmlErrorString(err));
}

void Nvml_DeviceGetEccMode(nvmlDevice_t a0, nvmlEnableState_t* a1, nvmlEnableState_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetEccMode(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetEccMode", "nvmlDeviceGetEccMode", err, nvmlErrorString(err));
}

void Nvml_DeviceGetEncoderUtilization(nvmlDevice_t a0, unsigned int* a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetEncoderUtilization(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetEncoderUtilization", "nvmlDeviceGetEncoderUtilization", err, nvmlErrorString(err));
}

void Nvml_DeviceGetEnforcedPowerLimit(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetEnforcedPowerLimit(a0, a1);
	nvml_return_handler("Nvml_DeviceGetEnforcedPowerLimit", "nvmlDeviceGetEnforcedPowerLimit", err, nvmlErrorString(err));
}

void Nvml_DeviceGetFanSpeed(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetFanSpeed(a0, a1);
	nvml_return_handler("Nvml_DeviceGetFanSpeed", "nvmlDeviceGetFanSpeed", err, nvmlErrorString(err));
}

void Nvml_DeviceGetGpuOperationMode(nvmlDevice_t a0, nvmlGpuOperationMode_t* a1, nvmlGpuOperationMode_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetGpuOperationMode(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetGpuOperationMode", "nvmlDeviceGetGpuOperationMode", err, nvmlErrorString(err));
}

void Nvml_DeviceGetGraphicsRunningProcesses(nvmlDevice_t a0, unsigned int* a1, nvmlProcessInfo_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetGraphicsRunningProcesses(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetGraphicsRunningProcesses", "nvmlDeviceGetGraphicsRunningProcesses", err, nvmlErrorString(err));
}

void Nvml_DeviceGetHandleByIndex(unsigned int a0, nvmlDevice_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetHandleByIndex(a0, a1);
	nvml_return_handler("Nvml_DeviceGetHandleByIndex", "nvmlDeviceGetHandleByIndex", err, nvmlErrorString(err));
}

void Nvml_DeviceGetHandleByPciBusId(const char* a0, nvmlDevice_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetHandleByPciBusId(a0, a1);
	nvml_return_handler("Nvml_DeviceGetHandleByPciBusId", "nvmlDeviceGetHandleByPciBusId", err, nvmlErrorString(err));
}

void Nvml_DeviceGetHandleBySerial(const char* a0, nvmlDevice_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetHandleBySerial(a0, a1);
	nvml_return_handler("Nvml_DeviceGetHandleBySerial", "nvmlDeviceGetHandleBySerial", err, nvmlErrorString(err));
}

void Nvml_DeviceGetHandleByUUID(const char* a0, nvmlDevice_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetHandleByUUID(a0, a1);
	nvml_return_handler("Nvml_DeviceGetHandleByUUID", "nvmlDeviceGetHandleByUUID", err, nvmlErrorString(err));
}

void Nvml_DeviceGetIndex(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetIndex(a0, a1);
	nvml_return_handler("Nvml_DeviceGetIndex", "nvmlDeviceGetIndex", err, nvmlErrorString(err));
}

void Nvml_DeviceGetInforomConfigurationChecksum(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetInforomConfigurationChecksum(a0, a1);
	nvml_return_handler("Nvml_DeviceGetInforomConfigurationChecksum", "nvmlDeviceGetInforomConfigurationChecksum", err, nvmlErrorString(err));
}

void Nvml_DeviceGetInforomImageVersion(nvmlDevice_t a0, char* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetInforomImageVersion(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetInforomImageVersion", "nvmlDeviceGetInforomImageVersion", err, nvmlErrorString(err));
}

void Nvml_DeviceGetInforomVersion(nvmlDevice_t a0, nvmlInforomObject_t a1, char* a2, unsigned int a3)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetInforomVersion(a0, a1, a2, a3);
	nvml_return_handler("Nvml_DeviceGetInforomVersion", "nvmlDeviceGetInforomVersion", err, nvmlErrorString(err));
}

void Nvml_DeviceGetMaxClockInfo(nvmlDevice_t a0, nvmlClockType_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMaxClockInfo(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetMaxClockInfo", "nvmlDeviceGetMaxClockInfo", err, nvmlErrorString(err));
}

void Nvml_DeviceGetMaxPcieLinkGeneration(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMaxPcieLinkGeneration(a0, a1);
	nvml_return_handler("Nvml_DeviceGetMaxPcieLinkGeneration", "nvmlDeviceGetMaxPcieLinkGeneration", err, nvmlErrorString(err));
}

void Nvml_DeviceGetMaxPcieLinkWidth(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMaxPcieLinkWidth(a0, a1);
	nvml_return_handler("Nvml_DeviceGetMaxPcieLinkWidth", "nvmlDeviceGetMaxPcieLinkWidth", err, nvmlErrorString(err));
}

void Nvml_DeviceGetMemoryErrorCounter(nvmlDevice_t a0, nvmlMemoryErrorType_t a1, nvmlEccCounterType_t a2, nvmlMemoryLocation_t a3, unsigned long long* a4)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMemoryErrorCounter(a0, a1, a2, a3, a4);
	nvml_return_handler("Nvml_DeviceGetMemoryErrorCounter", "nvmlDeviceGetMemoryErrorCounter", err, nvmlErrorString(err));
}

void Nvml_DeviceGetMemoryInfo(nvmlDevice_t a0, nvmlMemory_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMemoryInfo(a0, a1);
	nvml_return_handler("Nvml_DeviceGetMemoryInfo", "nvmlDeviceGetMemoryInfo", err, nvmlErrorString(err));
}

void Nvml_DeviceGetMinorNumber(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMinorNumber(a0, a1);
	nvml_return_handler("Nvml_DeviceGetMinorNumber", "nvmlDeviceGetMinorNumber", err, nvmlErrorString(err));
}

void Nvml_DeviceGetMultiGpuBoard(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMultiGpuBoard(a0, a1);
	nvml_return_handler("Nvml_DeviceGetMultiGpuBoard", "nvmlDeviceGetMultiGpuBoard", err, nvmlErrorString(err));
}

void Nvml_DeviceGetName(nvmlDevice_t a0, char* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetName(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetName", "nvmlDeviceGetName", err, nvmlErrorString(err));
}

void Nvml_DeviceGetPciInfo(nvmlDevice_t a0, nvmlPciInfo_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPciInfo(a0, a1);
	nvml_return_handler("Nvml_DeviceGetPciInfo", "nvmlDeviceGetPciInfo", err, nvmlErrorString(err));
}

void Nvml_DeviceGetPcieReplayCounter(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPcieReplayCounter(a0, a1);
	nvml_return_handler("Nvml_DeviceGetPcieReplayCounter", "nvmlDeviceGetPcieReplayCounter", err, nvmlErrorString(err));
}

void Nvml_DeviceGetPcieThroughput(nvmlDevice_t a0, nvmlPcieUtilCounter_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPcieThroughput(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetPcieThroughput", "nvmlDeviceGetPcieThroughput", err, nvmlErrorString(err));
}

void Nvml_DeviceGetPerformanceState(nvmlDevice_t a0, nvmlPstates_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPerformanceState(a0, a1);
	nvml_return_handler("Nvml_DeviceGetPerformanceState", "nvmlDeviceGetPerformanceState", err, nvmlErrorString(err));
}

void Nvml_DeviceGetPersistenceMode(nvmlDevice_t a0, nvmlEnableState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPersistenceMode(a0, a1);
	nvml_return_handler("Nvml_DeviceGetPersistenceMode", "nvmlDeviceGetPersistenceMode", err, nvmlErrorString(err));
}

void Nvml_DeviceGetPowerManagementDefaultLimit(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPowerManagementDefaultLimit(a0, a1);
	nvml_return_handler("Nvml_DeviceGetPowerManagementDefaultLimit", "nvmlDeviceGetPowerManagementDefaultLimit", err, nvmlErrorString(err));
}

void Nvml_DeviceGetPowerManagementLimit(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPowerManagementLimit(a0, a1);
	nvml_return_handler("Nvml_DeviceGetPowerManagementLimit", "nvmlDeviceGetPowerManagementLimit", err, nvmlErrorString(err));
}

void Nvml_DeviceGetPowerManagementLimitConstraints(nvmlDevice_t a0, unsigned int* a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPowerManagementLimitConstraints(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetPowerManagementLimitConstraints", "nvmlDeviceGetPowerManagementLimitConstraints", err, nvmlErrorString(err));
}

void Nvml_DeviceGetPowerManagementMode(nvmlDevice_t a0, nvmlEnableState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPowerManagementMode(a0, a1);
	nvml_return_handler("Nvml_DeviceGetPowerManagementMode", "nvmlDeviceGetPowerManagementMode", err, nvmlErrorString(err));
}

void Nvml_DeviceGetPowerState(nvmlDevice_t a0, nvmlPstates_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPowerState(a0, a1);
	nvml_return_handler("Nvml_DeviceGetPowerState", "nvmlDeviceGetPowerState", err, nvmlErrorString(err));
}

void Nvml_DeviceGetPowerUsage(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPowerUsage(a0, a1);
	nvml_return_handler("Nvml_DeviceGetPowerUsage", "nvmlDeviceGetPowerUsage", err, nvmlErrorString(err));
}

void Nvml_DeviceGetRetiredPages(nvmlDevice_t a0, nvmlPageRetirementCause_t a1, unsigned int* a2, unsigned long long* a3)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetRetiredPages(a0, a1, a2, a3);
	nvml_return_handler("Nvml_DeviceGetRetiredPages", "nvmlDeviceGetRetiredPages", err, nvmlErrorString(err));
}

void Nvml_DeviceGetRetiredPagesPendingStatus(nvmlDevice_t a0, nvmlEnableState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetRetiredPagesPendingStatus(a0, a1);
	nvml_return_handler("Nvml_DeviceGetRetiredPagesPendingStatus", "nvmlDeviceGetRetiredPagesPendingStatus", err, nvmlErrorString(err));
}

void Nvml_DeviceGetSamples(nvmlDevice_t a0, nvmlSamplingType_t a1, unsigned long long a2, nvmlValueType_t* a3, unsigned int* a4, nvmlSample_t* a5)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetSamples(a0, a1, a2, a3, a4, a5);
	nvml_return_handler("Nvml_DeviceGetSamples", "nvmlDeviceGetSamples", err, nvmlErrorString(err));
}

void Nvml_DeviceGetSerial(nvmlDevice_t a0, char* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetSerial(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetSerial", "nvmlDeviceGetSerial", err, nvmlErrorString(err));
}

void Nvml_DeviceGetSupportedClocksThrottleReasons(nvmlDevice_t a0, unsigned long long* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetSupportedClocksThrottleReasons(a0, a1);
	nvml_return_handler("Nvml_DeviceGetSupportedClocksThrottleReasons", "nvmlDeviceGetSupportedClocksThrottleReasons", err, nvmlErrorString(err));
}

void Nvml_DeviceGetSupportedGraphicsClocks(nvmlDevice_t a0, unsigned int a1, unsigned int* a2, unsigned int* a3)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetSupportedGraphicsClocks(a0, a1, a2, a3);
	nvml_return_handler("Nvml_DeviceGetSupportedGraphicsClocks", "nvmlDeviceGetSupportedGraphicsClocks", err, nvmlErrorString(err));
}

void Nvml_DeviceGetSupportedMemoryClocks(nvmlDevice_t a0, unsigned int* a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetSupportedMemoryClocks(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetSupportedMemoryClocks", "nvmlDeviceGetSupportedMemoryClocks", err, nvmlErrorString(err));
}

void Nvml_DeviceGetTemperature(nvmlDevice_t a0, nvmlTemperatureSensors_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetTemperature(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetTemperature", "nvmlDeviceGetTemperature", err, nvmlErrorString(err));
}

void Nvml_DeviceGetTemperatureThreshold(nvmlDevice_t a0, nvmlTemperatureThresholds_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetTemperatureThreshold(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetTemperatureThreshold", "nvmlDeviceGetTemperatureThreshold", err, nvmlErrorString(err));
}

void Nvml_DeviceGetTopologyCommonAncestor(nvmlDevice_t a0, nvmlDevice_t a1, nvmlGpuTopologyLevel_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetTopologyCommonAncestor(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetTopologyCommonAncestor", "nvmlDeviceGetTopologyCommonAncestor", err, nvmlErrorString(err));
}

void Nvml_DeviceGetTopologyNearestGpus(nvmlDevice_t a0, nvmlGpuTopologyLevel_t a1, unsigned int* a2, nvmlDevice_t* a3)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetTopologyNearestGpus(a0, a1, a2, a3);
	nvml_return_handler("Nvml_DeviceGetTopologyNearestGpus", "nvmlDeviceGetTopologyNearestGpus", err, nvmlErrorString(err));
}

void Nvml_DeviceGetTotalEccErrors(nvmlDevice_t a0, nvmlMemoryErrorType_t a1, nvmlEccCounterType_t a2, unsigned long long* a3)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetTotalEccErrors(a0, a1, a2, a3);
	nvml_return_handler("Nvml_DeviceGetTotalEccErrors", "nvmlDeviceGetTotalEccErrors", err, nvmlErrorString(err));
}

void Nvml_DeviceGetUUID(nvmlDevice_t a0, char* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetUUID(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetUUID", "nvmlDeviceGetUUID", err, nvmlErrorString(err));
}

void Nvml_DeviceGetUtilizationRates(nvmlDevice_t a0, nvmlUtilization_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetUtilizationRates(a0, a1);
	nvml_return_handler("Nvml_DeviceGetUtilizationRates", "nvmlDeviceGetUtilizationRates", err, nvmlErrorString(err));
}

void Nvml_DeviceGetVbiosVersion(nvmlDevice_t a0, char* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetVbiosVersion(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetVbiosVersion", "nvmlDeviceGetVbiosVersion", err, nvmlErrorString(err));
}

void Nvml_DeviceGetViolationStatus(nvmlDevice_t a0, nvmlPerfPolicyType_t a1, nvmlViolationTime_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetViolationStatus(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceGetViolationStatus", "nvmlDeviceGetViolationStatus", err, nvmlErrorString(err));
}

void Nvml_DeviceOnSameBoard(nvmlDevice_t a0, nvmlDevice_t a1, int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceOnSameBoard(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceOnSameBoard", "nvmlDeviceOnSameBoard", err, nvmlErrorString(err));
}

void Nvml_DeviceResetApplicationsClocks(nvmlDevice_t a0)
{
	nvmlReturn_t err;
	err = nvmlDeviceResetApplicationsClocks(a0);
	nvml_return_handler("Nvml_DeviceResetApplicationsClocks", "nvmlDeviceResetApplicationsClocks", err, nvmlErrorString(err));
}

void Nvml_DeviceSetAutoBoostedClocksEnabled(nvmlDevice_t a0, nvmlEnableState_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetAutoBoostedClocksEnabled(a0, a1);
	nvml_return_handler("Nvml_DeviceSetAutoBoostedClocksEnabled", "nvmlDeviceSetAutoBoostedClocksEnabled", err, nvmlErrorString(err));
}

void Nvml_DeviceSetCpuAffinity(nvmlDevice_t a0)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetCpuAffinity(a0);
	nvml_return_handler("Nvml_DeviceSetCpuAffinity", "nvmlDeviceSetCpuAffinity", err, nvmlErrorString(err));
}

void Nvml_DeviceSetDefaultAutoBoostedClocksEnabled(nvmlDevice_t a0, nvmlEnableState_t a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetDefaultAutoBoostedClocksEnabled(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceSetDefaultAutoBoostedClocksEnabled", "nvmlDeviceSetDefaultAutoBoostedClocksEnabled", err, nvmlErrorString(err));
}

void Nvml_DeviceValidateInforom(nvmlDevice_t a0)
{
	nvmlReturn_t err;
	err = nvmlDeviceValidateInforom(a0);
	nvml_return_handler("Nvml_DeviceValidateInforom", "nvmlDeviceValidateInforom", err, nvmlErrorString(err));
}

void Nvml_SystemGetTopologyGpuSet(unsigned int a0, unsigned int* a1, nvmlDevice_t* a2)
{
	nvmlReturn_t err;
	err = nvmlSystemGetTopologyGpuSet(a0, a1, a2);
	nvml_return_handler("Nvml_SystemGetTopologyGpuSet", "nvmlSystemGetTopologyGpuSet", err, nvmlErrorString(err));
}

void Nvml_UnitSetLedState(nvmlUnit_t a0, nvmlLedColor_t a1)
{
	nvmlReturn_t err;
	err = nvmlUnitSetLedState(a0, a1);
	nvml_return_handler("Nvml_UnitSetLedState", "nvmlUnitSetLedState", err, nvmlErrorString(err));
}

void Nvml_DeviceClearEccErrorCounts(nvmlDevice_t a0, nvmlEccCounterType_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceClearEccErrorCounts(a0, a1);
	nvml_return_handler("Nvml_DeviceClearEccErrorCounts", "nvmlDeviceClearEccErrorCounts", err, nvmlErrorString(err));
}

void Nvml_DeviceSetAPIRestriction(nvmlDevice_t a0, nvmlRestrictedAPI_t a1, nvmlEnableState_t a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetAPIRestriction(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceSetAPIRestriction", "nvmlDeviceSetAPIRestriction", err, nvmlErrorString(err));
}

void Nvml_DeviceSetApplicationsClocks(nvmlDevice_t a0, unsigned int a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetApplicationsClocks(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceSetApplicationsClocks", "nvmlDeviceSetApplicationsClocks", err, nvmlErrorString(err));
}

void Nvml_DeviceSetComputeMode(nvmlDevice_t a0, nvmlComputeMode_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetComputeMode(a0, a1);
	nvml_return_handler("Nvml_DeviceSetComputeMode", "nvmlDeviceSetComputeMode", err, nvmlErrorString(err));
}

void Nvml_DeviceSetDriverModel(nvmlDevice_t a0, nvmlDriverModel_t a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetDriverModel(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceSetDriverModel", "nvmlDeviceSetDriverModel", err, nvmlErrorString(err));
}

void Nvml_DeviceSetEccMode(nvmlDevice_t a0, nvmlEnableState_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetEccMode(a0, a1);
	nvml_return_handler("Nvml_DeviceSetEccMode", "nvmlDeviceSetEccMode", err, nvmlErrorString(err));
}

void Nvml_DeviceSetGpuOperationMode(nvmlDevice_t a0, nvmlGpuOperationMode_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetGpuOperationMode(a0, a1);
	nvml_return_handler("Nvml_DeviceSetGpuOperationMode", "nvmlDeviceSetGpuOperationMode", err, nvmlErrorString(err));
}

void Nvml_DeviceSetPersistenceMode(nvmlDevice_t a0, nvmlEnableState_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetPersistenceMode(a0, a1);
	nvml_return_handler("Nvml_DeviceSetPersistenceMode", "nvmlDeviceSetPersistenceMode", err, nvmlErrorString(err));
}

void Nvml_DeviceSetPowerManagementLimit(nvmlDevice_t a0, unsigned int a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetPowerManagementLimit(a0, a1);
	nvml_return_handler("Nvml_DeviceSetPowerManagementLimit", "nvmlDeviceSetPowerManagementLimit", err, nvmlErrorString(err));
}

void Nvml_DeviceGetSupportedEventTypes(nvmlDevice_t a0, unsigned long long* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetSupportedEventTypes(a0, a1);
	nvml_return_handler("Nvml_DeviceGetSupportedEventTypes", "nvmlDeviceGetSupportedEventTypes", err, nvmlErrorString(err));
}

void Nvml_DeviceRegisterEvents(nvmlDevice_t a0, unsigned long long a1, nvmlEventSet_t a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceRegisterEvents(a0, a1, a2);
	nvml_return_handler("Nvml_DeviceRegisterEvents", "nvmlDeviceRegisterEvents", err, nvmlErrorString(err));
}

void Nvml_EventSetCreate(nvmlEventSet_t* a0)
{
	nvmlReturn_t err;
	err = nvmlEventSetCreate(a0);
	nvml_return_handler("Nvml_EventSetCreate", "nvmlEventSetCreate", err, nvmlErrorString(err));
}

void Nvml_EventSetFree(nvmlEventSet_t a0)
{
	nvmlReturn_t err;
	err = nvmlEventSetFree(a0);
	nvml_return_handler("Nvml_EventSetFree", "nvmlEventSetFree", err, nvmlErrorString(err));
}

void Nvml_EventSetWait(nvmlEventSet_t a0, nvmlEventData_t* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlEventSetWait(a0, a1, a2);
	nvml_return_handler("Nvml_EventSetWait", "nvmlEventSetWait", err, nvmlErrorString(err));
}
