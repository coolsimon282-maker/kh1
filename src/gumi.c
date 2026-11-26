/**
 * Gummi ship blocks, probably (XGumiBlock / XGumiThing in gumi.h); built without -g (NO_G_FILES).
 * JP/EU: 0x1BBCD8-0x1BD0B8. Final Mix (#ifdef VERSION_FM): 0x1B9B78-0x1BAF08; functions paired with JP's by
 * address order and size where they correspond.
 */
#include "common.h"

#ifdef VERSION_FM
extern s32 D_0037A148;
extern s32 D_0037A150;
extern s32 D_0037A154;
s32 func_001BB740(void);

typedef struct {
    u8 pad[0x9C00];
    u8 tbl9C00[0x1020];
    u8 tblAC20[1];
} A2Big22F768;

void *func_0022F768(s32);

u8 func_001B9B78(s32 i) {
    return ((A2Big22F768 *)func_0022F768(4))->tbl9C00[i];
}
#else
#include "gumi.h"
#include "xcursed.h"

s32 D_00373790;
s32 D_00373794;
s32 D_00373798;
s32 D_0037379C;
s32 D_00373898;
void* D_0037389C;
s32 D_003738A0;
s32 D_003738A8;

s32 D_00373B00[];
s32 D_00373BC0[];

s32 D_0061BA40;
s32 D_0061BA48[2][2];
s32 D_0061B950;
void* D_0061BA58;

XGumiThing D_0061B960;

extern void func_F20000();
extern void func_001C0370(void*, s32);

s32 func_001BBCD8(s32 arg0) {
    XGumi* pvVar1 = WorkBuffers_Get(4);

    return pvVar1->unk_9BC0[arg0];
}
#endif

#ifdef VERSION_FM
void *func_0022F768(s32);

void func_001B9BB0(s32 i, s32 x) {
    ((A2Big22F768 *)func_0022F768(4))->tbl9C00[i] = x;
}
#else
void func_001BBD10(s32 arg0, s32 arg1) {
    XGumi* pvVar1 = WorkBuffers_Get(4);

    pvVar1->unk_9BC0[arg0] = arg1;
}
#endif

#ifdef VERSION_FM
double asin(double);

double func_001B9BF8(double x) {
    return asin(x);
}
#else
void func_001BBD58(double arg0) {
    asin(arg0);
}
#endif

#ifdef VERSION_FM
extern s32 D_00621210;
s32 func_001207F8(s32);
void FlushCache(int);
void func_F20000(void);

s32 func_001B9C10(void) {
    if (func_001207F8(D_00621210)) {
        return 0;
    }
    FlushCache(0);
    FlushCache(2);
    func_F20000();
    return 4;
}
#else
s32 func_001BBD70(void) {
    if (func_00120640(D_0061B950) != 0) {
        return 0;
    }

    puts("overlay read run");
    FlushCache(0);
    FlushCache(2);
    func_F20000();
    return 4;
}
#endif

#ifdef VERSION_FM
void func_001B9C60(const char *name) {
    void (*f)(void) = func_F20000;

    D_00621210 = func_00120438(name, f);
    FlushCache(0);
    FlushCache(2);
    f();
}
#endif

#ifndef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BBDD0);
#endif

#ifdef VERSION_FM
void func_001B9CB0(void) {
    u8* p = func_0022F768(4);

    if (*(s32*)(p + 0x9B40) == 0) {
        *(s32*)(p + 0x9B40) = 0x4000;
    }
    if (*(s32*)(p + 0x9B44) == 0) {
        *(s32*)(p + 0x9B44) = 0x8000;
    }
    if (*(s32*)(p + 0x9B48) == 0) {
        *(s32*)(p + 0x9B48) = 0x400;
    }
    if (*(s32*)(p + 0x9B4C) == 0) {
        *(s32*)(p + 0x9B4C) = 0x2000;
    }
    if (*(s32*)(p + 0x9B50) == 0) {
        *(s32*)(p + 0x9B50) = 0x2000;
    }
    if (*(s32*)(p + 0x9B54) == 0) {
        *(s32*)(p + 0x9B54) = 0x2000;
    }
    if (*(s32*)(p + 0x9B58) == 0) {
        *(s32*)(p + 0x9B58) = 0x1000;
    }
    if (*(s32*)(p + 0x9B5C) == 0) {
        *(s32*)(p + 0x9B5C) = 0x1000;
    }
    if (*(s32*)(p + 0x9B60) == 0) {
        *(s32*)(p + 0x9B60) = 0x1000;
    }
}
#else
void func_001BBE38(void) {
    XGumi* pvVar1 = WorkBuffers_Get(4);

    if (pvVar1->unk_9B00 == 0) {
        pvVar1->unk_9B00 = 0x4000;
    }
    if (pvVar1->unk_9B04 == 0) {
        pvVar1->unk_9B04 = 0x8000;
    }
    if (pvVar1->unk_9B08 == 0) {
        pvVar1->unk_9B08 = 0x400;
    }
    if (pvVar1->unk_9B0C == 0) {
        pvVar1->unk_9B0C = 0x2000;
    }
    if (pvVar1->unk_9B10 == 0) {
        pvVar1->unk_9B10 = 0x2000;
    }
    if (pvVar1->unk_9B14 == 0) {
        pvVar1->unk_9B14 = 0x2000;
    }
    if (pvVar1->unk_9B18 == 0) {
        pvVar1->unk_9B18 = 0x1000;
    }
    if (pvVar1->unk_9B1C == 0) {
        pvVar1->unk_9B1C = 0x1000;
    }
    if (pvVar1->unk_9B20 == 0) {
        pvVar1->unk_9B20 = 0x1000;
    }
}
#endif

#ifdef VERSION_FM
void func_001B9CB0();

s32 func_001B9DF0(s32 i) {
    u8 *p = func_0022F768(4);

    func_001B9CB0();
    return ((s32 *)(p + 0x9B40))[i];
}
#else
s32 func_001BBF78(s32 arg0) {
    XGumi* pvVar1 = WorkBuffers_Get(4);
    func_001BBE38();
    return (&pvVar1->unk_9B00)[arg0];
}
#endif

#ifdef VERSION_FM
void func_001B9E40(s32 i, s32 x) {
    ((s32 *)((u8 *)func_0022F768(4) + 0x9B40))[i] = x;
}
#else
void func_001BBFC8(s32 arg0, s32 arg1) {
    XGumi* pvVar1 = WorkBuffers_Get(4);
    (&pvVar1->unk_9B00)[arg0] = arg1;
}
#endif

#ifdef VERSION_FM
s32 func_001BAAD0(void);
s32 func_001BC590(s32);

s32 func_001B9E88(void) {
    if (func_001BAAD0() & 0x80) {
        return 0;
    }
    return func_001BC590(0x31) > 0;
}
#else
s32 func_001BC010(void) {
    if ((func_001BCC80() & 0x80) == 0) {
        return func_001BC590(49) > 0;
    }
    return FALSE;
}
#endif

#ifdef VERSION_FM
void func_001BB580(void);
void func_001BE820(void*, s32);
void func_001BAAF0(u8*);
void func_001B9F78(s32);
void* func_001BA9A8(void);
s32* func_001BA980(void);
void func_001BAA20(u8*);
void* func_001BA9D8(s32);
void func_001BAB80(s32, u8*);
void func_001BA108(void*, s32);

void func_001BC048(void) {
    u8* p;
    u8* q;

    func_001BB580();
    p = func_0022F768(4);
    func_001BE820(p, 0xB040);
    *(s32*)(p + 4) = 0x101;
    p[0] = 'G';
    p[1] = 'U';
    p[2] = 'M';
    p[3] = 'I';
    func_001BAAF0(p);
    func_001B9F78(0);
    q = func_001BA9A8();
    q[0x44] = 1;
    q[0x47] = 1;
    func_001BAA20((u8*)func_001BA980());
    func_001BAB80(10, func_001BA9D8(0));
    func_001BA108(func_001BA9D8(0), 0);
}
#else
void func_001BC048(void) {
    XGumi* pXVar1;
    XGumiBlock* pXVar2;

    func_001BD210();
    pXVar1 = (XGumi*)WorkBuffers_Get(4);
    func_001C0370(pXVar1, sizeof(XGumi));

    pXVar1->unk_0004 = 0x100;
    pXVar1->unk_0000[0] = 'G';
    pXVar1->unk_0000[1] = 'U';
    pXVar1->unk_0000[2] = 'M';
    pXVar1->unk_0000[3] = 'I';

    func_001BCCA0(pXVar1);
    func_001BC100(0);

    pXVar2 = func_001BCB58();
    pXVar2->unk_44 = 1;
    pXVar2->unk_47 = 1;
    func_001BCBD0(func_001BCB30());
    func_001BCD30(10, func_001BCB88(0));
    func_001BC290(func_001BCB88(0), 0);
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/gumi", func_001B9F78);
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BC100);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BA060);
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BC1E8);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BA108);
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BC290);
#endif

#ifdef VERSION_FM
s32 func_001BA1E0(void) {
    return 0xB040;
}
#else
s32 func_001BC368(void) {
    return sizeof(XGumi);
}
#endif

#ifdef VERSION_FM
typedef struct {
    u8 pad[0x14];
    u16 unk_14;
    u16 unk_16;
    u8 pad2[4];
} A2Elem1C;
A2Elem1C *func_001BB658(s32 i);

u16 func_001BC370(s32 i) {
    return func_001BB658(i)->unk_14;
}
#else
u16 func_001BC370(s32 arg0) {
    return *(u16*)(func_001BD288(arg0) + 0x14); // todo: struct
}
#endif

#ifdef VERSION_FM
u16 func_001BC390(s32 i) {
    return func_001BB658(i)->unk_16;
}
#else
u16 func_001BC390(s32 arg0) {
    return *(u16*)(func_001BD288(arg0) + 0x16); // todo: struct
}
#endif

#ifdef VERSION_FM
void func_001BB558(void);
s32 func_001BE5C8(s32);
s32 func_001BE5D0(s32);
s32 func_001EFBB8(s32);
void func_001EFAF0(void);

s32 func_001BA228(s32 a0) {
    s32 r;

    func_001BB558();
    r = func_001EFBB8(func_001BE5C8(a0));
    func_001EFAF0();
    return r;
}
#else
s32 func_001BC3B0(s32 arg0) {
    s32 iVar1;

    func_001BD1E8();
    iVar1 = func_001C0148(arg0);
    iVar1 = func_001F0E98(iVar1);
    func_001F0DD0();
    return iVar1;
}
#endif

#ifdef VERSION_FM
s32 func_001BA268(s32 a0) {
    s32 r;

    func_001BB558();
    r = func_001EFBB8(func_001BE5D0(a0));
    func_001EFAF0();
    return r;
}
#else
s32 func_001BC3F0(s32 arg0) {
    s32 iVar1;

    func_001BD1E8();
    iVar1 = func_001C0150(arg0);
    iVar1 = func_001F0E98(iVar1);
    func_001F0DD0();
    return iVar1;
}
#endif

#ifdef VERSION_FM
void *func_001BA9D8(s32);

void func_001BA2A8(s32 n, u8 *src) {
    u8 *d = (u8 *)func_001BA9D8(n) + 0x50;
    s32 i;

    for (i = 0; i < 32; i++) {
        *d++ = src[i];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BC430);
#endif

#ifdef VERSION_FM
void *func_001BA9A8(void);
u8 func_001BA458(s32 x);

s32 func_001BC480(s32 i) {
    u8* p = (u8*)func_001BA9A8() + i;
    s32 c = *p;
    s32 m = func_001BA458(i);

    if (c < m) {
        *p += 1;
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BC480);
#endif

#ifdef VERSION_FM
void func_001BA358(s32 i, s32 add) {
    u8 *p = (u8 *)func_001BA9A8() + i;

    if (*p + add > func_001BA458(i)) {
        *p = func_001BA458(i);
    } else {
        *p += add;
    }
}
#else
// s32 func_001BC480(s32 arg0) {
//     u8 bVar1;
//     XGumiBlock* pXVar2;
//     s32 lVar3;

//     printf(D_00489CE0, arg0);
//     pXVar2 = func_001BCB58();
//     bVar1 = pXVar2->unk_00[arg0];

//     lVar3 = func_001BC5F8(arg0);

//     if (lVar3 > bVar1) {
//         pXVar2->unk_00[arg0]++;
//     }
//     return lVar3 > bVar1;
// }

INCLUDE_ASM("asm/nonmatchings/gumi", func_001BC4F8);
#endif

#ifdef VERSION_FM
void func_001BC578(void) {
    func_001BB740();
}
#else
s32 func_001BC578(void) {
    return func_001BD360();
}
#endif

#ifdef VERSION_FM
void *func_001BA9A8(void);

s32 func_001BC590(s32 i) {
    return ((u8 *)func_001BA9A8())[i];
}
#else
u8 func_001BC590(s32 arg0) {
    XGumiBlock* pXVar1 = func_001BCB58();
    return pXVar1->unk_00[arg0];
}
#endif

#ifdef VERSION_FM
void func_001BA420(s32 i, s32 x) {
    ((u8 *)func_001BA9A8())[i] = x;
}
#else
void func_001BC5C0(s32 arg0, s32 arg1) {
    XGumiBlock* pXVar1 = func_001BCB58();
    pXVar1->unk_00[arg0] = arg1;
}
#endif

#ifdef VERSION_FM
A2Elem1C *func_001BB658(s32 i);

u8 func_001BA458(s32 x) {
    if ((u32)(x - 0x47) < 0x30) {
        return 1;
    }
    return ((u8 *)func_001BB658(x))[0xB];
}
#else
u8 func_001BC5F8(s32 arg0) {
    return *(u8*)(func_001BD288(arg0) + 0xB); // todo: struct
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BA488);
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BC618);
#endif

#ifdef VERSION_FM
typedef struct {
    u64 d[14];
} A2S70;
extern u8 D_002C5AD0[];
extern u8 D_00621220[];
void func_001BA520(void);

void func_001BA4A8(void) {
    func_001BA520();
    *(A2S70 *)D_002C5AD0 = *(A2S70 *)D_00621220;
}
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BC638);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BA520);
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BC6B0);
#endif

#ifdef VERSION_FM
extern s32 D_003772D0;

void func_001BA6F8(void) {
    D_003772D0 = 0;
}
#else
void func_001BC888(void) {
    D_00373790 = 0;
}
#endif

#ifdef VERSION_FM
extern u8 D_00621220[];
extern s32 D_00621300;
extern s32 D_00621308[][2];
void func_001BE820(void *, s32);
void func_0010FCE0(void);
void func_0010FCD0(void);

void func_001BA708(s32 x) {
    D_003772D0 = x;
    if (x) {
        func_001BE820(D_00621220, 0x70);
        D_00621300 = 0;
        D_00621308[0][0] = 0;
        D_00621308[0][1] = 0;
        D_00621308[1][0] = 0;
        D_00621308[1][1] = 0;
        func_0010FCE0();
    } else {
        func_0010FCD0();
    }
}
#else
void func_001BC898(s32 arg0) {
    D_00373790 = arg0;
    if (arg0 != 0) {
        func_001C0370(&D_0061B960, sizeof(XGumiThing));
        D_0061BA40 = 0;
        D_0061BA48[0][0] = 0;
        D_0061BA48[0][1] = 0;
        D_0061BA48[1][0] = 0;
        D_0061BA48[1][1] = 0;
        func_0010FCE0();
    } else {
        func_0010FCD0();
    }
}
#endif

#ifdef VERSION_FM
extern s32 D_00621300;

void func_001BA768(s32 x) {
    D_00621300 = x;
}
#else
void func_001BC8F8(s32 arg0) {
    D_0061BA40 = arg0;
}
#endif

#ifdef VERSION_FM
extern s32 D_00621308[][2];

void func_001BA778(s32 i, s32 a, s32 b) {
    D_00621308[i][0] = a;
    D_00621308[i][1] = b;
}
#else
void func_001BC908(s32 arg0, s32 arg1, s32 arg2) {
    D_0061BA48[arg0][0] = arg1;
    D_0061BA48[arg0][1] = arg2;
}
#endif

#ifdef VERSION_FM
void func_001BE670(s32);

void func_001BA798(void) {
    D_003772D0 = 0;
    func_001BE670(0);
}
#else
void func_001BC928(void) {
    D_00373790 = 0;
    func_001C01C0(0);
}
#endif

#ifdef VERSION_FM
void *func_00112C70(void);

void func_001BA7B8(void) {
    func_00112C70();
}
#else
s32 func_001BC948(void) {
    return func_00112C70();
}
#endif

#ifdef VERSION_FM
extern s32 D_003772DC;

s32 func_001BA7D0(void) {
    return D_003772DC;
}
#else
s32 func_001BC960(void) {
    return D_0037379C;
}
#endif

#ifdef VERSION_FM
extern s32 D_003773EC;
extern s32 D_003772D4;
extern char D_0048FFF0[];
extern char D_00490000[];
int puts(const char *);
void func_001BA910(s32);

void func_001BA7E0(void) {
    D_003773EC = 1;
    D_003772DC = 1;
    func_001BA6F8();
    puts(D_0048FFF0);
    func_001B9C60(D_00490000);
    func_001BA910((s32)func_001BA7B8);
    D_003772D4++;
}
#else
void func_001BC970(void) {
    D_003738A8 = 1;
    D_0037379C = 1;
    func_001BC888();
    puts("Run Gumi Edit");
    func_001BBDD0("gb.x");
    func_001BCAA0(func_001BC948);
    D_00373794++;
}
#endif

#ifdef VERSION_FM
s32 func_001BA848(void) {
    return 0;
}
#else
s32 func_001BC9D8(void) {
    return 0;
}
#endif

#ifdef VERSION_FM
f32 func_001BA850(void) {
    return 0.0f;
}
#else
f32 func_001BC9E0(void) {
    return 0.0f;
}
#endif

#ifdef VERSION_FM
f32 func_001BA860(void) {
    return 0.0f;
}
#else
f32 func_001BC9F0(void) {
    return 0.0f;
}
#endif

#ifdef VERSION_FM
extern void *D_003773E0;
extern void *D_003773E4;
extern void *D_003773DC;
extern s32 D_003772D8;
extern char D_00490008[];
extern char D_00490018[];
void func_001C20B8(void);
void func_00236F18(void);

void func_001BA870(void) {
    D_003773EC = 1;
    D_003773DC = func_001BA848;
    D_003773E0 = func_001BA850;
    D_003773E4 = func_001BA860;
    D_003772DC = 2;
    func_001C20B8();
    func_00236F18();
    func_001BA6F8();
    puts(D_00490008);
    func_001B9C60(D_00490018);
    D_003772D8++;
}
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BCA00);
#endif

#ifdef VERSION_FM
extern s32 D_00621318;

void func_001BA910(s32 x) {
    D_00621318 = x;
}
#else
// void func_001BCA00(void) {
//     D_003738A8 = 1;
//     D_00373898 = func_001BC9D8;
//     D_0037389C = func_001BC9E0;
//     D_003738A0 = func_001BC9F0;
//     D_0037379C = 2;
//     func_001C20B8();
//     func_00233968();
//     func_001BC888();
//     puts(D_00489D10);
//     func_001BBDD0(D_00489D20);
//     D_00373798++;
// }

void func_001BCAA0(void* arg0) {
    D_0061BA58 = arg0;
}
#endif

#ifdef VERSION_FM
s32 func_001BA920(void) {
    return D_00621318;
}
#else
void* func_001BCAB0(void) {
    return D_0061BA58;
}
#endif

#ifdef VERSION_FM
void func_001C2808(void *, s32, void *);

void func_001BA930(u8 *obj, s8 v) {
    s8 buf = v;
    func_001C2808(obj + 0x2F0, 1, &buf);
}
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BCAC0);
#endif

#ifdef VERSION_FM
void func_001C2728(void *, s32, void *);

s8 func_001BA958(u8 *obj) {
    s8 buf;
    func_001C2728(obj + 0x2F0, 1, &buf);
    return buf;
}
#endif

#ifndef VERSION_FM
void func_001BCAE8(void) {
    XGumi* piVar1 = WorkBuffers_Get(4);

    if ((*(s32*)piVar1->unk_0000 != 'IMUG') || (piVar1->unk_0004 != 0x100)) {
        func_001BC048();
    }
}
#endif

#ifdef VERSION_FM
void fm_func_001B9B30();
void *func_0022F768(s32);

s32 *func_001BA980(void) {
    fm_func_001B9B30();
    return (s32 *)((u8 *)func_0022F768(4) + 8);
}
#else
s32* func_001BCB30(void) {
    XGumi* piVar1;

    func_001BCAE8();
    piVar1 = WorkBuffers_Get(4);
    return &piVar1->unk_0008;
}
#endif

#ifdef VERSION_FM
void fm_func_001B9B30();
void *func_0022F768(s32);

void *func_001BA9A8(void) {
    fm_func_001B9B30();
    return (u8 *)func_0022F768(4) + 0x9A78;
}
#else
XGumiBlock* func_001BCB58(void) {
    XGumi* piVar1;

    func_001BCAE8();
    piVar1 = WorkBuffers_Get(4);
    return &piVar1->unk_9A78;
}
#endif

#ifdef VERSION_FM
void fm_func_001B9B30();
void *func_0022F768(s32);

void *func_001BA9D8(s32 i) {
    fm_func_001B9B30();
    return (u8 *)func_0022F768(4) + i * 0xF70 + 0x18;
}
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BCB88);
#endif

#ifdef VERSION_FM
void func_001BAA20(u8 *p) {
    s32 i;
    u8 *q = p + 7;

    *(s32 *)(p + 8) = 0;
    for (i = 7; i >= 0; i--) {
        *q-- = i;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BCBD0);
#endif

#ifdef VERSION_FM
s32 *func_001BA980();

void func_001BAA58(u8 *src) {
    u8 *d = (u8 *)func_001BA980();
    s32 i;

    for (i = 0; i < 8; i++) {
        d[i] = src[i];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BCC08);
#endif

#ifdef VERSION_FM
s32 *func_001BA980();

void func_001BAAA8(s32 x) {
    func_001BA980()[2] = x;
}
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BCC58);
#endif

#ifdef VERSION_FM
s32 *func_001BA980();

s32 func_001BAAD0(void) {
    return func_001BA980()[2];
}
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BCC80);
#endif

#ifdef VERSION_FM
void func_001BAAF0(u8 *a0) {
    *(s32 *)(a0 + 0x9B40) = 0x4000;
    *(s32 *)(a0 + 0x9B44) = 0x8000;
    *(s32 *)(a0 + 0x9B48) = 0x400;
    *(s32 *)(a0 + 0x9B60) = 0x1000;
    *(s32 *)(a0 + 0x9B64) = 0;
    *(s32 *)(a0 + 0x9B4C) = 0x2000;
    *(s32 *)(a0 + 0x9B50) = 0x2000;
    *(s32 *)(a0 + 0x9B54) = 0x2000;
    *(s32 *)(a0 + 0x9B58) = 0x1000;
    /* The original assembler moved the last instruction of the `sw $7,0x9B5C($4)` macro (lui $1; addu $1,$1,$4;
     * sw) into the jr delay slot; ours never does, so this store is written with $at spelled out, after a barrier
     * so that nothing else can use $at in between. */
    __asm__ volatile("");
    {
        register u8 *at asm("$1") = a0 + 0x10000;
        *(s32 *)(at - 0x64A4) = 0x1000;
    }
}
#else
void func_001BCCA0(XGumi* arg0) {
    arg0->unk_9B00 = 0x4000;
    arg0->unk_9B04 = 0x8000;
    arg0->unk_9B08 = 0x400;
    arg0->unk_9B0C = 0x2000;
    arg0->unk_9B10 = 0x2000;
    arg0->unk_9B14 = 0x2000;
    arg0->unk_9B18 = 0x1000;
    arg0->unk_9B1C = 0x1000;
    arg0->unk_9B20 = 0x1000;
    arg0->unk_9B24 = 0;
}
#endif

#ifdef VERSION_FM
extern char D_00490020[];
void func_001BE820(void *, s32);
void func_001BEF98(char *, char *);

void func_001BAB80(s32 n, u8 *p) {
    s32 i;

    for (i = 0; i < n; i++) {
        func_001BE820(p, 0xF70);
        func_001BEF98((char *)(p + 0x50), D_00490020);
        p += 0xF70;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BCD30);
#endif

#ifdef VERSION_FM
void func_001BABE8(void) {
    ((u8*)func_001BA9A8())[0x31]++;
    func_001BA930((u8*)0, 4);
    func_001BA930((u8*)1, 4);
    func_001BA930((u8*)2, 4);
    func_001BA930((u8*)3, 4);
    func_001BA930((u8*)4, 4);
    func_001BA930((u8*)5, 4);
    func_001BA930((u8*)6, 4);
    func_001BA930((u8*)7, 4);
    func_001BA930((u8*)8, 4);
    func_001BA930((u8*)9, 4);
    func_001BA930((u8*)10, 3);
    func_001BA930((u8*)11, 2);
    func_001BA930((u8*)12, 4);
    func_001BA930((u8*)13, 4);
    func_001BA930((u8*)14, 4);
    func_001BA930((u8*)15, 31);
    func_001BA930((u8*)16, 31);
    func_001BA930((u8*)17, 31);
    func_001BA930((u8*)18, 31);
    func_001BA930((u8*)19, 31);
    func_001BA930((u8*)20, 31);
    func_001BA930((u8*)21, 31);
    func_001BA930((u8*)22, 31);
    func_001BA930((u8*)23, 31);
    func_001BA930((u8*)24, 31);
    func_001BA930((u8*)34, -1);
    func_001BA930((u8*)35, -1);
    func_001BA930((u8*)36, -1);
    func_001BA930((u8*)37, -1);
    func_001BA930((u8*)38, -1);
}
#else
void func_001BCD98(void) {
    XGumiBlock* iVar1 = func_001BCB58();

    iVar1->unk_31 += 1;
    func_001BCAC0(0, 4);
    func_001BCAC0(1, 4);
    func_001BCAC0(2, 4);
    func_001BCAC0(3, 4);
    func_001BCAC0(4, 4);
    func_001BCAC0(5, 4);
    func_001BCAC0(6, 4);
    func_001BCAC0(7, 4);
    func_001BCAC0(8, 4);
    func_001BCAC0(9, 4);
    func_001BCAC0(10, 3);
    func_001BCAC0(11, 2);
    func_001BCAC0(12, 4);
    func_001BCAC0(13, 4);
    func_001BCAC0(14, 4);
    func_001BCAC0(15, 31);
    func_001BCAC0(16, 31);
    func_001BCAC0(17, 31);
    func_001BCAC0(18, 31);
    func_001BCAC0(19, 31);
    func_001BCAC0(20, 31);
    func_001BCAC0(21, 31);
    func_001BCAC0(22, 31);
    func_001BCAC0(23, 31);
    func_001BCAC0(24, 31);
    func_001BCAC0(34, -1);
    func_001BCAC0(35, -1);
    func_001BCAC0(36, -1);
    func_001BCAC0(37, -1);
    func_001BCAC0(38, -1);
}
#endif

#ifdef VERSION_FM
typedef struct {
    u8 pad[0x9B38];
    s32 a;
    s32 b;
} A2Obj9B38;

s32 func_001BAD78(s32 i) {
    A2Obj9B38 *q = func_0022F768(4);

    switch (i) {
    case 0:
        return q->a;
    case 1:
        return q->b;
    }
    return 0;
}
#else
s32 func_001BCF28(s32 arg0) {
    XGumi* pvVar1 = WorkBuffers_Get(4);

    switch (arg0) {
        case 0:
            return pvVar1->unk_9AF8;
        case 1:
            return pvVar1->unk_9AFC;
        default:
            return 0;
    }
}
#endif

#ifndef VERSION_FM
INCLUDE_RODATA("asm/nonmatchings/gumi", D_00489D28);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BADE8);
#else
INCLUDE_ASM("asm/nonmatchings/gumi", func_001BCF98);
#endif
