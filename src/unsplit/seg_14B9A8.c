// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x14B9A8).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

extern s32 D_0046A058[];
extern u8 D_004919B0[];
extern u8 D_004919E8[];
extern s32 D_0066AA84;
extern s32 _impure_ptr;
void abort(void);
void fiprintf(s32, u8 *, s32, s32, s32);
void func_00149E38(s32, u8 *);
void func_0024F008();
s32 sceCdGetError(void);
void sceDevctl(u8 *, s32, s32, s32, s32, s32);

s32 func_0024B9A8(s32 i) {
    return D_0046A058[i];
}

extern s32 D_00669A38;

s32 func_0024B9C0(void) {
    return D_00669A38;
}

extern s32 D_00669A3C;

s32 func_0024B9D0(void) {
    return D_00669A3C;
}

void func_0024B9E0(s32 x) {
    D_00669A38 = x;
}

void func_0024B9F0(s32 x) {
    D_00669A3C = x;
}

void func_0024BA00(s32 a0) {
    s32 t0;
    D_00669A38 = a0;
    t0 = sceCdGetError();
    D_00669A3C = t0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024BA28);

s32 func_0024BA28(s32, s32, s32, void *);

void func_0024BB88(s32 a0, s32 a1, f32 *a2) {
    f32 v;
    if (func_0024BA28(a0, a1, 0, &v) < 0) {
        __asm__ volatile("break 0");
    }
    *a2 = v;
}

s32 func_0024BA28(s32, s32, s32, void *);

void func_0024BBC8(s32 a0, s32 a1, s32 *a2) {
    s32 v;
    if (func_0024BA28(a0, a1, 0, &v) < 0) {
        __asm__ volatile("break 0");
    }
    *a2 = v;
}

typedef struct {
    void *ptr;
    s32 id;
} A2Ent;

void func_0024BC08(s32 a0, A2Ent *e) {
    while (e->ptr != 0) {
        if (func_0024BA28(a0, e->id, 0, e->ptr) < 0) {
            __asm__ volatile("break 0");
        }
        e++;
    }
}

typedef union {
    u32 w;
    struct {
        s16 lo;
        s16 hi;
    } s;
} A2Ent4;
extern s32 D_0046A540;
extern A2Ent4 *D_0046A568[];

s32 func_0024BC68(s32 a, s32 b) {
    A2Ent4 *e;

    for (e = D_0046A568[D_0046A540]; e->s.hi != -10; e++) {
        if (e->s.hi == -1 && a == ((e->w >> 4) & 0xF) && b == ((e->w >> 8) & 0xF)) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024BCE8);

extern u32 D_002C5AD8;

u32 func_0024BE58(void) {
    u32 x = D_002C5AD8;
    return x | ((x >> 24) & 0xF0);
}

extern u32 D_002C5AE0;

u32 func_0024BE70(void) {
    u32 x = D_002C5AE0;
    return x | ((x >> 24) & 0xF0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024BE88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024C460);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024C8B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024C950);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024CDE8);

void func_0024CE80(u8 *dst, s16 *src) {
    s32 i;
    s32 j = 0;
    s32 c;

    for (i = 0; i < 8 && (c = *src) >= 0; i++, src++) {
        if (c == 0) {
            c = 1;
        } else {
            c += 0x20;
            if (c >= 0x100) {
                c += 0x1800;
                dst[j++] = c >> 8;
            }
        }
        dst[j++] = c;
    }
    dst[j] = 0;
}

typedef struct {
    u8 pad[0x34];
    s8 name[0x2C];
} A2Ent60;
typedef struct {
    u8 pad[0x60];
    A2Ent60 ent[1];
} A2ObjBC4E0;
A2ObjBC4E0 *func_001BC4E0(void);
extern s32 D_00669A60;
extern s16 D_00669A40[];

void func_0024CF00(void) {
    A2Ent60 *e = &func_001BC4E0()->ent[D_00669A60];
    s32 i;

    for (i = 0; e->name[i] != 0; i++) {
        e->name[i] = 0;
    }
    func_0024CE80((u8 *)e->name, D_00669A40);
}

extern s32 D_0046A5D8;

s32 func_0024CF80(void) {
    return D_0046A5D8;
}

extern s32 D_00669A7C;

s32 func_0024CF90(void) {
    return D_00669A7C;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024CFA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D138);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D1C8);

extern s32 D_0046A55C;

s32 func_0024D408(void) {
    return D_0046A55C;
}

s32 func_0024D138();
s32 func_001EAFD8(void);
void func_0024CDE8(s16 *, s32);
void func_0024D1C8(s16 *, s32, s32, s32);

void func_0024D418(void) {
    s16 buf[9];
    s32 i;

    func_0011ED30(0x2BFE8, func_0024D138);
    for (i = 0; i < 9; i++) {
        buf[i] = -1;
    }
    func_0024CDE8(buf, func_001EAFD8());
    func_0024D1C8(buf, -1, 0, 1);
}

extern s32 D_0046A53C;

s32 func_0024A000(void) {
    return D_0046A53C;
}

extern s32 D_0046A60C;

s32 func_0024D4A0(void) {
    return D_0046A60C;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D4B0);

extern s32 D_0046A618;

void func_0024D5D0(s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        D_0046A618++;
    }
}

s32 func_0024D608(void) {
    return D_0046A618;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D618);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D808);

extern u8 D_0046A620[];

void *func_0024D8A0(void) {
    return D_0046A620;
}

extern u8 D_0046A628[];

void *func_0024D8B0(void) {
    return D_0046A628;
}

extern u8 D_0046A640[];

void *func_0024D8C0(void) {
    return D_0046A640;
}

extern u8 D_0046A650[];

void *func_0024D8D0(void) {
    return D_0046A650;
}

extern u8 D_0046A660[];

void *func_0024D8E0(void) {
    return D_0046A660;
}

typedef struct {
    u8 pad[4];
    s32 (*unk_04)(void);
    s32 (*unk_08)(void);
    u8 padC[4];
    s32 unk_10;
} A2MountF;
extern A2MountF D_0046A688_f __asm__("D_0046A688");
extern char D_00491998[];
extern char D_004919A8_c[] __asm__("D_004919A8");
int sprintf(char*, const char*, ...);
int sceMount(const char* fsdevname, const char* blkdevname, int flag, void* arg, int arglen);

s32 func_0024D8F0(void) {
    A2MountF *p = &D_0046A688_f;
    char buf[0x80];

    if (p->unk_10 == 0) {
        s32 a = p->unk_04();
        s32 r;
        sprintf(buf, D_00491998, a, p->unk_08());
        r = sceMount(D_004919A8_c, buf, 0, 0, 0);
        if (r < 0) {
            return (r == -5) ? -1 : 1;
        }
        p->unk_10 = 1;
    }
    return 0;
}

typedef struct {
    u8 pad[0x10];
    s32 unk_10;
} A2Mount;
extern A2Mount D_0046A688;
extern u8 D_004919A8[];
s32 sceUmount(u8 *);

s32 func_0024D9A0(void) {
    A2Mount *p = &D_0046A688;

    if (p->unk_10 != 0) {
        s32 r = sceUmount(D_004919A8);

        if (r != 0) {
            return 1;
        }
        p->unk_10 = 0;
        return r;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D9F0);

void func_0024DAA0(void) {
    sceDevctl(D_004919B0, 0x4807, 0, 0, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024DAD0);

extern s32 D_0046A674;

s32 func_0024DB68(void) {
    return D_0046A674;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024DB78);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024DCC8);

typedef struct {
    u8 pad[8];
    s32 unk_08;
    s32 unk_0C;
} A2Ent120190;
extern u8 D_004919C8[];
A2Ent120190 *func_00120190(u8 *);

s32 func_0024DD98(s32 *out) {
    s32 r = 0;
    A2Ent120190 *q;

    if (out != NULL) {
        *out = 0;
    }
    q = func_00120190(D_004919C8);
    if (q != NULL) {
        r = q->unk_0C;
        if (out != NULL) {
            *out = q->unk_08;
        }
    }
    return r;
}

extern s32 D_0046A614;
extern s32 D_0046A67C;
extern s32 D_0046A680;
extern s32 D_0046A678;
extern s32 D_0046A6AC;
extern s32 D_0046A608;
extern u8* (*D_0046A68C)(void);
extern char D_004919D8[];
extern char D_004919E0[];
extern char D_00491978[];
u8* func_0011FD30(void);
int abs(int);
int memcmp(const void*, const void*, unsigned int);
int sceSifSearchModuleByName(const char*);
s32 func_0024DCC8(u8*, u8*);
void func_0024DB78(s32);
s32 func_0024D9F0(void);
s32 func_0024DAA0_r(void) __asm__("func_0024DAA0");
s32 func_0024DDF8(void) {
    u8* buf;
    u8* q;
    u8* p;
    u8* s;
    s32 i;
    s32 flag;
    s32 r;

    D_0046A614 = 0;
    D_0046A680 = 0;
    D_0046A67C = 0;
    if (func_0024D4A0() == 0) {
        return D_0046A67C;
    }
    i = 0;
    D_0046A614 = 10;
    buf = func_0011FD30();
    q = D_0046A68C() + 8;
    for (;; i++) {
        p = buf + i;
        if (memcmp(D_004919D8, p, 4) == 0) {
            break;
        }
    }
    buf = p + 5;
    q[0] = buf[0];
    q[1] = buf[1];
    q[2] = buf[2];
    q[3] = buf[4];
    q[4] = buf[5];
    if (memcmp(q, D_004919E0, 5) == 0) {
        D_0046A678 = 1;
    }
    func_0024D9A0();
    if (sceSifSearchModuleByName(D_00491978) < 0) {
        D_0046A67C = 0;
        D_0046A680 = 3;
    } else {
        if (func_0024DCC8(D_004919B0, D_0046A628) != 0) {
            flag = 1;
            D_0046A6AC = 1;
        } else {
            flag = 0;
            D_0046A6AC = 0;
        }
        D_0046A608 = func_0024DD98(0);
        D_0046A614 = 20;
        r = func_0024DAA0_r();
        r = abs(r);
        D_0046A614 = 30;
        switch (r & 0xF) {
        case 0:
            func_0024DB78(D_0046A608);
            if (func_0024D8F0() != 0) {
                D_0046A67C = 1;
                if (flag) {
                    D_0046A67C = 3;
                    D_0046A680 = 2;
                }
            } else if (func_0024D9F0() != 0) {
                D_0046A67C = 3;
                func_0024D9A0();
                D_0046A680 = 2;
            } else {
                D_0046A67C = 2;
            }
            break;
        case 1:
            D_0046A680 = 1;
            D_0046A67C = 1;
            break;
        case 2:
            D_0046A67C = 1;
            D_0046A680 = 4;
            break;
        default:
            D_0046A67C = 0;
            D_0046A680 = 3;
            break;
        }
    }
    D_0046A614 = 0x82;
    return D_0046A67C;
}

extern s32 D_0046A67C;

s32 func_0024E078(void) {
    return D_0046A67C;
}

void func_0024E088(s32 x) {
    D_0046A67C = x;
}

extern s32 D_0046A680;

s32 func_0024E098(void) {
    return D_0046A680;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E0A4);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E0E4);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024AB00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E18C);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E1D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E640);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E678);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E6E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E6E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E75C);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E8D4);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024EA4C);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024EBF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024EC1C);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024EDC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024EDF0);

extern u8 *D_002E26A0[];
void func_00242B68(s32);
s32 func_0013C2A8(u16);
void func_00241C60(void *, s32);

void func_0024EF88(void) {
    s32 i;

    func_00242B68(1);
    func_00242B68(2);
    for (i = 0; i < 2; i++) {
        u8 *o = D_002E26A0[i + 1];

        if (o != NULL) {
            func_00241C60(o, func_0013C2A8(*(u16 *)(*(u8 **)(o + 0x130) + 0x4C)));
        }
    }
}

extern void (*D_0066AA80)(void);
extern u8 D_0066AA90[];
unsigned long long func_001245F0(s32);
void func_00123E48(s32, u8 *);
void func_0024F008(void)
{
  s32 *new_var;
  new_var = &D_0066AA84;
  func_001245F0(*(*((s32 **) new_var)));
  func_00123E48(*(*((s32 **) new_var)), D_0066AA90);
  func_0024EF88();
  if (D_0066AA80 != 0)
  {
    D_0066AA80();
  }
}

void func_0024F070(void) {
    func_00149E38(*(u16 *)(*(u8 **)&D_0066AA84 + 0x4C), func_0024F008);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024F098);

extern s32 D_0066AAA0;
extern void (*D_0066AA80)(void);
void func_00131D68(s32, s32);

void func_0024F1D0(s32 a0) {
    func_00131D68(a0, D_0066AAA0);
    if (D_0066AA80 != NULL) {
        D_0066AA80();
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024F210);

void __assert(s32 a0, s32 a1, s32 a2) {
    fiprintf(*(s32 *)(*(u8 **)&_impure_ptr + 0xC), D_004919E8, a2, a0, a1);
    abort();
}
