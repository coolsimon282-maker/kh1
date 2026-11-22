#include "ppp.h"

s32 D_006105A4;

typedef struct {
    /* 0x00 */ u32 unFrameCt;
    /* 0x04 */ u8 bSmp;
    /* 0x05 */ u8 bStandby;
    /* 0x06 */ char dummy0[2];
    /* 0x08 */ sceVu0FVECTOR* pvecSmp;
    /* 0x0C */ char dummy1[4];
    /* 0x10 */ f32 avecBonePos[2][4];
} VRyjDrawShipolyBone;

void pppRyjDrawShipolyBoneCalc(void) {
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipolyBone", func_0019D100);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipolyBone", pppRyjDrawShipolyBoneDraw);

void pppRyjDrawShipolyBoneCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawShipolyBone* p = (VRyjDrawShipolyBone*)&pobj->val[ctbl->useVal[1]];

    p->unFrameCt = 0;
    p->bSmp = 0;
    p->bStandby = 1;
    p->pvecSmp = NULL;
    ppvMng->unk_B3 = 1;
}

void pppRyjDrawShipolyBoneDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawShipolyBone* p = (VRyjDrawShipolyBone*)&pobj->val[ctbl->useVal[1]];

    if (p->pvecSmp != NULL) {
        pppFree(ppvEnv, p->pvecSmp);
        p->pvecSmp = NULL;
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipolyBone", func_0019D798);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipolyBone", func_0019D7E0);

typedef struct {
    /* 0x00 */ u8 unk_00[0x50];
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ s32 unk_58;
} RyjShipolyUnk1;

typedef struct {
    /* 0x00 */ u8 unk_00[0xC9];
    /* 0xC9 */ u8 unk_C9;
    /* 0xCA */ u8 unk_CA[2];
    /* 0xCC */ u8 unk_CC;
} RyjShipolyUnk2;

s32 func_0019D840(RyjShipolyUnk1* a, RyjShipolyUnk2* b) {
    if (a->unk_50 == 0) {
        return 0;
    }
    if ((b->unk_CC == 1 || b->unk_CC == 2) && a->unk_54 == 0) {
        return 0;
    }
    if (b->unk_C9 != 0 && a->unk_58 == 0) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipolyBone", func_0019D898);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipolyBone", func_0019E520);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipolyBone", func_0019E8B0);
