
#ifndef GPUMOND_CONFIG_H_INCLUDED
#define GPUMOND_CONFIG_H_INCLUDED 1

#undef  GPUMOND_SYSLOG_IDENT
#define GPUMOND_SYSLOG_IDENT "gpumond"

/* Maximal line length supported by the Gpumond_Logging interface. Run
 * python2 -c 'print("a"*1024)' to get an idea what the number means.
 * Note that additional restrictions might be imposed by the system (e.g.,
 * when logging via syslog).
 */
#undef  GPUMOND_LOGGING_MAX_LINE_LEN
#define GPUMOND_LOGGING_MAX_LINE_LEN		1024

/* Default timer period in seconds.
 */
#undef  GPUMOND_TIMER_DEFAULT_PERIOD_SEC
#define GPUMOND_TIMER_DEFAULT_PERIOD_SEC	2

/* Default maximal allowed deviation in microseconds.
 */
#undef  GPUMOND_DEFAULT_MAX_DEVIATION_USEC
#define GPUMOND_DEFAULT_MAX_DEVIATION_USEC	100

/* Maximal number of GPU hosts/devices supported by the
 * daemon.
 */
#undef  GPUMOND_MAX_DEVICES
#define GPUMOND_MAX_DEVICES			16

/* Maximal number of processes with active context per GPU.
 */
#undef  GPUMOND_MAX_PROCS_PER_DEVICE
#define GPUMOND_MAX_PROCS_PER_DEVICE		64

/* Maximal string length for the NVML error.
 */
#undef  GPUMOND_NVML_ERROR_STRLEN
#define GPUMOND_NVML_ERROR_STRLEN		2048

#endif

