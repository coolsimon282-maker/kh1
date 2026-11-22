#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail2", pppKeShpTail2Calc);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail2", pppKeShpTail2Draw);

typedef struct {
    /* 0x0 */ u8 unk_0;
    /* 0x1 */ u8 unk_1;
    /* 0x2 */ s16 unk_2;
    /* 0x4 */ s16 unk_4;
    /* 0x6 */ s16 unk_6;
} VKeShpTail2;

void pppKeShpTail2Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpTail2* v = (VKeShpTail2*)&pobj->val[ctbl->useVal[0]];

    v->unk_0 = 0x1F;
    v->unk_4 = 0;
    v->unk_6 = 0;
    v->unk_1 = 0;
    v->unk_2 = 0;
}
