/**
 * Particle effect ("ppp") manager.
 *
 * Each running effect has a manager (ppvmng, 0xC0 bytes) in ppvMngTbl[0x100]. A manager is created from a DPD file
 * (effect data: an etc. header (pppPEtcData), texture/CLUT images, shapes, RSD models, VSF data and the program data
 * (pppPData) that says which programs (pppProg: ini/sta/calc/end/con/des... functions) run on which objects
 * (pppPObject)). This file sets up the effect heap and render tables, relocates DPD data, uploads textures through a
 * small VRAM cache, creates/deletes effect objects, steps every manager once per frame and draws them sorted by depth.
 *
 * usef (manager flags, from the code here): 1 = in use, 2 = ended, 4 = suspended (objects freed), 8 = set by
 * init_part_mng, 0x20 = skipped by the update loop (probably paused), 0x40 = set/cleared by pppCalcAllPart.
 */
#include "common.h"
#include "ppp.h"
#include "ppp/draw.h"

#include "libgraph.h"

extern s32 D_00370200;

extern void func_0011D1F8(s32, s32, s32);

extern ppvmng ppvMngTbl[];

extern sceVu0FMATRIX D_00615E70;
extern void func_0024EDF0(sceVu0FMATRIX, pppPEtcData*);

extern sceVu0FMATRIX D_002B84F0;

s32 D_0035FE00;

pppModelSt RendModel[128]; // = {};
pppShapeSt RendShape[128]; // = {};
pppVsfSt RendVsf[128];     // = {};
ppvmng D_00360600[0x100];  // = {};

s16 D_0036C5C6[];
#ifdef VERSION_FM
void pppRyjMegaBirthCalc();
void pppRyjMegaBirthModelCalc();

// .data (0x00362730-0x00372708); the program table D_00370200 is at the end of the file
pppModelSt D_00362730[128] = {0};
pppShapeSt D_00363930[128] = {0};
pppVsfSt D_00363D30[128] = {0};
ppvmng ppvMngTbl[0x100] = {0};
s32 D_0036C600 = 0;
// DMA end tag + GIF tag + register data
u64 D_00370140[6] __attribute__((aligned(16))) = {
    0x70000002, 0x0,
    0x1000000000008001ULL, 0xE,
    0x0, 0x3F,
};
u64 D_00370170[8] __attribute__((aligned(16))) = {
    0x70000003, 0x0,
    0x2000000000008001ULL, 0xEE,
    0x31000070, 0x4E,
    0x5, 0x8,
};
u32 D_003701B0[4] = {0};
void* D_003701C0[4] = {pppRyjMegaBirthCalc, pppRyjMegaBirthModelCalc, NULL, NULL};
sceVu0FVECTOR D_003701D0 = {0.0f, 0.0f, 0.0f, 0.0f};
sceVu0IVECTOR D_003701E0 = {0, 0, 0, 0};
sceVu0FVECTOR ppvParScl = {0.0f, 0.0f, 0.0f, 0.0f};
#else
s32 D_0036C600;
#endif

u8 D_00590580[];

s32 ppvCurPrimpLen;
u_long128* ppvPrimp;
s32 ppvPrimpLen;

u_long128 D_00570580;
pppSVECTOR* ppvVertex;

// Sets the GS packet area the effects draw into (NULL: the default area, length 0x20000).
void pppSetPrimPacket(u_long128* primPacketArea, s32 len) {
    if (primPacketArea != NULL) {
        ppvPrimp = primPacketArea;
        ppvPrimpLen = len;
    } else {
        ppvPrimp = &D_00570580;
        ppvPrimpLen = 0x20000;
    }
}

// Starts a draw pass (no vertex buffer yet).
void drawStart(void) {
    ppvVertex = NULL;
}

// Allocates from the effect heap (debug wrapper of pppAlloc).
s32 pppDbgAlloc(s32 arg0, s32 arg1) {
    return pppAlloc(arg0, arg1);
}

// Ends a draw pass: if anything was queued, kicks the ordering table and clears it.
void drawEnd(void) {
    if (ppvCurPrimpLen != 0) {
        op_ot_draw();
        op_otz_init();
    }
}

// Initialises the effect drawing state (draw, GS, ordering table, fog work).
void initGraphicSystem(void) {
    op_init_draw();
    op_gs2_init();
    op_otz_init();
    op_init_fog_work();
}

// Ends every running effect: stops its sound, frees its objects and marks the manager ended.
void pppEndAllPart(void) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (ppvMngTbl[i].usef & 1) {
            pppPEtcData* e = ppvMngTbl[i].pEtc;
            if (e != NULL && *(u16*)&e->seNo != 0) {
                func_0011D1F8(*(u16*)&e->seNo, ppvMngTbl[i].unk_A8, 0x3C);
            }
            pppAllFreePObject(&ppvMngTbl[i]);
            pppEndMng(&ppvMngTbl[i]);
        }
    }
}

// Sets flag 0x20 on every running effect (pppCalcAllPart skips them: probably pause).
void pppPauseAllPart(void) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (ppvMngTbl[i].usef & 1) {
            ppvMngTbl[i].usef |= 0x20;
        }
    }
}

// Clears flag 0x20 on every running effect (undoes pppPauseAllPart).
void pppResumeAllPart(void) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (ppvMngTbl[i].usef & 1) {
            ppvMngTbl[i].usef &= ~0x20;
        }
    }
}

// Sets flag 0x20 on the running effect whose handle (unk_94) is arg0.
void pppPausePart(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if ((ppvMngTbl[i].usef & 1) && ppvMngTbl[i].unk_94 == arg0) {
            ppvMngTbl[i].usef |= 0x20;
            return;
        }
    }
}

// Clears flag 0x20 on the running effect whose handle (unk_94) is arg0.
void pppResumePart(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if ((ppvMngTbl[i].usef & 1) && ppvMngTbl[i].unk_94 == arg0) {
            ppvMngTbl[i].usef &= ~0x20;
            return;
        }
    }
}

// Ends the running effect whose handle is arg0 (sound stopped, objects freed, marked ended).
void pppEndPart(s32 arg0) {
    s32 i;
    s32 off;
    ppvmng *base = ppvMngTbl;
    u8 *p = (u8 *)base + 0x80; // fields through p + offset: the original's loop keeps &tbl[i] + 0x80 in a register

    for (i = 0, off = 0; i < 0x100; i++, p += 0xC0, off += 0xC0) {
        if ((*(u16 *)(p + 6) & 1) && *(s32 *)(p + 0x14) == arg0) {
            pppPEtcData* e = *(pppPEtcData **)(p + 0xC);
            if (*(u16*)&e->seNo != 0) {
                func_0011D1F8(*(u16*)&e->seNo, *(s32*)(p + 0x28), 0x3C);
            }
            off += (s32)base;
            pppAllFreePObject((ppvmng*)off);
            pppEndMng((void *)off);
            return;
        }
    }
}

// Like pppEndAllPart, but clears each manager completely (pppClearMng).
void pppKillAllPart(void) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (ppvMngTbl[i].usef & 1) {
            pppPEtcData* e = ppvMngTbl[i].pEtc;
            if (e != NULL && *(u16*)&e->seNo != 0) {
                func_0011D1F8(*(u16*)&e->seNo, ppvMngTbl[i].unk_A8, 0x3C);
            }
            pppAllFreePObject(&ppvMngTbl[i]);
            pppClearMng(&ppvMngTbl[i]);
        }
    }
}

// Like pppEndPart, but clears the manager completely (pppClearMng).
void pppKillPart(s32 arg0) {
    s32 i;
    s32 off;
    ppvmng *base = ppvMngTbl;
    u8 *p = (u8 *)base + 0x80;

    for (i = 0, off = 0; i < 0x100; i++, p += 0xC0, off += 0xC0) {
        if ((*(u16 *)(p + 6) & 1) && *(s32 *)(p + 0x14) == arg0) {
            pppPEtcData* e = *(pppPEtcData **)(p + 0xC);
            if (*(u16*)&e->seNo != 0) {
                func_0011D1F8(*(u16*)&e->seNo, *(s32*)(p + 0x28), 0x3C);
            }
            off += (s32)base;
            pppAllFreePObject((ppvmng*)off);
            pppClearMng((ppvmng*)off);
            return;
        }
    }
}

// Ends every effect whose DPD data lies in [arg0, arg0 + arg1) (e.g. before that memory is reused).
void pppEndPartInArea(s32 arg0, s32 arg1) {
    s32 i;
    s32 off;
    s32 d;
    ppvmng *base = ppvMngTbl;
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
                pppEndMng((void *)(off + (s32)base));
            }
        }
    }
}

// Like pppEndPartInArea, but clears the managers completely.
void pppKillPartInArea(s32 arg0, s32 arg1) {
    s32 i;
    s32 off;
    s32 d;
    ppvmng *base = ppvMngTbl;
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
                pppClearMng((ppvmng*)(off + (s32)base));
            }
        }
    }
}

// Sets (arg0 != 0) or clears the stop bit 0x80 and unk_B7 of every running effect.
void pppStopAllPart(s32 a0) {
    s32 i;
    for (i = 0; i < 0x100; i++) {
        if (ppvMngTbl[i].usef & 1) {
            if (a0) {
                ppvMngTbl[i].unk_B7 = 1;
                ppvMngTbl[i].stop |= 0x80;
            } else {
                ppvMngTbl[i].unk_B7 = 0;
                ppvMngTbl[i].stop &= 0x7F;
            }
        }
    }
}

// Returns the bone number (pEtc->boneNo) of the effect with handle arg0, or -2 if there is none.
s32 pppGetPartBoneNo(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (ppvMngTbl[i].unk_94 == arg0) {
            return ppvMngTbl[i].pEtc->boneNo;
        }
    }
    return -2;
}

// Moves the texture (TBP) and CLUT (CBP) addresses in an RSD model's packets to the given VRAM blocks.
void dpd_reloc_rsd_texp(u8* rsd, s16* tim, s16 tex, s16 clut) {
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


// Moves the texture (TBP) and CLUT (CBP) addresses in a shape's packets to the given VRAM blocks.
void dpd_reloc_shape_texp(u8* shp, u16* tim, s16 tex, s16 clut) {
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


// Sets up the per-frame matrices (world, screen, screen*world) for drawing effects.
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppSetUp);

// Skips the DPD header's version word.
s32* dpd_h_skip_version(s32* p) {
    return p + 1;
}

// Skips n length-prefixed blocks of a DPD header.
s32* dpd_h_skip_datainfo(s32* p, s32 n) {
    s32 len;
    s32 i;

    for (i = 0; i < n; i++) {
        len = *p++;
        p += len;
    }
    return p;
}

// Points the manager at etc. header number idx of a DPD and records how many texture/CLUT blocks it needs.
void dpd_set_object_etc(s32* dpd, s32 idx, s32* out, ppvmng* m) {
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


// Turns the offsets in a DPD's five pointer tables into addresses (adds the base).
s32* dpd_reloc_tables(s32* arg0, s32 arg1) {
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

// Relocates a loaded DPD file and the program data of each of its effects.
void dpd_reloc(s32* arg0) {
    s32* p;
    s32 n;
    s32 i;

    dpd_reloc_tables(arg0, (s32)arg0);
    p = dpd_h_skip_version(arg0);
    n = *p++;
    for (i = 0; i < n; i++) {
        dpd_reloc_pdata(*p++, &D_00370200);
    }
}

// For every shape the effect uses, moves its texture/CLUT addresses to the manager's VRAM blocks.
s32* dpd_set_shape_texp(s32* p, u8* use, s16 tex, s16 clut) {
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
            dpd_reloc_shape_texp(shp, (u16*)tim, tex, clut);
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


void dpd_reloc_rsd_texp(u8*, s16*, s16, s16);

// For every RSD model the effect uses, moves its texture/CLUT addresses to the manager's VRAM blocks.
s32* dpd_set_rsd_texp(s32* p, u8* use, s16 tex, s16 clut) {
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
            dpd_reloc_rsd_texp(shp, tim, tex, clut);
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


s32* dpd_set_shape_texp(s32*, u8*, s16, s16);
s32* dpd_set_rsd_texp(s32*, u8*, s16, s16);

// Moves the effect's shapes and models to the VRAM blocks the manager got (texpStart/clutpStart).
void dpd_set_object_tex(ppvmng* pMng) {
    s32* p = (s32*)pMng->pchDpd;
    s16 texpStart = pMng->texpStart;
    s16 clutpStart = pMng->clutpStart;

    if (texpStart == 0 && clutpStart == 0) {
        return;
    }
    p = dpd_h_skip_version(p);
    p = dpd_h_skip_datainfo(p, 2);
    p = dpd_set_shape_texp(p, pMng->pEtc->abUseShape, texpStart, clutpStart);
    dpd_set_rsd_texp(p, pMng->pEtc->abUseRsd, texpStart, clutpStart);
}

extern pppShapeSt D_00363930[];

// Registers the shapes the effect uses in the shape table (ppvEnv->lpShape).
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

// Registers the RSD models the effect uses in the model table (ppvEnv->lpModel).
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

// Registers the VSF data the effect uses in the VSF table (ppvEnv->lpVsf).
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


// Registers the effect's shapes, models and VSF data in the render tables.
s32 dpd_set_object_data(ppvmng* pMng) {
    s32* piVar1;
    s16** ppsVar2;

    piVar1 = dpd_h_skip_version(pMng->pchDpd);
    piVar1 = dpd_h_skip_datainfo(piVar1, 2);
    ppsVar2 = dpd_set_shape_data(piVar1, pMng->pEtc->abUseShape);
    ppsVar2 = dpd_set_rsd_data(ppsVar2, pMng->pEtc->abUseRsd);
    return dpd_set_vsf_data(ppsVar2, pMng->pEtc->abUseVsf);
}

// Sets D_0036C600 (read by pppDrawAllPart).
void func_00182110(s32 arg0) {
    D_0036C600 = arg0;
}

// Uploads one texture image to GS memory (VRAM block offset added for relocatable images).
void dpd_load_tim(s16* tim, s16 off) {
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

// Uploads one CLUT (16x16 or 8x2) to GS memory.
void dpd_load_clut(s16* clut, s16 off) {
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

// Uploads the textures the effect uses.
void dpd_load_object_tim(s32* arg0, u8* use, s16 off) {
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
            dpd_load_tim(tim, off);
        }
        bits >>= 1;
    }
}


// Uploads every texture of a DPD.
void dpd_load_all_tim(s32* arg0) {
    s32* p = dpd_h_skip_datainfo(dpd_h_skip_version(arg0), 1);
    s32 n = *p++;
    s32 i;

    for (i = 0; i < n; i++) {
        dpd_load_tim(*p++, 0);
    }
}



// Uploads the CLUTs the effect uses.
void dpd_load_object_clut(s32* arg0, u8* use, s16 off) {
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
            dpd_load_clut(tim, off);
        }
        bits >>= 1;
    }
}


// Uploads every CLUT of a DPD.
void dpd_load_all_clut(s32* arg0) {
    s32* p;
    s32 n;
    s32 i;

    if (arg0 == NULL) {
        return;
    }
    p = dpd_h_skip_datainfo(dpd_h_skip_version(arg0), 1);
    n = *p++;
    for (i = 0; i < n; i++) {
        dpd_load_clut(*p++, 0);
    }
}

// Clears one VRAM cache entry.
void vramcache_clear(_VRAMCACHE* cache) {
    cache->dpd = NULL;
    cache->dpdId = 0;
    cache->blockStart = -1;
    cache->blockNum = 0;
    cache->boolUse = FALSE;
}

// Clears the texture (10) and CLUT (6) VRAM cache entries.
void vramcachemng_clear(_VRAMCACHE_MNG* cacheMng) {
    s32 i;

    for (i = 0; i < 10; i++) {
        vramcache_clear(&cacheMng->vramCacheTex[i]);
    }

    for (i = 0; i < 6; i++) {
        vramcache_clear(&cacheMng->vramCacheClut[i]);
    }
}

// Probably finds or allocates n consecutive VRAM cache blocks for the manager's DPD (first block, or < 0).
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182580);

// Gets texture VRAM blocks for the manager (texpStart = 0x3800 + 128 * block, 0 if none).
void vramcache_texture(_VRAMCACHE_MNG* cacheMng, ppvmng* pMng) {
    s32 lVar1 = func_00182580(cacheMng, 10, pMng, pMng->unk_91);

    if (lVar1 < 0) {
        pMng->texpStart = 0;
    } else {
        pMng->texpStart = (lVar1 << 7) + 0x3800;
    }
}

// Gets CLUT VRAM blocks for the manager (clutpStart = 0x3D40 + 32 * block, 0 if none).
void vramcache_clut(_VRAMCACHE_MNG* cacheMng, ppvmng* pMng) {
    s32 lVar1 = func_00182580(cacheMng->vramCacheClut, 6, pMng, pMng->unk_92);

    if (lVar1 < 0) {
        pMng->clutpStart = 0;
    } else {
        pMng->clutpStart = (lVar1 << 5) + 0x3D40;
    }
}

// Probably the view-clip test of the effect's bounding box (world * view matrix against pEtc).
void func_00182938(ppvmng* arg0) {
    sceVu0FMATRIX m;

    sceVu0MulMatrix(m, D_002B84F0, D_00615E70);
    func_0024EDF0(m, arg0->pEtc);
}

// Adds up the work memory size (pEtc->nWorkMemSize) of every running, not suspended effect.
s32 pppGetAllWorkMemSize(void) {
    ppvmng* p = ppvMngTbl;
    s32 i;
    s32 sum = 0;

    for (i = 0; i < 0x100; i++, p++) {
        if ((p->usef & 1) && !(p->usef & 4)) {
            sum += *(s32*)((u8*)p->pEtc + 0xF0);
        }
    }
    return sum;
}

/* pppSuspendOnePart and pppKillOneTempPart read the managers through this second type (and ppvmng for unk_98): with
   ppvmng for both, GCC strength-reduces the loop differently (24 and 8 bytes longer), so keep the two types. */
typedef struct {
    /* 0x00 */ char unk_00[0x86];
    /* 0x86 */ u16 usef;
    /* 0x88 */ char unk_88[0x4];
    /* 0x8C */ pppPEtcData* pEtc;
    /* 0x90 */ char unk_90[0x30];
} PppMngU;
extern PppMngU ppvMngTblU[] __asm__("ppvMngTbl");

// Suspends the first running effect with unk_98 < arg0: stops its sound, frees its objects, sets flag 4.
s32 pppSuspendOnePart(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if ((ppvMngTblU[i].usef & 1) && !(ppvMngTblU[i].usef & 4) && ((ppvmng*)&ppvMngTblU[i])->unk_98 < arg0) {
            if (*(u16*)&ppvMngTblU[i].pEtc->seNo != 0) {
                func_0011D1F8(*(u16*)&ppvMngTblU[i].pEtc->seNo, *(s32*)((u8*)&ppvMngTblU[i] + 0xA8), 0x3C);
            }
            pppAllFreePObject((ppvmng*)&ppvMngTblU[i]);
            ppvMngTblU[i].usef |= 4;
            return 1;
        }
    }
    return 0;
}


// Clears the first running effect with unk_98 < 0 (sound stopped, objects freed, manager cleared).
s32 pppKillOneTempPart(void) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if ((ppvMngTblU[i].usef & 1) && !(ppvMngTblU[i].usef & 4) && ((ppvmng*)&ppvMngTblU[i])->unk_98 < 0) {
            if (*(u16*)&ppvMngTblU[i].pEtc->seNo != 0) {
                func_0011D1F8(*(u16*)&ppvMngTblU[i].pEtc->seNo, *(s32*)((u8*)&ppvMngTblU[i] + 0xA8), 0x3C);
            }
            pppAllFreePObject((ppvmng*)&ppvMngTblU[i]);
            pppClearMng((ppvmng*)&ppvMngTblU[i]);
            return 1;
        }
    }
    return 0;
}


#ifdef VERSION_FM
// Quicksort of a[left..right] in descending order, swapping b[] (the indices) along.
void pppQuickSortF(f32* a, s32* b, s32 left, s32 right) {
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
        pppQuickSortF(a, b, left, i - 1);
    }
    if (j + 1 < right) {
        pppQuickSortF(a, b, j + 1, right);
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppQuickSortF);
#endif

// Computes each effect's depth and sorts the effects for drawing (pppQuickSortF).
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppSortAllPart);

// Per-frame update of every running effect (sound, render data, program calls, end handling).
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppCalcAllPart);

// Draws every running effect in depth order (VRAM cache, texture upload, DMA of the packets).
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppDrawAllPart);

// Clears a manager and sets its default position, scale and colour (usef = 9).
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

// Finds a free manager in ppvMngTbl, initialises it and returns it through *out.
void pppGetFreeMng(ppvmng **out) {
    ppvmng *p = ppvMngTbl;
    s32 i;
    for (i = 0; i < 0x100; i++) {
        // usef bits 0-1 (in use / ended) tested with one 64-bit load of 0x80..0x87, as the original does
        if (!(*(u64 *)((u8 *)&p[i] + 0x80) & 0x3000000000000)) {
            init_part_mng(&p[i]);
            *out = &p[i];
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
void pppInitHeap(pppMemMng* m, pppEMCB* start, s32 size);

// Initialises the effect system: graphics, heap (0x80000 bytes), render tables, managers, matrices.
void pppInitPartRender(void) {
    s32 i;

    initGraphicSystem();
    ppvUserStopPartF = 0;
    pppInitHeap(&D_00615E40.heapMng, (pppEMCB*)D_00595E40, 0x80000);
    D_00615E40.lpModel = D_00362730;
    D_00615E40.lpShape = D_00363930;
    D_00615E40.lpVsf = D_00363D30;
    ppvEnv = &D_00615E40;
    ppvHookFuncTbl = NULL;
    memset(ppvMngTbl, 0, 0xC000);
    for (i = 255; i >= 0; i--) {
        ppvMngTbl[i].usef = 0;
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

// Sets the world/screen matrices and the eye/at vectors for this frame (the old ones are kept).
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

// Probably converts the frame time step (D_002B8340) for the effect timers.
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001838E8);

// Calls every program's ini function (pppProg.iniFunc) for the manager.
void pppProgIni(ppvmng* arg0) {
    s32 i;

    for (i = 0; i < arg0->progNum; i++) {
        void (*f)(void*) = arg0->progTbl[i]->iniFunc;
        if (f != NULL) {
            f(arg0);
        }
    }
}

// Calls every program's sta function (pppProg.staFunc) for the manager.
void pppProgSta(ppvmng* arg0) {
    s32 i;

    for (i = 0; i < arg0->progNum; i++) {
        void (*f)(void*) = arg0->progTbl[i]->staFunc;
        if (f != NULL) {
            f(arg0);
        }
    }
}

// Calls every program's end function (pppProg.endFunc) for the manager.
void pppProgEnd(ppvmng* arg0) {
    s32 i;

    for (i = 0; i < arg0->progNum; i++) {
        void (*f)(void*) = arg0->progTbl[i]->endFunc;
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

// Points an object's control data at its program data and calls each program's con2 function.
void pppCon2PObject(pppPObject* pobj) {
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

// Points an object's control data at its program data and calls each program's con function.
void pppConPObject(pppPObject* pobj) {
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

// Allocates an effect object for program data pdv, links it into the manager's list by priority and constructs it.
pppPObject* pppCreatePObject(ppvmng* m, pppPDataVal* pdv) {
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
    pppConPObject(pobj);
    return pobj;
}


// Calls each program's des function on the object, unlinks it and frees it.
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


// Deletes every object of the manager and frees its program data values.
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

// Marks a manager ended (usef bit 1 -> 2) and tells its owner through the handle (flags bit 1 -> 2).
void pppEndMng(ppvmng* arg0) {
    if (arg0->unk_94 != 0) {
        *(s32*)(arg0->unk_94 + 0x14) &= ~1;
        *(s32*)(arg0->unk_94 + 0x14) |= 2;
    }
    if (arg0->usef & 1) {
        arg0->usef = (arg0->usef & ~1) | 2;
    }
}

// Clears a manager and its handle's flags.
void pppClearMng(ppvmng* arg0) {
    u8* p = *(u8**)((u8*)arg0 + 0x94);

    if (p != NULL) {
        *(s32*)(p + 0x14) = 0;
        memset(arg0, 0, 0xC0);
    }
}

// Probably builds the effect's base matrix (follows the camera / bone: atan2f, asinf, pppGetRotMatrixXYZ).
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183EF8);

#ifdef VERSION_FM
// Points a manager at an effect's program data: program table, data values, start frames (calls ini if arg2).
void pppSetMngData(ppvmng* m, s32* data, s32 arg2) {
    s32* d;
    s32 flag;
    s32* p1;
    s32* p2;
    pppPData* pd;
    pppPDataVal* v;
    u8 i;

    ppvMng = m;
    d = data;
    m->endTime = *d++;
    flag = *d++;
    p1 = (s32*)((u8*)data + *d++);
    p2 = (s32*)((u8*)data + *d++);
    if (flag & 1) {
        m->loopf = 1;
    } else {
        m->loopf = 0;
    }
    m->progNum = *p1++;
    m->progTbl = (pppProg**)p1;
    m->pdtNum = *p2++;
    m->pdtTbl = p2;
    if (m->pdtNum != 0) {
        m->unk_80 = pppDbgAlloc((s32)ppvEnv, m->pdtNum * 16);
    } else {
        m->unk_80 = 0;
    }
    pd = (pppPData*)d;
    if (pd->next != NULL) {
        m->pdtList = NULL;
    }
    m->time = 0;
    m->endReq = 0;
    m->pdtList = (m->pdtNum != 0) ? pd : NULL;
    m->unk_74 = NULL;
    v = (pppPDataVal*)m->unk_80;
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
        pppProgIni(m);
    }
    m->unk_9C = 0;
    m->waitTime = *(f32*)&m->pEtc->wait;
}

#else
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppSetMngData);
#endif

// Relocates an effect's program data: program numbers become pppProg pointers, offsets become addresses.
void dpd_reloc_pdata(s32 b, s32 progs) {
    s32 *t1;
    s32 *t2;
    s32 n1;
    s32 n2;
    s32 *pd;
    s32 i;
    s32 j;
    s32 k;
    s32 *e;

    b += 0x110;
    t1 = (s32 *)(b + *(s32 *)(b + 8));
    t2 = (s32 *)(b + *(s32 *)(b + 0xC));
    n1 = *t1++;
    n2 = *t2++;
    pd = (s32 *)(b + 0x10);

    if (*pd == 0) {
        return;
    }
    for (;;) {
        *pd = b + *pd;
        for (i = 0; i < *(s16 *)((u8 *)pd + 0x26); i++) {
            e = pd + 10 + i * 4;
            e[0] = progs + e[0] * 0x28;
            e[2] = b + e[2];
            e[3] = b + e[3];
        }
        if (*(s32 *)*pd == 0) {
            *pd = 0;
            break;
        }
        pd = (s32 *)*pd;
    }
    for (j = 0; j < n1; j++) {
        t1[j] = progs + t1[j] * 0x28;
    }
    for (k = 0; k < n2; k++) {
        t2[k] += b;
    }
}

// Makes env the current effect environment, copies three values from src and initialises its heap.
void pppSetEnv(pppEnvSt* env, s32* src, void* heap, s32 size) {
    ppvEnv = env;
    if (src != NULL) {
        ((s32*)env)[4] = src[5];
        ((s32*)env)[5] = src[6];
        ((s32*)env)[6] = src[7];
    }
    pppInitHeap(env, heap, size);
}

// Probably the per-frame calc pass over the manager's objects (calls each program's calc function).
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184548);

// Probably the per-frame pass that runs object timers, loops and deletes finished objects.
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184728);

pppPObject* pppCreatePObject(ppvmng*, pppPDataVal*);

// Creates the objects whose start frame has been reached.
void pppBirthPObject(ppvmng* m) {
    s32 i;
    pppPDataVal* pdv;
    pppPObject* pobj;

    for (i = 0; i < m->pdtNum; i++) {
        pdv = &((pppPDataVal*)m->unk_80)[i];
        if (pdv->startFrame <= m->time) {
            pdv->startFrame = 0x7FFFFFFF;
            pobj = pppCreatePObject(m, pdv);
            pdv->pobj = pobj;
            pobj->appearf = 0;
        }
    }
}


// Runs the start of a manager's frame: sta functions, new objects, calc pass.
void pppCalcMng(ppvmng* pMng) {
    ppvMng = pMng;
    pppProgSta(pMng);
    pppBirthPObject(pMng);
    func_00184548(pMng);
}

// Runs the end of a manager's frame and advances its time by one frame; returns 1 when the effect is over.
s32 pppStepMng(ppvmng* m) {
    s32 tm;

    ppvMng = m;
    func_00184728(m);
    pppProgEnd(m);
    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return 0;
    }
    tm = m->time;
    m->prevTime = tm;
    m->time = tm + 0x1000;
    if (m->loopf != 0) {
        if (m->endReq != 0) {
            return m->unk_74 == NULL;
        }
        if (tm + 0x1000 > 0x6FFFFFFF) {
            m->time = 0x70000000;
            m->prevTime = 0x6FFFF000;
        }
        return 0;
    }
    return tm + 0x1000 >= m->endTime;
}


// Advances a manager's time by one frame without running its programs; returns 1 when the effect is over.
s32 pppStepMngNoCalc(ppvmng* arg0) {
    s32 t;

    ppvMng = arg0;
    // stop (0xB1) and unk_B4 tested with one 64-bit load, as the original does
    if (ppvUserStopPartF != 0 || (*(u64*)&arg0->drawPriority & 0xFF0000FF00)) {
        return 0;
    }
    t = arg0->time;
    arg0->prevTime = t;
    arg0->time = t + 0x1000;
    if (arg0->loopf != 0) {
        if (arg0->endReq != 0) {
            return arg0->unk_74 == NULL;
        }
        if (arg0->time > 0x6FFFFFFF) {
            arg0->time = 0x70000000;
            arg0->prevTime = 0x6FFFF000;
        }
        return 0;
    }
    return arg0->time >= arg0->endTime;
}


// Empty.
void func_00185000(void) {
}

// Initialises the effect heap: one free block from start to start + size - 16 and an end block.
void pppInitHeap(pppMemMng* m, pppEMCB* start, s32 size) {
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

// Allocates a block from the effect heap.
INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppAlloc);

typedef struct {
    s32 next;
    s32 prev;
    s32 owner;
    s32 wdummy;
} pppEMCBi;

// Frees a block of the effect heap and merges it with free neighbours.
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

#ifdef VERSION_FM
void pppKeThResCon();
void pppKeThRes8Con();
void pppKeThRes8x4Con();
void pppKeThRes8x128Con();
void pppKeThRes16Con();
void pppKeThRes16x4Con();
void pppKeThRes16x64Con();
void pppKeThRes24Con();
void pppKeThRes24x4Con();
void pppKeThRes32Con();
void pppKeThRes32x4Con();
void pppKeThRes32x32Con();
void pppKeThRes40Con();
void pppKeThRes40x4Con();
void pppKeThRes48Con();
void pppKeThRes48x4Con();
void pppKeThRes64Con();
void pppKeThRes64x4Con();
void pppKeThRes64x16Con();
void pppKeThRes128Con();
void pppKeThRes128x4Con();
void pppKeThRes128x8Con();
void pppKeThRes255Con();
void pppKeThRes255x4Con();
void pppKeHitBallCalc();
void pppKeHitBallCon();
void pppKeGrvTgtCalc();
void pppKeGrvTgtCon();
void pppAcceleCalc();
void pppAcceleCon();
void pppAngAcceleCalc();
void pppAngAcceleCon();
void pppSclAcceleCalc();
void pppSclAcceleCon();
void pppColAcceleCalc();
void pppColAcceleCon();
void pppEiWfaccCalc();
void pppKeHmgEffCalc();
void pppKeHmgEffCon();
void pppKeGrvEffCalc();
void pppKeGrvEffCon();
void pppKeHitChkPxBCalc();
void pppKeHitChkPxBCon();
void pppMove();
void pppMoveCon();
void pppAngMoveCalc();
void pppAngMoveCon();
void pppSclMoveCalc();
void pppSclMoveCon();
void pppColMoveCalc();
void pppColMoveCon();
void pppPoint();
void pppPointCon();
void pppAngleCalc();
void pppAngleCon();
void pppScaleCalc();
void pppScaleCon();
void pppColorCalc();
void pppColorCon();
void pppPObjPointCalc();
void pppVertexAttendCalc();
void pppEiWindFunCalc();
void pppEiWindFunCon();
void pppKeMvYpEffCalc();
void pppKeDrctCalc();
void pppKeDrctCon();
void pppVtMimeCalc();
void pppVtMimeDraw();
void pppVtMimeCon();
void pppVtMimeCon2();
void pppVtMimeDes();
void pppKeTkFadeDraw();
void pppKeTkFadeCon();
void pppRandFloatCalc();
void pppRandUpFloatCalc();
void pppRandDownFloatCalc();
void pppRandCharCalc();
void pppRandUpCharCalc();
void pppRandDownCharCalc();
void pppRandShortCalc();
void pppRandUpShortCalc();
void pppRandDownShortCalc();
void pppRandIntCalc();
void pppRandUpIntCalc();
void pppRandDownIntCalc();
void pppRandFVCalc();
void pppRandUpFVCalc();
void pppRandDownFVCalc();
void pppRandIVCalc();
void pppRandUpIVCalc();
void pppRandDownIVCalc();
void pppRandCVCalc();
void pppRandUpCVCalc();
void pppRandDownCVCalc();
void pppRandHCVCalc();
void pppRandUpHCVCalc();
void pppRandDownHCVCalc();
void pppSRandFVCalc();
void pppSRandUpFVCalc();
void pppSRandDownFVCalc();
void pppSRandCVCalc();
void pppSRandUpCVCalc();
void pppSRandDownCVCalc();
void pppSRandHCVCalc();
void pppSRandUpHCVCalc();
void pppSRandDownHCVCalc();
void pppSMatrixCalc();
void pppKeMatSNCalc();
void pppKeMatSNCon();
void pppMatrixXYZCalc();
void pppMatrixXZYCalc();
void pppMatrixYZXCalc();
void pppMatrixYXZCalc();
void pppMatrixZXYCalc();
void pppMatrixZYXCalc();
void pppMatrixLocCalc();
void pppMatrixSclCalc();
void pppRyjMatrixNoRotCalc();
void pppKeMatPhtCalc();
void pppRyjMatrixWorldXYZCalc();
void pppRyjMatrixWorldXYZCon();
void pppRyjMatrixWorldXZYCalc();
void pppRyjMatrixWorldXZYCon();
void pppRyjMatrixWorldYXZCalc();
void pppRyjMatrixWorldYXZCon();
void pppRyjMatrixWorldYZXCalc();
void pppRyjMatrixWorldYZXCon();
void pppRyjMatrixWorldZXYCalc();
void pppRyjMatrixWorldZXYCon();
void pppRyjMatrixWorldZYXCalc();
void pppRyjMatrixWorldZYXCon();
void pppParMatrixCalc();
void pppKeParMatRCalc();
void pppChrSclXYZMatrixCalc();
void pppChrSclXZMatrixCalc();
void pppChrSclYMatrixCalc();
void pppChrYSclXYZMatrixCalc();
void pppChrXSclXYZMatrixCalc();
void pppDrawMatrixCalc();
void pppDrawMatrixFrontCalc();
void pppDrawMatrixNoRotCalc();
void pppDrawMatrixWoodCalc();
void pppDrawMatrixWoodSta();
void pppKeDMatCalc();
void pppKeDMatFrCalc();
void pppKeDMatPhtCalc();
void pppKeDMatPhtFrCalc();
void pppRyjDrawMatrixWorldCalc();
void pppRyjDrawMatrixWorldCon();
void pppRyjDrawMatrixWorldFrontCalc();
void pppRyjDrawMatrixWorldFrontCon();
void pppRyjDrawMatrixWorldNoRotCalc();
void pppRyjDrawMatrixWorldNoRotCon();
void pppRyjDrawMatrixWorldWoodCalc();
void pppRyjDrawMatrixWorldWoodCon();
void pppKeZCrctCalc();
void pppKeZCrctShpCalc();
void pppKeThTpCalc();
void pppKeThTpCon();
void pppKeThTp2Con();
void pppKeThSftCalc();
void pppKeThSftCon();
void pppKeThCalc();
void pppKeThDraw();
void pppKeThCon();
void pppKeThCon2();
void pppKeThDes();
void pppDrawMdlDraw();
void pppDrawMdlSemiDraw();
void pppDrawMdlTsCalc();
void pppDrawMdlTsDraw();
void pppDrawMdlTsCon();
void pppDrawMdl2Draw();
void pppDrawMdlSemi2Draw();
void pppDrawMdlTs2Calc();
void pppDrawMdlTs2Draw();
void pppDrawMdlTs2Con();
void pppDrawMdl3Draw();
void pppDrawMdlSemi3Draw();
void pppDrawMdlTs3Calc();
void pppDrawMdlTs3Draw();
void pppDrawMdlTs3Con();
void pppDrawMdlSeaDraw();
void pppDrawMdlSeaCon();
void pppDrawMdlSeaDes();
void pppDrawShapeCalc();
void pppDrawShapeDraw();
void pppDrawShapeCon();
void pppDrawShapeXCalc();
void pppDrawShapeXDraw();
void pppDrawShapeXCon();
void pppDrawShapeFieldDraw();
void pppDrawShapeFieldCon();
void pppDrawShapeFieldDes();
void pppKeMdlBmpDraw();
void pppKeMdlBmpCon();
void pppKeMdlBmpCon2();
void pppKeMdlDttDraw();
void pppKeMdlDttCon();
void pppKeMdlDttCon2();
void pppKeMdlTfdDraw();
void pppKeMdlTfdCon();
void pppKeMdlTfdUvDraw();
void pppKeMdlTfdUvCon();
void pppKeMdlTfd2Draw();
void pppKeMdlTfd2Con();
void pppKeMdlTfdUv2Draw();
void pppKeMdlTfdUv2Con();
void pppKeMdlTfd3Draw();
void pppKeMdlTfd3Con();
void pppKeMdlTfdUv3Draw();
void pppKeMdlTfdUv3Con();
void pppKeShpTailCalc();
void pppKeShpTailDraw();
void pppKeShpTailCon();
void pppKeShpTailXCalc();
void pppKeShpTailXDraw();
void pppKeShpTailXCon();
void pppKeShpTail2Calc();
void pppKeShpTail2Draw();
void pppKeShpTail2Con();
void pppKeShpTail2XCalc();
void pppKeShpTail2XDraw();
void pppKeShpTail2XCon();
void pppKeShpTail3Calc();
void pppKeShpTail3Draw();
void pppKeShpTail3Con();
void pppKeShpTail3Con2();
void pppKeShpTail3XCalc();
void pppKeShpTail3XDraw();
void pppKeShpTail3XCon();
void pppKeShpTail3XCon2();
void pppKeShpTailPhtCalc();
void pppKeShpTailPhtDraw();
void pppKeShpTailPhtCon();
void pppKeShpTailPhtCon2();
void pppKeShpTailLcCalc();
void pppKeShpTailLcDraw();
void pppKeShpTailLcCon();
void pppKeShpDttCalc();
void pppKeShpDttDraw();
void pppKeShpDttCon();
void pppRyjDrawShipolyCalc();
void pppRyjDrawShipolyDraw();
void pppRyjDrawShipolyCon();
void pppRyjDrawShipolyDes();
void pppDrawHookDraw();
void pppPointApCalc();
void pppPointApCon();
void pppPointRApCalc();
void pppPointRApCon();
void pppVertexApCalc();
void pppVertexApCon();
void pppSegmentApCalc();
void pppFaceApCalc();
void pppVertexApLcCalc();
void pppVertexApLcCon();
void pppVertexApAtCalc();
void pppVertexApAtCon();
void pppKeBornRndCalc();
void pppKeBornRndCon();
void pppKeBornRnd2Calc();
void pppKeBornRnd2Con();
void pppKeBornRnd3Calc();
void pppKeBornRnd3Con();
void pppKeBornRnd4Calc();
void pppKeBornRnd4Con();
void pppKeBornRnd5Calc();
void pppKeBornRnd5Con();
void pppKeBornRnd6Calc();
void pppKeBornRnd6Con();
void pppKeBornPtCmplCalc();
void pppKeBornPtCmplCon();
void pppKeHitBornCalc();
void pppKeHitBornCon();
void pppKeThHitBornCalc();
void pppKeThHitBornCon();
void pppKeLnsLpSftCalc();
void pppKeLnsLpSftCon();
void pppKeLnsLpDraw();
void pppKeLnsLpCon();
void pppKeLnsLpCon2();
void pppKeLnsArndDraw();
void pppKeLnsArndCon();
void pppKeLnsClmDraw();
void pppKeLnsClmCon();
void pppKeLnsCrnDraw();
void pppKeLnsCrnCon();
void pppKeLnsFlsDraw();
void pppKeLnsFlsCon();
void pppKeAcmSolidEnd();
void pppKeThLzCalc();
void pppKeThLzCon();
void pppKeThLzDes();
void pppKeThCpCalc();
void pppKeThCpCon();
void pppKeThCpDes();
void pppKeThCpSftCalc();
void pppKeAccSpdSvCalc();
void pppKeAccSpdSvCon();
void pppRyjDrawShipolyBoneCalc();
void pppRyjDrawShipolyBoneDraw();
void pppRyjDrawShipolyBoneCon();
void pppRyjDrawShipolyBoneDes();
void pppRyjMegaBirthCalc();
void pppRyjMegaBirthDraw();
void pppRyjMegaBirthCon();
void pppRyjMegaBirthDes();
void pppRyjMngFlagCalc();
void pppRyjMegaBirthPrizeDraw();
void pppRyjMegaBirthPrizeCon();
void pppRyjMegaPlaceCalc();
void pppRyjMegaPlaceDraw();
void pppRyjMegaPlaceCon();
void pppRyjMegaPlaceDes();
void pppRyjMegaPlaceShapeCalc();
void pppRyjMegaPlaceShapeCon();
void pppRyjMegaPlaceModelCalc();
void pppRyjMegaPlaceModelCon();
void pppRyjMegaPlaceLampCalc();
void pppRyjMegaPlaceLampCon();
void pppRyjMegaBirthModelCalc();
void pppRyjMegaBirthModelDraw();
void pppRyjMegaBirthModelCon();
void pppRyjMegaBirthModelDes();
void pppRyjDrawKekotoCalc();
void pppRyjDrawKekotoDraw();
void pppRyjDrawKekotoCon();
void pppMoveLoopCalc();
void pppMoveLoopCon();
void pppMoveLoopCon2();
void pppAngMoveLoopCalc();
void pppAngMoveLoopCon();
void pppAngMoveLoopCon2();
void pppSclMoveLoopCalc();
void pppSclMoveLoopCon();
void pppSclMoveLoopCon2();
void pppPointLoopCalc();
void pppPointLoopCon();
void pppPointLoopCon2();
void pppAngleLoopCalc();
void pppAngleLoopCon();
void pppAngleLoopCon2();
void pppScaleLoopCalc();
void pppScaleLoopCon();
void pppScaleLoopCon2();
void pppMatrixLoopCalc();
void pppDrawMatrixLoopCalc();
void pppDrawMdlLoopCalc();
void pppDrawMdlLoopDraw();
void pppDrawMdlLoopCon();
void pppDrawMdlLoopCon2();
void pppDrawMdlLoopDes();
void pppDrawMdlLoopZCalc();
void pppDrawMdlLoopZDraw();
void pppDrawMdlLoopZCon();
void pppDrawMdlLoopZCon2();
void pppDrawMdlLoopZDes();
void pppRyjLightCalc();
void pppRyjLightCon();
void pppRyjLightDes();
void pppKeLnsLpTDraw();
void pppKeLnsLpTCon();
void pppKeLnsLpTCon2();
void pppKeLnsLpTDes();
void pppKeLnsArndTDraw();
void pppKeLnsArndTCon();
void pppKeLnsArndTDes();
void pppKeLnsClmTDraw();
void pppKeLnsClmTCon();
void pppKeLnsClmTDes();
void pppKeLnsCrnTDraw();
void pppKeLnsCrnTCon();
void pppKeLnsCrnTDes();
void pppKeLnsFlsTDraw();
void pppKeLnsFlsTCon();
void pppKeLnsFlsTDes();
void pppRyjDrawMatrixWorldDttCalc();
void pppRyjDrawMatrixWorldDttCon();
void pppRyjDrawMatrixWorldDttFrCalc();
void pppRyjDrawMatrixWorldDttFrCon();
void pppRyjMegaBirthFilterCalc();
void pppRyjMegaBirthFilterDraw();
void pppRyjMegaBirthFilterSta();
void pppRyjMegaBirthFilterCon();
void pppRyjMegaBirthFilterDes();
void pppRyjMegaBirthModelFilterCalc();
void pppRyjMegaBirthModelFilterDraw();
void pppRyjMegaBirthModelFilterSta();
void pppRyjMegaBirthModelFilterCon();
void pppRyjMegaBirthModelFilterDes();
void pppMatrixLoopXYZCalc();
void pppMatrixLoopXZYCalc();
void pppMatrixLoopYXZCalc();
void pppMatrixLoopYZXCalc();
void pppMatrixLoopZXYCalc();
void pppMatrixLoopZYXCalc();

// The effect program table: name and handlers of each program (ppp/*Prog). Its names are the last part of this
// file's .rodata (gcc puts an initializer's strings out last first).
typedef struct {
    /* 0x00 */ char* name;
    /* 0x04 */ void* calc;
    /* 0x08 */ void* unk_08;
    /* 0x0C */ void* draw;
    /* 0x10 */ void* unk_10;
    /* 0x14 */ void* sta;
    /* 0x18 */ void* end;
    /* 0x1C */ void* con;
    /* 0x20 */ void* con2;
    /* 0x24 */ void* des;
} PppProgEnt; // size = 0x28

PppProgEnt D_00370200_t[237] __asm__("D_00370200") = {
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDummyFunc", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppKeThRes", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThResCon, NULL, NULL},
    {"pppKeThRes8", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes8Con, NULL, NULL},
    {"pppKeThRes8x4", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes8x4Con, NULL, NULL},
    {"pppKeThRes8x128", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes8x128Con, NULL, NULL},
    {"pppKeThRes16", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes16Con, NULL, NULL},
    {"pppKeThRes16x4", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes16x4Con, NULL, NULL},
    {"pppKeThRes16x64", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes16x64Con, NULL, NULL},
    {"pppKeThRes24", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes24Con, NULL, NULL},
    {"pppKeThRes24x4", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes24x4Con, NULL, NULL},
    {"pppKeThRes32", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes32Con, NULL, NULL},
    {"pppKeThRes32x4", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes32x4Con, NULL, NULL},
    {"pppKeThRes32x32", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes32x32Con, NULL, NULL},
    {"pppKeThRes40", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes40Con, NULL, NULL},
    {"pppKeThRes40x4", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes40x4Con, NULL, NULL},
    {"pppKeThRes48", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes48Con, NULL, NULL},
    {"pppKeThRes48x4", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes48x4Con, NULL, NULL},
    {"pppKeThRes64", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes64Con, NULL, NULL},
    {"pppKeThRes64x4", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes64x4Con, NULL, NULL},
    {"pppKeThRes64x16", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes64x16Con, NULL, NULL},
    {"pppKeThRes128", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes128Con, NULL, NULL},
    {"pppKeThRes128x4", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes128x4Con, NULL, NULL},
    {"pppKeThRes128x8", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes128x8Con, NULL, NULL},
    {"pppKeThRes255", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes255Con, NULL, NULL},
    {"pppKeThRes255x4", NULL, NULL, NULL, NULL, NULL, NULL, pppKeThRes255x4Con, NULL, NULL},
    {"pppKeHitBall", pppKeHitBallCalc, NULL, NULL, NULL, NULL, NULL, pppKeHitBallCon, NULL, NULL},
    {"pppKeGrvTgt", pppKeGrvTgtCalc, NULL, NULL, NULL, NULL, NULL, pppKeGrvTgtCon, NULL, NULL},
    {"pppAccele", pppAcceleCalc, NULL, NULL, NULL, NULL, NULL, pppAcceleCon, pppAcceleCon, NULL},
    {"pppAngAccele", pppAngAcceleCalc, NULL, NULL, NULL, NULL, NULL, pppAngAcceleCon, pppAngAcceleCon, NULL},
    {"pppSclAccele", pppSclAcceleCalc, NULL, NULL, NULL, NULL, NULL, pppSclAcceleCon, pppSclAcceleCon, NULL},
    {"pppColAccele", pppColAcceleCalc, NULL, NULL, NULL, NULL, NULL, pppColAcceleCon, pppColAcceleCon, NULL},
    {"pppEiWfacc", pppEiWfaccCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppKeHmgEff", pppKeHmgEffCalc, NULL, NULL, NULL, NULL, NULL, pppKeHmgEffCon, NULL, NULL},
    {"pppKeGrvEff", pppKeGrvEffCalc, NULL, NULL, NULL, NULL, NULL, pppKeGrvEffCon, NULL, NULL},
    {"pppKeHitChkPxB", pppKeHitChkPxBCalc, NULL, NULL, NULL, NULL, NULL, pppKeHitChkPxBCon, NULL, NULL},
    {"pppMove", pppMove, NULL, NULL, NULL, NULL, NULL, pppMoveCon, pppMoveCon, NULL},
    {"pppAngMove", pppAngMoveCalc, NULL, NULL, NULL, NULL, NULL, pppAngMoveCon, pppAngMoveCon, NULL},
    {"pppSclMove", pppSclMoveCalc, NULL, NULL, NULL, NULL, NULL, pppSclMoveCon, pppSclMoveCon, NULL},
    {"pppColMove", pppColMoveCalc, NULL, NULL, NULL, NULL, NULL, pppColMoveCon, pppColMoveCon, NULL},
    {"pppPoint", pppPoint, NULL, NULL, NULL, NULL, NULL, pppPointCon, pppPointCon, NULL},
    {"pppAngle", pppAngleCalc, NULL, NULL, NULL, NULL, NULL, pppAngleCon, pppAngleCon, NULL},
    {"pppScale", pppScaleCalc, NULL, NULL, NULL, NULL, NULL, pppScaleCon, pppScaleCon, NULL},
    {"pppColor", pppColorCalc, NULL, NULL, NULL, NULL, NULL, pppColorCon, pppColorCon, NULL},
    {"pppPObjPoint", pppPObjPointCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppVertexAttend", pppVertexAttendCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppEiWindFun", pppEiWindFunCalc, NULL, NULL, NULL, NULL, NULL, pppEiWindFunCon, NULL, NULL},
    {"pppKeMvYpEff", pppKeMvYpEffCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppKeDrct", pppKeDrctCalc, NULL, NULL, NULL, NULL, NULL, pppKeDrctCon, NULL, NULL},
    {"pppVtMime", pppVtMimeCalc, NULL, pppVtMimeDraw, NULL, NULL, NULL, pppVtMimeCon, pppVtMimeCon2, pppVtMimeDes},
    {"pppKeTkFade", NULL, NULL, pppKeTkFadeDraw, NULL, NULL, NULL, pppKeTkFadeCon, pppKeTkFadeCon, NULL},
    {"pppRandFloat", pppRandFloatCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandUpFloat", pppRandUpFloatCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandDownFloat", pppRandDownFloatCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandChar", pppRandCharCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandUpChar", pppRandUpCharCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandDownChar", pppRandDownCharCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandShort", pppRandShortCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandUpShort", pppRandUpShortCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandDownShort", pppRandDownShortCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandInt", pppRandIntCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandUpInt", pppRandUpIntCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandDownInt", pppRandDownIntCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandFV", pppRandFVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandUpFV", pppRandUpFVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandDownFV", pppRandDownFVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandIV", pppRandIVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandUpIV", pppRandUpIVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandDownIV", pppRandDownIVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandCV", pppRandCVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandUpCV", pppRandUpCVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandDownCV", pppRandDownCVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandHCV", pppRandHCVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandUpHCV", pppRandUpHCVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRandDownHCV", pppRandDownHCVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppSRandFV", pppSRandFVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppSRandUpFV", pppSRandUpFVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppSRandDownFV", pppSRandDownFVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppSRandCV", pppSRandCVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppSRandUpCV", pppSRandUpCVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppSRandDownCV", pppSRandDownCVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppSRandHCV", pppSRandHCVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppSRandUpHCV", pppSRandUpHCVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppSRandDownHCV", pppSRandDownHCVCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppSMatrix", pppSMatrixCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppKeMatSN", pppKeMatSNCalc, NULL, NULL, NULL, NULL, NULL, pppKeMatSNCon, NULL, NULL},
    {"pppMatrix", pppMatrixXYZCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixXYZ", pppMatrixXYZCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixXZY", pppMatrixXZYCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixYZX", pppMatrixYZXCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixYXZ", pppMatrixYXZCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixZXY", pppMatrixZXYCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixZYX", pppMatrixZYXCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixLoc", pppMatrixLocCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixScl", pppMatrixSclCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixFront", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRyjMatrixNoRot", pppRyjMatrixNoRotCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppKeMatPht", pppKeMatPhtCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRyjMatrixWorld", pppRyjMatrixWorldXYZCalc, NULL, NULL, NULL, NULL, NULL, pppRyjMatrixWorldXYZCon, NULL, NULL},
    {"pppRyjMatrixWorldXYZ", pppRyjMatrixWorldXYZCalc, NULL, NULL, NULL, NULL, NULL, pppRyjMatrixWorldXYZCon, NULL, NULL},
    {"pppRyjMatrixWorldXZY", pppRyjMatrixWorldXZYCalc, NULL, NULL, NULL, NULL, NULL, pppRyjMatrixWorldXZYCon, NULL, NULL},
    {"pppRyjMatrixWorldYXZ", pppRyjMatrixWorldYXZCalc, NULL, NULL, NULL, NULL, NULL, pppRyjMatrixWorldYXZCon, NULL, NULL},
    {"pppRyjMatrixWorldYZX", pppRyjMatrixWorldYZXCalc, NULL, NULL, NULL, NULL, NULL, pppRyjMatrixWorldYZXCon, NULL, NULL},
    {"pppRyjMatrixWorldZXY", pppRyjMatrixWorldZXYCalc, NULL, NULL, NULL, NULL, NULL, pppRyjMatrixWorldZXYCon, NULL, NULL},
    {"pppRyjMatrixWorldZYX", pppRyjMatrixWorldZYXCalc, NULL, NULL, NULL, NULL, NULL, pppRyjMatrixWorldZYXCon, NULL, NULL},
    {"pppParMatrix", pppParMatrixCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppKeParMatR", pppKeParMatRCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppChrSclXYZMatrix", pppChrSclXYZMatrixCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppChrSclXZMatrix", pppChrSclXZMatrixCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppChrSclYMatrix", pppChrSclYMatrixCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppChrYSclXYZMatrix", pppChrYSclXYZMatrixCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppChrXSclXYZMatrix", pppChrXSclXYZMatrixCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDrawMatrix", pppDrawMatrixCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDrawMatrixFront", pppDrawMatrixFrontCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDrawMatrixNoRot", pppDrawMatrixNoRotCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDrawMatrixWood", pppDrawMatrixWoodCalc, NULL, NULL, NULL, pppDrawMatrixWoodSta, NULL, NULL, NULL, NULL},
    {"pppKeDMat", pppKeDMatCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppKeDMatFr", pppKeDMatFrCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppKeDMatPht", pppKeDMatPhtCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppKeDMatPhtFr", pppKeDMatPhtFrCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRyjDrawMatrixWorld", pppRyjDrawMatrixWorldCalc, NULL, NULL, NULL, NULL, NULL, pppRyjDrawMatrixWorldCon, NULL, NULL},
    {"pppRyjDrawMatrixWorldFront", pppRyjDrawMatrixWorldFrontCalc, NULL, NULL, NULL, NULL, NULL, pppRyjDrawMatrixWorldFrontCon, NULL, NULL},
    {"pppRyjDrawMatrixWorldNoRot", pppRyjDrawMatrixWorldNoRotCalc, NULL, NULL, NULL, NULL, NULL, pppRyjDrawMatrixWorldNoRotCon, NULL, NULL},
    {"pppRyjDrawMatrixWorldWood", pppRyjDrawMatrixWorldWoodCalc, NULL, NULL, NULL, NULL, NULL, pppRyjDrawMatrixWorldWoodCon, NULL, NULL},
    {"pppKeZCrct", pppKeZCrctCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppKeZCrctShp", pppKeZCrctShpCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppKeThTp", pppKeThTpCalc, NULL, NULL, NULL, NULL, NULL, pppKeThTpCon, NULL, NULL},
    {"pppKeThTp2", pppKeThTpCalc, NULL, NULL, NULL, NULL, NULL, pppKeThTp2Con, NULL, NULL},
    {"pppKeThSft", pppKeThSftCalc, NULL, NULL, NULL, NULL, NULL, pppKeThSftCon, pppKeThSftCon, NULL},
    {"pppKeTh", pppKeThCalc, NULL, pppKeThDraw, NULL, NULL, NULL, pppKeThCon, pppKeThCon2, pppKeThDes},
    {"pppDrawMdlBS", NULL, NULL, pppDrawMdlDraw, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDrawMdl", NULL, NULL, pppDrawMdlDraw, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDrawMdlSemi", NULL, NULL, pppDrawMdlSemiDraw, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDrawMdlTs", pppDrawMdlTsCalc, NULL, pppDrawMdlTsDraw, NULL, NULL, NULL, pppDrawMdlTsCon, pppDrawMdlTsCon, NULL},
    {"pppDrawMdl2", NULL, NULL, pppDrawMdl2Draw, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDrawMdlSemi2", NULL, NULL, pppDrawMdlSemi2Draw, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDrawMdlTs2", pppDrawMdlTs2Calc, NULL, pppDrawMdlTs2Draw, NULL, NULL, NULL, pppDrawMdlTs2Con, pppDrawMdlTs2Con, NULL},
    {"pppDrawMdl3", NULL, NULL, pppDrawMdl3Draw, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDrawMdlSemi3", NULL, NULL, pppDrawMdlSemi3Draw, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDrawMdlTs3", pppDrawMdlTs3Calc, NULL, pppDrawMdlTs3Draw, NULL, NULL, NULL, pppDrawMdlTs3Con, pppDrawMdlTs3Con, NULL},
    {"pppDrawMdlSea", NULL, NULL, pppDrawMdlSeaDraw, NULL, NULL, NULL, pppDrawMdlSeaCon, NULL, pppDrawMdlSeaDes},
    {"pppDrawShape", pppDrawShapeCalc, NULL, pppDrawShapeDraw, NULL, NULL, NULL, pppDrawShapeCon, pppDrawShapeCon, NULL},
    {"pppDrawShapeX", pppDrawShapeXCalc, NULL, pppDrawShapeXDraw, NULL, NULL, NULL, pppDrawShapeXCon, pppDrawShapeXCon, NULL},
    {"pppDrawShapeField", NULL, NULL, pppDrawShapeFieldDraw, NULL, NULL, NULL, pppDrawShapeFieldCon, NULL, pppDrawShapeFieldDes},
    {"pppKeMdlBmp", NULL, NULL, pppKeMdlBmpDraw, NULL, NULL, NULL, pppKeMdlBmpCon, pppKeMdlBmpCon2, NULL},
    {"pppKeMdlDtt", NULL, NULL, pppKeMdlDttDraw, NULL, NULL, NULL, pppKeMdlDttCon, pppKeMdlDttCon2, NULL},
    {"pppKeMdlTfd", NULL, NULL, pppKeMdlTfdDraw, NULL, NULL, NULL, pppKeMdlTfdCon, NULL, NULL},
    {"pppKeMdlTfdUv", NULL, NULL, pppKeMdlTfdUvDraw, NULL, NULL, NULL, pppKeMdlTfdUvCon, NULL, NULL},
    {"pppKeMdlTfd2", NULL, NULL, pppKeMdlTfd2Draw, NULL, NULL, NULL, pppKeMdlTfd2Con, NULL, NULL},
    {"pppKeMdlTfdUv2", NULL, NULL, pppKeMdlTfdUv2Draw, NULL, NULL, NULL, pppKeMdlTfdUv2Con, NULL, NULL},
    {"pppKeMdlTfd3", NULL, NULL, pppKeMdlTfd3Draw, NULL, NULL, NULL, pppKeMdlTfd3Con, NULL, NULL},
    {"pppKeMdlTfdUv3", NULL, NULL, pppKeMdlTfdUv3Draw, NULL, NULL, NULL, pppKeMdlTfdUv3Con, NULL, NULL},
    {"pppKeShpTail", pppKeShpTailCalc, NULL, pppKeShpTailDraw, NULL, NULL, NULL, pppKeShpTailCon, NULL, NULL},
    {"pppKeShpTailX", pppKeShpTailXCalc, NULL, pppKeShpTailXDraw, NULL, NULL, NULL, pppKeShpTailXCon, NULL, NULL},
    {"pppKeShpTail2", pppKeShpTail2Calc, NULL, pppKeShpTail2Draw, NULL, NULL, NULL, pppKeShpTail2Con, NULL, NULL},
    {"pppKeShpTail2X", pppKeShpTail2XCalc, NULL, pppKeShpTail2XDraw, NULL, NULL, NULL, pppKeShpTail2XCon, NULL, NULL},
    {"pppKeShpTail3", pppKeShpTail3Calc, NULL, pppKeShpTail3Draw, NULL, NULL, NULL, pppKeShpTail3Con, pppKeShpTail3Con2, NULL},
    {"pppKeShpTail3X", pppKeShpTail3XCalc, NULL, pppKeShpTail3XDraw, NULL, NULL, NULL, pppKeShpTail3XCon, pppKeShpTail3XCon2, NULL},
    {"pppKeShpTailPht", pppKeShpTailPhtCalc, NULL, pppKeShpTailPhtDraw, NULL, NULL, NULL, pppKeShpTailPhtCon, pppKeShpTailPhtCon2, NULL},
    {"pppKeShpTailLc", pppKeShpTailLcCalc, NULL, pppKeShpTailLcDraw, NULL, NULL, NULL, pppKeShpTailLcCon, NULL, NULL},
    {"pppKeShpDtt", pppKeShpDttCalc, NULL, pppKeShpDttDraw, NULL, NULL, NULL, pppKeShpDttCon, pppKeShpDttCon, NULL},
    {"pppRyjDrawShipoly", pppRyjDrawShipolyCalc, NULL, pppRyjDrawShipolyDraw, NULL, NULL, NULL, pppRyjDrawShipolyCon, NULL, pppRyjDrawShipolyDes},
    {"pppDrawHook", NULL, NULL, pppDrawHookDraw, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppSDMatrix", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppSCMatrix", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppWMatrix", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppWMatrixXYZ", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppWMatrixXZY", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppWMatrixYZX", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppWMatrixYXZ", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppWMatrixZXY", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppWMatrixZYX", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppPointAp", pppPointApCalc, NULL, NULL, NULL, NULL, NULL, pppPointApCon, NULL, NULL},
    {"pppPointRAp", pppPointRApCalc, NULL, NULL, NULL, NULL, NULL, pppPointRApCon, NULL, NULL},
    {"pppVertexAp", pppVertexApCalc, NULL, NULL, NULL, NULL, NULL, pppVertexApCon, NULL, NULL},
    {"pppSegmentAp", pppSegmentApCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppFaceAp", pppFaceApCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppVertexApLc", pppVertexApLcCalc, NULL, NULL, NULL, NULL, NULL, pppVertexApLcCon, pppVertexApLcCon, NULL},
    {"pppVertexApAt", pppVertexApAtCalc, NULL, NULL, NULL, NULL, NULL, pppVertexApAtCon, pppVertexApAtCon, NULL},
    {"pppKeBornRnd", pppKeBornRndCalc, NULL, NULL, NULL, NULL, NULL, pppKeBornRndCon, NULL, NULL},
    {"pppKeBornRnd2", pppKeBornRnd2Calc, NULL, NULL, NULL, NULL, NULL, pppKeBornRnd2Con, NULL, NULL},
    {"pppKeBornRnd3", pppKeBornRnd3Calc, NULL, NULL, NULL, NULL, NULL, pppKeBornRnd3Con, NULL, NULL},
    {"pppKeBornRnd4", pppKeBornRnd4Calc, NULL, NULL, NULL, NULL, NULL, pppKeBornRnd4Con, NULL, NULL},
    {"pppKeBornRnd5", pppKeBornRnd5Calc, NULL, NULL, NULL, NULL, NULL, pppKeBornRnd5Con, NULL, NULL},
    {"pppKeBornRnd6", pppKeBornRnd6Calc, NULL, NULL, NULL, NULL, NULL, pppKeBornRnd6Con, NULL, NULL},
    {"pppKeBornPtCmpl", pppKeBornPtCmplCalc, NULL, NULL, NULL, NULL, NULL, pppKeBornPtCmplCon, NULL, NULL},
    {"pppKeHitBorn", pppKeHitBornCalc, NULL, NULL, NULL, NULL, NULL, pppKeHitBornCon, NULL, NULL},
    {"pppKeThHitBorn", pppKeThHitBornCalc, NULL, NULL, NULL, NULL, NULL, pppKeThHitBornCon, NULL, NULL},
    {"pppKeLnsLpSft", pppKeLnsLpSftCalc, NULL, NULL, NULL, NULL, NULL, pppKeLnsLpSftCon, pppKeLnsLpSftCon, NULL},
    {"pppKeLnsLp", NULL, NULL, pppKeLnsLpDraw, NULL, NULL, NULL, pppKeLnsLpCon, pppKeLnsLpCon2, NULL},
    {"pppKeLnsArnd", NULL, NULL, pppKeLnsArndDraw, NULL, NULL, NULL, pppKeLnsArndCon, NULL, NULL},
    {"pppKeLnsClm", NULL, NULL, pppKeLnsClmDraw, NULL, NULL, NULL, pppKeLnsClmCon, NULL, NULL},
    {"pppKeLnsCrn", NULL, NULL, pppKeLnsCrnDraw, NULL, NULL, NULL, pppKeLnsCrnCon, NULL, NULL},
    {"pppKeLnsFls", NULL, NULL, pppKeLnsFlsDraw, NULL, NULL, NULL, pppKeLnsFlsCon, NULL, NULL},
    {"pppKeAcmSolid", NULL, NULL, NULL, NULL, NULL, pppKeAcmSolidEnd, NULL, NULL, NULL},
    {"pppKeHitChk", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppKeThLz", pppKeThLzCalc, NULL, NULL, NULL, NULL, NULL, pppKeThLzCon, NULL, pppKeThLzDes},
    {"pppKeThCp", pppKeThCpCalc, NULL, NULL, NULL, NULL, NULL, pppKeThCpCon, NULL, pppKeThCpDes},
    {"pppKeThCpSft", pppKeThCpSftCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppKeAccSpdSv", pppKeAccSpdSvCalc, NULL, NULL, NULL, NULL, NULL, pppKeAccSpdSvCon, NULL, NULL},
    {"pppRyjDrawShipolyBone", pppRyjDrawShipolyBoneCalc, NULL, pppRyjDrawShipolyBoneDraw, NULL, NULL, NULL, pppRyjDrawShipolyBoneCon, NULL, pppRyjDrawShipolyBoneDes},
    {"pppRyjMegaBirth", pppRyjMegaBirthCalc, NULL, pppRyjMegaBirthDraw, NULL, NULL, NULL, pppRyjMegaBirthCon, NULL, pppRyjMegaBirthDes},
    {"pppRyjMngFlag", pppRyjMngFlagCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppRyjMegaBirthPrize", NULL, NULL, pppRyjMegaBirthPrizeDraw, NULL, NULL, NULL, pppRyjMegaBirthPrizeCon, NULL, NULL},
    {"pppRyjMegaPlace", pppRyjMegaPlaceCalc, NULL, pppRyjMegaPlaceDraw, NULL, NULL, NULL, pppRyjMegaPlaceCon, NULL, pppRyjMegaPlaceDes},
    {"pppRyjMegaPlaceShape", pppRyjMegaPlaceShapeCalc, NULL, NULL, NULL, NULL, NULL, pppRyjMegaPlaceShapeCon, NULL, NULL},
    {"pppRyjMegaPlaceModel", pppRyjMegaPlaceModelCalc, NULL, NULL, NULL, NULL, NULL, pppRyjMegaPlaceModelCon, NULL, NULL},
    {"pppRyjMegaPlaceLamp", pppRyjMegaPlaceLampCalc, NULL, NULL, NULL, NULL, NULL, pppRyjMegaPlaceLampCon, NULL, NULL},
    {"pppRyjMegaBirthModel", pppRyjMegaBirthModelCalc, NULL, pppRyjMegaBirthModelDraw, NULL, NULL, NULL, pppRyjMegaBirthModelCon, NULL, pppRyjMegaBirthModelDes},
    {"pppRyjDrawKekoto", pppRyjDrawKekotoCalc, NULL, pppRyjDrawKekotoDraw, NULL, NULL, NULL, pppRyjDrawKekotoCon, NULL, NULL},
    {"pppMoveLoop", pppMoveLoopCalc, NULL, NULL, NULL, NULL, NULL, pppMoveLoopCon, pppMoveLoopCon2, NULL},
    {"pppAngMoveLoop", pppAngMoveLoopCalc, NULL, NULL, NULL, NULL, NULL, pppAngMoveLoopCon, pppAngMoveLoopCon2, NULL},
    {"pppSclMoveLoop", pppSclMoveLoopCalc, NULL, NULL, NULL, NULL, NULL, pppSclMoveLoopCon, pppSclMoveLoopCon2, NULL},
    {"pppPointLoop", pppPointLoopCalc, NULL, NULL, NULL, NULL, NULL, pppPointLoopCon, pppPointLoopCon2, NULL},
    {"pppAngleLoop", pppAngleLoopCalc, NULL, NULL, NULL, NULL, NULL, pppAngleLoopCon, pppAngleLoopCon2, NULL},
    {"pppScaleLoop", pppScaleLoopCalc, NULL, NULL, NULL, NULL, NULL, pppScaleLoopCon, pppScaleLoopCon2, NULL},
    {"pppMatrixLoop", pppMatrixLoopCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDrawMatrixLoop", pppDrawMatrixLoopCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppDrawMdlLoop", pppDrawMdlLoopCalc, NULL, pppDrawMdlLoopDraw, NULL, NULL, NULL, pppDrawMdlLoopCon, pppDrawMdlLoopCon2, pppDrawMdlLoopDes},
    {"pppDrawMdlLoopZ", pppDrawMdlLoopZCalc, NULL, pppDrawMdlLoopZDraw, NULL, NULL, NULL, pppDrawMdlLoopZCon, pppDrawMdlLoopZCon2, pppDrawMdlLoopZDes},
    {"pppRyjLight", pppRyjLightCalc, NULL, NULL, NULL, NULL, NULL, pppRyjLightCon, NULL, pppRyjLightDes},
    {"pppKeLnsLpT", NULL, NULL, pppKeLnsLpTDraw, NULL, NULL, NULL, pppKeLnsLpTCon, pppKeLnsLpTCon2, pppKeLnsLpTDes},
    {"pppKeLnsArndT", NULL, NULL, pppKeLnsArndTDraw, NULL, NULL, NULL, pppKeLnsArndTCon, NULL, pppKeLnsArndTDes},
    {"pppKeLnsClmT", NULL, NULL, pppKeLnsClmTDraw, NULL, NULL, NULL, pppKeLnsClmTCon, NULL, pppKeLnsClmTDes},
    {"pppKeLnsCrnT", NULL, NULL, pppKeLnsCrnTDraw, NULL, NULL, NULL, pppKeLnsCrnTCon, NULL, pppKeLnsCrnTDes},
    {"pppKeLnsFlsT", NULL, NULL, pppKeLnsFlsTDraw, NULL, NULL, NULL, pppKeLnsFlsTCon, NULL, pppKeLnsFlsTDes},
    {"pppRyjDrawMatrixWorldDtt", pppRyjDrawMatrixWorldDttCalc, NULL, NULL, NULL, NULL, NULL, pppRyjDrawMatrixWorldDttCon, NULL, NULL},
    {"pppRyjDrawMatrixWorldDttFr", pppRyjDrawMatrixWorldDttFrCalc, NULL, NULL, NULL, NULL, NULL, pppRyjDrawMatrixWorldDttFrCon, NULL, NULL},
    {"pppRyjMegaBirthFilter", pppRyjMegaBirthFilterCalc, NULL, pppRyjMegaBirthFilterDraw, NULL, pppRyjMegaBirthFilterSta, NULL, pppRyjMegaBirthFilterCon, NULL, pppRyjMegaBirthFilterDes},
    {"pppRyjMegaBirthModelFilter", pppRyjMegaBirthModelFilterCalc, NULL, pppRyjMegaBirthModelFilterDraw, NULL, pppRyjMegaBirthModelFilterSta, NULL, pppRyjMegaBirthModelFilterCon, NULL, pppRyjMegaBirthModelFilterDes},
    {"pppMatrixLoopXYZ", pppMatrixLoopXYZCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixLoopXZY", pppMatrixLoopXZYCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixLoopYXZ", pppMatrixLoopYXZCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixLoopYZX", pppMatrixLoopYZXCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixLoopZXY", pppMatrixLoopZXYCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {"pppMatrixLoopZYX", pppMatrixLoopZYXCalc, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, (void*)-1, (void*)-1, (void*)-1, (void*)-1, (void*)-1, (void*)-1, (void*)-1, (void*)-1, (void*)-1},
};
#else
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
#endif
