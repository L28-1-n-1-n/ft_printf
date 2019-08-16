#include "printf.h"
#include <stdio.h>

void  big_int(t_float fnum)
{
  uint64_t raw[20]; //max no. of bits required = [(308 * 4) + 1 (1 bit for integer force add) + 8] / 64, where (2-2^-52) * 2^1023 = 10^308
  unsigned int block;
  uint8_t digit;
  uint64_t mask;

  block = 0;
  digit = 0;
  mask = 0xF;
  ft_bzero(&raw[0], 20 * sizeof(uint64_t));
  raw[19] |= (((fnum.mantissa & 0xFE00000000000) >> 45) + 0x80); // add most significant 7 bits of mantissa to raw , then put 1 in froht of most sig. bit

// fnum.mantissa = fnum.mantissa << 8; // will somehow need to find a way to count to 52
  raw[19] = raw[19] << 1;
  while (block < 15) // (64 - 8) / 4 = 14
  {
    digit = raw[19] & mask;
    if (digit > 4)
    {
      digit += 3;
      raw[19] |= (digit << (block * 4));
      break;
    }
    mask = mask << 4;
    block++;
  }
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
