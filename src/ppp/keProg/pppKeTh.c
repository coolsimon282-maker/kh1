#include "common.h"
#include "ppp.h"

typedef struct {
    /* 0x00 */ u8 unk_00[0xC];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u8 unk_10[0x14];
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ u8 unk_28[4];
    /* 0x2C */ s32 unk_2C;
} KeThSub; // size = 0x30

typedef struct {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ KeThSub sub;
    /* 0x40 */ u8 unk_40[0x2C];
    /* 0x6C */ s32 unk_6C;
    /* 0x70 */ u64 unk_70;
    /* 0x78 */ u64 unk_78;
    /* 0x80 */ u64 unk_80;
    /* 0x88 */ u64 unk_88;
} KeTh; // size = 0x90

// Accessed through unions: the stores keep their order between the two bases.
typedef union {
    KeTh v;
    u8 raw[0x90];
} KeThU;

typedef union {
    KeThSub s;
    u8 raw[0x30];
} KeThSubU;

void func_001AADB8(void*);

typedef struct {
    /* 0x00 */ u8 c0[8];
    /* 0x08 */ char pad_08[4];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u8 c1[8];
    /* 0x18 */ char pad_18[4];
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ u8 unk_40;
    /* 0x41 */ u8 unk_41;
    /* 0x42 */ u8 unk_42;
} KeThCSub;

typedef struct {
    /* 0x00 */ char pad_00[4];
    /* 0x04 */ u8 flags;
    /* 0x05 */ char pad_05[0xB];
    /* 0x10 */ KeThCSub sub;
    /* 0x54 */ char pad_54[0xC];
    /* 0x60 */ void* pool;
    /* 0x64 */ void* tgt;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ u16 col[16];
} KeThC;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 pdtn;
    /* 0x08 */ s32 off;
    /* 0x0C */ u16 col[16];
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53;
    /* 0x54 */ u8 pad_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ u8 unk_56;
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ u8 unk_58;
} PKeTh;

typedef struct {
    /* 0x00 */ KeThC* head;
    /* 0x04 */ void* tgt;
    /* 0x08 */ KeThCSub* sub;
    /* 0x0C */ void* pool;
    /* 0x10 */ f32* pos;
    /* 0x14 */ f32* dir;
} KeThUpd;

void func_001AAA30(KeThC* head, void* pool, f32* arg2, f32* arg3);
void func_001AAB28(KeThUpd* u);

void pppKeThCalc(pppPObject* pobj, PKeTh* p, pppCtrlTable* ctbl) {
    sceVu0FMATRIX m;
    sceVu0FVECTOR dir;
    sceVu0FVECTOR pos;
    KeThUpd u;
    f32* src;
    KeThC* w;
    KeThCSub* sub;
    void* v2;
    void* tgt;
    f32 f;

    w = (KeThC*)&pobj->val[ctbl->useVal[0]];
    src = (f32*)&pobj->val[ctbl->useVal[2]];
    sub = &w->sub;
    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    sceVu0CopyMatrix(m, ppvPObj.next->cmat);
    *(u_long128*)m[3] = 0;
    m[3][3] = 1.0f;
    sceVu0ApplyMatrix(dir, m, src);
    sceVu0Normalize(dir, dir);
    sceVu0CopyVector(pos, ppvPObj.next->cmat[3]);
    if (pobj->time == p->cdt.time) {
        if (pobj->time == 0) {
            v2 = &pobj->val[ctbl->useVal[1]];
            if (p->pdtn != -1) {
                tgt = &((pppPDataVal*)ppvMng->unk_80)[p->pdtn].pobj->val[p->off];
            } else {
                tgt = &ppvDbgTemp;
            }
            if (w->tgt == &ppvDbgTemp) {
                return;
            }
            w->tgt = tgt;
            w->pool = v2;
            if (p->unk_56 == 0) {
                w->flags |= 8;
            }
            if (p->unk_55) {
                w->flags |= 4;
            }
            if (p->unk_58) {
                w->flags |= 0x10;
            }
            if (p->unk_57) {
                w->flags |= 0x20;
            }
            func_001AAA30(w, w->pool, pos, dir);
        }
        w->col[0] += p->col[0];
        w->col[1] += p->col[1];
        w->col[2] += p->col[2];
        w->col[3] += p->col[3];
        w->col[4] += p->col[4];
        w->col[5] += p->col[5];
        w->col[6] += p->col[6];
        w->col[7] += p->col[7];
        w->col[8] += p->col[8];
        w->col[9] += p->col[9];
        w->col[10] += p->col[10];
        w->col[11] += p->col[11];
        w->col[12] += p->col[12];
        w->col[13] += p->col[13];
        w->col[14] += p->col[14];
        w->col[15] += p->col[15];
        w->unk_68 = p->unk_2C;
        w->unk_6C += p->unk_48;
        sub->unk_42 = ((u8*)w->pool)[1] - 1;
        sub->unk_0C += p->unk_30;
        sub->unk_30 = p->unk_38;
        sub->unk_38 = p->unk_3C;
        sub->unk_3C = p->unk_40;
        sub->unk_24 += p->unk_44;
        sub->unk_2C += p->unk_4C;
        sub->unk_28 = p->unk_50 * 3.141592654 * (3.141592654 / 180.0);
        sub->unk_40 = p->unk_52;
        sub->unk_41 = p->unk_53;
        sub->unk_1C = -(sub->unk_0C - sub->unk_0C * p->unk_34) / sub->unk_42;
    }
    sub->unk_20 = w->unk_68 / sub->unk_42;
    sub->unk_34 = w->unk_6C / sub->unk_20;
    sub->c0[0] = w->col[0] >> 7;
    sub->c0[1] = w->col[1] >> 7;
    sub->c0[2] = w->col[2] >> 7;
    sub->c0[3] = w->col[3] >> 7;
    sub->c0[4] = w->col[4] >> 7;
    sub->c0[5] = w->col[5] >> 7;
    sub->c0[6] = w->col[6] >> 7;
    sub->c0[7] = w->col[7] >> 7;
    sub->c1[0] = w->col[8] >> 7;
    sub->c1[1] = w->col[9] >> 7;
    sub->c1[2] = w->col[10] >> 7;
    sub->c1[3] = w->col[11] >> 7;
    sub->c1[4] = w->col[12] >> 7;
    sub->c1[5] = w->col[13] >> 7;
    sub->c1[6] = w->col[14] >> 7;
    sub->c1[7] = w->col[15] >> 7;
    u.tgt = w->tgt;
    u.head = w;
    u.pool = w->pool;
    u.sub = &w->sub;
    u.pos = pos;
    u.dir = dir;
    func_001AAB28(&u);
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeTh", pppKeThDraw);

void pppKeThCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThU* v = (KeThU*)&pobj->val[ctbl->useVal[0]];
    KeThSubU* sub = (KeThSubU*)&v->v.sub;

    func_001AADB8(v);
    v->v.unk_70 = 0;
    v->v.unk_78 = 0;
    v->v.unk_80 = 0;
    v->v.unk_88 = 0;
    v->v.unk_6C = 0;
    sub->s.unk_0C = 0;
    sub->s.unk_24 = 0;
    sub->s.unk_2C = 0;
}

void pppKeThCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThU* v = (KeThU*)&pobj->val[ctbl->useVal[0]];
    KeThSubU* sub = (KeThSubU*)&v->v.sub;

    v->v.unk_70 = 0;
    v->v.unk_78 = 0;
    v->v.unk_80 = 0;
    v->v.unk_88 = 0;
    v->v.unk_6C = 0;
    sub->s.unk_0C = 0;
    sub->s.unk_24 = 0;
    sub->s.unk_2C = 0;
}

void pppKeThDes(void) {
}
