#include "printf.h"
#include <stdlib.h>

void round_float(char *str, int carry, size_t i)
{
  if (!carry)
    return ;
  if (str[i] == '9') // i.e. carry is 1
    if (str[i - 1] == '9')
    {
      str[i] = '0';
      round_float(str, 1, i - 1);
    }
    else
    {
      str[i - 1]++;
      str[i] = '0';
    }
  else
    str[i]++;
  return ;
}

void print_float_str(char *final, t_block *blksk, t_float *fnum)
{
  char str[8192];
  int carry;
  long double tens;
  unsigned int index;
  unsigned int second_count;
  second_count = 56;
  carry = 0;
  tens = 1;
  index = 18;
  ft_bzero(str, 8192);
  if ((fnum->sign == '-') && (!(blksk->flag & 2))) // '0' flag not engaged
    str[0] = '-';
  if (((fnum->sign == '+') && (blksk->flag & 4)) && (!(blksk->flag & 2))) // '+' flag, positive number and '0' flag not engaged
    str[0] = '+';
  if (blksk->precision == 0)
    fnum->integer = ((int)(fnum->decimal * 10) >= 5) ? fnum->integer + 1 : fnum->integer;
  if (!(*(fnum->big_str)))
  {
    while (fnum->integer / 10)
      {
        ft_strcat_char(str, fnum->integer % 10 + '0');
        fnum->integer = fnum->integer / 10;
      }
      ft_strcat_char(str, fnum->integer + '0'); // this is the case where rounding to precision 0 is dealt with
  }
  else
    ft_strcat(str, fnum->big_str);
  if (!(*(fnum->big_str)))
  {
    if (( str[0] == '-') || (str[0] == '+'))
      ft_strrev(&str[1]);
      else
      ft_strrev(str);
  }
  if ((blksk->flag & 16) || (blksk->precision)) // '#' is on or precision is non-zero
    ft_strcat_char(group_digit(str, blksk), '.');
  if (blksk->precision > 0)
  {
    while (second_count)
    {
      while (index)
      {
        tens = tens * ((long double)10);
        index--;
      }
      printf("tens is %Lf\n",tens);
      fnum->decimal *= tens;
      printf("fnum->decimal is %.400Lf\n", fnum->decimal);
      tens = 1;
      index = 18;
      second_count--;
    }

    while (blksk->precision > 0)
    {
      ft_strcat_char(str,(int)(fnum->decimal * 10) + '0');
      fnum->decimal = fnum->decimal * 10 - (int)(fnum->decimal * 10);
    //  printf("fnum->decimal is %.400Lf\n", fnum->decimal);
      blksk->precision--;
    }

    carry = ((int)(fnum->decimal * 10) >= 5) ? 1 : 0;
    round_float(str, carry, ft_strlen(str) - 1);
  }
  carry = blksk->width - ft_strlen(str);
  if (((blksk->flag & 32) && (!(blksk->flag & 4))) && (!(blksk->flag & 8)) &&
      (!((fnum->sign == '-') && (blksk->flag & 2)))) // space flag
    ft_strcat_char(final, ' ');
  if (((blksk->flag & 32) && (fnum->sign == '+')) && (blksk->flag & 8)) // space flag
    ft_strcat_char(final, ' ');
  if ((fnum->sign == '-') && (blksk->flag & 2)) // '0' flag and negative digit
      ft_strcat_char(final, '-');
  if (((fnum->sign == '+') && (blksk->flag & 4)) && (blksk->flag & 2)) // '+' flag, positive number and '0' flag present
      ft_strcat_char(final, '+');
  if (blksk->width > ft_strlen(str))
  {
      if (blksk->flag & 8)// '-' flag , 0 ignored
      {
      carry = ((blksk->flag & 32) && (fnum->sign == '+')) ? carry - 1 : carry;
        while (carry--)
          ft_strcat_char(str, ' ');
      }
      if ((blksk->flag & 2) &&  (!(blksk->flag & 8))) // zero flag without '-'
      {
        carry = ((fnum->sign == '-') || (blksk->flag & 4) || (blksk->flag & 32))  ? carry - 1 : carry; // presence of sign reduce 1 zero
        while (carry--)
          ft_strcat_char(final, '0');
      }
      if ((!(blksk->flag & 2)) &&  (!(blksk->flag & 8))) // no '-' or zero flag
      {
        carry = (blksk->flag & 32) ? carry - 1 : carry; // space flag is absorbed in width
        while (carry--)
          ft_strcat_char(final, ' ');
      }
  }
  ft_strcat(final, str);
}
