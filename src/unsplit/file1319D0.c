#include "common.h"

extern s32 D_003E8E08[];
void func_001F3110(s32);
void func_0020BD18(s32, s32);
s32 func_001FC308(s32, s32, s32, s32, s32, s32, s32, s32, s32);
u8 *func_001F3A20(u8 *, s32);
void func_0020B998(void);
void func_00231A80(void);
extern s32 D_003F7E94;
extern s32 D_003F7EC4;
extern s32 D_00647650;
extern s32 D_00647654;
extern s32 D_00647658;
extern s32 D_0064770C;
s32 func_001EC360(void);
void func_001F3840(s32);
s32 func_001F40C8(void);
s32 func_001F42B8(s32);
void func_001F82B0(void);
void func_001F9438(s32, s32, s32, s32, s32, s32, s32);
void func_0020BE10(s32);
void func_001FD858(u8 *);
s32 func_001FD518(u8 *);
s32 func_001FD618(u8 *);
s32 func_001FD548(u8 *);
s32 func_001FE5A0();
void func_00202FC0(u8 *);
s32 func_001FD590(u8 *);
void func_001F8F30(void);
extern u32 D_003E3D6C;
void func_001F8EE0(u8 *);
void func_0020DD38(u8 *, s32, s32, s32, s32, s32);
s32 func_001F0BD8(u32);
s32 func_001F0420(s32, s32);
s32 func_001F03A0(s32);
void func_00242EF8(s32, s32, s32, s32 *, s32 *);

extern s32 D_003F7D10[];
extern s32 D_00647664;
extern s32 D_00647668;
extern s32 D_006476F4;
extern s32 D_00647670[];
s32 func_001EC258(s32);

void func_002319D0(void) {
    s32 i;
    s32 s = func_001EC360();

    D_00647664 = s;
    D_00647668 = D_003F7D10[s];
    D_006476F4 = 0;
    for (i = 0; i < D_00647668; i++) {
        if ((D_00647670[i] = func_001EC258(i)) != 0) {
            D_006476F4++;
        }
    }
}

void func_001EC380(s32);
extern s32 D_00647664;
extern s32 D_00647668;
extern s32 D_006476F4;

void func_00231A80(void) {
    s32 d = D_00647668 - D_006476F4;
    if (d < 4) {
        if (D_00647664 < 4) {
            func_001EC380(D_00647664 + 1);
        } else if (D_00647664 == 4) {
            if (d == 0) func_001EC380(5);
        } else if (D_00647664 == 5) {
            if (d == 0) func_001EC380(6);
        }
    }
}

s32 func_00231B10(void) {
    s32 t0 = func_001EC360();
    return ((t0 ^ 0x6) == 0);
}

s32 func_00231B38(s32 a0, s32 a1) {
    u8 *p = (u8 *)D_003010F8 + a0 * 0x74;
    s32 n = 0, k;
    for (k = 0; k < p[0x25]; k++) { if (p[0x26 + k] == a1) n++; }
    return n;
}

void func_0011D598_v(s32) __asm__("func_0011D598");
extern u16 D_003F7C48[];
extern s32 D_0064765C;
extern s32 D_00647660;
extern s32 D_00647670[];
extern u16 D_003F7A70[];
extern s32 D_006476F4;
typedef struct { u8 pad[9]; u8 a[1]; } V231B98;
void func_001EC2C0(s32, s32);

void func_00231B98(void) {
    u8 *c;
    u16 *t;
    s32 n;

    if (D_00647660 > 0) {
        func_0011D598_v(0x12);
        if (D_00647670[D_0064765C] == 0) {
            D_00647670[D_0064765C] = 1;
            D_006476F4++;
            func_001EC2C0(D_0064765C, 1);
        }
        ((V231B98 *)D_003010F8)->a[D_00647660 + 0x490]++;
        c = (u8 *)&D_003F7C48[D_0064765C * 3];
        t = &D_003F7A70[c[2] * 2];
        for (n = c[3]; n > 0; n--, t += 2) {
            ((V231B98 *)D_003010F8)->a[t[0] + 0x490] -= t[1];
        }
    } else {
        func_0011D598(4);
    }
}

extern u16 D_003F7C48[];
extern s32 D_0064765C;
extern s32 D_00647660;
extern s32 D_00647670[];
extern u16 D_003F7A70[];
typedef struct { u8 pad[9]; u8 a[1]; } V231CD0;
void func_00231CD0(s32 a0) {
    u8 *c = (u8 *)&D_003F7C48[D_0064765C * 3];
    u16 *t;
    s32 n;

    if (c[4] == 1 && D_00647670[D_0064765C] != 0) {
        D_00647660 = -3;
        return;
    }
    t = &D_003F7A70[c[2] * 2];
    n = c[3];
    D_00647660 = a0;
    for (; n > 0; n--, t += 2) {
        if (((V231CD0 *)D_003010F8)->a[t[0] + 0x490] < t[1]) {
            D_00647660 = -1;
            return;
        }
    }
    if (((V231CD0 *)D_003010F8)->a[D_00647660 + 0x490] >= 99) D_00647660 = -2;
}

s32 func_00231DD0(s32 a0) {
    u8 *c = (u8 *)&D_003F7C48[a0 * 3];
    u16 *t;
    s32 n;

    if (c[4] == 1 && D_00647670[a0] != 0) {
        return -3;
    }
    t = &D_003F7A70[c[2] * 2];
    n = c[3];
    for (; n > 0; n--, t += 2) {
        if (((V231CD0 *)D_003010F8)->a[t[0] + 0x490] < t[1]) {
            return -1;
        }
    }
    if (((V231CD0 *)D_003010F8)->a[*(u16 *)c + 0x490] >= 99) {
        return -2;
    }
    return 0;
}

/* func_00231EA0 is layout-sensitive (notes/f1.md F1/F24): ee-gcc 2.96 makes several tie decisions in it
 * (combine folding `lhu D_003F7C48(reg)`, two saved-register ties) that depend on how many declarations precede
 * it in the file. Since the split into its own file (26 Nov) it needs no layout externs. */
extern u16 D_003F7C48[];
extern s32 D_003F7E98;
extern s32 D_0064765C;
extern void (*D_0064764C)(s32);
extern s32 D_00647660;
extern void (*D_00647648)(s32);
extern s32 D_006476F4;
extern s32 D_00647670[];
extern s32 D_003F7D30[];
extern s32 D_003F7D40[];
extern s32 D_003F7D50[];
void func_00231CD0(s32);
s32 func_00231DD0(s32);

void func_00231EA0(u8 *a0) {
    s32 pos[2];
    s32 col[4];
    s32 item;
    s16 cnt;
    s32 j;
    s32 k;
    s32 y;
    s32 c;
    s32 x;
    s32 e;

    if (D_003F7E98 != 0 && func_001F42B8((s32)a0)) {
        func_001FD858(a0);
        func_0020BD18((s32)a0, 8);
        D_00647654 = func_001FD618(a0);
        D_00647658 = func_001FD518(a0);
        D_0064765C = func_001FD548(a0);
        if (func_001FE5A0(a0)) {
            func_00231CD0(D_003F7C48[D_0064765C * 3]);
            if (D_0064764C != NULL) {
                D_0064764C(D_00647660);
            }
        }
    }
    item = D_003F7C48[D_0064765C * 3];
    if (D_00647648 != NULL) {
        D_00647648(item);
    }
    cnt = *(s16 *)(a0 + 0xCC);
    D_003E8E08[0] = D_006476F4;
    D_003E8E08[1] = cnt;
    func_001F9438((s32)a0, 0, 0xA0, 0x2A, 0x1AE, 0xF, 0x80E6E6E6);
    j = 0;
    func_00202FC0(a0);
    k = D_00647654;
    y = func_001FD590(a0);
    func_001F8EE0(a0);
    for (; j < 7 && k < cnt; j++, k++) {
        if (((u8)D_003F7C48[k * 3 + 2] == 1 && D_00647670[k] != 0) || func_00231DD0(k) != 0) {
            c = (j == D_00647658) ? 3 : 2;
        } else {
            c = j == D_00647658;
        }
        func_0020DD38(a0, c, 0x1B, y, 0xCC, D_003F7C48[k * 3]);
        if (D_00647670[k] != 0) {
            func_001FC308((s32)a0, 0xBD, y + 7, 0, 0, 0x37, 0, 0x80009100, 0x8027E4D4);
        }
        y += 0x1C;
    }
    func_001F8F30();
    x = 0x12F;
    pos[0] = *(s32 *)(a0 + 0xB0) + 0x1410;
    pos[1] = *(s32 *)(a0 + 0xB4) + 0xEB0;
    col[0] = 0x80;
    col[1] = 0x80;
    col[2] = 0x80;
    col[3] = *(s32 *)(a0 + 0x90);
    for (j = 0; (u32)j < D_003E3D6C && (e = func_001F0BD8(j)) != 0; j++) {
        func_001FC308((s32)a0, x, 0xDA, 0, 0, 0x15, 0, 0x26E6E6E6, 0x26E6E6E6);
        func_001FC308((s32)a0, x, 0xDA, 0, 0, 0x16, 0, 0x4C000000, 0x4C000000);
        func_001FB428((s32)a0, 1, 0, 0, x + 0x21, 0x10D, func_001F0420(*(u8 *)(j + (s32)D_003010F8 + 0x48E), item), 0xF, 0x80808080);
        pos[0] += D_003F7D40[j];
        pos[1] += D_003F7D50[j];
        func_00242EF8(e, D_003F7D30[j], D_003F7D30[j], pos, col);
        pos[0] = pos[0] - D_003F7D40[j] + 0x300;
        pos[1] -= D_003F7D50[j];
        x += 0x30;
    }
    func_001FC308((s32)a0, x, 0xDA, 0, 0, 0x15, 0, 0x26E6E6E6, 0x26E6E6E6);
    func_001FC308((s32)a0, x, 0xDA, 0, 0, 0x16, 0, 0x4C000000, 0x4C000000);
    func_001FC308((s32)a0, x - 8, 0xE6, 0, 0, 7, 0, 0x80808080, 0x80808080);
    func_001FB428((s32)a0, 1, 0, 0, x + 0x21, 0x10D, func_001F03A0(item), 0xF, 0x80808080);
}

extern u8 D_003F7D88[];
void func_00205B30(u8 *, u8 *);
s32 func_00207CA0(s32);
void func_001FB428(u8 *, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00207D60(u8 *, s32, s32, s32, s32, s32, s32);
typedef struct { u8 pad[9]; u8 a[1]; } V232390;

void func_00232390(u8 *a0) {
    s32 i;
    u8 *p;
    u8 *c;
    u16 *t;
    s32 n;
    s32 y;
    s32 id;
    s32 need;
    s32 have;
    s32 col;
    s32 r;

    p = D_003F7D88;
    for (i = 0; i < 7U; i++) {
        func_00205B30(a0, p);
        p += 0x20;
    }
    func_001FC308((s32)a0, 0xB, 0xD, 0, 0, 0x3D, 0, 0x80009100, 0x8027E4D4);
    func_001F9438((s32)a0, 1, 0x1EA, 0xB, 0x1AA, 0xF, 0x4D508B2E);
    y = 0x3F;
    func_001F9438((s32)a0, 0, 0x2C, 0x2A, 0x1AB, 0xF, 0x80C8C8C8);
    func_001F9438((s32)a0, 0, 0x10F, 0x2A, 0x1AC, 0xF, 0x80C8C8C8);
    func_001F9438((s32)a0, 1, 0x1E4, 0x2A, 0x1AD, 0xF, 0x80C8C8C8);
    c = (u8 *)&D_003F7C48[D_0064765C * 3];
    t = &D_003F7A70[c[2] * 2];
    n = c[3];
    for (i = 0; i < n; i++) {
        id = t[0];
        need = t[1];
        t += 2;
        have = ((V232390 *)D_003010F8)->a[id + 0x490];
        col = (have < need) ? 2 : 0;
        func_0020DD38(a0, col, 0xF7, y, 0xC2, id);
        r = func_00207CA0(0);
        func_001F9438((s32)a0, 0, 0x190, y + 7, 0x55, 0xC, r);
        func_001FB428(a0, 0, 1, 0, 0x1A2, y + 7, need, 0xC, r);
        func_00207D60(a0, col, 0x1BD, y, 0x1E0, have, 0xC);
        y += 0x1C;
    }
}

s32 func_002325F8(void) {
    if (func_001F40C8() != 0) {
        func_001F82B0();
        func_0020B998();
        return 0;
    }
    D_003F7E94 = 0;
    func_00231A80();
    return 4;
}

void func_001F3110_v(void) __asm__("func_001F3110");
extern s32 D_003F7E98;
extern s32 D_00647668;
extern u8 D_003F7E70[];
extern u8 D_003F7D60[];
void func_0020B968(void);
void func_0020BB90(s32, s32);
void func_0020BDA8(s32);
void Party_RefreshStats(void);
void func_002319D0(void);
void UiObject_InsertAfter(u8 *, s32);
s32 func_002325F8(void);

void func_00232640(s32 a0, s32 a1) {
    u8 *p;
    s32 r;

    if (D_003F7E94 == 0) {
        func_001F3110_v();
        func_0020B968();
        func_0020BB90(0xE7, 0);
        func_0020BDA8(0x10);
        D_003F7E94 = 1;
        D_003F7E98 = 1;
        Party_RefreshStats();
        D_00647648 = (void (*)(s32))a0;
        D_0064764C = (void (*)(s32))a1;
        func_002319D0();
        r = (s32)func_001F3A20(D_003F7E70, 1);
        D_00647650 = r;
        if (r != 0) {
            p = func_001F3A20(D_003F7D60, 1);
            if (p != NULL) {
                UiObject_InsertAfter(p, D_00647650);
                *(s16 *)(p + 0xCC) = D_00647668;
                *(s16 *)(p + 0xD0) = D_00647654 << 4;
                *(s16 *)(p + 0xD2) = D_00647658 << 4;
            }
        }
        do {
            TaskSystem_AddTask(0x2BF84, func_002325F8);
        } while (0);
    }
}

void func_00232758(void) {
    func_001F3840(D_00647650);
    func_0020BE10(0x10);
}

void func_00232780(void) {
    D_003F7E94 = 0;
}

void func_00232790(void) {
    D_003F7E94 = 0;
    D_00647654 = 0;
    D_00647658 = 0;
}

extern s32 D_003F7EC8;
extern s32 D_006476F8;
extern s32 D_006476FC;
extern s32 D_00647700;
extern s32 D_00647704;
extern s32 D_00647708;
s32 func_001FE570(u8 *);
void func_001FE180(u8 *);
s32 func_001F4390(s32);
void func_0010E8A0(s32, s32, s32);
void func_001FEA38(u8 *);
void func_002040C8(u8 *);
void func_001F8E18(u8 *);

void func_002327B0(u8 *a0) {
    s32 x, y, k, lim, i, y2;

    *(s16 *)(a0 + 0xCC) = *(u16 *)D_00647700;
    if (func_001F42B8((s32)a0)) {
        if (D_003F7EC8 != 0) {
            func_001FD858(a0);
            if (func_001FE570(a0)) {
                D_003F7EC8 = 0;
                if (D_006476FC != 0) {
                    ((void (*)(s32))D_006476FC)(func_001FD548(a0));
                }
            }
        } else {
            func_001FE180(a0);
        }
    }
    if (func_001F4390) {
        x = ((*(s32 *)(a0 + 0xB0) - 0x7000) >> 4) + 0x1C;
        y = (*(s32 *)(a0 + 0xB4) - 0x7400) >> 4;
        func_0010E8A0(x, y + 0x28, D_00647708);
        func_001FEA38(a0);
        func_002040C8(a0);
        k = func_001FD618(a0);
        lim = *(s16 *)(a0 + 0xCC);
        y2 = y + func_001FD590(a0);
        func_001F8E18(a0);
        for (i = 11; i >= 0; i--, k++, y2 += 24) {
            if (k < lim) {
                func_0010E8A0(x, y2, D_00647704 + k * 32);
            }
        }
        func_001F8F30();
    }
    if (D_006476F8 != 0) {
        ((void (*)(s32))D_006476F8)(func_001FD548(a0));
    }
}

s32 func_00232960(void) {
    if (func_001F40C8() != 0) {
        func_001F82B0();
        return 0;
    }
    D_003F7EC4 = 0;
    return 4;
}

extern s32 D_003F7EC8;
extern s32 D_006476F8;
extern s32 D_006476FC;
extern s32 D_00647700;
extern s32 D_00647704;
extern s32 D_00647708;
typedef struct {
    u8 pad0[0xC];
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    u8 pad14[4];
    s16 unk18;
} D3F7EA0_t;
extern D3F7EA0_t D_003F7EA0;


void func_002329A0(u8 *a0, s32 a1, s32 a2) {
    s32 x0, y0, w, h, e;
    func_001F3110((s32)a0);
    D_003F7EC4 = 1;
    D_003F7EC8 = 1;
    D_00647700 = (s32)a0;
    D_006476F8 = a1;
    D_006476FC = a2;
    D_00647704 = (s32)(a0 + 4);
    D_00647708 = (s32)(a0 + 0x644);
    x0 = (u32)(*(s32 *)(a0 + 0x664) - 0x7000) >> 4;
    y0 = (u32)(*(s32 *)(a0 + 0x668) - 0x7400) >> 4;
    w = ((u32)(*(s32 *)(a0 + 0x66C) - 0x7000) >> 4) - x0 + 1;
    h = ((u32)(*(s32 *)(a0 + 0x670) - 0x7400) >> 4) - y0 + 1;
    D_003F7EA0.unk10 = w;
    D_003F7EA0.unk12 = h;
    D_003F7EA0.unk18 = w - 0x28;
    D_003F7EA0.unkC = x0;
    D_003F7EA0.unkE = y0;
    e = (s32)func_001F3A20((u8 *)&D_003F7EA0, 0);
    D_0064770C = e;
    func_0011ED30(0x2C01A, func_00232960);
}

void func_00232AA8(void) {
    func_001F3840(D_0064770C);
}

void func_00232AC8(void) {
}
