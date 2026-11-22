#include "ppp.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ pppFVECTOR vec;
    /* 0x10 */ f32 len;
    /* 0x14 */ f32 r;
    /* 0x18 */ f32 wv;
    /* 0x1C */ f32 wdv;
    /* 0x20 */ f32 wddv;
} PEiWindFun;

typedef struct {
    /* 0x00 */ pppFVECTOR vec;
    /* 0x0C */ f32 len;
    /* 0x10 */ f32 r;
    /* 0x14 */ f32 cosa;
    /* 0x18 */ f32 wv;
    /* 0x1C */ f32 wdv;
    /* 0x20 */ f32 wddv;
} VEiWindFun;

void pppEiWindFunCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VEiWindFun* v = (VEiWindFun*)&pobj->val[ctbl->useVal[0]];

    v->len = 0;
    v->r = 0;
    v->wv = v->wdv = v->wddv = 0;
}

// sqrt on VU0 (hand-written macro code)
static inline f32 vu0Sqrt(f32 x) {
    f32 r;
    __asm__ volatile("qmtc2.ni %1, $vf2
                     "
                     "vsqrt Q, $vf2x
                     "
                     "vwaitq
                     "
                     "vaddq.x $vf2, $vf0, Q
                     "
                     "qmfc2.ni %0, $vf2
                     "
                     : "=r"(r)
                     : "r"(x));
    return r;
}

void pppEiWindFunCalc(pppPObject* pobj, PEiWindFun* p, pppCtrlTable* ctbl) {
    VEiWindFun* v = (VEiWindFun*)&pobj->val[ctbl->useVal[0]];
    f32 len;
    f32 r;

    if (ppvUserStopPartF == 0 && !ppvMng->stop && ppvMng->unk_B4 == 0) {
        v->wdv += v->wddv;
        v->wv += v->wdv;
    }
    if (p->cdt.time == pobj->time) {
        v->vec = p->vec;
        len = v->len = p->len;
        r = v->r = p->r;
        v->cosa = len / vu0Sqrt(len * len + r * r);
        if (ppvUserStopPartF == 0 && !ppvMng->stop && ppvMng->unk_B4 == 0) {
            v->wv += p->wv;
            v->wdv += p->wdv;
            v->wddv += p->wddv;
        }
    }
}
