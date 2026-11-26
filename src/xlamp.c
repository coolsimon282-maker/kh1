/**
 * Frame and DMA plumbing: two task lists (D_004FA560, D_004F8530) with add helpers, the VIF1/GIF DMA end handlers
 * (installed with AddDmacHandler; they switch FlushCache to iFlushCache while they run), the per-frame system update /
 * start-up lists that call the subsystems' init and update functions (actors, lights, graphics DMA, ...), and the
 * performance counter stop. JP/EU: 0x121DE0-0x122828.
 * Final Mix (#ifdef VERSION_FM) has only the rest of the file here, 0x122028-0x122430 (from JP's func_00122410 on):
 * JP's first part is not at this place in FM (func_00122228 / func_001222B0 are at 0x15ED80, in seg_03BDE8), so those
 * functions are JP/EU only in this file.
 */
#include "common.h"

#ifndef VERSION_FM
#include "libpc.h"
#include "eekernel.h"
#include "libgraph.h"

extern void* D_002C219C;

extern s32 D_0034DF90; // also used in 4A098 split

// .bss
s32 D_004F0508;
s32 D_004F050C;
s32 D_004F8530;
s32 D_004FA560;
s32 D_004FA668;

extern void* TaskList_Add(); //  todo: conflicting signatures already used, figure out correct one

void* func_00121DE0(s32 arg0, s32 arg1) {
    return TaskList_Add(D_004FA560, arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00121E08);

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00121EC8);

s32 func_00121FB8(s32 unused) {
    iDisableDmac(DMAC_VIF1);
    iDisableDmac(DMAC_GIF);
    D_002C219C = iFlushCache;

    if (func_00121EC8() != 0) {
        iEnableDmac(DMAC_VIF1);
        iEnableDmac(DMAC_GIF);
    }

    D_002C219C = FlushCache;
    ExitHandler();
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122030);

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122110);

void* func_00122228(s32 arg0, s32 arg1) {
    return TaskList_Add(D_004F8530, arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122250);

void func_001222B0(void) {
    DisableDmac(DMAC_VIF1);
    DisableDmac(DMAC_GIF);
    D_004F0508 = AddDmacHandler(DMAC_VIF1, func_00121FB8, 0);
    D_004F050C = AddDmacHandler(DMAC_GIF, func_00121FB8, 0);
}

void func_00122318(void) {
    DisableDmac(DMAC_VIF1);
    DisableDmac(DMAC_GIF);
    RemoveDmacHandler(DMAC_VIF1, D_004F0508);
    RemoveDmacHandler(DMAC_GIF, D_004F050C);
}

INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122358);

INCLUDE_ASM("asm/nonmatchings/xlamp", func_001223B0);
#endif

#ifdef VERSION_FM
void func_00127340(void);
void func_00132E38(void);
void func_0013F2C0(void);
void func_001478E0(void);
void func_00148E60(void);
void func_0014F868(void);
void func_00151B90(void);
void func_00121F30(s32 a0, s32 *a1);

extern u32* D_004F6EB8;
extern u32 D_004F6DB8[];

void func_00122410(void) {
    D_004F6DB8[0] = D_004F6DB8[1] = 0x70000000;
    D_004F6EB8 = D_004F6DB8;
}
#else
INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122410);
#endif

#ifdef VERSION_FM
u32 func_00122048(s32 a, u32 b) {
    u32 *p = D_004F6EB8;
    u32 *old = p;
    u32 n;

    p += 2;
    D_004F6EB8 = p;
    n = (old[1] + b - 1) / b * b;
    p[0] = n;
    if (a != 0) {
        D_004F6EB8[1] = n + a;
    } else {
        D_004F6EB8[1] = 0x70004000;
    }
    return n;
}
#else
INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122430);
#endif

#ifdef VERSION_FM
void func_001220B8(void) {
    D_004F6EB8 -= 2;
}
#else
void func_001224A0(void) {
    D_004FA668 -= 8;
}
#endif

#ifdef VERSION_FM
void func_001220D0(void) {
    scePcStop();
}
#else
void func_001224B8(void) {
    scePcStop();
}
#endif

#ifdef VERSION_FM
void func_001220E8(void) {
    func_00148E60();
    func_001478E0();
    func_0013F2C0();
    func_00127340();
    func_0014F868();
    func_00151B90();
    func_00132E38();
}
#else
void func_001224D0(void) {
    func_00148FD0();
    func_00147B28();
    func_0013F248();
    func_00127310();
    func_0014FAC0();
    func_00151F20();
    func_00132D48();
}
#endif

#ifdef VERSION_FM
void func_0013CE98(void);
void func_001255F8(void);
void func_00124F38(void);
void func_00128B68(void);
void func_00133628(void);
void func_00148F08(void);
void func_00142340(void);
void func_00157DC8(void);
void func_001561F8(void);
void func_0014A248(void);
void func_0012FF80(void);

void func_00122130(void) {
    D_002C1EA8 = 0;
    func_0013CE98();
    func_001255F8();
    func_00124F38();
    func_00128B68();
    func_00133628();
    func_00148F08();
    func_00142340();
    func_00157DC8();
    func_001561F8();
    func_0014A248();
    func_0012FF80();
}
#else
void func_00122518(void) {
    D_002C1EA8 = 0;
    func_0013CE18();
    func_001255F8();
    Actor_InitSystem();
    GraphicsDma_Init();
    func_001334A8();
    func_00149078();
    func_00142260();
    func_00142578();
    func_001582E8();
    func_001566E0();
    func_0014A248();
    func_0012FE80();
}
#endif

#ifdef VERSION_FM
void func_00122588(s32 a0, s32 a1) {
    extern s32 D_002B8678;
    extern s32 D_002B8680;
    extern s32 D_002B8684;
    extern s32 D_002C5C4C;
    extern s32 D_002C5C50;
    extern s32 D_002C5C54;
    extern void func_00132C70(s32, s32);

    D_002C1EA8 = 0;
    if (D_002B8678 == 0x10 && (D_002B8680 == 0x1A || D_002B8680 == 0x21 || D_002B8680 == 0x22)) {
        D_002C1EA8 |= 0x20;
    }
    D_002C5C4C = D_002B8678 == 9 || (D_002B8678 == 0x10 && D_002B8680 == 0x15);
    D_002C5C50 = D_002B8678 == 10 || (D_002B8678 == 0x10 && D_002B8680 == 0x16);
    D_002C5C54 = D_002B8678 == 0xF && D_002B8684 == 10;
    func_0012B738();
    func_00124F38();
    func_00142030();
    func_001561B0();
    func_00132C70(a0, a1);
    func_00133520();
    func_00146590();
    func_00151808();
    func_001356A8();
    func_0014C378();
    func_0012FF80();
    func_00123108();
    func_00134718();
    func_0013BCA8();
    func_0012EA38();
}
#else
INCLUDE_ASM("asm/nonmatchings/xlamp", func_00122588);
#endif

#ifdef VERSION_FM
extern s32 D_00351A48;
void func_00239488(void);
void func_0014C378(void);
void fm_func_001249D8(void);
void func_0012FB18(void);
void func_0017EBD0(void);
void func_0017DB68(void);
void func_00146508(void);
void func_00151808(void);
void func_001762C8(void);
void func_00168518(void);
void func_001574F0(void);

void func_00122720(void) {
    func_00239488();
    func_00178140(0);
    func_0013BCA8();
    func_0014C378();
    fm_func_001249D8();
    func_0012FB18();
    func_0017EBD0();
    func_0017DB68();
    func_00133520();
    func_00146508();
    func_00151808();
    func_001762C8();
    func_00168518();
    D_00351A48 = 6;
    func_001574F0();
}
#else
void func_00122720(void) {
    func_00235EE0();
    func_00178140(0);
    Summon_End(); // in xapple
    func_0014C498();
    func_00124CD8();
    func_0012FB18();
    func_00180358();
    func_0017F2B0();
    func_001421D8();
    func_001333A0();
    func_001467A8();
    func_00151B88();
    func_001777E0();
    func_001697B8();
    D_0034DF90 = 6;
    func_00157A18();
}
#endif

#ifdef VERSION_FM
void func_00178140(s32);
void func_0013BCA8(void);
void func_001590A8(void);
void func_00124DD0(void);
void func_00133520(void);
void func_00146590(void);
void func_00148E98(void);
void func_0012B738(void);
void func_00123020(void);
void func_0014C330(void);
void func_001356A8(void);
void func_0012FC58(void);
void func_0016F548(void);

void func_001223B8(void) {
    func_00178140(0);
    func_0013BCA8();
    func_001590A8();
    func_00124DD0();
    func_00133520();
    func_00146590();
    func_00148E98();
    func_0012B738();
    func_00123020();
    func_0014C330();
    func_001356A8();
    func_0012FC58();
    func_0016F548();
}
#else
void func_001227B0(void) {
    func_00178140(0);
    Summon_End(); // in xapple
    func_0015A5D0();
    func_00124DD0();
    func_001333A0();
    func_00146830();
    func_00149008();
    func_0012B5D8();
    Light_ClearTemporary();
    func_0014C450();
    func_001355B8();
    func_0012FB50();
    func_00170A28();
}
#endif
