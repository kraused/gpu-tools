
#include <string.h>
#include <unistd.h>

#include "config.h"
#include "platform.h"
#include "alloc.h"
#include "logging.h"
#include "output.h"
#include "gpumond.h"
#include "helper.h"

int main(int argc, char **argv)
{
	SInt32 err;
	struct Gpumond app;

	/* May not be actually needed but should not hurt either.
	 * Note that the logging and output mechanisms may share
	 * the syslog connection (same identifier).
	 */
	Gpumond_Syslog_Open();

	memset(&app, 0, sizeof(app));

	app.alloc   = Libc_Allocator();
	app.logging = File_Logging(app.alloc, STDERR_FILENO);
	app.output  = File_Output(app.alloc, app.logging, "-");

	app.period  = GPUMOND_TIMER_DEFAULT_PERIOD_SEC;
	app.max_deviation_usec = GPUMOND_DEFAULT_MAX_DEVIATION_USEC;

	err = Gpumond_Init(&app);
	if (UNLIKELY(err))
		return err;

	err = Gpumond_Loop(&app);
	if (UNLIKELY(err))
		return err;

	err = Gpumond_Fini(&app);
	if (UNLIKELY(err))
		return err;


	Gpumond_Syslog_Close();

	return 0;
}

