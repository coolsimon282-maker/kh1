#include "ppp.h"

void pppSclMoveLoopCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    f32* v = (f32*)&pobj->val[ctbl->useVal[1]];

    v[0] = v[1] = v[2] = 0.0f;
}

void pppSclMoveLoopCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    pppSclMoveLoopCon(pobj, ctbl);
}

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ f32 x;
    /* 0x8 */ f32 y;
    /* 0xC */ f32 z;
} PSclMoveLoop;

void pppSclMoveLoopCalc(pppPObject* pobj, PSclMoveLoop* p, pppCtrlTable* ctbl) {
    f32* scl = (f32*)&pobj->val[ctbl->useVal[0]];
    f32* v = (f32*)&pobj->val[ctbl->useVal[1]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    if (p->cdt.time == pobj->time) {
        v[0] += p->x;
        v[1] += p->y;
        v[2] += p->z;
    }

    if (!ppvEmptyLoop) {
        scl[0] += v[0];
        scl[1] += v[1];
        scl[2] += v[2];
    }
}
