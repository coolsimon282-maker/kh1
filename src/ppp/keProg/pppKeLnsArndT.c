#include "ppp/pppKeLns.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsArndT", pppKeLnsArndTDraw);

void pppKeLnsArndTCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsArnd* arnd = (KeLnsArnd*)&pobj->val[ctbl->useVal[0]];

    KeLnsArnd_Init(arnd);
}

void pppKeLnsArndTDes(void) {
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsArndT", func_00194BD0);
