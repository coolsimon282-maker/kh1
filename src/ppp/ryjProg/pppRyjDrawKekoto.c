#include "ppp.h"

extern void func_001A2F20(void*, void*);

void pppRyjDrawKekotoCalc(pppPObject* pobj, pppCDT* p, pppCtrlTable* ctbl) {
    void* v = &pobj->val[ctbl->useVal[2]];

    if (p->time == pobj->time) {
        func_001A2F20(p, v);
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawKekoto", pppRyjDrawKekotoDraw);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawKekoto", pppRyjDrawKekotoCon);
