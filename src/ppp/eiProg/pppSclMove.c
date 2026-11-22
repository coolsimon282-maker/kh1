#include "ppp.h"

typedef struct {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} VSclMove;

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ f32 x;
    /* 0x8 */ f32 y;
    /* 0xC */ f32 z;
} PSclMove;

void pppSclMoveCalc(pppPObject* pobj, PSclMove* p, pppCtrlTable* ctbl) {
    VSclMove* scl = (VSclMove*)&pobj->val[ctbl->useVal[0]];
    VSclMove* spd = (VSclMove*)&pobj->val[ctbl->useVal[1]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->cdt.time == pobj->time) {
        spd->x += p->x;
        spd->y += p->y;
        spd->z += p->z;
    }
    scl->x += spd->x;
    scl->y += spd->y;
    scl->z += spd->z;
}

void pppSclMoveCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VSclMove* v = (VSclMove*)&pobj->val[ctbl->useVal[1]];

    v->x = v->y = v->z = 0.0f;
}
