#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd2", pppKeBornRnd2Calc);

typedef struct {
    /* 0x0 */ s16 unk_00;
} VKeBornRnd2;

void pppKeBornRnd2Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeBornRnd2*)&pobj->val[ctbl->useVal[0]])->unk_00 = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd2", func_0018EDD8);
