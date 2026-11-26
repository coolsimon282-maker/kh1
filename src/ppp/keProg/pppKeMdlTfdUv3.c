#include "ppp.h"

typedef struct {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
} VKeMdlTfdUv3;

#include "libgraph.h"
typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 mdlIdx;
    /* 0x08 */ f32 inp;
    /* 0x0C */ f32 dinp;
    /* 0x10 */ f32 ddinp;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ u8 unk_1C;
    /* 0x20 */ f32 u;
    /* 0x24 */ f32 du;
    /* 0x28 */ f32 ddu;
    /* 0x2C */ f32 v;
    /* 0x30 */ f32 dv;
    /* 0x34 */ f32 ddv;
    /* 0x38 */ u8 unk_38;
    /* 0x39 */ u8 unk_39;
    /* 0x3A */ u8 unk_3A;
    /* 0x3B */ u8 unk_3B;
    /* 0x3C */ u8 unk_3C;
} PKeMdlTfdUv3;

typedef struct {
    /* 0x00 */ f32 inp;
    /* 0x04 */ f32 dinp;
    /* 0x08 */ f32 ddinp;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ f32 u;
    /* 0x14 */ f32 du;
    /* 0x18 */ f32 ddu;
    /* 0x1C */ f32 v;
    /* 0x20 */ f32 dv;
    /* 0x24 */ f32 ddv;
} VKeMdlTfdUv3f;

extern s32 D_00616224;
void func_001AB4B8(f32 inp, s32 arg1, s32 arg2, void* pkt);
void op_ot_insert0(u32* p, s32 qwc, s32 pri, s32 arg3);
void op_draw_model(u32 index, u16* col, s32 a2, s32 a3, s32 a4, u8 flags, void* a6);

void pppKeMdlTfdUv3Draw(pppPObject* pobj, PKeMdlTfdUv3* p, pppCtrlTable* ctbl) {
    VKeMdlTfdUv3f* v = (VKeMdlTfdUv3f*)&pobj->val[ctbl->useVal[2]];
    pppModelSt* mdl;
    sceGsLoadImage* li;
    s32 ofs;
    s32 pkt;
    void* a6;
    u16* col;

    if (!(ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0)) {
        v->dinp += v->ddinp;
        v->du += v->ddu;
        v->dv += v->ddv;
        v->inp += v->dinp;
        v->u += v->du;
        v->v += v->dv;
        if (pobj->time == p->cdt.time) {
            v->inp += p->inp;
            v->dinp += p->dinp;
            v->ddinp += p->ddinp;
            v->u += p->u;
            v->du += p->du;
            v->ddu += p->ddu;
            v->v += p->v;
            v->dv += p->dv;
            v->ddv += p->ddv;
        }
    }
    if (p->mdlIdx == 0xFFFF) {
        return;
    }
    mdl = &ppvEnv->lpModel[p->mdlIdx];
    ofs = p->unk_1C * 4;
    li = (sceGsLoadImage*)(D_00616224 + 0x10);
    sceGsSetDefLoadImage(li, (((u32)mdl->tex0h >> 5) & 0x3FFF) + ofs, 4, ((u32)mdl->tex0h >> 19) & 0xF, 0, 0, 16, 16);
    *(u64*)((u8*)li + 0x50) = 0x0800000000008100;
    pkt = D_00616224;
    func_001AB4B8(v->inp, p->unk_14, p->unk_18, (void*)(pkt + 0x70));
    op_ot_insert0((u32*)D_00616224, 0x107, 0, 0);
    D_00616224 = pkt + 0x1070;
    col = (u16*)&pobj->val[ctbl->useVal[0]];
    a6 = &pobj->val[ctbl->useVal[3]];
    op_draw_model(p->mdlIdx, col, ofs, v->u, v->v, p->unk_38 | p->unk_39 | p->unk_3C | p->unk_3A | p->unk_3B, a6);
}

void pppKeMdlTfdUv3Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeMdlTfdUv3* v = (VKeMdlTfdUv3*)&pobj->val[ctbl->useVal[2]];

    v->unk_00 = v->unk_04 = v->unk_08 = v->unk_10 = v->unk_14 = v->unk_18 = v->unk_1C = v->unk_20 = v->unk_24 = 0.0f;
}
