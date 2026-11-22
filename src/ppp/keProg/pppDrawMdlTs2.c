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

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 add[6];
} PDrawMdlTs2;

void pppDrawMdlTs2Calc(pppPObject* pobj, PDrawMdlTs2* p, pppCtrlTable* ctbl) {
    VDrawMdlTs2* v = (VDrawMdlTs2*)&pobj->val[ctbl->useVal[2]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    v->unk_04 += v->unk_08;
    v->unk_10 += v->unk_14;
    v->unk_00 += v->unk_04;
    v->unk_0C += v->unk_10;
    if (p->cdt.time != pobj->time) {
        return;
    }
    v->unk_00 += p->add[0];
    v->unk_04 += p->add[1];
    v->unk_08 += p->add[2];
    v->unk_0C += p->add[3];
    v->unk_10 += p->add[4];
    v->unk_14 += p->add[5];
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppDrawMdlTs2", pppDrawMdlTs2Draw);
