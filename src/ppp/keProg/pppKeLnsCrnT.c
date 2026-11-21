#include "ppp/pppKeLns.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsCrnT", pppKeLnsCrnTDraw);

void pppKeLnsCrnTCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsCrn* crn = (KeLnsCrn*)&pobj->val[ctbl->useVal[0]];

    KeLnsCrn_Init(crn);
}

void pppKeLnsCrnTDes(void) {
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsCrnT", func_00195148);
