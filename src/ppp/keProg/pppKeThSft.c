#include "ppp.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ u16 col[16];
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ u8 unk_34;
} PKeThSft;

typedef struct {
    /* 0x00 */ u16 col[16];
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
} VKeThSftF;

typedef struct {
    /* 0x00 */ char pad_00[0xC];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ char pad_10[0x14];
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char pad_28[4];
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ char pad_30[0x10];
    /* 0x40 */ u8 unk_40;
} KeThSftSub;

typedef struct {
    /* 0x00 */ char pad_00[0x10];
    /* 0x10 */ KeThSftSub sub;
    /* 0x54 */ char pad_54[0x18];
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ u16 col[16];
} KeThSftW;

void pppKeThSftCalc(pppPObject* pobj, PKeThSft* p, pppCtrlTable* ctbl) {
    VKeThSftF* v;
    KeThSftW* w;
    KeThSftSub* sub;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    v = (VKeThSftF*)&pobj->val[ctbl->useVal[0]];
    w = (KeThSftW*)&pobj->val[ctbl->useVal[1]];
    sub = &w->sub;

    if (pobj->time == p->cdt.time) {
        w->sub.unk_40 = p->unk_34;
        v->unk_28 += p->unk_2C;
        v->unk_20 += p->unk_24;
        v->unk_24 += p->unk_28;
        v->unk_2C += p->unk_30;
        v->col[0] += p->col[0];
        v->col[1] += p->col[1];
        v->col[2] += p->col[2];
        v->col[3] += p->col[3];
        v->col[4] += p->col[4];
        v->col[5] += p->col[5];
        v->col[6] += p->col[6];
        v->col[7] += p->col[7];
        v->col[8] += p->col[8];
        v->col[9] += p->col[9];
        v->col[10] += p->col[10];
        v->col[11] += p->col[11];
        v->col[12] += p->col[12];
        v->col[13] += p->col[13];
        v->col[14] += p->col[14];
        v->col[15] += p->col[15];
        if (pobj->time == 0 && pobj->loop_in == 0) {
            return;
        }
    }

    w->unk_6C += v->unk_28;
    sub->unk_0C += v->unk_20;
    sub->unk_24 += v->unk_24;
    sub->unk_2C += v->unk_2C;
    w->col[0] += v->col[0];
    w->col[1] += v->col[1];
    w->col[2] += v->col[2];
    w->col[3] += v->col[3];
    w->col[4] += v->col[4];
    w->col[5] += v->col[5];
    w->col[6] += v->col[6];
    w->col[7] += v->col[7];
    w->col[8] += v->col[8];
    w->col[9] += v->col[9];
    w->col[10] += v->col[10];
    w->col[11] += v->col[11];
    w->col[12] += v->col[12];
    w->col[13] += v->col[13];
    w->col[14] += v->col[14];
    w->col[15] += v->col[15];
}

typedef struct {
    /* 0x00 */ u64 unk_00;
    /* 0x08 */ u64 unk_08;
    /* 0x10 */ u64 unk_10;
    /* 0x18 */ u64 unk_18;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
} VKeThSft;

void pppKeThSftCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeThSft* v = (VKeThSft*)&pobj->val[ctbl->useVal[0]];

    v->unk_28 = 0;
    v->unk_20 = 0;
    v->unk_24 = 0;
    v->unk_2C = 0;
    v->unk_00 = 0;
    v->unk_08 = 0;
    v->unk_10 = 0;
    v->unk_18 = 0;
}
