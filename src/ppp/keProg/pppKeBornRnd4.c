#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd4", pppKeBornRnd4Calc);

typedef struct {
    /* 0x0 */ s16 unk_00;
} VKeBornRnd4;

void pppKeBornRnd4Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeBornRnd4*)&pobj->val[ctbl->useVal[0]])->unk_00 = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd4", func_0018F548);
