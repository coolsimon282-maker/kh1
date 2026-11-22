#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ f32 r;
} PKeHitBall;

typedef struct {
    /* 0x0 */ f32 r;
    /* 0x4 */ void* pos;
} VKeHitBall;

void pppKeHitBallCalc(pppPObject* pobj, PKeHitBall* p, pppCtrlTable* ctbl) {
    if (pobj->time == p->cdt.time) {
        VKeHitBall* v = (VKeHitBall*)&pobj->val[ctbl->useVal[1]];

        v->pos = &pobj->val[ctbl->useVal[0]];
        v->r = p->r;
    }
}

void pppKeHitBallCon(void) {
}
