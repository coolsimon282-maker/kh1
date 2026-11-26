/* gcc 2.95.3 libgcc's fp-bit.c types (include/libgcc-2.95.3), with the bitfield view of the number. The EE
   copy of the float pack_d has no NaN/infinity classes and no rounding, flushes denormals to zero and uses the
   largest exponent for normal numbers (EE single precision): only a fraction that overflowed at that exponent
   saturates. */
#define FINE_GRAINED_LIBRARIES
#define FLOAT
#define FLOAT_BIT_ORDER_MISMATCH
#include "config/fp-bit.c"

FLO_type
pack_d ( fp_number_type *  src)
{
  FLO_union_type dst;
  fractype fraction = src->fraction.ll;
  int sign = src->sign;
  int exp = 0;

  if (iszero (src))
    {
      exp = 0;
      fraction = 0;
    }
  else if (fraction == 0)
    {
      exp = 0;
    }
  else
    {
      if (src->normal_exp < NORMAL_EXPMIN)
	{
	  exp = 0;
	  fraction = 0;
	}
      else if (src->normal_exp > EXPBIAS + 1
	       || (src->normal_exp == EXPBIAS + 1 && (intfrac) fraction < 0))
	{
	  exp = EXPMAX;
	  fraction = 0;
	}
      else
	{
	  exp = src->normal_exp + EXPBIAS;
	  fraction >>= NGARDS;
	}
    }

  dst.bits.fraction = fraction;
  dst.bits.exp = exp;
  dst.bits.sign = sign;
  return dst.value;
}
