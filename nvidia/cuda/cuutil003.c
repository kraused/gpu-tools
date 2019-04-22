
/* cuutil002: Test peer-to-peer memory over InfiniBand.
 */

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <alloca.h>

#include <infiniband/verbs.h>
#include <cuda_runtime.h>

#include "common.h"
#include "minipmi.h"


void b64encode(const char *x, long n, long linelen)
{
	static const char CHARS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	long i, j, k;
	char b1, b2, b3;
	char e1, e2, e3, e4;
	char *p;

	linelen = 4*((long )((linelen + 3)/4));

	p = alloca(linelen);

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
}

/* TODO Improve the error handling
 */
#define error(FMT, ...)	do { fprintf(stderr, FMT, ## __VA_ARGS__ "\n"); abort(); } while(0)

enum {
	SERVICE_LEVEL	= 0,

	CQ_SIZE		= 65536,

	MAX_INLINE_DATA	= 64,
	MAX_SEND_WR     = 16,
	MAX_RECV_WR     = 16,
	MAX_SEND_SGE    = 1,
	MAX_RECV_SGE    = 1,

	GPU_DEVICE	= 0,

	BUF_NUM_PAGES	= 1
};

struct Context
{
	SInt64			pgsize;

	struct minipmi_context	pmiCtx;
	int			rank;
	int			size;

	struct ibv_device	**ibDevList;
	struct ibv_device	*ibDev;
	struct ibv_context	*ibCtx;
	int			ibPortnum;

	struct ibv_pd		*ibPd;	/* Protection domain */
	struct ibv_cq		*ibCq;	/* Completion queue */

	struct ibv_qp		*ibQp;	/* Queue pair */

	void			*hostBuf;
	struct ibv_mr		*ibHostMr;

	void			*gpuBuf;
	struct ibv_mr		*ibGpuMr;

	struct {
		SInt64		lid;
		SInt64		qpn;
		SInt64		psn;
	}			here, other;

} Ctx;



void setup_gpu_context()
{
	cudaSetDevice(0);
}

void select_channel_adapter()
{
	struct ibv_context	*ctx;
	struct ibv_device_attr	dattr;
	struct ibv_port_attr 	pattr;
	int i, p, ret, port;

	Ctx.ibDevList = ibv_get_device_list(NULL);
	if (UNLIKELY(!Ctx.ibDevList)) {
		error("ibv_get_device_list returned NULL");
	}

	port = -1;

	for (i = 0; Ctx.ibDevList[i]; ++i) {
		ctx = ibv_open_device(Ctx.ibDevList[i]);
		if (UNLIKELY(!ctx))
			continue;

		ret = ibv_query_device(ctx, &dattr);
		if (UNLIKELY(ret))
			continue;

		for (p = 0; p < dattr.phys_port_cnt; ++p) {
			ret = ibv_query_port(ctx, (p + 1), &pattr);
			if (UNLIKELY(ret))
				continue;

			if (IBV_PORT_ACTIVE == pattr.state) {
				port = (p + 1);
				break;
			}
		}

		if (-1 == port) {
			ibv_close_device(ctx);
		} else {
			Ctx.ibDev     = Ctx.ibDevList[i];
			Ctx.ibCtx     = ctx;
			Ctx.ibPortnum =	port;
			break;
		}
	}

	if (UNLIKELY(-1 == port)) {
		error("Could not get hold of a working HCA");
	}
}

void create_qp()
{
	struct ibv_qp_init_attr iattr = {
		.send_cq = Ctx.ibCq,
		.recv_cq = Ctx.ibCq,
		.cap = {
			/* We will not have more than one WR posted at a time. */
			.max_send_wr     = MAX_SEND_WR,
			.max_recv_wr     = MAX_RECV_WR,
			.max_send_sge    = MAX_SEND_SGE,
			.max_recv_sge    = MAX_RECV_SGE,
			.max_inline_data = MAX_INLINE_DATA
		},
		.qp_type = IBV_QPT_RC,
		.sq_sig_all = 0	 /* Each send WR will specify whether or not
					 * to create a CQE. */
	};

	Ctx.ibQp = ibv_create_qp(Ctx.ibPd, &iattr);
	if (UNLIKELY(!Ctx.ibQp)) {
		error("ibv_create_qp() failed");
	}
}

/* Move the queue pair from RESET to INIT state.
 */
void move_qp_to_init()
{
	struct ibv_qp_attr attr = {
		.qp_state	= IBV_QPS_INIT,
		.pkey_index      = 0,
		.port_num	= Ctx.ibPortnum,
		.qp_access_flags = IBV_ACCESS_REMOTE_WRITE
	};
	int ret;

	ret = ibv_modify_qp(Ctx.ibQp, &attr,
			    IBV_QP_STATE |
			    IBV_QP_PKEY_INDEX |
			    IBV_QP_PORT |
			    IBV_QP_ACCESS_FLAGS);
	if (UNLIKELY(ret)) {
		error("Moving queue pair to init state failed");
	}
}

/* Move the queue pair from INIT to RTR (ready to receive) state.
 */
void move_qp_to_rtr()
{
	struct ibv_qp_attr attr = {
		.qp_state       = IBV_QPS_RTR,
		.path_mtu       = IBV_MTU_512,  /* recommended value */
		.dest_qp_num    = Ctx.other.qpn,
		.rq_psn	 = Ctx.other.psn,
		.max_dest_rd_atomic     = 1,
		.min_rnr_timer	  = 12,   /* recommended value */
		/* AH (address handle) attributes */
		.ah_attr	= {
			.is_global      = 0,    /* GRH attributes are not valid (since they are not set).
						 * We stay within one subnet. */
			.dlid	   = Ctx.other.lid,
			.sl	     = SERVICE_LEVEL,
			.src_path_bits  = 0,    /* Use base LID (0 == LMC) */
			.port_num       = Ctx.ibPortnum
		}
	};
	int ret;

	ret = ibv_modify_qp(Ctx.ibQp, &attr,
			    IBV_QP_STATE |
			    IBV_QP_PATH_MTU |
			    IBV_QP_DEST_QPN |
			    IBV_QP_RQ_PSN |
			    IBV_QP_MAX_DEST_RD_ATOMIC |
			    IBV_QP_MIN_RNR_TIMER |
			    IBV_QP_AV);
	if (UNLIKELY(ret)) {
		error("Moving queue pair to ready-to-receive state failed");
	}
}

/* Move the QP to the RTS state. This should be done after
 * the QP has been moved into the RTR state.
 */
void move_qp_to_rts()
{
	struct ibv_qp_attr attr = {
		.qp_state       = IBV_QPS_RTS,
		.timeout	= 14,   /* Local ack timeout for primary path */
		.retry_cnt      = 7,    /* Retry count */
		.rnr_retry      = 7,    /* RNR (receiver not ready) retry */
		.sq_psn	 = 0,
		.max_rd_atomic  = 1     /* Number of outstanding RDMA reads & atomic
					 * operations on the destination QP */
	};
	int ret;

	ret = ibv_modify_qp(Ctx.ibQp, &attr,
			    IBV_QP_STATE |
			    IBV_QP_TIMEOUT |
			    IBV_QP_RETRY_CNT |
			    IBV_QP_RNR_RETRY |
			    IBV_QP_SQ_PSN |
			    IBV_QP_MAX_QP_RD_ATOMIC);
	if (UNLIKELY(ret)) {
		error("Moving queue pair to ready-to-send state failed");
	}
}

void setup_ib_context()
{
	select_channel_adapter();

	Ctx.ibPd = ibv_alloc_pd(Ctx.ibCtx);
	if (UNLIKELY(!Ctx.ibPd)) {
		error("ibv_alloc_pd() failed");
	}

	Ctx.ibCq = ibv_create_cq(Ctx.ibCtx, CQ_SIZE, NULL, NULL, 0);
	if (UNLIKELY(!Ctx.ibCq)) {
		error("ibv_create_cq() failed");
	}

	create_qp();
	move_qp_to_init();
}

void kvs_put_SInt64(const char *key, SInt64 value)
{
	char k[64];
	char v[64];
	int ret;

	snprintf(k, sizeof(k), "%s-%d", key, Ctx.rank);
	snprintf(v, sizeof(v), "%ld", value);

	ret = minipmi_kvs_put(&Ctx.pmiCtx, k, v);
	if (UNLIKELY(ret)) {
		error("minipmi_kvs_put() failed");
	}
}

void kvs_get_SInt64(const char *key, SInt64 *value)
{
	char k[64];
	char v[64];
	int len;
	int ret;

	snprintf(k, sizeof(k), "%s-%d", key, (1 - Ctx.rank));

	ret = minipmi_kvs_get(&Ctx.pmiCtx, k, v, 64, &len);
	if (UNLIKELY(ret)) {
		error("minipmi_kvs_get() failed");
	}

	*value = strtol(v, NULL, 0);
}

void connect1()
{
	int ret;
	struct ibv_port_attr attr;

	ret = ibv_query_port(Ctx.ibCtx, Ctx.ibPortnum, &attr);
	if (UNLIKELY(ret)) {
		error("ibv_query_port() failed");
	}

	Ctx.here.lid = attr.lid;
	Ctx.here.qpn = Ctx.ibQp->qp_num;
	Ctx.here.psn = 0;	/* Packet sequence number */

	kvs_put_SInt64("LID", Ctx.here.lid);
	kvs_put_SInt64("QPN", Ctx.here.qpn);
	kvs_put_SInt64("PSN", Ctx.here.psn);

	ret = minipmi_kvs_sync(&Ctx.pmiCtx);
	if (UNLIKELY(ret)) {
		error("minipmi_kvs_sync() failed");
	}

	kvs_get_SInt64("LID", &Ctx.other.lid);
	kvs_get_SInt64("QPN", &Ctx.other.qpn);
	kvs_get_SInt64("PSN", &Ctx.other.psn);

	move_qp_to_rtr();
}

void connect2()
{
	move_qp_to_rts();
}

void disconnect()
{
	int ret;

	ret = ibv_destroy_qp(Ctx.ibQp);
	if (UNLIKELY(ret)) {
		error("ibv_destroy_qp() failed");
	}
}

void alloc()
{
	int i;
	int flag;
	void *p;

	Ctx.hostBuf = memalign(Ctx.pgsize, BUF_NUM_PAGES*Ctx.pgsize);
	if (UNLIKELY(!Ctx.hostBuf)) {
		error("memalign() failed");
	}

	for (i = 0; i < (BUF_NUM_PAGES*Ctx.pgsize/sizeof(SInt32)); ++i) {
		((SInt32 *)Ctx.hostBuf)[i] = -1;
	}

	Ctx.ibHostMr = ibv_reg_mr(Ctx.ibPd, Ctx.hostBuf, BUF_NUM_PAGES*Ctx.pgsize,
				  IBV_ACCESS_LOCAL_WRITE |
				  IBV_ACCESS_REMOTE_WRITE);
	if (UNLIKELY(!Ctx.ibHostMr)) {
		error("ibv_reg_mr() failed");
	}

	cudaMalloc(&p, BUF_NUM_PAGES*Ctx.pgsize);
	Ctx.gpuBuf = (void *)p;

#if 0
	flag = 1;
	Nvcu_PointerSetAttribute(&flag, CU_POINTER_ATTRIBUTE_SYNC_MEMOPS, (CUdeviceptr )Ctx.gpuBuf);
#endif

	cudaMemcpy(Ctx.gpuBuf, Ctx.hostBuf, BUF_NUM_PAGES*Ctx.pgsize, cudaMemcpyHostToDevice);

	Ctx.ibGpuMr = ibv_reg_mr(Ctx.ibPd, Ctx.gpuBuf, BUF_NUM_PAGES*Ctx.pgsize,
				 IBV_ACCESS_LOCAL_WRITE |
				 IBV_ACCESS_REMOTE_WRITE);
	if (UNLIKELY(!Ctx.ibGpuMr)) {
		error("ibv_reg_mr() failed");
	}
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
	struct ibv_sge sge = {
		.addr   = (UInt64 )Ctx.gpuBuf,
		.length = BUF_NUM_PAGES*Ctx.pgsize,
		.lkey   = Ctx.ibGpuMr->lkey
	};
	struct ibv_recv_wr wr = {
		.next	   = NULL, /* linked list: Only one entry */
		.wr_id	  = 0,
		.sg_list	= &sge,
		.num_sge	= 1,
	};
	struct ibv_recv_wr *badWr;
	int ret;

	ret = ibv_post_recv(Ctx.ibQp, &wr, &badWr);
	if (UNLIKELY(ret)) {
		error("ibv_post_recv() failed");
	}
}

void send()
{
	struct ibv_sge sge = {
		.addr   = (UInt64 )Ctx.gpuBuf,
		.length = BUF_NUM_PAGES*Ctx.pgsize,
		.lkey   = Ctx.ibGpuMr->lkey
	};
	const _Bool maybe_send_inline = (sge.length <= MAX_INLINE_DATA) ? IBV_SEND_INLINE : 0;
	struct ibv_send_wr wr = {
		.next	   = NULL, /* linked list: Only one entry */
		.wr_id	  = 0,
		.sg_list	= &sge,
		.num_sge	= 1,
		.opcode	 = IBV_WR_SEND,
		/* Since we set qp_sig_all = 0 we have to specify IBV_SEND_SIGNALED here */
		.send_flags     = IBV_SEND_SIGNALED | maybe_send_inline,
		.imm_data       = 0,
	};
	struct ibv_send_wr *badWr;
	int ret;

	ret = ibv_post_send(Ctx.ibQp, &wr, &badWr);
	if (UNLIKELY(ret)) {
		error("ibv_post_send() failed");
	}
}

void wait()
{
	int ret;
	struct ibv_wc wc;

	while (1) {
		ret = ibv_poll_cq(Ctx.ibCq, 1, &wc);
		if (UNLIKELY(ret < 0)) {
			error("ibv_poll_cq() failed");
		}

		if (ret)
			break;
	}
	
	sync();
}

int main(int argc, char **argv)
{
	int ret;

	Ctx.pgsize = sysconf(_SC_PAGESIZE);

	/* FIXME Check ret.
 	 */
	ret = minipmi_initialize(&Ctx.pmiCtx);
	ret = minipmi_get_rank(&Ctx.pmiCtx, &Ctx.rank);
	ret = minipmi_get_size(&Ctx.pmiCtx, &Ctx.size);

	if (UNLIKELY(2 != Ctx.size)) {
		error("2 != Ctx.size");
	}

	setup_gpu_context();

	setup_ib_context();

	alloc();

	connect1();
	/* Post a receive before moving the QP to RTS state.
	 */
	if (1 == Ctx.rank) {
		recv();
	}
	connect2();
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

	b64encode(Ctx.hostBuf, BUF_NUM_PAGES*Ctx.pgsize, 64);

	disconnect();

	return 0;
}

