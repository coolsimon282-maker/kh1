#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppFVECTOR scl;
} PSclAccele;

typedef struct {
    /* 0x0 */ pppFVECTOR scl;
} VSclAccele;

void pppSclAcceleCalc(pppPObject* pobj, PSclAccele* p, pppCtrlTable* ctbl) {
    VSclAccele* ac0 = (VSclAccele*)&pobj->val[ctbl->useVal[0]];
    VSclAccele* ac1 = (VSclAccele*)&pobj->val[ctbl->useVal[1]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    if (p->cdt.time == pobj->time) {
        ac1->scl.x += p->scl.x;
        ac1->scl.y += p->scl.y;
        ac1->scl.z += p->scl.z;
    }
    ac0->scl.x += ac1->scl.x;
    ac0->scl.y += ac1->scl.y;
    ac0->scl.z += ac1->scl.z;
}

void pppSclAcceleCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VSclAccele* ac = (VSclAccele*)&pobj->val[ctbl->useVal[1]];

    ac->scl.x = ac->scl.y = ac->scl.z = 0.0f;
}
