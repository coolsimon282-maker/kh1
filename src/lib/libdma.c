// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Its .data is defined at dch below.
#include "common.h"

typedef struct DmaChan {
    volatile int chcr; /* 0x00 */
    int pad0[3];
    unsigned int madr; /* 0x10 */
    int pad1[3];
    int qwc; /* 0x20 */
    int pad2[3];
    unsigned int tadr; /* 0x30 */
} DmaChan;

typedef struct {
    unsigned char mfd;   /* 0x00 */
    unsigned char sts;   /* 0x01 */
    unsigned char std;   /* 0x02 */
    unsigned char rcyc;  /* 0x03 */
    unsigned short cde;  /* 0x04 */
    unsigned short cpc;  /* 0x06 */
    unsigned short sqwc; /* 0x08 */
    unsigned short tqwc; /* 0x0A */
    void* rbadr;         /* 0x0C */
    int rbsize;          /* 0x10 */
} DmaEnv;

#ifdef VERSION_FM
// .data (0x0046C540-0x0046C580)
char D_0046C540[16] = "PsIIlibdma  2500"; // library version (no NUL)
DmaChan* dch[10] = { // the DMA channel registers
    (DmaChan*)0x10008000, (DmaChan*)0x10009000, (DmaChan*)0x1000A000, (DmaChan*)0x1000B000, (DmaChan*)0x1000B400,
    (DmaChan*)0x1000C000, (DmaChan*)0x1000C400, (DmaChan*)0x1000C800, (DmaChan*)0x1000D000, (DmaChan*)0x1000D400,
};
int D_0046C578[2] = {0};
#else
extern DmaChan* dch[10];
#endif
extern char D_00492E60[];            /* the sync timeout message */
extern int D_00492E78[10];           /* resetChan */
extern unsigned char D_00492EA0[16]; /* mfdCode */
extern unsigned char D_00492EB0[16]; /* stsCode */
extern unsigned char D_00492EC0[16]; /* stdCode */
extern DmaEnv D_0066FAD8;            /* sceDmaCurrentEnv */

int scePrintf(const char* fmt, ...);
int DIntr(void);
int EIntr(void);
unsigned int func_00267248(DmaChan* ch);
void memclr(void* p, int n);
int sceDmaPutEnv(DmaEnv* env);

void func_00266AB0(DmaChan* ch) {
    int n = 0x1000000;

    while (ch->chcr & 0x100) {
        if (--n < 0) {
            scePrintf(D_00492E60);
            func_00267248(ch);
        }
    }
}

void func_00266B20(DmaChan* ch, unsigned int addr, int n) {
    if (n == 0) {
        n = 0x1000000;
    }
    while (*(volatile unsigned int*)&ch->madr < addr) {
        if (--n < 0) {
            scePrintf(D_00492E60);
            func_00267248(ch);
        }
    }
}

unsigned int func_00266BA8(unsigned int addr) {
    if ((addr >> 28) == 7) {
        addr &= 0x0FFFFFFF;
        addr |= 0x80000000;
    }
    return addr;
}

void memclr(void* p, int n) {
    unsigned char* c = p;
    int i;
    for (i = n - 1; i != -1; i--) {
        *c++ = 0;
    }
}

DmaChan* sceDmaGetChan(unsigned int id) {
    if (id < 0xA) {
        return dch[id];
    }
    return 0;
}

int sceDmaReset(int mode) {
    DmaEnv env;
    int old;
    int i;

    old = *(volatile int*)0x1000E000 & 1;
    for (i = 0; i < 10; i++) {
        if (D_00492E78[i] != 0) {
            int* ch = (int*)dch[i];
            ch[0x00 / 4] = 0;
            ch[0x30 / 4] = 0;
            ch[0x10 / 4] = 0;
            ch[0x50 / 4] = 0;
            ch[0x40 / 4] = 0;
            ch[0x80 / 4] = 0;
        }
    }
    *(volatile int*)0x1000E010 = 0xFF1F;
    *(int*)0x1000E010 = *(volatile int*)0x1000E010 & 0xFF1F0000;
    memclr(&env, 0x14);
    sceDmaPutEnv(&env);
    if (mode == 1) {
        *(volatile int*)0x1000E000 = *(volatile int*)0x1000E000 | 1;
    }
    return old;
}

int sceDmaPutEnv(DmaEnv* env) {
    int ctrl = *(volatile int*)0x1000E000;
    int pcr = *(volatile int*)0x1000E020;
    int sqwc = *(volatile int*)0x1000E030;
    int rbor = *(volatile int*)0x1000E050;
    int rbsr = *(volatile int*)0x1000E040;

    if (env->mfd >= 10) {
        return -1;
    }
    if (env->sts >= 10) {
        return -2;
    }
    if (env->std >= 10) {
        return -3;
    }
    if (env->rcyc >= 7) {
        return -4;
    }
    ctrl = (ctrl & 0xFFFFFFCF) | (D_00492EA0[env->mfd] << 4);
    ctrl = (ctrl & 0xFFFFFF3F) | (D_00492EB0[env->sts] << 6);
    ctrl = (ctrl & 0xFFFFFFF3) | (D_00492EC0[env->std] << 2);
    if (env->rcyc != 0) {
        ctrl |= 2;
        ctrl = (ctrl & 0xFFFFFCFF) | ((env->rcyc - 1) << 8);
    } else {
        ctrl &= 0xFFFFFFFD;
    }
    pcr = (env->cde << 16) | env->cpc;
    sqwc = (env->tqwc << 16) | env->sqwc;
    rbor = (int)env->rbadr;
    rbsr = env->rbsize;
    *(volatile int*)0x1000E000 = ctrl;
    *(volatile int*)0x1000E020 = pcr;
    *(volatile int*)0x1000E030 = sqwc;
    *(volatile int*)0x1000E050 = rbor;
    *(volatile int*)0x1000E040 = rbsr;
    D_0066FAD8 = *env;
    return 0;
}

DmaEnv* sceDmaGetEnv(DmaEnv* env) {
    *env = D_0066FAD8;
    return env;
}

int sceDmaPutStallAddr(unsigned int addr) {
    int old = *(volatile int*)0x1000E060;
    *(int*)0x1000E060 = addr;
    return old;
}

void sceDmaSend(DmaChan* ch, unsigned int addr) {
    addr = func_00266BA8(addr);
    func_00266AB0(ch);
    if (ch->tadr != 0xFFFFFFFF) {
        ch->tadr = addr;
    }
    ch->qwc = 0;
    ch->chcr = (ch->chcr & ~0xC) | 0x105;
}

void sceDmaSendN(DmaChan* ch, unsigned int addr, int size) {
    addr = func_00266BA8(addr);
    func_00266AB0(ch);
    if (ch->madr != 0xFFFFFFFF) {
        ch->madr = addr;
    }
    ch->qwc = size;
    ch->chcr = (ch->chcr & ~0xC) | 0x101;
}

void sceDmaSendI(DmaChan* ch, unsigned int addr, int size) {
    addr = func_00266BA8(addr);
    func_00266AB0(ch);
    if (ch->madr != 0xFFFFFFFF) {
        ch->madr = addr;
    }
    ch->qwc = size;
    ch->chcr = (ch->chcr & ~0xC) | 0x109;
}

void sceDmaRecv(DmaChan* ch) {
    func_00266AB0(ch);
    ch->qwc = 0;
    ch->chcr = ((((ch->chcr & ~0xC) | 4) & ~1) | 0x100);
}

void sceDmaRecvN(DmaChan* ch, unsigned int addr, int size) {
    int c;

    addr = func_00266BA8(addr);
    func_00266AB0(ch);
    if (ch->madr != 0xFFFFFFFF) {
        ch->madr = addr;
    }
    ch->qwc = size;
    c = ch->chcr;
    c &= ~0xC;
    c &= ~1;
    c |= 0x100;
    ch->chcr = c;
}

void sceDmaRecvI(DmaChan* ch, unsigned int addr, int size) {
    addr = func_00266BA8(addr);
    func_00266AB0(ch);
    if (ch->madr != 0xFFFFFFFF) {
        ch->madr = addr;
    }
    ch->qwc = size;
    ch->chcr = (((ch->chcr & ~0xC) | 8) & ~1) | 0x100;
}

int func_002671D8(DmaChan* ch, int mode) {
    if (mode == 1) {
        return ((unsigned int)ch->chcr >> 8) & 1;
    }
    func_00266AB0(ch);
    return 0;
}

int func_00267210(DmaChan* ch, unsigned int addr, int mode, int n) {
    if (mode == 1) {
        return ch->madr < addr;
    }
    func_00266B20(ch, addr, n);
    return 0;
}

unsigned int func_00267248(DmaChan* ch) {
    int s;
    unsigned int en;
    unsigned int old;

    s = DIntr();
    en = *(volatile unsigned int*)0x1000F520;
    if (!(en & 0x10000)) {
        *(volatile unsigned int*)0x1000F590 = en | 0x10000;
    }
    *(volatile unsigned int*)0x1000E000;
    old = ch->chcr;
    ch->chcr = old & ~0x100;
    *(volatile unsigned int*)0x1000F590 = en;
    if (s) {
        EIntr();
    }
    return old;
}

int sceDmaRestart(DmaChan* ch, unsigned int chcr) {
    unsigned int v = ch->chcr;
    ch->chcr = chcr;
    return (v >> 8) & 1;
}
