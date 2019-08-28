#include "printf.h"

int  float_special(t_float *fnum, unsigned int bit_value)
{
  printf("exponent is %d\n", fnum->exponent);
  if (bit_value == 64)
  {
    if (fnum->exponent == 1024) // full 1 for 11 digits = 2047, 2047 - bias of 1023 = 1024
    {
      if (fnum->mantissa == 0)
        ft_strcpy(fnum->big_str, "inf");
      else
        ft_strcpy(fnum->big_str, "nan");
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
if (bit_value = 80)
{
  if (fnum->exponent == -16383) // all zero exponent
  {
    if (fnum->mantissa == 0)
    {
      fnum->integer = 0;
      fnum->decimal = 0;
      return (1);
    }
    else
      denormalized;
    return (1);
  }
}

  return (0);
}

//0xFFF0000000000000L negative infinity, does not work = = but like the real printf, it is treated as positive 0
 // 0x7F0000000000000 positive infinity --> does NOT work = =
 // the tricky thing is, when positive inf and neg inf are read as double, somehow they are not the same number as in wikipedia
// also need to catch subnormal stuff, i.e. digits, i.e. exponent is 0 (see wikipedia)
// when you deal with precision, take care to know that you can ask for more precsion than there is, and stop when it is over the limit, or keep printig zeros
// needs to deal with big int such as -1119223372036854775808.0L
//https://gcc.gnu.org/onlinedocs/gcc/Floating-Types.html check out __float80 and __float128 types
//https://www.youtube.com/watch?v=6frTBpLN1L8 different ways : denormalized number represented by the same 80 or 64 bits
