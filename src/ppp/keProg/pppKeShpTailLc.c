#include "ppp.h"

typedef struct {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8 unk_08;
} VKeShpTailLc;

void pppKeShpTailLcCalc(void) {
}

void pppKeShpTailLcDraw(void) {
}

void pppKeShpTailLcCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpTailLc* v = (VKeShpTailLc*)&pobj->val[ctbl->useVal[0]];

    v->unk_00 = 0x1F;
    v->unk_02 = 0;
    v->unk_04 = 0;
    v->unk_01 = 0;
    v->unk_08 = 0;
}
