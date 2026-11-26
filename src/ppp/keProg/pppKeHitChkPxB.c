#include "ppp.h"

typedef struct {
    /* 0x00 */ s32 unk_00[3];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u8 unk_10;
} VKeHitChkPxB;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 pdtn;
    /* 0x08 */ s32 valOff;
    /* 0x0C */ u8 unk_0C;
} PKeHitChkPxB;

typedef struct {
    /* 0x0 */ f32 r;
    /* 0x4 */ f32* pos;
} KeHitBallV;

typedef struct {
    /* 0x00 */ sceVu0FVECTOR pos;
    /* 0x10 */ u8 flag;
    /* 0x14 */ KeHitBallV* ball;
} VKeHitChkPxBCalc;

typedef struct {
    /* 0x00 */ sceVu0FVECTOR org;
    /* 0x10 */ sceVu0FVECTOR dir;
    /* 0x20 */ f32 radius;
    /* 0x24 */ f32 t;
} KeRaySphere;

s32 op_ray_sphere(KeRaySphere* r);
void op_vec_sub_xyz(f32* a, f32* b, f32* c);

void pppKeHitChkPxBCalc(pppPObject* pobj, PKeHitChkPxB* p, pppCtrlTable* ctbl) {
    VKeHitChkPxBCalc* v = (VKeHitChkPxBCalc*)&pobj->val[ctbl->useVal[2]];
    KeRaySphere rs;
    sceVu0FVECTOR d;
    f32* vel;
    f32* pos;
    KeHitBallV* ball;

    if (v->flag & 1) {
        return;
    }
    if (pobj->time == p->cdt.time) {
        if (p->pdtn != -1) {
            v->ball = (KeHitBallV*)&((pppPDataVal*)ppvMng->unk_80)[p->pdtn].pobj->val[p->valOff];
        } else {
            v->ball = (KeHitBallV*)&ppvDbgTemp;
        }
        if (p->unk_0C) {
            v->flag |= 2;
        }
        if (pobj->time == 0 && pobj->loop_in == 0) {
            return;
        }
    }
    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    ball = v->ball;
    if (ball == (KeHitBallV*)&ppvDbgTemp) {
        return;
    }
    pos = (f32*)&pobj->val[ctbl->useVal[0]];
    vel = (f32*)&pobj->val[ctbl->useVal[1]];
    if (ball->r == 0.0f) {
        return;
    }
    rs.radius = ball->r;
    sceVu0SubVector(rs.org, pos, ball->pos);
    sceVu0CopyVector(rs.dir, vel);
    if (!op_ray_sphere(&rs)) {
        return;
    }
    if (rs.t < 0.0f) {
        return;
    }
    if (1.0f < rs.t) {
        return;
    }
    v->flag |= 1;
    sceVu0ScaleVector(d, rs.dir, rs.t);
    sceVu0AddVector(d, d, rs.org);
    sceVu0AddVector(v->pos, v->ball->pos, d);
    if (v->flag & 2) {
        op_vec_sub_xyz(vel, v->pos, pos);
        pobj->time = 0xFFFF0000;
    }
}

void pppKeHitChkPxBCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeHitChkPxB* v = (VKeHitChkPxB*)&pobj->val[ctbl->useVal[2]];

    v->unk_0C = 1.0f;
    v->unk_10 = 0;
}
