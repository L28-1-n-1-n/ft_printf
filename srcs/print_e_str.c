#include "printf.h"
#include <stdlib.h>


int change_precision(long double decimal)
{
  int test_int;
  int count;

  count = 0;
  test_int = (int)(decimal * 10);
  if (test_int != 0)
    return (0);
  while (test_int == 0)
  {
    test_int = (int)(decimal * 10);
    decimal = decimal * 10 - (int)(decimal * 10);
    count++;
  }
  return (count);
}
int adjust_e_pres(char *final, char *str, t_block *blksk, t_float *fnum)
{
  int final_len;

  if (((fnum->integer == 0) && (fnum->decimal != 0)) || ((*(fnum->big_str)) && (fnum->exponent < 0)))
  {
    blksk->precision++;
    fnum->eflag |= 1;
  }
  blksk->orig = blksk->precision;
  if ((fnum->integer == 0) && (fnum->decimal != 0))
    blksk->precision += change_precision(fnum->decimal); // case 0.00000000sth
  final_len = ft_strlen(final);
  if ((fnum->sign == '-') && (!(blksk->flag & 2))) // '0' flag not engaged
    str[0] = '-';
  if (((fnum->sign == '+') && (blksk->flag & 4)) && (!(blksk->flag & 2))) // '+' flag, positive number and '0' flag not engaged
    str[0] = '+';
  if (blksk->precision == 0) // Absolutely no need to worry about big_int or sub_array in this one, since in both cases first digit of decimal must always be zero
    fnum->integer = ((int)(fnum->decimal * 10) >= 5) ? fnum->integer + 1 : fnum->integer;
  return (final_len);
}

int print_e_str(char *final, t_block *blksk, t_float *fnum)
{
  char *str;

  if (blksk->precision == -2)
    blksk->precision = 6;
  if (blksk->precision + blksk->width > FLEN)
  {
    if (!(str = ft_memalloc(blksk->precision + blksk->width )))
      return(ft_free(str, -1));
    ft_bzero(str, blksk->precision + blksk->width);
  }
  else
  {
    if (!(str = ft_memalloc(FLEN)))
      return(ft_free(str, -1));
    ft_bzero(str, FLEN);
  }
  fnum->final_len = adjust_e_pres(final, str, blksk, fnum);
  non_big_str(str, blksk, fnum);
  return (pestr_helper(final, str, blksk, fnum));
}
