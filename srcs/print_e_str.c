#include "printf.h"
#include <stdlib.h>

void adjust_str(char *str, t_block *blksk, int carry)
{
  if (blksk->flag & 8)// '-' flag , 0 ignored
    while (carry--)
      ft_strcat_char(str, ' ');
  if ((blksk->flag & 2) &&  (!(blksk->flag & 8))) // zero flag without '-'
    while (carry--)
    {
      if ((str[0] == '-') || (str[0] == '+'))
        ft_strpcat_char(&str[1], '0');
      else
        ft_strpcat_char(str, '0');
    }
  if ((!(blksk->flag & 2)) &&  (!(blksk->flag & 8))) // no '-' or zero flag
    while (carry--)
      ft_strpcat_char(str, ' ');
}

void move_dot(char *str, t_block *blksk)
{
  int i;
  int placeholder;

  placeholder = 0;
  i = ft_strchr_arg(str, '.'); // case 0.0000000001234
  if ((str[i - 1] > '0') && (str[i - 1] <= '9'))
    pos_exp(str, blksk, i);
  if (str[i - 1] == '0')
  {
    placeholder = i - 1;
    while ((str[placeholder]) && (str[placeholder] == '0'))
      placeholder--;
    if ((str[placeholder]) && (str[placeholder] > '0') && (str[placeholder] <= '9'))
      pos_exp(str, blksk, i);
    else
      neg_exp(str, blksk, i);
  }
}

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
  int carry;
  int i;
  int final_len;

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
  final_len = adjust_e_pres(final, str, blksk, fnum);
  i = 0;
  carry = 0;
  non_big_str(str, blksk, fnum);
  if (((blksk->flag & 16) || (blksk->precision)) && (!(fnum->eflag & 4)))// '#' is on or precision is non-zero
    ft_strcat_char(group_digit(str, blksk), '.');
  if ((blksk->precision > 0) && (!(fnum->eflag & 4)))
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
            i = 0;
            while ((fnum->big_str[i] == '0') && (fnum->big_str[i]))
              i++;
            while ((blksk->precision > 0) && (fnum->big_str[i]))
            {
              ft_strcat_char(str,fnum->big_str[i]);
              i++;
              blksk->precision--;
            }
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
      carry = ((int)(fnum->decimal * 10) > 5) ? 1 : 0;
    round_float(str, carry, ft_strlen(str) - 1);
  }
  if (fnum->eflag & 4) // only here we add nan or inf
    ft_strcat(str, fnum->big_str);
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
  if ((size_t)blksk->width > ft_strlen(str))
  {
      if (blksk->flag & 8)// '-' flag , 0 ignored
      {
      carry = ((blksk->flag & 32) && (fnum->sign == '+')) ? carry - 1 : carry;
        while (carry--)
          ft_strcat_char(str, ' ');
      fnum->eflag |= 2;
      }
      if ((blksk->flag & 2) && (!(blksk->flag & 8)) && (!(fnum->eflag & 4))) // zero flag without '-'
      {
        carry = ((fnum->sign == '-') || (blksk->flag & 4) || (blksk->flag & 32))  ? carry - 1 : carry; // presence of sign reduce 1 zero
        if (fnum->eflag == 1)
              carry -= 3;
        while (carry--)
          ft_strcat_char(final, '0');
      }
      if ((!(blksk->flag & 2)) &&  (!(blksk->flag & 8))) // no '-' or zero flag
      {
        carry = (blksk->flag & 32) ? carry - 1 : carry; // space flag is absorbed in width
        if (fnum->eflag == 1)
              carry -= 3;
        while (carry--)
          ft_strcat_char(final, ' ');
      }
  }
  blksk->precision = blksk->orig;
  if (!(fnum->eflag & 4))
  {
    move_dot(str, blksk);
    carry = blksk->width - (ft_strlen(final) - final_len + ft_strlen(str));
    if (carry > 0)
      adjust_str(str, blksk, carry);
  }

if (ft_strlen(final) + ft_strlen(str) > FLEN)
{
  output_final(final, 0);
  if (ft_strlen(str) > FLEN)
    output_final(str, 0);
  else
    ft_strcat(final, str);
}
else
  ft_strcat(final, str);
  free (str);
  return (0);
}
