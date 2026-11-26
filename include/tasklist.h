#ifndef TASKLIST_H
#define TASKLIST_H

#include "common.h"

/*
 * Task lists (xgoblin.c). A list head and its entries have the same 16-byte layout; common_data.h's XGoblin is the
 * old single view of both (kept there unchanged for the files that include it).
 */

// One task: TaskList_UpdateMatching calls func every frame while (runFlags & mask) == mask.
typedef struct TaskEntry {
    /* 0x00 */ u16 flags;    // 0 = free; 0x11 when added, bit 4 cleared after each run
    /* 0x02 */ u16 runFlags; // set by callers after TaskSystem_AddTask (1 / -1: also runs while D_002C1EBC is 1)
    /* 0x04 */ s32 prio;     // the list is sorted by it, lowest first
    /* 0x08 */ struct TaskEntry* next;
    /* 0x0C */ u32 (*func)(struct TaskEntry*); // return bit 4: remove the task, bit 8: stop the walk
} TaskEntry; // size = 0x10

// A task list head: a pool of count entries of entrySize bytes, and the list sorted by priority.
typedef struct TaskList {
    /* 0x00 */ u16 entrySize;
    /* 0x02 */ u16 count;
    /* 0x04 */ s32 pool; // address of the first pool entry
    /* 0x08 */ TaskEntry* first;
    /* 0x0C */ TaskEntry* lastAdded; // where TaskList_FindFree goes on searching; NULL after each update
} TaskList; // size = 0x10

#endif // TASKLIST_H
