#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd", pppKeBornRndCalc);

void pppKeBornRndCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    *(s16*)&pobj->val[ctbl->useVal[0]] = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd", func_0018EB98);
