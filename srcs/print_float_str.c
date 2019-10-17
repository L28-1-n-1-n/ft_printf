#include "printf.h"
#include <stdlib.h>


size_t round_f_helper(char *str, size_t i)
{
  ft_memmove(&str[1], &str[0], ft_strlen(&str[0]));
  str[0] = '0';
  i += 1;
  return (i);
}

void round_float(char *str, int carry, size_t i)
{
  if (!carry)
    return ;
    if ((str[i] == '9') && (i == 0))
      i = round_f_helper(str, i);
  if (str[i] == '9') // i.e. carry is 1
  {
    if (str[i - 1] == '9')
    {
      str[i] = '0';
      round_float(str, 1, i - 1);
    }
    else  if (str[i - 1] == '.')
    {
      str[i] = '0';
      round_float(str, 1, i - 2);
    }
    else
    {
      str[i - 1]++;
      str[i] = '0';
    }
  }
  else
    str[i]++;
  return ;
}


void non_big_str(char *str, t_block *blksk, t_float *fnum)
{
  if (!(*(fnum->big_str)))
  {
    while (fnum->integer / 10)
      {
        ft_strcat_char(str, fnum->integer % 10 + '0');
        fnum->integer = fnum->integer / 10;
      }
      ft_strcat_char(str, fnum->integer + '0'); // this is the case where rounding to precision 0 is dealt with, or if integer is less than 10 to begin with
    if (( str[0] == '-') || (str[0] == '+'))
      ft_strrev(&str[1]);
    else
      ft_strrev(str);
  }
  else
  {
    if ((fnum->exponent > 0) && (!(fnum->eflag & 4))) // case big_int and big_int only
      ft_strcat(str, fnum->big_str);
    if (fnum->exponent < 0) // sub_array and sub_array_80
      ft_strcat_char(str, fnum->integer + '0');
  }
  if (((blksk->flag & 16) || (blksk->precision)) && (!(fnum->eflag & 4))) // '#' is on or precision is non-zero
    ft_strcat_char(group_digit(str, blksk), '.');
}

void adjust_f_pres(char *str, t_block *blksk, t_float *fnum)
{
  if ((fnum->sign == '-') && (!(blksk->flag & 2))) // '0' flag not engaged
    str[0] = '-';
  if (((fnum->sign == '+') && (blksk->flag & 4)) && (!(blksk->flag & 2))) // '+' flag, positive number and '0' flag not engaged
    str[0] = '+';
  if (blksk->precision == 0)// Absolutely no need to worry about big_int or sub_array in this one, since in both cases first digit of decimal must always be zero
  {
    if  ((fnum->integer % 10) % 2)
      fnum->integer = (fnum->decimal >= 0.5) ? fnum->integer + 1 : fnum->integer;
    else
      fnum->integer = (fnum->decimal <= 0.5) ? fnum->integer  : fnum->integer + 1;
  }
}

int print_float_str(char *final, t_block *blksk, t_float *fnum)
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
  adjust_f_pres(str, blksk, fnum);
  non_big_str(str, blksk, fnum);
  return(pfstr_helper(final, str, blksk, fnum));
}
