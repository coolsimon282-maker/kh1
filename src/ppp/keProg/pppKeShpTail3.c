#include "ppp.h"

typedef struct {
    /* 0x000 */ u64 unk_000[6];
    /* 0x030 */ char unk_030[0x1C0];
    /* 0x1F0 */ s32 unk_1F0;
    /* 0x1F4 */ s16 unk_1F4;
    /* 0x1F6 */ s16 unk_1F6;
    /* 0x1F8 */ s16 unk_1F8;
    /* 0x1FA */ u8 unk_1FA;
} VKeShpTail3;

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail3", pppKeShpTail3Calc);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail3", pppKeShpTail3Draw);

void pppKeShpTail3Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpTail3* v = (VKeShpTail3*)&pobj->val[ctbl->useVal[0]];

    v->unk_1FA = 0;
    v->unk_1F4 = 0;
    v->unk_1F0 = 0;
    v->unk_1F8 = rand();
    v->unk_000[0] = 0;
    v->unk_000[1] = 0;
    v->unk_000[2] = 0;
    v->unk_000[3] = 0;
    v->unk_000[4] = 0;
    v->unk_000[5] = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail3", pppKeShpTail3Con2);
