#include "ppp.h"

void KeLnsFls_Init(void*);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsFlsT", pppKeLnsFlsTDraw);

void pppKeLnsFlsTCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    void* fls = &pobj->val[ctbl->useVal[0]];

    KeLnsFls_Init(fls);
}

void pppKeLnsFlsTDes(void) {
}
