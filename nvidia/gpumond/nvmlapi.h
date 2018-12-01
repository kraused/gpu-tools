
#ifndef GPUMOND_NVMLAPI_H_INCLUDED
#define GPUMOND_NVMLAPI_H_INCLUDED 1

#include <nvml.h>

#include "config.h"
#include "platform.h"

/* Not thread safe or reentrant but good enough for our purpose.
 */
SInt32 Last_Nvml_Error();
const char *Last_Nvml_Error_Msg();

/* Wrapper around NVML library calls.
 *
 * Generated with python2 wrap-nvml.py --prototypes.
 */

SInt32 Nvml_DeviceClearAccountingPids(nvmlDevice_t);
SInt32 Nvml_DeviceGetAccountingBufferSize(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetAccountingMode(nvmlDevice_t, nvmlEnableState_t*);
SInt32 Nvml_DeviceGetAccountingPids(nvmlDevice_t, unsigned int*, unsigned int*);
SInt32 Nvml_DeviceGetAccountingStats(nvmlDevice_t, unsigned int, nvmlAccountingStats_t*);
SInt32 Nvml_DeviceSetAccountingMode(nvmlDevice_t, nvmlEnableState_t);
SInt32 Nvml_Init();
SInt32 Nvml_Shutdown();
SInt32 Nvml_SystemGetDriverVersion(char*, unsigned int);
SInt32 Nvml_SystemGetNVMLVersion(char*, unsigned int);
SInt32 Nvml_SystemGetProcessName(unsigned int, char*, unsigned int);
SInt32 Nvml_SystemGetHicVersion(unsigned int*, nvmlHwbcEntry_t*);
SInt32 Nvml_UnitGetCount(unsigned int*);
SInt32 Nvml_UnitGetDevices(nvmlUnit_t, unsigned int*, nvmlDevice_t*);
SInt32 Nvml_UnitGetFanSpeedInfo(nvmlUnit_t, nvmlUnitFanSpeeds_t*);
SInt32 Nvml_UnitGetHandleByIndex(unsigned int, nvmlUnit_t*);
SInt32 Nvml_UnitGetLedState(nvmlUnit_t, nvmlLedState_t*);
SInt32 Nvml_UnitGetPsuInfo(nvmlUnit_t, nvmlPSUInfo_t*);
SInt32 Nvml_UnitGetTemperature(nvmlUnit_t, unsigned int, unsigned int*);
SInt32 Nvml_UnitGetUnitInfo(nvmlUnit_t, nvmlUnitInfo_t*);
SInt32 Nvml_DeviceClearCpuAffinity(nvmlDevice_t);
SInt32 Nvml_DeviceGetAPIRestriction(nvmlDevice_t, nvmlRestrictedAPI_t, nvmlEnableState_t*);
SInt32 Nvml_DeviceGetApplicationsClock(nvmlDevice_t, nvmlClockType_t, unsigned int*);
SInt32 Nvml_DeviceGetAutoBoostedClocksEnabled(nvmlDevice_t, nvmlEnableState_t*, nvmlEnableState_t*);
SInt32 Nvml_DeviceGetBAR1MemoryInfo(nvmlDevice_t, nvmlBAR1Memory_t*);
SInt32 Nvml_DeviceGetBoardId(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetBoardPartNumber(nvmlDevice_t, char*, unsigned int);
SInt32 Nvml_DeviceGetBrand(nvmlDevice_t, nvmlBrandType_t*);
SInt32 Nvml_DeviceGetBridgeChipInfo(nvmlDevice_t, nvmlBridgeChipHierarchy_t*);
SInt32 Nvml_DeviceGetClockInfo(nvmlDevice_t, nvmlClockType_t, unsigned int*);
SInt32 Nvml_DeviceGetComputeMode(nvmlDevice_t, nvmlComputeMode_t*);
SInt32 Nvml_DeviceGetComputeRunningProcesses(nvmlDevice_t, unsigned int*, nvmlProcessInfo_t*);
SInt32 Nvml_DeviceGetCount(unsigned int*);
SInt32 Nvml_DeviceGetCpuAffinity(nvmlDevice_t, unsigned int, unsigned long*);
SInt32 Nvml_DeviceGetCurrPcieLinkGeneration(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetCurrPcieLinkWidth(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetCurrentClocksThrottleReasons(nvmlDevice_t, unsigned long long*);
SInt32 Nvml_DeviceGetDecoderUtilization(nvmlDevice_t, unsigned int*, unsigned int*);
SInt32 Nvml_DeviceGetDefaultApplicationsClock(nvmlDevice_t, nvmlClockType_t, unsigned int*);
SInt32 Nvml_DeviceGetDetailedEccErrors(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, nvmlEccErrorCounts_t*);
SInt32 Nvml_DeviceGetDisplayActive(nvmlDevice_t, nvmlEnableState_t*);
SInt32 Nvml_DeviceGetDisplayMode(nvmlDevice_t, nvmlEnableState_t*);
SInt32 Nvml_DeviceGetDriverModel(nvmlDevice_t, nvmlDriverModel_t*, nvmlDriverModel_t*);
SInt32 Nvml_DeviceGetEccMode(nvmlDevice_t, nvmlEnableState_t*, nvmlEnableState_t*);
SInt32 Nvml_DeviceGetEncoderUtilization(nvmlDevice_t, unsigned int*, unsigned int*);
SInt32 Nvml_DeviceGetEnforcedPowerLimit(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetFanSpeed(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetGpuOperationMode(nvmlDevice_t, nvmlGpuOperationMode_t*, nvmlGpuOperationMode_t*);
SInt32 Nvml_DeviceGetGraphicsRunningProcesses(nvmlDevice_t, unsigned int*, nvmlProcessInfo_t*);
SInt32 Nvml_DeviceGetHandleByIndex(unsigned int, nvmlDevice_t*);
SInt32 Nvml_DeviceGetHandleByPciBusId(const char*, nvmlDevice_t*);
SInt32 Nvml_DeviceGetHandleBySerial(const char*, nvmlDevice_t*);
SInt32 Nvml_DeviceGetHandleByUUID(const char*, nvmlDevice_t*);
SInt32 Nvml_DeviceGetIndex(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetInforomConfigurationChecksum(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetInforomImageVersion(nvmlDevice_t, char*, unsigned int);
SInt32 Nvml_DeviceGetInforomVersion(nvmlDevice_t, nvmlInforomObject_t, char*, unsigned int);
SInt32 Nvml_DeviceGetMaxClockInfo(nvmlDevice_t, nvmlClockType_t, unsigned int*);
SInt32 Nvml_DeviceGetMaxPcieLinkGeneration(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetMaxPcieLinkWidth(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetMemoryErrorCounter(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, nvmlMemoryLocation_t, unsigned long long*);
SInt32 Nvml_DeviceGetMemoryInfo(nvmlDevice_t, nvmlMemory_t*);
SInt32 Nvml_DeviceGetMinorNumber(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetMultiGpuBoard(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetName(nvmlDevice_t, char*, unsigned int);
SInt32 Nvml_DeviceGetPciInfo(nvmlDevice_t, nvmlPciInfo_t*);
SInt32 Nvml_DeviceGetPcieReplayCounter(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetPcieThroughput(nvmlDevice_t, nvmlPcieUtilCounter_t, unsigned int*);
SInt32 Nvml_DeviceGetPerformanceState(nvmlDevice_t, nvmlPstates_t*);
SInt32 Nvml_DeviceGetPersistenceMode(nvmlDevice_t, nvmlEnableState_t*);
SInt32 Nvml_DeviceGetPowerManagementDefaultLimit(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetPowerManagementLimit(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetPowerManagementLimitConstraints(nvmlDevice_t, unsigned int*, unsigned int*);
SInt32 Nvml_DeviceGetPowerManagementMode(nvmlDevice_t, nvmlEnableState_t*);
SInt32 Nvml_DeviceGetPowerState(nvmlDevice_t, nvmlPstates_t*);
SInt32 Nvml_DeviceGetPowerUsage(nvmlDevice_t, unsigned int*);
SInt32 Nvml_DeviceGetRetiredPages(nvmlDevice_t, nvmlPageRetirementCause_t, unsigned int*, unsigned long long*);
SInt32 Nvml_DeviceGetRetiredPagesPendingStatus(nvmlDevice_t, nvmlEnableState_t*);
SInt32 Nvml_DeviceGetSamples(nvmlDevice_t, nvmlSamplingType_t, unsigned long long, nvmlValueType_t*, unsigned int*, nvmlSample_t*);
SInt32 Nvml_DeviceGetSerial(nvmlDevice_t, char*, unsigned int);
SInt32 Nvml_DeviceGetSupportedClocksThrottleReasons(nvmlDevice_t, unsigned long long*);
SInt32 Nvml_DeviceGetSupportedGraphicsClocks(nvmlDevice_t, unsigned int, unsigned int*, unsigned int*);
SInt32 Nvml_DeviceGetSupportedMemoryClocks(nvmlDevice_t, unsigned int*, unsigned int*);
SInt32 Nvml_DeviceGetTemperature(nvmlDevice_t, nvmlTemperatureSensors_t, unsigned int*);
SInt32 Nvml_DeviceGetTemperatureThreshold(nvmlDevice_t, nvmlTemperatureThresholds_t, unsigned int*);
SInt32 Nvml_DeviceGetTopologyCommonAncestor(nvmlDevice_t, nvmlDevice_t, nvmlGpuTopologyLevel_t*);
SInt32 Nvml_DeviceGetTopologyNearestGpus(nvmlDevice_t, nvmlGpuTopologyLevel_t, unsigned int*, nvmlDevice_t*);
SInt32 Nvml_DeviceGetTotalEccErrors(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, unsigned long long*);
SInt32 Nvml_DeviceGetUUID(nvmlDevice_t, char*, unsigned int);
SInt32 Nvml_DeviceGetUtilizationRates(nvmlDevice_t, nvmlUtilization_t*);
SInt32 Nvml_DeviceGetVbiosVersion(nvmlDevice_t, char*, unsigned int);
SInt32 Nvml_DeviceGetViolationStatus(nvmlDevice_t, nvmlPerfPolicyType_t, nvmlViolationTime_t*);
SInt32 Nvml_DeviceOnSameBoard(nvmlDevice_t, nvmlDevice_t, int*);
SInt32 Nvml_DeviceResetApplicationsClocks(nvmlDevice_t);
SInt32 Nvml_DeviceSetAutoBoostedClocksEnabled(nvmlDevice_t, nvmlEnableState_t);
SInt32 Nvml_DeviceSetCpuAffinity(nvmlDevice_t);
SInt32 Nvml_DeviceSetDefaultAutoBoostedClocksEnabled(nvmlDevice_t, nvmlEnableState_t, unsigned int);
SInt32 Nvml_DeviceValidateInforom(nvmlDevice_t);
SInt32 Nvml_SystemGetTopologyGpuSet(unsigned int, unsigned int*, nvmlDevice_t*);
SInt32 Nvml_UnitSetLedState(nvmlUnit_t, nvmlLedColor_t);
SInt32 Nvml_DeviceClearEccErrorCounts(nvmlDevice_t, nvmlEccCounterType_t);
SInt32 Nvml_DeviceSetAPIRestriction(nvmlDevice_t, nvmlRestrictedAPI_t, nvmlEnableState_t);
SInt32 Nvml_DeviceSetApplicationsClocks(nvmlDevice_t, unsigned int, unsigned int);
SInt32 Nvml_DeviceSetComputeMode(nvmlDevice_t, nvmlComputeMode_t);
SInt32 Nvml_DeviceSetDriverModel(nvmlDevice_t, nvmlDriverModel_t, unsigned int);
SInt32 Nvml_DeviceSetEccMode(nvmlDevice_t, nvmlEnableState_t);
SInt32 Nvml_DeviceSetGpuOperationMode(nvmlDevice_t, nvmlGpuOperationMode_t);
SInt32 Nvml_DeviceSetPersistenceMode(nvmlDevice_t, nvmlEnableState_t);
SInt32 Nvml_DeviceSetPowerManagementLimit(nvmlDevice_t, unsigned int);
SInt32 Nvml_DeviceGetSupportedEventTypes(nvmlDevice_t, unsigned long long*);
SInt32 Nvml_DeviceRegisterEvents(nvmlDevice_t, unsigned long long, nvmlEventSet_t);
SInt32 Nvml_EventSetCreate(nvmlEventSet_t*);
SInt32 Nvml_EventSetFree(nvmlEventSet_t);
SInt32 Nvml_EventSetWait(nvmlEventSet_t, nvmlEventData_t*, unsigned int);

#endif

