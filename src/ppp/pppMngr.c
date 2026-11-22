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

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181200);

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

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181340);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001813F0);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001814C8);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001815A0);

s32 func_00181600(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (D_00364130[i].unk_94 == arg0) {
            return D_00364130[i].pEtc->boneNo;
        }
    }
    return -2;
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181640);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001817E8);

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

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181A58);

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

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181C20);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00181D30);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", dpd_set_object_tex);
// void dpd_set_object_tex(ppvmng* pMng) {
//     int* piVar1;
//     short clutpStart;
//     short texpStart;

//     texpStart = pMng->texpStart;
//     clutpStart = pMng->clutpStart;
//     if ((texpStart == 0) && (clutpStart == 0)) {
//         return;
//     }
//     piVar1 = dpd_h_skip_version(pMng->pchDpd);
//     piVar1 = dpd_h_skip_datainfo(piVar1, 2);
//     piVar1 = func_00181C20(piVar1, pMng->pEtc->abUseShape, texpStart, clutpStart);
//     func_00181D30(piVar1, pMng->pEtc->abUseRsd, texpStart, clutpStart);
// }

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", dpd_set_shape_data);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", dpd_set_rsd_data);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", dpd_set_vsf_data);

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

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001821A8);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182288);

void func_00182348(s32* arg0) {
    s32* p = dpd_h_skip_datainfo(dpd_h_skip_version(arg0), 1);
    s32 n = *p++;
    s32 i;

    for (i = 0; i < n; i++) {
        func_00182120(*p++, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001823B8);

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

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_001829D0);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182A78);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00182B18);

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

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183658);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppInitPartRender);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppSetPartMatrix);

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

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183AD0);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183B70);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00183C10);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", pppDeletePObject);

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

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184298);

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

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184DB0);

void func_00184E48(ppvmng* pMng) {
    ppvMng = pMng;
    func_001839F0(pMng);
    func_00184DB0(pMng);
    func_00184548(pMng);
}

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184E80);

INCLUDE_ASM("asm/nonmatchings/ppp/pppMngr", func_00184F60);

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
