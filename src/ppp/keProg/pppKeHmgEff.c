#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ f32 rate;
    /* 0x8 */ pppParamPObj target;
} PKeHmgEff;

typedef struct {
    /* 0x0 */ f32 rate;
    /* 0x4 */ f32* target;
} VKeHmgEff;

f32 op_vec_length_sq(f32* v);
void op_vec_copy_xyz(f32* dst, f32* src);
s32 op_rand16(void);

void pppKeHmgEffCalc(pppPObject* pobj, PKeHmgEff* p, pppCtrlTable* ctbl) {
    VKeHmgEff* v = (VKeHmgEff*)&pobj->val[ctbl->useVal[2]];
    f32* pos;
    f32* vel;
    f32 dir[4] __attribute__((aligned(16)));
    f32 sum[4] __attribute__((aligned(16)));
    f32 vdir[4] __attribute__((aligned(16)));
    f32 len;

    if (pobj->time == p->cdt.time) {
        v->rate = p->rate;
        if (p->target.pdtn != -1) {
            v->target = (f32*)&((pppPDataVal*)ppvMng->unk_80)[p->target.pdtn].pobj->val[p->target.valoff];
        } else {
            v->target = (f32*)&ppvDbgTemp;
        }
        if (pobj->time == 0 && !pobj->loop_in) {
            return;
        }
    }
    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (v->target == (f32*)&ppvDbgTemp) {
        return;
    }
    pos = (f32*)&pobj->val[ctbl->useVal[0]];
    vel = (f32*)&pobj->val[ctbl->useVal[1]];
    sceVu0SubVector(dir, v->target, pos);
    sceVu0Normalize(dir, dir);
    sceVu0CopyVector(vdir, vel);
    len = op_vec_length_sq(vdir);
    sceVu0Normalize(vdir, vdir);
    sceVu0AddVector(sum, vdir, dir);
    if (*(u64*)&sum[0] == 0 && *(u64*)&sum[2] == 0) {
        dir[op_rand16() % 3] += 0.05f;
    }
    sceVu0InterVector(dir, dir, vdir, v->rate);
    sceVu0Normalize(dir, dir);
    sceVu0ScaleVector(dir, dir, len);
    op_vec_copy_xyz(vel, dir);
}

void pppKeHmgEffCon(void) {
}
