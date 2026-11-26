#include "ppp.h"

s32 func_0019FF38(void* arg0, void* arg1); // pppRyjMegaBirthPrize

void pppRyjMegaPlaceLampCalc(pppPObject* pobj, void* p, pppCtrlTable* ctbl) {
    u8* v1 = (u8*)&pobj->val[ctbl->useVal[1]];

    if (*v1 == 0) {
        if (func_0019FF38(&pobj->val[ctbl->useVal[0]], p)) {
            *v1 = 1;
        }
    }
}

typedef struct {
    /* 0x0 */ char unk_00[0x8];
    /* 0x8 */ s32 unk_08;
} VRyjMegaPlaceLamp;

void pppRyjMegaPlaceLampCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaPlaceLamp* v0 = (VRyjMegaPlaceLamp*)&pobj->val[ctbl->useVal[0]];
    u8* v1 = (u8*)&pobj->val[ctbl->useVal[1]];

    *v1 = 0;
    v0->unk_08++;
}

// VU0 random number 0..1.
f32 RyjMegaPlaceLamp_Rand(void) {
    f32 r;
    __asm__ volatile(
        "addi $8, $0, -1
"
        "qmtc2.ni $8, $vf2
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vitof0.x $vf2, $vf2
"
        "vadd.x $vf1, $vf1, $vf2
"
        "qmfc2.ni %0, $vf1
"
        : "=r"(r) : : "$8");
    return r;
}

// a * 2 * rand - a / 2 (after one discarded random number).
s8 RyjMegaPlaceLamp_RandSpread(u8 arg0) {
    RyjMegaPlaceLamp_Rand();
    return arg0 * 2 * RyjMegaPlaceLamp_Rand() - (arg0 >> 1);
}

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} RyjLampTex;

typedef struct {
    /* 0x000 */ char unk_000[0x101];
    /* 0x101 */ u8 unk_101;
    /* 0x102 */ char unk_102[0x4];
    /* 0x106 */ u8 unk_106;
} RyjLampData;

// True when the lamp texture data needed by the parameters is there.
s32 RyjMegaPlaceLamp_HasData(RyjLampTex* tex, RyjLampData* data) {
    if (tex->unk_10 == 0) {
        return 0;
    }
    if (data->unk_106 != 0 && tex->unk_14 == 0) {
        return 0;
    }
    if (data->unk_101 != 0 && tex->unk_18 == 0) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlaceLamp", func_001A0F58);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlaceLamp", func_001A1F28);

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ u8* unk_10;
    /* 0x14 */ u8* unk_14;
    /* 0x18 */ u8* unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ u16 unk_20;
} RyjLampWork;

typedef struct {
    /* 0x00 */ char unk_00[0x1E];
    /* 0x1E */ u16 unk_1E;
    /* 0x20 */ u16 unk_20;
} RyjLampArg;

NOTHROW(void, func_001A0F58);
NOTHROW(void, func_001A1F28);

void func_001A23F0(RyjLampWork* w, RyjLampArg* a, void* c) {
    u8* e = w->unk_10;
    u8* t = w->unk_14;
    u8* s = w->unk_18;
    s32 n = w->unk_1C;
    s32 cnt = 0;
    s32 i;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    w->unk_20++;
    for (i = 0; i < n; i++) {
        if (*(u16*)(e + 0x40) != 0) {
            func_001A1F28(w, a, e, c, s);
        } else if (a->unk_20 <= w->unk_20 && cnt < a->unk_1E) {
            func_001A0F58(w, a, c, e, t, s);
            cnt++;
        }
        if (t != NULL) {
            t += 0x40;
        }
        if (s != NULL) {
            s += 0x20;
        }
        e += 0xB0;
    }
    if (cnt > 0) {
        w->unk_20 = 0;
    }
}
