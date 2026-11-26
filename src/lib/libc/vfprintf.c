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

/* from newlib's libc/stdlib/mprec.h (little-endian IEEE) and vfprintf.c's flag bits */
union double_union {
	double d;
	__uint32_t i[2];
};
#define word0(x) (x.i[1])
#define Sign_bit 0x80000000
#define	ALT		0x001		/* alternate form */

/* newlib's static cvt(); global here while its callers are still asm */
char *
cvt(data, value, ndigits, flags, sign, decpt, ch, length)
	struct _reent *data;
	double value;
	int ndigits, flags, *decpt, ch, *length;
	char *sign;
{
	int mode, dsgn;
	char *digits, *bp, *rve;
        union double_union tmp;

	if (ch == 'f') {
		mode = 3;		/* ndigits after the decimal point */
	} else {
		/* To obtain ndigits after the decimal point for the 'e'
		 * and 'E' formats, round to ndigits + 1 significant
		 * figures.
		 */
		if (ch == 'e' || ch == 'E') {
			ndigits++;
		}
		mode = 2;		/* ndigits significant digits */
	}

        tmp.d = value;
	if (word0(tmp) & Sign_bit) { /* this will check for < 0 and -0.0 */
		value = -value;
		*sign = '-';
        } else
		*sign = '\000';
	digits = _dtoa_r(data, value, mode, ndigits, decpt, &dsgn, &rve);
	if ((ch != 'g' && ch != 'G') || flags & ALT) {	/* Print trailing zeros */
		bp = digits + ndigits;
		if (ch == 'f') {
			if (*digits == '0' && value)
				*decpt = -ndigits + 1;
			bp += *decpt;
		}
		if (value == 0)	/* kludge for __dtoa irregularity */
			rve = bp;
		while (rve < bp)
			*rve++ = '0';
	}
	*length = rve - digits;
	return (digits);
}

#define	to_char(n)	((n) + '0')
#define	MAXEXP		308

/* newlib's static exponent(); global here while its callers are still asm */
int
exponent(p0, exp, fmtch)
	char *p0;
	int exp, fmtch;
{
	register char *p, *t;
	char expbuf[MAXEXP];

	p = p0;
	*p++ = fmtch;
	if (exp < 0) {
		exp = -exp;
		*p++ = '-';
	}
	else
		*p++ = '+';
	t = expbuf + MAXEXP;
	if (exp > 9) {
		do {
			*--t = to_char(exp % 10);
		} while ((exp /= 10) > 9);
		*--t = to_char(exp);
		for (; t < expbuf + MAXEXP; *p++ = *t++);
	}
	else {
		*p++ = '0';
		*p++ = to_char(exp);
	}
	return (p - p0);
}
