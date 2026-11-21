#include "ppp.h"

typedef struct {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
} VKeMdlTfdUv3;

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeMdlTfdUv3", pppKeMdlTfdUv3Draw);

void pppKeMdlTfdUv3Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeMdlTfdUv3* v = (VKeMdlTfdUv3*)&pobj->val[ctbl->useVal[2]];

    v->unk_00 = v->unk_04 = v->unk_08 = v->unk_10 = v->unk_14 = v->unk_18 = v->unk_1C = v->unk_20 = v->unk_24 = 0.0f;
}
