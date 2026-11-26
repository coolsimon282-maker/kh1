#include "ppp.h"
#include "libgraph.h"

typedef struct {
    /* 0x00 */ f32 inp;
    /* 0x04 */ f32 dinp;
    /* 0x08 */ f32 ddinp;
} KeTfdInp;

typedef struct {
    /* 0x00 */ KeTfdInp a;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ KeTfdInp b;
    /* 0x1C */ KeTfdInp c;
} VKeMdlTfdUv2;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 mdlIdx;
    /* 0x08 */ KeTfdInp a;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ u8 unk_1C;
    /* 0x1D */ char pad_1D[3];
    /* 0x20 */ KeTfdInp b;
    /* 0x2C */ KeTfdInp c;
    /* 0x38 */ u8 unk_38;
} PKeMdlTfdUv2;

extern s32 D_00616224;
void func_001AB4B8(f32 inp, s32 arg1, s32 arg2, void* pkt);
void op_ot_insert0(u32* p, s32 qwc, s32 pri, s32 arg3);
void op_draw_model(u32 index, u16* col, s32 a2, s32 a3, s32 a4, u8 flags, s32 a6);

void pppKeMdlTfdUv2Draw(pppPObject* pobj, PKeMdlTfdUv2* p, pppCtrlTable* ctbl) {
    VKeMdlTfdUv2* v = (VKeMdlTfdUv2*)&pobj->val[ctbl->useVal[2]];
    pppModelSt* mdl;
    sceGsLoadImage* li;
    s32 ofs;
    s32 pkt;

    if (!(ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0)) {
        v->a.dinp += v->a.ddinp;
        v->a.inp += v->a.dinp;
        v->b.dinp += v->b.ddinp;
        v->b.inp += v->b.dinp;
        v->c.dinp += v->c.ddinp;
        v->c.inp += v->c.dinp;
        if (pobj->time == p->cdt.time) {
            v->a.inp += p->a.inp;
            v->a.dinp += p->a.dinp;
            v->a.ddinp += p->a.ddinp;
            v->b.inp += p->b.inp;
            v->b.dinp += p->b.dinp;
            v->b.ddinp += p->b.ddinp;
            v->c.inp += p->c.inp;
            v->c.dinp += p->c.dinp;
            v->c.ddinp += p->c.ddinp;
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
    func_001AB4B8(v->a.inp, p->unk_14, p->unk_18, (void*)(pkt + 0x70));
    op_ot_insert0((u32*)D_00616224, 0x107, 0, 0);
    D_00616224 = pkt + 0x1070;
    op_draw_model(p->mdlIdx, (u16*)&pobj->val[ctbl->useVal[0]], ofs, v->b.inp, v->c.inp, p->unk_38, 0);
}

void pppKeMdlTfdUv2Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    f32* v = (f32*)&pobj->val[ctbl->useVal[2]];

    v[0] = v[1] = v[2] = v[4] = v[5] = v[6] = v[7] = v[8] = v[9] = 0.0f;
}
