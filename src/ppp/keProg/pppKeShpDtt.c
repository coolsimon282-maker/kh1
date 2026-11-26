#include "ppp.h"

void pppKeShpDttCalc(void) {
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ u8 unk_18;
    /* 0x19 */ u8 unk_19;
} PKeShpDtt;

typedef struct {
    /* 0x00 */ sceVu0FVECTOR pos;
    /* 0x10 */ sceVu0FVECTOR col;
    /* 0x20 */ sceVu0FMATRIX* m20;
    /* 0x24 */ u32 pkt;
    /* 0x28 */ sceVu0FMATRIX* m28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ sceVu0FVECTOR v30;
    /* 0x40 */ u64 tag40;
    /* 0x48 */ u64 tag48;
    /* 0x50 */ u64 tag50;
    /* 0x58 */ f32 sx;
    /* 0x5C */ f32 sy;
} KeShpDttDraw;

extern s32 D_00616224;
extern s32 ppvCurPrimpLen;
void func_001ABA80(KeShpDttDraw*);
s32 func_001ABCC8(KeShpDttDraw*);
void op_ot_insert0(u32* p, s32 qwc, s32 pri, s32 arg3);
void op_ot_insert2(u32* p, s32 qwc, s32 pri, s32 arg3);

void pppKeShpDttDraw(pppPObject* pobj, PKeShpDtt* p, pppCtrlTable* ctbl) {
    KeShpDttDraw d;
    sceVu0FVECTOR* m = (sceVu0FVECTOR*)&pobj->val[ctbl->useVal[2]];
    f32* v = (f32*)&pobj->val[ctbl->useVal[0]];
    u8* c;
    ppvmng** pm = &ppvMng;
    f32* q;

    if (ppvUserStopPartF == 0 && !(*pm)->stop && (*pm)->unk_B4 == 0) {
        v[1] += v[2];
        v[0] += v[1];
        if (pobj->time == p->cdt.time) {
            v[0] += p->unk_04;
            v[1] += p->unk_08;
            v[2] += p->unk_0C;
        }
    }

    c = (u8*)&pobj->val[ctbl->useVal[1]];
    d.col[0] = c[8];
    d.col[1] = c[9];
    d.col[2] = c[10];
    d.col[3] = c[11];
    if (p->unk_19 & 2) {
        q = (f32*)&pobj->val[ctbl->useVal[3]];
        d.pos[0] = q[0];
        d.pos[1] = q[1];
        d.pos[2] = 512.0f;
        d.pos[3] = 1.0f;
        d.m28 = &ppvScreenMatrix;
    } else {
        *(u_long128*)d.pos = *(u_long128*)m[3];
        d.m28 = &ppvScreenMatrix;
    }
    d.sx = p->unk_10 * ppvParScl[0];
    d.sy = p->unk_14 * ppvParScl[1];
    d.m20 = &ppvScreenMatrix;
    d.pkt = D_00616224 + 0x10;
    if (p->unk_18 == 0) {
        d.tag40 = 0x2A8021A00;
        d.tag50 = 0x740000007000;
    } else {
        d.tag40 = 0x2A8020000;
        d.tag50 = 0x720000007000;
    }
    d.tag48 = 0x17F000001FF0000;
    d.v30[0] = d.v30[2] = d.v30[3] = 0.0f;
    d.v30[1] = -v[0];
    sceVu0ApplyMatrix(d.v30, m, d.v30);
    *(s32*)&d.v30[3] = p->unk_19;
    func_001ABA80(&d);
    if (func_001ABCC8(&d)) {
        if (p->unk_19 & 2) {
            op_ot_insert0((u32*)D_00616224, (d.pkt - D_00616224) >> 4, 4, 0);
        } else {
            op_ot_insert2((u32*)D_00616224, (d.pkt - D_00616224) >> 4, d.unk_2C / 0x3000, 0);
        }
        ppvCurPrimpLen += d.pkt - D_00616224;
        D_00616224 = d.pkt;
    }
}

typedef struct {
    /* 0x0 */ s64 unk_00;
    /* 0x8 */ s32 unk_08;
} VKeShpDtt;

void pppKeShpDttCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeShpDtt* v = (VKeShpDtt*)&pobj->val[ctbl->useVal[0]];

    v->unk_00 = 0;
    v->unk_08 = 0;
}
