// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

typedef struct {
    unsigned int d4madr;
    unsigned int d4tadr;
    unsigned int d4qwc;
    unsigned int d4chcr;
    unsigned int d3madr;
    unsigned int d3qwc;
    unsigned int d3chcr;
    unsigned int ipubp;
    unsigned int ipuctrl;
} IpuDmaEnv;

#define R_D3_CHCR ((volatile int*)0x1000B000)
#define R_D3_MADR ((volatile int*)0x1000B010)
#define R_D3_QWC ((volatile int*)0x1000B020)
#define R_D4_CHCR ((volatile int*)0x1000B400)
#define R_D4_MADR ((volatile int*)0x1000B410)
#define R_D4_QWC ((volatile int*)0x1000B420)
#define R_D4_TADR ((volatile int*)0x1000B430)
#define R_ENABLER ((volatile int*)0x1000F520)
#define R_ENABLEW ((volatile int*)0x1000F590)
#define R_IPU_CMD ((volatile int*)0x10002000)
#define R_IPU_CTRL ((volatile int*)0x10002010)
#define R_IPU_BP ((volatile int*)0x10002020)

int DIntr(void);
int EIntr(void);

void setD3_CHCR(int chcr) {
    DIntr();
    *R_ENABLEW = *R_ENABLER | 0x10000;
    *R_D3_CHCR = chcr;
    *R_ENABLEW = *R_ENABLER & 0xFFFEFFFF;
    EIntr();
}

void setD4_CHCR(int chcr) {
    DIntr();
    *R_ENABLEW = *R_ENABLER | 0x10000;
    *R_D4_CHCR = chcr;
    *R_ENABLEW = *R_ENABLER & 0xFFFEFFFF;
    EIntr();
}

void sceIpuStopDMA(IpuDmaEnv* env) {
    setD4_CHCR(1);
    env->d4madr = *R_D4_MADR;
    env->d4tadr = *R_D4_TADR;
    env->d4qwc = *R_D4_QWC;
    env->d4chcr = *R_D4_CHCR;
    while (*R_IPU_CTRL & 0xF0) {}
    setD3_CHCR(0);
    env->d3madr = *R_D3_MADR;
    env->d3qwc = *R_D3_QWC;
    env->d3chcr = *R_D3_CHCR;
    env->ipubp = *R_IPU_BP;
    env->ipuctrl = *R_IPU_CTRL;
}

void sceIpuRestartDMA(IpuDmaEnv* env) {
    unsigned int bp = env->ipubp;
    int cmd = bp & 0x7F;
    int n = ((bp >> 16) & 3) + ((bp >> 8) & 0xF);
    int madr = env->d4madr - (n << 4);
    int qwc = env->d4qwc + n;

    if (env->d3madr != 0 && env->d3qwc != 0) {
        *R_D3_MADR = env->d3madr;
        *R_D3_QWC = env->d3qwc;
        setD3_CHCR(env->d3chcr | 0x100);
    }
    while (*R_IPU_CTRL < 0) {}
    *R_IPU_CMD = cmd;
    while (*R_IPU_CTRL < 0) {}
    if (madr != 0 && qwc != 0) {
        *R_D4_MADR = madr;
        *R_D4_TADR = env->d4tadr;
        *R_D4_QWC = qwc;
        setD4_CHCR(env->d4chcr | 0x100);
    }
}

int sceIpuSync(int mode, unsigned short timeout) {
    int r = 0;
    switch (mode) {
    case 0:
        while (*R_IPU_CTRL < 0) {}
        r = 0;
        break;
    case 1:
        r = (unsigned)*R_IPU_CTRL >> 31;
        break;
    }
    return r;
}
