#include "printf.h"

void underflow_exponent(t_float fnum, long double decimal, long double *fraction, unsigned int bit_value)
{
  uint64_t remain;
  int i;
//  unsigned int array[53]; // this will input the corresoinding ^ at each bit
  unsigned int array[64];
  unsigned int add_exp;
  long double total;

  total = 0;
  remain = (bit_value == 64) ? (0x10000000000000 + fnum.mantissa) : fnum.mantissa;
  ft_bzero(array, 64 * sizeof(unsigned int));
//  ft_bzero(array, 53 * sizeof(unsigned int));
  add_exp = -1 * fnum.exponent;
  decimal = 1;
  i = (bit_value == 64) ? 52 : 63;
  while (i >= 0)
  {
    if (remain & 1)
    {
      array[i] = i + add_exp;
      printf("array[%d] is %d\n",i, array[i]);
      while (array[i] >= 63)
      {
          decimal *= (((long double)1)/ fraction[63]);
          array[i] -=63;
      }
      if (array[i])
        decimal *= (((long double)1)/ fraction[array[i]]);
      total += decimal;
      decimal = 1;
    }
    remain = remain >> 1;
    i--;
  }
  printf("total is finally %.100Lf\n", total);
}

void bit_power(long double *fraction)
{
  unsigned int i;
  unsigned int previous;
  //long double test;
  int final;

  i = 1;
  previous = 1;
  final = 0;
  fraction[0] = 1;
  while (i < 64)
  {
    fraction[i] = (unsigned long long)1 << i;
    i++;
  }
  /*print the whole array
  i = 0;
  while (i < 64)
  {
    printf("fraction[%d] is %Lf\n", i, fraction[i]);
    i++;
  }
//This is to print each decimal number by division
  test = (((long double) 1 )/ fraction[63]) + (((long double) 1 )/ fraction[1]) ;
  printf("test is %.100Lf\n", test);
  final = (int)(test * 10);
  printf("final is %d\n", final);*/
}


void  print_small_range(unsigned int i, uint64_t integer, uint64_t remain, long double decimal, long double *fraction)
{
  printf("integer is %llu\n", integer);
  printf("remain is %llu\n", remain);
  while (i > 0)
  {
    if (remain & 1)
    {
      decimal += (((long double)1)/ fraction[i]);
      printf("i is %d\n", i);
      printf("i is %u, we added %.40Lf and decimal is  %.100Lf\n",i, (((long double)1)/ fraction[i]), decimal);
    }
    remain = remain >> 1;
    i--;
  }
  printf("decimal is finally %.100Lf\n", decimal);
}

void   compose_float_80(t_float fnum, long double *fraction)
{
  uint64_t integer;
  uint64_t remain;
  long double decimal;
  unsigned int i;

  i = 63 - fnum.exponent;
  if ((fnum.exponent > 0) && (fnum.exponent < 65)) // i.e. <= 52, 1 is added on left most, but shift '.' starts from after this 1
  {
    decimal = 0;

    integer = (uint64_t)fnum.mantissa >> i;
    remain = (uint64_t)(fnum.mantissa << (1 + fnum.exponent)) >> (1 + fnum.exponent);
    printf("integer is %llu\n", integer);
    printf("remain is %llu\n", remain);
    print_small_range(i, integer, remain, decimal, fraction);
  }
  if (fnum.exponent > 64)
    big_int_80(fnum); // need to rewrite this so first 8 bits are copied instead of first 7
  if (fnum.exponent < 0)
    underflow_exponent(fnum, decimal, fraction, 80); // needs testing
}



void   compose_float_64(t_float fnum, long double *fraction)
{
  uint64_t integer;
  uint64_t remain;
  long double decimal;
  unsigned int i;

  decimal = 0;
  if ((fnum.exponent > 0) && (fnum.exponent < 53)) // i.e. <= 52, 1 is added on left most, but shift '.' starts from after this 1
  { // tested the above correct
    i = 52 - fnum.exponent; // this is actually 64 - f.e - 1 to take into account that first bit is given to integer 1, if exp is 8, we need to shift 9 bits
    printf("we want integer to be (0x10000000000000 + fnum.mantissa) i.e.%llu\n", (0x10000000000000 + fnum.mantissa));
    integer = (0x10000000000000 + fnum.mantissa) >> i; // 1 is manually added superior of the most significant bit as 1 is implied in 64 bit float, but not in 80 bit float
    remain = (fnum.mantissa << (12 + fnum.exponent)) >> (12 + fnum.exponent);
    print_small_range(i, integer, remain, decimal, fraction);
  }
  if ((fnum.exponent >= 53) && (fnum.exponent <= 63)) // i.e.total bits is 64, including the 1 we forcefully add in front
  { // tested the above correct
    i = 0;
    printf("we want integer to be (0x10000000000000 + fnum.mantissa) i.e.%llu\n", (0x10000000000000 + fnum.mantissa));
    integer = (0x10000000000000 + fnum.mantissa) << (fnum.exponent - 52); // tested correct
    remain = 0;
    print_small_range(i, integer, remain, decimal, fraction);
  }
  if ((fnum.exponent >= -12) && (fnum.exponent < 0))
  {
    integer = 0;
    remain = (0x10000000000000 + fnum.mantissa); // tested and only work when exponent is between -1 and -12
    i = 52 + (-1 * fnum.exponent);
    print_small_range(i, integer, remain, decimal, fraction);
  }
  if (fnum.exponent > 63)
    big_int(fnum);
  if (fnum.exponent < -12)
    underflow_exponent(fnum, decimal, fraction, 64);
}

void   decode_float(uint64_t *word, char *final, t_block *blksk)
{
  t_float fnum;
  long double fraction[64];

  if ((blksk->modifier == 0) || (blksk->modifier == l)) // 1, 11, 52
    {
      fnum.sign = (word[0] >> 63) ? '-' : '+';
      fnum.exponent = ((word[0] << 1) >> 53) - 1023;
      fnum.mantissa = (word[0] << 12) >> 12;
      printf("exponent is %i\n", fnum.exponent);
      printf("mantissa is %lli\n", fnum.mantissa);
      if (fnum.exponent <= 64)
      {
        bit_power(fraction);
        compose_float_64(fnum, fraction);
      }
      printf("exponent is %i\n", fnum.exponent);
      printf("mantissa is %lli\n", fnum.mantissa); // first 12 digits don't count
      compose_float_64(fnum, fraction);
    }
  else // case L, 80 bit, 1, 15, 1 (integer part), 63
    {
      fnum.exponent = ((uint16_t)word[1] & 0x7FFF) - 16383; // 2^31 - 2^16 junk values, 16 bits are 2^15 to 2^0
      fnum.sign = (word[1] & 0x8000) ? '-' : '+';
      fnum.mantissa = word[0]; // This should change
      printf("((uint16_t)word[1] & 0x7FFF) is %d\n", ((uint16_t)word[1] & 0x7FFF));
      printf("L exponent is %hu\n", fnum.exponent);
      printf("mantissa is %llu\n", fnum.mantissa); // first 64 digits don't count
      bit_power(fraction);
      compose_float_80(fnum, fraction);
    }
  printf("sign is %c\n", fnum.sign);
  (void)blksk;
  (void)final;
}
