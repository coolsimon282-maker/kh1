#include "ppp.h"

NOTHROW_FN(void KeBornRnd6_BornLine(pppPObject* parent, s32* p, pppCtrlTable* ctbl));
s32 pppKeBornPtCmplCalc(pppPObject* pobj, s32* a1, pppCtrlTable* ctbl) {
    s32* p = a1;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p[2] != -1 && p[4] != -1) {
        KeBornRnd6_BornLine(pobj, a1, ctbl);
    }
}

typedef struct {
    /* 0x0 */ s32 unk_00;
} VKeBornPtCmpl;

void pppKeBornPtCmplCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeBornPtCmpl*)&pobj->val[ctbl->useVal[0]])->unk_00 = 0;
}

double atan(double);
// atan2 of (v[1], v[0]) written out with atan and quadrant fixes.
s32 KeBornPtCmpl_Atan2(f32* v, f32* out) {
    f32 x = v[0];
    f32 y = v[1];
    f32 r = x * y;

    if (r > 0.0f) {
        r = (x > 0.0f) ? 0.0f : -3.1415926f;
        r += atan(y / x);
    } else if (r < 0.0f) {
        r = (y > 0.0f) ? 1.5707963f : -1.5707963f;
        r -= atan(x / y);
    } else if (x != 0.0f) {
        r = (x > 0.0f) ? 0.0f : 3.1415926f;
    } else {
        if (y == 0.0f) {
            return 0;
        }
        r = -1.5707963f;
        if (y > 0.0f) {
            r = 1.5707963f;
        }
    }
    *out = r;
    return 1;
}
