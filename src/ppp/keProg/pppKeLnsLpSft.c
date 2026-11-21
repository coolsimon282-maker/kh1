#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsLpSft", pppKeLnsLpSftCalc);

void pppKeLnsLpSftCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    s32* v = (s32*)&pobj->val[ctbl->useVal[0]];

    v[0] = 0;
    v[1] = 0;
}
