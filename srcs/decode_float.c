#include "printf.h"
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
  i = 0;
  /*print the whole array
  while (i < 64)
  {
    printf("fraction[%d] is %Lf\n", i, fraction[i]);
    i++;
  }*/
/* This is to print each decimal number by division
  test = (((long double) 1 )/ fraction[63]) + (((long double) 1 )/ fraction[1]) ;
  printf("test is %.100Lf\n", test);
  final = (int)(test * 10);
  printf("final is %d\n", final);*/
}
/*
void   compose_float_80(t_float fnum, long double *fraction, unsigned int bit_value)
{
  uint64_t integer;
  uint64_t remain;
  long double decimal;
  unsigned int i;

  i = (bit_value == 64) ? 52 - fnum.exponent : 63 - fnum.exponent; // this is actually 64 - f.e - 1 to take into account that first bit is given to integer 1, if exp is 8, we need to shift 9 bits
  //i = 52 - fnum.exponent;
  decimal = 0;
  if (bit_value == 64)
  {
    if (fnum.exponent > 0)
    {
      i = (bit_value == 64) ? 52 - fnum.exponent : 63 - fnum.exponent;
      integer = (0x10000000000000 + fnum.mantissa) >> (i); // 1 is manually added superior of the most significant bit as 1 is implied in 64 bit float, but not in 80 bit float
      remain = (fnum.mantissa << (12 + fnum.exponent)) >> (12 + fnum.exponent);
    }
    if (fnum.exponent < 0)
    {
      integer = 0;
      remain = (0x10000000000000 + fnum.mantissa); // this will only work when exponent is between -1 and -20
      i = 52 + (-1 * fnum.exponent);
    }
  } // We now need major restructuring. One function for float 64, one for float 80, and one for use decimal array method, another for BCD method
  else // case float_80
  {
    integer = fnum.mantissa >> i;
    remain = (fnum.mantissa << (1 + fnum.exponent)) >> (1 + fnum.exponent);
  }
  printf("integer is %llu\n", integer);
  //result : first 12 + exp bits of decimal = 12 + 8 = 20 bits must be = 0 and will not be considered
  printf("remain is %llu\n", remain);
  // last bit is 2^-44, where 44 = 52 - 8, i.e. 52 - exponent

  while (i > 0)
  {
    if (remain & 1)
    {
      decimal += (((long double)1)/ fraction[i]);
      printf("i is %u, we added %.40Lf and decimal is  %.100Lf\n",i, (((long double)1)/ fraction[i]), decimal);
    }
    remain = remain >> 1;
    i--;
  }
  printf("decimal is finally %.100Lf\n", decimal);
}
*/
void  print_small_range(unsigned int i, uint64_t integer, uint64_t remain, long double decimal, long double *fraction)
{
  printf("integer is %llu\n", integer);
  //result : first 12 + exp bits of decimal = 12 + 8 = 20 bits must be = 0 and will not be considered
  printf("remain is %llu\n", remain);
  // last bit is 2^-44, where 44 = 52 - 8, i.e. 52 - exponent

  while (i > 0)
  {
    if (remain & 1)
    {
      decimal += (((long double)1)/ fraction[i]);
      printf("i is %u, we added %.40Lf and decimal is  %.100Lf\n",i, (((long double)1)/ fraction[i]), decimal);
    }
    remain = remain >> 1;
    i--;
  }
  printf("decimal is finally %.100Lf\n", decimal);
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
  if (fnum.exponent < 0)
  {
    integer = 0;
    remain = (0x10000000000000 + fnum.mantissa); // tested and only work when exponent is between -1 and -12
    i = 52 + (-1 * fnum.exponent);
    print_small_range(i, integer, remain, decimal, fraction);
  }
  if (fnum.exponent > 63)
    big_int(fnum);
  // We now need major restructuring. One function for float 64, one for float 80, and one for use decimal array method, another for BCD method
  /*else // case float_80
  {
    integer = fnum.mantissa >> i;
    remain = (fnum.mantissa << (1 + fnum.exponent)) >> (1 + fnum.exponent);
  }*/

//  print_small_range(i, integer, remain, decimal, fraction);
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
  else // case L, 80 bit
    {
      fnum.exponent = (word[1] & 0x7FFF) - 16383; // 2^31 - 2^16 junk values, 16 bits are 2^15 to 2^0
      fnum.sign = (word[1] & 0x8000) ? '-' : '+';
      fnum.mantissa = word[0]; // This should change
      // remove leading 16 bits, then the trailing zeros should become last 16 bits of word[1], or uint16_t of word 1
      printf("L exponent is %hu\n", fnum.exponent);
      printf("mantissa is %llu\n", fnum.mantissa); // first 64 digits don't count
    //  compose_float_80(fnum, fraction, 80);
    }
  // the other option is 80 bits, 1, 15, 1 (integer part), 63
  printf("sign is %c\n", fnum.sign);
  (void)blksk;
  (void)final;
}
