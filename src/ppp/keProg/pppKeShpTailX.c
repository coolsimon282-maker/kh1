#include "ppp.h"

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
} VKeShpTailX;

typedef struct {
    /* 0x00 */ u8 n;
    /* 0x01 */ u8 cur;
    /* 0x02 */ u16 wait;
    /* 0x04 */ u16 seq;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ char pad[8];
    /* 0x10 */ sceVu0FVECTOR pos[1];
} VKeShpTailXC;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 shapeNo;
    /* 0x08 */ u16 speed;
    /* 0x0A */ char pad[0x17];
    /* 0x21 */ u8 world;
} PKeShpTailX;

typedef struct {
    /* 0x0 */ s16 ofs;
    /* 0x2 */ s16 time;
    /* 0x4 */ s8 flag;
    /* 0x5 */ char pad[3];
} ShpTailXAnm;

extern sceVu0FMATRIX D_00615E70;
void func_001AB0F0(void* dst, void* src);

void pppKeShpTailXCalc(pppPObject* pobj, PKeShpTailX* p, pppCtrlTable* ctbl) {
    VKeShpTailXC* v;
    sceVu0FVECTOR tmp;
    s32 i;
    u8 cur;
    u8* shp;
    ShpTailXAnm* anm;
    pppShapeSt* lp;
    f32* d;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    v = (VKeShpTailXC*)&pobj->val[ctbl->useVal[0]];
    if (pobj->time == 0 && pobj->loop_in == 0) {
        if (p->world) {
            sceVu0ApplyMatrix(tmp, D_00615E70, ppvPObj.next->cmat[3]);
            tmp[3] = 1.0f;
        } else {
            sceVu0CopyVector(tmp, ppvPObj.next->cmat[3]);
            tmp[3] = 1.0f;
        }
        d = v->pos[0];
        for (i = v->n; i > 0; i--) {
            sceVu0CopyVector(d, tmp);
            d += 4;
        }
    }
    if (v->cur == 0) {
        v->cur = v->n;
    }
    v->cur--;
    if (p->world) {
        sceVu0ApplyMatrix(v->pos[v->cur], D_00615E70, ppvPObj.next->cmat[3]);
        v->pos[v->cur][3] = 1.0f;
    } else {
        func_001AB0F0(v->pos[v->cur], ppvPObj.next->cmat[3]);
    }
    lp = ppvEnv->lpShape;
    lp += p->shapeNo;
    shp = (u8*)lp->shape;
    anm = (ShpTailXAnm*)(shp + 0x10) + v->seq;
    v->unk6 = v->seq;
    v->wait += p->speed;
    if (v->wait >= anm->time) {
        v->wait -= anm->time;
        v->seq++;
        if (v->seq >= *(s16*)(shp + 6)) {
            if (anm->flag & 0x80) {
                v->seq = 0;
                v->wait = 0;
            } else {
                v->seq--;
                v->wait = 0;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTailX", pppKeShpTailXDraw);

void pppKeShpTailXCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpTailX* v = (VKeShpTailX*)&pobj->val[ctbl->useVal[0]];

    v->unk0 = 0x1F;
    v->unk4 = 0;
    v->unk6 = 0;
    v->unk1 = 0;
    v->unk2 = 0;
}
