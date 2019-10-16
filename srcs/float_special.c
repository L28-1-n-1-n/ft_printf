#include "printf.h"
#include <stdio.h>

void cat_words_64(t_float *fnum, char type)
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
}

int f_special_64(t_float *fnum, char type)
{
  if (fnum->exponent == 1024) // full 1 for 11 digits = 2047, 2047 - bias of 1023 = 1024
  {
   cat_words_64(fnum, type);
   fnum->eflag |= 4;
   return (1);
  }
  if ((fnum->exponent == -1023) && (fnum->mantissa == 0))
  {
    fnum->integer = 0;
    fnum->decimal = 0;
    return (1);
  }
  return (0);
}

void cat_words_80(t_float *fnum, char type)
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

int f_special_80(t_float *fnum, char type)
{
  if ((fnum->exponent == -16383) && (fnum->mantissa == 0)) // all zero exponent
  {
    fnum->integer = 0;
    fnum->decimal = 0;
    return (1);
  }
  if (fnum->exponent == 0x7FFF)
  {
    if ((fnum->mantissa >> 61) == (int64_t)2)
      cat_words_80(fnum, type);
    if ((fnum->mantissa >> 61) == (int64_t)3)
    {
      if ((type == 'f') || (type == 'e') || (type == 'g'))
        ft_strcpy(fnum->big_str, "qnan");
      else // case 'F'
        ft_strcpy(fnum->big_str, "QNAN");
    }
    fnum->eflag |= 4;
    return (1);
  }
  return (0);
}

int  float_special(t_float *fnum, unsigned int bit_value, char type)
{
  if (bit_value == 64)
    return(f_special_64(fnum, type));
else if (bit_value == 80)
    return(f_special_80(fnum, type));
return (0);
}
