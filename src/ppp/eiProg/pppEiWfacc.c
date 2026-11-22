#include "ppp.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ pppParamPObj wind;
    /* 0x0C */ pppParamPObj pos;
    /* 0x14 */ f32 mass;
} PEiWfacc;

typedef struct {
    /* 0x00 */ f32 vec[3];
    /* 0x0C */ f32 len;
    /* 0x10 */ f32 r;
    /* 0x14 */ f32 cosa;
    /* 0x18 */ f32 wv;
} WfaccWind;

f32 sceVu0InnerProduct(f32* a, f32* b);

// v.xyz = normalize(v.xyz) on VU0, returns the old length (hand-written macro code)
static inline f32 vu0NormalizeLen(f32* v) {
    f32 len;
    __asm__ volatile(
        "lqc2 $vf10, 0(%1)\n"
        "vadd.xyz $vf8, $vf0, $vf10\n"
        "vmul.xyz $vf10, $vf10, $vf10\n"
        "vmove.xyz $vf9, $vf10\n"
        "vaddx.y $vf9, $vf9, $vf9x\n"
        "vaddy.z $vf9, $vf9, $vf9y\n"
        "vsqrt Q, $vf9z\n"
        "vwaitq\n"
        "vaddq.x $vf10, $vf0, Q\n"
        "qmfc2.ni %0, $vf10\n"
        "vdiv Q, $vf0w, $vf10x\n"
        "vwaitq\n"
        "vmulq.xyz $vf9, $vf8, Q\n"
        "sqc2 $vf9, 0(%1)\n"
        : "=r"(len) : "r"(v) : "memory");
    return len;
}

void pppEiWfaccCalc(pppPObject* pobj, PEiWfacc* p, pppCtrlTable* ctbl) {
    f32* pos = (f32*)&pobj->val[ctbl->useVal[0]];
    WfaccWind* wind;
    f32* tpos;
    f32* vel;
    f32 d[4] __attribute__((aligned(16)));
    f32 len;
    f32 dot;
    f32 f;

    if (p->wind.pdtn != -1) {
        wind = (WfaccWind*)&((pppPDataVal*)ppvMng->unk_80)[p->wind.pdtn].pobj->val[p->wind.valoff];
    } else {
        wind = (WfaccWind*)&ppvDbgTemp;
    }
    if (p->pos.pdtn != -1) {
        tpos = (f32*)&((pppPDataVal*)ppvMng->unk_80)[p->pos.pdtn].pobj->val[p->pos.valoff];
    } else {
        tpos = (f32*)&ppvDbgTemp;
    }
    d[0] = pos[0] - tpos[0];
    d[1] = pos[1] - tpos[1];
    d[2] = pos[2] - tpos[2];
    len = vu0NormalizeLen(d);
    if (len < wind->len) {
        dot = sceVu0InnerProduct(wind->vec, d);
        if (wind->cosa < dot) {
            f = wind->wv * ((dot - wind->cosa) / (1.0f - wind->cosa)) * ((wind->len - len) / wind->len) / p->mass;
            vel = (f32*)&pobj->val[ctbl->useVal[1]];
            vel[0] += d[0] * f;
            vel[1] += d[1] * f;
            vel[2] += d[2] * f;
        }
    }
}
