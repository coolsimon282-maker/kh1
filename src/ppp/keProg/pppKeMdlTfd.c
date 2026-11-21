#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeMdlTfd", pppKeMdlTfdDraw);

void pppKeMdlTfdCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    s32* v = (s32*)&pobj->val[ctbl->useVal[2]];

    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
}
