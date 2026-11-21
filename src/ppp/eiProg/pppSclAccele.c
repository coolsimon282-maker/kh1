#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppSclAccele", pppSclAcceleCalc);

typedef struct {
    /* 0x0 */ pppFVECTOR scl;
} VSclAccele;

void pppSclAcceleCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VSclAccele* ac = (VSclAccele*)&pobj->val[ctbl->useVal[1]];

    ac->scl.x = ac->scl.y = ac->scl.z = 0.0f;
}
