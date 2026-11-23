// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

typedef struct { /* field names derived */
    unsigned int psize : 8;
    unsigned int dsize : 24;
    void *dest;
    int cid;
    int opt;
} SifCmdHeader; /* derived name */

typedef struct {
    SifCmdHeader header;
    int newaddr;
} SifCmdChangeAddrData; /* derived name */

typedef struct {
    SifCmdHeader header;
    int rno;
    int value;
} SifCmdSRegData; /* derived name */

typedef struct {
    void (*fn)();
    void *data;
} SifCmdEntry; /* derived name */

typedef struct {
    int sendbuf;
    int ackbuf;
    int iopbuf;
    SifCmdEntry *systbl;
    int nsys;
    SifCmdEntry *usrtbl;
    int nusr;
    int *sreg;
} SifCmdData; /* derived name */

/* sifcmd.o's data, still in the data segments */
extern int D_0066E6D4;        /* cmdDmacId */
extern SifCmdData D_0066E6D8; /* cmdData */
extern int D_0066E800[32];    /* cmdSreg */
extern int D_0046BE8C;        /* cmd_inited */

void _set_sreg(void *pkt, void *data)
{
    SifCmdSRegData *sr = pkt;
    SifCmdData *cd = data;

    cd->sreg[sr->rno] = sr->value;
}

void _change_addr(void *pkt, void *data)
{
    SifCmdChangeAddrData *ca = pkt;
    SifCmdData *cd = data;

    cd->iopbuf = ca->newaddr;
}

int sceSifGetSreg(int reg)
{
    return D_0066E800[reg];
}

int sceSifSetSreg(int reg, int val)
{
    D_0066E800[reg] = val;
    return val;
}

void *secSifGetDataTable(void)
{
    return &D_0066E6D8;
}

extern int D_0066E600[32];          /* cmdSendBuf */
extern int D_0066E680[16];          /* cmdAckBuf */
extern int D_0066E6C0[5];           /* cmdInitPkt */
extern SifCmdEntry D_0066E700[32];  /* sysCmdTable */

void DIntr(void);
void EIntr(void);
void FlushCache(int);
void sceSifSetDChain(void);
int AddDmacHandler(int ch, int (*fn)(int), int next);
int EnableDmac(int ch);
int sceSifGetReg(unsigned int reg);
int sceSifSetReg(unsigned int reg, int val);
int _sceSifCmdIntrHdlr(int);
unsigned int sceSifSendCmd(int cid, void *pkt, int pktsize, void *src, void *dest, int size);

void sceSifInitCmd(void)
{
    SifCmdEntry *h;
    int i;

    DIntr();
    if (D_0046BE8C != 0) {
        EIntr();
        return;
    }
    D_0046BE8C = 1;
    D_0066E6D8.sendbuf = (int)D_0066E600 | 0x20000000;
    D_0066E6D8.ackbuf = (int)D_0066E680 | 0x20000000;
    D_0066E6D8.iopbuf = 0;
    D_0066E6D8.systbl = D_0066E700;
    D_0066E6D8.nsys = 0x20;
    D_0066E6D8.usrtbl = 0;
    D_0066E6D8.nusr = 0;
    D_0066E6D8.sreg = D_0066E800;
    h = D_0066E700;
    for (i = 0; i < 32; i++) {
        h->fn = 0;
        h->data = 0;
        h++;
    }
    for (i = 0; i < 32; i++) {
        D_0066E800[i] = 0;
    }
    D_0066E700[0].fn = _change_addr;
    D_0066E700[0].data = &D_0066E6D8;
    D_0066E700[1].fn = _set_sreg;
    D_0066E700[1].data = &D_0066E6D8;
    EIntr();
    FlushCache(0);
    if (*(volatile int *)0x1000E010 & 0x20) {
        *(volatile int *)0x1000E010 = 0x20;
    }
    if ((*(volatile int *)0x1000C000 & 0x100) == 0) {
        sceSifSetDChain();
    }
    D_0066E6D4 = AddDmacHandler(5, _sceSifCmdIntrHdlr, 0);
    EnableDmac(5);
    D_0066E6D8.iopbuf = sceSifGetReg(0x80000000);
    if (D_0066E6D8.iopbuf != 0) {
        D_0066E6C0[4] = (int)D_0066E600;
        sceSifSendCmd(0x80000000, D_0066E6C0, 0x14, 0, 0, 0);
        return;
    }
    while ((sceSifGetReg(4) & 0x20000) == 0) {
        ;
    }
    D_0066E6D8.iopbuf = sceSifGetReg(2);
    sceSifSetReg(0x80000000, D_0066E6D8.iopbuf);
    sceSifSetReg(0x80000001, (int)&D_0066E6D8);
    D_0066E6C0[4] = (int)D_0066E600;
    D_0066E6C0[3] = 0;
    sceSifSendCmd(0x80000002, D_0066E6C0, 0x14, 0, 0, 0);
}

void sceSifExitCmd(void)
{
    DisableDmac(5);
    RemoveDmacHandler(5, D_0066E6D4);
    D_0046BE8C = 0;
}

SifCmdEntry *sceSifSetCmdBuffer(SifCmdEntry *tbl, int n)
{
    SifCmdEntry *old = D_0066E6D8.usrtbl;
    D_0066E6D8.usrtbl = tbl;
    D_0066E6D8.nusr = n;
    return old;
}

SifCmdEntry *sceSifSetSysCmdBuffer(SifCmdEntry *tbl, int n)
{
    SifCmdEntry *old = D_0066E6D8.systbl;
    D_0066E6D8.systbl = tbl;
    D_0066E6D8.nsys = n;
    return old;
}

void sceSifAddCmdHandler(int cid, void (*fn)(), void *data)
{
    int off = cid * 8;
    SifCmdEntry *h;
    if (cid >= 0)
        goto pos;
    cid = (int)D_0066E6D8.systbl;
    goto done;
pos:
    cid = (int)D_0066E6D8.usrtbl;
done:
    off += cid;
    h = (SifCmdEntry *)off;
    h->fn = fn;
    h->data = data;
}

void sceSifRemoveCmdHandler(int cid)
{
    int off = cid * 8;
    if (cid < 0) {
        cid = (int)D_0066E6D8.systbl;
    } else {
        cid = (int)D_0066E6D8.usrtbl;
    }
    off += cid;
    ((SifCmdEntry *)off)->fn = 0;
}

typedef struct {
    unsigned int src;
    unsigned int dest;
    int size;
    int attr;
} SifDmaEntry; /* sceSifDmaData */

void sceSifWriteBackDCache(void *p, int size);
unsigned int isceSifSetDma(SifDmaEntry *d, int n);
unsigned int sceSifSetDma(SifDmaEntry *d, int n);

int _sceSifSendCmd(int cid, int mode, void *pkt, int pktsize, void *src, void *dest, int size)
{
    SifDmaEntry dmat[2];
    SifCmdHeader *header;
    int count;

    if (pktsize < 16 || pktsize > 112) {
        return 0;
    }
    header = pkt;
    count = 0;
    if (size > 0) {
        header->dsize = size;
        dmat[0].src = (unsigned int)src;
        dmat[0].dest = (unsigned int)dest;
        dmat[0].size = size;
        header->dest = dest;
        dmat[0].attr = 0;
        count = 1;
        if (mode & 4) {
            sceSifWriteBackDCache(src, size);
        }
    } else {
        header->dsize = 0;
        header->dest = 0;
    }
    dmat[count].src = (unsigned int)pkt;
    dmat[count].dest = D_0066E6D8.iopbuf;
    dmat[count].size = pktsize;
    header->cid = cid;
    header->psize = pktsize;
    dmat[count].attr = 0x44;
    count++;
    sceSifWriteBackDCache(pkt, pktsize);
    if (mode & 1) {
        return isceSifSetDma(dmat, count);
    }
    return sceSifSetDma(dmat, count);
}

int _sceSifSendCmd(int cid, int mode, void *pkt, int pktsize, void *src, void *dest, int size);

unsigned int sceSifSendCmd(int cid, void *pkt, int pktsize, void *src, void *dest, int size)
{
    return _sceSifSendCmd(cid, 0, pkt, pktsize, src, dest, size);
}

unsigned int isceSifSendCmd(int cid, void *pkt, int pktsize, void *src, void *dest, int size)
{
    return _sceSifSendCmd(cid, 1, pkt, pktsize, src, dest, size);
}

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", _sceSifCmdIntrHdlr);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", sceSifWriteBackDCache);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", func_002607E4);
