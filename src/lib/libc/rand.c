/* newlib 1.9.0 rand.c (the 64-bit generator); the 1.8.2 struct _reent in include/newlib still has a 32-bit
   _rand_next, so the state at 0xA8 of the reent struct is addressed directly here. */
#include <stdlib.h>
#include <reent.h>

#define RAND_NEXT(r) (*(unsigned long long *)((char *)(r) + 0xA8))

void
_DEFUN (srand, (seed), unsigned int seed)
{
  RAND_NEXT(_REENT) = seed;
}

int
_DEFUN_VOID (rand)
{
  struct _reent *r = _REENT;

  RAND_NEXT(r) = RAND_NEXT(r) * __extension__ 6364136223846793005LL + 1;
  return (int)((RAND_NEXT(r) >> 32) & RAND_MAX);
}
