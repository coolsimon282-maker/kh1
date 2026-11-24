#include "common.h"
#include "ppp.h"
#include "ppp/draw.h"

#include "libgraph.h"

extern s32 D_00370200;

extern void func_0011D1F8(s32, s32, s32);

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ void (*func)(void*);
} PppFuncEnt;

typedef struct {
    /* 0x00 */ char unk_00[0x64];
    /* 0x64 */ s32 num;
    /* 0x68 */ char unk_68[0x10];
    /* 0x78 */ PppFuncEnt** ents;
} PppFuncList;

typedef struct {
    /* 0x00 */ char unk_00[0x86];
    /* 0x86 */ u16 usef;
    /* 0x88 */ char unk_88[0x4];
    /* 0x8C */ pppPEtcData* pEtc;
    /* 0x90 */ char unk_90[0x4];
    /* 0x94 */ s32 unk_94;
    /* 0x98 */ char unk_98[0x28];
} PppMngU;

extern PppMngU D_00364130[];

extern sceVu0FMATRIX D_00615E70;
extern void func_0024EDF0(sceVu0FMATRIX, pppPEtcData*);

extern sceVu0FMATRIX D_002B84F0;

s32 D_0035FE00;

pppModelSt RendModel[128]; // = {};
pppShapeSt RendShape[128]; // = {};
pppVsfSt RendVsf[128];     // = {};
ppvmng D_00360600[0x100];  // = {};

s16 D_0036C5C6[];
s32 D_0036C600;

u8 D_00590580[];

s32 ppvCurPrimpLen;
u_long128* ppvPrimp;
s32 ppvPrimpLen;

u_long128 D_00570580;
pppSVECTOR* ppvVertex;

void pppSetPrimPacket(u_long128* primPacketArea, s32 len) {
    if (primPacketArea != NULL) {
        ppvPrimp = primPacketArea;
        ppvPrimpLen = len;
    } else {
        ppvPrimp = &D_00570580;
        ppvPrimpLen = 0x20000;
    }
}

void drawStart(void) {
    ppvVertex = NULL;
}

s32 pppDbgAlloc(s32 arg0, s32 arg1) {
    return pppAlloc(arg0, arg1);
}

void drawEnd(void) {
    if (ppvCurPrimpLen != 0) {
        op_ot_draw();
        op_otz_init();
    }
}

void initGraphicSystem(void) {
    op_init_draw();
    op_gs2_init();
    op_otz_init();
    op_init_fog_work();
}

void func_00181040(void) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (D_00364130[i].usef & 1) {
            pppPEtcData* e = D_00364130[i].pEtc;
            if (e != NULL && *(u16*)&e->seNo != 0) {
                func_0011D1F8(*(u16*)&e->seNo, *(s32*)((u8*)&D_00364130[i] + 0xA8), 0x3C);
            }
            pppAllFreePObject((ppvmng*)&D_00364130[i]);
            func_00183E78(&D_00364130[i]);
        }
    }
}

void func_001810D0(void) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (D_00364130[i].usef & 1) {
            D_00364130[i].usef |= 0x20;
        }
    }
}

void func_00181110(void) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (D_00364130[i].usef & 1) {
            D_00364130[i].usef &= ~0x20;
        }
    }
}

void func_00181150(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if ((D_00364130[i].usef & 1) && D_00364130[i].unk_94 == arg0) {
            D_00364130[i].usef |= 0x20;
            return;
        }
    }
}

void func_001811A8(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if ((D_00364130[i].usef & 1) && D_00364130[i].unk_94 == arg0) {
            D_00364130[i].usef &= ~0x20;
            return;
        }
    }
}

void func_00181200(s32 arg0) {
    s32 i;
    s32 off;
    PppMngU *base = D_00364130;
    u8 *p = (u8 *)base + 0x80;

    for (i = 0, off = 0; i < 0x100; i++, p += 0xC0, off += 0xC0) {
        if ((*(u16 *)(p + 6) & 1) && *(s32 *)(p + 0x14) == arg0) {
            pppPEtcData* e = *(pppPEtcData **)(p + 0xC);
            if (*(u16*)&e->seNo != 0) {
                func_0011D1F8(*(u16*)&e->seNo, *(s32*)(p + 0x28), 0x3C);
            }
            off += (s32)base;
            pppAllFreePObject((ppvmng*)off);
            func_00183E78((void *)off);
            return;
        }
    }
}

void func_001812B0(void) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (D_00364130[i].usef & 1) {
            pppPEtcData* e = D_00364130[i].pEtc;
            if (e != NULL && *(u16*)&e->seNo != 0) {
                func_0011D1F8(*(u16*)&e->seNo, *(s32*)((u8*)&D_00364130[i] + 0xA8), 0x3C);
            }
            pppAllFreePObject((ppvmng*)&D_00364130[i]);
            func_00183EC8((ppvmng*)&D_00364130[i]);
        }
    }
}

void func_00181340(s32 arg0) {
    s32 i;
    s32 off;
    PppMngU *base = D_00364130;
    u8 *p = (u8 *)base + 0x80;

    for (i = 0, off = 0; i < 0x100; i++, p += 0xC0, off += 0xC0) {
        if ((*(u16 *)(p + 6) & 1) && *(s32 *)(p + 0x14) == arg0) {
            pppPEtcData* e = *(pppPEtcData **)(p + 0xC);
            if (*(u16*)&e->seNo != 0) {
                func_0011D1F8(*(u16*)&e->seNo, *(s32*)(p + 0x28), 0x3C);
            }
            off += (s32)base;
            pppAllFreePObject((ppvmng*)off);
            func_00183EC8((ppvmng*)off);
            return;
        }
    }
}

void func_001813F0(s32 arg0, s32 arg1) {
    s32 i;
    s32 off;
    s32 d;
    PppMngU *base = D_00364130;
    u8 *p = (u8 *)base + 0x80;

    for (i = 0, off = 0; i < 0x100; i++, p += 0xC0, off += 0xC0) {
        if (*(u16 *)(p + 6) & 1) {
            d = *(s32 *)(p + 8) - arg0;
            if (d >= 0 && d < arg1) {
                pppPEtcData* e = *(pppPEtcData **)(p + 0xC);
                if (*(u16*)&e->seNo != 0) {
                    func_0011D1F8(*(u16*)&e->seNo, *(s32*)(p + 0x28), 0x3C);
                }
                pppAllFreePObject((ppvmng*)(off + (s32)base));
                func_00183E78((void *)(off + (s32)base));
            }
        }
    }
}

void func_001814C8(s32 arg0, s32 arg1) {
    s32 i;
    s32 off;
    s32 d;
    PppMngU *base = D_00364130;
    u8 *p = (u8 *)base + 0x80;

    for (i = 0, off = 0; i < 0x100; i++, p += 0xC0, off += 0xC0) {
        if (*(u16 *)(p + 6) & 1) {
            d = *(s32 *)(p + 8) - arg0;
            if (d >= 0 && d < arg1) {
                pppPEtcData* e = *(pppPEtcData **)(p + 0xC);
                if (*(u16*)&e->seNo != 0) {
                    func_0011D1F8(*(u16*)&e->seNo, *(s32*)(p + 0x28), 0x3C);
                }
                pppAllFreePObject((ppvmng*)(off + (s32)base));
                func_00183EC8((ppvmng*)(off + (s32)base));
            }
        }
    }
}

typedef struct {
    char pad[0x86];
    u16 usef;
    char pad2[0x28];
    u8 drawPriority;
    u8 stop;
    u8 pad4[5];
    u8 b7;
    u64 pad3;
} MngV15A0;
extern MngV15A0 D_00364130_v15A0[] __asm__("D_00364130");
void func_001815A0(s32 a0) {
    s32 i;
    for (i = 0; i < 0x100; i++) {
        if (D_00364130_v15A0[i].usef & 1) {
            if (a0) {
                D_00364130_v15A0[i].b7 = 1;
                D_00364130_v15A0[i].stop |= 0x80;
            } else {
                D_00364130_v15A0[i].b7 = 0;
                D_00364130_v15A0[i].stop &= 0x7F;
            }
        }
    }
}

s32 func_00181600(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (D_00364130[i].unk_94 == arg0) {
            return D_00364130[i].pEtc->boneNo;
        }
    }
    return -2;
}

void func_00181640(u8* rsd, s16* tim, s16 tex, s16 clut) {
    s16 dt;
    s16 dc;
    u8* e = rsd + *(s32*)(rsd + 4);
    s32 size;
    s32 flag;
    s32 t;
    u32 w;

    if (tex == 0 && clut == 0) {
        return;
    }
    if (tex != 0) {
        dt = tex - (u16)tim[1];
    }
    if (clut != 0) {
        dc = clut - (u16)tim[2];
    }
    if (dt == 0 && dc == 0) {
        return;
    }
    while ((s8)e[1] != -1) {
        flag = 1;
        switch ((s8)e[1]) {
            case 0:
                size = 0x14;
                flag = 0;
                break;
            case 1:
                size = 0x1C;
                flag = 0;
                break;
            case 2:
                size = 0x20;
                break;
            case 4:
                size = 0x18;
                flag = 0;
                break;
            case 5:
                size = 0x20;
                flag = 0;
                break;
            case 3:
            case 6:
                size = 0x28;
                break;
            case 7:
                size = 0x30;
                break;
        }
        if (flag) {
            if (tex != 0 && dt != 0) {
                t = *(u16*)(e + 8) & 0x3FFF;
                if (t >= 0x3800) {
                    *(u32*)(e + 8) = (*(u32*)(e + 8) & ~0x3FFF) + (t + dt);
                }
            }
            if (clut != 0 && dc != 0) {
                w = *(u32*)(e + 0xC);
                t = (w >> 5) & 0x3FFF;
                if (t >= 0x3D40) {
                    *(u32*)(e + 0xC) = (w & 0xFFF8001F) + ((t + dc) << 5);
                }
            }
        }
        e += size * *(s16*)(e + 2);
        e += 0x10;
    }
}


void func_001817E8(u8* shp, u16* tim, s16 tex, s16 clut) {
    s16 dt = 0;
    s16 dc = 0;
    s32 n;
    s16* a;
    u8* e;
    s32 t;
    u32 w;

    if (tex == 0 && clut == 0) {
        return;
    }
    if (tex != 0) {
        dt = tex - tim[1];
    }
    if (clut != 0) {
        dc = clut - tim[2];
    }
    n = *(s16*)(shp + 6);
    a = (s16*)(shp + 0x10);
    for (; n > 0; n--) {
        e = shp + a[0];
        a += 4;
        if (tex != 0 && dt != 0) {
            t = *(u16*)(e + 0x10) & 0x3FFF;
            if (t >= 0x3800) {
                *(u32*)(e + 0x10) = (*(u32*)(e + 0x10) & ~0x3FFF) + (t + dt);
            }
        }
        if (clut != 0 && dc != 0) {
            w = *(u32*)(e + 0x14);
            t = (w & 0x7FFE0) >> 5;
            if (t >= 0x3D40) {
                *(u32*)(e + 0x14) = (w & 0xFFF8001F) + ((t + dc) << 5);
            }
        }
    }
}


INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppSetUp);

s32* dpd_h_skip_version(s32* p) {
    return p + 1;
}

s32* dpd_h_skip_datainfo(s32* p, s32 n) {
    s32 len;
    s32 i;

    for (i = 0; i < n; i++) {
        len = *p++;
        p += len;
    }
    return p;
}

void func_00181A58(s32* dpd, s32 idx, s32* out, ppvmng* m) {
    s32* p = dpd_h_skip_version(dpd);
    s32 n;
    s32 i;
    s32 v;
    s32 a;
    s32 b;

    *out = 0;
    n = *p++;
    for (i = 0; i < n; i++) {
        if (idx == i) {
            v = *p;
            m->pEtc = (pppPEtcData*)v;
            *out = v + 0x110;
        }
        p++;
    }
    p = dpd_h_skip_datainfo(p, 4);
    if (p[0] != -1) {
        a = p[1] - 0x3781;
        b = p[3] - 0x3D21;
        m->unk_91 = a / 128;
        m->unk_92 = b / 32;
    } else {
        m->unk_91 = 0;
        m->unk_92 = 0;
    }
}


s32* func_00181B38(s32* arg0, s32 arg1) {
    s32* p = dpd_h_skip_version(arg0);
    s32 i;
    s32 j;
    s32 n;

    for (i = 0; i < 5; i++) {
        n = *p++;
        for (j = 0; j < n; j++) {
            *p++ += arg1;
        }
    }
    return p;
}

void func_00181BA8(s32* arg0) {
    s32* p;
    s32 n;
    s32 i;

    func_00181B38(arg0, (s32)arg0);
    p = dpd_h_skip_version(arg0);
    n = *p++;
    for (i = 0; i < n; i++) {
        func_001843E0(*p++, &D_00370200);
    }
}

s32* func_00181C20(s32* p, u8* use, s16 tex, s16 clut) {
    s32 n = *p++;
    s32 i;
    u8 bits = 0;
    s16* tim;
    s32 j;
    s32 k;
    u8* shp;

    for (i = 0; i < n; i++) {
        j = i & 7;
        tim = (s16*)*p++;
        k = i >> 3;
        if (j == 0) {
            bits = use[k];
        }
        if (bits & 1) {
            shp = (u8*)(tim + 8);
            if (tim[1] == 0) {
                tim[1] = 0x3800;
            }
            if (tim[2] == 0) {
                tim[2] = 0x3D40;
            }
            func_001817E8(shp, (u16*)tim, tex, clut);
            if (tex != 0) {
                tim[1] = tex;
            }
            if (clut != 0) {
                tim[2] = clut;
            }
        }
        bits >>= 1;
    }
    return p;
}


void func_00181640(u8*, s16*, s16, s16);

s32* func_00181D30(s32* p, u8* use, s16 tex, s16 clut) {
    s32 n = *p++;
    s32 i;
    u8 bits = 0;
    s16* tim;
    s32 j;
    s32 k;
    u8* shp;

    for (i = 0; i < n; i++) {
        j = i & 7;
        tim = (s16*)*p++;
        k = i >> 3;
        if (j == 0) {
            bits = use[k];
        }
        if (bits & 1) {
            shp = (u8*)(tim + 8);
            if (tim[1] == 0) {
                tim[1] = 0x3800;
            }
            if (tim[2] == 0) {
                tim[2] = 0x3D40;
            }
            func_00181640(shp, tim, tex, clut);
            if (tex != 0) {
                tim[1] = tex;
            }
            if (clut != 0) {
                tim[2] = clut;
            }
        }
        bits >>= 1;
    }
    return p;
}


s32* func_00181C20(s32*, u8*, s16, s16);
s32* func_00181D30(s32*, u8*, s16, s16);

void dpd_set_object_tex(ppvmng* pMng) {
    s32* p = (s32*)pMng->pchDpd;
    s16 texpStart = pMng->texpStart;
    s16 clutpStart = pMng->clutpStart;

    if (texpStart == 0 && clutpStart == 0) {
        return;
    }
    p = dpd_h_skip_version(p);
    p = dpd_h_skip_datainfo(p, 2);
    p = func_00181C20(p, pMng->pEtc->abUseShape, texpStart, clutpStart);
    func_00181D30(p, pMng->pEtc->abUseRsd, texpStart, clutpStart);
}

extern pppShapeSt D_00363930[];

s32* dpd_set_shape_data(s32* p, u8* use) {
    s32 n = *p++;
    s32 i;
    u8 bits = 0;
    s16* s;
    s32 k;
    s32 j;

    for (i = 0; i < n;) {
        j = i & 7;
        s = (s16*)*p++;
        k = i >> 3;
        i++;
        if (j == 0) {
            bits = use[k];
        }
        if (bits & 1) {
            pppShapeSt* d = &D_00363930[s[0]];
            d->shape = (u_long128*)(s + 8);
            d->nPacketSize = *(s32*)(s + 4);
        }
        bits >>= 1;
    }
    return p;
}


extern pppModelSt D_00362730[];

s32* dpd_set_rsd_data(s32* p, u8* use) {
    s32 n = *p++;
    s32 i;
    u8 bits = 0;
    s32* s;
    s32 k;
    s32 j;
    OMD_H* h;

    for (i = 0; i < n;) {
        j = i & 7;
        s = (s32*)*p++;
        k = i >> 3;
        i++;
        if (j == 0) {
            bits = use[k];
        }
        if (bits & 1) {
            pppModelSt* d = &D_00362730[*(s16*)s];

            h = (OMD_H*)(s + 4);
            d->omd = h;
            d->nvert = (s16)h->vc;
            d->nnorm = (s16)h->nc;
            d->npoly = (s16)h->pc;
            d->vert = (pppSVECTOR*)((u8*)h + h->va);
            d->norm = (pppSVECTOR*)((u8*)h + h->na);
            d->nPacketSize = s[2];
        }
        bits >>= 1;
    }
    return p;
}


extern pppVsfSt D_00363D30[];

s32* dpd_set_vsf_data(s32* p, u8* use) {
    s32 n = *p++;
    s32 i;
    u8 bits = 0;
    s32* s;
    s32 k;
    s32 j;

    for (i = 0; i < n;) {
        j = i & 7;
        s = (s32*)*p++;
        k = i >> 3;
        i++;
        if (j == 0) {
            bits = use[k];
        }
        if (bits & 1) {
            pppVsfSt* d = &D_00363D30[s[0]];
            d->modelNo = *(u16*)(s + 1);
            d->indexN = *(u16*)(s + 2);
            d->index = (s16*)(s + 3);
        }
        bits >>= 1;
    }
    return p;
}


s32 dpd_set_object_data(ppvmng* pMng) {
    s32* piVar1;
    s16** ppsVar2;

    piVar1 = dpd_h_skip_version(pMng->pchDpd);
    piVar1 = dpd_h_skip_datainfo(piVar1, 2);
    ppsVar2 = dpd_set_shape_data(piVar1, pMng->pEtc->abUseShape);
    ppsVar2 = dpd_set_rsd_data(ppsVar2, pMng->pEtc->abUseRsd);
    return dpd_set_vsf_data(ppsVar2, pMng->pEtc->abUseVsf);
}

void func_00182110(s32 arg0) {
    D_0036C600 = arg0;
}

void func_00182120(s16* tim, s16 off) {
    sceGsLoadImage li;
    s16 dbp = tim[0];

    if (dbp >= 0x3800) {
        dbp = dbp + off - 0x3800;
    }
    sceGsSetDefLoadImage(&li, dbp, tim[2], tim[3], tim[4], tim[5], tim[6], tim[7]);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&li, (u_long128*)(tim + 0x10));
}

void func_001821A8(s16* clut, s16 off) {
    sceGsLoadImage li;
    s16 cbp = clut[1];

    if (cbp == 0) {
        return;
    }
    if (cbp >= 0x3D40) {
        cbp = cbp + off - 0x3D40;
    }
    switch (clut[3]) {
        case 0x13:
            sceGsSetDefLoadImage(&li, cbp, 1, 0, 0, 0, 16, 16);
            break;
        case 0x14:
            sceGsSetDefLoadImage(&li, cbp, 1, 0, 0, 0, 8, 2);
            break;
        default:
            return;
    }
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&li, (u_long128*)((u8*)clut + ((s32*)clut)[6] + 0x20));
}

void func_00182288(s32* arg0, u8* use, s16 off) {
    s32* p = dpd_h_skip_datainfo(dpd_h_skip_version(arg0), 1);
    s32 n = *p++;
    s32 i;
    u8 bits = 0;
    s16* tim;
    s32 k;
    s32 j;

    for (i = 0; i < n;) {
        j = i & 7;
        tim = (s16*)*p++;
        k = i >> 3;
        i++;
        if (j == 0) {
            bits = use[k];
        }
        if (bits & 1) {
            func_00182120(tim, off);
        }
        bits >>= 1;
    }
}


void func_00182348(s32* arg0) {
    s32* p = dpd_h_skip_datainfo(dpd_h_skip_version(arg0), 1);
    s32 n = *p++;
    s32 i;

    for (i = 0; i < n; i++) {
        func_00182120(*p++, 0);
    }
}



void func_001823B8(s32* arg0, u8* use, s16 off) {
    s32* p;
    s32 n;
    s32 i;
    u8 bits = 0;
    s16* tim;
    s32 k;
    s32 j;

    if (arg0 == NULL) {
        return;
    }
    p = dpd_h_skip_datainfo(dpd_h_skip_version(arg0), 1);
    n = *p++;
    for (i = 0; i < n;) {
        j = i & 7;
        tim = (s16*)*p++;
        k = i >> 3;
        i++;
        if (j == 0) {
            bits = use[k];
        }
        if (bits & 1) {
            func_001821A8(tim, off);
        }
        bits >>= 1;
    }
}


void func_00182478(s32* arg0) {
    s32* p;
    s32 n;
    s32 i;

    if (arg0 == NULL) {
        return;
    }
    p = dpd_h_skip_datainfo(dpd_h_skip_version(arg0), 1);
    n = *p++;
    for (i = 0; i < n; i++) {
        func_001821A8(*p++, 0);
    }
}

void vramcache_clear(_VRAMCACHE* cache) {
    cache->dpd = NULL;
    cache->dpdId = 0;
    cache->blockStart = -1;
    cache->blockNum = 0;
    cache->boolUse = FALSE;
}

void vramcachemng_clear(_VRAMCACHE_MNG* cacheMng) {
    s32 i;

    for (i = 0; i < 10; i++) {
        vramcache_clear(&cacheMng->vramCacheTex[i]);
    }

    for (i = 0; i < 6; i++) {
        vramcache_clear(&cacheMng->vramCacheClut[i]);
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182580);

void vramcache_texture(_VRAMCACHE_MNG* cacheMng, ppvmng* pMng) {
    s32 lVar1 = func_00182580(cacheMng, 10, pMng, pMng->unk_91);

    if (lVar1 < 0) {
        pMng->texpStart = 0;
    } else {
        pMng->texpStart = (lVar1 << 7) + 0x3800;
    }
}

void vramcache_clut(_VRAMCACHE_MNG* cacheMng, ppvmng* pMng) {
    s32 lVar1 = func_00182580(cacheMng->vramCacheClut, 6, pMng, pMng->unk_92);

    if (lVar1 < 0) {
        pMng->clutpStart = 0;
    } else {
        pMng->clutpStart = (lVar1 << 5) + 0x3D40;
    }
}

void func_00182938(ppvmng* arg0) {
    sceVu0FMATRIX m;

    sceVu0MulMatrix(m, D_002B84F0, D_00615E70);
    func_0024EDF0(m, arg0->pEtc);
}

s32 func_00182980(void) {
    PppMngU* p = D_00364130;
    s32 i;
    s32 sum = 0;

    for (i = 0; i < 0x100; i++, p++) {
        if ((p->usef & 1) && !(p->usef & 4)) {
            sum += *(s32*)((u8*)p->pEtc + 0xF0);
        }
    }
    return sum;
}

s32 func_001829D0(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if ((D_00364130[i].usef & 1) && !(D_00364130[i].usef & 4) && ((ppvmng*)&D_00364130[i])->unk_98 < arg0) {
            if (*(u16*)&D_00364130[i].pEtc->seNo != 0) {
                func_0011D1F8(*(u16*)&D_00364130[i].pEtc->seNo, *(s32*)((u8*)&D_00364130[i] + 0xA8), 0x3C);
            }
            pppAllFreePObject((ppvmng*)&D_00364130[i]);
            D_00364130[i].usef |= 4;
            return 1;
        }
    }
    return 0;
}


s32 func_00182A78(void) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if ((D_00364130[i].usef & 1) && !(D_00364130[i].usef & 4) && ((ppvmng*)&D_00364130[i])->unk_98 < 0) {
            if (*(u16*)&D_00364130[i].pEtc->seNo != 0) {
                func_0011D1F8(*(u16*)&D_00364130[i].pEtc->seNo, *(s32*)((u8*)&D_00364130[i] + 0xA8), 0x3C);
            }
            pppAllFreePObject((ppvmng*)&D_00364130[i]);
            func_00183EC8((ppvmng*)&D_00364130[i]);
            return 1;
        }
    }
    return 0;
}


#ifdef VERSION_FM
void func_00182B18(f32* a, s32* b, s32 left, s32 right) {
    s32 i;
    s32 j;
    f32 pivot;
    f32 tf;
    s32 ti;

    pivot = a[(left + right) / 2];
    i = left;
    j = right;
    for (;;) {
        while (a[i] > pivot) {
            i++;
        }
        while (pivot > a[j]) {
            j--;
        }
        if (i >= j) {
            break;
        }
        tf = a[i];
        a[i] = a[j];
        a[j] = tf;
        ti = b[i];
        b[i] = b[j];
        b[j] = ti;
        i++;
        j--;
    }
    if (left < i - 1) {
        func_00182B18(a, b, left, i - 1);
    }
    if (j + 1 < right) {
        func_00182B18(a, b, j + 1, right);
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182B18);
#endif

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182C78);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182D90);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001831A0);

void init_part_mng(ppvmng* pMng) {
    memset(pMng, 0, 0xC0);
    pMng->unk_00 = 0;
    pMng->usef = 9;
    pMng->unk_04 = 0.0f;
    pMng->unk_08 = 0.0f;
    pMng->unk_0C = 1.0f;
    pMng->unk_20 = 1.0f;
    pMng->unk_24 = 1.0f;
    pMng->unk_28 = 1.0f;
    pMng->unk_2C = 1.0f;
    pMng->unk_10 = 0.0f;
    pMng->unk_14 = 0.0f;
    pMng->unk_18 = 0.0f;
    pMng->unk_1C = 0.0f;
    pMng->colorR = 1.0f;
    pMng->colorG = 1.0f;
    pMng->colorB = 1.0f;
    pMng->colorA = 1.0f;
    pMng->scaleX = 1.0f;
    pMng->scaleY = 1.0f;
    pMng->unk_48 = 1.0f;
    pMng->unk_4C = 1.0f;
}

void func_00183658(ppvmng **out) {
    PppMngU *p = D_00364130;
    s32 i;
    for (i = 0; i < 0x100; i++) {
        if (!(*(u64 *)((u8 *)&p[i] + 0x80) & 0x3000000000000)) {
            init_part_mng((ppvmng *)&p[i]);
            *out = (ppvmng *)&p[i];
            break;
        }
    }
}

extern pppEnvSt D_00615E40;
extern u8 D_00595E40[];
extern sceVu0FMATRIX D_006161C0;
extern sceVu0FVECTOR D_00616200;
extern pppModelSt D_00362730[];
extern pppShapeSt D_00363930[];
extern pppVsfSt D_00363D30[];
void func_00185008(pppMemMng* m, pppEMCB* start, s32 size);

void pppInitPartRender(void) {
    s32 i;

    initGraphicSystem();
    ppvUserStopPartF = 0;
    func_00185008(&D_00615E40.heapMng, (pppEMCB*)D_00595E40, 0x80000);
    D_00615E40.lpModel = D_00362730;
    D_00615E40.lpShape = D_00363930;
    D_00615E40.lpVsf = D_00363D30;
    ppvEnv = &D_00615E40;
    ppvHookFuncTbl = NULL;
    memset(D_00364130, 0, 0xC000);
    for (i = 255; i >= 0; i--) {
        D_00364130[i].usef = 0;
    }
    sceVu0UnitMatrix(D_006161C0);
    *(u_long128*)D_00616200 = 0;
    D_00616200[3] = 1.0f;
    pppSetPrimPacket(NULL, -1);
}

typedef struct {
    u_long128 q[4];
} PppMtx;

extern sceVu0FMATRIX D_00615EB0;
extern sceVu0FMATRIX D_00615EF0;
extern sceVu0FMATRIX D_00615F30;
extern sceVu0FVECTOR D_00615F90;
extern sceVu0FVECTOR D_00615FA0;
extern f32 D_00615FB0;
extern f32 D_002DED00;
extern sceVu0FMATRIX D_00616180;

void pppSetPartMatrix(sceVu0FMATRIX world, sceVu0FMATRIX screen, sceVu0FVECTOR eye, sceVu0FVECTOR at) {
    sceVu0FMATRIX unused;

    sceVu0CopyMatrix(D_00615EF0, D_00615EB0);
    ((u_long128*)D_00615EB0)[0] = ((u_long128*)world)[0];
    ((u_long128*)D_00615EB0)[1] = ((u_long128*)world)[1];
    ((u_long128*)D_00615EB0)[2] = ((u_long128*)world)[2];
    ((u_long128*)D_00615EB0)[3] = ((u_long128*)world)[3];
    ((u_long128*)ppvScreenMatrix)[0] = ((u_long128*)screen)[0];
    ((u_long128*)ppvScreenMatrix)[1] = ((u_long128*)screen)[1];
    ((u_long128*)ppvScreenMatrix)[2] = ((u_long128*)screen)[2];
    ((u_long128*)ppvScreenMatrix)[3] = ((u_long128*)screen)[3];
    *(u_long128*)D_00615F90 = *(u_long128*)ppvEye;
    *(u_long128*)D_00615FA0 = *(u_long128*)ppvAt;
    *(u_long128*)ppvEye = *(u_long128*)eye;
    *(u_long128*)ppvAt = *(u_long128*)at;
    D_00615FB0 = D_002DED00;
    sceVu0InversMatrix(D_00615F30, D_00615EB0);
    sceVu0MulMatrix(D_00616180, ppvScreenMatrix, D_00615EB0);
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001838E8);

void func_00183980(PppFuncList* arg0) {
    s32 i;

    for (i = 0; i < arg0->num; i++) {
        void (*f)(void*) = arg0->ents[i]->func;
        if (f != NULL) {
            f(arg0);
        }
    }
}

void func_001839F0(PppFuncList* arg0) {
    s32 i;

    for (i = 0; i < arg0->num; i++) {
        void (*f)(void*) = *(void (**)(void*))((u8*)arg0->ents[i] + 0x14);
        if (f != NULL) {
            f(arg0);
        }
    }
}

void func_00183A60(PppFuncList* arg0) {
    s32 i;

    for (i = 0; i < arg0->num; i++) {
        void (*f)(void*) = *(void (**)(void*))((u8*)arg0->ents[i] + 0x18);
        if (f != NULL) {
            f(arg0);
        }
    }
}

typedef struct {
    /* 0x00 */ char unk_00[0x20];
    /* 0x20 */ s32 cvoff;
    /* 0x24 */ s16 unk_24;
    /* 0x26 */ s16 ctrlTablen;
    /* 0x28 */ pppCtrlTable ctrlTable[0];
} PppPDataF;

void func_00183AD0(pppPObject* pobj) {
    PppPDataF* pdt = (PppPDataF*)pobj->pdtval->pdt;
    pppCtrlData** cd = (pppCtrlData**)((u8*)pobj + pdt->cvoff);
    pppCtrlTable* ct;
    pppProg* prog;
    s32 i;

    for (i = 0; i < pdt->ctrlTablen; i++) {
        ct = &pdt->ctrlTable[i];
        prog = (pppProg*)ct->prog;
        *cd++ = ct->ctrldt;
        if (prog != NULL && prog->con2Func != NULL) {
            ((void (*)(pppPObject*, pppCtrlTable*))prog->con2Func)(pobj, ct);
        }
    }
}

void func_00183B70(pppPObject* pobj) {
    PppPDataF* pdt = (PppPDataF*)pobj->pdtval->pdt;
    pppCtrlData** cd = (pppCtrlData**)((u8*)pobj + pdt->cvoff);
    pppCtrlTable* ct;
    pppProg* prog;
    s32 i;

    for (i = 0; i < pdt->ctrlTablen; i++) {
        ct = &pdt->ctrlTable[i];
        prog = (pppProg*)ct->prog;
        *cd++ = ct->ctrldt;
        if (prog != NULL && prog->conFunc != NULL) {
            ((void (*)(pppPObject*, pppCtrlTable*))prog->conFunc)(pobj, ct);
        }
    }
}

pppPObject* func_00183C10(ppvmng* m, pppPDataVal* pdv) {
    PppPDataF* pdt = (PppPDataF*)pdv->pdt;
    pppPObject* pobj;
    pppPObject** pp;
    pppPObject* q;
    s16 prio;

    pobj = (pppPObject*)pppDbgAlloc((s32)ppvEnv, pdt->cvoff + pdt->ctrlTablen * 4);
    pobj->appearf = 1;
    pobj->time = 0;
    pobj->lpvert = NULL;
    pobj->lpnorm = NULL;
    pobj->pdtval = pdv;
    pobj->loop_in = 0;
    pobj->loop_start0 = 0;
    q = m->unk_74;
    if (q == NULL) {
        pdv->pobj = pobj;
        m->unk_74 = pobj;
        pobj->next = NULL;
    } else if (pdv->pobj != NULL) {
        pobj->next = pdv->pobj->next;
        pdv->pobj->next = pobj;
    } else {
        prio = pdt->unk_24;
        pp = &m->unk_74;
        do {
            if (((PppPDataF*)q->pdtval->pdt)->unk_24 >= prio) {
                pdv->pobj = pobj;
                *pp = pobj;
                pobj->next = q;
                goto end;
            }
            pp = &q->next;
            q = *pp;
        } while (q != NULL);
        pdv->pobj = pobj;
        *pp = pobj;
        pobj->next = NULL;
    }
end:
    pdv->pobjn++;
    func_00183B70(pobj);
    return pobj;
}


void pppDeletePObject(pppPObject* pobj) {
    pppPDataVal* pdv = pobj->pdtval;
    PppPDataF* pdt = (PppPDataF*)pdv->pdt;
    pppCtrlTable* ct;
    pppProg* prog;
    s32 i;

    for (i = 0; i < pdt->ctrlTablen; i++) {
        ct = &pdt->ctrlTable[i];
        prog = (pppProg*)ct->prog;
        if (prog != NULL && prog->desFunc != NULL) {
            ((void (*)(pppPObject*, pppCtrlTable*))prog->desFunc)(pobj, ct);
        }
    }
    pdv->pobjn--;
    if (pdv->pobjn == 0) {
        pdv->pobj = NULL;
    } else if (pdv->pobj == pobj) {
        pdv->pobj = pobj->next;
    }
    pppFree(ppvEnv, pobj);
}


void pppAllFreePObject(ppvmng* pMng) {
    pppPObject* pObj = pMng->unk_74;
    pppPObject* next;

    if (pObj != NULL) {
        do {
            next = pObj->next;
            pppDeletePObject(pObj);
            pObj = next;
        } while (pObj != NULL);
    }

    pMng->unk_74 = NULL;

    if (pMng->unk_80 != 0) {
        pppFree(ppvEnv, pMng->unk_80);
        pMng->unk_80 = 0;
    }
}
// void pppAllFreePObject(ppvmng* pMng) {
//     pppPObject* pObj = pMng->unk_74;

//     while (pObj != NULL) {
//         pppDeletePObject(pObj);
//         pObj = pObj->next;
//     }

//     pMng->unk_74 = NULL;

//     if (pMng->unk_80 != 0) {
//         pppFree(ppvEnv, pMng->unk_80);
//         pMng->unk_80 = 0;
//     }
// }

void func_00183E78(PppMngU* arg0) {
    if (arg0->unk_94 != 0) {
        *(s32*)(arg0->unk_94 + 0x14) &= ~1;
        *(s32*)(arg0->unk_94 + 0x14) |= 2;
    }
    if (arg0->usef & 1) {
        arg0->usef = (arg0->usef & ~1) | 2;
    }
}

void func_00183EC8(ppvmng* arg0) {
    u8* p = *(u8**)((u8*)arg0 + 0x94);

    if (p != NULL) {
        *(s32*)(p + 0x14) = 0;
        memset(arg0, 0, 0xC0);
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183EF8);

#ifdef VERSION_FM
typedef struct {
    /* 0x00 */ char unk_00[0x54];
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ char unk_5C[0x8];
    /* 0x64 */ s32 num;
    /* 0x68 */ s32 npd;
    /* 0x6C */ char unk_6C[0x4];
    /* 0x70 */ pppPData* unk_70;
    /* 0x74 */ void* unk_74;
    /* 0x78 */ s32* ents;
    /* 0x7C */ s32* pds;
    /* 0x80 */ pppPDataVal* pdv;
    /* 0x84 */ u8 unk_84;
    /* 0x85 */ u8 unk_85;
    /* 0x86 */ char unk_86[0x6];
    /* 0x8C */ pppPEtcData* pEtc;
    /* 0x90 */ char unk_90[0xC];
    /* 0x9C */ s32 unk_9C;
    /* 0xA0 */ char unk_A0[0xC];
    /* 0xAC */ f32 unk_AC;
} PppMngS;

void func_00184298(PppMngS* m, s32* data, s32 arg2) {
    s32* d;
    s32 flag;
    s32* p1;
    s32* p2;
    pppPData* pd;
    pppPDataVal* v;
    u8 i;

    ppvMng = (ppvmng*)m;
    d = data;
    m->unk_54 = *d++;
    flag = *d++;
    p1 = (s32*)((u8*)data + *d++);
    p2 = (s32*)((u8*)data + *d++);
    if (flag & 1) {
        m->unk_84 = 1;
    } else {
        m->unk_84 = 0;
    }
    m->num = *p1++;
    m->ents = p1;
    m->npd = *p2++;
    m->pds = p2;
    if (m->npd != 0) {
        m->pdv = (pppPDataVal*)pppDbgAlloc((s32)ppvEnv, m->npd * 16);
    } else {
        m->pdv = NULL;
    }
    pd = (pppPData*)d;
    if (pd->next != NULL) {
        m->unk_70 = NULL;
    }
    m->unk_58 = 0;
    m->unk_85 = 0;
    m->unk_70 = (m->npd != 0) ? pd : NULL;
    m->unk_74 = NULL;
    v = m->pdv;
    i = 0;
    do {
        v->pdt = pd;
        v->startFrame = pd->startFrameInit;
        v->pobj = NULL;
        v->pobjn = 0;
        v->pdtno = i++;
        pd = pd->next;
        v++;
    } while (pd != NULL);
    if (arg2 != 0) {
        func_00183980((PppFuncList*)m);
    }
    m->unk_9C = 0;
    m->unk_AC = *(f32*)&m->pEtc->wait;
}

#else
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184298);
#endif

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001843E0);

void func_00184500(pppEnvSt* env, s32* src, void* heap, s32 size) {
    ppvEnv = env;
    if (src != NULL) {
        ((s32*)env)[4] = src[5];
        ((s32*)env)[5] = src[6];
        ((s32*)env)[6] = src[7];
    }
    func_00185008(env, heap, size);
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184548);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184728);

pppPObject* func_00183C10(ppvmng*, pppPDataVal*);

void func_00184DB0(ppvmng* m) {
    s32 i;
    pppPDataVal* pdv;
    pppPObject* pobj;

    for (i = 0; i < *(s32*)((u8*)m + 0x68); i++) {
        pdv = &((pppPDataVal*)m->unk_80)[i];
        if (pdv->startFrame <= *(s32*)((u8*)m + 0x58)) {
            pdv->startFrame = 0x7FFFFFFF;
            pobj = func_00183C10(m, pdv);
            pdv->pobj = pobj;
            pobj->appearf = 0;
        }
    }
}


void func_00184E48(ppvmng* pMng) {
    ppvMng = pMng;
    func_001839F0(pMng);
    func_00184DB0(pMng);
    func_00184548(pMng);
}

typedef struct {
    /* 0x00 */ char unk_00[0x54];
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ char unk_60[0x14];
    /* 0x74 */ pppPObject* unk_74;
    /* 0x78 */ char unk_78[0xC];
    /* 0x84 */ u8 unk_84;
    /* 0x85 */ u8 unk_85;
} PppMngT2;

s32 func_00184E80(ppvmng* m) {
    PppMngT2* t = (PppMngT2*)m;
    s32 tm;

    ppvMng = m;
    func_00184728(m);
    func_00183A60(m);
    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return 0;
    }
    tm = t->unk_58;
    t->unk_5C = tm;
    t->unk_58 = tm + 0x1000;
    if (t->unk_84 != 0) {
        if (t->unk_85 != 0) {
            return t->unk_74 == NULL;
        }
        if (tm + 0x1000 > 0x6FFFFFFF) {
            t->unk_58 = 0x70000000;
            t->unk_5C = 0x6FFFF000;
        }
        return 0;
    }
    return tm + 0x1000 >= t->unk_54;
}


typedef struct {
    /* 0x00 */ char unk_00[0x54];
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ char unk_60[0x14];
    /* 0x74 */ void* unk_74;
    /* 0x78 */ char unk_78[0xC];
    /* 0x84 */ u8 unk_84;
    /* 0x85 */ u8 unk_85;
    /* 0x86 */ char unk_86[0x2A];
    /* 0xB0 */ u64 unk_B0;
} PppMngT;

s32 func_00184F60(ppvmng* arg0) {
    PppMngT* m = (PppMngT*)arg0;
    s32 t;

    ppvMng = arg0;
    if (ppvUserStopPartF != 0 || (m->unk_B0 & 0xFF0000FF00)) {
        return 0;
    }
    t = m->unk_58;
    m->unk_5C = t;
    m->unk_58 = t + 0x1000;
    if (m->unk_84 != 0) {
        if (m->unk_85 != 0) {
            return m->unk_74 == NULL;
        }
        if (m->unk_58 > 0x6FFFFFFF) {
            m->unk_58 = 0x70000000;
            m->unk_5C = 0x6FFFF000;
        }
        return 0;
    }
    return m->unk_58 >= m->unk_54;
}


void func_00185000(void) {
}

void func_00185008(pppMemMng* m, pppEMCB* start, s32 size) {
    pppEMCB* b;

    m->effectHeapTop = start;
    m->lastFreeHeap = NULL;
    m->effectHeapBottom = (pppEMCB*)((u8*)start + size - 16);
    start->prev = NULL;
    start->next = m->effectHeapBottom;
    start->owner = 0;
    b = m->effectHeapBottom;
    b->prev = m->effectHeapTop;
    b->owner = 1;
    b->next = NULL;
    m->allocSize = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppAlloc);

typedef struct {
    s32 next;
    s32 prev;
    s32 owner;
    s32 wdummy;
} pppEMCBi;

void pppFree(pppEnvSt* env, void* ptr) {
    pppEMCBi* blk = (pppEMCBi*)ptr - 1;
    pppEMCBi* prev;
    pppEMCBi* next;
    s32* mng = (s32*)&env->heapMng;

    blk->owner = 0;
    mng[0] = (s32)blk;
    mng[3] -= blk->next - (s32)blk;
    prev = (pppEMCBi*)blk->prev;
    if (prev != NULL && prev->owner == 0) {
        prev->next = blk->next;
        ((pppEMCBi*)blk->next)->prev = (s32)prev;
        blk = prev;
    }
    next = (pppEMCBi*)blk->next;
    if (next->owner == 0) {
        blk->next = next->next;
        ((pppEMCBi*)next->next)->prev = (s32)blk;
    }
}

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004887D0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004887D8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004887F0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488808);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488820);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488838);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488850);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488868);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488888);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004888A0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004888B8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004888C0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004888E0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004888F0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488900);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488910);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488920);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488930);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488940);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488950);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488960);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488978);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488988);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488998);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004889A8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004889B8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004889C8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004889D8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004889E8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488A00);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488A18);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488A30);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488A48);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488A60);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488A70);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488A88);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488A98);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488AA8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488AC0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488AD0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488AE0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488AF0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488B00);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488B10);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488B20);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488B30);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488B40);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488B50);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488B60);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488B70);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488B80);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488B90);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488BA0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488BB0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488BC0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488BD0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488BE0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488BF0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488C00);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488C10);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488C20);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488C30);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488C40);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488C50);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488C60);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488C70);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488C80);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488C90);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488CA0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488CB0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488CC0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488CD0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488CE0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488CF0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488D00);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488D10);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488D20);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488D38);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488D48);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488D58);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488D68);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488D78);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488D88);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488D98);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488DA8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488DB8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488DC8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488DD8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488DE8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488DF8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488E08);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488E18);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488E28);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488E38);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488E48);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488E60);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488E70);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488E80);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488E90);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488EA0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488EB0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488EC0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488ED0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488EE0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488EF0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488F00);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488F10);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488F20);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488F30);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488F38);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488F48);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488F58);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488F68);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488F78);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488F88);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488FA8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488FC8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00488FE8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489000);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489010);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489020);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489030);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489040);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489058);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489070);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489088);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489098);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004890B0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004890C8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004890E0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004890F8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489110);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489120);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489130);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489148);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489160);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489178);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489190);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004891A8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004891C0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004891D8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004891E8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489200);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489210);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489220);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489230);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489240);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489250);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489260);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489270);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489280);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489290);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004892A0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004892B0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004892C0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004892D0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004892E0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004892F0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489300);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489310);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489320);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489330);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489340);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489350);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489360);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489370);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489380);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489390);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004893A0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004893B0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004893C0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004893D0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004893E0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004893F0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489400);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489410);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489420);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489430);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489440);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489458);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489468);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489478);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489488);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489498);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004894A8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004894C0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004894D0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004894E0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004894F0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489500);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489510);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489520);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489530);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489540);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489550);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489560);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489570);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489580);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489590);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004895A0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004895B0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004895C0);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004895C8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004895D8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004895E8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004895F8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489608);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489618);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489628);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489638);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489648);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489658);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489668);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489678);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489688);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489698);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004896A8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004896B8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004896C8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004896D8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004896E8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004896F8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489708);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489718);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489728);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489738);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489748);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489758);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489768);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489778);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489788);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_00489798);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004897A8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004897B8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004897C8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004897D8);

INCLUDE_RODATA("asm/nonmatchings/ppp/pppMngr", D_004897E8);
