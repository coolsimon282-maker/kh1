#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppParamPObj target;
} PKeGrvEff;

typedef struct {
    /* 0x00 */ f32 radius;
    /* 0x04 */ f32 power;
    /* 0x08 */ f32* pos;
} KeGrvTarget;

// FM's ppp code behaves as if built without strict aliasing (the store to target makes the compiler reload
// pobj->time and ctbl->useVal); a union member gives the same alias-everything access.
typedef union {
    /* 0x0 */ KeGrvTarget* target;
} VKeGrvEff;

f32 op_vec_length_sq(f32* v);
void op_vec_add_xyz(f32* dst, f32* a, f32* b);

void pppKeGrvEffCalc(pppPObject* pobj, PKeGrvEff* p, pppCtrlTable* ctbl) {
    VKeGrvEff* v = (VKeGrvEff*)&pobj->val[ctbl->useVal[2]];
    KeGrvTarget* t;
    f32* vel;
    f32 d[4] __attribute__((aligned(16)));
    f32 len;

    if (pobj->time == p->cdt.time) {
        if (p->target.pdtn != -1) {
            v->target = (KeGrvTarget*)&((pppPDataVal*)ppvMng->unk_80)[p->target.pdtn].pobj->val[p->target.valoff];
        } else {
            v->target = (KeGrvTarget*)&ppvDbgTemp;
        }
        if (pobj->time == 0 && !pobj->loop_in) {
            return;
        }
    }
    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    t = v->target;
    if (t == (KeGrvTarget*)&ppvDbgTemp) {
        return;
    }
    vel = (f32*)&pobj->val[ctbl->useVal[1]];
    sceVu0SubVector(d, t->pos, (f32*)&pobj->val[ctbl->useVal[0]]);
    len = op_vec_length_sq(d);
    sceVu0Normalize(d, d);
    if (len < t->radius) {
        sceVu0ScaleVector(d, d, (1.0f - len / t->radius) * t->power);
        op_vec_add_xyz(vel, vel, d);
    }
}

void pppKeGrvEffCon(void) {
}
