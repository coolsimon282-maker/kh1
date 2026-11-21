#include "ppp/pppKeLns.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsClmT", pppKeLnsClmTDraw);

void pppKeLnsClmTCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsClm* clm = (KeLnsClm*)&pobj->val[ctbl->useVal[0]];

    KeLnsClm_Init(clm);
    clm->num = 4;
}

void pppKeLnsClmTDes(void) {
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsClmT", func_00194E58);
