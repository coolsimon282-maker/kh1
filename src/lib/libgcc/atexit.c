// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

#include "gcc/sys/reent.h"

extern void *malloc(unsigned int);

int atexit(void (*fn)(void))
{
  register struct _atexit *p;

  /* first time through? */
  if ((p = _REENT->_atexit) == NULL)
    _REENT->_atexit = p = &_REENT->_atexit0;
  if (p->_ind >= _ATEXIT_SIZE)
    {
      if ((p = (struct _atexit *) malloc (sizeof *p)) == NULL)
	return -1;
      p->_ind = 0;
      p->_next = _REENT->_atexit;
      _REENT->_atexit = p;
    }
  p->_fns[p->_ind++] = fn;
  return 0;
}
