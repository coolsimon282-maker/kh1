// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

/* gcc 2.96 (EE) frame-dwarf2.c, from gcc's frame.c. Its data (the object list) stays in the data segments. */
typedef unsigned char byte;
typedef unsigned int uword;
typedef int sword;
typedef unsigned int uaddr;
typedef unsigned int size_t;

struct dwarf_fde {
    uword length;
    sword CIE_delta;
    void *pc_begin;
    uword pc_range;
};
typedef struct dwarf_fde fde;

struct object {
    void *pc_begin;
    void *pc_end;
    fde *fde_begin;
    fde **fde_array;
    size_t count;
    struct object *next;
};

extern struct object *D_0066FAD0; /* objects */
extern int __sce_eh_sema_id;
int WaitSema(int);
int SignalSema(int);
void *malloc(size_t);
void free(void *);
void abort(void);

static inline int __gthread_mutex_lock(int *m) {
    return WaitSema(*m);
}

static inline int __gthread_mutex_unlock(int *m) {
    return SignalSema(*m);
}

#define next_fde(f) ((fde *)((char *)(f) + (f)->length + sizeof((f)->length)))

byte *decode_uleb128(byte *buf, unsigned *r) {
    unsigned shift = 0;
    unsigned result = 0;

    while (1) {
        unsigned byte = *buf++;
        result |= (byte & 0x7f) << shift;
        if ((byte & 0x80) == 0)
            break;
        shift += 7;
    }
    *r = result;
    return buf;
}

byte *decode_sleb128(byte *buf, int *r) {
    unsigned shift = 0;
    unsigned result = 0;
    unsigned byte;

    while (1) {
        byte = *buf++;
        result |= (byte & 0x7f) << shift;
        shift += 7;
        if ((byte & 0x80) == 0)
            break;
    }
    if (shift < (sizeof(*r) * 8) && (byte & 0x40) != 0)
        result |= (-1 << shift);
    *r = result;
    return buf;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", fde_merge);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", end_fde_sort);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", __register_frame_info);

void __register_frame(void *begin) {
    struct object *ob = (struct object *)malloc(sizeof(struct object));
    __register_frame_info(begin, ob);
}

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", __register_frame_info_table);

void __register_frame_info(void *begin, struct object *ob);
void __register_frame_info_table(void *begin, struct object *ob);
void __register_frame_table(void *begin) {
    struct object *ob = (struct object *)malloc(sizeof(struct object));
    __register_frame_info_table(begin, ob);
}

void *__deregister_frame_info(void *begin) {
    struct object **p;

    __gthread_mutex_lock(&__sce_eh_sema_id);
    p = &D_0066FAD0;
    while (*p) {
        if ((*p)->fde_begin == begin) {
            struct object *ob = *p;
            *p = (*p)->next;
            if (ob->fde_array && ob->fde_array != begin)
                free(ob->fde_array);
            __gthread_mutex_unlock(&__sce_eh_sema_id);
            return (void *)ob;
        }
        p = &((*p)->next);
    }
    __gthread_mutex_unlock(&__sce_eh_sema_id);
    abort();
}

void __deregister__frame(void *begin) {
    free(__deregister_frame_info(begin));
}

size_t count_fdes(fde *this_fde) {
    size_t count;

    for (count = 0; this_fde->length != 0; this_fde = next_fde(this_fde)) {
        if (this_fde->CIE_delta == 0 || this_fde->pc_begin == 0)
            continue;
        ++count;
    }
    return count;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", add_fdes);

fde *search_fdes(fde *this_fde, void *pc) {
    for (; this_fde->length != 0; this_fde = next_fde(this_fde)) {
        if (this_fde->CIE_delta == 0 || this_fde->pc_begin == 0)
            continue;
        if ((uaddr)((char *)pc - (char *)this_fde->pc_begin) < this_fde->pc_range)
            return this_fde;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", frame_init);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", find_fde);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", extract_cie_info);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", decode_stack_op);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", execute_cfa_insn);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", __frame_state_for);
