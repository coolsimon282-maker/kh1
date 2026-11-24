// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"
#include <_ansi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <reent.h>
#include <stdarg.h>
#include "local.h"
#include "fvwrite.h"

int _vfprintf_r(struct _reent *, FILE *, const char *, va_list);

/*
 * Flush out all the vectors defined by the given uio,
 * then reset it so that it can be reused.
 * (newlib's static __sprint; global here while its callers are still asm)
 */
int
func_00252328(fp, uio)
	FILE *fp;
	register struct __suio *uio;
{
	register int err;

	if (uio->uio_resid == 0) {
		uio->uio_iovcnt = 0;
		return (0);
	}
	err = __sfvwrite(fp, uio);
	uio->uio_resid = 0;
	uio->uio_iovcnt = 0;
	return (err);
}

/*
 * Helper function for `fprintf to unbuffered unix file': creates a
 * temporary buffer.  We only work on write-only files; this avoids
 * worries about ungetc buffers and so forth.
 * (newlib's static __sbprintf; global here while its callers are still asm)
 */
int
func_00252370(fp, fmt, ap)
	register FILE *fp;
	const char *fmt;
	va_list ap;
{
	int ret;
	FILE fake;
	unsigned char buf[BUFSIZ];

	/* copy the important variables */
	fake._data = fp->_data;
	fake._flags = fp->_flags & ~__SNBF;
	fake._file = fp->_file;
	fake._cookie = fp->_cookie;
	fake._write = fp->_write;

	/* set up the buffer */
	fake._bf._base = fake._p = buf;
	fake._bf._size = fake._w = sizeof(buf);
	fake._lbfsize = 0;	/* not actually used, but Just In Case */

	/* do the work, then copy any error status */
	ret = vfprintf(&fake, fmt, ap);
	if (ret >= 0 && fflush(&fake))
		ret = EOF;
	if (fake._flags & __SERR)
		fp->_flags |= __SERR;
	return (ret);
}

int
_DEFUN (vfprintf, (fp, fmt0, ap),
	FILE * fp _AND
	_CONST char *fmt0 _AND
	va_list ap)
{
  CHECK_INIT (fp);
  return _vfprintf_r (fp->_data, fp, fmt0, ap);
}

INCLUDE_ASM("asm/nonmatchings/lib/libc/vfprintf", _vfprintf_r);

INCLUDE_ASM("asm/nonmatchings/lib/libc/vfprintf", cvt);

INCLUDE_ASM("asm/nonmatchings/lib/libc/vfprintf", exponent);
