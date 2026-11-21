#include "ppp.h"

void pppVertexApAtCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    s16* v = (s16*)&pobj->val[ctbl->useVal[0]];

    v[0] = 0;
    v[1] = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppVertexApAt", func_00186640);

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppVertexApAt", pppVertexApAtCalc);
