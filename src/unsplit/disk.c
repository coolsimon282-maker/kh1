// Final Mix's version of disk (JP: src/disk.c, 0x24A010-0x24AAA8; here 0x24D4A0-0x24E098).
// Split out of the placeholder seg_14B9A8; FM only (the JP/EU builds use src/disk.c).
#include "common.h"

extern u8 D_004919B0[];
void sceDevctl(u8 *, s32, s32, s32, s32, s32);

extern s32 D_0046A60C;

s32 func_0024D4A0(void) {
    return D_0046A60C;
}

typedef struct {
    char c[11];
} S11_D4B0;
typedef struct {
    char c[16];
} S16_D4B0;
extern S11_D4B0 D_0048B478;
extern S16_D4B0 D_0048B488;
extern char D_00491948[];
extern char D_00491958[];
extern char D_00491968[];
extern char D_00491970[];
extern s32 D_0046A610;
s32 func_00120A20(char *, s32, char *, s32 *);
void func_0024D808(void);

s32 func_0024D4B0(void) {
    S11_D4B0 a = D_0048B478;
    S16_D4B0 b = D_0048B488;
    s32 r;

    D_0046A610 = 0;
    D_0046A60C = 0;
    func_00120A20(D_00491948, 0, NULL, &r);
    if (func_00120A20(D_00491958, 0, NULL, &r) < 0) {
        return 1;
    }
    if (func_00120A20(D_00491968, 10, a.c, &r) < 0) {
        return 1;
    }
    if (func_00120A20(D_00491970, 0x12, b.c, &r) < 0) {
        return 1;
    }
    D_0046A60C = 1;
    func_0024D808();
    return 0;
}

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

void func_0024D618(void *arg) {
    s32 sema = (s32)arg;
    extern s32 sceDevctl_q(u8 *, s32, s32, s32, void *, s32) __asm__("sceDevctl");
    extern s32 WaitSema(s32);
    extern s32 sceCdPowerOff(int *);
    extern s32 sceSifSearchModuleByName(const char *);
    extern char D_00491978[];
    extern u8 D_00491980[];
    extern u8 D_00491988[];
    extern u8 D_00491990[];
    int stat;

    for (;;) {
        WaitSema(sema);
        D_002C1EB8.u8 = D_002C1EB8.u8 & ~0x18 | 0x10;
        if (sceSifSearchModuleByName(D_00491978) >= 0) {
            if (sceDevctl_q(D_00491980, 0x4807, 0, 0, 0, 0) != 3) {
                sceDevctl_q(D_00491990, 0x5003, 0, 0, 0, 0);
                goto b;
            }
            while (sceDevctl_q(D_00491988, 0x4402, 0, 0, 0, 0) < 0) {
                    func_0024D5D0(100000);
                }
            goto done;
        b:
            while (sceDevctl_q(D_00491980, 0x4806, 0, 0, 0, 0) < 0) {
                    func_0024D5D0(100000);
                }
        } else {
            while (sceDevctl_q(D_00491988, 0x4402, 0, 0, 0, 0) < 0) {
                func_0024D5D0(100000);
            }
        }
    done:
        while (sceCdPowerOff(&stat) == 0) {
            func_0024D5D0(100000);
        }
        D_002C1EB8.u8 |= 0x18;
        D_0046A610++;
    }
}

void D_0024D7B0(void *arg) {
    extern s32 iSignalSema(s32);

    D_002C1EB8.u8 = D_002C1EB8.u8 & ~0x18 | 0x8;
    if (func_0024D4A0() != 0) {
        iSignalSema((s32)arg);
    }
}

#include "eekernel.h"
int *sceCdPOffCallback(void (*func)(void *), void *addr);
void func_0024D618(void *);
extern u8 D_00669A80[];
extern u8 D_00494050[];

void func_0024D808(void) {
    struct ThreadParam tp;
    struct SemaParam sp;
    s32 sema;

    sp.maxCount = 1;
    sp.initCount = 0;
    sp.option = 0;
    sema = CreateSema(&sp);
    tp.stackSize = 0x1000;
    tp.gpReg = D_00494050;
    tp.entry = func_0024D618;
    tp.stack = D_00669A80;
    tp.initPriority = 1;
    StartThread(CreateThread(&tp), (void *)sema);
    sceCdPOffCallback((void (*)(void *))D_0024D7B0, (void *)sema);
}

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

extern s32 D_0046A614;
extern u32 D_0046A608_u __asm__("D_0046A608");
int sceOpen(const char *filename, int flag, ...);
long sceLseek64(int fd, long offset, int whence);
int sceClose(int fd);

s32 func_0024D9F0(void) {
    s32 *p = &D_0046A614;
    s32 fd;
    s32 k;
    long sz;
    s32 r;

    *p = 0x5A;
    fd = sceOpen(func_0024D8E0(), 1);
    *p = 0x64;
    if (fd < 0) {
        r = 1;
    } else {
        sz = sceLseek64(fd, 0, 2);
        *p = 0x6E;
        sceClose(fd);
        *p = 0x78;
        r = 1;
        if (D_0046A608_u == sz) {
            r = 0;
        }
    }
    return r;
}

void func_0024DAA0(void) {
    sceDevctl(D_004919B0, 0x4807, 0, 0, 0, 0);
}

s32 sceDevctl_r(u8 *, s32, s32, s32, void *, s32) __asm__("sceDevctl");
extern s32 D_0046A614;

s32 func_0024DAD0(u8 *dev, s32 n) {
    s32 *p;
    u32 buf;

    sceDevctl_r(dev, 0x4802, 0, 0, 0, 0);
    p = &D_0046A614;
    *p = 0x3C;
    buf = 0;
    if (sceDevctl_r(dev, 0x480A, 0, 0, &buf, 4) != 0) {
        return 0;
    }
    *p = 0x46;
    if ((s32)(buf >> 18) < n) {
        return 0;
    }
    return 1;
}

extern s32 D_0046A674;

s32 func_0024DB68(void) {
    return D_0046A674;
}

extern char D_004919B8[];
int sceIoctl2(int, int, void *, unsigned int, void *, unsigned int);
int sceDclose(int);

s32 func_0024DB78(s32 size) {
    A2MountF *m = &D_0046A688_f;
    s32 *st = &D_0046A674;
    s32 *p;
    s32 n = 0;
    s32 mounted;
    s32 fd;
    s32 k;
    char buf[0x40];

    mounted = m->unk_10;
    *st = 0;
    if (mounted != 0) {
        func_0024D9A0();
    }
    p = &D_0046A614;
    *p = 0x28;
    sprintf(buf, D_004919B8, m->unk_04(), D_0046A650);
    fd = sceOpen(buf, 1);
    if (fd >= 0) {
        n = sceIoctl2(fd, 0x6803, 0, 0, 0, 0);
        if (n < 0) {
            n = 0;
        }
        n++;
        sceDclose(fd);
    }
    *p = 0x32;
    k = ((((u32)(size + 0xFFFFF) >> 20) + 0x7F) >> 7) + 1;
    if (func_0024DAD0(D_004919B0, k - n) == 0) {
        *st = -1;
    }
    if (mounted != 0) {
        func_0024D8F0();
    }
    *p = 0x50;
    return *st;
}

typedef struct {
    u8 stat[0x40];
    char d_name[256];
    void *d_private;
} Dirent24DCC8;
s32 sceDopen(u8 *);
s32 sceDread(s32, Dirent24DCC8 *);
s32 sceDclose(s32);
s32 strcmp(const char *, const char *);

s32 func_0024DCC8(u8 *path, u8 *name) {
    Dirent24DCC8 d;
    s32 fd;
    s32 k;
    s32 n;
    s32 found = 0;

    fd = sceDopen(path);
    if (fd < 0) {
        return 0;
    }
    n = 0;
    while (sceDread(fd, &d) > 0) {
        n++;
    }
    sceDclose(fd);
    if (n == 0) {
        return 0;
    }
    fd = sceDopen(path);
    if (fd < 0) {
        return 0;
    }
    while (sceDread(fd, &d) > 0) {
        if (strcmp(d.d_name, (char *)name) == 0) {
            found = 1;
        }
    }
    sceDclose(fd);
    return found;
}

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
s32 func_0024DB78(s32);
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
