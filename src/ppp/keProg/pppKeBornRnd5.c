#include "common.h"

#include "ppp.h"

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ u8 unk2;
} VKeBornRnd5;

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd5", pppKeBornRnd5Calc);

void pppKeBornRnd5Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeBornRnd5* v = (VKeBornRnd5*)&pobj->val[ctbl->useVal[0]];

    v->unk0 = 0;
    v->unk2 = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd5", func_0018F780);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd5", func_0018F910);

INCLUDE_RODATA("asm/nonmatchings/ppp/keProg/pppKeBornRnd5", D_00489808);

INCLUDE_RODATA("asm/nonmatchings/ppp/keProg/pppKeBornRnd5", D_00489810);
