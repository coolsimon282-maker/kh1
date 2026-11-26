#include "ppp.h"

typedef struct {
    pppCDT cdt;
    s32 index;
    s8 scale[4];
    u8 twice;
} PSRandCV;

NOTHROW_FN(s8 SRandDownFV_Scale(s8 a, f32 b));
NOTHROW_FN(f32 SRandDownFV_Rand(u8 twice));

void pppSRandCVCalc(pppPObject* pobj, PSRandCV* p, pppCtrlTable* ctbl) {
    f32* rv;
    u8* tgt;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->cdt.time != pobj->time) {
        return;
    }
    rv = (f32*)&pobj->val[ctbl->useVal[0]];
    rv[0] = SRandDownFV_Rand(p->twice);
    rv[1] = SRandDownFV_Rand(p->twice);
    rv[2] = SRandDownFV_Rand(p->twice);
    rv[3] = SRandDownFV_Rand(p->twice);
    if (p->index != -1) {
        tgt = (u8*)&pobj->val[p->index];
    } else {
        tgt = (u8*)&ppvDbgTemp;
    }
    tgt[0] += SRandDownFV_Scale(p->scale[0], rv[0]);
    tgt[1] += SRandDownFV_Scale(p->scale[1], rv[1]);
    tgt[2] += SRandDownFV_Scale(p->scale[2], rv[2]);
    tgt[3] += SRandDownFV_Scale(p->scale[3], rv[3]);
}

// a * b.
s8 SRandCV_Scale(s8 a, f32 b) {
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

// VU0 random number 0..1, or the average of two (twice).
f32 SRandCV_Rand(u8 twice) {
    f32 r = vu0Rand();
    if (twice) {
        r = (r + vu0Rand()) * 0.5f;
    }
    return r;
}
