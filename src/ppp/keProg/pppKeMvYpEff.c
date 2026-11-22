#include "common.h"

#include "ppp.h"

s32 func_0018FE28(f32* v, f32* out);
f32 func_001AB380(f32 x); // square root

void pppKeMvYpEffCalc(pppPObject* pobj, void* p, pppCtrlTable* ctbl) {
    f32* vel;
    s32* ang;
    f32 y;
    f32 x;
    f32 t[4];
    f32 a;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    vel = (f32*)&pobj->val[ctbl->useVal[1]];
    y = vel[1];
    x = vel[0];
    if (y == 0.0f && x == 0.0f && vel[2] == 0.0f) {
        return;
    }
    ang = (s32*)&pobj->val[ctbl->useVal[0]];
    t[0] = -y;
    t[1] = x;
    if (func_0018FE28(t, &a)) {
        ang[2] = a * 32768.0f / 3.141592654;
    }
    t[0] = func_001AB380(y * y + x * x);
    t[1] = -vel[2];
    if (func_0018FE28(t, &a)) {
        ang[0] = a * 32768.0f / 3.141592654;
    }
}
