// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Its .data is defined below (FM); the .bss is still in the data segments: declare it extern here.
#include "common.h"

#include "eekernel.h"
#include "sifrpc.h"
#include "sifcmd.h"

#ifdef VERSION_FM
/* cdvd000.o's .data (0x0046C600-0x0046E070); the receive/send buffers are 64-byte aligned for the SIF DMA */
char D_0046C600[16] = "PsIIlibcdvd 2500"; /* library version (no NUL) */
int SCE_CD_debug = 0;
int D_0046C614 = 0;               /* cb_thread_id */
int D_0046C618 = 0;               /* scmd_keep_cmd */
int D_0046C61C = 0;               /* ncmd_keep_cmd */
int D_0046C620 = -1;              /* cb_semid */
int Init_seq = 0;                 /* poff_busy */
int D_0046C628 = -1;              /* _sceCd_ncmd_semid */
int D_0046C62C = -1;              /* _sceCd_scmd_semid */
int _sceCd_c_cb_sem = 0;
volatile int D_0046C634 = 0;      /* _sceCd_ee_read_mode */
int D_0046C638 = -1;              /* ncmd_bind */
int _icmd_bind = -1;              /* poff_bind */
int D_0046C640 = -1;              /* search_bind */
int D_0046C644 = -1;              /* diskready_bind */
int D_0046C648 = -1;              /* scmd_bind */
int D_0046C64C = -1;              /* init_bind */
int D_0046C650 = 0;               /* init_count */
volatile int D_0046C654 = 0;      /* sceCdCbfunc_num */
int D_0046C658 = 0;               /* sceCdCbfunc_number */
int D_0046C680[32] __attribute__((aligned(64))) = {0};   /* _sceCd_ncmdrdata */
int D_0046C700[1024] __attribute__((aligned(64))) = {0}; /* _sceCd_ncmdsdata */
int D_0046D700[48] __attribute__((aligned(64))) = {0};   /* _sceCd_rd_intr_data */
int D_0046D7C0[4] = {0};          /* _sceCd_Read_cur_pos */
sceSifClientData _sceCd_cd_ncmd = {0};
int D_0046D800[272] __attribute__((aligned(64))) = {0};  /* _sceCd_scmdrdata */
int D_0046DC40[258] = {0};        /* _sceCd_scmdsdata */
sceSifClientData _sceCd_cd_scmd = {0};
#endif
/* cdvd000.o's .data (defined above in FM) and .bss (still in the data segments) */
extern int SCE_CD_debug;
extern int D_0046C614;            /* cb_thread_id */
extern int D_0046C618;            /* scmd_keep_cmd */
extern int D_0046C61C;            /* ncmd_keep_cmd */
extern int D_0046C620;            /* cb_semid */
extern int Init_seq;              /* poff_busy */
extern int D_0046C628;            /* _sceCd_ncmd_semid */
extern int D_0046C62C;            /* _sceCd_scmd_semid */
extern int _sceCd_c_cb_sem;
extern int D_0046C638;            /* ncmd_bind */
extern int D_0046C648;            /* scmd_bind */
extern int _icmd_bind;            /* poff_bind */
extern volatile int D_0046C654;   /* sceCdCbfunc_num */
extern int D_0046C658;            /* sceCdCbfunc_number */
extern int D_0046C680[];          /* _sceCd_ncmdrdata */
extern sceSifClientData _sceCd_cd_ncmd;
extern sceSifClientData _sceCd_cd_scmd;
extern int D_00673340;            /* cd_cbfunc */
extern void (*sceCdPoffCbfunc)(void*);
extern void* sceCdPoffCbdata;
extern int D_0067334C;            /* cb_thread_word */
extern int D_00673350;            /* cd_thread_id */
extern struct ThreadParam D_00673358; /* cd_thread_stat */
extern struct ThreadParam D_00673388; /* cb_thread_param */
extern char D_00494050[];         /* _gp */
/* strings */
extern char D_004930E0[]; /* "sceCdCbfunc= %d sceCdCbfunc_num= %d\n" */
extern char D_00493178[]; /* "Ncmd fail sema cur_cmd:%d keep_cmd:%d\n" */
extern char D_004931A0[]; /* "Libcdvd bind err N CMD\n" */
extern char D_004931B8[]; /* "N cmd wait\n" */
extern char D_004931C8[]; /* "S cmd wait\n" */
extern char D_004931D8[]; /* "Scmd fail sema cur_cmd:%d keep_cmd:%d\n" */
extern char D_00493200[]; /* "Libcdvd bind err S cmd\n" */


int sceCdSync(int mode);
int sceCdSyncS(int mode);
void _sceCd_cd_callback(void* data);
void _sceCd_Poff_Intr(void* data);
int PowerOffCB(void);
extern int D_0046C700[];  /* _sceCd_ncmdsdata */
extern int D_0046D700[];  /* _sceCd_rd_intr_data */
extern int D_0046D7C0[];  /* _sceCd_Read_cur_pos */
extern char D_00493290[]; /* "call cdread cmd\n" */
extern char D_004932A8[]; /* "cdread end\n" */
extern char D_004932B8[]; /* sceCdStatus's debug message */
void cmd_sem_init(void);
void cdvd_exit(void);
void _Cdvd_cbLoop(void* arg);

void CB_DelayTh(int id, unsigned short time, void* arg) {
    iSignalSema((int)arg);
    __asm__ volatile("sync
 ei");
}

void sceCdDelayThread(unsigned short ticks) {
    struct SemaParam buf;
    unsigned short id = ticks;
    int r;
    buf.maxCount = 1;
    buf.initCount = 0;
    buf.option = 0;
    r = CreateSema(&buf);
    SetAlarm(id, (void*)CB_DelayTh, (void*)r);
    WaitSema(r);
    DeleteSema(r);
}

int sceCdCallback(int func) {
    int ret;
    int s;
    if (sceCdSync(1) != 0) {
        return 0;
    }
    s = DIntr();
    ret = D_00673340;
    D_00673340 = func;
    if (s) {
        EIntr();
    }
    return ret;
}

void _sceCd_cd_callback(void* data) {
    int* result = data;

    D_0046C654 = result[0];
    *(volatile int*)&D_0046C658 = D_0046C654;
    if (D_0046C654 == 11) {
        D_0046C654 = 0;
        *(volatile int*)&_sceCd_c_cb_sem = 0;
        return;
    }
    iSignalSema(*(volatile int*)&D_0046C628);
    if (D_0046C614 != 0 && D_00673340 != 0) {
        iSignalSema(*(volatile int*)&D_0046C620);
    } else {
        _sceCd_c_cb_sem = 0;
    }
    D_0046C654 = 0;
}

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", _Cdvd_cbLoop);

int sceCdInitEeCB(int priority, void* stack, int stackSize) {
    int r = 1;

    if (D_0046C614 == 0) {
        D_00673350 = GetThreadId();
        ReferThreadStatus(D_00673350, &D_00673358);
        D_00673388.stackSize = stackSize;
        D_00673388.gpReg = D_00494050;
        D_00673388.entry = _Cdvd_cbLoop;
        D_00673388.stack = stack;
        D_00673388.initPriority = priority;
        D_0046C614 = CreateThread(&D_00673388);
        StartThread(D_0046C614, 0);
    } else {
        ChangeThreadPriority(D_0046C614, priority);
        r = 0;
    }
    return r;
}

typedef struct {
    int size1;
    int size2;
    char* dest1;
    char* dest2;
    char buf1[64];
    char buf2[64];
} CdReadEnd;

void func_00269790(void* pkt) {
    CdReadEnd* r = (CdReadEnd*)((int)pkt | 0x20000000);
    char* dst;
    int i;

    if (r->size1 > 0) {
        dst = r->dest1;
        for (i = 0; i < r->size1; i++) {
            dst[i] = r->buf1[i];
        }
    }
    if (r->size2 > 0) {
        dst = r->dest2;
        for (i = 0; i < r->size2; i++) {
            dst[i] = r->buf2[i];
        }
    }
    _sceCd_cd_callback((void*)&D_0046C654);
}

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", cmd_sem_init);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", cdvd_exit);

int sceCdPOffCallback(void (*func)(void*), void* arg) {
    int ret;
    int s;
    if (_icmd_bind < 0) {
        PowerOffCB();
    }
    s = DIntr();
    ret = (int)sceCdPoffCbfunc;
    sceCdPoffCbdata = arg;
    sceCdPoffCbfunc = func;
    if (s) {
        EIntr();
    }
    return ret;
}

void _sceCd_Poff_Intr(void* data) {
    if (sceCdPoffCbfunc != 0 && Init_seq == 0) {
        sceCdPoffCbfunc(sceCdPoffCbdata);
    }
}

int PowerOffCB(void) {
    int s;

    Init_seq = 1;
    s = DIntr();
    sceSifAddCmdHandler(0x80000012, _sceCd_Poff_Intr, 0);
    if (s) {
        EIntr();
    }
    Init_seq = 0;
    _icmd_bind = 1;
    return 1;
}

/* the search RPC's request record: the file entry the reply fills, the name, the request's own address and the
   layer */
typedef struct {
    unsigned char file[0x24];
    char name[0x100];
    void* addr;
    int layer;
} CdSearchReq;

typedef struct sceCdlFILE {
    unsigned char b[0x24];
} sceCdlFILE;

extern int D_0046C640;                 /* search_bind */
extern sceSifClientData D_0066D540;    /* search_cd */
extern CdSearchReq D_006733C0 __attribute__((aligned(64))); /* search_req */
extern int D_00673500[16];             /* search_rdata */
extern char D_00493108[]; /* "Libcdvd bind err CdSearchFile\n" */
extern char D_00493128[]; /* "ee call cmd search %s\n" */
extern char D_00493140[]; /* "search name %s\n" */
extern char D_00493150[]; /* "search size %d\n" */
extern char D_00493160[]; /* "search loc lbn %d\n" */

int sceCdSearchFile(sceCdlFILE* fp, const char* name, int layer) {
    char* req;
    int w;
    int i;
    int v;

    cmd_sem_init();
    if (D_0046C628 != PollSema(*(volatile int*)&D_0046C628)) {
        return 0;
    }
    D_0046C61C = 1;
    ReferThreadStatus(D_00673350, &D_00673358);
    if (sceCdSync(1) != 0) {
        SignalSema(*(volatile int*)&D_0046C628);
        return 0;
    }
    sceSifInitRpc(0);
    if (D_0046C640 < 0) {
        while (1) {
            if (sceSifBindRpc(&D_0066D540, 0x80000597, 0) < 0) {
                if (SCE_CD_debug > 0) {
                    scePrintf(D_00493108);
                }
                w = 0x100000;
                while (w--) {}
                continue;
            }
            if (D_0066D540.serve != 0) {
                D_0046C640 = 0;
                break;
            }
            w = 0x100000;
            while (w--) {}
        }
    }
    for (i = 0; i < 0x100; i++) {
        if ((D_006733C0.name[i] = name[i]) == 0) {
            break;
        }
    }
    if (i == 0x100) {
        D_006733C0.name[i - 1] = 0;
    }
    if (SCE_CD_debug > 0) {
        scePrintf(D_00493128, D_006733C0.name);
    }
    req = (char*)&D_006733C0;
    *(int*)(req + 0x128) = layer;
    *(char**)(req + 0x124) = req;
    sceSifWriteBackDCache(req, 0x12C);
    if (sceSifCallRpc(&D_0066D540, 0, 0, req, 0x12C, D_00673500, 4, 0, 0) < 0) {
        SignalSema(*(volatile int*)&D_0046C628);
        return 0;
    }
    *fp = *(sceCdlFILE*)((int)req | 0x20000000);
    if (SCE_CD_debug > 0) {
        scePrintf(D_00493140, (char*)fp + 8);
    }
    if (SCE_CD_debug > 0) {
        scePrintf(D_00493150, ((int*)fp)[1]);
    }
    if (SCE_CD_debug > 0) {
        scePrintf(D_00493160, ((int*)fp)[0]);
    }
    v = *(int*)((int)D_00673500 | 0x20000000);
    SignalSema(D_0046C628);
    return v;
}

int func_00269DA8(sceCdlFILE* fp, const char* name) {
    return sceCdSearchFile(fp, name, 0);
}

int _sceCd_ncmd_prechk(int cmd) {
    int w;

    cmd_sem_init();
    if (D_0046C628 != PollSema(*(volatile int*)&D_0046C628)) {
        if (SCE_CD_debug > 0) {
            scePrintf(D_00493178, cmd, D_0046C61C);
        }
        return 0;
    }
    D_0046C61C = cmd;
    ReferThreadStatus(D_00673350, &D_00673358);
    if (sceCdSync(1) != 0) {
        SignalSema(*(volatile int*)&D_0046C628);
        return 0;
    }
    sceSifInitRpc(0);
    if (D_0046C638 < 0) {
        while (1) {
            if (sceSifBindRpc(&_sceCd_cd_ncmd, 0x80000595, 0) < 0) {
                if (SCE_CD_debug > 0) {
                    scePrintf(D_004931A0);
                }
                w = 0x100000;
                while (w--) {}
                continue;
            }
            if (_sceCd_cd_ncmd.serve != 0) {
                D_0046C638 = 0;
                break;
            }
            w = 0x100000;
            while (w--) {}
        }
    }
    return 1;
}

int sceCdNcmdDiskReady(void) {
    int* p;
    int v;
    if (_sceCd_ncmd_prechk(2) == 0) {
        return 0;
    }
    p = D_0046C680;
    if (sceSifCallRpc(&_sceCd_cd_ncmd, 0xE, 0, 0, 0, p, 4, 0, 0) < 0) {
        SignalSema(D_0046C628);
        return 0;
    }
    v = *(int*)((int)p | 0x20000000);
    SignalSema(D_0046C628);
    return v;
}

int sceCdSync(int mode) {
    if (!mode) {
        if (SCE_CD_debug > 0)
            scePrintf(D_004931B8);
        while (_sceCd_c_cb_sem != 0 || sceSifCheckStatRpc(&_sceCd_cd_ncmd.rpcd)) {
            sceCdDelayThread(0x3C);
        }
        return 0;
    }
    if (_sceCd_c_cb_sem != 0 || sceSifCheckStatRpc(&_sceCd_cd_ncmd.rpcd) != 0) {
        return 1;
    }
    return 0;
}

int sceCdSyncS(int mode) {
    if (!mode) {
        if (SCE_CD_debug > 0)
            scePrintf(D_004931C8);
        while (sceSifCheckStatRpc(&_sceCd_cd_scmd.rpcd)) {
            sceCdDelayThread(0x3C);
        }
        return 0;
    }
    return sceSifCheckStatRpc(&_sceCd_cd_scmd.rpcd);
}

int _sceCd_scmd_prechk(int cmd) {
    int w;

    cmd_sem_init();
    if (D_0046C62C != PollSema(*(volatile int*)&D_0046C62C)) {
        if (SCE_CD_debug > 0) {
            scePrintf(D_004931D8, cmd, D_0046C618);
        }
        return 0;
    }
    D_0046C618 = cmd;
    ReferThreadStatus(D_00673350, &D_00673358);
    if (sceCdSyncS(1) != 0) {
        SignalSema(*(volatile int*)&D_0046C62C);
        return 0;
    }
    sceSifInitRpc(0);
    if (D_0046C648 < 0) {
        while (1) {
            if (sceSifBindRpc(&_sceCd_cd_scmd, 0x80000593, 0) < 0) {
                if (SCE_CD_debug > 0) {
                    scePrintf(D_00493200);
                }
                w = 0x100000;
                while (w--) {}
                continue;
            }
            if (_sceCd_cd_scmd.serve != 0) {
                D_0046C648 = 0;
                break;
            }
            w = 0x100000;
            while (w--) {}
        }
    }
    return 1;
}

extern volatile int D_0046C634;     /* _sceCd_ee_read_mode */
extern int D_0046C644;              /* diskready_bind */
extern int D_0046C64C;              /* init_bind */
extern int D_0046C650;              /* init_count */
extern sceSifClientData D_0066D568; /* init_cd */
extern sceSifClientData D_00673590; /* diskready_cd */
extern int D_006735C0;              /* init_sdata */
extern int D_006735D0;              /* diskready_sdata */
extern int D_0046D800[];            /* _sceCd_scmdrdata */
extern int D_0046DC40[];            /* _sceCd_scmdsdata */
extern char D_00493218[]; /* "Libcdvd bind err %d CD_Init %d\n" */
extern char D_00493238[]; /* "Libcdvd Exit\n" */
extern char D_00493248[]; /* "DiskReady 0\n" */
extern char D_00493258[]; /* "Libcdvd bind err CdDiskReady\n" */
extern char D_00493278[]; /* "DiskReady ended\n" */

int sceCdInit(int mode) {
    int* p;
    int ver;
    int r;
    int w;
    int type;
    int v1;
    int v2;

    if (sceCdSyncS(1) != 0) {
        return 0;
    }
    sceSifInitRpc(0);
    D_00673350 = GetThreadId();
    *(volatile int*)&Init_seq = 1;
    D_0046C640 = -1;
    D_0046C638 = -1;
    D_0046C648 = -1;
    D_0046C644 = -1;
    D_0046C64C = -1;
    _icmd_bind = -1;
    *(volatile int*)&D_0046C634 = 0;
    D_0046C650++;
    while (1) {
        r = sceSifBindRpc(&D_0066D568, 0x80000592, 0);
        if (r < 0) {
            if (SCE_CD_debug > 0) {
                scePrintf(D_00493218, r, D_0046C650);
            }
            w = 0x100000;
            while (w--) {}
            continue;
        }
        if (D_0066D568.serve != 0) {
            D_006735C0 = mode;
            D_0046C64C = 0;
            sceSifWriteBackDCache(&D_006735C0, 4);
            p = D_0046D800;
            if (sceSifCallRpc(&D_0066D568, 0, 0, &D_006735C0, 4, p, 16, 0, 0) < 0) {
                *(volatile int*)&Init_seq = 0;
                return 0;
            }
            break;
        }
        w = 0x100000;
        while (w--) {}
    }
    v1 = *(int*)((int)(p + 1) | 0x20000000);
    v2 = *(int*)((int)(p + 2) | 0x20000000);
    type = *(int*)((int)(p + 3) | 0x20000000);
    ver = 1;
    if (type == 0xFF) {
    } else if (type == 0xFE) {
        SCE_CD_debug = 1;
    } else if (v1 / 256 < 2 || v2 / 256 < 2) {
        ver = 2;
    }
    *(volatile int*)&Init_seq = 0;
    switch (mode) {
    case 5:
        if (SCE_CD_debug > 0) {
            scePrintf(D_00493238);
        }
        cdvd_exit();
        *(volatile int*)&D_0046C628 = -1;
        *(volatile int*)&D_0046C62C = -1;
        *(volatile int*)&D_0046C620 = -1;
        break;
    case 0:
    case 1:
    default:
        cmd_sem_init();
        PowerOffCB();
        break;
    }
    return ver;
}

int sceCdDiskReady(int mode) {
    int v;
    int w;

    if (SCE_CD_debug > 0) {
        scePrintf(D_00493248);
    }
    cmd_sem_init();
    if (D_0046C62C != PollSema(*(volatile int*)&D_0046C62C)) {
        return 6;
    }
    if (sceCdSyncS(1) != 0) {
        SignalSema(*(volatile int*)&D_0046C62C);
        return (mode != 8) ? 6 : -1;
    }
    sceSifInitRpc(0);
    if (D_0046C644 < 0) {
        while (1) {
            if (sceSifBindRpc(&D_00673590, 0x8000059A, 0) < 0) {
                if (SCE_CD_debug > 0) {
                    scePrintf(D_00493258);
                }
                w = 0x100000;
                while (w--) {}
                continue;
            }
            if (D_00673590.serve != 0) {
                D_0046C644 = 0;
                break;
            }
            w = 0x100000;
            while (w--) {}
        }
    }
    D_006735D0 = mode;
    sceSifWriteBackDCache(&D_006735D0, 4);
    if (sceSifCallRpc(&D_00673590, 0, 0, &D_006735D0, 4, D_0046D800, 4, 0, 0) < 0) {
        SignalSema(*(volatile int*)&D_0046C62C);
        return (mode != 8) ? 6 : -1;
    }
    if (SCE_CD_debug > 0) {
        scePrintf(D_00493278);
    }
    v = *(int*)((int)D_0046D800 | 0x20000000);
    SignalSema(D_0046C62C);
    return v;
}

int sceCdMmode(int media) {
    int* p;
    int* sd;
    int v;
    sd = D_0046DC40;
    if (_sceCd_scmd_prechk(0x22) == 0) {
        return 0;
    }
    sd[0] = media;
    sceSifWriteBackDCache(sd, 4);
    p = D_0046D800;
    if (sceSifCallRpc(&_sceCd_cd_scmd, 0x22, 0, sd, 4, p, 4, 0, 0) < 0) {
        SignalSema(D_0046C62C);
        return 0;
    }
    v = *(int*)((int)p | 0x20000000);
    SignalSema(D_0046C62C);
    return v;
}

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdRead);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdSeek);

int sceCdGetError(void) {
    int* p;
    int v;
    if (_sceCd_scmd_prechk(3) == 0) {
        return -1;
    }
    p = D_0046D800;
    if (sceSifCallRpc(&_sceCd_cd_scmd, 4, 0, 0, 0, p, 4, 0, 0) < 0) {
        SignalSema(D_0046C62C);
        return -1;
    }
    v = *(int*)((int)p | 0x20000000);
    SignalSema(D_0046C62C);
    return v;
}

int sceCdStatus(void) {
    int* p;
    int v;
    if (_sceCd_scmd_prechk(2) == 0) {
        return -1;
    }
    p = D_0046D800;
    if (sceSifCallRpc(&_sceCd_cd_scmd, 0xC, 0, 0, 0, p, 4, 0, 0) < 0) {
        SignalSema(D_0046C62C);
        return -1;
    }
    v = *(int*)((int)p | 0x20000000);
    SignalSema(D_0046C62C);
    if (SCE_CD_debug >= 2) {
        scePrintf(D_004932B8);
    }
    return v;
}

int sceCdBreak(void) {
    int* p;
    int v;
    if (_sceCd_scmd_prechk(0x1E) == 0) {
        return 0;
    }
    p = D_0046D800;
    D_0046C654 = 8;
    if (sceSifCallRpc(&_sceCd_cd_scmd, 0x16, 0, 0, 0, p, 4, 0, 0) < 0) {
        SignalSema(*(volatile int*)&D_0046C62C);
        D_0046C654 = 0;
        return 0;
    }
    D_0046C654 = 0;
    v = *(int*)((int)p | 0x20000000);
    SignalSema(*(volatile int*)&D_0046C62C);
    return v;
}

int sceCdPowerOff(int* stat) {
    int* p;
    int v;
    if (_sceCd_scmd_prechk(0x21) == 0) {
        return 0;
    }
    p = D_0046D800;
    if (sceSifCallRpc(&_sceCd_cd_scmd, 0x21, 0, 0, 0, p, 8, 0, 0) < 0) {
        SignalSema(D_0046C62C);
        return 0;
    }
    *stat = *(int*)((int)(p + 1) | 0x20000000);
    v = *(int*)((int)p | 0x20000000);
    SignalSema(D_0046C62C);
    return v;
}
