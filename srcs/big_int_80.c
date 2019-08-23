#include "printf.h"
#include <stdio.h>
void  print_result_80(uint64_t *raw)
{
  unsigned int i;
  uint64_t mask;
  int digit;
  uint64_t block;
  char str[5270]; // max digit = 1 + 4932 + 2 = 312 + 20 * \n, where 20 = 320 / 16


  ft_bzero(str, 5270);
  digit = 0;
  mask = 0xF000000000000000;
  i = 0;
  while (i < 310)
  {
    block = 0;
    while (block < 16) // (64 - 8) / 4 = 14, #0 - #13 = total 14 blocks
    {
      digit = (raw[i] & mask) >> ((15 - block) * 4);
      ft_strcat_char(str, digit + '0');
      block++;
      mask = (block == 16) ? 0xF000000000000000 : mask >> 4; //reset mask to block 1 before exit loop at block == 14
    }
    i++;
    ft_strcat_char(str, '\n');
    printf("last i is %d\n",i);
  }

  printf("RESULTING NUMBER IS %s\n", str);
}

void  print_bits_80(uint64_t *data, char *message, unsigned int number, unsigned int row_no)
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
    if (data[row_no] & mask)
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
    if (data[row_no] & mask)
      ft_strcat(str, "1");
    else
      ft_strcat(str,"0");
    mask = mask >> 1;
    bit_number--;
  }
  if (strcmp(message, "(add 3)"))
    printf("-------------------------------------------     %u    ---------------------------------\n", row_no);
  printf("%s %s %d\n\n", str, message, number);
}

void compare_blocks_80(uint64_t*raw, unsigned int row_no, uint64_t origin_mask)
{
  uint64_t block;
  uint64_t b_limit;
  uint64_t extra_shift;
  unsigned int digit;
  uint64_t mask;

  print_bits_80(raw, "(init)", row_no, row_no);
  digit = 0;
  block = 0;
  b_limit = (row_no == 309) ? 14 : 16;
  extra_shift = (row_no == 309) ? 8 : 0;
  mask = origin_mask;
  while (block < b_limit) // (64 - 8) / 4 = 14, #0 - #13 = total 14 blocks
  {
    digit = (raw[row_no] & mask) >> (extra_shift + block * 4);
    if (digit > 4)
    {
      raw[row_no] += ((uint64_t)3 << (extra_shift + block * 4));
      print_bits_80(raw, "(add 3)", block, row_no);
    }
    block++;
    mask = (block == b_limit) ? origin_mask : mask << 4; //reset mask to block 1 before exit loop at block == 14
  }
  if((raw[row_no - 1]) && (row_no != 0))
    compare_blocks_80(raw, row_no - 1, 0xF);
}

void carry_bit_80(uint64_t *raw, unsigned int row_no, unsigned int carry)
{
  if (!(row_no)) // row_no = 0 means no need to consider last line
    return ;
  unsigned int mem;

  mem = carry; // store the carry bit from last iteration, e.g. most significant bit of raw[19] will be appended to raw[18] if it was 1
  if (raw[row_no - 1] & 0x8000000000000000)
    carry = 1;
  else
    carry = 0;
  if (raw[row_no - 1])
    raw[row_no - 1] <<= 1;
  if(mem)
    raw[row_no - 1] |= 1;
  carry_bit_80(raw, row_no - 1, carry);
}

void  within_row_80(uint64_t *raw, unsigned int shift)
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
    carry_bit_80(raw, 309, (raw[309] & 0x8000000000000000) >> 63);
    raw[309] <<= 1;
    shift_count++;
    block = 0;
    print_bits_80(raw, "(shift)", shift, 309);
    compare_blocks_80(raw, 309, 0xF00);
    shift--;
  }
  print_bits_80(raw, "RESULT", 0, 309);
  printf("\n\nShift_count is %d\n", shift_count);
}

void  big_int_80(t_float fnum)
{
  uint64_t raw[311]; //max no. of bits required = [(308 * 4) + 1 (1 bit for integer force add) + 8] / 64, where (2-2^-52) * 2^1023 = 10^308
  uint64_t man_mask;
  int z;

  z = 56;
  man_mask = 0xFF00000000000000; // this value >> 8 gives the 8 bits right after the first 7 bits
  ft_bzero(&raw[0], 311 * sizeof(uint64_t));
  raw[309] |= ((fnum.mantissa & 0xFF00000000000000) >> z); // add most significant 7 bits of mantissa to raw , then put 1 in froht of most sig. bit
  while (z > 0)
  {
    print_bits_80(raw, "(init)", 309, 309);
    within_row_80(raw, 8);
    man_mask >>= 8;
    z -= 8;
    printf("mask is %llu and z is %d\n", man_mask, z);
    raw[309] |= ((fnum.mantissa & man_mask) >> z);
  }
  print_bits_80(raw, "(hola)", 309, 309);
  within_row_80(raw, 8);
  z = fnum.exponent - 64;
  printf("z is %d\n", z);
  print_bits_80(raw, "(HOLA)", 309, 309);
  while (z > 8)
  {
    within_row_80(raw, 8);
    z -= 8;
  }
  within_row_80(raw, z); //1 less zero, since we will shift one last time just after this
  printf("-------------------------------------------     ONE LAST SHIFT    ---------------------------------\n");
  carry_bit_80(raw, 310, 0); // if we put 19, row[19] will not be shifted for one last shift
  print_bits_80(raw, "RESULT", 308, 308);
  print_bits_80(raw, "RESULT", 309, 309);
  print_bits_80(raw, "RESULT", 310, 310);
  printf("-------------------     When you read the result, make sure to ignore the last 00000000 of raw[19]   ---------------\n");
  printf("--------------TO DO : write function to translate the result number into digits and then result string    ----------\n");
  print_result_80(raw);
}
