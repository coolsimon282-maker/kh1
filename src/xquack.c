/**
 * EE side of the sound driver: SIF RPC calls to the IOP sound module (RPC id 0x11). Each wrapper puts its arguments
 * in soundRpcBuf (0x2000 bytes, sent and received), calls one command number and returns the buffer. The driver also
 * writes the state of its 24 voices to D_0063D640 (0xB4 bytes each), which SoundRpc_IsVoiceActive reads.
 */
#include "common.h"
#include "xquack.h"
#include "eekernel.h"
#include "sifrpc.h"

typedef struct XDuck {
    /* 0x00 */ u8 unk_00;
    /* 0x00 */ s8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s8 unk_04;
    /* 0x05 */ char unk_05[11];
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char unk_14[4];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ char unk_1C[0x2C];
} XDuck; // size = 0x48

#ifdef VERSION_FM
// .data (0x003E3C80-0x003E3CB8)
s32 D_003DE5B8 = 0;
sceSifClientData soundRpcClient = {{0}};
s32 D_003E3CB0 = 0;
#else
s32 D_003DE5B8;
sceSifClientData soundRpcClient;
#endif

void* soundRpcBuf;
XDuck D_00639180[3];
s32 D_00639588;
s32 D_00639880;

extern s8 D_0063F640[256];

typedef struct {
    /* 0x00 */ s8 active;
    /* 0x01 */ char unk_01[3];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[4];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char unk_14[0xA0];
} XQuackVoice; // size = 0xB4

extern u8 D_0063D640[0x2000];

void func_001ED878(s32 arg0) {
    D_003DE5B8 = arg0;
}

extern s32 D_00635640[0x400][8];
extern s32 D_003E3CB0;
extern char D_00490910[];
int printf(const char*, ...);

// Clears the buffers, binds the sound RPC server (id 0x11, retrying) and sends command 0 with the voice-state buffers.
s32 SoundRpc_Initialize(s32 arg0) {
    u32 i;
    u32 j;
    s32* buf;
    u8* p;

    func_001ED878(0);
    for (i = 0; i < 0x800; i++) {
        ((u32*)&soundRpcBuf)[i] = 0;
    }
    p = D_0063D640;
    for (i = 0; i < 0x2000; i++) {
        p[i] = 0;
    }
    p = (u8*)D_0063F640;
    for (i = 0; i < 0x100; i++) {
        p[i] = 0;
    }
    while (1) {
        if (sceSifBindRpc(&soundRpcClient, 0x11, 0) < 0) {
            printf(D_00490910);
            return -1;
        }
        if (soundRpcClient.serve != NULL) {
            break;
        }
        i = 0x10000;
        while (i--) {
        }
    }
    D_003E3CB0 = 0;
    for (j = 0; j < 0x400; j++) {
        for (i = 0; i < 8; i++) {
            D_00635640[j][i] = -1;
        }
    }
    buf = (s32*)&soundRpcBuf;
    buf[0] = (s32)D_0063D640;
    buf[1] = arg0;
    buf[2] = (s32)D_0063F640;
    sceSifCallRpc(&soundRpcClient, 0, 0, buf, 0x2000, buf, 0x2000, NULL, NULL);
    return 0;
}

// Sends sound RPC command 31 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EDA60(void) {
    sceSifCallRpc(&soundRpcClient, 31, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Sends sound RPC command 32 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EDAB8(void) {
    sceSifCallRpc(&soundRpcClient, 32, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Sends sound RPC command 33 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EDB10(void) {
    sceSifCallRpc(&soundRpcClient, 33, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Sends sound RPC command 34 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EDB68(void) {
    sceSifCallRpc(&soundRpcClient, 34, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Returns 1 if one of the 24 voices plays sound arg0 (with arg1 / arg2 matching unless < 0).
s32 SoundRpc_IsVoiceActive(s32 arg0, s32 arg1, s32 arg2) {
    XQuackVoice* p;
    s32 i;

    FlushCache(0);
    p = (XQuackVoice*)D_0063D640;
    if (arg1 < 0 && arg2 < 0) {
        for (i = 0; i < 24; i++, p++) {
            if (p->active != 0 && p->unk_0C == arg0) {
                return 1;
            }
        }
    } else if (arg1 < 0) {
        for (i = 0; i < 24; i++, p++) {
            if (p->active != 0 && p->unk_0C == arg0 && p->unk_04 == arg2) {
                return 1;
            }
        }
    } else if (arg2 < 0) {
        for (i = 0; i < 24; i++, p++) {
            if (p->active != 0 && p->unk_0C == arg0 && p->unk_10 == arg1) {
                return 1;
            }
        }
    }
    for (i = 0; i < 24; i++, p++) {
        if (p->active != 0 && p->unk_0C == arg0 && p->unk_10 == arg1 && p->unk_04 == arg2) {
            return 1;
        }
    }
    return 0;
}

typedef struct {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ u8 rate[4]; // big-endian sample rate
    /* 0x14 */ u8 unk_14[0xA];
    /* 0x1E */ u8 unk_1E;
    /* 0x1F */ u8 unk_1F;
} XQuackVag;

void* func_001EDD20(XQuackVag* vag, s32 arg1, s32 arg2, s32 arg3) {
    s32 base = 48000;
    s32 rate;
    s32 pitch;
    u8 e;
    u8 f;

    rate = vag->rate[0] << 24;
    rate |= vag->rate[1] << 16;
    rate |= vag->rate[2] << 8;
    rate |= vag->rate[3];
    pitch = (rate << 12) / base;
    e = vag->unk_1E;
    f = vag->unk_1F;
    if (!(D_003DE5B8 & 4)) {
        func_001EE0B8(0x12, (s32)vag, arg1, arg2, arg3, pitch, e, f);
        return soundRpcBuf;
    }
    return soundRpcBuf;
}

s32 func_001EDDC0(s32 arg0, s32 arg1, s32 arg2) {
    XDuck* p;
    s32 i;
    s32 count;

    FlushCache(0);
    p = D_00639180;
    if (arg0 < 0 && arg1 < 0 && arg2 == 0) {
        count = 0;
        for (i = 0; i < 4; i++, p++) {
            if (p->unk_04 != 0) {
                count++;
            }
        }
        return count;
    } else if (arg0 < 0) {
        if (arg2 == 0) {
            count = 0;
            for (i = 0; i < 4; i++, p++) {
                if (p->unk_04 != 0 && (p->unk_00 & 0x7F) == 1) {
                    count++;
                }
            }
            return count;
        }
        for (i = 0; i < 4; i++, p++) {
            if (p->unk_04 != 0 && (p->unk_00 & 0x7F) == 1 && p->unk_10 == arg2) {
                return 1;
            }
        }
        return 0;
    }
    for (i = 0; i < 4; i++, p++) {
        if (p->unk_04 != 0 && p->unk_00 == 0 && p->unk_02 == arg0 && p->unk_03 == arg1) {
            return 1;
        }
    }
    return 0;
}

void* func_001EDF28(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (!(D_003DE5B8 & 8)) {
        func_001EE0B8(41, arg0, arg1, arg2, arg3, 0, 0, 0);
        return soundRpcBuf;
    }
    return soundRpcBuf;
}

// Looks arg0 up in the three cached entries (D_00639180) and returns its unk_18 (0 if none).
s32 SoundRpc_FindCachedValue(s32 arg0) {
    XDuck* p0;
    s32 i;

    FlushCache(WRITEBACK_DCACHE);
    p0 = D_00639180;

    for (i = 0; i <= ARRAY_COUNT(D_00639180); i++, p0++) {
        if (p0->unk_04 != 0 && p0->unk_10 == arg0) {
            return p0->unk_18;
        }
    }
    return 0;
}

s32 func_001EDFF8(s8* arg0) {
    s32 i;
    s8* p;

    for (i = 0; i < 255; i++) {
        *arg0++ = D_0063F640[i];
    }
    D_0063F640[255] = 0;
    if (D_0063F640[0] == 0) {
        return 0;
    }
    p = &D_0063F640[255];
    for (i = 255; i >= 0; i--) {
        *p-- = 0;
    }
    return 1;
}

s32 func_001EE068(void) {
    FlushCache(WRITEBACK_DCACHE);
    return D_00639588;
}

s32 func_001EE090(void) {
    FlushCache(WRITEBACK_DCACHE);
    return D_00639880;
}

extern s32 D_00635640[0x400][8];
extern s32 D_003E3CB0;
extern char D_00490928[];
int printf(const char*, ...);

void func_001EE0B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 n = D_003E3CB0;

    D_00635640[n][0] = arg0;
    D_00635640[n][1] = arg1;
    D_00635640[n][2] = arg2;
    D_00635640[n][3] = arg3;
    D_00635640[n][4] = arg4;
    D_00635640[n][5] = arg5;
    D_00635640[n][6] = arg6;
    D_00635640[n][7] = arg7;
    D_003E3CB0 = n + 1;
    if (n + 1 >= 0x400) {
        D_003E3CB0 = 0;
        printf(D_00490928);
    }
}

// Sends sound RPC command 1 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EE188(void* arg0) {
    soundRpcBuf = arg0;
    sceSifCallRpc(&soundRpcClient, 1, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

void* func_001EE1E0(s32 arg0, s32 arg1) {
    func_001EE0B8(38, arg0, arg1, 0, 0, 0, 0, 0);
    return soundRpcBuf;
}

// Sends sound RPC command 39 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EE228(void* arg0) {
    soundRpcBuf = arg0;
    sceSifCallRpc(&soundRpcClient, 39, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);

    return soundRpcBuf;
}

// Sends sound RPC command 15 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EE280(void* arg0) {
    soundRpcBuf = arg0;
    sceSifCallRpc(&soundRpcClient, 15, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);

    return soundRpcBuf;
}

void* func_001EE2D8(s32 arg0, s32 arg1, s32 arg2) {
    D_00639880++;
    func_001EE0B8(4, arg0, arg1, arg2, 0, 0, 0, 0);
    return soundRpcBuf;
}

void* func_001EE330(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (!(D_003DE5B8 & 2)) {
        func_001EE0B8(5, arg0, arg1, arg2, arg3, arg4, 0, 0);
        return soundRpcBuf;
    }
    return soundRpcBuf;
}

void* func_001EE390(s32 arg0, s32 arg1, s32 arg2) {
    func_001EE0B8(6, arg0, arg1, arg2, 0, 0, 0, 0);
    return soundRpcBuf;
}

void* func_001EE3D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001EE0B8(2, arg0, arg1, arg2, arg3, 0, 0, 0);
    return soundRpcBuf;
}

void* func_001EE428(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_001EE0B8(7, arg0, arg1, arg2, arg3, arg4, 0, 0);
    return soundRpcBuf;
}

void* func_001EE478(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_001EE0B8(8, arg0, arg1, arg2, arg3, arg4, 0, 0);
    return soundRpcBuf;
}

void* func_001EE4C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001EE0B8(9, arg0, arg1, arg2, arg3, 0, 0, 0);
    return soundRpcBuf;
}

void* func_001EE518(s32 arg0, s32 arg1, s32 arg2) {
    D_00639880++;
    func_001EE0B8(11, arg0, arg1, arg2, 0, 0, 0, 0);
    return soundRpcBuf;
}

void* func_001EE570(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    if (!(D_003DE5B8 & 1)) {
        func_001EE0B8(12, arg0, arg1, arg2, arg3, arg4, arg5, 0);
        return soundRpcBuf;
    }
    return soundRpcBuf;
}

void* func_001EE5D8(s32 arg0) {
    func_001EE0B8(13, arg0, 0, 0, 0, 0, 0, 0);
    return soundRpcBuf;
}

void* func_001EE618(s32 arg0, s32 arg1, s32 arg2) {
    func_001EE0B8(14, arg0, arg1, arg2, 0, 0, 0, 0);
    return soundRpcBuf;
}

// Sends sound RPC command 47 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EE660(void* arg0) {
    soundRpcBuf = arg0;
    sceSifCallRpc(&soundRpcClient, 47, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Sends sound RPC command 48 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EE6B8(void* arg0) {
    soundRpcBuf = arg0;
    sceSifCallRpc(&soundRpcClient, 48, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

void* func_001EE710(s32 arg0, s32 arg1, s32 arg2) {
    D_00639880++;
    func_001EE0B8(3, arg0, arg1, arg2, 0, 0, 0, 0);
    return soundRpcBuf;
}

void* func_001EE768(s32 arg0) {
    func_001EE0B8(19, arg0, 0, 0, 0, 0, 0, 0);
    return soundRpcBuf;
}

void* func_001EE7A8(s32 arg0, s32 arg1, s32 arg2) {
    func_001EE0B8(20, arg0, arg1, arg2, 0, 0, 0, 0);
    return soundRpcBuf;
}

void* func_001EE7F0(s32 arg0, s32 arg1, s32 arg2) {
    func_001EE0B8(21, arg0, arg1, arg2, 0, 0, 0, 0);
    return soundRpcBuf;
}

void* func_001EE838(s32 arg0, s32 arg1, s32 arg2) {
    D_00639880++;
    func_001EE0B8(40, arg0, arg1, arg2, 0, 0, 0, 0);
    return soundRpcBuf;
}

void* func_001EE890(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001EE0B8(42, arg0, arg1, arg2, arg3, 0, 0, 0);
    return soundRpcBuf;
}

void* func_001EE8E0(s32 arg0, s32 arg1) {
    func_001EE0B8(43, arg0, arg1, 0, 0, 0, 0, 0);
    return soundRpcBuf;
}

// Sends sound RPC command 22 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EE928(void) {
    sceSifCallRpc(&soundRpcClient, 22, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Sends sound RPC command 23 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EE980(void* arg0) {
    soundRpcBuf = arg0;
    sceSifCallRpc(&soundRpcClient, 23, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Sends sound RPC command 24 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EE9D8(void) {
    sceSifCallRpc(&soundRpcClient, 24, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Sends sound RPC command 25 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EEA30(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32* buf = (s32*)&soundRpcBuf;

    buf[0] = arg0;
    buf[1] = arg1;
    buf[2] = arg2;
    buf[3] = arg3;
    sceSifCallRpc(&soundRpcClient, 25, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Sends sound RPC command 27 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EEA98(void) {
    sceSifCallRpc(&soundRpcClient, 27, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Sends sound RPC command 29 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EEAF0(void* arg0) {
    soundRpcBuf = arg0;
    sceSifCallRpc(&soundRpcClient, 29, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Sends sound RPC command 50 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EEB48(s32 arg0, s32 arg1) {
    s32* buf = (s32*)&soundRpcBuf;

    buf[0] = arg0;
    buf[1] = arg1;
    sceSifCallRpc(&soundRpcClient, 50, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Sends sound RPC command 35 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EEBA8(void* arg0) {
    soundRpcBuf = arg0;
    sceSifCallRpc(&soundRpcClient, 35, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Sends sound RPC command 36 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EEC00(void* arg0) {
    soundRpcBuf = arg0;
    sceSifCallRpc(&soundRpcClient, 36, 0, &soundRpcBuf, 0x2000, &soundRpcBuf, 0x2000, NULL, NULL);
    return soundRpcBuf;
}

// Sends sound RPC command 30 (arguments in the shared buffer soundRpcBuf) and returns the buffer.
void* func_001EEC58(void) {
    s32 i, j;

    if (D_00635640[0][0] != -1) {
        sceSifCallRpc(&soundRpcClient, 30, 0, D_00635640, 0x2000, D_00635640, 0x2000, NULL, NULL);
        D_003E3CB0 = 0;
        for (i = 0; i < 0x400; i++) {
            for (j = 7; j >= 0; j--) {
                D_00635640[i][j] = -1;
            }
        }
    }
    return soundRpcBuf;
}
