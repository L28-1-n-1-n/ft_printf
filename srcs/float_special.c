#include "printf.h"
#include <stdio.h>
int  float_special(t_float *fnum, unsigned int bit_value, char type)
{
  if (bit_value == 64)
  {
    if (fnum->exponent == 1024) // full 1 for 11 digits = 2047, 2047 - bias of 1023 = 1024
    {
      if (fnum->mantissa == 0)
      {
        if ((type == 'f') || (type == 'e') || (type == 'g'))
          ft_strcpy(fnum->big_str, "inf");
        else // case 'F', 'E' or 'G'
          ft_strcpy(fnum->big_str, "INF");
      }
      else
      {
        if ((type == 'f') || (type == 'e') || (type == 'g'))
          ft_strcpy(fnum->big_str, "nan");
        else // case 'F', 'E' or 'G'
          ft_strcpy(fnum->big_str, "NAN");
      }
     fnum->eflag |= 4;
     return (1);
    }
  if ((fnum->exponent == -1023) && (fnum->mantissa == 0))
  {
    fnum->integer = 0;
    fnum->decimal = 0;
    return (1);
  }
}
/*  if ((fnum->exponent == 0) && (fnum->mantissa == 0))
    return (1);*/
if (bit_value == 80)
{
  if (fnum->exponent == -16383) // all zero exponent
  {
    if (fnum->mantissa == 0)
    {
      fnum->integer = 0;
      fnum->decimal = 0;
      return (1);
    }
  }
  if (fnum->exponent == 0x7FFF)
  {
    if ((fnum->mantissa >> 61) == (int64_t)2)
    {
      if (fnum->mantissa == 4611686018427387904) // All 1 exponent, 2^62 for mantissa
      {
        if ((type == 'f') || (type == 'e') || (type == 'g'))
          ft_strcpy(fnum->big_str, "inf");
          else // case 'F'
          ft_strcpy(fnum->big_str, "INF");
      }
      else
      {
        if ((type == 'f') || (type == 'e') || (type == 'g'))
          ft_strcpy(fnum->big_str, "snan");
        else // case 'F'
          ft_strcpy(fnum->big_str, "SNAN");
      }
    }
    if ((fnum->mantissa >> 61) == (int64_t)3)
    {
      if ((type == 'f') || (type == 'e') || (type == 'g'))
        ft_strcpy(fnum->big_str, "qnan");
      else // case 'F'
        ft_strcpy(fnum->big_str, "QNAN");
    }
    fnum->eflag |= 4;
  }
}
  return (0);
}
