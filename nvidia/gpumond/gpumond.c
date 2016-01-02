
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <sys/signalfd.h>

#include "gpumond.h"

static SInt32 _Init_Signal_Handling(struct Gpumond *self)
{
	sigset_t all;
	SInt32 err;

	sigfillset(&all);
	err = sigprocmask(SIG_BLOCK, &all, &self->_default_signal_set);
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(self->logging, "Failed to block signals: %d (%s)", errno, strerror(errno));
		return -errno;
	}

	self->_sigfd = signalfd(-1, &all, 0);
	if (UNLIKELY(-1 == self->_sigfd)) {
		GPUMOND_LOGGING_ERROR(self->logging, "Failed to open signalfd: %d (%s)", errno, strerror(errno));
		return -errno;
	}

	return 0;
}

static SInt32 _Fini_Signal_Handling(struct Gpumond *self)
{
	SInt32 err;

	err = close(self->_sigfd);
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(self->logging, "close() failed with errno %d (%s)", errno, strerror(errno));
	}

	err = sigprocmask(SIG_BLOCK, &self->_default_signal_set, NULL);
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(self->logging, "Failed to reset default signal set");
		return -errno;
	}

	return 0;
}

static SInt32 _Create_Timer(struct Gpumond *self)
{
	self->_timerfd = timerfd_create(CLOCK_MONOTONIC, 0);
	if (UNLIKELY(-1 == self->_timerfd)) {
		GPUMOND_LOGGING_ERROR(self->logging, "Failed to open timerfd: %d (%s)", errno, strerror(errno));
		return -errno;
	}

	return 0;
}

static SInt32 _Destroy_Timer(struct Gpumond *self)
{
	SInt32 err;

	err = close(self->_timerfd);
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(self->logging, "close() failed with errno %d: %s", errno, strerror(errno));
	}

	return 0;
}

static SInt32 _Setup_Timer(struct Gpumond *self)
{
	SInt32 err;
	struct timespec tp;

	err = clock_gettime(CLOCK_MONOTONIC, &tp);
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(self->logging, "clock_gettime() failed with errno %d: %s", errno, strerror(errno));
		return -errno;
	}

	GPUMOND_LOGGING_DEBUG(self->logging, "current time = {.sec = %lld, .nsec = %lld}", tp.tv_sec, tp.tv_nsec);

	memset(&self->_timerval, 0, sizeof(self->_timerval));

	self->_timerval.it_value.tv_sec  = self->period*((SInt64 )((tp.tv_sec + self->period - 1)/self->period));
	self->_timerval.it_value.tv_nsec = 0;

	self->_timerval.it_interval.tv_sec  = self->period;
	self->_timerval.it_interval.tv_nsec = 0;

	err = timerfd_settime(self->_timerfd, TFD_TIMER_ABSTIME, &self->_timerval, NULL);
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(self->logging, "timerfd_settime() failed with errno %d: %s", errno, strerror(errno));
		return -errno;
	}

	return 0;
}

static void _Fill_Pollfds(struct Gpumond *self)
{
	self->_pfds[0].fd     = self->_sigfd;
	self->_pfds[0].events = POLLIN;

	self->_pfds[1].fd     = self->_timerfd;
	self->_pfds[1].events = POLLIN;
}

static SInt32 _Handle_Sigquit(struct Gpumond *self, SInt32 signo)
{
	self->_quit = 1;

	return 0;
}

static SInt32 _Handle_Signal(struct Gpumond *self)
{
	struct signalfd_siginfo info;
	SInt32 err;

	err = read(self->_sigfd, &info, sizeof(info));
	if (UNLIKELY(err < 0)) {
		GPUMOND_LOGGING_ERROR(self->logging, "read() failed with errno %d: %s", errno, strerror(errno));
		return -errno;
	}
	if (err != sizeof(info)) {
		GPUMOND_LOGGING_ERROR(self->logging, "read() returned %d (sizeof signalfd_siginfo is %d)\n", err, sizeof(info));
		return -1;
	}

	GPUMOND_LOGGING_DEBUG(self->logging, "Received signal %d", info.ssi_signo);

	if ((SIGINT  == info.ssi_signo) ||
	    (SIGQUIT == info.ssi_signo) ||
	    (SIGTERM == info.ssi_signo))
		return _Handle_Sigquit(self, info.ssi_signo);

	GPUMOND_LOGGING_WARN(self->logging, "Ignoring signal %d from pid %d (uid %d)", info.ssi_signo, info.ssi_pid, info.ssi_uid);

	return 0;
}

static SInt32 _Handle_Timer(struct Gpumond *self)
{
	SInt32 err;
	UInt64 exp;
	UInt64 duration;
	struct timespec tp, tq;

	GPUMOND_LOGGING_DEBUG(self->logging, "Timer expired");

	err = read(self->_timerfd, &exp, sizeof(UInt64));
	if (UNLIKELY(err < 0)) {
		GPUMOND_LOGGING_ERROR(self->logging, "read() failed with errno %d: %s", errno, strerror(errno));
		return -errno;
	}
	if (err != sizeof(UInt64)) {
		GPUMOND_LOGGING_ERROR(self->logging, "read() returned %d (sizeof UInt64 is %d)\n", err, sizeof(UInt64));
		return -1;
	}

	if (UNLIKELY(exp > 1)) {
		GPUMOND_LOGGING_WARN(self->logging, "Number of timer expirations since last read() = %d", (SInt32 )exp);
	}

	err = clock_gettime(CLOCK_MONOTONIC, &tp);
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(self->logging, "clock_gettime() failed with errno %d: %s", errno, strerror(errno));
		return -errno;
	}

	GPUMOND_LOGGING_DEBUG(self->logging, "current time = {.sec = %lld, .nsec = %lld}", tp.tv_sec, tp.tv_nsec);

	/* Try to align the data gathering by skipping samples if we are out of line.
	 */
	if (UNLIKELY(tp.tv_nsec > self->max_deviation_usec*1000LL)) {
		GPUMOND_LOGGING_WARN(self->logging, "Current time deviates by more than %d usecs: Skipping", self->max_deviation_usec);
		return 0;
	}

	err = Gpumond_Monitor_Collect(&self->data, self->logging);
	if (UNLIKELY(err)) {
		return err;
	}

	err = clock_gettime(CLOCK_MONOTONIC, &tq);
	if (UNLIKELY(err)) {
		GPUMOND_LOGGING_ERROR(self->logging, "clock_gettime() failed with errno %d: %s", errno, strerror(errno));
		return -errno;
	}

	duration = (tq.tv_nsec - tp.tv_nsec) + 1000*1000*1000L*(tq.tv_sec - tp.tv_sec);
	GPUMOND_LOGGING_DEBUG(self->logging, "Data collection took %lld nsec", duration);

	err = Gpumond_Monitor_Print(&self->data, self->output, self->logging);
	if (UNLIKELY(err)) {
		return err;
	}

	return 0;
}

SInt32 Gpumond_Init(struct Gpumond *self)
{
	SInt32 err;

	err = Gpumond_Monitor_Init(&self->data, self->logging);
	if (UNLIKELY(err)) {
		return err;
	}

	err = _Init_Signal_Handling(self);
	if (UNLIKELY(err)) {
		return err;
	}

	err = _Create_Timer(self);
	if (UNLIKELY(err)) {
		return err;
	}

	return 0;
}

SInt32 Gpumond_Fini(struct Gpumond *self)
{
	SInt32 err;
	SInt32 tmp;

	tmp = _Fini_Signal_Handling(self);
	if (UNLIKELY(tmp)) {
		err = tmp;
	}

	tmp = _Destroy_Timer(self);
	if (UNLIKELY(tmp)) {
		err = tmp;
	}

	err = Gpumond_Monitor_Fini(&self->data, self->logging);
	if (UNLIKELY(err)) {
		return err;
	}

	return err;
}

SInt32 Gpumond_Loop(struct Gpumond *self)
{
	SInt32 err;

	_Setup_Timer(self);

	self->_quit = 0;
	while (!self->_quit) {
		_Fill_Pollfds(self);

		err = poll(self->_pfds, 2, -1);
		if (UNLIKELY(err < 0)) {
			GPUMOND_LOGGING_ERROR(self->logging, "poll() failed with errno %d: %s", errno, strerror(errno));
			return -1;
		}

		if (self->_pfds[0].revents & POLLIN)
			_Handle_Signal(self);

		if (self->_pfds[1].revents & POLLIN)
			_Handle_Timer(self);
	}

	return 0;
}

