// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Its .data (two words) is defined at D_0046BE88 below.
#include "common.h"

struct ThreadParam {
    int status;
    void (*entry)(void *);
    void *stack;
    int stackSize;
    void *gpReg;
    int initPriority;
    int currentPriority;
    unsigned int attr;
    unsigned int option;
    int waitType;
    int waitId;
    int wakeupCount;
};

struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};

int WaitSema(int s);
int iSignalSema(int s);
int CreateSema(struct SemaParam *p);
int DeleteSema(int s);
int CreateThread(struct ThreadParam *p);
int StartThread(int t, void *arg);
int GetThreadId(void);
int ChangeThreadPriority(int t, int p);
int WakeupThread(int t);
int RotateThreadReadyQueue(int p);
int SuspendThread(int t);
int _iWakeupThread(void);
int _iSuspendThread(void);
void kprintf(char *fmt, ...);
extern char D_00492388[];

/* An EE syscall leaf (`addiu $3,$zero,NUM; syscall 0`) issued inline, for
   the calls that act on its result.  The syscall returns in $2. */
#define SYSCALL_INLINE(num, dst)                                                                   \
    {                                                                                              \
        register int __sc_ret __asm__("$2");                                                       \
        __asm__ __volatile__("addiu $3, $0, " #num "\n\tsyscall 0"                                 \
                             : "=r"(__sc_ret)                                                      \
                             :                                                                     \
                             : "$3", "memory");                                                    \
        (dst) = __sc_ret;                                                                          \
    }

typedef struct { /* field names derived */
    unsigned char code;
    unsigned char id;
} KernEvent; /* derived name */

typedef struct { /* field names derived */
    int ridx;
    int widx;
    KernEvent ent[512];
} KernEventRing; /* derived name */

/* the kernel event thread's stack (16-byte aligned, as CreateThread
   requires), the semaphore that wakes it and the ring of events the
   interrupt-side calls post to it */
extern char D_0066DDB0[0x400]; /* kernEventStack */

extern int D_0066E1B0; /* kernEventSema */

extern KernEventRing D_0066E1B8; /* kernEventRing */

void topThread(void *arg)
{
    KernEventRing *ring = (KernEventRing *)arg;
    int i;

    while (1) {
        WaitSema(D_0066E1B0);
        i = ring->ridx & 0x1FF;
        ring->ridx = i + 1;
        switch (ring->ent[i].code) {
        case 0:
            WakeupThread(ring->ent[i].id);
            break;
        case 1:
            RotateThreadReadyQueue(ring->ent[i].id);
            break;
        case 2:
            SuspendThread(ring->ent[i].id);
            break;
        default:
            kprintf(D_00492388); /* the message "## internel error in libkernl.a!" in .rodata */
            break;
        }
    }
}

/* the kernel event thread's id, zero until InitKernEvent creates it */
#ifdef VERSION_FM
// .data (0x0046BE88-0x0046BE90)
int D_0046BE88 = 0; /* kernEventThreadId */
int D_0046BE8C = 0;
#else
extern int D_0046BE88; /* kernEventThreadId */
#endif

/* The link's small-data base, which no header declares */
extern char D_00494050[]; /* _gp */

int InitThread(void)
{
    struct ThreadParam th;
    struct SemaParam sm;
    int tid;

    if (D_0046BE88 > 0) {
        return -1;
    }

    sm.maxCount = 0xFF;
    sm.initCount = 0;
    D_0066E1B0 = CreateSema(&sm);
    if (D_0066E1B0 < 0) {
        return -1;
    }

    th.entry = topThread;
    th.stack = D_0066DDB0;
    th.stackSize = 0x400;
    th.gpReg = D_00494050;
    th.initPriority = 0;
    tid = CreateThread(&th);
    D_0046BE88 = tid;
    if (tid < 0) {
        DeleteSema(D_0066E1B0);
        return -1;
    }

    D_0066E1B8.ridx = 0;
    D_0066E1B8.widx = 0;
    StartThread(tid, &D_0066E1B8);
    ChangeThreadPriority(GetThreadId(), 1);
    return D_0046BE88;
}

int iWakeupThread(int id)
{
    int r;
    int i;
    SYSCALL_INLINE(-0x2F, r);
    if (r != id) {
        return _iWakeupThread();
    }
    if ((unsigned int)r >= 0x100) {
        goto fail;
    }
    if (D_0046BE88 != 0) {
        goto post;
    }
fail:
    return -1;
post:
    i = D_0066E1B8.widx & 0x1FF;
    D_0066E1B8.widx = i + 1;
    D_0066E1B8.ent[i].code = 0;
    D_0066E1B8.ent[i].id = r;
    iSignalSema(D_0066E1B0);
    return r;
}

int iRotateThreadReadyQueue(int id)
{
    int i;
    if ((unsigned int)id >= 0x80) {
        goto fail;
    }
    if (D_0046BE88 != 0) {
        goto post;
    }
fail:
    return -1;
post:
    i = D_0066E1B8.widx & 0x1FF;
    D_0066E1B8.widx = i + 1;
    D_0066E1B8.ent[i].code = 1;
    D_0066E1B8.ent[i].id = id;
    iSignalSema(D_0066E1B0);
    return id;
}

int iSuspendThread(int id)
{
    int r;
    int i;
    SYSCALL_INLINE(-0x2F, r);
    if (r != id) {
        return _iSuspendThread();
    }
    if ((unsigned int)r >= 0x100) {
        goto fail;
    }
    if (D_0046BE88 != 0) {
        goto post;
    }
fail:
    return -1;
post:
    i = D_0066E1B8.widx & 0x1FF;
    D_0066E1B8.widx = i + 1;
    D_0066E1B8.ent[i].code = 2;
    D_0066E1B8.ent[i].id = r;
    iSignalSema(D_0066E1B0);
    return r;
}
