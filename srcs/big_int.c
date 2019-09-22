#include "printf.h"
#include <stdio.h>
void  print_result(uint64_t *raw, t_float *fnum)
{
  unsigned int i;
  uint64_t mask;
  int digit;
  uint64_t block;
  char str[340]; // max digit = 1 + 309 + 2 = 312 + 20 * \n, where 20 = 320 / 16

  ft_bzero(str, 340);
  digit = 0;
  mask = 0xF000000000000000;
  i = 0;
  while (i < 20)
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
  //  ft_strcat_char(str, '\n');
  }
  i = 0;
  while (str[i] == '0')
    i++;
  digit = ft_strlen(&str[i]) - 2;
  ft_memmove(&str[0], &str[i], digit);
  ft_memset(&str[digit], '\0', 340 - digit);
  ft_strcpy(fnum->big_str, str);
}

void  print_bits(uint64_t *data, char *message, unsigned int number, unsigned int row_no)
{
  uint64_t mask;
  unsigned int bit_number;
  char str[79]; // 64 + 14 + 1

  (void)message;
  (void)number;
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
//  if (strcmp(message, "(add 3)"))
//    printf("-------------------------------------------     %u    ---------------------------------\n", row_no);
//  printf("%s %s %d\n\n", str, message, number);
}

void compare_blocks(uint64_t*raw, unsigned int row_no, uint64_t origin_mask)
{
  uint64_t block;
  uint64_t b_limit;
  uint64_t extra_shift;
  unsigned int digit;
  uint64_t mask;

//  print_bits(raw, "(init)", row_no, row_no);
  digit = 0;
  block = 0;
  b_limit = (row_no == 19) ? 14 : 16;
  extra_shift = (row_no == 19) ? 8 : 0;
  mask = origin_mask;
  while (block < b_limit) // (64 - 8) / 4 = 14, #0 - #13 = total 14 blocks
  {
    digit = (raw[row_no] & mask) >> (extra_shift + block * 4);
    if (digit > 4)
    {
      raw[row_no] += ((uint64_t)3 << (extra_shift + block * 4));
//      print_bits(raw, "(add 3)", block, row_no);
    }
    block++;
    mask = (block == b_limit) ? origin_mask : mask << 4; //reset mask to block 1 before exit loop at block == 14
  }
  if((raw[row_no - 1]) && (row_no != 0))
    compare_blocks(raw, row_no - 1, 0xF);
}

void carry_bit(uint64_t *raw, unsigned int row_no, unsigned int carry)
{
  unsigned int mem;

  if (!(row_no)) // row_no = 0 means no need to consider last line
    return ;
  mem = carry; // store the carry bit from last iteration, e.g. most significant bit of raw[19] will be appended to raw[18] if it was 1
  if (raw[row_no - 1] & 0x8000000000000000)
    carry = 1;
  else
    carry = 0;
  if (raw[row_no - 1])
    raw[row_no - 1] <<= 1;
  if(mem)
    raw[row_no - 1] |= 1;
  carry_bit(raw, row_no - 1, carry);
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
    carry_bit(raw, 19, (raw[19] & 0x8000000000000000) >> 63);
    raw[19] <<= 1;
    shift_count++;
    block = 0;
  //  print_bits(raw, "(shift)", shift, 19);
    compare_blocks(raw, 19, 0xF00);
    shift--;
  }
//  print_bits(raw, "RESULT", 0, 19);
//  printf("\n\nShift_count is %d\n", shift_count);
}

void  big_int(t_float *fnum)
{
  uint64_t raw[21]; //max no. of bits required = [(308 * 4) + 1 (1 bit for integer force add) + 8] / 64, where (2-2^-52) * 2^1023 = 10^308
  uint64_t man_mask;
  int z;

  z = 45;
  man_mask = 0x1FE00000000000; // this value >> 8 gives the 8 bits right after the first 7 bits
  ft_bzero(&raw[0], 21 * sizeof(uint64_t));
  raw[19] |= (((fnum->mantissa & 0xFE00000000000) >> z) + 0x80); // add most significant 7 bits of mantissa to raw , then put 1 in froht of most sig. bit
  while (z >= 5)
  {
  //  print_bits(raw, "(init)", 19, 19);
    within_row(raw, 8);
    man_mask >>= 8;
    z -= 8;
    raw[19] = (z > 0)? raw[19] | ((fnum->mantissa & man_mask) >> z) : raw[19] | ((fnum->mantissa & man_mask) << (-1 * z));
  }
  //print_bits(raw, "(hola)", 19, 19);
  within_row(raw, 8);
  z = fnum->exponent - 52 + z;
  //printf("z is %d\n", z);
  //print_bits(raw, "(HOLA)", 19, 19);
  while (z > 8)
  {
    within_row(raw, 8);
    z -= 8;
  }
  within_row(raw, z - 1); //1 less zero, since we will shift one last time just after this
//  printf("-------------------------------------------     ONE LAST SHIFT    ---------------------------------\n");
  carry_bit(raw, 20, 0); // if we put 19, row[19] will not be shifted for one last shift
//  print_bits(raw, "RESULT", 17, 17);
//  print_bits(raw, "RESULT", 18, 18);
//  print_bits(raw, "RESULT", 19, 19);
  print_result(raw, fnum);
}
