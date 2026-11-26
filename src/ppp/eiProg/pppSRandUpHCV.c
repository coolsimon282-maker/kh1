#include "ppp.h"

typedef struct {
    pppCDT cdt;
    s32 index;
    s16 scale[4];
    u8 twice;
} PSRandUpHCV;

NOTHROW_FN(s8 SRandHCV_Scale(s16 a, f32 b));
NOTHROW_FN(f32 SRandHCV_Rand(u8 twice));

void pppSRandUpHCVCalc(pppPObject* pobj, PSRandUpHCV* p, pppCtrlTable* ctbl) {
    f32* rv;
    u16* tgt;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->cdt.time != pobj->time) {
        return;
    }
    rv = (f32*)&pobj->val[ctbl->useVal[0]];
    rv[0] = SRandHCV_Rand(p->twice);
    rv[1] = SRandHCV_Rand(p->twice);
    rv[2] = SRandHCV_Rand(p->twice);
    rv[3] = SRandHCV_Rand(p->twice);
    if (p->index != -1) {
        tgt = (u16*)&pobj->val[p->index];
    } else {
        tgt = (u16*)&ppvDbgTemp;
    }
    tgt[0] += SRandHCV_Scale(p->scale[0], rv[0]);
    tgt[1] += SRandHCV_Scale(p->scale[1], rv[1]);
    tgt[2] += SRandHCV_Scale(p->scale[2], rv[2]);
    tgt[3] += SRandHCV_Scale(p->scale[3], rv[3]);
}

// a * b.
s8 SRandUpHCV_Scale(s16 a, f32 b) {
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

// Negated VU0 random number, or the average of two negated ones (twice).
f32 SRandUpHCV_Rand(u8 twice) {
    f32 r = vu0Rand();

    r = -r;
    if (twice) {
        r = (r - vu0Rand()) * 0.5f;
    }
    return r;
}
