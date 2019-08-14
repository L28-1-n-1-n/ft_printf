#include "printf.h"

int  float_special(double n, long double long_n, unsigend int bit_value, char *final)
{
  unsigned int flag;

  flag = 0;
  if (bit_value = 64)
  {
    if ((isnan(n)) ||(n == 0x7FF0000000000001) || (n == 0x7FFFFFFFFFFFFFF)
        (n == 0x7FF8000000000001) || (n == 0x7FFFFFFFFFFFFFFF))
    {
      ft_strcat(final, "NaN");
      return (1);
    }
  }
  else // case bit 80
  {
    if(isnan(long_n))
      ft_strcat(final, "nan");
  }

  return (0);
}


// 0x7F0000000000000 positive infinity
// also need to catch subnormal stuff, i.e. digits, i.e. exponent is 0 (see wikipedia)
// when you deal with precision, take care to know that you can ask for more precsion than there is, and stop when it is over the limit, or keep printig zeros
