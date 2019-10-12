#include "printf.h"
#include <stdlib.h>

void underflow_exponent(t_float *fnum, long double *fraction, unsigned int bit_value)
{
  int i;
  long double tmp_decimal;
  unsigned int array[64];
    if (fnum->exponent == -1023)
    {
      fnum->remain = fnum->mantissa;
      fnum->exponent += 1;
      sub_array(fnum);
      return ;
    }
    if (fnum->exponent == -16383)
    {
      fnum->remain = ((uint64_t)(fnum->mantissa << 1)) >> 1;
      fnum->exponent += 1;
      sub_array_80(fnum);
      return ;
    }
  // if not subnormal:
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
}

void bit_power(long double *fraction)
{
  unsigned int i;
  unsigned int previous;
  long double test;
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
  //print the whole array
  /*
  i = 0;
  while (i < 64)
  {
    printf("fraction[%d] is %.70Lf\n", i, ((long double)1)/ fraction[i]);
    i++;
  }*/
  i = 1;
  test = 1;
  while (i < 65)
  {
    test = test * ((long double)5);
    i++;
  }
//This is to print each decimal number by division
/*  test = (((long double) 1 )/ fraction[63]) + (((long double) 1 )/ fraction[1]) ;
  printf("test is %.100Lf\n", test);
  final = (int)(test * 10);
  printf("final is %d\n", final);*/
}


void  print_small_range(unsigned int i, t_float *fnum, long double *fraction)
{
  while (i > 0)
  {
    if (fnum->remain & 1)
      fnum->decimal += (((long double)1)/ fraction[i]);
    fnum->remain >>= 1;
    i--;
  }
  long double test_deci;
  int test_int;
  i = 0;
  test_deci = fnum->decimal;
  while (i < 30)
  {
    test_int = (int)(test_deci * 10);
//    printf("integer=%d\n", test_int);
    test_deci = test_deci - (int)(test_deci * 10);
//    printf("decimal=%Lf\n", test_deci);
    i++;
  }
}

void   compose_float_80(t_float *fnum, long double *fraction)
{
  unsigned int i;
  printf("we are here\n");

  i = 63 - fnum->exponent;
  if ((fnum->exponent > 0) && (fnum->exponent < 65)) // i.e. <= 52, 1 is added on left most, but shift '.' starts from after this 1
  {
    fnum->decimal = 0;
    fnum->integer = (uint64_t)fnum->mantissa >> i;
    fnum->remain = (uint64_t)(fnum->mantissa << (1 + fnum->exponent)) >> (1 + fnum->exponent);
    print_small_range(i, fnum, fraction);
  }
  if (fnum->exponent > 64)
    big_int_80(fnum);
  if (fnum->exponent < 0)
    underflow_exponent(fnum, fraction, 80); // needs testing
//  print_float_str(final, blksk, fnum);
}



void   compose_float_64(t_float *fnum, long double *fraction)
{
  unsigned int i;
  printf("we are here64\n");


  fnum->decimal = 0;
  if ((fnum->exponent > 0) && (fnum->exponent < 53)) // i.e. <= 52, 1 is added on left most, but shift '.' starts from after this 1
  {
    i = 52 - fnum->exponent; // this is actually 64 - f.e - 1 to take into account that first bit is given to integer 1, if exp is 8, we need to shift 9 bits
    fnum->integer = (0x10000000000000 + fnum->mantissa) >> i; // 1 is manually added superior of the most significant bit as 1 is implied in 64 bit float, but not in 80 bit float
    fnum->remain = (fnum->mantissa << (12 + fnum->exponent)) >> (12 + fnum->exponent);
    print_small_range(i, fnum, fraction);
  }
  printf("we are here642\n");

  if ((fnum->exponent >= 53) && (fnum->exponent <= 63)) // i.e.total bits is 64, including the 1 we forcefully add in front
  {
    i = 0;
    fnum->integer = (0x10000000000000 + fnum->mantissa) << (fnum->exponent - 52); // tested correct
    fnum->remain = 0;
    print_small_range(i, fnum, fraction);
  }
  printf("we are here63\n");

  if ((fnum->exponent >= -12) && (fnum->exponent < 0))
  {
    fnum->integer = 0;
    fnum->remain = (0x10000000000000 + fnum->mantissa); // tested and only work when exponent is between -1 and -12
    i = 52 + (-1 * fnum->exponent);
    print_small_range(i, fnum, fraction);
  }
  printf("we are here64\n");

  if (fnum->exponent > 63)
    big_int(fnum);
    printf("we are here65\n");

  if (fnum->exponent < -12)
    underflow_exponent(fnum, fraction, 64);
    printf("we are here65\n");

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
  fnum->eflag = 0;
  ft_strcpy(fnum->big_str, "\0");
  return (fnum);
}

int   decode_float(uint64_t *word, char *final, t_block *blksk)
{
  t_float *fnum;
  long double fraction[64];
  if (!(fnum = (t_float *)malloc(sizeof(t_float))))
    return (0);
    printf("yoyo\n");

  init_float(fnum);
  bit_power(fraction);
      printf("yoyo\n");
  if ((blksk->modifier == 0) || (blksk->modifier == l)) // 1, 11, 52
    {
          printf("yoyo\n");
      fnum->sign = (word[0] >> 63) ? '-' : '+';
      fnum->exponent = ((word[0] << 1) >> 53) - 1023;
      fnum->mantissa = (word[0] << 12) >> 12;
//      printf("fnum->sign is %c\n", fnum->sign);
  //    printf("fnum->exponent is %hd\n", fnum->exponent);
  //    printf("fnum->mantissa is %llu\n", fnum->mantissa);
  printf("pouf\n");
      if (!(float_special(fnum, 64, blksk->type)))
        compose_float_64(fnum, fraction);
    }
  else // case L, 80 bit, 1, 15, 1 (integer part), 63
    {
          printf("yoyo1\n");
      fnum->exponent = ((uint16_t)word[1] & 0x7FFF) - 16383; // 2^31 - 2^16 junk values, 16 bits are 2^15 to 2^0
      printf("yoyo2\n");

      fnum->sign = (word[1] & 0x8000) ? '-' : '+';
      printf("yoyo3\n");
      fnum->mantissa = word[0];
      printf("haha\n");

      if (!(float_special(fnum, 80, blksk->type)))
        compose_float_80(fnum, fraction);
    }
    printf("yoyo\n");
  if ((blksk->type == 'f') || (blksk->type == 'F'))
    print_float_str(final, blksk, fnum);
  else
  {
    if ((blksk->type == 'e') || (blksk->type == 'E'))
      print_e_str(final, blksk, fnum);
    else // 'g' flag
    {
      if (fnum->eflag & 4)
      {
        blksk->type = (blksk->type == 'g') ? 'g' : 'G';
        print_float_str(final, blksk, fnum);
      }
      else
        print_g_str(final, blksk, fnum);
    }
  }
  free(fnum);
  return (1);
}
