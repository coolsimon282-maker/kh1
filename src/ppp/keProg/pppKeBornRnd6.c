#include "ppp.h"

typedef struct {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u8 unk_02;
} VKeBornRnd6;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ char pad_09[3];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
} PKeBornRnd6;

void KeBornRnd5_Born();
void KeBornRnd2(pppPObject* pobj, PKeBornRnd6* p, void* func, VKeBornRnd6* v, s16 a, u8 b, u8 c);

void pppKeBornRnd6Calc(pppPObject* pobj, PKeBornRnd6* p, pppCtrlTable* ctbl) {
    VKeBornRnd6* v;

    if (ppvEmptyLoop) {
        return;
    }
    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->unk_07 == 0) {
        return;
    }
    v = (VKeBornRnd6*)&pobj->val[ctbl->useVal[0]];
    if (v->unk_02 == 0) {
        v->unk_02 = p->unk_07;
        if (p->unk_0C == -1) {
            return;
        }
        if (p->unk_14 == -1) {
            return;
        }
        KeBornRnd2(pobj, p, KeBornRnd5_Born, v, p->unk_04, p->unk_08, p->unk_06);
    }
    v->unk_02--;
}

void pppKeBornRnd6Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeBornRnd6* v = (VKeBornRnd6*)&pobj->val[ctbl->useVal[0]];

    v->unk_00 = 0;
    v->unk_02 = 0;
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ u8 count;
    /* 0x05 */ char pad_05[3];
    /* 0x08 */ s32 pdtn;
    /* 0x0C */ s32 valoff;
} PKeBornRnd6Line;

typedef struct {
    /* 0x00 */ f32* prev;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 step;
} VKeBornRnd6Line;

pppPObject* pppCreatePObject(ppvmng*, pppPDataVal*);
void op_vec_copy_xyz(f32*, f32*);
void op_vec_add_xyz(f32*, f32*, f32*);

// Creates the child particles of a KeBornRnd6 line.
void KeBornRnd6_BornLine(pppPObject* parent, PKeBornRnd6Line* p, pppCtrlTable* ctbl) {
    pppPObject* child;
    pppPDataVal* pdv;
    f32* pos;
    VKeBornRnd6Line* v;

    {
        pppPDataVal* d = &((pppPDataVal*)ppvMng->unk_80)[p->pdtn];

        child = NULL;
        if (d != NULL) {
            child = pppCreatePObject(ppvMng, d);
            child->ppobj = parent;
        }
    }
    pos = (f32*)&child->val[p->valoff];
    op_vec_copy_xyz(pos, (f32*)&parent->val[ctbl->useVal[1]]);
    v = (VKeBornRnd6Line*)&parent->val[ctbl->useVal[0]];
    if (v->prev == NULL) {
        v->step = 1.0f / (p->count + 1);
    } else {
        sceVu0FVECTOR a;
        sceVu0FVECTOR d;
        sceVu0FVECTOR s;
        f32 n;
        f32 step;

        sceVu0CopyVector(a, v->prev);
        sceVu0SubVector(d, pos, a);
        n = p->count;
        step = v->step;
        while (n > 0.0f) {
            f32* q;

            child = NULL;
            pdv = &((pppPDataVal*)ppvMng->unk_80)[p->pdtn];
            if (pdv != NULL) {
                child = pppCreatePObject(ppvMng, pdv);
                child->ppobj = parent;
            }
            q = (f32*)&child->val[p->valoff];
            sceVu0ScaleVector(s, d, step * n);
            n -= 1.0f;
            op_vec_add_xyz(q, a, s);
        }
    }
    v->prev = pos;
}
