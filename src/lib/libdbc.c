// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

/* libdbc has no reference source: the types are derived from the assembly. */

typedef struct {
    void *pkt;
    int pid;
    int sema;
    unsigned int mode;
    unsigned int command;
    void *buff;
    void *cbuff;
    void (*func)(void *);
    void *para;
    void *serve; /* 0x24, zero until the bind is answered */
} DbcClient;

typedef struct {
    int w[16];
} DbcSocketTable;

typedef struct {
    unsigned int option;
    int type;
    int port;
    int slot;
    int number;
    unsigned char name[16];
} DbcSocketParam;

typedef struct {
    int s;
    int cmd;
    int len;
    unsigned char data[0x80];
    int ret;
} DbcSendBuf;

typedef struct {
    int s;
    int cmd;
    int slen;
    int rlen;
    unsigned char sdata[0x80];
    unsigned char rdata[0x80];
    int ret;
} DbcSRBuf;

typedef struct {
    unsigned int option;
    int type;
    int port;
    int slot;
    int number;
    unsigned char name[16];
    int ret;
    void *buf0;
    void *buf1;
} DbcCreateBuf;

extern DbcClient D_00669B08;      /* the client of the dbcman RPC server 0x80000900 */
extern int D_00669B80[256];       /* the RPC send and receive buffer */
extern DbcSocketTable D_0066A000; /* the socket states */
extern DbcClient D_0066FB30;      /* the client of the RPC server 0x8000091B (sceDbcSendData2) */
extern DbcSocketTable D_0066FF80; /* the work area the IOP writes the socket states to */
extern char D_00492ED0[];
extern char D_00492EE8[];
extern char D_00492F10[];
extern char D_00492F38[];
extern char D_00492F50[];
extern char D_00492F70[];
extern char D_00492F90[];
extern char D_00492FB0[];
extern char D_00492FD0[];
extern char D_00492FF0[];
extern char D_00493010[];
extern char D_00493038[];
extern char D_00493058[];
extern char D_00493078[];
extern char D_00493098[];

int sceSifCallRpc(DbcClient *cd, unsigned int rpc_number, unsigned int mode, void *sendbuf, int ssize,
                  void *recvbuf, int rsize, void (*end_func)(void *), void *end_param);
int sceSifBindRpc(DbcClient *cd, unsigned int sid, int mode);
void sceSifInitRpc(int mode);
int sceSifCheckStatRpc(DbcClient *cd);
int DIntr(void);
int EIntr(void);
void SyncDCache(void *a, void *b);
void exit(int);
void scePrintf(char *fmt, ...);
void DPRINT(char *fmt, ...);
int sceDbcSetWorkAddr(void *addr);

int sceDbcGetModVersion(void)
{
    sceSifCallRpc(&D_00669B08, 0x80000963, 0, D_00669B80, 0x400, D_00669B80, 0x400, 0, 0);
    return D_00669B80[0];
}

int sceDbcInit(void)
{
    int i;
    int ver;

    sceSifInitRpc(0);
    while (1) {
        if (sceSifBindRpc(&D_00669B08, 0x80000900, 0) < 0) {
            DPRINT(D_00492ED0);
            exit(-1);
        }
        if (D_00669B08.serve != 0) {
            break;
        }
        i = 0x10000;
        while (i--) {
        }
    }
    while (1) {
        if (sceSifBindRpc(&D_0066FB30, 0x8000091B, 0) < 0) {
            DPRINT(D_00492ED0);
            exit(-1);
        }
        if (D_0066FB30.serve != 0) {
            break;
        }
        i = 0x10000;
        while (i--) {
        }
    }
    ver = sceDbcGetModVersion();
    if ((ver >> 8) != 2) {
        scePrintf(D_00492EE8);
        scePrintf(D_00492F10, 2, 0, ver >> 8, ver & 0xFF);
        return 0;
    }
    for (i = 0; i < 16; i++) {
        D_0066A000.w[i] = 0;
    }
    DPRINT(D_00492F38, &D_0066FF80);
    sceDbcSetWorkAddr(&D_0066FF80);
    return 1;
}

int sceDbcEnd(void)
{
    return 1;
}

int sceDbcSetWorkAddr(void *addr)
{
    D_00669B80[1] = (int)addr;
    if (sceSifCallRpc(&D_00669B08, 0x80000904, 0, D_00669B80, 0x400, D_00669B80, 0x400, 0, 0) < 0) {
        DPRINT(D_00492F50);
        return 0;
    }
    return D_00669B80[0];
}

int sceDbcCreateSocket(DbcSocketParam *param, void *buf0, void *buf1)
{
    int i;
    DbcCreateBuf *p = (DbcCreateBuf *)D_00669B80;

    p->buf0 = buf0;
    p->buf1 = buf1;
    p->option = param->option;
    p->type = param->type;
    p->port = param->port;
    p->slot = param->slot;
    p->number = param->number;
    for (i = 0; i < 16; i++) {
        p->name[i] = param->name[i];
    }
    if (sceSifCallRpc(&D_00669B08, 0x80000901, 0, D_00669B80, 0x400, D_00669B80, 0x400, 0, 0) < 0) {
        DPRINT(D_00492F70);
        return 0;
    }
    return p->ret;
}

int sceDbcDeleteSocket(int s)
{
    D_00669B80[0] = s;
    if (sceSifCallRpc(&D_00669B08, 0x80000902, 0, D_00669B80, 0x400, D_00669B80, 0x400, 0, 0) < 0) {
        DPRINT(D_00492F90);
        return 0;
    }
    return D_00669B80[1];
}

int sceDbcGetDepNumber(int s)
{
    SyncDCache(&D_0066FF80, (char *)&D_0066FF80 + 0x80);
    DIntr();
    D_0066A000 = D_0066FF80;
    EIntr();
    if (D_0066A000.w[s] != 1) {
        return -12;
    }
    D_00669B80[0] = s;
    if (sceSifCallRpc(&D_00669B08, 0x80000903, 0, D_00669B80, 0x400, D_00669B80, 0x400, 0, 0) < 0) {
        DPRINT(D_00492FB0);
        return 0;
    }
    return D_00669B80[1];
}

int sceDbcInitSocket(int s)
{
    D_00669B80[0] = s;
    if (sceSifCallRpc(&D_00669B08, 0x80000915, 0, D_00669B80, 0x400, D_00669B80, 0x400, 0, 0) < 0) {
        DPRINT(D_00492FD0);
        return 0;
    }
    return D_00669B80[1];
}

int sceDbcResetSocket(int s)
{
    D_00669B80[0] = s;
    if (sceSifCallRpc(&D_00669B08, 0x80000916, 0, D_00669B80, 0x400, D_00669B80, 0x400, 0, 0) < 0) {
        DPRINT(D_00492FF0);
        return 0;
    }
    return D_00669B80[1];
}

int sceDbcGetDeviceStatus(int s)
{
    D_00669B80[0] = s;
    if (sceSifCallRpc(&D_00669B08, 0x80000917, 0, D_00669B80, 0x400, D_00669B80, 0x400, 0, 0) < 0) {
        DPRINT(D_00493010);
        return 0;
    }
    return D_00669B80[1];
}

int sceDbcSRData(int s, int cmd, int *slen, unsigned char *sdata, int *rlen, unsigned char *rdata)
{
    int i;
    DbcSRBuf *p = (DbcSRBuf *)D_00669B80;

    p->s = s;
    p->cmd = cmd;
    p->slen = *slen;
    p->rlen = *rlen;
    for (i = 0; i < *slen; i++) {
        p->sdata[i] = sdata[i];
    }
    if (sceSifCallRpc(&D_00669B08, 0x80000918, 0, D_00669B80, 0x400, D_00669B80, 0x400, 0, 0) < 0) {
        DPRINT(D_00493038);
        return 0;
    }
    if (p->ret >= 0) {
        *slen = p->slen;
        *rlen = p->rlen;
        for (i = 0; i < p->rlen; i++) {
            rdata[i] = p->rdata[i];
        }
    }
    return p->ret;
}

int sceDbcSendData(int s, int cmd, int *len, unsigned char *data)
{
    int i;
    DbcSendBuf *p = (DbcSendBuf *)D_00669B80;

    p->s = s;
    p->cmd = cmd;
    p->len = *len;
    for (i = 0; i < *len; i++) {
        p->data[i] = data[i];
    }
    if (sceSifCallRpc(&D_00669B08, 0x80000919, 0, D_00669B80, 0x400, D_00669B80, 0x400, 0, 0) < 0) {
        DPRINT(D_00493058);
        return 0;
    }
    if (p->ret < 0) {
        return p->ret;
    }
    *len = p->len;
    return p->ret;
}

int sceDbcSendData2(int s, int cmd, int *len, unsigned char *data)
{
    int i;
    DbcSendBuf *p = (DbcSendBuf *)D_00669B80;

    p->s = s;
    p->cmd = cmd;
    p->len = *len;
    for (i = 0; i < *len; i++) {
        p->data[i] = data[i];
    }
    if (sceSifCheckStatRpc(&D_0066FB30) == 1) {
        return 0;
    }
    if (sceSifCallRpc(&D_0066FB30, 0x8000091B, 1, D_00669B80, 0x400, D_00669B80, 0x400, 0, 0) < 0) {
        DPRINT(D_00493078);
        return 0;
    }
    return 1;
}

int sceDbcReceiveData(int s, int cmd, int *len, unsigned char *data)
{
    int i;
    DbcSendBuf *p = (DbcSendBuf *)D_00669B80;

    p->s = s;
    p->cmd = cmd;
    p->len = *len;
    if (sceSifCallRpc(&D_00669B08, 0x8000091A, 0, D_00669B80, 0x400, D_00669B80, 0x400, 0, 0) < 0) {
        DPRINT(D_00493098);
        return 0;
    }
    if (p->ret >= 0) {
        *len = p->len;
        for (i = 0; i < p->len; i++) {
            data[i] = p->data[i];
        }
    }
    return p->ret;
}

void DPRINT(char *fmt, ...)
{
}
