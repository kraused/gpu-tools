
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "watchman/plugin.hxx"
#include "watchman/alloc.hxx"
#include "watchman/program.hxx"
#include "watchman/buffer.hxx"
#include "watchman/file.hxx"
#include "watchman/named_clingy_file.hxx"
#include "watchman/watchman.hxx"
#include "watchman/compiler.hxx"
#include "watchman/error.hxx"

static char _gpumond[1][WATCHMAN_PROGRAM_MAX_ARGV_STRLEN + 1];
static char *_argv[2];

static char **_fill_argv()
{
	strcpy(_gpumond[0], GPUMOND_BIN_PREFIX "/gpumond.exe");

	_argv[0] = _gpumond[0];
	_argv[1] = NULL;

	return _argv;
}

class Gpumond_Program : public Program
{

public:
				Gpumond_Program();

};

class Gpumond_Watchman_Plugin : public Watchman_Plugin
{

public:
				explicit Gpumond_Watchman_Plugin(void *handle);

public:
	int			init(Watchman *w, int argc, char **argv);
	int			fini();

private:
	Allocator		*_alloc;

private:
	Gpumond_Program		*_proc;

private:
	Buffer			_buf;

private:
				/* Mountpoint of the filesystem on which the
				 * the output file resides. */
	const char		*_fo_mountpoint;
	const char		*_fo_path;

private:
	Named_Clingy_File	*_fo;
	File			*_fe;
};

Gpumond_Program::Gpumond_Program()
: Program(_fill_argv())
{
}

Gpumond_Watchman_Plugin::Gpumond_Watchman_Plugin(void *handle)
: Watchman_Plugin(handle, 1), _fo(NULL), _fe(NULL)
{
}

int Gpumond_Watchman_Plugin::init(Watchman *w, int argc, char **argv)
{
	int   err;
	off_t offset;

	_alloc = w->alloc();

	_fo_mountpoint = argv[0];
	_fo_path       = argv[1];

	_proc = _alloc->create<Gpumond_Program>();

	_fo = _alloc->create<Named_Clingy_File>();
	_fe = _alloc->create<File>(STDERR_FILENO);

	err = _fo->attach(_fo_mountpoint);
	if (unlikely(err)) {
		return err;
	}

	err = _fo->open(_fo_path, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	if (unlikely(err)) {
		return err;
	}

	offset = lseek(_fo->fileno(), 0, SEEK_END);
	if (unlikely(-1 == offset)) {
		WATCHMAN_ERROR("lseek() failed with error %d (%s)", errno, strerror(errno));
	}

        err = w->add_child(_proc, &_buf, _fo, _fe);
        if (unlikely(err)) {
                WATCHMAN_ERROR("Failed to add children to list: %d", err);
                return err;
        }

	return 0;
}

int Gpumond_Watchman_Plugin::fini()
{
	_fo = _alloc->destroy<Named_Clingy_File>(_fo);
	_fe = _alloc->destroy<File>(_fe);

	_proc = _alloc->destroy<Gpumond_Program>(_proc);

	return 0;
}

extern "C" Watchman_Plugin *entry(void *handle, Watchman *w)
{
	Allocator *alloc = w->alloc();

	return alloc->create<Gpumond_Watchman_Plugin>(handle);
}

