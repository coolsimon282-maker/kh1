#include "ppp.h"

typedef struct {
    /* 0x00 */ u64 unk_00;
    /* 0x08 */ u64 unk_08;
    /* 0x10 */ u64 unk_10;
    /* 0x18 */ u64 unk_18;
    /* 0x20 */ u64 unk_20;
    /* 0x28 */ u64 unk_28;
} VKeShpTail3X;

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail3X", pppKeShpTail3XCalc);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail3X", pppKeShpTail3XDraw);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail3X", pppKeShpTail3XCon);

void pppKeShpTail3XCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpTail3X* v = (VKeShpTail3X*)&pobj->val[ctbl->useVal[0]];

    v->unk_00 = 0;
    v->unk_08 = 0;
    v->unk_10 = 0;
    v->unk_18 = 0;
    v->unk_20 = 0;
    v->unk_28 = 0;
}
