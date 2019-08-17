#include "printf.h"
#include <stdio.h>

void  print_bits(uint64_t data, char *message, unsigned int number)
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
  ft_strcat(str, " ");
  mask = 0x80;
  while (bit_number)
  {
    if (data & mask)
      ft_strcat(str, "1");
    else
      ft_strcat(str,"0");
    mask = mask >> 1;
    bit_number--;
  }
  printf("%s %s %d\n\n", str, message, number);
}

void  within_row(uint64_t *raw, unsigned int shift)
{
  uint64_t block;
  unsigned int digit;
  uint64_t mask;
  static int shift_count = 0;

  block = 0;
  mask = 0xF00; // start at 9th bit
  digit = 0;
  while (shift) // loop until copied number is shifted 8 times
  {
    raw[19] = raw[19] << 1;
    shift_count++;
    block = 0;
    print_bits(raw[19], "(shift)", shift);
    while (block < 14) // (64 - 8) / 4 = 14, #0 - #13 = total 14 blocks
    {
  //    printf("mask is %llu at block %d\n", mask, block);
      digit = (raw[19] & mask) >> (8 + block * 4);
  //    printf("raw[19] has value %llu\n", raw[19]);
  //    printf("mask is %llu\n", mask);
  //    printf("digit is %d\n", digit);
      if (digit > 4)
      {
        raw[19] += ((uint64_t)3 << (8 + block * 4));
        print_bits(raw[19], "(add 3)", block);
        if (block == 6)
          printf("%llu is added to the above value\n", ((uint64_t)3 << (8 + block * 4)));
      }
      mask = (block == 13) ? 0xF00 : mask << 4;
      block++;
    }
    shift--;
  }
  print_bits(raw[19], "RESULT", 0);
  printf("\n\nShift_count is %d\n", shift_count);
}

void  big_int(t_float fnum)
{
  uint64_t raw[20]; //max no. of bits required = [(308 * 4) + 1 (1 bit for integer force add) + 8] / 64, where (2-2^-52) * 2^1023 = 10^308
  uint64_t man_mask;
  int z;
  int remain_z;

  z = 45;
  man_mask = 0x1FE00000000000; // this value >> 8 gives the 8 bits right after the first 7 bits
  ft_bzero(&raw[0], 20 * sizeof(uint64_t));
  raw[19] |= (((fnum.mantissa & 0xFE00000000000) >> z) + 0x80); // add most significant 7 bits of mantissa to raw , then put 1 in froht of most sig. bit
  while (z >= 5)
  {
    print_bits(raw[19], "(init)", 0);
    within_row(raw, 8);
    man_mask >>= 8;
    z -= 8;
    if (z > 0)
      raw[19] |= ((fnum.mantissa & man_mask) >> z);
    else
      raw[19] |= ((fnum.mantissa & man_mask) << (-1 * z));
  }
  print_bits(raw[19], "(init)", 0);
  within_row(raw, 8);
  remain_z = fnum.exponent - 52 + z;
  print_bits(raw[19], "(init)", 0);
  while (remain_z > 8)
  {
    within_row(raw, 8);
    remain_z -= 8;
  }
  within_row(raw, remain_z);
  // next step is to copy the last 5 bits from mantissa, then << 3, then copy that to raw[19] and shift one cycle
  // then repeat cycle calling on raw[19] alone, until exponent - 52 nos. of zeroes has been shifted
  // for that, we need to write method to shift and add least significant bit to one row above
  int i;
  i = 0;
  (void)fnum;
  while (i < 20)
  {
    printf("raw[%d] has value %llu\n" , i, raw[i]);
    i++;
  }
  //remain is essentially zeros
}
