// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

typedef struct {
    unsigned int psize : 8;
    unsigned int dsize : 24;
    void* dest;
    int cid;
    unsigned int opt;
} SifCmdHeader;

typedef struct {
    SifCmdHeader header;
    int arglen;
    int mode;
    char arg[80];
} SifCmdResetData;

typedef struct {
    unsigned int src;
    unsigned int dest;
    int size;
    int attr;
} SifDmaData;

extern SifCmdResetData D_0066DD40 __attribute__((aligned(64))); /* resetData (64-aligned, in the bss) */
extern char D_00492350[];          /* "rom0:UDNL " */
extern char D_00492360[];          /* "too long parameter '%s'\n" */

void sceSifStopDma(void);
unsigned int sceSifGetReg(unsigned int reg);
unsigned int sceSifSetReg(unsigned int reg, unsigned int val);
unsigned int sceSifSetDma(SifDmaData* sdd, int len);
void sceSifWriteBackDCache(const void* p, int size);
void sceResetttyinit(void);
int sceSifInitRpc(unsigned int mode);
void sceSifExitRpc(void);
int scePrintf(const char* fmt, ...);

int sceSifResetIop(char* arg, int mode) {
    SifDmaData dma;
    int i;
    unsigned int addr;

    sceSifStopDma();
    addr = sceSifGetReg(0x80000000);
    D_0066DD40.mode = mode;
    for (i = 0; arg[i] != 0; i++) {
        D_0066DD40.arg[i] = arg[i];
    }
    D_0066DD40.arglen = i;
    D_0066DD40.header.dest = 0;
    D_0066DD40.header.cid = 0x80000003;
    D_0066DD40.header.dsize = 0;
    D_0066DD40.header.psize = sizeof(D_0066DD40);
    dma.src = (unsigned int)&D_0066DD40;
    dma.dest = addr;
    dma.size = sizeof(D_0066DD40);
    dma.attr = 0x44;
    sceSifWriteBackDCache(&D_0066DD40, sizeof(D_0066DD40));
    sceSifSetReg(4, 0x40000);
    if (sceSifSetDma(&dma, 1) != 0) {
        sceSifSetReg(4, 0x10000);
        sceSifSetReg(4, 0x20000);
        sceSifSetReg(0x80000002, 0);
        sceSifSetReg(0x80000000, 0);
        return 1;
    }
    return 0;
}

int sceSifIsAliveIop(void) {
    int t = sceSifGetReg(4) & 0x10000;
    return t != 0;
}

int sceSifSyncIop(void) {
    if (sceSifGetReg(4) & 0x40000) {
        sceResetttyinit();
        return 1;
    }
    return 0;
}

int sceSifRebootIop(const char* arg) {
    char buf[80];
    char* s = D_00492350;
    char* d;
    char* p;

    for (p = (char*)arg; *p != 0; p++) {}
    if ((unsigned int)(p + 11 - (char*)arg) > 80) {
        scePrintf(D_00492360, arg);
        return 0;
    }
    sceSifInitRpc(0);
    sceSifExitRpc();
    d = buf;
    while (*s != 0) {
        *d++ = *s++;
    }
    while (*arg != 0) {
        *d++ = *arg++;
    }
    *d = 0;
    return sceSifResetIop(buf, 0);
}
