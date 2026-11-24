/* ef_rem_pio2.c -- float version of e_rem_pio2.c
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

/* __ieee754_rem_pio2f(x,y)
 *
 * return the remainder of x rem pi/2 in y[0]+y[1]
 * use __kernel_rem_pio2f()
 */

#include "fdlibm.h"

/* The EE single-precision format has no Inf/NaN (newlib's fdlibm.h FLT_UWORD macros). */
#define FLT_UWORD_IS_FINITE(x) 1

/* the constants' .rodata is still in the asm data segment: the tables are the segment's D_ labels
   (D_00493C2C sits one word before npio2_hw, so npio2_hw[n-1] is D_00493C2C[n]); the scalars are spelled
   as literals */
extern const __int32_t D_00493918[]; /* two_over_pi[] */
extern const __int32_t D_00493C2C[]; /* &npio2_hw[-1] */
#define two_over_pi D_00493918
#define zero ((float)0.0000000000e+00)
#define half ((float)5.0000000000e-01)
#define two8 ((float)2.5600000000e+02)    /* 0x43800000 */
#define invpio2 ((float)6.3661980629e-01) /* 0x3f22f984 */
#define pio2_1 ((float)1.5707855225e+00)  /* 0x3fc90f80 */
#define pio2_1t ((float)1.0804334124e-05) /* 0x37354443 */
#define pio2_2 ((float)1.0804273188e-05)  /* 0x37354400 */
#define pio2_2t ((float)6.0770999344e-11) /* 0x2e85a308 */
#define pio2_3 ((float)6.0770943833e-11)  /* 0x2e85a300 */
#define pio2_3t ((float)6.1232342629e-17) /* 0x248d3132 */

/* a real call, not gcc's builtin abs.s (newlib was built with -fno-builtin) */
float fabsf_call(float) __asm__("fabsf");

#ifdef __STDC__
	__int32_t __ieee754_rem_pio2f(float x, float *y)
#else
	__int32_t __ieee754_rem_pio2f(x,y)
	float x,y[];
#endif
{
	float z,w,t,r,fn;
	float tx[3];
	__int32_t i,j,n,ix,hx;
	int e0,nx;

	GET_FLOAT_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix<=0x3f490fd8)   /* |x| ~<= pi/4 , no need for reduction */
	    {y[0] = x; y[1] = 0; return 0;}
	if(ix<0x4016cbe4) {  /* |x| < 3pi/4, special case with n=+-1 */
	    if(hx>0) {
		z = x - pio2_1;
		if((ix&0xfffffff0)!=0x3fc90fd0) { /* 24+24 bit pi OK */
		    y[0] = z - pio2_1t;
		    y[1] = (z-y[0])-pio2_1t;
		} else {		/* near pi/2, use 24+24+24 bit pi */
		    z -= pio2_2;
		    y[0] = z - pio2_2t;
		    y[1] = (z-y[0])-pio2_2t;
		}
		return 1;
	    } else {	/* negative x */
		z = x + pio2_1;
		if((ix&0xfffffff0)!=0x3fc90fd0) { /* 24+24 bit pi OK */
		    y[0] = z + pio2_1t;
		    y[1] = (z-y[0])+pio2_1t;
		} else {		/* near pi/2, use 24+24+24 bit pi */
		    z += pio2_2;
		    y[0] = z + pio2_2t;
		    y[1] = (z-y[0])+pio2_2t;
		}
		return -1;
	    }
	}
	if(ix<=0x43490f80) { /* |x| ~<= 2^7*(pi/2), medium size */
	    t  = fabsf_call(x);
	    n  = (__int32_t) (t*invpio2+half);
	    fn = (float)n;
	    r  = t-fn*pio2_1;
	    w  = fn*pio2_1t;	/* 1st round good to 40 bit */
	    if(n<32&&(ix&0xffffff00)!=D_00493C2C[n]) {
		y[0] = r-w;	/* quick check no cancellation */
	    } else {
	        __uint32_t high;
	        j  = ix>>23;
	        y[0] = r-w;
		GET_FLOAT_WORD(high,y[0]);
	        i = j-((high>>23)&0xff);
	        if(i>8) {  /* 2nd iteration needed, good to 57 */
		    t  = r;
		    w  = fn*pio2_2;
		    r  = t-w;
		    w  = fn*pio2_2t-((t-r)-w);
		    y[0] = r-w;
		    GET_FLOAT_WORD(high,y[0]);
		    i = j-((high>>23)&0xff);
		    if(i>25)  {	/* 3rd iteration need, 74 bits acc */
		    	t  = r;	/* will cover all possible cases */
		    	w  = fn*pio2_3;
		    	r  = t-w;
		    	w  = fn*pio2_3t-((t-r)-w);
		    	y[0] = r-w;
		    }
		}
	    }
	    y[1] = (r-y[0])-w;
	    if(hx<0) 	{y[0] = -y[0]; y[1] = -y[1]; return -n;}
	    else	 return n;
	}
    /*
     * all other (large) arguments
     */
	if(!FLT_UWORD_IS_FINITE(ix)) {
	    y[0]=y[1]=x-x; return 0;
	}
    /* set z = scalbn(|x|,ilogb(x)-7) */
	e0 	= (int)((ix>>23)-134);	/* e0 = ilogb(z)-7; */
	SET_FLOAT_WORD(z, ix - ((__int32_t)e0<<23));
	for(i=0;i<2;i++) {
		tx[i] = (float)((__int32_t)(z));
		z     = (z-tx[i])*two8;
	}
	tx[2] = z;
	nx = 3;
	while(tx[nx-1]==zero) nx--;	/* skip zero term */
	n  =  __kernel_rem_pio2f(tx,y,e0,nx,2,two_over_pi);
	if(hx<0) {y[0] = -y[0]; y[1] = -y[1]; return -n;}
	return n;
}
