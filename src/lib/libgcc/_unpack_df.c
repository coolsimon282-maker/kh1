/* gcc 2.95.3 libgcc's fp-bit.c types (include/libgcc-2.95.3). The EE copy of unpack_d has no denormals (a zero
   exponent is zero); the largest exponent is infinity (with normal_exp EXPBIAS and the implicit 1) or a NaN. */
#define FINE_GRAINED_LIBRARIES
#include "config/fp-bit.c"

void
unpack_d (FLO_union_type * src, fp_number_type * dst)
{
  fractype fraction;
  int exp;
  int sign;

  fraction = src->value_raw & ((((fractype)1) << FRACBITS) - (fractype)1);
  exp = ((int)(src->value_raw >> FRACBITS)) & ((1 << EXPBITS) - 1);
  sign = ((int)(src->value_raw >> (FRACBITS + EXPBITS))) & 1;

  dst->sign = sign;
  if (exp == 0)
    {
      dst->class = CLASS_ZERO;
    }
  else if (exp == EXPMAX)
    {
      dst->normal_exp = EXPBIAS;
      if (fraction == 0)
	{
	  dst->class = CLASS_INFINITY;
	  dst->fraction.ll = IMPLICIT_1;
	}
      else
	{
	  if (fraction & QUIET_NAN)
	    {
	      dst->class = CLASS_QNAN;
	    }
	  else
	    {
	      dst->class = CLASS_SNAN;
	    }
	  dst->fraction.ll = fraction;
	}
    }
  else
    {
      dst->normal_exp = exp - EXPBIAS;
      dst->class = CLASS_NUMBER;
      dst->fraction.ll = (fraction << NGARDS) | IMPLICIT_1;
    }
}
