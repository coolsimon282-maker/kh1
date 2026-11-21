#include "ppp.h"

void pppDrawMdlTs3Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    f32* v = (f32*)&pobj->val[ctbl->useVal[2]];

    v[0] = v[1] = v[2] = v[3] = v[4] = v[5] = 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppDrawMdlTs3", pppDrawMdlTs3Calc);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppDrawMdlTs3", pppDrawMdlTs3Draw);
