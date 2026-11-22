#include "common.h"

extern sceVu0FVECTOR D_002C5C60;

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[0x38];
} XOwlEnt;

extern XOwlEnt D_002C5C80[];

typedef struct {
    /* 0x00 */ char unk_0x00[0x10];
    /* 0x10 */ sceVu0FVECTOR* unk_10;
    /* 0x20 */ sceVu0FVECTOR unk_20;
    /* 0x30 */ sceVu0FVECTOR unk_30;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ void (*unk_48)(sceVu0FVECTOR*);
} XHoot;

extern f32 D_002B8340[];

s32 D_004FA670;
s32 D_004FA680;

s32 func_00122828(XHoot* arg0) {
    s32 uVar1;
    f32 fVar2;
    f32 r;

    uVar1 = 0;
    fVar2 = arg0->unk_44 - D_002B8340[1];

    r = fVar2 / arg0->unk_40;
    arg0->unk_44 = fVar2;
    if (r < 0.0f) {
        r = 0.0f;
        if (arg0->unk_48 != NULL) {
            arg0->unk_48(arg0->unk_10);
        }
        uVar1 = 4;
    }
    sceVu0InterVector(arg0->unk_10[3], &arg0->unk_20, &arg0->unk_30, r);
    return uVar1;
}

void func_001228C8(f32 arg0, sceVu0FVECTOR* arg1, f32* arg2, void (*arg3)()) {
    XHoot* pvVar1;

    if (0.0f >= arg0) {
        sceVu0CopyVector(arg1[3], arg2);
    } else {
        pvVar1 = func_0011EEB8(&D_004FA670, 0, func_00122828);
        pvVar1->unk_10 = arg1;
        pvVar1->unk_44 = arg0;
        pvVar1->unk_40 = arg0;
        pvVar1->unk_48 = arg3;
        sceVu0CopyVector(pvVar1->unk_20, arg1[3]);
        sceVu0CopyVector(pvVar1->unk_30, arg2);
    }
}


INCLUDE_ASM("asm/nonmatchings/xowl", func_00122988);

XOwlEnt* func_00122AF8(s32 arg0, s32 arg1, s32 arg2) {
    XOwlEnt* p = D_002C5C80;
    s32 i;

    for (i = 0; i < 31; i++, p++) {
        if (p->unk_00 == 0) {
            p->unk_00 = arg0;
            p->unk_04 = arg1;
            *(s32*)((u8*)p + 8) = arg2;
            sceVu0CopyVector((f32*)((u8*)p + 0x30), D_002C5C60);
            return p;
        }
    }
    return NULL;
}

void func_00122B70(s32* arg0) {
    *arg0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/xowl", func_00122B78);

INCLUDE_ASM("asm/nonmatchings/xowl", func_00122DD8);

INCLUDE_ASM("asm/nonmatchings/xowl", func_00122EC8);

void func_00122FF0(void) {
    func_0011EDD0(&D_004FA670, &D_004FA680, 0x50, 8);
}

void func_00123020(void) {
    XOwlEnt* p = D_002C5C80;
    s32 i;

    for (i = 30; i >= 0; i--) {
        if (p->unk_00 != 0 && (p->unk_04 & 8)) {
            func_00122B70((s32*)p);
        }
        p++;
    }
    func_00122FF0();
}

void func_00123088(void) {
    XOwlEnt* p = D_002C5C80;
    s32 i;

    for (i = 30; i >= 0; i--) {
        if (p->unk_00 != 0 && (p->unk_04 & 8)) {
            p->unk_04 |= 0x10;
        }
        p++;
    }
}

void func_001230D0(void) {
    XOwlEnt* p = D_002C5C80;
    s32 i;

    for (i = 0; i < 31; i++, p++) {
        p->unk_04 &= ~0x10;
    }
}

INCLUDE_ASM("asm/nonmatchings/xowl", func_00123108);
