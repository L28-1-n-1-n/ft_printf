#include "printf.h"
void bit_power(long double *fraction)
{
  unsigned int i;
  unsigned int previous;
  long double test;
  int final;
//  float wow;

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

  test = (((long double) 1 )/ fraction[63]) + (((long double) 1 )/ fraction[1]) ;
  printf("test is %.100Lf\n", test);
  final = (int)(test * 10);
  printf("final is %d\n", final);
}

void   compose_float(t_float fnum, long double *fraction, unsigned int bit_value)
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
    integer = (0x10000000000000 + fnum.mantissa) >> (i); // 1 is manually added superior of the most significant bit as 1 is implied in 64 bit float, but not in 80 bit float
    remain = (fnum.mantissa << (12 + fnum.exponent)) >> (12 + fnum.exponent);
  }
  else
  {
    integer = fnum.mantissa >> (i);
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
void   decode_float(uint64_t *word, char *final, t_block *blksk)
{
  t_float fnum;
  long double fraction[64];

  bit_power(fraction);
  if ((blksk->modifier == 0) || (blksk->modifier == l)) // 1, 11, 52
    {
      if (word[0] >> 63) // same for 63 or 80 bits
        fnum.sign = '-';
      else
        fnum.sign = '+';
      fnum.exponent = ((word[0] << 1) >> 53) - 1023;
      printf("exponent is %hu\n", fnum.exponent);
      fnum.mantissa = (word[0] << 12) >> 12;
      printf("mantissa is %llu\n", fnum.mantissa); // first 12 digits don't count
      compose_float(fnum, fraction, 64);
    }
  else // case L, 80 bit
    {
      fnum.exponent = (word[1] & 0x7FFF) - 16383; // 2^31 - 2^16 junk values, 16 bits are 2^15 to 2^0
      printf("L exponent is %hu\n", fnum.exponent);
      if (word[1] & 0x8000) // same for 63 or 80 bits
        fnum.sign = '-';
      else
        fnum.sign = '+';
      fnum.mantissa = word[0]; // This should change
      // remove leading 16 bits, then the trailing zeros should become last 16 bits of word[1], or uint16_t of word 1
      printf("mantissa is %llu\n", fnum.mantissa); // first 64 digits don't count
      compose_float(fnum, fraction, 80);
    }
  // the other option is 80 bits, 1, 15, 1 (integer part), 63
  printf("sign is %c\n", fnum.sign);
  (void)blksk;
  (void)final;
}
