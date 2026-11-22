#include "ppp.h"

typedef struct {
    /* 0x00 */ u64 unk_00;
    /* 0x08 */ u64 unk_08;
    /* 0x10 */ u64 unk_10;
    /* 0x18 */ u64 unk_18;
    /* 0x20 */ u64 unk_20;
    /* 0x28 */ u64 unk_28;
} VKeShpTail3X;

typedef struct {
    /* 0x000 */ VKeShpTail3X head;
    /* 0x030 */ u8 unk_30[0x1C0];
    /* 0x1F0 */ s32 unk_1F0;
    /* 0x1F4 */ s16 unk_1F4;
    /* 0x1F6 */ s16 unk_1F6;
    /* 0x1F8 */ s16 unk_1F8;
    /* 0x1FA */ u8 unk_1FA;
} VKeShpTail3XFull;

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail3X", pppKeShpTail3XCalc);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail3X", pppKeShpTail3XDraw);

void pppKeShpTail3XCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpTail3XFull* v = (VKeShpTail3XFull*)&pobj->val[ctbl->useVal[0]];

    v->unk_1FA = 0;
    v->unk_1F4 = 0;
    v->unk_1F0 = 0;
    v->unk_1F8 = rand();
    v->head.unk_00 = 0;
    v->head.unk_08 = 0;
    v->head.unk_10 = 0;
    v->head.unk_18 = 0;
    v->head.unk_20 = 0;
    v->head.unk_28 = 0;
}

void pppKeShpTail3XCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpTail3X* v = (VKeShpTail3X*)&pobj->val[ctbl->useVal[0]];

    v->unk_00 = 0;
    v->unk_08 = 0;
    v->unk_10 = 0;
    v->unk_18 = 0;
    v->unk_20 = 0;
    v->unk_28 = 0;
}
