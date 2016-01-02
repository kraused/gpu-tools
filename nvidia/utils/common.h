
#ifndef NVIDIA_UTILS_COMMON_H_INCLUDED
#define NVIDIA_UTILS_COMMON_H_INCLUDED 1

#include <nvidia/gdk/nvml.h>

#define LIKELY(X)	__builtin_expect(!!(X), 1)
#define UNLIKELY(X)	__builtin_expect(!!(X), 0)

typedef void (*Nvml_Return_Handling_Function)(const char *caller,
                                              const char *callee,
                                              nvmlReturn_t err,
                                              const char *errstr);

extern Nvml_Return_Handling_Function nvml_return_handler;

void Nvml_Default_Return_Handler(const char *caller,
                                 const char *callee,
                                 nvmlReturn_t err,
                                 const char *errstr);

void Nvml_Debug_Return_Handler(const char *caller,
                               const char *callee,
                               nvmlReturn_t err,
                               const char *errstr);

const char *Nvml_Convert_EnableState(nvmlEnableState_t x);

/* Wrapper around NVML library calls.
 *
 * Generated with python2 wrap-nvml.py --prototypes.
 */

void Nvml_DeviceClearAccountingPids(nvmlDevice_t);
void Nvml_DeviceGetAccountingBufferSize(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetAccountingMode(nvmlDevice_t, nvmlEnableState_t*);
void Nvml_DeviceGetAccountingPids(nvmlDevice_t, unsigned int*, unsigned int*);
void Nvml_DeviceGetAccountingStats(nvmlDevice_t, unsigned int, nvmlAccountingStats_t*);
void Nvml_DeviceSetAccountingMode(nvmlDevice_t, nvmlEnableState_t);
void Nvml_Init();
void Nvml_Shutdown();
void Nvml_SystemGetDriverVersion(char*, unsigned int);
void Nvml_SystemGetNVMLVersion(char*, unsigned int);
void Nvml_SystemGetProcessName(unsigned int, char*, unsigned int);
void Nvml_SystemGetHicVersion(unsigned int*, nvmlHwbcEntry_t*);
void Nvml_UnitGetCount(unsigned int*);
void Nvml_UnitGetDevices(nvmlUnit_t, unsigned int*, nvmlDevice_t*);
void Nvml_UnitGetFanSpeedInfo(nvmlUnit_t, nvmlUnitFanSpeeds_t*);
void Nvml_UnitGetHandleByIndex(unsigned int, nvmlUnit_t*);
void Nvml_UnitGetLedState(nvmlUnit_t, nvmlLedState_t*);
void Nvml_UnitGetPsuInfo(nvmlUnit_t, nvmlPSUInfo_t*);
void Nvml_UnitGetTemperature(nvmlUnit_t, unsigned int, unsigned int*);
void Nvml_UnitGetUnitInfo(nvmlUnit_t, nvmlUnitInfo_t*);
void Nvml_DeviceClearCpuAffinity(nvmlDevice_t);
void Nvml_DeviceGetAPIRestriction(nvmlDevice_t, nvmlRestrictedAPI_t, nvmlEnableState_t*);
void Nvml_DeviceGetApplicationsClock(nvmlDevice_t, nvmlClockType_t, unsigned int*);
void Nvml_DeviceGetAutoBoostedClocksEnabled(nvmlDevice_t, nvmlEnableState_t*, nvmlEnableState_t*);
void Nvml_DeviceGetBAR1MemoryInfo(nvmlDevice_t, nvmlBAR1Memory_t*);
void Nvml_DeviceGetBoardId(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetBrand(nvmlDevice_t, nvmlBrandType_t*);
void Nvml_DeviceGetBridgeChipInfo(nvmlDevice_t, nvmlBridgeChipHierarchy_t*);
void Nvml_DeviceGetClockInfo(nvmlDevice_t, nvmlClockType_t, unsigned int*);
void Nvml_DeviceGetComputeMode(nvmlDevice_t, nvmlComputeMode_t*);
void Nvml_DeviceGetComputeRunningProcesses(nvmlDevice_t, unsigned int*, nvmlProcessInfo_t*);
void Nvml_DeviceGetCount(unsigned int*);
void Nvml_DeviceGetCpuAffinity(nvmlDevice_t, unsigned int, unsigned long*);
void Nvml_DeviceGetCurrPcieLinkGeneration(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetCurrPcieLinkWidth(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetCurrentClocksThrottleReasons(nvmlDevice_t, unsigned long long*);
void Nvml_DeviceGetDecoderUtilization(nvmlDevice_t, unsigned int*, unsigned int*);
void Nvml_DeviceGetDefaultApplicationsClock(nvmlDevice_t, nvmlClockType_t, unsigned int*);
void Nvml_DeviceGetDetailedEccErrors(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, nvmlEccErrorCounts_t*);
void Nvml_DeviceGetDisplayActive(nvmlDevice_t, nvmlEnableState_t*);
void Nvml_DeviceGetDisplayMode(nvmlDevice_t, nvmlEnableState_t*);
void Nvml_DeviceGetDriverModel(nvmlDevice_t, nvmlDriverModel_t*, nvmlDriverModel_t*);
void Nvml_DeviceGetEccMode(nvmlDevice_t, nvmlEnableState_t*, nvmlEnableState_t*);
void Nvml_DeviceGetEncoderUtilization(nvmlDevice_t, unsigned int*, unsigned int*);
void Nvml_DeviceGetEnforcedPowerLimit(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetFanSpeed(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetGpuOperationMode(nvmlDevice_t, nvmlGpuOperationMode_t*, nvmlGpuOperationMode_t*);
void Nvml_DeviceGetGraphicsRunningProcesses(nvmlDevice_t, unsigned int*, nvmlProcessInfo_t*);
void Nvml_DeviceGetHandleByIndex(unsigned int, nvmlDevice_t*);
void Nvml_DeviceGetHandleByPciBusId(const char*, nvmlDevice_t*);
void Nvml_DeviceGetHandleBySerial(const char*, nvmlDevice_t*);
void Nvml_DeviceGetHandleByUUID(const char*, nvmlDevice_t*);
void Nvml_DeviceGetIndex(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetInforomConfigurationChecksum(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetInforomImageVersion(nvmlDevice_t, char*, unsigned int);
void Nvml_DeviceGetInforomVersion(nvmlDevice_t, nvmlInforomObject_t, char*, unsigned int);
void Nvml_DeviceGetMaxClockInfo(nvmlDevice_t, nvmlClockType_t, unsigned int*);
void Nvml_DeviceGetMaxPcieLinkGeneration(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetMaxPcieLinkWidth(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetMemoryErrorCounter(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, nvmlMemoryLocation_t, unsigned long long*);
void Nvml_DeviceGetMemoryInfo(nvmlDevice_t, nvmlMemory_t*);
void Nvml_DeviceGetMinorNumber(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetMultiGpuBoard(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetName(nvmlDevice_t, char*, unsigned int);
void Nvml_DeviceGetPciInfo(nvmlDevice_t, nvmlPciInfo_t*);
void Nvml_DeviceGetPcieReplayCounter(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetPcieThroughput(nvmlDevice_t, nvmlPcieUtilCounter_t, unsigned int*);
void Nvml_DeviceGetPerformanceState(nvmlDevice_t, nvmlPstates_t*);
void Nvml_DeviceGetPersistenceMode(nvmlDevice_t, nvmlEnableState_t*);
void Nvml_DeviceGetPowerManagementDefaultLimit(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetPowerManagementLimit(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetPowerManagementLimitConstraints(nvmlDevice_t, unsigned int*, unsigned int*);
void Nvml_DeviceGetPowerManagementMode(nvmlDevice_t, nvmlEnableState_t*);
void Nvml_DeviceGetPowerState(nvmlDevice_t, nvmlPstates_t*);
void Nvml_DeviceGetPowerUsage(nvmlDevice_t, unsigned int*);
void Nvml_DeviceGetRetiredPages(nvmlDevice_t, nvmlPageRetirementCause_t, unsigned int*, unsigned long long*);
void Nvml_DeviceGetRetiredPagesPendingStatus(nvmlDevice_t, nvmlEnableState_t*);
void Nvml_DeviceGetSamples(nvmlDevice_t, nvmlSamplingType_t, unsigned long long, nvmlValueType_t*, unsigned int*, nvmlSample_t*);
void Nvml_DeviceGetSerial(nvmlDevice_t, char*, unsigned int);
void Nvml_DeviceGetSupportedClocksThrottleReasons(nvmlDevice_t, unsigned long long*);
void Nvml_DeviceGetSupportedGraphicsClocks(nvmlDevice_t, unsigned int, unsigned int*, unsigned int*);
void Nvml_DeviceGetSupportedMemoryClocks(nvmlDevice_t, unsigned int*, unsigned int*);
void Nvml_DeviceGetTemperature(nvmlDevice_t, nvmlTemperatureSensors_t, unsigned int*);
void Nvml_DeviceGetTemperatureThreshold(nvmlDevice_t, nvmlTemperatureThresholds_t, unsigned int*);
void Nvml_DeviceGetTopologyCommonAncestor(nvmlDevice_t, nvmlDevice_t, nvmlGpuTopologyLevel_t*);
void Nvml_DeviceGetTopologyNearestGpus(nvmlDevice_t, nvmlGpuTopologyLevel_t, unsigned int*, nvmlDevice_t*);
void Nvml_DeviceGetTotalEccErrors(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, unsigned long long*);
void Nvml_DeviceGetUUID(nvmlDevice_t, char*, unsigned int);
void Nvml_DeviceGetUtilizationRates(nvmlDevice_t, nvmlUtilization_t*);
void Nvml_DeviceGetVbiosVersion(nvmlDevice_t, char*, unsigned int);
void Nvml_DeviceGetViolationStatus(nvmlDevice_t, nvmlPerfPolicyType_t, nvmlViolationTime_t*);
void Nvml_DeviceOnSameBoard(nvmlDevice_t, nvmlDevice_t, int*);
void Nvml_DeviceResetApplicationsClocks(nvmlDevice_t);
void Nvml_DeviceSetAutoBoostedClocksEnabled(nvmlDevice_t, nvmlEnableState_t);
void Nvml_DeviceSetCpuAffinity(nvmlDevice_t);
void Nvml_DeviceSetDefaultAutoBoostedClocksEnabled(nvmlDevice_t, nvmlEnableState_t, unsigned int);
void Nvml_DeviceValidateInforom(nvmlDevice_t);
void Nvml_SystemGetTopologyGpuSet(unsigned int, unsigned int*, nvmlDevice_t*);
void Nvml_UnitSetLedState(nvmlUnit_t, nvmlLedColor_t);
void Nvml_DeviceClearEccErrorCounts(nvmlDevice_t, nvmlEccCounterType_t);
void Nvml_DeviceSetAPIRestriction(nvmlDevice_t, nvmlRestrictedAPI_t, nvmlEnableState_t);
void Nvml_DeviceSetApplicationsClocks(nvmlDevice_t, unsigned int, unsigned int);
void Nvml_DeviceSetComputeMode(nvmlDevice_t, nvmlComputeMode_t);
void Nvml_DeviceSetDriverModel(nvmlDevice_t, nvmlDriverModel_t, unsigned int);
void Nvml_DeviceSetEccMode(nvmlDevice_t, nvmlEnableState_t);
void Nvml_DeviceSetGpuOperationMode(nvmlDevice_t, nvmlGpuOperationMode_t);
void Nvml_DeviceSetPersistenceMode(nvmlDevice_t, nvmlEnableState_t);
void Nvml_DeviceSetPowerManagementLimit(nvmlDevice_t, unsigned int);
void Nvml_DeviceGetSupportedEventTypes(nvmlDevice_t, unsigned long long*);
void Nvml_DeviceRegisterEvents(nvmlDevice_t, unsigned long long, nvmlEventSet_t);
void Nvml_EventSetCreate(nvmlEventSet_t*);
void Nvml_EventSetFree(nvmlEventSet_t);
void Nvml_EventSetWait(nvmlEventSet_t, nvmlEventData_t*, unsigned int);

#endif

