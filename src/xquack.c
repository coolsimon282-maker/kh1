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

s32 D_003DE5B8;
sceSifClientData D_003DE5C0;

void* D_0062D980;
XDuck D_00639180[3];
s32 D_00639588;
s32 D_00639880;

extern s8 D_0063F640[256];

void func_001ED878(s32 arg0) {
    D_003DE5B8 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/xquack", func_001ED888);

void* func_001EDA60(void) {
    sceSifCallRpc(&D_003DE5C0, 31, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EDAB8(void) {
    sceSifCallRpc(&D_003DE5C0, 32, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EDB10(void) {
    sceSifCallRpc(&D_003DE5C0, 33, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EDB68(void) {
    sceSifCallRpc(&D_003DE5C0, 34, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

INCLUDE_ASM("asm/nonmatchings/xquack", func_001EDBC0);

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
        return D_0062D980;
    }
    return D_0062D980;
}

INCLUDE_ASM("asm/nonmatchings/xquack", func_001EDDC0);

void* func_001EDF28(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (!(D_003DE5B8 & 8)) {
        func_001EE0B8(41, arg0, arg1, arg2, arg3, 0, 0, 0);
        return D_0062D980;
    }
    return D_0062D980;
}

s32 func_001EDF88(s32 arg0) {
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

void* func_001EE188(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 1, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EE1E0(s32 arg0, s32 arg1) {
    func_001EE0B8(38, arg0, arg1, 0, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE228(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 39, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);

    return D_0062D980;
}

void* func_001EE280(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 15, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);

    return D_0062D980;
}

void* func_001EE2D8(s32 arg0, s32 arg1, s32 arg2) {
    D_00639880++;
    func_001EE0B8(4, arg0, arg1, arg2, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE330(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (!(D_003DE5B8 & 2)) {
        func_001EE0B8(5, arg0, arg1, arg2, arg3, arg4, 0, 0);
        return D_0062D980;
    }
    return D_0062D980;
}

void* func_001EE390(s32 arg0, s32 arg1, s32 arg2) {
    func_001EE0B8(6, arg0, arg1, arg2, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE3D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001EE0B8(2, arg0, arg1, arg2, arg3, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE428(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_001EE0B8(7, arg0, arg1, arg2, arg3, arg4, 0, 0);
    return D_0062D980;
}

void* func_001EE478(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_001EE0B8(8, arg0, arg1, arg2, arg3, arg4, 0, 0);
    return D_0062D980;
}

void* func_001EE4C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001EE0B8(9, arg0, arg1, arg2, arg3, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE518(s32 arg0, s32 arg1, s32 arg2) {
    D_00639880++;
    func_001EE0B8(11, arg0, arg1, arg2, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE570(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    if (!(D_003DE5B8 & 1)) {
        func_001EE0B8(12, arg0, arg1, arg2, arg3, arg4, arg5, 0);
        return D_0062D980;
    }
    return D_0062D980;
}

void* func_001EE5D8(s32 arg0) {
    func_001EE0B8(13, arg0, 0, 0, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE618(s32 arg0, s32 arg1, s32 arg2) {
    func_001EE0B8(14, arg0, arg1, arg2, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE660(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 47, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EE6B8(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 48, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EE710(s32 arg0, s32 arg1, s32 arg2) {
    D_00639880++;
    func_001EE0B8(3, arg0, arg1, arg2, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE768(s32 arg0) {
    func_001EE0B8(19, arg0, 0, 0, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE7A8(s32 arg0, s32 arg1, s32 arg2) {
    func_001EE0B8(20, arg0, arg1, arg2, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE7F0(s32 arg0, s32 arg1, s32 arg2) {
    func_001EE0B8(21, arg0, arg1, arg2, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE838(s32 arg0, s32 arg1, s32 arg2) {
    D_00639880++;
    func_001EE0B8(40, arg0, arg1, arg2, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE890(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001EE0B8(42, arg0, arg1, arg2, arg3, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE8E0(s32 arg0, s32 arg1) {
    func_001EE0B8(43, arg0, arg1, 0, 0, 0, 0, 0);
    return D_0062D980;
}

void* func_001EE928(void) {
    sceSifCallRpc(&D_003DE5C0, 22, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EE980(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 23, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EE9D8(void) {
    sceSifCallRpc(&D_003DE5C0, 24, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EEA30(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32* buf = (s32*)&D_0062D980;

    buf[0] = arg0;
    buf[1] = arg1;
    buf[2] = arg2;
    buf[3] = arg3;
    sceSifCallRpc(&D_003DE5C0, 25, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EEA98(void) {
    sceSifCallRpc(&D_003DE5C0, 27, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EEAF0(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 29, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EEB48(s32 arg0, s32 arg1) {
    s32* buf = (s32*)&D_0062D980;

    buf[0] = arg0;
    buf[1] = arg1;
    sceSifCallRpc(&D_003DE5C0, 50, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EEBA8(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 35, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EEC00(void* arg0) {
    D_0062D980 = arg0;
    sceSifCallRpc(&D_003DE5C0, 36, 0, &D_0062D980, 0x2000, &D_0062D980, 0x2000, NULL, NULL);
    return D_0062D980;
}

void* func_001EEC58(void) {
    s32 i, j;

    if (D_00635640[0][0] != -1) {
        sceSifCallRpc(&D_003DE5C0, 30, 0, D_00635640, 0x2000, D_00635640, 0x2000, NULL, NULL);
        D_003E3CB0 = 0;
        for (i = 0; i < 0x400; i++) {
            for (j = 7; j >= 0; j--) {
                D_00635640[i][j] = -1;
            }
        }
    }
    return D_0062D980;
}
