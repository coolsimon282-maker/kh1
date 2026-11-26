#include "ppp.h"

typedef struct {
    pppCDT cdt;
    s32 index;
    s16 scale[4];
    u8 twice;
} PSRandHCV;

NOTHROW_FN(s8 SRandDownCV_Scale(s16 a, f32 b));
NOTHROW_FN(f32 SRandDownCV_Rand(u8 twice));

void pppSRandHCVCalc(pppPObject* pobj, PSRandHCV* p, pppCtrlTable* ctbl) {
    f32* rv;
    u16* tgt;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->cdt.time != pobj->time) {
        return;
    }
    rv = (f32*)&pobj->val[ctbl->useVal[0]];
    rv[0] = SRandDownCV_Rand(p->twice);
    rv[1] = SRandDownCV_Rand(p->twice);
    rv[2] = SRandDownCV_Rand(p->twice);
    rv[3] = SRandDownCV_Rand(p->twice);
    if (p->index != -1) {
        tgt = (u16*)&pobj->val[p->index];
    } else {
        tgt = (u16*)&ppvDbgTemp;
    }
    tgt[0] += SRandDownCV_Scale(p->scale[0], rv[0]);
    tgt[1] += SRandDownCV_Scale(p->scale[1], rv[1]);
    tgt[2] += SRandDownCV_Scale(p->scale[2], rv[2]);
    tgt[3] += SRandDownCV_Scale(p->scale[3], rv[3]);
}

// a * b.
s8 SRandHCV_Scale(s16 a, f32 b) {
    return a * b;
}

static inline f32 vu0Rand(void) {
    f32 r;
    __asm__ volatile(
        "addi $8, $0, -1\n"
        "qmtc2.ni $8, $vf2\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vitof0.x $vf2, $vf2\n"
        "vadd.x $vf1, $vf1, $vf2\n"
        "qmfc2.ni %0, $vf1\n"
        : "=r"(r) : : "$8");
    return r;
}

// VU0 random number 0..1, or the average of two (twice).
f32 SRandHCV_Rand(u8 twice) {
    f32 r = vu0Rand();

    if (twice) {
        r = (r + vu0Rand()) * 0.5f;
    }
    return r;
}

