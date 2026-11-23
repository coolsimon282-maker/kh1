// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

extern int D_00464B1C; /* glue.o's tty_opened (data still in the data segment) */
extern int D_0046AE48; /* glue.o's heap_ptr */

int DIntr(void);
int EIntr(void);
int SetVSyncFlag(void* flag, void* val);
int sceTtyInit(void);
int sceTtyRead(void* buf, int size);
int sceTtyWrite(const void* buf, int size);
int* __errno(void);
void func_0025F9A8(int n);

void sceResetttyinit(void) {
    D_00464B1C = 0;
}

void VSync(void) {
    int s;
    s = DIntr();
    *(volatile int*)0x1000F000 = 4;
    __asm__ volatile("sync");
    if (s) {
        EIntr();
    }
    while ((*(volatile int*)0x1000F000 & 4) == 0) {}
    s = DIntr();
    *(volatile int*)0x1000F000 = 4;
    __asm__ volatile("sync");
    if (s) {
        EIntr();
    }
}

long long VSync2(void) {
    volatile int flag;
    volatile long long val;
    int s;
    flag = 0;
    SetVSyncFlag((void*)&flag, (void*)&val);
    s = DIntr();
    *(volatile int*)0x1000F000 = 4;
    __asm__ volatile("sync");
    if (s) {
        EIntr();
    }
    while ((*(volatile int*)0x1000F000 & 4) == 0 && flag == 0) {}
    s = DIntr();
    *(volatile int*)0x1000F000 = 4;
    __asm__ volatile("sync");
    if (s) {
        EIntr();
    }
    return val;
}

int write(int fd, const void* buf, int size) {
    if (fd - 1 < 2U) {
        if (D_00464B1C == 0) {
            if (sceTtyInit() == 0) {
                return -1;
            }
            D_00464B1C = 1;
        }
        return sceTtyWrite(buf, size);
    }
    return -1;
}

int read(int fd, void* buf, int size) {
    if (fd == 0) {
        if (D_00464B1C == 0) {
            if (sceTtyInit() == 0) {
                return -1;
            }
            D_00464B1C = 1;
        }
        return sceTtyRead(buf, size);
    }
    return -1;
}

int open(void) {
    *__errno() = 5;
    return -1;
}

int close(int fd) {
    return -1;
}

int iotctl(void) {
    return -1;
}

long lseek(int fd, long offset, int whence) {
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", sbrk);

int isatty(int fd) {
    return 1;
}

struct glue_stat {
    int st_dev;
    int st_mode;
    char pad[0x40];
    long long st_blksize;
};

int fstat(int fd, struct glue_stat* st) {
    st->st_blksize = 0;
    st->st_mode = 0x2000;
    return 0;
}

int getpid(void) {
    return 1;
}

int kill(int pid, int sig) {
    if (pid == 1) {
        func_0025F9A8(sig);
    }
    return 0;
}

int stat(void) {
    *__errno() = 5;
    return -1;
}

int unlink(void) {
    *__errno() = 5;
    return -1;
}
