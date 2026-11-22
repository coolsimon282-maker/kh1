#include "ppp.h"

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} VKeGrvTgt;

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ f32 x;
    /* 0x8 */ f32 y;
} PKeGrvTgt;

typedef union {
    f32 f;
    void* p;
} KeGrvTgtVal;

typedef struct {
    /* 0x0 */ KeGrvTgtVal x;
    /* 0x4 */ KeGrvTgtVal y;
    /* 0x8 */ void* target;
} VKeGrvTgtCalc;

void pppKeGrvTgtCalc(pppPObject* pobj, PKeGrvTgt* p, pppCtrlTable* ctbl) {
    if (pobj->time == p->cdt.time) {
        VKeGrvTgtCalc* v = (VKeGrvTgtCalc*)&pobj->val[ctbl->useVal[1]];

        v->x.f = p->x;
        v->y.f = p->y;
        v->target = &pobj->val[ctbl->useVal[0]];
    }
}

void pppKeGrvTgtCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeGrvTgt*)&pobj->val[ctbl->useVal[1]])->unk_08 = 0;
}
