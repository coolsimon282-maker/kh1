#include "ppp.h"

typedef struct {
    /* 0x00 */ u64 unk_00;
    /* 0x08 */ u64 unk_08;
    /* 0x10 */ u64 unk_10;
    /* 0x18 */ u64 unk_18;
    /* 0x20 */ u64 unk_20;
    /* 0x28 */ u64 unk_28;
} VKeShpTail3X;

typedef struct {
    /* 0x000 */ VKeShpTail3X head;
    /* 0x030 */ u8 unk_30[0x1C0];
    /* 0x1F0 */ s32 unk_1F0;
    /* 0x1F4 */ s16 unk_1F4;
    /* 0x1F6 */ s16 unk_1F6;
    /* 0x1F8 */ s16 unk_1F8;
    /* 0x1FA */ u8 unk_1FA;
} VKeShpTail3XFull;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ char pad_04[0x1C];
    /* 0x20 */ u16 init[24];
    /* 0x50 */ char pad_50[3];
    /* 0x53 */ u8 unk_53;
} PKeShpTail3X;

typedef struct {
    /* 0x000 */ u16 w[24];
    /* 0x030 */ sceVu0FVECTOR hist[28];
    /* 0x1F0 */ s32 unk_1F0;
    /* 0x1F4 */ s16 unk_1F4;
    /* 0x1F6 */ s16 unk_1F6;
    /* 0x1F8 */ s16 unk_1F8;
    /* 0x1FA */ u8 unk_1FA;
} VKeShpTail3XW;

extern sceVu0FMATRIX D_00615E70;

void pppKeShpTail3XCalc(pppPObject* pobj, PKeShpTail3X* p, pppCtrlTable* ctbl) {
    VKeShpTail3XW* v;
    sceVu0FVECTOR t;
    s32 i;
    sceVu0FVECTOR* pv;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    v = (VKeShpTail3XW*)&pobj->val[ctbl->useVal[0]];
    if (pobj->time == 0 && pobj->loop_in == 0) {
        if (p->unk_53) {
            sceVu0ApplyMatrix(t, D_00615E70, ppvPObj.next->cmat[3]);
            t[3] = 1.0f;
        } else {
            sceVu0CopyVector(t, ppvPObj.next->cmat[3]);
            t[3] = 1.0f;
        }
        pv = v->hist;
        for (i = 28; i > 0; i--) {
            sceVu0CopyVector(*pv, t);
            pv++;
        }
    }
    if (v->unk_1FA == 0) {
        v->unk_1FA = 28;
    }
    v->unk_1FA--;
    if (p->unk_53) {
        sceVu0ApplyMatrix(v->hist[v->unk_1FA], D_00615E70, ppvPObj.next->cmat[3]);
        v->hist[v->unk_1FA][3] = 1.0f;
    } else {
        sceVu0CopyVector(v->hist[v->unk_1FA], ppvPObj.next->cmat[3]);
    }
    v->w[8] += v->w[12];
    v->w[0] += v->w[8];
    v->w[9] += v->w[13];
    v->w[1] += v->w[9];
    v->w[10] += v->w[14];
    v->w[2] += v->w[10];
    v->w[11] += v->w[15];
    v->w[3] += v->w[11];
    v->w[16] += v->w[20];
    v->w[4] += v->w[16];
    v->w[17] += v->w[21];
    v->w[5] += v->w[17];
    v->w[18] += v->w[22];
    v->w[6] += v->w[18];
    v->w[19] += v->w[23];
    v->w[7] += v->w[19];
    if (pobj->time != p->cdt.time) {
        return;
    }
    v->w[0] += p->init[0];
    v->w[1] += p->init[1];
    v->w[2] += p->init[2];
    v->w[3] += p->init[3];
    v->w[8] += p->init[8];
    v->w[9] += p->init[9];
    v->w[10] += p->init[10];
    v->w[11] += p->init[11];
    v->w[12] += p->init[12];
    v->w[13] += p->init[13];
    v->w[14] += p->init[14];
    v->w[15] += p->init[15];
    v->w[4] += p->init[4];
    v->w[5] += p->init[5];
    v->w[6] += p->init[6];
    v->w[7] += p->init[7];
    v->w[16] += p->init[16];
    v->w[17] += p->init[17];
    v->w[18] += p->init[18];
    v->w[19] += p->init[19];
    v->w[20] += p->init[20];
    v->w[21] += p->init[21];
    v->w[22] += p->init[22];
    v->w[23] += p->init[23];
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeShpTail3X", pppKeShpTail3XDraw);

void pppKeShpTail3XCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpTail3XFull* v = (VKeShpTail3XFull*)&pobj->val[ctbl->useVal[0]];

    v->unk_1FA = 0;
    v->unk_1F4 = 0;
    v->unk_1F0 = 0;
    v->unk_1F8 = rand();
    v->head.unk_00 = 0;
    v->head.unk_08 = 0;
    v->head.unk_10 = 0;
    v->head.unk_18 = 0;
    v->head.unk_20 = 0;
    v->head.unk_28 = 0;
}

void pppKeShpTail3XCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpTail3X* v = (VKeShpTail3X*)&pobj->val[ctbl->useVal[0]];

    v->unk_00 = 0;
    v->unk_08 = 0;
    v->unk_10 = 0;
    v->unk_18 = 0;
    v->unk_20 = 0;
    v->unk_28 = 0;
}
