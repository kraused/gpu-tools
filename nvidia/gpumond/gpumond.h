
#ifndef GPUMOND_GPUMOND_H_INCLUDED
#define GPUMOND_GPUMOND_H_INCLUDED 1

#include <signal.h>
#include <poll.h>
#include <sys/timerfd.h>

#include "config.h"
#include "platform.h"
#include "alloc.h"
#include "logging.h"
#include "output.h"
#include "monitor.h"

/* Application data.
 */
struct Gpumond
{
	struct Gpumond_Allocator	*alloc;
	struct Gpumond_Logging		*logging;
	struct Gpumond_Output		*output;

	struct Gpumond_Monitor_Data	data;

					/* Timer period
					 */ 
	SInt32	 			period;

					/* Maximal deviation of the sampling
					 * start from the expected time that
					 * will be tolerated. Unit: usecs
					 */
	SInt32				max_deviation_usec;

	SInt32				_sigfd;
	sigset_t			_default_signal_set;

	SInt32				_timerfd;
	struct itimerspec		_timerval;

	SInt32				_quit;

	struct pollfd			_pfds[2];
};

SInt32 Gpumond_Init(struct Gpumond *self);
SInt32 Gpumond_Fini(struct Gpumond *self);
SInt32 Gpumond_Loop(struct Gpumond *self);

#endif

