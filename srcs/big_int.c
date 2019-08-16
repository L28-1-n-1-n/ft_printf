#include "printf.h"
#include <stdio.h>

void  big_int(t_float fnum)
{
  uint64_t raw[20]; //max no. of bits required = [308 + 1 (1 bit for integer force add) + 8] * 4 , where (2-2^-52) * 2^1023 = 10^308

  ft_bzero(&raw[0], 20 * sizeof(uint64_t));

  raw[19] |= (fnum.mantissa & 0xFF00000000000); // add most significant 8 bits of mantissa to raw  // we forgot the first 1 !!!
  --> the above is incorrect. needs to first add 1 in front of it and then >> 52 - 8 bits
// fnum.mantissa = fnum.mantissa << 8; // will somehow need to find a way to count to 52

  int i;
  i = 0;
  (void)fnum;
  while (i < 20)
  {
    printf("raw[%d] has value %llu\n" , i, raw[i]);
    i++;
  }
  //remain is essentially zeros
  printf("size of uint64_t is %lu\n", sizeof(uint64_t));
}
