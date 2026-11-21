#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeThTp", pppKeThTpCalc);

typedef struct {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ char unk_10[0xC];
    /* 0x1C */ s32 unk_1C;
} VKeThTp;

void pppKeThTpCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeThTp* v = (VKeThTp*)&pobj->val[ctbl->useVal[0]];

    v->unk_1C = 0;
    v->unk_0C = 0.0f;
}

void pppKeThTp2Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeThTp* v = (VKeThTp*)&pobj->val[ctbl->useVal[0]];

    v->unk_1C = 0;
    v->unk_0C = 1.0f;
}
