#include "ppp/pppKeLns.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsLpT", pppKeLnsLpTDraw);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsLpT", pppKeLnsLpTCon);

void pppKeLnsLpTCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsLp* lp = (KeLnsLp*)&pobj->val[ctbl->useVal[0]];

    lp->lVec[3] = 0;
    lp->pow = 0;
}

void pppKeLnsLpTDes(void) {
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsLpT", func_00194980);
