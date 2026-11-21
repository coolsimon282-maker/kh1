#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeThHitBorn", pppKeThHitBornCalc);

void pppKeThHitBornCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    u8* v = (u8*)&pobj->val[ctbl->useVal[1]];

    *v = 0;
}
