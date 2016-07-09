
#include <stdio.h>

#include "nvmlapi.h"

static SInt32	_last_nvml_error_int;
static char 	_last_nvml_error_str[GPUMOND_NVML_ERROR_STRLEN];

SInt32 Last_Nvml_Error()
{
	return _last_nvml_error_int;
}

const char *Last_Nvml_Error_Msg()
{
	return _last_nvml_error_str;
}

static SInt32 _Nvml_Return_Handler(const char *caller,
                                   const char *callee,
                                   nvmlReturn_t err,
                                   const char *errstr)
{
	_last_nvml_error_int = err;

	if (UNLIKELY(NVML_SUCCESS != err)) {
		snprintf(_last_nvml_error_str, GPUMOND_NVML_ERROR_STRLEN,
		         "%s: %s() returned %d: %s", caller, callee, (SInt32 )err, errstr);
		return -1;
	} else {
		_last_nvml_error_str[0] = 0;
	}

	return 0;
}

/* Wrapper around NVML library calls.
 *
 * Generated with python2 wrap-nvml.py --definitions.
 */

SInt32 Nvml_DeviceClearAccountingPids(nvmlDevice_t a0)
{
	nvmlReturn_t err;
	err = nvmlDeviceClearAccountingPids(a0);
	return _Nvml_Return_Handler("Nvml_DeviceClearAccountingPids", "nvmlDeviceClearAccountingPids", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetAccountingBufferSize(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetAccountingBufferSize(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetAccountingBufferSize", "nvmlDeviceGetAccountingBufferSize", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetAccountingMode(nvmlDevice_t a0, nvmlEnableState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetAccountingMode(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetAccountingMode", "nvmlDeviceGetAccountingMode", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetAccountingPids(nvmlDevice_t a0, unsigned int* a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetAccountingPids(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetAccountingPids", "nvmlDeviceGetAccountingPids", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetAccountingStats(nvmlDevice_t a0, unsigned int a1, nvmlAccountingStats_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetAccountingStats(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetAccountingStats", "nvmlDeviceGetAccountingStats", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceSetAccountingMode(nvmlDevice_t a0, nvmlEnableState_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetAccountingMode(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceSetAccountingMode", "nvmlDeviceSetAccountingMode", err, nvmlErrorString(err));
}

SInt32 Nvml_Init()
{
	nvmlReturn_t err;
	err = nvmlInit();
	return _Nvml_Return_Handler("Nvml_Init", "nvmlInit", err, nvmlErrorString(err));
}

SInt32 Nvml_Shutdown()
{
	nvmlReturn_t err;
	err = nvmlShutdown();
	return _Nvml_Return_Handler("Nvml_Shutdown", "nvmlShutdown", err, nvmlErrorString(err));
}

SInt32 Nvml_SystemGetDriverVersion(char* a0, unsigned int a1)
{
	nvmlReturn_t err;
	err = nvmlSystemGetDriverVersion(a0, a1);
	return _Nvml_Return_Handler("Nvml_SystemGetDriverVersion", "nvmlSystemGetDriverVersion", err, nvmlErrorString(err));
}

SInt32 Nvml_SystemGetNVMLVersion(char* a0, unsigned int a1)
{
	nvmlReturn_t err;
	err = nvmlSystemGetNVMLVersion(a0, a1);
	return _Nvml_Return_Handler("Nvml_SystemGetNVMLVersion", "nvmlSystemGetNVMLVersion", err, nvmlErrorString(err));
}

SInt32 Nvml_SystemGetProcessName(unsigned int a0, char* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlSystemGetProcessName(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_SystemGetProcessName", "nvmlSystemGetProcessName", err, nvmlErrorString(err));
}

SInt32 Nvml_SystemGetHicVersion(unsigned int* a0, nvmlHwbcEntry_t* a1)
{
	nvmlReturn_t err;
	err = nvmlSystemGetHicVersion(a0, a1);
	return _Nvml_Return_Handler("Nvml_SystemGetHicVersion", "nvmlSystemGetHicVersion", err, nvmlErrorString(err));
}

SInt32 Nvml_UnitGetCount(unsigned int* a0)
{
	nvmlReturn_t err;
	err = nvmlUnitGetCount(a0);
	return _Nvml_Return_Handler("Nvml_UnitGetCount", "nvmlUnitGetCount", err, nvmlErrorString(err));
}

SInt32 Nvml_UnitGetDevices(nvmlUnit_t a0, unsigned int* a1, nvmlDevice_t* a2)
{
	nvmlReturn_t err;
	err = nvmlUnitGetDevices(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_UnitGetDevices", "nvmlUnitGetDevices", err, nvmlErrorString(err));
}

SInt32 Nvml_UnitGetFanSpeedInfo(nvmlUnit_t a0, nvmlUnitFanSpeeds_t* a1)
{
	nvmlReturn_t err;
	err = nvmlUnitGetFanSpeedInfo(a0, a1);
	return _Nvml_Return_Handler("Nvml_UnitGetFanSpeedInfo", "nvmlUnitGetFanSpeedInfo", err, nvmlErrorString(err));
}

SInt32 Nvml_UnitGetHandleByIndex(unsigned int a0, nvmlUnit_t* a1)
{
	nvmlReturn_t err;
	err = nvmlUnitGetHandleByIndex(a0, a1);
	return _Nvml_Return_Handler("Nvml_UnitGetHandleByIndex", "nvmlUnitGetHandleByIndex", err, nvmlErrorString(err));
}

SInt32 Nvml_UnitGetLedState(nvmlUnit_t a0, nvmlLedState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlUnitGetLedState(a0, a1);
	return _Nvml_Return_Handler("Nvml_UnitGetLedState", "nvmlUnitGetLedState", err, nvmlErrorString(err));
}

SInt32 Nvml_UnitGetPsuInfo(nvmlUnit_t a0, nvmlPSUInfo_t* a1)
{
	nvmlReturn_t err;
	err = nvmlUnitGetPsuInfo(a0, a1);
	return _Nvml_Return_Handler("Nvml_UnitGetPsuInfo", "nvmlUnitGetPsuInfo", err, nvmlErrorString(err));
}

SInt32 Nvml_UnitGetTemperature(nvmlUnit_t a0, unsigned int a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlUnitGetTemperature(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_UnitGetTemperature", "nvmlUnitGetTemperature", err, nvmlErrorString(err));
}

SInt32 Nvml_UnitGetUnitInfo(nvmlUnit_t a0, nvmlUnitInfo_t* a1)
{
	nvmlReturn_t err;
	err = nvmlUnitGetUnitInfo(a0, a1);
	return _Nvml_Return_Handler("Nvml_UnitGetUnitInfo", "nvmlUnitGetUnitInfo", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceClearCpuAffinity(nvmlDevice_t a0)
{
	nvmlReturn_t err;
	err = nvmlDeviceClearCpuAffinity(a0);
	return _Nvml_Return_Handler("Nvml_DeviceClearCpuAffinity", "nvmlDeviceClearCpuAffinity", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetAPIRestriction(nvmlDevice_t a0, nvmlRestrictedAPI_t a1, nvmlEnableState_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetAPIRestriction(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetAPIRestriction", "nvmlDeviceGetAPIRestriction", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetApplicationsClock(nvmlDevice_t a0, nvmlClockType_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetApplicationsClock(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetApplicationsClock", "nvmlDeviceGetApplicationsClock", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetAutoBoostedClocksEnabled(nvmlDevice_t a0, nvmlEnableState_t* a1, nvmlEnableState_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetAutoBoostedClocksEnabled(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetAutoBoostedClocksEnabled", "nvmlDeviceGetAutoBoostedClocksEnabled", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetBAR1MemoryInfo(nvmlDevice_t a0, nvmlBAR1Memory_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetBAR1MemoryInfo(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetBAR1MemoryInfo", "nvmlDeviceGetBAR1MemoryInfo", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetBoardId(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetBoardId(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetBoardId", "nvmlDeviceGetBoardId", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetBrand(nvmlDevice_t a0, nvmlBrandType_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetBrand(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetBrand", "nvmlDeviceGetBrand", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetBridgeChipInfo(nvmlDevice_t a0, nvmlBridgeChipHierarchy_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetBridgeChipInfo(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetBridgeChipInfo", "nvmlDeviceGetBridgeChipInfo", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetClockInfo(nvmlDevice_t a0, nvmlClockType_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetClockInfo(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetClockInfo", "nvmlDeviceGetClockInfo", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetComputeMode(nvmlDevice_t a0, nvmlComputeMode_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetComputeMode(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetComputeMode", "nvmlDeviceGetComputeMode", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetComputeRunningProcesses(nvmlDevice_t a0, unsigned int* a1, nvmlProcessInfo_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetComputeRunningProcesses(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetComputeRunningProcesses", "nvmlDeviceGetComputeRunningProcesses", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetCount(unsigned int* a0)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetCount(a0);
	return _Nvml_Return_Handler("Nvml_DeviceGetCount", "nvmlDeviceGetCount", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetCpuAffinity(nvmlDevice_t a0, unsigned int a1, unsigned long* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetCpuAffinity(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetCpuAffinity", "nvmlDeviceGetCpuAffinity", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetCurrPcieLinkGeneration(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetCurrPcieLinkGeneration(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetCurrPcieLinkGeneration", "nvmlDeviceGetCurrPcieLinkGeneration", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetCurrPcieLinkWidth(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetCurrPcieLinkWidth(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetCurrPcieLinkWidth", "nvmlDeviceGetCurrPcieLinkWidth", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetCurrentClocksThrottleReasons(nvmlDevice_t a0, unsigned long long* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetCurrentClocksThrottleReasons(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetCurrentClocksThrottleReasons", "nvmlDeviceGetCurrentClocksThrottleReasons", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetDecoderUtilization(nvmlDevice_t a0, unsigned int* a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetDecoderUtilization(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetDecoderUtilization", "nvmlDeviceGetDecoderUtilization", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetDefaultApplicationsClock(nvmlDevice_t a0, nvmlClockType_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetDefaultApplicationsClock(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetDefaultApplicationsClock", "nvmlDeviceGetDefaultApplicationsClock", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetDetailedEccErrors(nvmlDevice_t a0, nvmlMemoryErrorType_t a1, nvmlEccCounterType_t a2, nvmlEccErrorCounts_t* a3)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetDetailedEccErrors(a0, a1, a2, a3);
	return _Nvml_Return_Handler("Nvml_DeviceGetDetailedEccErrors", "nvmlDeviceGetDetailedEccErrors", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetDisplayActive(nvmlDevice_t a0, nvmlEnableState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetDisplayActive(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetDisplayActive", "nvmlDeviceGetDisplayActive", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetDisplayMode(nvmlDevice_t a0, nvmlEnableState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetDisplayMode(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetDisplayMode", "nvmlDeviceGetDisplayMode", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetDriverModel(nvmlDevice_t a0, nvmlDriverModel_t* a1, nvmlDriverModel_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetDriverModel(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetDriverModel", "nvmlDeviceGetDriverModel", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetEccMode(nvmlDevice_t a0, nvmlEnableState_t* a1, nvmlEnableState_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetEccMode(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetEccMode", "nvmlDeviceGetEccMode", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetEncoderUtilization(nvmlDevice_t a0, unsigned int* a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetEncoderUtilization(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetEncoderUtilization", "nvmlDeviceGetEncoderUtilization", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetEnforcedPowerLimit(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetEnforcedPowerLimit(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetEnforcedPowerLimit", "nvmlDeviceGetEnforcedPowerLimit", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetFanSpeed(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetFanSpeed(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetFanSpeed", "nvmlDeviceGetFanSpeed", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetGpuOperationMode(nvmlDevice_t a0, nvmlGpuOperationMode_t* a1, nvmlGpuOperationMode_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetGpuOperationMode(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetGpuOperationMode", "nvmlDeviceGetGpuOperationMode", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetGraphicsRunningProcesses(nvmlDevice_t a0, unsigned int* a1, nvmlProcessInfo_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetGraphicsRunningProcesses(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetGraphicsRunningProcesses", "nvmlDeviceGetGraphicsRunningProcesses", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetHandleByIndex(unsigned int a0, nvmlDevice_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetHandleByIndex(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetHandleByIndex", "nvmlDeviceGetHandleByIndex", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetHandleByPciBusId(const char* a0, nvmlDevice_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetHandleByPciBusId(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetHandleByPciBusId", "nvmlDeviceGetHandleByPciBusId", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetHandleBySerial(const char* a0, nvmlDevice_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetHandleBySerial(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetHandleBySerial", "nvmlDeviceGetHandleBySerial", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetHandleByUUID(const char* a0, nvmlDevice_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetHandleByUUID(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetHandleByUUID", "nvmlDeviceGetHandleByUUID", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetIndex(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetIndex(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetIndex", "nvmlDeviceGetIndex", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetInforomConfigurationChecksum(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetInforomConfigurationChecksum(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetInforomConfigurationChecksum", "nvmlDeviceGetInforomConfigurationChecksum", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetInforomImageVersion(nvmlDevice_t a0, char* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetInforomImageVersion(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetInforomImageVersion", "nvmlDeviceGetInforomImageVersion", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetInforomVersion(nvmlDevice_t a0, nvmlInforomObject_t a1, char* a2, unsigned int a3)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetInforomVersion(a0, a1, a2, a3);
	return _Nvml_Return_Handler("Nvml_DeviceGetInforomVersion", "nvmlDeviceGetInforomVersion", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetMaxClockInfo(nvmlDevice_t a0, nvmlClockType_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMaxClockInfo(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetMaxClockInfo", "nvmlDeviceGetMaxClockInfo", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetMaxPcieLinkGeneration(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMaxPcieLinkGeneration(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetMaxPcieLinkGeneration", "nvmlDeviceGetMaxPcieLinkGeneration", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetMaxPcieLinkWidth(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMaxPcieLinkWidth(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetMaxPcieLinkWidth", "nvmlDeviceGetMaxPcieLinkWidth", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetMemoryErrorCounter(nvmlDevice_t a0, nvmlMemoryErrorType_t a1, nvmlEccCounterType_t a2, nvmlMemoryLocation_t a3, unsigned long long* a4)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMemoryErrorCounter(a0, a1, a2, a3, a4);
	return _Nvml_Return_Handler("Nvml_DeviceGetMemoryErrorCounter", "nvmlDeviceGetMemoryErrorCounter", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetMemoryInfo(nvmlDevice_t a0, nvmlMemory_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMemoryInfo(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetMemoryInfo", "nvmlDeviceGetMemoryInfo", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetMinorNumber(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMinorNumber(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetMinorNumber", "nvmlDeviceGetMinorNumber", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetMultiGpuBoard(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetMultiGpuBoard(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetMultiGpuBoard", "nvmlDeviceGetMultiGpuBoard", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetName(nvmlDevice_t a0, char* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetName(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetName", "nvmlDeviceGetName", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetPciInfo(nvmlDevice_t a0, nvmlPciInfo_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPciInfo(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetPciInfo", "nvmlDeviceGetPciInfo", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetPcieReplayCounter(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPcieReplayCounter(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetPcieReplayCounter", "nvmlDeviceGetPcieReplayCounter", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetPcieThroughput(nvmlDevice_t a0, nvmlPcieUtilCounter_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPcieThroughput(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetPcieThroughput", "nvmlDeviceGetPcieThroughput", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetPerformanceState(nvmlDevice_t a0, nvmlPstates_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPerformanceState(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetPerformanceState", "nvmlDeviceGetPerformanceState", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetPersistenceMode(nvmlDevice_t a0, nvmlEnableState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPersistenceMode(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetPersistenceMode", "nvmlDeviceGetPersistenceMode", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetPowerManagementDefaultLimit(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPowerManagementDefaultLimit(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetPowerManagementDefaultLimit", "nvmlDeviceGetPowerManagementDefaultLimit", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetPowerManagementLimit(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPowerManagementLimit(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetPowerManagementLimit", "nvmlDeviceGetPowerManagementLimit", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetPowerManagementLimitConstraints(nvmlDevice_t a0, unsigned int* a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPowerManagementLimitConstraints(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetPowerManagementLimitConstraints", "nvmlDeviceGetPowerManagementLimitConstraints", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetPowerManagementMode(nvmlDevice_t a0, nvmlEnableState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPowerManagementMode(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetPowerManagementMode", "nvmlDeviceGetPowerManagementMode", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetPowerState(nvmlDevice_t a0, nvmlPstates_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPowerState(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetPowerState", "nvmlDeviceGetPowerState", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetPowerUsage(nvmlDevice_t a0, unsigned int* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetPowerUsage(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetPowerUsage", "nvmlDeviceGetPowerUsage", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetRetiredPages(nvmlDevice_t a0, nvmlPageRetirementCause_t a1, unsigned int* a2, unsigned long long* a3)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetRetiredPages(a0, a1, a2, a3);
	return _Nvml_Return_Handler("Nvml_DeviceGetRetiredPages", "nvmlDeviceGetRetiredPages", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetRetiredPagesPendingStatus(nvmlDevice_t a0, nvmlEnableState_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetRetiredPagesPendingStatus(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetRetiredPagesPendingStatus", "nvmlDeviceGetRetiredPagesPendingStatus", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetSamples(nvmlDevice_t a0, nvmlSamplingType_t a1, unsigned long long a2, nvmlValueType_t* a3, unsigned int* a4, nvmlSample_t* a5)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetSamples(a0, a1, a2, a3, a4, a5);
	return _Nvml_Return_Handler("Nvml_DeviceGetSamples", "nvmlDeviceGetSamples", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetSerial(nvmlDevice_t a0, char* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetSerial(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetSerial", "nvmlDeviceGetSerial", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetSupportedClocksThrottleReasons(nvmlDevice_t a0, unsigned long long* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetSupportedClocksThrottleReasons(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetSupportedClocksThrottleReasons", "nvmlDeviceGetSupportedClocksThrottleReasons", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetSupportedGraphicsClocks(nvmlDevice_t a0, unsigned int a1, unsigned int* a2, unsigned int* a3)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetSupportedGraphicsClocks(a0, a1, a2, a3);
	return _Nvml_Return_Handler("Nvml_DeviceGetSupportedGraphicsClocks", "nvmlDeviceGetSupportedGraphicsClocks", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetSupportedMemoryClocks(nvmlDevice_t a0, unsigned int* a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetSupportedMemoryClocks(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetSupportedMemoryClocks", "nvmlDeviceGetSupportedMemoryClocks", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetTemperature(nvmlDevice_t a0, nvmlTemperatureSensors_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetTemperature(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetTemperature", "nvmlDeviceGetTemperature", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetTemperatureThreshold(nvmlDevice_t a0, nvmlTemperatureThresholds_t a1, unsigned int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetTemperatureThreshold(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetTemperatureThreshold", "nvmlDeviceGetTemperatureThreshold", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetTopologyCommonAncestor(nvmlDevice_t a0, nvmlDevice_t a1, nvmlGpuTopologyLevel_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetTopologyCommonAncestor(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetTopologyCommonAncestor", "nvmlDeviceGetTopologyCommonAncestor", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetTopologyNearestGpus(nvmlDevice_t a0, nvmlGpuTopologyLevel_t a1, unsigned int* a2, nvmlDevice_t* a3)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetTopologyNearestGpus(a0, a1, a2, a3);
	return _Nvml_Return_Handler("Nvml_DeviceGetTopologyNearestGpus", "nvmlDeviceGetTopologyNearestGpus", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetTotalEccErrors(nvmlDevice_t a0, nvmlMemoryErrorType_t a1, nvmlEccCounterType_t a2, unsigned long long* a3)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetTotalEccErrors(a0, a1, a2, a3);
	return _Nvml_Return_Handler("Nvml_DeviceGetTotalEccErrors", "nvmlDeviceGetTotalEccErrors", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetUUID(nvmlDevice_t a0, char* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetUUID(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetUUID", "nvmlDeviceGetUUID", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetUtilizationRates(nvmlDevice_t a0, nvmlUtilization_t* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetUtilizationRates(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetUtilizationRates", "nvmlDeviceGetUtilizationRates", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetVbiosVersion(nvmlDevice_t a0, char* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetVbiosVersion(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetVbiosVersion", "nvmlDeviceGetVbiosVersion", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetViolationStatus(nvmlDevice_t a0, nvmlPerfPolicyType_t a1, nvmlViolationTime_t* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetViolationStatus(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceGetViolationStatus", "nvmlDeviceGetViolationStatus", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceOnSameBoard(nvmlDevice_t a0, nvmlDevice_t a1, int* a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceOnSameBoard(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceOnSameBoard", "nvmlDeviceOnSameBoard", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceResetApplicationsClocks(nvmlDevice_t a0)
{
	nvmlReturn_t err;
	err = nvmlDeviceResetApplicationsClocks(a0);
	return _Nvml_Return_Handler("Nvml_DeviceResetApplicationsClocks", "nvmlDeviceResetApplicationsClocks", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceSetAutoBoostedClocksEnabled(nvmlDevice_t a0, nvmlEnableState_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetAutoBoostedClocksEnabled(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceSetAutoBoostedClocksEnabled", "nvmlDeviceSetAutoBoostedClocksEnabled", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceSetCpuAffinity(nvmlDevice_t a0)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetCpuAffinity(a0);
	return _Nvml_Return_Handler("Nvml_DeviceSetCpuAffinity", "nvmlDeviceSetCpuAffinity", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceSetDefaultAutoBoostedClocksEnabled(nvmlDevice_t a0, nvmlEnableState_t a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetDefaultAutoBoostedClocksEnabled(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceSetDefaultAutoBoostedClocksEnabled", "nvmlDeviceSetDefaultAutoBoostedClocksEnabled", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceValidateInforom(nvmlDevice_t a0)
{
	nvmlReturn_t err;
	err = nvmlDeviceValidateInforom(a0);
	return _Nvml_Return_Handler("Nvml_DeviceValidateInforom", "nvmlDeviceValidateInforom", err, nvmlErrorString(err));
}

SInt32 Nvml_SystemGetTopologyGpuSet(unsigned int a0, unsigned int* a1, nvmlDevice_t* a2)
{
	nvmlReturn_t err;
	err = nvmlSystemGetTopologyGpuSet(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_SystemGetTopologyGpuSet", "nvmlSystemGetTopologyGpuSet", err, nvmlErrorString(err));
}

SInt32 Nvml_UnitSetLedState(nvmlUnit_t a0, nvmlLedColor_t a1)
{
	nvmlReturn_t err;
	err = nvmlUnitSetLedState(a0, a1);
	return _Nvml_Return_Handler("Nvml_UnitSetLedState", "nvmlUnitSetLedState", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceClearEccErrorCounts(nvmlDevice_t a0, nvmlEccCounterType_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceClearEccErrorCounts(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceClearEccErrorCounts", "nvmlDeviceClearEccErrorCounts", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceSetAPIRestriction(nvmlDevice_t a0, nvmlRestrictedAPI_t a1, nvmlEnableState_t a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetAPIRestriction(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceSetAPIRestriction", "nvmlDeviceSetAPIRestriction", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceSetApplicationsClocks(nvmlDevice_t a0, unsigned int a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetApplicationsClocks(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceSetApplicationsClocks", "nvmlDeviceSetApplicationsClocks", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceSetComputeMode(nvmlDevice_t a0, nvmlComputeMode_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetComputeMode(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceSetComputeMode", "nvmlDeviceSetComputeMode", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceSetDriverModel(nvmlDevice_t a0, nvmlDriverModel_t a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetDriverModel(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceSetDriverModel", "nvmlDeviceSetDriverModel", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceSetEccMode(nvmlDevice_t a0, nvmlEnableState_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetEccMode(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceSetEccMode", "nvmlDeviceSetEccMode", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceSetGpuOperationMode(nvmlDevice_t a0, nvmlGpuOperationMode_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetGpuOperationMode(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceSetGpuOperationMode", "nvmlDeviceSetGpuOperationMode", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceSetPersistenceMode(nvmlDevice_t a0, nvmlEnableState_t a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetPersistenceMode(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceSetPersistenceMode", "nvmlDeviceSetPersistenceMode", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceSetPowerManagementLimit(nvmlDevice_t a0, unsigned int a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceSetPowerManagementLimit(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceSetPowerManagementLimit", "nvmlDeviceSetPowerManagementLimit", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceGetSupportedEventTypes(nvmlDevice_t a0, unsigned long long* a1)
{
	nvmlReturn_t err;
	err = nvmlDeviceGetSupportedEventTypes(a0, a1);
	return _Nvml_Return_Handler("Nvml_DeviceGetSupportedEventTypes", "nvmlDeviceGetSupportedEventTypes", err, nvmlErrorString(err));
}

SInt32 Nvml_DeviceRegisterEvents(nvmlDevice_t a0, unsigned long long a1, nvmlEventSet_t a2)
{
	nvmlReturn_t err;
	err = nvmlDeviceRegisterEvents(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_DeviceRegisterEvents", "nvmlDeviceRegisterEvents", err, nvmlErrorString(err));
}

SInt32 Nvml_EventSetCreate(nvmlEventSet_t* a0)
{
	nvmlReturn_t err;
	err = nvmlEventSetCreate(a0);
	return _Nvml_Return_Handler("Nvml_EventSetCreate", "nvmlEventSetCreate", err, nvmlErrorString(err));
}

SInt32 Nvml_EventSetFree(nvmlEventSet_t a0)
{
	nvmlReturn_t err;
	err = nvmlEventSetFree(a0);
	return _Nvml_Return_Handler("Nvml_EventSetFree", "nvmlEventSetFree", err, nvmlErrorString(err));
}

SInt32 Nvml_EventSetWait(nvmlEventSet_t a0, nvmlEventData_t* a1, unsigned int a2)
{
	nvmlReturn_t err;
	err = nvmlEventSetWait(a0, a1, a2);
	return _Nvml_Return_Handler("Nvml_EventSetWait", "nvmlEventSetWait", err, nvmlErrorString(err));
}
