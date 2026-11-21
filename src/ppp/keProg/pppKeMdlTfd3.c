#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeMdlTfd3", pppKeMdlTfd3Draw);

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ s32 unk_4;
    /* 0x8 */ s32 unk_8;
} VKeMdlTfd3;

void pppKeMdlTfd3Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeMdlTfd3* v = (VKeMdlTfd3*)&pobj->val[ctbl->useVal[2]];

    v->unk_0 = 0;
    v->unk_4 = 0;
    v->unk_8 = 0;
}
