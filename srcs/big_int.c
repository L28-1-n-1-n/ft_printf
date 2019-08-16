#include "printf.h"
#include <stdio.h>

void  print_bits(uint64_t data, char *message)
{
  uint64_t mask;
  unsigned int bit_number;
  char str[79]; // 64 + 14 + 1

  ft_bzero(str, 79);
  bit_number = 64;
  mask = 0x8000000000000000;
  while (bit_number > 8)
  {
    if (!(bit_number % 4))
      ft_strcat(str, " ");
    if (data & mask)
      ft_strcat(str, "1");
    else
      ft_strcat(str,"0");
    mask = mask >> 1;
    bit_number--;
  }
  mask = 0xF;
  while (bit_number)
  {
    if (data & mask)
      ft_strcat(str, "1");
    else
      ft_strcat(str,"0");
    mask = mask >> 1;
    bit_number--;
  }
  printf("%s %s\n", str, message);
}

void  big_int(t_float fnum)
{
  uint64_t raw[20]; //max no. of bits required = [(308 * 4) + 1 (1 bit for integer force add) + 8] / 64, where (2-2^-52) * 2^1023 = 10^308
  unsigned int block;
  unsigned int shift;
  uint8_t digit;
  uint64_t mask;
//  char message[10];

//  ft_bzero(message, 10);
  block = 0;
  digit = 0;
  mask = 0xF00; // start at 9th bit
  ft_bzero(&raw[0], 20 * sizeof(uint64_t));
  raw[19] |= (((fnum.mantissa & 0xFE00000000000) >> 45) + 0x80); // add most significant 7 bits of mantissa to raw , then put 1 in froht of most sig. bit
  shift = 8;
// fnum.mantissa = fnum.mantissa << 8; // will somehow need to find a way to count to 52
  print_bits(raw[19], "(init)\n");


  while (shift) // loop until copied number is shifted 8 times
  {
    raw[19] = raw[19] << 1;
    block = 0;
    print_bits(raw[19], "(shift)\n");
    while (block < 15) // (64 - 8) / 4 = 14
    {
      digit = raw[19] & mask;
      if (digit > 4)
      {
        raw[19] |= (3 << (block * 4));
        print_bits(raw[19], "(add 3)\n");
      }
      mask = mask << 4;
      block++;
    }
    shift--;
  }
  print_bits(raw[19], "RESULT\n");

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
