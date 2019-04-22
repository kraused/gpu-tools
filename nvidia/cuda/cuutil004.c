
/* cuutil002: Test peer-to-peer memory over InfiniBand.
 */

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <alloca.h>

#include <mpi.h>
#include <cuda_runtime.h>

#include "common.h"


void b64encode(const char *x, long n, long linelen)
{
	static const char CHARS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	long i, j, k;
	char b1, b2, b3;
	char e1, e2, e3, e4;
	char *p;

	linelen = 4*((long )((linelen + 3)/4));

	p = (char *)malloc(linelen);

	for(i = 0; i < n;) {
		for (j = 0; (j < linelen) && (i < n); j += 4, i += 3) {
			if ((i + 2) < n) {
				b1 = x[i];
				b2 = x[i + 1];
				b3 = x[i + 2];

				e1 = CHARS[((b1 & 0xFC) >> 2)];
				e2 = CHARS[((b1 & 0x03) << 4) | ((b2 & 0xF0) >> 4)];
				e3 = CHARS[((b2 & 0x0F) << 2) | ((b3 & 0xC0) >> 6)];
				e4 = CHARS[((b3 & 0x3F))];
			} else {
				b1 = x[i];
				b2 = ((i + 1) < n) ? x[i + 1] : 0;
				b3 = 0;

				e1 = CHARS[((b1 & 0xFC) >> 2)];
				e2 = '=';
				e3 = '=';
				e4 = '=';

				if ((i + 1) < n) {
					e2 = CHARS[((b1 & 0x03) << 4) | ((b2 & 0xF0) >> 4)];
					e3 = CHARS[((b2 & 0x0F) << 2)];
				}
			}

			p[j    ] = e1;
			p[j + 1] = e2;
			p[j + 2] = e3;
			p[j + 3] = e4;
		}

		for (k = 0; k < j; ++k) {
			fputc(p[k], stdout);
		}
		fputc('\n', stdout);
	}
	
	free(p);
}

/* TODO Improve the error handling
 */
#define error(FMT, ...)	do { fprintf(stderr, FMT, ## __VA_ARGS__ "\n"); abort(); } while(0)

enum {
	BUF_NUM_PAGES	= 8
};

struct Context
{
	SInt64			pgsize;

	int			rank;
	int			size;

	void			*hostBuf;
	void			*gpuBuf;

	MPI_Comm		comm;

} Ctx;



void alloc()
{
	int i;
	void *p;

	Ctx.hostBuf = memalign(Ctx.pgsize, BUF_NUM_PAGES*Ctx.pgsize);
	if (UNLIKELY(!Ctx.hostBuf)) {
		error("memalign() failed");
	}

	for (i = 0; i < (BUF_NUM_PAGES*Ctx.pgsize/sizeof(SInt32)); ++i) {
		((SInt32 *)Ctx.hostBuf)[i] = -1;
	}

	cudaMalloc(&p, BUF_NUM_PAGES*Ctx.pgsize);
#if 0
	cudaMallocManaged(&p, BUF_NUM_PAGES*Ctx.pgsize, cudaMemAttachGlobal);
#endif
	Ctx.gpuBuf = (void *)p;
}

void fill()
{
	int i;

	for (i = 0; i < (BUF_NUM_PAGES*Ctx.pgsize/sizeof(SInt32)); ++i) {
		((SInt32 *)Ctx.hostBuf)[i] = rand();
	}

	cudaMemcpy(Ctx.gpuBuf, Ctx.hostBuf, BUF_NUM_PAGES*Ctx.pgsize, cudaMemcpyHostToDevice);
}

void sync()
{
	cudaMemcpy(Ctx.hostBuf, Ctx.gpuBuf, BUF_NUM_PAGES*Ctx.pgsize, cudaMemcpyDeviceToHost);
}

void recv()
{
	MPI_Recv(Ctx.gpuBuf, BUF_NUM_PAGES*Ctx.pgsize, MPI_BYTE, 0, 0, Ctx.comm, MPI_STATUS_IGNORE);
}

void send()
{
	MPI_Send(Ctx.gpuBuf, BUF_NUM_PAGES*Ctx.pgsize, MPI_BYTE, 1, 0, Ctx.comm);
}

void wait()
{
	sync();
}

int main(int argc, char **argv)
{
	int ret;
	MPI_Comm tmp;

	Ctx.pgsize = sysconf(_SC_PAGESIZE);

	cudaSetDevice(0);

	MPI_Init(&argc, &argv);

	Ctx.comm = MPI_COMM_WORLD;
	MPI_Comm_dup(MPI_COMM_WORLD, &tmp);

	MPI_Comm_size(MPI_COMM_WORLD, &Ctx.size);
	MPI_Comm_rank(MPI_COMM_WORLD, &Ctx.rank);

	alloc();

	MPI_Barrier(MPI_COMM_WORLD);

	if (1 == Ctx.rank) {
		recv();
	}
	if (0 == Ctx.rank) {
		fill();
		send();
	}
	wait();

	{
		struct timespec ts;
		ts.tv_sec  = 10;
		ts.tv_nsec = 0;	

		nanosleep(&ts, NULL);
	}

	b64encode((const char*)Ctx.hostBuf, BUF_NUM_PAGES*Ctx.pgsize, 64);

	return 0;
}

