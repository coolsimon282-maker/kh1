/* gcc 2.95.3 libgcc's fp-bit.c types (include/libgcc-2.95.3). The EE copy of unpack_d has no denormal or
   NaN/infinity handling: a zero exponent is zero, anything else a normal number. */
#define FINE_GRAINED_LIBRARIES
#define FLOAT
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
  else
    {
      dst->normal_exp = exp - EXPBIAS;
      dst->class = CLASS_NUMBER;
      dst->fraction.ll = (fraction << NGARDS) | IMPLICIT_1;
    }
}
