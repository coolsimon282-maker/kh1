#include "ppp.h"

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

typedef struct {
    pppCDT cdt;
    s32 index;
    s16 scale[4];
    u8 twice;
} PRandDownHCV;

s16 func_0018A858(s16 a, f32 b);

void pppRandDownHCVCalc(pppPObject* pobj, PRandDownHCV* p, pppCtrlTable* ctbl) {
    f32* rv;
    u16* tgt;
    f32 r;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->cdt.time != pobj->time) {
        return;
    }
    r = vu0Rand();
    r = -r;
    if (p->twice) {
        r = (r - vu0Rand()) * 0.5f;
    }
    rv = (f32*)&pobj->val[ctbl->useVal[0]];
    *rv = r;
    if (p->index != -1) {
        tgt = (u16*)&pobj->val[p->index];
    } else {
        tgt = (u16*)&ppvDbgTemp;
    }
    tgt[0] += func_0018A858(p->scale[0], *rv);
    tgt[1] += func_0018A858(p->scale[1], *rv);
    tgt[2] += func_0018A858(p->scale[2], *rv);
    tgt[3] += func_0018A858(p->scale[3], *rv);
}



f32 func_0018AA30(f32 arg0, f32 arg1) {
    return arg0 * arg1 - arg0;
}

f32 func_0018AA40(u8 twice) {
    f32 r = vu0Rand();
    if (twice) {
        r += vu0Rand();
    } else {
        r += r;
    }
    return r;
}
