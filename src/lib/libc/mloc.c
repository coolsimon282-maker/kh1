// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
#include "../../../include/include_asm.h"

#include "../../../include/common.h"

extern int GetThreadId(void);
extern int WaitSema(int s);
extern s32 __sce_sema_id;
/* .data (0x0046AE28-0x0046AE30): the thread holding the malloc lock and its lock count */
s32 curr_thread = -1;
s32 num_threads = 0;

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

extern int SignalSema(int s);

void _malloc_unlock(void) {
    if (--num_threads == 0) {
        curr_thread = -1;
        SignalSema(__sce_sema_id);
    }
}
