#include "printf.h"
#include <stdlib.h>

void round_float(char *final, int carry, size_t i)
{
  if (!carry)
    return(0);
  if (final[i] == '9') // i.e. carry is 1
    if (final[i - 1] == '9')
      round_float(final, 1, i - 1);
    else
    {
      final[i - 1]++;
      final[i] = '0';
    }
  else
    final[i]++;
  return (0);
}

void print_float_str(char *final, t_block *blksk, t_float *fnum)
{
  char str[8192];
  int carry;

  carry = 0;
  ft_bzero(str, 8192);
  if (fnum->sign == '-')
    str[0] = '-';
  if ((fnum->sign == '+') && (blksk->flag & 4))
    str[0] = '+';
  if (blksk->precision == 0)
    fnum->integer = ((int)(fnum->decimal * 10) >= 5) ? fnum->integer + 1 : fnum->integer;
  while (fnum->integer / 10)
    {
      ft_strcat_char(str, fnum->integer % 10 + '0');
      fnum->integer = fnum->integer / 10;
    }
    ft_strcat_char(str, fnum->integer + '0'); // this is the case where rounding to precision 0 is dealt with
  if ((str[0] == '-') || (str[0] == '+'))
    ft_strrev(&str[1]);
  else
    ft_strrev(str);
  if ((blksk->flag & 16) || (blksk->precision)) // '#' is on
    ft_strcat_char(str, '.');
    // PROBLEM: ROUNDING NEEDS TO BE RECURSIVE UNTIL YOU'VE ROUNDED ALL 9s !!!
    // the idea of multiplying the decimal by power is out of the question, imagine a precision of 100, then you will have 10^100
    // will just have to write function to retrospectively change the last digit of str, recursive function until you no longer hit a 9
  if (blksk->precision > 0)
  {
    while (blksk->precision > 0)
    {
      ft_strcat_char(str,(int)(fnum->decimal * 10) + '0');
      fnum->decimal = fnum->decimal * 10 - (int)(fnum->decimal * 10);
      printf("fnum->decimal is %Lf\n", fnum->decimal);
      printf("precision is now %d\n", blksk->precision);
      blksk->precision--;
    }
    carry = ((int)(fnum->decimal * 10) >= 5) ? 1 : 0);
    round_float(final, carry, ft_strlen(final));
  }
/*  if ((int)(fnum->decimal * 10) >= 5)
    ft_strcat_char(str,(int)(fnum->decimal * 10) + 1 + '0');
  else
    ft_strcat_char(str,(int)(fnum->decimal * 10) + '0');*/
  printf("str is %s\n", str);
  printf("final is %s\n", final);
  (void)blksk;
}

void underflow_exponent(t_float *fnum, long double *fraction, unsigned int bit_value)
{
  int i;
  long double tmp_decimal;
  unsigned int array[64];

  fnum->remain = (bit_value == 64) ? (0x10000000000000 + fnum->mantissa) : fnum->mantissa;
  ft_bzero(array, 64 * sizeof(unsigned int));
  tmp_decimal = 1;
  i = (bit_value == 64) ? 52 : 63;
  while (i >= 0)
  {
    if (fnum->remain & 1)
    {
      array[i] = i + (-1 * fnum->exponent);
      while (array[i] >= 63)
      {
          tmp_decimal *= (((long double)1)/ fraction[63]);
          array[i] -=63;
      }
      if (array[i])
        tmp_decimal *= (((long double)1)/ fraction[array[i]]);
      fnum->decimal += tmp_decimal;
      tmp_decimal = 1;
    }
    fnum->remain = fnum->remain >> 1;
    i--;
  }
  printf("total is finally %.100Lf\n", fnum->decimal);
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


void  print_small_range(unsigned int i, t_float *fnum, long double *fraction)
{
  printf("integer is %llu\n", fnum->integer);
  printf("remain is %llu\n", fnum->remain);
  printf("YOLO\n");
  while (i > 0)
  {
    if (fnum->remain & 1)
    {
      fnum->decimal += (((long double)1)/ fraction[i]);
      printf("i is %d\n", i);
      printf("i is %u, we added %.40Lf and decimal is  %.100Lf\n",i, (((long double)1)/ fraction[i]), fnum->decimal);
    }
    fnum->remain = fnum->remain >> 1;
    i--;
  }
  printf("decimal is finally %.100Lf\n", fnum->decimal);

}

void   compose_float_80(t_float *fnum, long double *fraction)
{
  unsigned int i;

  i = 63 - fnum->exponent;
  if ((fnum->exponent > 0) && (fnum->exponent < 65)) // i.e. <= 52, 1 is added on left most, but shift '.' starts from after this 1
  {
    fnum->decimal = 0;
    fnum->integer = (uint64_t)fnum->mantissa >> i;
    fnum->remain = (uint64_t)(fnum->mantissa << (1 + fnum->exponent)) >> (1 + fnum->exponent);
    printf("integer is %llu\n", fnum->integer);
    printf("remain is %llu\n", fnum->remain);
    print_small_range(i, fnum, fraction);
  }
  if (fnum->exponent > 64)
    big_int_80(fnum); // need to rewrite this so first 8 bits are copied instead of first 7
  if (fnum->exponent < 0)
    underflow_exponent(fnum, fraction, 80); // needs testing
//  print_float_str(final, blksk, fnum);
}



void   compose_float_64(t_float *fnum, long double *fraction)
{
  unsigned int i;

  fnum->decimal = 0;
  if ((fnum->exponent > 0) && (fnum->exponent < 53)) // i.e. <= 52, 1 is added on left most, but shift '.' starts from after this 1
  {
    i = 52 - fnum->exponent; // this is actually 64 - f.e - 1 to take into account that first bit is given to integer 1, if exp is 8, we need to shift 9 bits
    fnum->integer = (0x10000000000000 + fnum->mantissa) >> i; // 1 is manually added superior of the most significant bit as 1 is implied in 64 bit float, but not in 80 bit float
    fnum->remain = (fnum->mantissa << (12 + fnum->exponent)) >> (12 + fnum->exponent);
    print_small_range(i, fnum, fraction);
  }
  if ((fnum->exponent >= 53) && (fnum->exponent <= 63)) // i.e.total bits is 64, including the 1 we forcefully add in front
  {
    i = 0;
    fnum->integer = (0x10000000000000 + fnum->mantissa) << (fnum->exponent - 52); // tested correct
    fnum->remain = 0;
    print_small_range(i, fnum, fraction);
  }
  if ((fnum->exponent >= -12) && (fnum->exponent < 0))
  {
    fnum->integer = 0;
    fnum->remain = (0x10000000000000 + fnum->mantissa); // tested and only work when exponent is between -1 and -12
    i = 52 + (-1 * fnum->exponent);
    print_small_range(i, fnum, fraction);
  }
  if (fnum->exponent > 63)
    big_int(fnum);
  if (fnum->exponent < -12)
    underflow_exponent(fnum, fraction, 64);
//  print_float_str(final, blksk, fnum);
}

t_float   *init_float(t_float *fnum)
{
  fnum->sign = 0;
  fnum->exponent = 0;
  fnum->mantissa = 0;
  fnum->integer = 0;
  fnum->remain = 0;
  fnum->decimal = 0;
  return (fnum);
}

int   decode_float(uint64_t *word, char *final, t_block *blksk)
{
  t_float *fnum;
  long double fraction[64];
  if (!(fnum = (t_float *)malloc(sizeof(t_float))))
    return (0);
  init_float(fnum);
  if ((blksk->modifier == 0) || (blksk->modifier == l)) // 1, 11, 52
    {
      fnum->sign = (word[0] >> 63) ? '-' : '+';
      fnum->exponent = ((word[0] << 1) >> 53) - 1023;
      fnum->mantissa = (word[0] << 12) >> 12;
      bit_power(fraction);
      compose_float_64(fnum, fraction);
    }
  else // case L, 80 bit, 1, 15, 1 (integer part), 63
    {
      fnum->exponent = ((uint16_t)word[1] & 0x7FFF) - 16383; // 2^31 - 2^16 junk values, 16 bits are 2^15 to 2^0
      fnum->sign = (word[1] & 0x8000) ? '-' : '+';
      fnum->mantissa = word[0];
      bit_power(fraction);
      compose_float_80(fnum, fraction);
    }
  print_float_str(final, blksk, fnum);
  free(fnum);
  return (1);
}
