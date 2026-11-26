// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
#include "../../../include/include_asm.h"


/* newlib mallocr.c (malloc_r.c = mallocr.c with DEFINE_MALLOC); the original file is not in
   the tree, so the pieces they use are written out. Its state (the bins, the trim parameters, sbrk_base and
   current_mallinfo) is defined after the macros below. */
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

/* the state (.data 0x0046A9D0-0x0046AE28; this file is only built for FM, without VERSION_FM), as mallocr.c defines it with DEFINE_MALLOC */
#define IAV(i) bin_at(i), bin_at(i)
mbinptr D_0046A9D0[128 * 2 + 2] = { /* av_: every bin starts empty (pointing at itself) */
    0, 0,
    IAV(0), IAV(1), IAV(2), IAV(3), IAV(4), IAV(5), IAV(6), IAV(7),
    IAV(8), IAV(9), IAV(10), IAV(11), IAV(12), IAV(13), IAV(14), IAV(15),
    IAV(16), IAV(17), IAV(18), IAV(19), IAV(20), IAV(21), IAV(22), IAV(23),
    IAV(24), IAV(25), IAV(26), IAV(27), IAV(28), IAV(29), IAV(30), IAV(31),
    IAV(32), IAV(33), IAV(34), IAV(35), IAV(36), IAV(37), IAV(38), IAV(39),
    IAV(40), IAV(41), IAV(42), IAV(43), IAV(44), IAV(45), IAV(46), IAV(47),
    IAV(48), IAV(49), IAV(50), IAV(51), IAV(52), IAV(53), IAV(54), IAV(55),
    IAV(56), IAV(57), IAV(58), IAV(59), IAV(60), IAV(61), IAV(62), IAV(63),
    IAV(64), IAV(65), IAV(66), IAV(67), IAV(68), IAV(69), IAV(70), IAV(71),
    IAV(72), IAV(73), IAV(74), IAV(75), IAV(76), IAV(77), IAV(78), IAV(79),
    IAV(80), IAV(81), IAV(82), IAV(83), IAV(84), IAV(85), IAV(86), IAV(87),
    IAV(88), IAV(89), IAV(90), IAV(91), IAV(92), IAV(93), IAV(94), IAV(95),
    IAV(96), IAV(97), IAV(98), IAV(99), IAV(100), IAV(101), IAV(102), IAV(103),
    IAV(104), IAV(105), IAV(106), IAV(107), IAV(108), IAV(109), IAV(110), IAV(111),
    IAV(112), IAV(113), IAV(114), IAV(115), IAV(116), IAV(117), IAV(118), IAV(119),
    IAV(120), IAV(121), IAV(122), IAV(123), IAV(124), IAV(125), IAV(126), IAV(127),
};
unsigned long D_0046ADD8 = 0x20000;     /* trim_threshold (DEFAULT_TRIM_THRESHOLD) */
unsigned long D_0046ADE0 = 0;           /* top_pad (DEFAULT_TOP_PAD) */
char* D_0046ADE8 = (char*)(-1);         /* sbrk_base */
unsigned long D_0046ADF0 = 0;           /* max_sbrked_mem */
unsigned long D_0046ADF8 = 0;           /* max_total_mem */
struct mallinfo_a2 D_0046AE00 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; /* current_mallinfo */
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

#define request2size(req) \
 (((long)((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) < \
  (long)(MINSIZE + MALLOC_ALIGN_MASK)) ? ((MINSIZE + MALLOC_ALIGN_MASK) & ~(MALLOC_ALIGN_MASK)) : \
   (((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) & ~(MALLOC_ALIGN_MASK)))
#define set_inuse_bit_at_offset(p, s) (((mchunkptr)(((char*)(p)) + (s)))->size |= PREV_INUSE)
#define set_foot(p, s)   (((mchunkptr)((char*)(p) + (s)))->prev_size = (s))
#define next_bin(b)    ((mbinptr)((char*)(b) + 2 * sizeof(mbinptr)))
#define prev_bin(b)    ((mbinptr)((char*)(b) - 2 * sizeof(mbinptr)))
#define last_remainder (bin_at(1))
#define first(b) ((b)->fd)
#define last(b)  ((b)->bk)
#define MAX_SMALLBIN_SIZE   512
#define SMALLBIN_WIDTH        8
#define SMALLBIN_WIDTH_BITS   3
#define MAX_SMALLBIN        (MAX_SMALLBIN_SIZE / SMALLBIN_WIDTH) - 1
#define smallbin_index(sz)  (((unsigned long)(sz)) >> SMALLBIN_WIDTH_BITS)
#define is_small_request(nb) (nb < MAX_SMALLBIN_SIZE - SMALLBIN_WIDTH)
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
#define link_last_remainder(P)                                                \
{                                                                             \
  last_remainder->fd = last_remainder->bk =  P;                               \
  P->fd = P->bk = last_remainder;                                             \
}
#define clear_last_remainder \
  (last_remainder->fd = last_remainder->bk = last_remainder)
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
#define long_sub_size_t(x, y)                                \
        (x < y ? -(long) (y - x) : x - y)

extern void _malloc_lock _PARAMS ((struct _reent *));
extern void _malloc_unlock _PARAMS ((struct _reent *));

_PTR
_malloc_r (struct _reent *reent_ptr, size_t bytes)
{
  mchunkptr victim;                  /* inspected/selected chunk */
  INTERNAL_SIZE_T victim_size;       /* its size */
  int       idx;                     /* index for bin traversal */
  mbinptr   bin;                     /* associated bin */
  mchunkptr remainder;               /* remainder from a split */
  long      remainder_size;          /* its size */
  int       remainder_index;         /* its bin index */
  unsigned long block;               /* block traverser bit */
  int       startidx;                /* first bin of a traversed block */
  mchunkptr fwd;                     /* misc temp for linking */
  mchunkptr bck;                     /* misc temp for linking */
  mbinptr q;                         /* misc temp */

  INTERNAL_SIZE_T nb  = request2size(bytes);  /* padded request size; */

  MALLOC_LOCK;

  /* Check for exact match in a bin */

  if (is_small_request(nb))  /* Faster version for small requests */
  {
    idx = smallbin_index(nb);

    /* No traversal or size check necessary for small bins.  */

    q = bin_at(idx);
    victim = last(q);

    if (victim != q)
    {
      victim_size = chunksize(victim);
      unlink(victim, bck, fwd);
      set_inuse_bit_at_offset(victim, victim_size);
      MALLOC_UNLOCK;
      return chunk2mem(victim);
    }

    idx += 2; /* Set for bin scan below. We have already scanned 2 bins. */

  }
  else
  {
    idx = bin_index(nb);
    bin = bin_at(idx);

    for (victim = last(bin); victim != bin; victim = victim->bk)
    {
      victim_size = chunksize(victim);
      remainder_size = long_sub_size_t(victim_size, nb);

      if (remainder_size >= (long)MINSIZE) /* too big */
      {
        --idx; /* adjust to rescan below after checking last remainder */
        break;
      }

      else if (remainder_size >= 0) /* exact fit */
      {
        unlink(victim, bck, fwd);
        set_inuse_bit_at_offset(victim, victim_size);
        MALLOC_UNLOCK;
        return chunk2mem(victim);
      }
    }

    ++idx;

  }

  /* Try to use the last split-off remainder */

  if ( (victim = last_remainder->fd) != last_remainder)
  {
    victim_size = chunksize(victim);
    remainder_size = long_sub_size_t(victim_size, nb);

    if (remainder_size >= (long)MINSIZE) /* re-split */
    {
      remainder = chunk_at_offset(victim, nb);
      set_head(victim, nb | PREV_INUSE);
      link_last_remainder(remainder);
      set_head(remainder, remainder_size | PREV_INUSE);
      set_foot(remainder, remainder_size);
      MALLOC_UNLOCK;
      return chunk2mem(victim);
    }

    clear_last_remainder;

    if (remainder_size >= 0)  /* exhaust */
    {
      set_inuse_bit_at_offset(victim, victim_size);
      MALLOC_UNLOCK;
      return chunk2mem(victim);
    }

    /* Else place in bin */

    frontlink(victim, victim_size, remainder_index, bck, fwd);
  }

  /*
     If there are any possibly nonempty big-enough blocks,
     search for best fitting chunk by scanning bins in blockwidth units.
  */

  if ( (block = idx2binblock(idx)) <= binblocks)
  {

    /* Get to the first marked block */

    if ( (block & binblocks) == 0)
    {
      /* force to an even block boundary */
      idx = (idx & ~(BINBLOCKWIDTH - 1)) + BINBLOCKWIDTH;
      block <<= 1;
      while ((block & binblocks) == 0)
      {
        idx += BINBLOCKWIDTH;
        block <<= 1;
      }
    }

    /* For each possibly nonempty block ... */
    for (;;)
    {
      startidx = idx;          /* (track incomplete blocks) */
      q = bin = bin_at(idx);

      /* For each bin in this block ... */
      do
      {
        /* Find and use first big enough chunk ... */

        for (victim = last(bin); victim != bin; victim = victim->bk)
        {
          victim_size = chunksize(victim);
          remainder_size = long_sub_size_t(victim_size, nb);

          if (remainder_size >= (long)MINSIZE) /* split */
          {
            remainder = chunk_at_offset(victim, nb);
            set_head(victim, nb | PREV_INUSE);
            unlink(victim, bck, fwd);
            link_last_remainder(remainder);
            set_head(remainder, remainder_size | PREV_INUSE);
            set_foot(remainder, remainder_size);
            MALLOC_UNLOCK;
            return chunk2mem(victim);
          }

          else if (remainder_size >= 0)  /* take */
          {
            set_inuse_bit_at_offset(victim, victim_size);
            unlink(victim, bck, fwd);
            MALLOC_UNLOCK;
            return chunk2mem(victim);
          }

        }

       bin = next_bin(bin);

       if (idx < MAX_SMALLBIN)
         {
           bin = next_bin(bin);
           ++idx;
         }
      } while ((++idx & (BINBLOCKWIDTH - 1)) != 0);

      /* Clear out the block bit. */

      do   /* Possibly backtrack to try to clear a partial block */
      {
        if ((startidx & (BINBLOCKWIDTH - 1)) == 0)
        {
          binblocks &= ~block;
          break;
        }
        --startidx;
       q = prev_bin(q);
      } while (first(q) == q);

      /* Get to the next possibly nonempty block */

      if ( (block <<= 1) <= binblocks && (block != 0) )
      {
        while ((block & binblocks) == 0)
        {
          idx += BINBLOCKWIDTH;
          block <<= 1;
        }
      }
      else
        break;
    }
  }


  /* Try to use top chunk */

  /* Require that there be a remainder, ensuring top always exists  */
  remainder_size = long_sub_size_t(chunksize(top), nb);
  if (chunksize(top) < nb || remainder_size < (long)MINSIZE)
  {
    /* Try to extend */
    malloc_extend_top(reent_ptr, nb);
    remainder_size = long_sub_size_t(chunksize(top), nb);
    if (chunksize(top) < nb || remainder_size < (long)MINSIZE)
    {
      MALLOC_UNLOCK;
      return 0; /* propagate failure */
    }
  }

  victim = top;
  set_head(victim, nb | PREV_INUSE);
  top = chunk_at_offset(victim, nb);
  set_head(top, remainder_size | PREV_INUSE);
  MALLOC_UNLOCK;
  return chunk2mem(victim);

}
