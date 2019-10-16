#include "printf.h"

void uf_not_subnormal(t_float *fnum, long double *fraction, unsigned int bit_value)
{
  int i;
  long double tmp_decimal;
  unsigned int array[64];

  ft_bzero(array, 64 * sizeof(unsigned int));
  tmp_decimal = 1;
  i = (bit_value == 64) ? 52 : 63;
  while (i >= 0)
  {
    if (fnum->remain & 1)
    {
      array[i] = i + (-1 * fnum->exponent);
      while (array[i] >= 63)
      {
          tmp_decimal *= (((long double)1)/ fraction[63]);
          array[i] -=63;
      }
      if (array[i])
        tmp_decimal *= (((long double)1)/ fraction[array[i]]);
      fnum->decimal += tmp_decimal;
      tmp_decimal = 1;
    }
    fnum->remain = fnum->remain >> 1;
    i--;
  }
}

unsigned int uf_subnormal(t_float *fnum)
{
    if (fnum->exponent == -1023)
    {
      fnum->remain = fnum->mantissa;
      fnum->exponent += 1;
      sub_array(fnum);
      return (1);
    }
    if (fnum->exponent == -16383)
    {
      fnum->remain = ((uint64_t)(fnum->mantissa << 1)) >> 1;
      fnum->exponent += 1;
      sub_array_80(fnum);
      return (1);
    }

    return (0);
}
