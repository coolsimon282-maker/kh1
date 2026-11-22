#include "ppp/pppKeLns.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ f32 sft;
    /* 0x8 */ f32 pow;
} PKeLnsLpSft;

typedef union {
    f32 f;
    s32 i;
} FI;

void pppKeLnsLpSftCalc(pppPObject* pobj, PKeLnsLpSft* p, pppCtrlTable* ctbl) {
    FI* v;
    KeLnsLp* lp;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    v = (FI*)&pobj->val[ctbl->useVal[0]];
    lp = (KeLnsLp*)&pobj->val[ctbl->useVal[1]];
    if (pobj->time == p->cdt.time) {
        v[0].f += p->sft;
        v[1].f += p->pow;
        if (pobj->time == 0 && !pobj->loop_in) {
            return;
        }
    }
    lp->lVec[3] += v[0].f;
    lp->pow += v[1].f;
}

void pppKeLnsLpSftCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    s32* v = (s32*)&pobj->val[ctbl->useVal[0]];

    v[0] = 0;
    v[1] = 0;
}
