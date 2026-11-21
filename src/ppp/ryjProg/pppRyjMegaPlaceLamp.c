#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlaceLamp", pppRyjMegaPlaceLampCalc);

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

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlaceLamp", func_001A0EA8);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlaceLamp", func_001A0F10);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlaceLamp", func_001A0F58);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlaceLamp", func_001A1F28);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlaceLamp", func_001A23F0);
