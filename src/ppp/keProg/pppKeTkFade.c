#include "ppp.h"

#include "libgraph.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 mdlIdx;
    /* 0x08 */ f32 inp;
    /* 0x0C */ f32 dinp;
    /* 0x10 */ f32 ddinp;
    /* 0x14 */ u32 col0;
    /* 0x18 */ u32 col1;
} PKeTkFade;

typedef struct {
    /* 0x00 */ f32 inp;
    /* 0x04 */ f32 dinp;
    /* 0x08 */ f32 ddinp;
} VKeTkFade;

extern u_long128 D_00372770[2];
extern s8 D_00372790[];
s32 op_spr_alloc(s32 size);
void op_spr_free(s32 size);

void pppKeTkFadeDraw(pppPObject* pobj, PKeTkFade* p, pppCtrlTable* ctbl) {
    VKeTkFade* v = (VKeTkFade*)&pobj->val[ctbl->useVal[0]];
    sceVu0FVECTOR d;
    sceVu0FVECTOR c;
    sceGsLoadImage li;
    pppModelSt* mdl;
    u64 tex0;
    u32* dst;
    u32* buf;
    s32 i;
    s32 n;
    u32 c0;
    u32 c1;
    f32 f;

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
    buf = (u32*)op_spr_alloc(0x420);
    ((u_long128*)buf)[0x40] = D_00372770[0];
    ((u_long128*)buf)[0x41] = D_00372770[1];
    mdl = &ppvEnv->lpModel[p->mdlIdx];
    n = v->inp;
    tex0 = ((u64)mdl->tex0h << 32) | mdl->tex0l;
    c1 = p->col1;
    c0 = p->col0;
    if (n < 0) {
        if (n < -0x100) {
            n = -0x100;
        }
        n += 0x100;
        dst = ((n & 0xE0) + D_00372790[n & 0x1F]) + buf;
        for (i = n; i < 0x100; i++) {
            *dst = c0;
            dst += *(s8*)((i & 0x1F) + (s32)buf + 0x400);
        }
        i = 0;
        f = n;
        dst = buf;
    } else {
        if (n >= 0x100) {
            n = 0xFF;
        }
        dst = buf;
        for (i = 0; i < n; i++) {
            *dst = c1;
            dst += *(s8*)((i & 0x1F) + (s32)buf + 0x400);
        }
        f = 256.0f - (f32)n;
        n = 0x100;
    }
    c[0] = (s32)((c1) & 0xFF);
    c[1] = (s32)((c1 >> 8) & 0xFF);
    c[2] = (s32)((c1 >> 16) & 0xFF);
    c[3] = (s32)((c1 >> 24) & 0xFF);
    d[0] = (s32)((c0) & 0xFF);
    d[1] = (s32)((c0 >> 8) & 0xFF);
    d[2] = (s32)((c0 >> 16) & 0xFF);
    d[3] = (s32)((c0 >> 24) & 0xFF);
    sceVu0SubVector(d, d, c);
    sceVu0DivVector(d, d, f);
    for (; i < n; i++) {
        *dst = (u32)c[3] << 24 | (u32)c[2] << 16 | (u32)c[1] << 8 | (u32)c[0];
        sceVu0AddVector(c, c, d);
        dst += *(s8*)((i & 0x1F) + (s32)buf + 0x400);
    }
    sceGsSetDefLoadImage(&li, (tex0 >> 37) & 0x3FFF, 4, (tex0 >> 51) & 0xF, 0, 0, 16, 16);
    FlushCache(0);
    sceGsExecLoadImage(&li, (u_long128*)buf);
    sceGsSyncPath(0, 0);
    op_spr_free(0x420);
}

void pppKeTkFadeCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    s32* v = (s32*)&pobj->val[ctbl->useVal[0]];

    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
}
