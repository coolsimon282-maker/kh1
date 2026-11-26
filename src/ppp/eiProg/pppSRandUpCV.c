#include "ppp.h"

typedef struct {
    pppCDT cdt;
    s32 index;
    s8 scale[4];
    u8 twice;
} PSRandUpCV;

NOTHROW_FN(s8 SRandCV_Scale(s8 a, f32 b));
NOTHROW_FN(f32 SRandCV_Rand(u8 twice));

void pppSRandUpCVCalc(pppPObject* pobj, PSRandUpCV* p, pppCtrlTable* ctbl) {
    f32* rv;
    u8* tgt;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->cdt.time != pobj->time) {
        return;
    }
    rv = (f32*)&pobj->val[ctbl->useVal[0]];
    rv[0] = SRandCV_Rand(p->twice);
    rv[1] = SRandCV_Rand(p->twice);
    rv[2] = SRandCV_Rand(p->twice);
    rv[3] = SRandCV_Rand(p->twice);
    if (p->index != -1) {
        tgt = (u8*)&pobj->val[p->index];
    } else {
        tgt = (u8*)&ppvDbgTemp;
    }
    tgt[0] += SRandCV_Scale(p->scale[0], rv[0]);
    tgt[1] += SRandCV_Scale(p->scale[1], rv[1]);
    tgt[2] += SRandCV_Scale(p->scale[2], rv[2]);
    tgt[3] += SRandCV_Scale(p->scale[3], rv[3]);
}

// a * b.
s8 SRandUpCV_Scale(s8 arg0, f32 arg1) {
    return arg0 * arg1;
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
f32 SRandUpCV_Rand(u8 twice) {
    f32 r = vu0Rand();
    r = -r;
    if (twice) {
        r = (r - vu0Rand()) * 0.5f;
    }
    return r;
}
