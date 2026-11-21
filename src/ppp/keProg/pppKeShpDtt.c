#include "ppp.h"

void pppKeShpDttCalc(void) {
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpDtt", pppKeShpDttDraw);

typedef struct {
    /* 0x0 */ s64 unk_00;
    /* 0x8 */ s32 unk_08;
} VKeShpDtt;

void pppKeShpDttCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpDtt* v = (VKeShpDtt*)&pobj->val[ctbl->useVal[0]];

    v->unk_00 = 0;
    v->unk_08 = 0;
}
