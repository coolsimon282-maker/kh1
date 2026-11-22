#include "ppp.h"

typedef struct {
    pppCDT cdt;
    s32 index;
    f32 scale[3];
    u8 twice;
} PSRandFV;

f32 func_0018AA30(f32 a, f32 b);
f32 func_0018AA40(u8 twice);

void pppSRandFVCalc(pppPObject* pobj, PSRandFV* p, pppCtrlTable* ctbl) {
    f32* rv;
    f32* tgt;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (pobj->time == 0) {
        rv = (f32*)&pobj->val[ctbl->useVal[0]];
        rv[0] = func_0018AA40(p->twice);
        rv[1] = func_0018AA40(p->twice);
        rv[2] = func_0018AA40(p->twice);
    } else {
        if (p->cdt.time != pobj->time) {
            return;
        }
        rv = (f32*)&pobj->val[ctbl->useVal[0]];
    }
    if (p->index != -1) {
        tgt = (f32*)&pobj->val[p->index];
    } else {
        tgt = (f32*)&ppvDbgTemp;
    }
    tgt[0] += func_0018AA30(p->scale[0], rv[0]);
    tgt[1] += func_0018AA30(p->scale[1], rv[1]);
    tgt[2] += func_0018AA30(p->scale[2], rv[2]);
}

f32 func_0018AC08(f32 a, f32 b) {
    return a * b;
}

static inline f32 vu0Rand(void) {
    f32 r;
    __asm__ volatile(
        "addi $8, $0, -1
"
        "qmtc2.ni $8, $vf2
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vitof0.x $vf2, $vf2
"
        "vadd.x $vf1, $vf1, $vf2
"
        "qmfc2.ni %0, $vf1
"
        : "=r"(r) : : "$8");
    return r;
}

f32 func_0018AC10(u8 twice) {
    f32 r = vu0Rand();
    if (twice) {
        r = (r + vu0Rand()) * 0.5f;
    }
    return r;
}
