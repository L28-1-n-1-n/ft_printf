#include "printf.h"
#include <stdlib.h>

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
  i = 1;
  test = 1;
  while (i < 65)
  {
    test = test * ((long double)5);
    i++;
  }
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

void choose_bit_length(uint64_t *word, t_float *fnum, t_block *blksk, long double *fraction)
{
  if ((blksk->modifier == 0) || (blksk->modifier == l)) // 1, 11, 52
    {
      fnum->sign = (word[0] >> 63) ? '-' : '+';
      fnum->exponent = ((word[0] << 1) >> 53) - 1023;
      fnum->mantissa = (word[0] << 12) >> 12;
      if (!(float_special(fnum, 64, blksk->type)))
        compose_float_64(fnum, fraction);
    }
  else // case L, 80 bit, 1, 15, 1 (integer part), 63
    {
      fnum->exponent = ((uint16_t)word[1] & 0x7FFF) - 16383; // 2^31 - 2^16 junk values, 16 bits are 2^15 to 2^0
      fnum->sign = (word[1] & 0x8000) ? '-' : '+';
      fnum->mantissa = word[0];
      if (!(float_special(fnum, 80, blksk->type)))
        compose_float_80(fnum, fraction);
    }
}

int   decode_float(uint64_t *word, char *final, t_block *blksk)
{
  t_float *fnum;
  long double fraction[64];
  int return_value;

  return_value = 0;
  if (!(fnum = (t_float *)malloc(sizeof(t_float))))
    ft_free(fnum, -1);
  init_float(fnum);
  bit_power(fraction);
  choose_bit_length(word, fnum, blksk, fraction);
  if ((blksk->type == 'f') || (blksk->type == 'F'))
    return_value = print_float_str(final, blksk, fnum);
  else
  {
    if ((blksk->type == 'e') || (blksk->type == 'E'))
      return_value = print_e_str(final, blksk, fnum);
    else if (fnum->eflag & 4)
    {
      blksk->type = (blksk->type == 'g') ? 'g' : 'G';
      return_value = print_float_str(final, blksk, fnum);
    }
    else
      return_value = print_g_str(final, blksk, fnum);
  }
  return (ft_free(fnum, return_value));
}
