/**
 * Disc access (disk_*): timers, the disc thread, game code and image names, mount / unmount, status, seek and block
 * reads. JP/EU: 0x24A010-0x24AAA8. Final Mix (#ifdef VERSION_FM): 0x24D4A0-0x24E098; its functions are paired with
 * JP's by address order and size where they correspond (FM's func_0024D618 and func_0024DDF8 regions differ).
 */
#include "common.h"

#ifdef VERSION_FM
extern u8 D_004919B0[];
void sceDevctl(u8 *, s32, s32, s32, s32, s32);

extern s32 D_0046A60C;

s32 func_0024D4A0(void) {
    return D_0046A60C;
}
#else
#include "disk.h"
#include "io.h"
#include "sifdev.h"
#include "sdk/libcdvd.h"
#include "eekernel.h"

s32 func_0024A010(void);
s32 disk_Mount(void);
s32 disk_Unmount(void);
s32 func_0024A4A8(void);
s32 disk_GetStatus(void);
s32 func_0024A630(s32);
s32 disk_Seek(char*, char*);
s32 disk_SetBlock(s32*);

s32 disk_BlockSize = 0; // file length

s32 D_004642EC = 0;
s32 D_004642F0 = 0;
s32 D_004642F4 = 0;
s32 disk_Timer = 0;
char disk_SectorSize[] = "128M";
char disk_Gamecode[] = "PP.SLPS-25105.0.KINGDOM";
char D_00464320[] = "haneman0";
char D_00464330[] = "mangan01";
char disk_ImgName[] = "pfs0:kingdom.img";
s32 D_00464354 = 0;
s32 D_00464358 = 0;
s32 D_0046435C = 0;

struct DiskManager disk_Mgr = {
    .unk_00 = func_0024A368,
    .getGamecode = disk_GetGamecode,
    .unk_08 = func_0024A388,
    .unk_0C = func_0024A398,
    .isMounted = FALSE,
    .getImgName = disk_GetImgName,
    .unk_18 = func_0024A8B0,
    .unk_1C = func_0024AA88,
    .unk_20 = func_0024AA98,
};

s32 D_00464384 = 0;
extern s32 D_0048DB00; // gp0 value

char disk_ThreadStack[0x1000];

s32 func_0024A010(void) {
    return D_004642EC;
}
#endif

#ifdef VERSION_FM
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
#else
INCLUDE_ASM("asm/nonmatchings/disk", func_0024A020);
#endif

#ifdef VERSION_FM
extern s32 D_0046A618;

void func_0024D5D0(s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        D_0046A618++;
    }
}
#else
void disk_Timeout(s32 time) {
    if (0 < time) {
        do {
            disk_Timer++;
            time--;
        } while (time != 0);
    }
}
#endif

#ifdef VERSION_FM
s32 func_0024D608(void) {
    return D_0046A618;
}
#else
s32 disk_GetTimer(void) {
    return disk_Timer;
}
#endif

#ifdef VERSION_FM
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
#endif

#ifndef VERSION_FM
void func_0024A188(void* sema) {
    int iVar1;
    int stat[4];

    do {
        WaitSema((s32)sema);
        D_002C1EB8.u8 = D_002C1EB8.u8 & ~0x18 | 0x10;
        iVar1 = func_0024A010();
        if (iVar1 != 0) {
            /* close all files */
            sceDevctl("pfs:", PDIOC_CLOSEALL, NULL, 0, NULL, 0);
        }
        while (sceDevctl("hdd:", HDIOC_DEV9OFF, NULL, 0, NULL, 0) < 0) {
            disk_Timeout(100000);
        }
        while (sceCdPowerOff(stat) == 0) {
            disk_Timeout(100000);
        }
        D_002C1EB8.u8 |= 0x10 | 0x8;
        D_004642F0++;
    } while (TRUE);
}

void func_0024A278(void* sema) {
    D_002C1EB8.s8 = D_002C1EB8.s8 & ~(0x10 | 0x8) | 0x8;
    if (func_0024A010() != 0) {
        iSignalSema((s32)sema);
    }
}
#endif

#ifdef VERSION_FM
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
#else
s32* disk_StartThread(void) {
    struct ThreadParam threadParam;
    s32 sema;
    struct SemaParam semaParam;
    int thread;

    semaParam.maxCount = 1;
    semaParam.initCount = 0;
    semaParam.option = 0;
    sema = CreateSema(&semaParam);
    threadParam.initPriority = 1;
    threadParam.stackSize = sizeof(disk_ThreadStack);
    threadParam.gpReg = &D_0048DB00;
    threadParam.entry = func_0024A188;
    threadParam.stack = disk_ThreadStack;
    thread = CreateThread(&threadParam);
    StartThread(thread, (void*)sema);
    return sceCdPOffCallback(func_0024A278, (void*)sema);
}
#endif

#ifdef VERSION_FM
extern u8 D_0046A620[];

void *func_0024D8A0(void) {
    return D_0046A620;
}
#else
char* func_0024A368(void) {
    return disk_SectorSize;
}
#endif

#ifdef VERSION_FM
extern u8 D_0046A628[];

void *func_0024D8B0(void) {
    return D_0046A628;
}
#else
char* disk_GetGamecode(void) {
    return disk_Gamecode;
}
#endif

#ifdef VERSION_FM
extern u8 D_0046A640[];

void *func_0024D8C0(void) {
    return D_0046A640;
}
#else
char* func_0024A388(void) {
    return D_00464320;
}
#endif

#ifdef VERSION_FM
extern u8 D_0046A650[];

void *func_0024D8D0(void) {
    return D_0046A650;
}
#else
char* func_0024A398(void) {
    return D_00464330;
}
#endif

#ifdef VERSION_FM
extern u8 D_0046A660[];

void *func_0024D8E0(void) {
    return D_0046A660;
}
#else
char* disk_GetImgName(void) {
    return disk_ImgName;
}
#endif

#ifdef VERSION_FM
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
#else
b32 disk_Mount(void) {
    char blkdevname[128];

    if (disk_Mgr.isMounted == FALSE) {
        sprintf(blkdevname, "hdd0:%s,%s", disk_Mgr.getGamecode(), disk_Mgr.unk_08());
        if (sceMount("pfs0:", blkdevname, SCE_MT_RDWR, NULL, 0) < 0) {
            return TRUE;
        }
        disk_Mgr.isMounted = TRUE;
    }
    return FALSE;
}
#endif

#ifdef VERSION_FM
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
#else
b32 disk_Unmount(void) {
    if (disk_Mgr.isMounted != FALSE) {
        if (sceUmount("pfs0:") == 0) {
            disk_Mgr.isMounted = FALSE;
            return FALSE;
        }
    }
    return TRUE;
}
#endif

#ifdef VERSION_FM
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
#else
b32 func_0024A4A8(void) {
    char* filename;
    s32 fd;
    u64 offset;
    s32 ret;

    D_004642F4 = 90;
    filename = disk_GetImgName();
    fd = sceOpen(filename, SCE_RDONLY);
    D_004642F4 = 100;
    ret = TRUE;
    if (fd >= 0) {
        offset = sceLseek64(fd, 0, 2);
        D_004642F4 = 110;
        sceClose(fd);
        D_004642F4 = 120;
        ret = disk_BlockSize; // seems fake?
        ret = TRUE;
        if ((u32)disk_BlockSize == offset) {
            ret = FALSE;
        }
    }
    return ret;
}
#endif

#ifdef VERSION_FM
void func_0024DAA0(void) {
    sceDevctl(D_004919B0, 0x4807, 0, 0, 0, 0);
}
#else
s32 disk_GetStatus(void) {
    return sceDevctl("hdd0:", HDIOC_STATUS, NULL, 0, NULL, 0);
}
#endif

#ifdef VERSION_FM
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
#else
b32 disk_IsSpaceAvailable(char* devname, s32 filesize) {
    u32 bufp; // installable size, in number of 256kB sectors

    // get total number of sectors on the disk
    sceDevctl(devname, HDIOC_TOTALSECTOR, NULL, 0, NULL, 0);

    D_004642F4 = 60;
    bufp = NULL;

    // return installable size into bufp if space is available
    if (sceDevctl(devname, HDIOC_FREESECTOR, NULL, 0, &bufp, 4) != 0) {
        return FALSE;
    }

    D_004642F4 = 70;
    if ((s32)((u32)bufp >> 0x12) < filesize) {
        return FALSE;
    }
    return TRUE;
}
#endif

#ifdef VERSION_FM
extern s32 D_0046A674;

s32 func_0024DB68(void) {
    return D_0046A674;
}
#else
s32 func_0024A620(void) {
    return D_00464354;
}
#endif

#ifdef VERSION_FM
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
#else
s32 func_0024A630(s32 blocksize) {
    char filename[0x40];
    s32 fd;
    int val;

    s32 temp = 0;
    s32 mounted = disk_Mgr.isMounted;

    D_00464354 = 0;
    if (mounted != FALSE) {
        disk_Unmount();
    }
    D_004642F4 = 40;
    sprintf(filename, "hdd0:%s,,%s", disk_Mgr.getGamecode(), &D_00464330);
    fd = sceOpen(filename, SCE_RDONLY);
    if (fd >= 0) {
        temp = sceIoctl2(fd, HIOCNSUB, NULL, 0, NULL, 0);
        if (temp < 0) {
            temp = 0;
        }
        temp++;
        sceDclose(fd);
    }
    D_004642F4 = 50;
    val = (((((u32)(blocksize + 0xFFFFF)) >> 20) + 0x7F) >> 7) + 1;
    if (disk_IsSpaceAvailable("hdd0:", val - temp) == FALSE) {
        D_00464354 = -1;
    }
    if (mounted != FALSE) {
        disk_Mount();
    }
    D_004642F4 = 80;
    return D_00464354;
}
#endif

#ifdef VERSION_FM
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
#else
b32 disk_Seek(char* dirname, char* query) {
    struct sce_dirent sp;
    s32 fd;
    s32 buflen;
    s32 bFoundQuery = FALSE;

    fd = sceDopen(dirname);
    if (fd < 0) {
        return FALSE;
    }

    buflen = 0;
    while (sceDread(fd, &sp) > 0) {
        buflen += 1;
    }
    sceDclose(fd);

    if (buflen == 0) {
        return FALSE;
    }

    fd = sceDopen(dirname);
    if (fd < 0) {
        return FALSE;
    }

    while (sceDread(fd, &sp) > 0) {
        if (strcmp(sp.d_name, query) == 0) {
            bFoundQuery = TRUE;
        }
    }
    sceDclose(fd);
    return bFoundQuery;
}
#endif

#ifdef VERSION_FM
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
#else
s32 disk_SetBlock(s32* isoBlock) {
    s32 length = 0;
    KingdomFile* kingdomFile;

    if (isoBlock != NULL) {
        *isoBlock = 0;
    }

    kingdomFile = cdvd_FindFile("kingdom.img");
    if (kingdomFile != NULL) {
        length = kingdomFile->length;
        if (isoBlock != NULL) {
            *isoBlock = kingdomFile->isoBlock;
        }
    }
    return length;
}
#endif

#ifdef VERSION_FM
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
#endif

#ifndef VERSION_FM
s32 func_0024A8B0(s32 arg0) {
    s32 cond;
    s32 diskStatus;

    D_004642F4 = 0;
    D_00464358 = D_0046435C = 0;

    if (func_0024A010() == 0) {
        return D_00464358;
    }

    D_004642F4 = 10;
    disk_Unmount();
    if (disk_Seek("hdd0:", disk_Gamecode)) {
        cond = TRUE;
        D_00464384 = 1;
    } else {
        cond = FALSE;
        D_00464384 = 0;
    }
    disk_BlockSize = disk_SetBlock(NULL);
    D_004642F4 = 20;
    diskStatus = disk_GetStatus();
    D_004642F4 = 30;
    switch (abs(diskStatus) & 0xF) {
        case 0:
            func_0024A630(disk_BlockSize);
            if (disk_Mount() != 0) {
                D_00464358 = 1;
                if (cond) {
                    D_00464358 = 3;
                    D_0046435C = 2;
                }
            } else if (func_0024A4A8() != 0) {
                D_00464358 = 3;
                disk_Unmount();
                D_0046435C = 2;
            } else {
                D_00464358 = 2;
            }
            break;
        case 1:
            D_00464358 = 1;
            D_0046435C = 1;
            break;
        case 2:
            D_00464358 = 1;
            D_0046435C = 4;
            break;
        case 3:
            D_00464358 = 1;
            D_0046435C = 3;
            break;
    }
    D_004642F4 = 130;
    return D_00464358;
}
#endif

#ifdef VERSION_FM
extern s32 D_0046A67C;

s32 func_0024E078(void) {
    return D_0046A67C;
}
#else
s32 func_0024AA88(void) {
    return D_00464358;
}
#endif

#ifdef VERSION_FM
void func_0024E088(s32 x) {
    D_0046A67C = x;
}
#else
void func_0024AA98(s32 arg0) {
    D_00464358 = arg0;
}
#endif

#ifdef VERSION_FM
// .data (0x0046A608-0x0046A6B0); the same layout as JP's disk.c (JP names in the comments)
typedef struct {
    /* 0x00 */ void* (*unk_00)(void);
    /* 0x04 */ void* (*getGamecode)(void);
    /* 0x08 */ void* (*unk_08)(void);
    /* 0x0C */ void* (*unk_0C)(void);
    /* 0x10 */ s32 isMounted;
    /* 0x14 */ void* (*getImgName)(void);
    /* 0x18 */ s32 (*unk_18)(void);
    /* 0x1C */ s32 (*unk_1C)(void);
    /* 0x20 */ void (*unk_20)(s32);
} XDiskMgr; // JP: DiskManager (include/disk.h); read here through A2Mount / A2MountF

#define DATA_LABEL(name, base, off) __asm__(".globl " #name "\n" #name " = " #base " + " #off)

s32 D_0046A608 = 0; // disk_BlockSize
s32 D_0046A60C = 0;
s32 D_0046A610 = 0;
s32 D_0046A614 = 0;
s32 D_0046A618 = 0; // disk_Timer
u8 D_0046A620[] = "128M";                    // disk_SectorSize
u8 D_0046A628[] = "PP.SLPS-25198.0.KINGDOM"; // disk_Gamecode
u8 D_0046A640[] = "haneman0";
u8 D_0046A650[] = "mangan01";
u8 D_0046A660[] = "pfs0:kingdom.img";        // disk_ImgName
s32 D_0046A674 = 0;
s32 D_0046A678 = 0;
s32 D_0046A67C = 0;
s32 D_0046A680 = 0;
XDiskMgr disk_Mgr_fm __asm__("D_0046A688") = { // disk_Mgr
    func_0024D8A0, func_0024D8B0, func_0024D8C0, func_0024D8D0, 0,
    func_0024D8E0, func_0024DDF8, func_0024E078, func_0024E088,
};
DATA_LABEL(D_0046A68C, D_0046A688, 0x4);  // .getGamecode
DATA_LABEL(D_0046A6A4, D_0046A688, 0x1C); // .unk_1C (xblade)
DATA_LABEL(D_0046A6A8, D_0046A688, 0x20); // .unk_20 (xkingdom)
s32 D_0046A6AC = 0;
#else
// blocked by subsequent 4-byte aligned function breaking split

// s32 func_0024AAA8(void) {
//     return D_0046435C;
// }
#endif
