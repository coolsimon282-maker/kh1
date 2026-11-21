#include "ppp.h"

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
} VKeShpTailX;

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTailX", pppKeShpTailXCalc);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTailX", pppKeShpTailXDraw);

void pppKeShpTailXCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpTailX* v = (VKeShpTailX*)&pobj->val[ctbl->useVal[0]];

    v->unk0 = 0x1F;
    v->unk4 = 0;
    v->unk6 = 0;
    v->unk1 = 0;
    v->unk2 = 0;
}
