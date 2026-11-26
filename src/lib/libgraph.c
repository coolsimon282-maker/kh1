// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Its .data is defined after the declarations below.
#include "common.h"

/* GS privileged registers */
#define GS_PMODE ((volatile u_long*)0x12000000)
#define GS_SMODE2 ((volatile u_long*)0x12000020)
#define GS_DISPFB1 ((volatile u_long*)0x12000070)
#define GS_DISPLAY1 ((volatile u_long*)0x12000080)
#define GS_DISPFB2 ((volatile u_long*)0x12000090)
#define GS_DISPLAY2 ((volatile u_long*)0x120000A0)
#define GS_EXTDATA ((volatile u_long*)0x120000C0)
#define GS_BGCOLOR ((volatile u_long*)0x120000E0)
#define GS_CSR ((volatile u_long*)0x12001000)

/* The record sceGsGetGParam hands back. */
typedef struct {
    short inter;   /* 0x0 */
    short omode;   /* 0x2 */
    short ffmd;    /* 0x4 */
    short version; /* 0x6, the GS revision out of CSR bits 16..23 */
    int intcUsed;  /* 0x8, set while the INTC 2 handler is installed */
    int handler;   /* 0xC, the handler id RemoveIntcHandler takes */
} sceGsGParam;

sceGsGParam* sceGsGetGParam(void);
int GsPutIMR(u_long imr);
int DisableIntc(int);
int RemoveIntcHandler(int, int);
void SetGsCrt(short inter, short omode, short ffmd);
int sceOpen(const char* filename, int flag, ...);
int sceRead(int fd, void* addr, int size);
int sceClose(int fd);
int func_002729D8(const char*);

#ifdef VERSION_FM
// .data (0x0046C4F0-0x0046C540)
char D_0046C4F0[16] = "PsIIlibgraph2500"; // library version (no NUL)
sceGsGParam D_004661C0 = {1, 2, 1, 3, NULL, 0}; /* gsGParam */
unsigned int D_0046C510[8] __attribute__((aligned(16))) = { /* sceGsResetPath's VIF1 packet */
    0x01000404, 0x20000000, 0x00000000, 0x05000000, 0x06000000, 0x03000000, 0x02000000, 0x04000000,
};
unsigned int D_0046C530[4] = {0x06000000, 0, 0, 0}; // read by sceGsExecStoreImage
#else
extern sceGsGParam D_004661C0;           /* gsGParam */
extern unsigned int D_0046C510[8];       /* sceGsResetPath's VIF1 packet (16-aligned) */
#endif
extern char D_00492920[];                /* the file func_00265558 reads */

void sceGsResetGraph(short mode, short inter, short omode, short ffmd) {
    sceGsGParam* g;

    switch (mode) {
        case 0:
            g = sceGsGetGParam();
            *GS_CSR = 0x200;
            g->inter = inter;
            g->omode = omode;
            g->version = (*GS_CSR >> 16) & 0xFF;
            GsPutIMR(0xFF00);
            g->ffmd = ffmd != 0;
            if (g->intcUsed != 0) {
                DisableIntc(2);
                RemoveIntcHandler(2, g->handler);
                g->intcUsed = 0;
                g->handler = 0;
            }
            SetGsCrt(inter & 1, omode & 0xFF, ffmd & 1);
            break;
        case 1:
            *GS_CSR = 0x100;
            break;
        case 5:
            g = sceGsGetGParam();
            g->inter = inter;
            g->omode = omode;
            g->version = (*GS_CSR >> 16) & 0xFF;
            g->ffmd = ffmd != 0;
            SetGsCrt(inter & 1, omode & 0xFF, ffmd & 1);
            break;
    }
}

sceGsGParam* sceGsGetGParam(void) {
    return &D_004661C0;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsResetPath);

int func_00265558(void) {
    char buf[256];
    char* p;
    int fd;
    unsigned int i;

    fd = sceOpen(D_00492920, 1);
    if (fd < 0) {
        return -1;
    }
    i = 0;
    p = buf;
    for (; i < 256; i++) {
        sceRead(fd, p, 1);
        if (*p++ == 0) {
            break;
        }
    }
    sceClose(fd);
    return func_002729D8(&buf[i - 9]) > 20010608;
}

void GetGsDxDyOffset(int mode, int* dx, int* dy, int* dw, int* dh) {
    __asm__ __volatile__("addiu $3, $0, 128\n\tsyscall 0" : : : "$3", "memory");
}

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsSetDefDispEnv);

void sceGsPutDispEnv(void* disp) {
    long* s = (long*)disp;
    if (sceGsGetGParam()->version == 1) {
        *GS_PMODE = s[0];
        *GS_DISPFB1 = s[2];
        *GS_DISPLAY1 = s[3];
        *GS_EXTDATA = s[4];
    } else {
        *GS_PMODE = s[0];
        *GS_SMODE2 = s[1];
        *GS_DISPFB2 = s[2];
        *GS_DISPLAY2 = s[3];
        *GS_BGCOLOR = s[4];
    }
}

#define D2_CHCR ((volatile u_int*)0x1000A000)
#define D2_MADR ((volatile u_int*)0x1000A010)
#define D2_QWC ((volatile u_int*)0x1000A020)

int scePrintf(const char* fmt, ...);
extern char D_00492968[]; /* "sceGsPutDrawEnv: DMA Ch.2 does not terminate\r\n" */

int sceGsPutDrawEnv(void* pkt) {
    unsigned int count;
    int qwc;

    count = 0;
    while (*D2_CHCR & 0x100) {
        if (count++ > 0x1000000) {
            scePrintf(D_00492968);
            return -1;
        }
    }
    qwc = *(long long*)pkt & 0x7FFF;
    *D2_QWC = qwc + 1;
    if (((unsigned int)pkt & 0x70000000) == 0x70000000)
        *D2_MADR = ((unsigned int)pkt & 0xFFFFFFF) | 0x80000000;
    else
        *D2_MADR = (unsigned int)pkt & 0xFFFFFFF;
    *D2_CHCR = 0x101;
    return 0;
}

int VSync(void);
long VSync2(void);

int sceGsSyncV(int mode) {
    sceGsGParam* gp = sceGsGetGParam();
    long c;

    if (gp->intcUsed == 0) {
        VSync();
        if (gp->inter != 1) {
            return 1;
        }
        return (int)((*GS_CSR >> 13) & 1);
    }
    c = VSync2();
    c = (c >> 13) & 1;
    if (gp->inter != 1) {
        return 1;
    }
    return (int)c;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsSyncPath);

extern char D_00492B30[];
extern char D_00492C50[];

/* R5900 opcodes with no C spelling.  Defined in this member. */
#define SYNC() __asm__ __volatile__("sync" : : : "memory")

typedef unsigned int u128_t __attribute__((mode(TI)));

typedef struct { /* field names derived */
    unsigned long long nloop : 15;
    unsigned long long eop : 1;
    unsigned long long pad1 : 30;
    unsigned long long pre : 1;
    unsigned long long prim : 11;
    unsigned long long flg : 2;
    unsigned long long nreg : 4;
    unsigned long long regs0 : 4;
    unsigned long long regs1 : 60;
} GifTag; /* derived name */

/* sceGsSetDefLoadImage: its switch jump table is in the data segment (blocked until that rodata is C). */
INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsSetDefLoadImage);





typedef struct {          /* field names derived */
    unsigned int h0;      /* 0x0 */
    unsigned int h1;      /* 0x4 */
    unsigned int h2;      /* 0x8 */
    unsigned int h3;      /* 0xC */
    GifTag gif;           /* 0x10 */
    long long bitbltbuf;  /* 0x20 */
    long long abitbltbuf; /* 0x28 */
    long long trxpos;     /* 0x30 */
    long long atrxpos;    /* 0x38 */
    long long trxreg;     /* 0x40 */
    long long atrxreg;    /* 0x48 */
    long long finish;     /* 0x50 */
    long long afinish;    /* 0x58 */
    long long trxdir;     /* 0x60 */
    long long atrxdir;    /* 0x68 */
} StoreImage;             /* derived name */

int sceGsSetDefStoreImage(StoreImage *di, short sbp, short sbw, short spsm, short ssax, short ssay,
                          short rrw, short rrh)
{
    di->h0 = 0;
    di->h1 = 0x06008000;
    di->h2 = 0x13000000;
    di->h3 = 0x50000006;
    *(u128_t *)&di->gif = 0;
    di->gif.nloop = 5;
    di->gif.eop = 1;
    di->gif.nreg = 1;
    di->gif.regs0 = 0xE;
    di->bitbltbuf = (long long)sbp | ((long long)sbw << 16) | ((long long)spsm << 24);
    di->abitbltbuf = 0x50;
    di->trxpos = (long long)ssax | ((long long)ssay << 16);
    di->atrxpos = 0x51;
    di->trxreg = (long long)rrw | ((long long)rrh << 32);
    di->atrxreg = 0x52;
    di->finish = 0;
    di->afinish = 0x61;
    di->trxdir = 1;
    di->atrxdir = 0x53;
    SYNC();
    return 7;
}


int sceGsExecLoadImage(void *pkt, void *img)
{
    unsigned int i = 0;

    while (*D2_CHCR & 0x100) {
        if (i++ > 0x1000000) {
            scePrintf(D_00492C50);
            return -1;
        }
    }
    *D2_QWC = 6;
    if (((unsigned int)pkt & 0x70000000) == 0x70000000) {
        *D2_MADR = ((unsigned int)pkt & 0x0FFFFFFF) | 0x80000000;
    } else {
        *D2_MADR = (unsigned int)pkt & 0x0FFFFFFF;
    }
    *D2_CHCR = 0x101;
    while (*D2_CHCR & 0x100) {
        if (i++ > 0x1000000) {
            scePrintf(D_00492C50);
            return -1;
        }
    }
    *D2_QWC = (int)(*(long *)((char *)pkt + 0x50) & 0x7FFF);
    if (((unsigned int)img & 0x70000000) == 0x70000000) {
        *D2_MADR = ((unsigned int)img & 0x0FFFFFFF) | 0x80000000;
    } else {
        *D2_MADR = (unsigned int)img & 0x0FFFFFFF;
    }
    *D2_CHCR = 0x101;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsExecStoreImage);

int AddIntcHandler(int, int (*)(int), int);
int EnableIntc(int);

int sceGsSyncVCallback(int (*func)(int)) {
    sceGsGParam* gp = sceGsGetGParam();
    int old = gp->intcUsed;

    if (func == 0) {
        DisableIntc(2);
        RemoveIntcHandler(2, gp->handler);
        gp->handler = 0;
        gp->intcUsed = 0;
    } else {
        if (old != 0) {
            DisableIntc(2);
            RemoveIntcHandler(2, gp->handler);
        }
        gp->intcUsed = (int)func;
        gp->handler = AddIntcHandler(2, func, -1);
        EnableIntc(2);
    }
    return old;
}
