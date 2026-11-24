/* sf_scalbn.c -- float version of s_scalbn.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

#include "fdlibm.h"
#include <limits.h>
#include <float.h>

/* The EE single-precision format has no denormals and no Inf/NaN (newlib's fdlibm.h FLT_UWORD macros). */
#define FLT_UWORD_IS_ZERO(x) ((x)<0x00800000L)
#define FLT_UWORD_IS_SUBNORMAL(x) 0
#define FLT_UWORD_IS_FINITE(x) 1
#define FLT_UWORD_MAX 0x7fffffffL
#define FLT_LARGEST_EXP (FLT_UWORD_MAX>>23)
#define FLT_SMALLEST_EXP 1

/* the constants' .rodata words are still in the asm data segment, so they are spelled as literals here */
#define two25 ((float)3.355443200e+07)  /* 0x4c000000 */
#define twom25 ((float)2.9802322388e-08) /* 0x33000000 */
#define huge ((float)1.0e+30)
#define tiny ((float)1.0e-30)

#ifdef __STDC__
	float scalbnf (float x, int n)
#else
	float scalbnf (x,n)
	float x; int n;
#endif
{
	__int32_t  k,ix;
	__uint32_t hx;

	GET_FLOAT_WORD(ix,x);
	hx = ix&0x7fffffff;
        k = hx>>23;		/* extract exponent */
	if (FLT_UWORD_IS_ZERO(hx))
	    return x;
        if (!FLT_UWORD_IS_FINITE(hx))
	    return x+x;		/* NaN or Inf */
        if (FLT_UWORD_IS_SUBNORMAL(hx)) {
	    x *= two25;
	    GET_FLOAT_WORD(ix,x);
	    k = ((ix&0x7f800000)>>23) - 25;
            if (n< -50000) return tiny*x; 	/*underflow*/
        }
        k = k+n;
        if (k > FLT_LARGEST_EXP) return huge*copysignf(huge,x); /* overflow  */
        if (k > 0) 				/* normal result */
	    {SET_FLOAT_WORD(x,(ix&0x807fffff)|(k<<23)); return x;}
        if (k < FLT_SMALLEST_EXP) {
            if (n > 50000) 	/* in case integer overflow in n+k */
		return huge*copysignf(huge,x);	/*overflow*/
	    else return tiny*copysignf(tiny,x);	/*underflow*/
        }
        k += 25;				/* subnormal result */
	SET_FLOAT_WORD(x,(ix&0x807fffff)|(k<<23));
        return x*twom25;
}

#ifdef _DOUBLE_IS_32BITS

#ifdef __STDC__
	double scalbn(double x, int n)
#else
	double scalbn(x,n)
	double x;
	int n;
#endif
{
	return (double) scalbnf((float) x, n);
}

#endif /* defined(_DOUBLE_IS_32BITS) */
