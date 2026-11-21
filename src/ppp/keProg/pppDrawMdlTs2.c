#include "ppp.h"

typedef struct {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
} VDrawMdlTs2;

void pppDrawMdlTs2Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VDrawMdlTs2* v = (VDrawMdlTs2*)&pobj->val[ctbl->useVal[2]];

    v->unk_00 = v->unk_04 = v->unk_08 = v->unk_0C = v->unk_10 = v->unk_14 = 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppDrawMdlTs2", pppDrawMdlTs2Calc);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppDrawMdlTs2", pppDrawMdlTs2Draw);
