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
    /* 0x1D */ u8 unk_1D;
} PKeMdlTfd;

typedef struct {
    /* 0x00 */ f32 inp;
    /* 0x04 */ f32 dinp;
    /* 0x08 */ f32 ddinp;
} VKeMdlTfdf;

extern s32 D_00616224;
void func_001AB4B8(f32 inp, s32 arg1, s32 arg2, void* pkt);
void func_001AC758(u32* p, s32 qwc, s32 pri, s32 arg3);
void func_001AB828(u32 index, u16* col, s32 a2, s32 a3, s32 a4, u8 flags, s32 a6);

void pppKeMdlTfdDraw(pppPObject* pobj, PKeMdlTfd* p, pppCtrlTable* ctbl) {
    VKeMdlTfdf* v = (VKeMdlTfdf*)&pobj->val[ctbl->useVal[2]];
    pppModelSt* mdl;
    sceGsLoadImage* li;
    s32 ofs;
    s32 pkt;

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
    func_001AB828(p->mdlIdx, (u16*)&pobj->val[ctbl->useVal[0]], ofs, 0, 0, 1, 0);
}


void pppKeMdlTfdCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    s32* v = (s32*)&pobj->val[ctbl->useVal[2]];

    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
}
