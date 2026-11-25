// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"

#include "fdlibm.h"

double cos(double x)
{
	double y[2],z=0.0;
	__int32_t n,ix;

	GET_HIGH_WORD(ix,x);

	ix &= 0x7fffffff;
	if(ix <= 0x3fe921fb) return __kernel_cos(x,z);

	else if (ix>=0x7ff00000) return x-x;

	else {
	    n = __ieee754_rem_pio2(x,y);
	    switch(n&3) {
		case 0: return  __kernel_cos(y[0],y[1]);
		case 1: return -__kernel_sin(y[0],y[1],1);
		case 2: return -__kernel_cos(y[0],y[1]);
		default:
		        return  __kernel_sin(y[0],y[1],1);
	    }
	}
}
