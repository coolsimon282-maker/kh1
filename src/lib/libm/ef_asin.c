/* ef_asin.c -- float version of e_asin.c.
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

/* the constants' .rodata words are still in the asm data segment, so they are spelled as literals here */
#define one ((float)1.0000000000e+00)     /* 0x3F800000 */
#define huge ((float)1.000e+30)
#define pio2_hi ((float)1.5707962513e+00) /* 0x3fc90fda */
#define pio2_lo ((float)7.5497894159e-08) /* 0x33a22168 */
#define pio4_hi ((float)7.8539818525e-01) /* 0x3f490fdb */
	/* coefficient for R(x^2) */
#define pS0 ((float)1.6666667163e-01)  /* 0x3e2aaaab */
#define pS1 ((float)-3.2556581497e-01) /* 0xbea6b090 */
#define pS2 ((float)2.0121252537e-01)  /* 0x3e4e0aa8 */
#define pS3 ((float)-4.0055535734e-02) /* 0xbd241146 */
#define pS4 ((float)7.9153501429e-04)  /* 0x3a4f7f04 */
#define pS5 ((float)3.4793309169e-05)  /* 0x3811ef08 */
#define qS1 ((float)-2.4033949375e+00) /* 0xc019d139 */
#define qS2 ((float)2.0209457874e+00)  /* 0x4001572d */
#define qS3 ((float)-6.8828397989e-01) /* 0xbf303361 */
#define qS4 ((float)7.7038154006e-02)  /* 0x3d9dc62e */

/* a real call, not gcc's builtin abs.s (newlib was built with -fno-builtin) */
float fabsf_call(float) __asm__("fabsf");

#ifdef __STDC__
	float __ieee754_asinf(float x)
#else
	float __ieee754_asinf(x)
	float x;
#endif
{
	float t,w,p,q,c,r,s;
	__int32_t hx,ix;
	GET_FLOAT_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix==0x3f800000) {
		/* asin(1)=+-pi/2 with inexact */
	    return x*pio2_hi+x*pio2_lo;
	} else if(ix> 0x3f800000) {	/* |x|>= 1 */
	    return (x-x)/(x-x);		/* asin(|x|>1) is NaN */
	} else if (ix<0x3f000000) {	/* |x|<0.5 */
	    if(ix<0x32000000) {		/* if |x| < 2**-27 */
		if(huge+x>one) return x;/* return x with inexact if x!=0*/
	    } else {
		t = x*x;
		p = t*(pS0+t*(pS1+t*(pS2+t*(pS3+t*(pS4+t*pS5)))));
		q = one+t*(qS1+t*(qS2+t*(qS3+t*qS4)));
		w = p/q;
		return x+x*w;
	    }
	}
	/* 1> |x|>= 0.5 */
	w = one-fabsf_call(x);
	t = w*(float)0.5;
	p = t*(pS0+t*(pS1+t*(pS2+t*(pS3+t*(pS4+t*pS5)))));
	q = one+t*(qS1+t*(qS2+t*(qS3+t*qS4)));
	s = __ieee754_sqrtf(t);
	if(ix>=0x3F79999A) { 	/* if |x| > 0.975 */
	    w = p/q;
	    t = pio2_hi-((float)2.0*(s+s*w)-pio2_lo);
	} else {
	    __int32_t iw;
	    w  = s;
	    GET_FLOAT_WORD(iw,w);
	    SET_FLOAT_WORD(w,iw&0xfffff000);
	    c  = (t-w*w)/(s+w);
	    r  = p/q;
	    p  = (float)2.0*s*r-(pio2_lo-(float)2.0*c);
	    q  = pio4_hi-(float)2.0*w;
	    t  = pio4_hi-(p-q);
	}
	if(hx>0) return t; else return -t;
}
