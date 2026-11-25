// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"


/* newlib mallocr.c (malloc_r.c = mallocr.c with DEFINE_MALLOC); the original file is not in
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
extern unsigned long D_0046ADF0;           /* max_sbrked_mem */
extern unsigned long D_0046ADF8;           /* max_total_mem */
#define max_sbrked_mem D_0046ADF0
#define max_total_mem D_0046ADF8
#define initial_top ((mchunkptr)(bin_at(0)))
#define chunk2mem(p) ((void*)((char*)(p) + 2*SIZE_SZ))
#define chunk_at_offset(p, s)  ((mchunkptr)(((char*)(p)) + (s)))
#define set_head_size(p, s) ((p)->size = (((p)->size & PREV_INUSE) | (s)))
#define MALLOC_ALIGNMENT (SIZE_SZ + SIZE_SZ + SIZE_SZ + SIZE_SZ)
#define MALLOC_ALIGN_MASK (MALLOC_ALIGNMENT - 1)
#define POINTER_UINT unsigned long

extern void *_sbrk_r _PARAMS ((struct _reent *, size_t));
extern void _free_r _PARAMS ((struct _reent *, void *));

static void malloc_extend_top(struct _reent *reent_ptr, INTERNAL_SIZE_T nb)
{
  char*     brk;                  /* return value from sbrk */
  INTERNAL_SIZE_T front_misalign; /* unusable bytes at front of sbrked space */
  INTERNAL_SIZE_T correction;     /* bytes for 2nd sbrk call */
  char*     new_brk;              /* return of 2nd sbrk call */
  INTERNAL_SIZE_T top_size;       /* new size of top chunk */

  mchunkptr old_top     = top;  /* Record state of old top */
  INTERNAL_SIZE_T old_top_size = chunksize(old_top);
  char*     old_end      = (char*)(chunk_at_offset(old_top, old_top_size));

  /* Pad request with top_pad plus minimal overhead */

  INTERNAL_SIZE_T    sbrk_size     = nb + top_pad + MINSIZE;
  unsigned long pagesz    = malloc_getpagesize;

  /* If not the first time through, round to preserve page boundary */
  /* Otherwise, we need to correct to a page size below anyway. */
  /* (We also correct below if an intervening foreign sbrk call.) */

  if (sbrk_base != (char*)(-1))
    sbrk_size = (sbrk_size + (pagesz - 1)) & ~(pagesz - 1);

  brk = (char*)(MORECORE (sbrk_size));

  /* Fail if sbrk failed or if a foreign sbrk call killed our space */
  if (brk == (char*)(MORECORE_FAILURE) ||
      (brk < old_end && old_top != initial_top))
    return;

  sbrked_mem += sbrk_size;

  if (brk == old_end) /* can just add bytes to current top */
  {
    top_size = sbrk_size + old_top_size;
    set_head(top, top_size | PREV_INUSE);
  }
  else
  {
    if (sbrk_base == (char*)(-1)) /* First time through. Record base */
      sbrk_base = brk;
    else  /* Someone else called sbrk().  Count those bytes as sbrked_mem. */
      sbrked_mem += brk - (char*)old_end;

    /* Guarantee alignment of first new chunk made from this space */
    front_misalign = (POINTER_UINT)chunk2mem(brk) & MALLOC_ALIGN_MASK;
    if (front_misalign > 0)
    {
      correction = (MALLOC_ALIGNMENT) - front_misalign;
      brk += correction;
    }
    else
      correction = 0;

    /* Guarantee the next brk will be at a page boundary */
    correction += pagesz - ((POINTER_UINT)(brk + sbrk_size) & (pagesz - 1));

    /* Allocate correction */
    new_brk = (char*)(MORECORE (correction));
    if (new_brk == (char*)(MORECORE_FAILURE)) return;

    sbrked_mem += correction;

    top = (mchunkptr)brk;
    top_size = new_brk - brk + correction;
    set_head(top, top_size | PREV_INUSE);

    if (old_top != initial_top)
    {

      /* There must have been an intervening foreign sbrk call. */
      /* A double fencepost is necessary to prevent consolidation */

      /* If not enough space to do this, then user did something very wrong */
      if (old_top_size < MINSIZE)
      {
        set_head(top, PREV_INUSE); /* will force null return from malloc */
        return;
      }

      /* Also keep size a multiple of MALLOC_ALIGNMENT */
      old_top_size = (old_top_size - 3*SIZE_SZ) & ~MALLOC_ALIGN_MASK;
      set_head_size(old_top, old_top_size);
      chunk_at_offset(old_top, old_top_size          )->size =
        SIZE_SZ|PREV_INUSE;
      chunk_at_offset(old_top, old_top_size + SIZE_SZ)->size =
        SIZE_SZ|PREV_INUSE;
      /* If possible, release the rest. */
      if (old_top_size >= MINSIZE)
        _free_r(reent_ptr, chunk2mem(old_top));
    }
  }

  if ((unsigned long)sbrked_mem > (unsigned long)max_sbrked_mem)
    max_sbrked_mem = sbrked_mem;
  if ((unsigned long)(sbrked_mem) > (unsigned long)max_total_mem)
    max_total_mem = sbrked_mem;
}

INCLUDE_ASM("asm/nonmatchings/lib/libc/malloc_r", _malloc_r);
