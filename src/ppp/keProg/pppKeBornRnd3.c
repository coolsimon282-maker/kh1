#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd3", pppKeBornRnd3Calc);

typedef struct {
    /* 0x0 */ s16 unk_0;
} VKeBornRnd3;

void pppKeBornRnd3Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeBornRnd3*)&pobj->val[ctbl->useVal[0]])->unk_0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd3", func_0018F000);
