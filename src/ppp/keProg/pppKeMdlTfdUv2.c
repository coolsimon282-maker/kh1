#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeMdlTfdUv2", pppKeMdlTfdUv2Draw);

void pppKeMdlTfdUv2Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    f32* v = (f32*)&pobj->val[ctbl->useVal[2]];

    v[0] = v[1] = v[2] = v[4] = v[5] = v[6] = v[7] = v[8] = v[9] = 0.0f;
}
