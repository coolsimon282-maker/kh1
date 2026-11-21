#include "ppp.h"

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} VKeMdlTfd2;

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeMdlTfd2", pppKeMdlTfd2Draw);

void pppKeMdlTfd2Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeMdlTfd2* v = (VKeMdlTfd2*)&pobj->val[ctbl->useVal[2]];

    v->unk_00 = 0;
    v->unk_04 = 0;
    v->unk_08 = 0;
}
