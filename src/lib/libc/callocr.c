/* newlib 1.8.2 callocr.c, i.e. mallocr.c with DEFINE_CALLOC (mallocr.c is not in include/newlib-private, so the
   pieces calloc uses are spelled out here). */
#include <_ansi.h>
#include <reent.h>
#include <string.h>
#include <stddef.h>

#define INTERNAL_SIZE_T size_t
#define SIZE_SZ (sizeof(INTERNAL_SIZE_T))
#define PREV_INUSE 0x1
#define IS_MMAPPED 0x2
#define SIZE_BITS (PREV_INUSE | IS_MMAPPED)

struct malloc_chunk
{
  INTERNAL_SIZE_T prev_size; /* Size of previous chunk (if free). */
  INTERNAL_SIZE_T size;      /* Size in bytes, including overhead. */
  struct malloc_chunk* fd;   /* double links -- used only if free. */
  struct malloc_chunk* bk;
};

typedef struct malloc_chunk* mchunkptr;

#define mem2chunk(mem) ((mchunkptr)((char*)(mem) - 2*SIZE_SZ))
#define chunksize(p) ((p)->size & ~(SIZE_BITS))

#define MALLOC_ZERO(charp, nbytes)                                            \
do {                                                                          \
  INTERNAL_SIZE_T mzsz = (nbytes);                                            \
  if(mzsz <= 9*sizeof(mzsz)) {                                                \
    INTERNAL_SIZE_T* mz = (INTERNAL_SIZE_T*) (charp);                         \
    if(mzsz >= 5*sizeof(mzsz)) {     *mz++ = 0;                               \
                                     *mz++ = 0;                               \
      if(mzsz >= 7*sizeof(mzsz)) {   *mz++ = 0;                               \
                                     *mz++ = 0;                               \
        if(mzsz >= 9*sizeof(mzsz)) { *mz++ = 0;                               \
                                     *mz++ = 0; }}}                           \
                                     *mz++ = 0;                               \
                                     *mz++ = 0;                               \
                                     *mz   = 0;                               \
  } else memset((charp), 0, mzsz);                                            \
} while(0)

extern _PTR _malloc_r _PARAMS ((struct _reent *, size_t));

_PTR
_calloc_r (struct _reent *reent_ptr, size_t n, size_t elem_size)
{
  mchunkptr p;
  INTERNAL_SIZE_T csz;

  INTERNAL_SIZE_T sz = n * elem_size;

  _PTR mem = _malloc_r (reent_ptr, sz);

  if (mem == 0)
    return 0;
  else
  {
    p = mem2chunk(mem);

    csz = chunksize(p);

    MALLOC_ZERO(mem, csz - SIZE_SZ);
    return mem;
  }
}
