// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/main", __do_global_dtors);

void __register_frame_info(void *beg, void *end);
extern void __do_global_dtors(void);
int atexit(void (*func)(void));

extern void (*D_0049402C[])();
extern char D_00494040[];
extern char D_0066FAB0[];

void __do_global_ctors(void) {
    __register_frame_info(D_00494040, D_0066FAB0);
    do {
        unsigned long nptrs = (unsigned long)D_0049402C[0];
        unsigned i;

        if (nptrs == (unsigned long)-1)
            for (nptrs = 0; D_0049402C[nptrs + 1] != 0; nptrs++)
                ;
        for (i = nptrs; i >= 1; i--)
            D_0049402C[i]();
    } while (0);
    atexit(__do_global_dtors);
}

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/main", __main);
