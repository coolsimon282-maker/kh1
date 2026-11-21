#include "ppp.h"

typedef struct {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u8 unk_02;
} VKeBornRnd6;

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd6", pppKeBornRnd6Calc);

void pppKeBornRnd6Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeBornRnd6* v = (VKeBornRnd6*)&pobj->val[ctbl->useVal[0]];

    v->unk_00 = 0;
    v->unk_02 = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd6", func_0018FBB0);
