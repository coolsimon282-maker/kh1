#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail2X", pppKeShpTail2XCalc);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail2X", pppKeShpTail2XDraw);

typedef struct {
    /* 0x0 */ u8 unk_0;
    /* 0x1 */ u8 unk_1;
    /* 0x2 */ s16 unk_2;
    /* 0x4 */ s16 unk_4;
    /* 0x6 */ s16 unk_6;
} VKeShpTail2X;

void pppKeShpTail2XCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpTail2X* v = (VKeShpTail2X*)&pobj->val[ctbl->useVal[0]];

    v->unk_0 = 0x1F;
    v->unk_4 = 0;
    v->unk_6 = 0;
    v->unk_1 = 0;
    v->unk_2 = 0;
}
