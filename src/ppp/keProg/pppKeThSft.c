#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeThSft", pppKeThSftCalc);

typedef struct {
    /* 0x00 */ u64 unk_00;
    /* 0x08 */ u64 unk_08;
    /* 0x10 */ u64 unk_10;
    /* 0x18 */ u64 unk_18;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
} VKeThSft;

void pppKeThSftCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeThSft* v = (VKeThSft*)&pobj->val[ctbl->useVal[0]];

    v->unk_28 = 0;
    v->unk_20 = 0;
    v->unk_24 = 0;
    v->unk_2C = 0;
    v->unk_00 = 0;
    v->unk_08 = 0;
    v->unk_10 = 0;
    v->unk_18 = 0;
}
