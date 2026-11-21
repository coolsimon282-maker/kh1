#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeMatSN", pppKeMatSNCalc);

typedef struct {
    /* 0x00 */ char unk_00[0x80];
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ s32 unk_84;
    /* 0x88 */ s32 unk_88;
} VKeMatSN;

void pppKeMatSNCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeMatSN* v = (VKeMatSN*)&pobj->val[ctbl->useVal[0]];

    v->unk_80 = 0;
    v->unk_84 = 0;
    v->unk_88 = 0;
}
