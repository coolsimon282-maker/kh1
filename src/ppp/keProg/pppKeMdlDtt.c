#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeMdlDtt", pppKeMdlDttDraw);

typedef struct {
    /* 0x0 */ u64 unk_0;
    /* 0x8 */ s32 unk_8;
} VKeMdlDtt;

void pppKeMdlDttCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeMdlDtt* v = (VKeMdlDtt*)&pobj->val[ctbl->useVal[0]];

    v->unk_0 = 0;
    v->unk_8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeMdlDtt", pppKeMdlDttCon2);
