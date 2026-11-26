#include "ppp/pppKeLns.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 shpIdx;
    /* 0x08 */ u8 col[4];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u8 unk_10[4];
    /* 0x14 */ u16 unk_14;
} PKeLnsClmTDraw;

typedef struct {
    /* 0x00 */ u8 unk_00[0x30];
    /* 0x30 */ sceVu0FVECTOR scl;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ u8 col[4];
} KeLnsClmTWork;

void KeLnsArnd_Start(pppPObject* pobj, PKeLnsClmTDraw* p, pppCtrlTable* ctbl);
void KeLnsArndT_Draw(KeLnsClmTWork* w, s32 arg1, s32 arg2);

void pppKeLnsClmTDraw(pppPObject* pobj, PKeLnsClmTDraw* p, pppCtrlTable* ctbl) {
    KeLnsClmTWork* w = (KeLnsClmTWork*)&pobj->val[ctbl->useVal[0]];

    KeLnsArnd_Start(pobj, p, ctbl);
    if (p->cdt.time == pobj->time) {
        w->unk_44 = p->unk_0C;
        w->unk_40 = p->unk_14;
    }
    w->col[0] = p->col[0] * ppvMng->colorR;
    w->col[1] = p->col[1] * ppvMng->colorG;
    w->col[2] = p->col[2] * ppvMng->colorB;
    w->col[3] = p->col[3] * ppvMng->colorA;
    sceVu0CopyVector(w->scl, ppvParScl);
    KeLnsArndT_Draw(w, 0, 0);
}

void pppKeLnsClmTCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsClm* clm = (KeLnsClm*)&pobj->val[ctbl->useVal[0]];

    KeLnsClm_Init(clm);
    clm->num = 4;
}

void pppKeLnsClmTDes(void) {
}

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ char unk_10[0x10];
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
} KeLnsClmTArg;

typedef struct {
    /* 0x00 */ KeLnsClmTArg* arg;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ sceVu0FMATRIX* mat;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ void* unk_14;
} KeLnsClmTDrawSt;

void KeLnsStr_Draw(KeLnsClmTDrawSt* st, s32 arg1);

// Builds the draw state from the work and draws it.
void KeLnsClmT_Draw(KeLnsClmTArg* arg) {
    KeLnsClmTDrawSt st;

    st.unk_04 = arg->unk_24;
    st.unk_10 = (u32)arg->unk_28;
    st.unk_12 = (u32)arg->unk_2C;
    st.unk_14 = arg->unk_10;
    st.arg = arg;
    st.unk_0C = arg->unk_20;
    st.mat = &ppvScreenMatrix;
    KeLnsStr_Draw(&st, 0);
}
