// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"

#include "../../../include/common.h"

extern int GetThreadId(void);
extern int WaitSema(int s);
extern s32 __sce_sema_id;
extern s32 curr_thread;
extern s32 num_threads;

void _malloc_lock(void) {
    s32 thread_id = GetThreadId();
    if (curr_thread == thread_id) {
        num_threads++;
        return;
    }
    WaitSema(__sce_sema_id);
    curr_thread = thread_id;
    num_threads++;
}

INCLUDE_ASM("asm/nonmatchings/lib/libc/mloc", _malloc_unlock);
