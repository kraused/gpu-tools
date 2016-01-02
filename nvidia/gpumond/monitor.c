
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "monitor.h"
#include "logging.h"
#include "output.h"

#undef  NVML_CALL
#define NVML_CALL(FUNCTION, ...)						\
	do {									\
		err = FUNCTION(__VA_ARGS__); 					\
		if (UNLIKELY(err)) { 						\
			GPUMOND_LOGGING_ERROR(logging, Last_Nvml_Error());	\
		}								\
	} while(0)								\

static SInt32 _Collect(struct _Gpumond_Monitor_Device_Data *self,
                       struct Gpumond_Logging *logging)
{
	SInt32 err;
	unsigned int ui32;
	unsigned long long ull;
	nvmlMemory_t mem;
	nvmlPstates_t pstate;
	nvmlUtilization_t utilization;
	/* Not supported on K80
	nvmlViolationTime_t vt;
	*/

	NVML_CALL(Nvml_DeviceGetClockInfo, self->handle, NVML_CLOCK_SM, &ui32);
	self->streaming_mp_clock = ui32;

	NVML_CALL(Nvml_DeviceGetClockInfo, self->handle, NVML_CLOCK_MEM, &ui32);
	self->memory_clock = ui32;

	ui32 = GPUMOND_MAX_PROCS_PER_DEVICE;
	NVML_CALL(Nvml_DeviceGetComputeRunningProcesses, self->handle, &ui32, (nvmlProcessInfo_t *)self->procs);
	self->nprocs = ui32;

	if (UNLIKELY(self->nprocs > GPUMOND_MAX_PROCS_PER_DEVICE)) {
		GPUMOND_LOGGING_ERROR(logging, "Number of processes exceeds GPUMOND_MAX_PROCS_PER_DEVICE (%d)", self->nprocs);
		self->nprocs = GPUMOND_MAX_PROCS_PER_DEVICE;
	}

	NVML_CALL(Nvml_DeviceGetCurrPcieLinkGeneration, self->handle, &ui32);
	self->pcie_link_gen = ui32;

	NVML_CALL(Nvml_DeviceGetCurrPcieLinkWidth, self->handle, &ui32);
	self->pcie_link_width = ui32;

	/* Not supported on K80
	NVML_CALL(Nvml_DeviceGetPcieThroughput, self->handle, NVML_PCIE_UTIL_TX_BYTES, &ui32);
	self->pcie_throughput_tx_kbps = ui32;

	NVML_CALL(Nvml_DeviceGetPcieThroughput, self->handle, NVML_PCIE_UTIL_RX_BYTES, &ui32);
	self->pcie_throughput_rx_kbps = ui32;
	*/

	NVML_CALL(Nvml_DeviceGetCurrentClocksThrottleReasons, self->handle, &ull);
	self->clocks_throttle_reason = ull;

	/* Not supported on K80.
	NVML_CALL(Nvml_DeviceGetFanSpeed, self->handle, &ui32);
	self->fan_speed = ui32;
	*/

	NVML_CALL(Nvml_DeviceGetMemoryInfo, self->handle, &mem);
	self->mem_total_b = mem.total;
	self->mem_free_b  = mem.free;
	self->mem_used_b  = mem.used;

	NVML_CALL(Nvml_DeviceGetPerformanceState, self->handle, &pstate);
	self->performance_state = pstate;

	NVML_CALL(Nvml_DeviceGetPowerUsage, self->handle, &ui32);
	self->power_usage = ui32;

	NVML_CALL(Nvml_DeviceGetTemperature, self->handle, NVML_TEMPERATURE_GPU, &ui32);
	self->temperature = ui32;

	NVML_CALL(Nvml_DeviceGetUtilizationRates, self->handle, &utilization);
	self->gpu_utilization_rate = utilization.gpu;
	self->mem_utilization_rate = utilization.memory;

	/* Not supported on K80
	NVML_CALL(Nvml_DeviceGetViolationStatus, self->handle, NVML_PERF_POLICY_POWER, &vt);
	self->throttle_duration_power.ref       = vt.referenceTime;
	self->throttle_duration_power.violation = vt.violationTime;

	NVML_CALL(Nvml_DeviceGetViolationStatus, self->handle, NVML_PERF_POLICY_THERMAL, &vt);
	self->throttle_duration_thermal.ref       = vt.referenceTime;
	self->throttle_duration_thermal.violation = vt.violationTime;
	*/

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
		GPUMOND_LOGGING_ERROR(logging, Last_Nvml_Error());
		return err;
	}

	count = 0;
	err = Nvml_DeviceGetCount(&count);
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(logging, Last_Nvml_Error());
		return err;
	}

	self->ndevices = count;

	for (i = 0; i < self->ndevices; ++i) {
		err = Nvml_DeviceGetHandleByIndex(i, &self->devices[i].handle);
		if (UNLIKELY(err)) {
			GPUMOND_LOGGING_ERROR(logging, Last_Nvml_Error());
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
		GPUMOND_LOGGING_ERROR(logging, Last_Nvml_Error());
		return err;
	}

	return 0;
}

SInt32 Gpumond_Monitor_Collect(struct Gpumond_Monitor_Data *self,
                               struct Gpumond_Logging *logging)
{
	SInt32 err;
	SInt32 i;

	for (i = 0; i < self->ndevices; ++i) {
		err = _Collect(&self->devices[i], logging);
		if (UNLIKELY(err)) {
			GPUMOND_LOGGING_ERROR(logging, Last_Nvml_Error());
			return err;
		}
	}

	return 0;
}

SInt32 _Serialize_Json(struct Gpumond_Monitor_Data *self, char *buf, SInt64 len)
{
	SInt32 i, j;

#undef  PUSH
#define PUSH(STRING)	do { SInt64 _push_n = strlen(buf); strcpy(buf + _push_n, STRING); } while(0)

#undef  COMMA
#define COMMA		do { SInt64 _push_n = strlen(buf); buf[_push_n] = ','; } while(0)

#undef  KV
#define KV(S, X)	do { SInt64 _push_n = strlen(buf); 							\
			     snprintf(buf + _push_n, len - _push_n, "\"" #X "\":%ld", (SInt64 )S.X); } while(0)

	buf[0] = 0;

	PUSH("{\"devices\": [");
	for (i = 0; i < self->ndevices; ++i) {
		PUSH("{");
		KV(self->devices[i], streaming_mp_clock); COMMA;
		KV(self->devices[i], streaming_mp_clock); COMMA;
		KV(self->devices[i], memory_clock); COMMA;
		KV(self->devices[i], pcie_link_gen); PUSH(", ");
		KV(self->devices[i], pcie_link_width); COMMA;
		KV(self->devices[i], clocks_throttle_reason); COMMA;
		KV(self->devices[i], mem_total_b); COMMA;
		KV(self->devices[i], mem_free_b); COMMA;
		KV(self->devices[i], mem_used_b); COMMA;
		KV(self->devices[i], performance_state); COMMA;
		KV(self->devices[i], power_usage); COMMA;
		KV(self->devices[i], temperature); COMMA;
		KV(self->devices[i], gpu_utilization_rate); COMMA;
		KV(self->devices[i], mem_utilization_rate); COMMA;

		PUSH("\"procs\":[");
		for (j = 0; j < self->devices[i].nprocs; ++j) {
			PUSH("{");
			KV(self->devices[i].procs[j], pid); COMMA;
			KV(self->devices[i].procs[j], memory_b);
			PUSH("}");
			if ((j + 1) < self->devices[i].nprocs) {
				COMMA;
			}
		}
		PUSH("]}");
		if ((i + 1) < self->ndevices) {
			COMMA;
		}
	}
	PUSH("]}");

	return 0;
}

SInt32 Gpumond_Monitor_Print(struct Gpumond_Monitor_Data *self,
                             struct Gpumond_Output *output,
                             struct Gpumond_Logging *logging)
{
	/* Temporary.
	 */
	static char buf[8196];
	SInt32 n;
	SInt32 err;

	_Serialize_Json(self, buf, sizeof(buf));

	n = strlen(buf);
	if (UNLIKELY(n >= sizeof(buf) - 2)) {
		GPUMOND_LOGGING_ERROR(logging, "Buffer overrun");
		_exit(1);
	}

	buf[n++] = '\n';
	buf[n] = 0;

	err = GPUMOND_OUTPUT_WRITE(output, buf, strlen(buf));
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(logging, "Failed to write output: %d", err);
		return err;
	}	

	return 0;
}

