/* sf_atan.c -- float version of s_atan.c.
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
 *
 */

#include "fdlibm.h"

/* The EE single-precision format has no Inf/NaN (newlib's fdlibm.h FLT_UWORD macros). */
#define FLT_UWORD_IS_NAN(x) 0

/* the constants' .rodata is still in the asm data segment: the tables are the segment's D_ labels, the
   scalars are spelled as literals */
extern const float D_00493F38[]; /* atanhi[4] */
extern const float D_00493F48[]; /* atanlo[4] */
extern const float D_00493F58[]; /* aT[11] */
#define atanhi D_00493F38
#define atanlo D_00493F48
#define aT D_00493F58
#define one ((float)1.0)
#define huge ((float)1.0e30)

/* a real call, not gcc's builtin abs.s (newlib was built with -fno-builtin) */
float fabsf_call(float) __asm__("fabsf");

#ifdef __STDC__
	float atanf(float x)
#else
	float atanf(x)
	float x;
#endif
{
	float w,s1,s2,z;
	__int32_t ix,hx,id;

	GET_FLOAT_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix>=0x50800000) {	/* if |x| >= 2^34 */
	    if(FLT_UWORD_IS_NAN(ix))
		return x+x;		/* NaN */
	    if(hx>0) return  atanhi[3]+atanlo[3];
	    else     return -atanhi[3]-atanlo[3];
	} if (ix < 0x3ee00000) {	/* |x| < 0.4375 */
	    if (ix < 0x31000000) {	/* |x| < 2^-29 */
		if(huge+x>one) return x;	/* raise inexact */
	    }
	    id = -1;
	} else {
	x = fabsf_call(x);
	if (ix < 0x3f980000) {		/* |x| < 1.1875 */
	    if (ix < 0x3f300000) {	/* 7/16 <=|x|<11/16 */
		id = 0; x = ((float)2.0*x-one)/((float)2.0+x);
	    } else {			/* 11/16<=|x|< 19/16 */
		id = 1; x  = (x-one)/(x+one);
	    }
	} else {
	    if (ix < 0x401c0000) {	/* |x| < 2.4375 */
		id = 2; x  = (x-(float)1.5)/(one+(float)1.5*x);
	    } else {			/* 2.4375 <= |x| < 2^66 */
		id = 3; x  = -(float)1.0/x;
	    }
	}}
    /* end of argument reduction */
	z = x*x;
	w = z*z;
    /* break sum from i=0 to 10 aT[i]z**(i+1) into odd and even poly */
	s1 = z*(aT[0]+w*(aT[2]+w*(aT[4]+w*(aT[6]+w*(aT[8]+w*aT[10])))));
	s2 = w*(aT[1]+w*(aT[3]+w*(aT[5]+w*(aT[7]+w*aT[9]))));
	if (id<0) return x - x*(s1+s2);
	else {
	    z = atanhi[id] - ((x*(s1+s2) - atanlo[id]) - x);
	    return (hx<0)? -z:z;
	}
}

#ifdef _DOUBLE_IS_32BITS

#ifdef __STDC__
	double atan(double x)
#else
	double atan(x)
	double x;
#endif
{
	return (double) atanf((float) x);
}

#endif /* defined(_DOUBLE_IS_32BITS) */
