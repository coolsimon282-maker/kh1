// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"

/* newlib mallocr.c's free and malloc_trim (freer.c = mallocr.c with DEFINE_FREE); mallocr.c itself is not in
   the tree, so the pieces they use are written out. Its state (the bins, the trim parameters, sbrk_base and
   current_mallinfo) stays in the data segments. */
#include <_ansi.h>
#include <reent.h>
#include <stddef.h>

#define INTERNAL_SIZE_T size_t
#define SIZE_SZ (sizeof(INTERNAL_SIZE_T))
#define MINSIZE (sizeof(struct malloc_chunk))
#define PREV_INUSE 0x1
#define IS_MMAPPED 0x2
#define SIZE_BITS (PREV_INUSE | IS_MMAPPED)
#define malloc_getpagesize (4096)
#define MORECORE(size) _sbrk_r(reent_ptr, (size))
#define MORECORE_FAILURE -1
#define MALLOC_LOCK _malloc_lock(reent_ptr)
#define MALLOC_UNLOCK _malloc_unlock(reent_ptr)

struct malloc_chunk
{
  INTERNAL_SIZE_T prev_size;
  INTERNAL_SIZE_T size;
  struct malloc_chunk* fd;
  struct malloc_chunk* bk;
};

typedef struct malloc_chunk* mchunkptr;
typedef struct malloc_chunk* mbinptr;

struct mallinfo_a2 {
  int arena;
  int ordblks;
  int smblks;
  int hblks;
  int hblkhd;
  int usmblks;
  int fsmblks;
  int uordblks;
  int fordblks;
  int keepcost;
};

extern mbinptr D_0046A9D0[];               /* av_ */
extern unsigned long D_0046ADD8;           /* trim_threshold */
extern unsigned long D_0046ADE0;           /* top_pad */
extern char* D_0046ADE8;                   /* sbrk_base */
extern struct mallinfo_a2 D_0046AE00;      /* current_mallinfo */

#define av_ D_0046A9D0
#define trim_threshold D_0046ADD8
#define top_pad D_0046ADE0
#define sbrk_base D_0046ADE8
#define current_mallinfo D_0046AE00
#define sbrked_mem (current_mallinfo.arena)

#define bin_at(i) ((mbinptr)((char*)&(av_[2*(i) + 2]) - 2*SIZE_SZ))
#define top (bin_at(0)->fd)

#define chunksize(p) ((p)->size & ~(SIZE_BITS))
#define set_head(p, s) ((p)->size = (s))

extern void _malloc_lock _PARAMS ((struct _reent *));
extern void _malloc_unlock _PARAMS ((struct _reent *));



#define chunk_at_offset(p, s)  ((mchunkptr)(((char*)(p)) + (s)))
#define inuse_bit_at_offset(p, s) (((mchunkptr)(((char*)(p)) + (s)))->size & PREV_INUSE)
#define set_foot(p, s)   (((mchunkptr)((char*)(p) + (s)))->prev_size = (s))
#define mem2chunk(mem) ((mchunkptr)((char*)(mem) - 2*SIZE_SZ))
#define last_remainder (bin_at(1))
#define MAX_SMALLBIN_SIZE 512
#define smallbin_index(sz)  (((unsigned long)(sz)) >> 3)
#define bin_index(sz)                                                         \
(((((unsigned long)(sz)) >> 9) ==    0) ?       (((unsigned long)(sz)) >>  3): \
 ((((unsigned long)(sz)) >> 9) <=    4) ?  56 + (((unsigned long)(sz)) >>  6): \
 ((((unsigned long)(sz)) >> 9) <=   20) ?  91 + (((unsigned long)(sz)) >>  9): \
 ((((unsigned long)(sz)) >> 9) <=   84) ? 110 + (((unsigned long)(sz)) >> 12): \
 ((((unsigned long)(sz)) >> 9) <=  340) ? 119 + (((unsigned long)(sz)) >> 15): \
 ((((unsigned long)(sz)) >> 9) <= 1364) ? 124 + (((unsigned long)(sz)) >> 18): \
                                          126)
#define BINBLOCKWIDTH     4
#define binblocks      (bin_at(0)->size)
#define idx2binblock(ix)    ((unsigned long)1 << (ix / BINBLOCKWIDTH))
#define mark_binblock(ii)   (binblocks |= idx2binblock(ii))

#define unlink(P, BK, FD)                                                     \
{                                                                             \
  BK = P->bk;                                                                 \
  FD = P->fd;                                                                 \
  FD->bk = BK;                                                                \
  BK->fd = FD;                                                                \
}

#define frontlink(P, S, IDX, BK, FD)                                          \
{                                                                             \
  if (S < MAX_SMALLBIN_SIZE)                                                  \
  {                                                                           \
    IDX = smallbin_index(S);                                                  \
    mark_binblock(IDX);                                                       \
    BK = bin_at(IDX);                                                         \
    FD = BK->fd;                                                              \
    P->bk = BK;                                                               \
    P->fd = FD;                                                               \
    FD->bk = BK->fd = P;                                                      \
  }                                                                           \
  else                                                                        \
  {                                                                           \
    IDX = bin_index(S);                                                       \
    BK = bin_at(IDX);                                                         \
    FD = BK->fd;                                                              \
    if (FD == BK) mark_binblock(IDX);                                         \
    else                                                                      \
    {                                                                         \
      while (FD != BK && S < chunksize(FD)) FD = FD->fd;                      \
      BK = FD->bk;                                                            \
    }                                                                         \
    P->bk = BK;                                                               \
    P->fd = FD;                                                               \
    FD->bk = BK->fd = P;                                                      \
  }                                                                           \
}

#define link_last_remainder(P)                                                \
{                                                                             \
  last_remainder->fd = last_remainder->bk =  P;                               \
  P->fd = P->bk = last_remainder;                                             \
}

int _malloc_trim_r _PARAMS ((struct _reent *, size_t));

void
_free_r (struct _reent *reent_ptr, _PTR mem)
{
  mchunkptr p;         /* chunk corresponding to mem */
  INTERNAL_SIZE_T hd;  /* its head field */
  INTERNAL_SIZE_T sz;  /* its size */
  int       idx;       /* its bin index */
  mchunkptr next;      /* next contiguous chunk */
  INTERNAL_SIZE_T nextsz; /* its size */
  INTERNAL_SIZE_T prevsz; /* size of previous contiguous chunk */
  mchunkptr bck;       /* misc temp for linking */
  mchunkptr fwd;       /* misc temp for linking */
  int       islr;      /* track whether merging with last_remainder */

  if (mem == 0)                              /* free(0) has no effect */
    return;

  MALLOC_LOCK;

  p = mem2chunk(mem);
  hd = p->size;

  sz = hd & ~PREV_INUSE;
  next = chunk_at_offset(p, sz);
  nextsz = chunksize(next);

  if (next == top)                            /* merge with top */
  {
    sz += nextsz;

    if (!(hd & PREV_INUSE))                    /* consolidate backward */
    {
      prevsz = p->prev_size;
      p = chunk_at_offset(p, -prevsz);
      sz += prevsz;
      unlink(p, bck, fwd);
    }

    set_head(p, sz | PREV_INUSE);
    top = p;
    if ((unsigned long)(sz) >= (unsigned long)trim_threshold)
      _malloc_trim_r(reent_ptr, top_pad);
    MALLOC_UNLOCK;
    return;
  }

  set_head(next, nextsz);                    /* clear inuse bit */

  islr = 0;

  if (!(hd & PREV_INUSE))                    /* consolidate backward */
  {
    prevsz = p->prev_size;
    p = chunk_at_offset(p, -prevsz);
    sz += prevsz;

    if (p->fd == last_remainder)             /* keep as last_remainder */
      islr = 1;
    else
      unlink(p, bck, fwd);
  }

  if (!(inuse_bit_at_offset(next, nextsz)))   /* consolidate forward */
  {
    sz += nextsz;

    if (!islr && next->fd == last_remainder)  /* re-insert last_remainder */
    {
      islr = 1;
      link_last_remainder(p);
    }
    else
      unlink(next, bck, fwd);
  }


  set_head(p, sz | PREV_INUSE);
  set_foot(p, sz);
  if (!islr)
    frontlink(p, sz, idx, bck, fwd);

  MALLOC_UNLOCK;
}

int
_malloc_trim_r (struct _reent *reent_ptr, size_t pad)
{
  long  top_size;        /* Amount of top-most memory */
  long  extra;           /* Amount to release */
  char* current_brk;     /* address returned by pre-check sbrk call */
  char* new_brk;         /* address returned by negative sbrk call */

  unsigned long pagesz = malloc_getpagesize;

  MALLOC_LOCK;

  top_size = chunksize(top);
  extra = ((top_size - pad - MINSIZE + (pagesz-1)) / pagesz - 1) * pagesz;

  if (extra < (long)pagesz)  /* Not enough memory to release */
  {
    MALLOC_UNLOCK;
    return 0;
  }

  else
  {
    /* Test to make sure no one else called sbrk */
    current_brk = (char*)(MORECORE (0));
    if (current_brk != (char*)(top) + top_size)
    {
      MALLOC_UNLOCK;
      return 0;     /* Apparently we don't own memory; must fail */
    }

    else
    {
      new_brk = (char*)(MORECORE (-extra));

      if (new_brk == (char*)(MORECORE_FAILURE)) /* sbrk failed? */
      {
        /* Try to figure out what we have */
        current_brk = (char*)(MORECORE (0));
        top_size = current_brk - (char*)top;
        if (top_size >= (long)MINSIZE) /* if not, we are very very dead! */
        {
          sbrked_mem = current_brk - sbrk_base;
          set_head(top, top_size | PREV_INUSE);
        }
        MALLOC_UNLOCK;
        return 0;
      }

      else
      {
        /* Success. Adjust top accordingly. */
        set_head(top, (top_size - extra) | PREV_INUSE);
        sbrked_mem -= extra;
        MALLOC_UNLOCK;
        return 1;
      }
    }
  }
}
