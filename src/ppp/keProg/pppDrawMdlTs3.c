#include "ppp.h"

void pppDrawMdlTs3Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    f32* v = (f32*)&pobj->val[ctbl->useVal[2]];

    v[0] = v[1] = v[2] = v[3] = v[4] = v[5] = 0.0f;
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 d[6];
} PDrawMdlTs3;

typedef union {
    f32 f;
    s32 i;
} FI;

void pppDrawMdlTs3Calc(pppPObject* pobj, PDrawMdlTs3* p, pppCtrlTable* ctbl) {
    FI* v = (FI*)&pobj->val[ctbl->useVal[2]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    v[1].f += v[2].f;
    v[0].f += v[1].f;
    v[4].f += v[5].f;
    v[3].f += v[4].f;

    if (p->cdt.time == pobj->time) {
        v[0].f += p->d[0];
        v[1].f += p->d[1];
        v[2].f += p->d[2];
        v[3].f += p->d[3];
        v[4].f += p->d[4];
        v[5].f += p->d[5];
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppDrawMdlTs3", pppDrawMdlTs3Draw);
