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

typedef struct fde_vector {
    fde **array;
    size_t count;
} fde_vector;

typedef struct fde_accumulator {
    fde_vector linear;
    fde_vector erratic;
} fde_accumulator;

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

typedef int saddr;

static inline saddr fde_compare(fde *x, fde *y) {
    return (saddr)x->pc_begin - (saddr)y->pc_begin;
}

void fde_merge(fde_vector *v1, const fde_vector *v2) {
    size_t i1, i2;
    fde *fde2;

    i2 = v2->count;
    if (i2) {
        i1 = v1->count;
        do {
            i2--;
            fde2 = v2->array[i2];
            while (i1 > 0 && fde_compare(v1->array[i1 - 1], fde2) > 0) {
                v1->array[i1 + i2] = v1->array[i1 - 1];
                i1--;
            }
            v1->array[i1 + i2] = fde2;
        } while (i2 > 0);
        v1->count += v2->count;
    }
}

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


fde **end_fde_sort(fde_accumulator *accu, size_t count);

static inline void fde_insert(fde_accumulator *accu, fde *this_fde) {
    if (accu->linear.array)
        accu->linear.array[accu->linear.count++] = this_fde;
}

static inline int start_fde_sort(fde_accumulator *accu, size_t count) {
    accu->linear.array = count ? (fde **)malloc(sizeof(fde *) * count) : 0;
    accu->erratic.array = accu->linear.array ? (fde **)malloc(sizeof(fde *) * count) : 0;
    accu->linear.count = 0;
    accu->erratic.count = 0;
    return accu->linear.array != 0;
}

void add_fdes(fde *this_fde, fde_accumulator *accu, void **beg_ptr, void **end_ptr) {
    void *pc_begin = *beg_ptr;
    void *pc_end = *end_ptr;

    for (; this_fde->length != 0; this_fde = next_fde(this_fde)) {
        if (this_fde->CIE_delta == 0 || this_fde->pc_begin == 0)
            continue;

        fde_insert(accu, this_fde);

        if (this_fde->pc_begin < pc_begin)
            pc_begin = this_fde->pc_begin;
        if ((char *)this_fde->pc_begin + this_fde->pc_range > (char *)pc_end)
            pc_end = (char *)this_fde->pc_begin + this_fde->pc_range;
    }

    *beg_ptr = pc_begin;
    *end_ptr = pc_end;
}

fde *search_fdes(fde *this_fde, void *pc) {
    for (; this_fde->length != 0; this_fde = next_fde(this_fde)) {
        if (this_fde->CIE_delta == 0 || this_fde->pc_begin == 0)
            continue;
        if ((uaddr)((char *)pc - (char *)this_fde->pc_begin) < this_fde->pc_range)
            return this_fde;
    }
    return 0;
}

void frame_init(struct object *ob) {
    size_t count;
    fde_accumulator accu;
    void *pc_begin, *pc_end;
    fde **array;

    if (ob->pc_begin)
        count = ob->count;
    else if (ob->fde_array) {
        fde **p = ob->fde_array;
        for (count = 0; *p; ++p)
            count += count_fdes(*p);
    } else
        count = count_fdes(ob->fde_begin);
    ob->count = count;

    if (!start_fde_sort(&accu, count) && ob->pc_begin)
        return;

    pc_begin = (void *)(uaddr)-1;
    pc_end = 0;

    if (ob->fde_array) {
        fde **p = ob->fde_array;
        for (; *p; ++p)
            add_fdes(*p, &accu, &pc_begin, &pc_end);
    } else
        add_fdes(ob->fde_begin, &accu, &pc_begin, &pc_end);

    array = end_fde_sort(&accu, count);
    if (array)
        ob->fde_array = array;
    ob->pc_begin = pc_begin;
    ob->pc_end = pc_end;
}

fde *find_fde(void *pc) {
    struct object *ob;
    size_t lo, hi;

    __gthread_mutex_lock(&__sce_eh_sema_id);

    for (ob = D_0066FAD0; ob; ob = ob->next) {
        if (ob->pc_begin == 0)
            frame_init(ob);
        if (pc >= ob->pc_begin && pc < ob->pc_end)
            break;
    }

    if (ob == 0) {
        __gthread_mutex_unlock(&__sce_eh_sema_id);
        return 0;
    }

    if (!ob->fde_array || (void *)ob->fde_array == (void *)ob->fde_begin)
        frame_init(ob);

    if (ob->fde_array && (void *)ob->fde_array != (void *)ob->fde_begin) {
        __gthread_mutex_unlock(&__sce_eh_sema_id);

        for (lo = 0, hi = ob->count; lo < hi;) {
            size_t i = (lo + hi) / 2;
            fde *f = ob->fde_array[i];

            if (pc < f->pc_begin)
                hi = i;
            else if ((char *)pc >= (char *)f->pc_begin + f->pc_range)
                lo = i + 1;
            else
                return f;
        }
    } else {
        fde *f;

        if (ob->fde_array) {
            fde **p = ob->fde_array;

            do {
                f = search_fdes(*p, pc);
                if (f)
                    break;
                p++;
            } while (*p);
        } else
            f = search_fdes(ob->fde_begin, pc);
        __gthread_mutex_unlock(&__sce_eh_sema_id);
        return f;
    }
    return 0;
}

struct dwarf_cie {
    uword length;
    sword CIE_id;
    byte version;
    char augmentation[0];
};

struct cie_info {
    char *augmentation;
    void *eh_ptr;
    int code_align;
    int data_align;
    unsigned ra_regno;
};

union unaligned {
    void *p;
    unsigned b2 __attribute__((mode(HI)));
    unsigned b4 __attribute__((mode(SI)));
    unsigned b8 __attribute__((mode(DI)));
} __attribute__((packed));

extern char D_00492850[]; /* "" */
extern char D_00492858[]; /* "eh" */
int strcmp(const char *, const char *);
size_t strlen(const char *);

static inline struct dwarf_cie *get_cie(fde *f) {
    return (void *)&f->CIE_delta - f->CIE_delta;
}

static inline void *read_pointer(void *p) {
    union unaligned *up = p;
    return up->p;
}

void *extract_cie_info(fde *f, struct cie_info *c) {
    void *p;
    int i;

    c->augmentation = get_cie(f)->augmentation;

    if (strcmp(c->augmentation, D_00492850) != 0 && strcmp(c->augmentation, D_00492858) != 0 &&
        c->augmentation[0] != 'z')
        return 0;

    p = c->augmentation + strlen(c->augmentation) + 1;

    if (strcmp(c->augmentation, D_00492858) == 0) {
        c->eh_ptr = read_pointer(p);
        p += sizeof(void *);
    } else
        c->eh_ptr = 0;

    p = decode_uleb128(p, &c->code_align);
    p = decode_sleb128(p, &c->data_align);
    c->ra_regno = *(unsigned char *)p++;

    if (c->augmentation[0] == 'z') {
        p = decode_uleb128(p, &i);
        p += i;
    }

    return p;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", decode_stack_op);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", execute_cfa_insn);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", __frame_state_for);
