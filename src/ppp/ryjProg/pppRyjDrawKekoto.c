#include "ppp.h"

extern void RyjMegaBirthModel_GetUv(void*, void*);

void pppRyjDrawKekotoCalc(pppPObject* pobj, pppCDT* p, pppCtrlTable* ctbl) {
    void* v = &pobj->val[ctbl->useVal[2]];

    if (p->time == pobj->time) {
        RyjMegaBirthModel_GetUv(p, v);
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawKekoto", pppRyjDrawKekotoDraw);

void pppRyjDrawKekotoCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    u_long128* v = (u_long128*)&pobj->val[ctbl->useVal[2]];
    s32 i;

    for (i = 7; i >= 0; i--) {
        v[i] = 0;
    }
}
