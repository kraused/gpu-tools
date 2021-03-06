
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>

#include "monitor.h"
#include "logging.h"
#include "output.h"

#undef	HANDLE_UNSUPPORTED_FIELD
#define	HANDLE_UNSUPPORTED_FIELD(FIELD, FUNCTION)										\
	if (UNLIKELY(NVML_ERROR_NOT_SUPPORTED == Last_Nvml_Error())) {								\
		self->supported[_GPUMOND_DEVICE_DATA_FIELDS_ ## FIELD] = 0;							\
		GPUMOND_LOGGING_ERROR(logging, "Unsupported field \"%s\" (function %s) will be skipped", #FIELD, #FUNCTION);	\
	} 															\

#undef  NVML_CALL
#define NVML_CALL(FIELD, FUNCTION, ...)									\
	do {												\
		if (self->supported[_GPUMOND_DEVICE_DATA_FIELDS_ ## FIELD]) {				\
			err = FUNCTION(__VA_ARGS__); 							\
			if (UNLIKELY(err)) { 								\
				HANDLE_UNSUPPORTED_FIELD(FIELD, FUNCTION)				\
				else {									\
					GPUMOND_LOGGING_ERROR(logging, Last_Nvml_Error_Msg());		\
				}									\
			}										\
		}											\
	} while(0)											\

static nvmlMemoryLocation_t _other_mem_locations[] = { NVML_MEMORY_LOCATION_L1_CACHE,
                                                       NVML_MEMORY_LOCATION_L2_CACHE,
                                                       NVML_MEMORY_LOCATION_REGISTER_FILE,
                                                       NVML_MEMORY_LOCATION_TEXTURE_MEMORY };

static SInt32 _Gpumond_Monitor_Device_Data_Init(struct _Gpumond_Monitor_Device_Data *self,
                                                SInt32 index,
                                                struct Gpumond_Logging *logging)
{
	SInt32 err, i;

	self->index = index;

	err = Nvml_DeviceGetHandleByIndex(self->index, &self->handle);
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(logging, Last_Nvml_Error_Msg());
		return err;
	}

	for (i = 0; i < _GPUMOND_DEVICE_DATA_FIELDS_SIZE; ++i) {
		self->supported[i] = 1;
	}

	NVML_CALL(name, Nvml_DeviceGetName, self->handle, self->name, 64);

	return 0;
}

static SInt32 _Collect(struct _Gpumond_Monitor_Device_Data *self,
                       struct Gpumond_Logging *logging)
{
	SInt32 err, i;
	unsigned int ui32;
	unsigned long long ull;
	nvmlMemory_t mem;
	nvmlPstates_t pstate;
	nvmlUtilization_t utilization;
	nvmlEnableState_t enabled;
	nvmlViolationTime_t vt;

	NVML_CALL(streaming_mp_clock, Nvml_DeviceGetClockInfo, self->handle, NVML_CLOCK_SM, &ui32);
	self->streaming_mp_clock = ui32;

	NVML_CALL(memory_clock, Nvml_DeviceGetClockInfo, self->handle, NVML_CLOCK_MEM, &ui32);
	self->memory_clock = ui32;

	ui32 = GPUMOND_MAX_PROCS_PER_DEVICE;
	NVML_CALL(procs, Nvml_DeviceGetComputeRunningProcesses, self->handle, &ui32, (nvmlProcessInfo_t *)self->procs);
	self->nprocs = ui32;

	if (UNLIKELY(self->nprocs > GPUMOND_MAX_PROCS_PER_DEVICE)) {
		GPUMOND_LOGGING_ERROR(logging, "Number of processes exceeds GPUMOND_MAX_PROCS_PER_DEVICE (%d)", self->nprocs);
		self->nprocs = GPUMOND_MAX_PROCS_PER_DEVICE;
	}

	NVML_CALL(pcie_link_gen, Nvml_DeviceGetCurrPcieLinkGeneration, self->handle, &ui32);
	self->pcie_link_gen = ui32;

	NVML_CALL(pcie_link_width, Nvml_DeviceGetCurrPcieLinkWidth, self->handle, &ui32);
	self->pcie_link_width = ui32;

	NVML_CALL(pcie_throughput_tx_kbps, Nvml_DeviceGetPcieThroughput, self->handle, NVML_PCIE_UTIL_TX_BYTES, &ui32);
	self->pcie_throughput_tx_kbps = ui32;

	NVML_CALL(pcie_throughput_rx_kbps, Nvml_DeviceGetPcieThroughput, self->handle, NVML_PCIE_UTIL_RX_BYTES, &ui32);
	self->pcie_throughput_rx_kbps = ui32;

	NVML_CALL(clocks_throttle_reason, Nvml_DeviceGetCurrentClocksThrottleReasons, self->handle, &ull);
	self->clocks_throttle_reason = ull;

	NVML_CALL(fan_speed, Nvml_DeviceGetFanSpeed, self->handle, &ui32);
	self->fan_speed = ui32;

	NVML_CALL(mem, Nvml_DeviceGetMemoryInfo, self->handle, &mem);
	self->mem_total_b = mem.total;
	self->mem_free_b  = mem.free;
	self->mem_used_b  = mem.used;

	NVML_CALL(performance_state, Nvml_DeviceGetPerformanceState, self->handle, &pstate);
	self->performance_state = pstate;

	NVML_CALL(power_usage, Nvml_DeviceGetPowerUsage, self->handle, &ui32);
	self->power_usage = ui32;

	NVML_CALL(temperature, Nvml_DeviceGetTemperature, self->handle, NVML_TEMPERATURE_GPU, &ui32);
	self->temperature = ui32;

	NVML_CALL(utilization, Nvml_DeviceGetUtilizationRates, self->handle, &utilization);
	self->gpu_utilization_rate = utilization.gpu;
	self->mem_utilization_rate = utilization.memory;

	NVML_CALL(throttle_duration_power, Nvml_DeviceGetViolationStatus, self->handle, NVML_PERF_POLICY_POWER, &vt);
	self->throttle_duration_power.ref       = vt.referenceTime;
	self->throttle_duration_power.violation = vt.violationTime;

	NVML_CALL(throttle_duration_thermal, Nvml_DeviceGetViolationStatus, self->handle, NVML_PERF_POLICY_THERMAL, &vt);
	self->throttle_duration_thermal.ref       = vt.referenceTime;
	self->throttle_duration_thermal.violation = vt.violationTime;

	ui32 = 0;
	err = Nvml_DeviceGetRetiredPages(self->handle,
			NVML_PAGE_RETIREMENT_CAUSE_MULTIPLE_SINGLE_BIT_ECC_ERRORS, &ui32, NULL);
	/* We do not query the addresses so NVML_ERROR_INSUFFICIENT_SIZE is a perfectly fine
	 * return value.
	 */
	if (UNLIKELY(err)) {
		if (UNLIKELY(NVML_ERROR_INSUFFICIENT_SIZE != Last_Nvml_Error())) {
			HANDLE_UNSUPPORTED_FIELD(retired_pages_sbe, Nvml_DeviceGetRetiredPages)
			else {
				GPUMOND_LOGGING_ERROR(logging, Last_Nvml_Error_Msg());
			}
		}
	}
	self->retired_pages_sbe = ui32;

	ui32 = 0;
	err = Nvml_DeviceGetRetiredPages(self->handle,
			NVML_PAGE_RETIREMENT_CAUSE_DOUBLE_BIT_ECC_ERROR, &ui32, NULL);
	if (UNLIKELY(err)) {
		if (UNLIKELY(NVML_ERROR_INSUFFICIENT_SIZE != Last_Nvml_Error())) {
			HANDLE_UNSUPPORTED_FIELD(retired_pages_dbe, Nvml_DeviceGetRetiredPages)
			else {
				GPUMOND_LOGGING_ERROR(logging, Last_Nvml_Error_Msg());
			}
		}
	}
	self->retired_pages_dbe = ui32;

	NVML_CALL(retirement_is_pending, Nvml_DeviceGetRetiredPagesPendingStatus, self->handle, &enabled);
	self->retirement_is_pending = enabled;

	NVML_CALL(ecc_err_count_volatile_device_mem_sbe,
			Nvml_DeviceGetMemoryErrorCounter, self->handle,
			NVML_MEMORY_ERROR_TYPE_CORRECTED,
			NVML_VOLATILE_ECC,
			NVML_MEMORY_LOCATION_DEVICE_MEMORY, &ull);
	self->ecc_err_count_volatile_device_mem_sbe = ull;

	NVML_CALL(ecc_err_count_volatile_device_mem_dbe,
			Nvml_DeviceGetMemoryErrorCounter, self->handle,
			NVML_MEMORY_ERROR_TYPE_UNCORRECTED,
			NVML_VOLATILE_ECC,
			NVML_MEMORY_LOCATION_DEVICE_MEMORY, &ull);
	self->ecc_err_count_volatile_device_mem_dbe = ull;

	self->ecc_err_count_volatile_other_sbe = 0;
	self->ecc_err_count_volatile_other_dbe = 0;
	for (i = 0; i < sizeof (_other_mem_locations)/sizeof (_other_mem_locations[0]); ++i) {
		NVML_CALL(ecc_err_count_volatile_other_sbe,
				Nvml_DeviceGetMemoryErrorCounter, self->handle,
				NVML_MEMORY_ERROR_TYPE_CORRECTED,
				NVML_VOLATILE_ECC,
				_other_mem_locations[i], &ull);
		self->ecc_err_count_volatile_other_sbe += ull;

		NVML_CALL(ecc_err_count_volatile_other_dbe,
				Nvml_DeviceGetMemoryErrorCounter, self->handle,
				NVML_MEMORY_ERROR_TYPE_UNCORRECTED,
				NVML_VOLATILE_ECC,
				_other_mem_locations[i], &ull);
		self->ecc_err_count_volatile_other_dbe += ull;
	}

	NVML_CALL(ecc_err_count_aggregate_device_mem_sbe,
			Nvml_DeviceGetMemoryErrorCounter, self->handle,
			NVML_MEMORY_ERROR_TYPE_CORRECTED,
			NVML_AGGREGATE_ECC,
			NVML_MEMORY_LOCATION_DEVICE_MEMORY, &ull);
	self->ecc_err_count_aggregate_device_mem_sbe = ull;

	NVML_CALL(ecc_err_count_aggregate_device_mem_dbe,
			Nvml_DeviceGetMemoryErrorCounter, self->handle,
			NVML_MEMORY_ERROR_TYPE_UNCORRECTED,
			NVML_AGGREGATE_ECC,
			NVML_MEMORY_LOCATION_DEVICE_MEMORY, &ull);
	self->ecc_err_count_aggregate_device_mem_dbe = ull;

	self->ecc_err_count_aggregate_other_sbe = 0;
	self->ecc_err_count_aggregate_other_dbe = 0;
	for (i = 0; i < sizeof (_other_mem_locations)/sizeof (_other_mem_locations[0]); ++i) {
		NVML_CALL(ecc_err_count_aggregate_other_sbe,
				Nvml_DeviceGetMemoryErrorCounter, self->handle,
				NVML_MEMORY_ERROR_TYPE_CORRECTED,
				NVML_AGGREGATE_ECC,
				_other_mem_locations[i], &ull);
		self->ecc_err_count_aggregate_other_sbe += ull;

		NVML_CALL(ecc_err_count_aggregate_other_dbe,
				Nvml_DeviceGetMemoryErrorCounter, self->handle,
				NVML_MEMORY_ERROR_TYPE_UNCORRECTED,
				NVML_AGGREGATE_ECC,
				_other_mem_locations[i], &ull);
		self->ecc_err_count_aggregate_other_dbe += ull;
	}

	return 0;
}

SInt32 Gpumond_Monitor_Init(struct Gpumond_Monitor_Data *self,
                            struct Gpumond_Logging *logging)
{
	SInt32 err;
	SInt32 i;
	UInt32 count;

	memset(self, 0, sizeof(struct Gpumond_Monitor_Data));

	err = Nvml_Init();
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(logging, Last_Nvml_Error_Msg());
		return err;
	}

	count = 0;
	err = Nvml_DeviceGetCount(&count);
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(logging, Last_Nvml_Error_Msg());
		return err;
	}

	self->ndevices = count;

	for (i = 0; i < self->ndevices; ++i) {
		err = _Gpumond_Monitor_Device_Data_Init(&self->devices[i], i, logging);
		if (UNLIKELY(err)) {
			GPUMOND_LOGGING_ERROR(logging, "_Gpumond_Monitor_Device_Data_Init() failed");
			return err;
		}
	}

	return 0;
}

SInt32 Gpumond_Monitor_Fini(struct Gpumond_Monitor_Data *self,
                            struct Gpumond_Logging *logging)
{
	SInt32 err;

	err = Nvml_Shutdown();
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(logging, Last_Nvml_Error_Msg());
		return err;
	}

	return 0;
}

SInt32 Gpumond_Monitor_Collect(struct Gpumond_Monitor_Data *self,
                               struct Gpumond_Logging *logging)
{
	SInt32 err;
	SInt32 i;
	struct timeval tv;
	struct timezone tz;

	err = gettimeofday(&tv, &tz);
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(logging, "gettimeofday() failed with errno %d: %s", errno, strerror(errno));
	}

	self->timestamp.sec  = tv.tv_sec;
	self->timestamp.usec = tv.tv_usec;

	for (i = 0; i < self->ndevices; ++i) {
		err = _Collect(&self->devices[i], logging);
		if (UNLIKELY(err)) {
			GPUMOND_LOGGING_ERROR(logging, "_Collect() failed");
			return err;
		}
	}

	return 0;
}

SInt64 _Serialize_Json(struct Gpumond_Monitor_Data *self, char *buf, SInt64 len)
{
	SInt32 i, j;
	SInt64 n;
	/* Helper variables for the macros. Be careful.
	 */
	SInt64 _k, _m;
	const char *_p;

	n = 0;
	buf[0] = 0;

	/* Careful: None of these macros (with the obvious exception of TERMINATE)
	 *          result in a zero-terminated string.
	 */

#undef  PUSHC
#define PUSHC(CHAR)	do { 							\
				if (UNLIKELY(n >= len)) {			\
					return -n;				\
				}						\
				buf[n] = CHAR; 					\
				++n;						\
			} while(0)

#undef	COMMA
#define COMMA		PUSHC(',')

#undef	TERMINATE
#define	TERMINATE	PUSHC('\0')

#undef	PUSHS
#define	PUSHS(STR)	do {								\
				for (_p = STR; *_p; ++_p) {				\
					PUSHC(*_p);					\
				}							\
			} while(0)


#undef	PUSHF
#define PUSHF(FMT, ...)	do {								\
				_m = len - n;						\
				_k = snprintf(buf + n, len - n,	FMT, __VA_ARGS__);	\
				if (UNLIKELY(_k < 0)) {					\
					return -1;					\
				}							\
				if (UNLIKELY(_k >= _m)) {				\
					return -n;					\
				}							\
				n += _k;						\
			} while(0)


#undef	KV
#define	KV(S, X)	PUSHF("\"" #X "\":%ld", (SInt64 )S.X)

#undef	KVSTR
#define	KVSTR(S, X)	PUSHF("\"" #X "\":\"%s\"", S.X)

#undef	KVIF
#define	KVIF(S, X)							\
	do {								\
		if (S.supported[_GPUMOND_DEVICE_DATA_FIELDS_ ## X]) { 	\
			KV(S, X); COMMA;				\
		}							\
	} while(0)

	PUSHC('{');
	PUSHF("\"timestamp\":[%ld,%ld],", (SInt64 )self->timestamp.sec, (SInt64 )self->timestamp.usec);
	PUSHS("\"devices\":");
	PUSHC('[');
	for (i = 0; i < self->ndevices; ++i) {
		PUSHC('{');
		if (self->devices[i].supported[_GPUMOND_DEVICE_DATA_FIELDS_name]) {
			KVSTR(self->devices[i], name); COMMA;
		}
		KVIF(self->devices[i], streaming_mp_clock);
		KVIF(self->devices[i], memory_clock);

		KVIF(self->devices[i], pcie_link_gen);
		KVIF(self->devices[i], pcie_link_width);
		KVIF(self->devices[i], pcie_throughput_tx_kbps);
		KVIF(self->devices[i], pcie_throughput_rx_kbps);

		KVIF(self->devices[i], clocks_throttle_reason);

		if (self->devices[i].supported[_GPUMOND_DEVICE_DATA_FIELDS_mem]) {
			KV(self->devices[i], mem_total_b); COMMA;
			KV(self->devices[i], mem_free_b);  COMMA;
			KV(self->devices[i], mem_used_b);  COMMA;
		}

		KVIF(self->devices[i], performance_state);

		KVIF(self->devices[i], fan_speed);
		KVIF(self->devices[i], power_usage);
		KVIF(self->devices[i], temperature);

		if (self->devices[i].supported[_GPUMOND_DEVICE_DATA_FIELDS_utilization]) {
			KV(self->devices[i], gpu_utilization_rate); COMMA;
			KV(self->devices[i], mem_utilization_rate); COMMA;
		}

		/* Todo: Report throttle_duration_power and throttle_duration_thermal */

		KVIF(self->devices[i], retired_pages_sbe);
		KVIF(self->devices[i], retired_pages_dbe);
		KVIF(self->devices[i], retirement_is_pending);

		KVIF(self->devices[i], ecc_err_count_volatile_device_mem_sbe);
		KVIF(self->devices[i], ecc_err_count_volatile_device_mem_dbe);
		KVIF(self->devices[i], ecc_err_count_volatile_other_sbe);
		KVIF(self->devices[i], ecc_err_count_volatile_other_dbe);
		KVIF(self->devices[i], ecc_err_count_aggregate_device_mem_sbe);
		KVIF(self->devices[i], ecc_err_count_aggregate_device_mem_dbe);
		KVIF(self->devices[i], ecc_err_count_aggregate_other_sbe);
		KVIF(self->devices[i], ecc_err_count_aggregate_other_dbe);

		if (self->devices[i].supported[_GPUMOND_DEVICE_DATA_FIELDS_procs]) {
			PUSHS("\"procs\":");
			PUSHC('[');
			for (j = 0; j < self->devices[i].nprocs; ++j) {
				PUSHC('{');
				KV(self->devices[i].procs[j], pid); COMMA;
				KV(self->devices[i].procs[j], memory_b);
				PUSHC('}');
				if ((j + 1) < self->devices[i].nprocs) {
					COMMA;
				}
			}
			PUSHC(']');
		}
		PUSHC('}');
		if ((i + 1) < self->ndevices) {
			COMMA;
		}
	}
	PUSHC(']');
	PUSHC('}');

	TERMINATE;

	return n;
}

SInt32 Gpumond_Monitor_Print(struct Gpumond_Monitor_Data *self,
                             struct Gpumond_Output *output,
                             struct Gpumond_Logging *logging)
{
	static char buf[8192];
	SInt64 n;
	SInt32 err;

	n = _Serialize_Json(self, buf, sizeof(buf));
	if (UNLIKELY(n < 0)) {
		GPUMOND_LOGGING_ERROR(logging, "_Serialize_Json reported truncation (%ld)", n);
		return -1;
	}
	--n;	/* _Serialize_Json() returns number of bytes written including
		 * the trailing zero.
		 */
	if (UNLIKELY((n + 1) >= sizeof(buf))) {
		GPUMOND_LOGGING_ERROR(logging, "Buffer is too small for trailing newline");
		return -1;
	}

	buf[n]     = '\n';
	buf[n + 1] = 0;

	err = GPUMOND_OUTPUT_WRITE(output, buf, strlen(buf));
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(logging, "Failed to write output: %d", err);
		return err;
	}

	return 0;
}

