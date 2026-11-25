// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"

#include "fdlibm.h"

	double fabs(double x)
{
	__uint32_t high;
	GET_HIGH_WORD(high,x);
	SET_HIGH_WORD(x,high&0x7fffffff);
        return x;
}
