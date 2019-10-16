#include "printf.h"
#include <stdlib.h>

void underflow_exponent(t_float *fnum, long double *fraction, unsigned int bit_value)
{
  if (uf_subnormal(fnum))
    return ;
  else
  {
    fnum->remain = (bit_value == 64) ? (0x10000000000000 + fnum->mantissa) : fnum->mantissa;
    uf_not_subnormal(fnum, fraction, bit_value);
  }
}

void  print_small_range(unsigned int i, t_float *fnum, long double *fraction)
{
  while (i > 0)
  {
    if (fnum->remain & 1)
      fnum->decimal += (((long double)1)/ fraction[i]);
    fnum->remain >>= 1;
    i--;
  }
}

void exp_0_to_neg_12( t_float *fnum, long double *fraction)
{
  unsigned int i;

  fnum->integer = 0;
  fnum->remain = (0x10000000000000 + fnum->mantissa);
  i = 52 + (-1 * fnum->exponent);
  print_small_range(i, fnum, fraction);
}

void   compose_float_64(t_float *fnum, long double *fraction)
{
  unsigned int i;

  i = 0;
  fnum->decimal = 0;
  if ((fnum->exponent >= 0) && (fnum->exponent < 53)) // i.e. <= 52, 1 is added on left most, but shift '.' starts from after this 1
  {
    i = 52 - fnum->exponent; // this is actually 64 - f.e - 1 to take into account that first bit is given to integer 1, if exp is 8, we need to shift 9 bits
    fnum->integer = (0x10000000000000 + fnum->mantissa) >> i; // 1 is manually added superior of the most significant bit as 1 is implied in 64 bit float, but not in 80 bit float
    fnum->remain = (fnum->mantissa << (12 + fnum->exponent)) >> (12 + fnum->exponent);
    print_small_range(i, fnum, fraction);
  }
  else if ((fnum->exponent >= 53) && (fnum->exponent <= 63)) // i.e.total bits is 64, including the 1 we forcefully add in front
  {
    i = 0;
    fnum->integer = (0x10000000000000 + fnum->mantissa) << (fnum->exponent - 52); // tested correct
    fnum->remain = 0;
    print_small_range(i, fnum, fraction);
  }
  else if ((fnum->exponent > -12) && (fnum->exponent < 0))
    exp_0_to_neg_12(fnum, fraction);
  else if (fnum->exponent > 63)
    big_int(fnum);
  else if (fnum->exponent <= -12)
    underflow_exponent(fnum, fraction, 64);
}

void   compose_float_80(t_float *fnum, long double *fraction)
{
  unsigned int i;

  i = 63 - fnum->exponent;
  if ((fnum->exponent >= 0) && (fnum->exponent < 65))
  {
    fnum->decimal = 0;
    fnum->integer = (uint64_t)fnum->mantissa >> i;
    fnum->remain = (uint64_t)(fnum->mantissa << (1 + fnum->exponent)) >> (1 + fnum->exponent);
    print_small_range(i, fnum, fraction);
  }
  if (fnum->exponent > 64)
    big_int_80(fnum);
  if (fnum->exponent < 0)
    underflow_exponent(fnum, fraction, 80);
}
