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

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlaceLamp", func_001A0E60);

f32 func_001A0E60(void);

s8 func_001A0EA8(u8 arg0) {
    func_001A0E60();
    return arg0 * 2 * func_001A0E60() - (arg0 >> 1);
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

s32 func_001A0F10(RyjLampTex* tex, RyjLampData* data) {
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

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlaceLamp", func_001A23F0);
