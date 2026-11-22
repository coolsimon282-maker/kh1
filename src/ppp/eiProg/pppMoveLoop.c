#include "ppp.h"

typedef struct {
    pppFVECTOR vec;
} VMoveLoop;

void pppMoveLoopCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VMoveLoop* v = (VMoveLoop*)&pobj->val[ctbl->useVal[1]];

    v->vec.x = v->vec.y = v->vec.z = 0.0f;
}

void pppMoveLoopCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    pppMoveLoopCon(pobj, ctbl);
}

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppFVECTOR vec;
} PMoveLoop;

void pppMoveLoopCalc(pppPObject* pobj, PMoveLoop* p, pppCtrlTable* ctbl) {
    VMoveLoop* mv0 = (VMoveLoop*)&pobj->val[ctbl->useVal[0]];
    VMoveLoop* mv1 = (VMoveLoop*)&pobj->val[ctbl->useVal[1]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    if (p->cdt.time == pobj->time) {
        mv1->vec.x += p->vec.x;
        mv1->vec.y += p->vec.y;
        mv1->vec.z += p->vec.z;
    }

    if (!ppvEmptyLoop) {
        mv0->vec.x += mv1->vec.x;
        mv0->vec.y += mv1->vec.y;
        mv0->vec.z += mv1->vec.z;
    }
}
