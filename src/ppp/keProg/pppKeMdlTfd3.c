#include "ppp.h"

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
    /* 0x1D */ u8 flag[5];
} PKeMdlTfd3;

typedef struct {
    /* 0x00 */ f32 inp;
    /* 0x04 */ f32 dinp;
    /* 0x08 */ f32 ddinp;
} VKeMdlTfd3f;

extern s32 D_00616224;
void func_001AB4B8(f32 inp, s32 arg1, s32 arg2, void* pkt);
void func_001AC758(u32* p, s32 qwc, s32 pri, s32 arg3);
void func_001AB828(u32 index, u16* col, s32 a2, s32 a3, s32 a4, u8 flags, void* a6);

void pppKeMdlTfd3Draw(pppPObject* pobj, PKeMdlTfd3* p, pppCtrlTable* ctbl) {
    VKeMdlTfd3f* v = (VKeMdlTfd3f*)&pobj->val[ctbl->useVal[2]];
    pppModelSt* mdl;
    sceGsLoadImage* li;
    s32 ofs;
    s32 pkt;
    u16* col;
    void* a6;

    if (!(ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0)) {
        v->dinp += v->ddinp;
        v->inp += v->dinp;
        if (pobj->time == p->cdt.time) {
            v->inp += p->inp;
            v->dinp += p->dinp;
            v->ddinp += p->ddinp;
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
    func_001AC758((u32*)D_00616224, 0x107, 0, 0);
    D_00616224 = pkt + 0x1070;
    col = (u16*)&pobj->val[ctbl->useVal[0]];
    a6 = &pobj->val[ctbl->useVal[3]];
    func_001AB828(p->mdlIdx, col, ofs, 0, 0, p->flag[0] | p->flag[1] | p->flag[3] | p->flag[2] | p->flag[4], a6);
}

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ s32 unk_4;
    /* 0x8 */ s32 unk_8;
} VKeMdlTfd3;

void pppKeMdlTfd3Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeMdlTfd3* v = (VKeMdlTfd3*)&pobj->val[ctbl->useVal[2]];

    v->unk_0 = 0;
    v->unk_4 = 0;
    v->unk_8 = 0;
}
