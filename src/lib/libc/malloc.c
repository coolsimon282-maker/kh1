// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"

#include <_ansi.h>
#include <reent.h>
#include <stdlib.h>

extern void _malloc_lock _PARAMS ((struct _reent *));
extern void _malloc_unlock _PARAMS ((struct _reent *));

_PTR
_DEFUN (malloc, (nbytes),
	size_t nbytes)		/* get a block */
{
  _PTR p;

  _malloc_lock (_impure_ptr);
  p = _malloc_r (_impure_ptr, nbytes);
  _malloc_unlock (_impure_ptr);
  return p;
}

void
_DEFUN (free, (aptr),
	_PTR aptr)
{
  _malloc_lock (_impure_ptr);
  _free_r (_impure_ptr, aptr);
  _malloc_unlock (_impure_ptr);
}
