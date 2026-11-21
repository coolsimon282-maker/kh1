#include "ppp.h"

typedef struct {
    /* 0x00 */ s32 unk_00[3];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u8 unk_10;
} VKeHitChkPxB;

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeHitChkPxB", pppKeHitChkPxBCalc);

void pppKeHitChkPxBCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeHitChkPxB* v = (VKeHitChkPxB*)&pobj->val[ctbl->useVal[2]];

    v->unk_0C = 1.0f;
    v->unk_10 = 0;
}
