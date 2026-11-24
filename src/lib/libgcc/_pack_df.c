/* gcc 2.95.3 libgcc's fp-bit.c types (include/libgcc-2.95.3), with the bitfield view of the number. The EE
   copy of pack_d does no rounding and flushes denormals to zero. */
#define FINE_GRAINED_LIBRARIES
#define FLOAT_BIT_ORDER_MISMATCH
#include "config/fp-bit.c"

FLO_type
pack_d ( fp_number_type *  src)
{
  FLO_union_type dst;
  fractype fraction = src->fraction.ll;
  int sign = src->sign;
  int exp = 0;

  if (isnan (src))
    {
      exp = EXPMAX;
      fraction |= QUIET_NAN;
    }
  else if (isinf (src))
    {
      exp = EXPMAX;
      fraction = 0;
    }
  else if (iszero (src))
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
      else if (src->normal_exp > EXPBIAS)
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
