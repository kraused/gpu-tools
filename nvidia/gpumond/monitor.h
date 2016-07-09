
#ifndef GPUMOND_MONITOR_H_INCLUDED
#define GPUMOND_MONITOR_H_INCLUDED 1

#include "config.h"
#include "platform.h"
#include "nvmlapi.h"

struct Gpumond_Logging;
struct Gpumond_Output;

struct _Gpumond_Processinfo
{
	/* Types are dictated by the nvmlProcessInfo_t struct.
	 */
	UInt32					pid;
	UInt64					memory_b;
};

struct _Gpumond_Monitor_Device_Data
{
	nvmlDevice_t				handle;

	SInt64					streaming_mp_clock;
	SInt64					memory_clock;

	SInt32					pcie_link_gen;
	SInt32					pcie_link_width;
	/* Not support on K80.
	SInt32					pcie_throughput_tx_kbps;
	SInt32					pcie_throughput_rx_kbps;
	*/

	UInt64					clocks_throttle_reason;

	SInt64					mem_total_b;
	SInt64					mem_free_b;
	SInt64					mem_used_b;

	SInt32					performance_state;

	/* Not supported on K80.
	SInt32					fan_speed;
	*/
	SInt32					power_usage;
	SInt32					temperature;

	SInt32					gpu_utilization_rate;
	SInt32					mem_utilization_rate;

	/* Not supported on K80.
	struct { UInt64 ref, violation; }	throttle_duration_power;
	struct { UInt64 ref, violation; }	throttle_duration_thermal;
	*/

	SInt32					retired_pages_sbe;
	SInt32					retired_pages_dbe;
	SInt32					retirement_is_pending;

	UInt64					ecc_err_count_volatile_device_mem_sbe;
	UInt64					ecc_err_count_volatile_device_mem_dbe;
	/* L1 and L2 cache, register file and texture */
	UInt64					ecc_err_count_volatile_other_sbe;
	UInt64					ecc_err_count_volatile_other_dbe;
	UInt64					ecc_err_count_aggregate_device_mem_sbe;
	UInt64					ecc_err_count_aggregate_device_mem_dbe;
	UInt64					ecc_err_count_aggregate_other_sbe;
	UInt64					ecc_err_count_aggregate_other_dbe;

	SInt32					nprocs;
	struct _Gpumond_Processinfo		procs[GPUMOND_MAX_PROCS_PER_DEVICE];
};

struct Gpumond_Monitor_Data
{
	struct { SInt64 sec, usec; }		timestamp;
	SInt32					ndevices;
	struct _Gpumond_Monitor_Device_Data	devices[GPUMOND_MAX_DEVICES];
};


SInt32 Gpumond_Monitor_Init(struct Gpumond_Monitor_Data *self,
                            struct Gpumond_Logging *logging);
SInt32 Gpumond_Monitor_Fini(struct Gpumond_Monitor_Data *self,
                            struct Gpumond_Logging *logging);

/* Collect data.
 */
SInt32 Gpumond_Monitor_Collect(struct Gpumond_Monitor_Data *self,
                               struct Gpumond_Logging *logging);

SInt32 Gpumond_Monitor_Print(struct Gpumond_Monitor_Data *self,
                             struct Gpumond_Output *output,
                             struct Gpumond_Logging *logging);

#endif

