// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

/* The cache loops: Hit Writeback Invalidate (0x14) / Hit Invalidate (0x16) of every D-cache line (both ways)
   whose tag (Index Load Tag 0x10, then TagLo) falls in [start, end]. ee-as 991111 would put a nop after
   the mfc0 (its next instruction reads the register), so the mfc0 is kept in .set noreorder. */
#define MFC0_STATUS(dst) __asm__ __volatile__("mfc0 %0, $12" : "=r"(dst))
int DIntr(void);
int EIntr(void);

void _sceSDC(unsigned int start, unsigned int end) {
    int i;
    unsigned int a;
    for (i = 0; i < 0x1000; i += 0x40) {
        __asm__ __volatile__(".set noreorder\n\tsync\n\tcache 0x10, 0(%1)\n\tsync\n\tmfc0 %0, $28\n\t.set reorder" : "=r"(a) : "r"(i));
        a = (a & 0xFFFFF000) + i;
        if (a >= start && a <= end) {
            __asm__ __volatile__("sync\n\tcache 0x14, 0(%0)\n\tsync" : : "r"(i));
        }
        __asm__ __volatile__(".set noreorder\n\tsync\n\tcache 0x10, 1(%1)\n\tsync\n\tmfc0 %0, $28\n\t.set reorder" : "=r"(a) : "r"(i));
        a = (a & 0xFFFFF000) + i;
        if (a >= start && a <= end) {
            __asm__ __volatile__("sync\n\tcache 0x14, 1(%0)\n\tsync" : : "r"(i));
        }
        __asm__ __volatile__("sync");
    }
}

void SyncDCache(int start, int end) {
    int eie;
    MFC0_STATUS(eie);
    eie &= 0x10000;
    if (eie) {
        DIntr();
    }
    _sceSDC(start & 0xFFFFFFC0, end & 0xFFFFFFC0);
    if (eie) {
        EIntr();
    }
}

void iSyncDCache(int start, int end) {
    _sceSDC(start & 0xFFFFFFC0, end & 0xFFFFFFC0);
}

void _sceIDC(unsigned int start, unsigned int end) {
    int i;
    unsigned int a;
    for (i = 0; i < 0x1000; i += 0x40) {
        __asm__ __volatile__(".set noreorder\n\tsync\n\tcache 0x10, 0(%1)\n\tsync\n\tmfc0 %0, $28\n\t.set reorder" : "=r"(a) : "r"(i));
        a = (a & 0xFFFFF000) + i;
        if (a >= start && a <= end) {
            __asm__ __volatile__("sync\n\tcache 0x16, 0(%0)\n\tsync" : : "r"(i));
        }
        __asm__ __volatile__(".set noreorder\n\tsync\n\tcache 0x10, 1(%1)\n\tsync\n\tmfc0 %0, $28\n\t.set reorder" : "=r"(a) : "r"(i));
        a = (a & 0xFFFFF000) + i;
        if (a >= start && a <= end) {
            __asm__ __volatile__("sync\n\tcache 0x16, 1(%0)\n\tsync" : : "r"(i));
        }
        __asm__ __volatile__("sync");
    }
}

void InvalidDCache(int start, int end) {
    int eie;
    MFC0_STATUS(eie);
    eie &= 0x10000;
    if (eie) {
        DIntr();
    }
    _sceIDC(start & 0xFFFFFFC0, end & 0xFFFFFFC0);
    if (eie) {
        EIntr();
    }
}

void iInvalidDCache(int start, int end) {
    _sceIDC(start & 0xFFFFFFC0, end & 0xFFFFFFC0);
}
