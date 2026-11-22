#include "ppp.h"

typedef struct {
    /* 0x00 */ u8 num;
    /* 0x01 */ u8 idx;
    /* 0x02 */ u16 cnt;
    /* 0x04 */ u16 seqIdx;
    /* 0x06 */ u16 prevSeq;
    /* 0x08 */ u8 pad08[8];
    /* 0x10 */ sceVu0FVECTOR pos[1];
} VKeShpTail2XCalc;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 shpIdx;
    /* 0x08 */ u16 speed;
    /* 0x0A */ u8 pad0A[0x1C];
    /* 0x26 */ u8 world;
} PKeShpTail2X;

typedef struct {
    /* 0x0 */ s16 unk_0;
    /* 0x2 */ s16 time;
    /* 0x4 */ s8 flag;
    /* 0x5 */ u8 unk_5[3];
} KeShpSeqX;

extern sceVu0FMATRIX D_00615E70;
void func_001AB0F0(void* dst, void* src);

// keeps a ring of the last num positions (the tail) and steps the shape animation
void pppKeShpTail2XCalc(pppPObject* pobj, PKeShpTail2X* p, pppCtrlTable* ctbl) {
    VKeShpTail2XCalc* v;
    u_long128* shape;
    pppShapeSt* shp;
    KeShpSeqX* seq;
    sceVu0FVECTOR t;
    sceVu0FVECTOR* vp;
    s32 n;
    s8 flag;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    v = (VKeShpTail2XCalc*)&pobj->val[ctbl->useVal[0]];
    if (pobj->time == 0 && pobj->loop_in == 0) {
        if (p->world) {
            sceVu0ApplyMatrix(t, D_00615E70, ppvPObj.next->cmat[3]);
            t[3] = 1.0f;
        } else {
            sceVu0CopyVector(t, ppvPObj.next->cmat[3]);
            t[3] = 1.0f;
        }
        vp = v->pos;
        for (n = v->num; n > 0; n--) {
            sceVu0CopyVector(*vp, t);
            vp++;
        }
    }
    if (v->idx == 0) {
        v->idx = v->num;
    }
    v->idx--;
    if (p->world) {
        sceVu0ApplyMatrix(v->pos[v->idx], D_00615E70, ppvPObj.next->cmat[3]);
        v->pos[v->idx][3] = 1.0f;
    } else {
        func_001AB0F0(v->pos[v->idx], ppvPObj.next->cmat[3]);
    }
    shp = &ppvEnv->lpShape[p->shpIdx];
    shape = shp->shape;
    seq = (KeShpSeqX*)(shape + 1) + v->seqIdx;
    v->prevSeq = v->seqIdx;
    v->cnt += p->speed;
    if (v->cnt >= seq->time) {
        v->cnt -= seq->time;
        v->seqIdx++;
        if (v->seqIdx >= ((s16*)shape)[3]) {
            flag = seq->flag;
            v->cnt = 0;
            if (flag & 0x80) {
                v->seqIdx = 0;
            } else {
                v->seqIdx--;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail2X", pppKeShpTail2XDraw);

typedef struct {
    /* 0x0 */ u8 unk_0;
    /* 0x1 */ u8 unk_1;
    /* 0x2 */ s16 unk_2;
    /* 0x4 */ s16 unk_4;
    /* 0x6 */ s16 unk_6;
} VKeShpTail2X;

void pppKeShpTail2XCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpTail2X* v = (VKeShpTail2X*)&pobj->val[ctbl->useVal[0]];

    v->unk_0 = 0x1F;
    v->unk_4 = 0;
    v->unk_6 = 0;
    v->unk_1 = 0;
    v->unk_2 = 0;
}
