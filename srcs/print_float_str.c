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
  char str[20000];
  int carry;
  int i;

  i = 0;
  printf("we got to print_float\n");
// SUB_ARRAY_80 WILL HAVE TO BE SPECIALLY PRINTED!!!!!!!!!
// algo for print sub_array_80 : skip fnumm->big_str until you have 4931 zeros in front of first digit, then start the non-zero parts
  carry = 0;
  ft_bzero(str, 20000);
  if ((fnum->sign == '-') && (!(blksk->flag & 2))) // '0' flag not engaged
    str[0] = '-';
  if (((fnum->sign == '+') && (blksk->flag & 4)) && (!(blksk->flag & 2))) // '+' flag, positive number and '0' flag not engaged
    str[0] = '+';
  if (blksk->precision == 0) // Absolutely no need to worry about big_int or sub_array in this one, since in both cases first digit of decimal must always be zero
    fnum->integer = ((int)(fnum->decimal * 10) >= 5) ? fnum->integer + 1 : fnum->integer;

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
      printf("in the middle, str is %s\n", str);
  }
  else
  {
    if (fnum->exponent > 0) // case big_int and big_int only
      ft_strcat(str, fnum->big_str);
    if (fnum->exponent < 0)
    ft_strcat_char(str, fnum->integer + '0');
  }
  if ((blksk->flag & 16) || (blksk->precision)) // '#' is on or precision is non-zero
    ft_strcat_char(group_digit(str, blksk), '.');
    printf("in the middle, str is %s\n", str);

  if (blksk->precision > 0)
  {
    if (*(fnum->big_str) && (fnum->exponent < 0)) // sub_array
      {
        if ((blksk->modifier == L) && (blksk->precision < 4931))
          while (blksk->precision--)
            ft_strcat_char(str,'0');
        else // include L and precision >= 4931, or ANY precision for non-L, i.e. sub_array
        {
          if (blksk->modifier == L)
          {
            i = 4931;
            while (i--)
              ft_strcat_char(str,'0');
            blksk->precision -= 4931;
          // NEED TO CHANGE BELOW: if flag == f only, precision is same as current method, if not, precision wiil make probram look for
          //corresponding index in sub_array, and (what?) of sub_array and sub_array_80 respectively?
            i = 0;

            while ((fnum->big_str[i] == '0') && (fnum->big_str[i]))
              i++;
            while ((blksk->precision > 0) && (fnum->big_str[i]))
            {
              ft_strcat_char(str,fnum->big_str[i]);
              i++;
              blksk->precision--;
            }
            printf("str is %s\n", str);
            while (blksk->precision > 0)
            {
              ft_strcat_char(str,'0');
              blksk->precision--;
            }
          }
          else // case modifier == 0 or l
           {
             i = 0;
             while ((blksk->precision > 0) && (fnum->big_str[i]))
             {
               ft_strcat_char(str, fnum->big_str[i]);
               i++;
               blksk->precision--;
             }
             while (blksk->precision > 0)
             {
               ft_strcat_char(str,'0');
               blksk->precision--;
             }
           }
        }
      }
    else
      while (blksk->precision > 0) // case normal decimals
      {
        ft_strcat_char(str,(int)(fnum->decimal * 10) + '0');
        fnum->decimal = fnum->decimal * 10 - (int)(fnum->decimal * 10);
        //  printf("fnum->decimal is %.400Lf\n", fnum->decimal);
        blksk->precision--;
      }
    if (*(fnum->big_str) && (fnum->exponent < 0))
      carry = (fnum->big_str[i] > '5') ? 1 : 0;
    else
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
      fnum->eflag |= 2; // this one particular case we need to deal with trailing zeros followed by space in g flag
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
  printf("dot is at pos %zu\n", ft_strchr_arg(str, '.'));
  ft_strcat(final, str);
}
