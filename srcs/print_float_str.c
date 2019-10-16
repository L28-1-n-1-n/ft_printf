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

int print_float_str(char *final, t_block *blksk, t_float *fnum)
{
  char *str;
  int carry;
  int i;
  uint64_t int_copy;

  i = 0;
  int_copy = 0;

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
  carry = 0;
  if ((fnum->sign == '-') && (!(blksk->flag & 2))) // '0' flag not engaged
    str[0] = '-';
  if (((fnum->sign == '+') && (blksk->flag & 4)) && (!(blksk->flag & 2))) // '+' flag, positive number and '0' flag not engaged
    str[0] = '+';
  if (blksk->precision == 0) // Absolutely no need to worry about big_int or sub_array in this one, since in both cases first digit of decimal must always be zero
  {
    int_copy = fnum->integer % 10;
      if (int_copy % 2)
        fnum->integer = (fnum->decimal >= 0.5) ? fnum->integer + 1 : fnum->integer;
      else
        fnum->integer = (fnum->decimal <= 0.5) ? fnum->integer  : fnum->integer + 1;
  }
/*  printf("fnum->exponent is %d\n", fnum->exponent);
  printf("fnum->mantissa is %lld\n", fnum->mantissa);
  printf("fnum->integer is %llu\n", fnum->integer);
  printf("fnum->remain is %llu\n", fnum->remain);
  printf("fnum->decimal is %Lf\n", fnum->decimal);
  printf("fnum->eflag is %u\n", fnum->eflag);*/

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
  if ((blksk->precision > 0) && (!(fnum->eflag & 4))) // not nan or inf
  {
    if (*(fnum->big_str) && (fnum->exponent < 0)) // sub_array
      {
        if ((blksk->modifier == L) && (blksk->precision < 4931))
        {
          while (blksk->precision--)
            ft_strcat_char(str,'0');
        }
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
      carry = ((int)(fnum->decimal * 10) >= 5) ? 1 : 0;
    round_float(str, carry, ft_strlen(str) - 1);
  }
  if (fnum->eflag & 4) // only here we add nan or inf
  {
    if ((ft_strcmp(fnum->big_str, "nan")) && (ft_strcmp(fnum->big_str, "NAN")))
      ft_strcat(str, fnum->big_str);
    else
    {
      if (str[0] == '+')
        str[0] = '\0';
      ft_strcat(str, fnum->big_str);
    }
  }
  carry = blksk->width - ft_strlen(str);
  if (((blksk->flag & 32) && (!(blksk->flag & 4))) && (!(blksk->flag & 8)) &&
      (!((fnum->sign == '-') && (blksk->flag & 2)))) // 32 is space flag
    ft_strcat_char(final, ' ');
  if (((blksk->flag & 32) && (fnum->sign == '+')) && (blksk->flag & 8) && (!(blksk->flag & 4))) // space flag
    ft_strcat_char(final, ' ');

  if ((fnum->sign == '-') && (blksk->flag & 2)) // '0' flag and negative digit
    ft_strcat_char(final, '-');
  //  ft_strpcat_char(str, '-');

  if (((fnum->sign == '+') && (blksk->flag & 4)) && (blksk->flag & 2)) // '+' flag, positive number and '0' flag present
    ft_strcat_char(final, '+');
  //  ft_strpcat_char(str, '+');
  if ((size_t)blksk->width > ft_strlen(str))
  {

      if (blksk->flag & 8)// '-' flag , 0 ignored
      {
      carry = ((blksk->flag & 32) && (fnum->sign == '+')) ? carry - 1 : carry;
        while (carry--)
          ft_strcat_char(str, ' ');
      fnum->eflag |= 2; // this one particular case we need to deal with trailing zeros followed by space in g flag
      }
      if ((blksk->flag & 2) && (!(blksk->flag & 8)) && (!(fnum->eflag & 4))) // zero flag without '-'
      {
        carry = ((fnum->sign == '-') || (blksk->flag & 4) || (blksk->flag & 32))  ? carry - 1 : carry; // presence of sign reduce 1 zero
        while (carry--)
        //  ft_strcat_char(final, '0');
          ft_strpcat_char(str, '0');

      }
      if ((!(blksk->flag & 2)) &&  (!(blksk->flag & 8))) // no '-' or zero flag
      {
        carry = (blksk->flag & 32) ? carry - 1 : carry; // space flag is absorbed in width
        while (carry--)
      //    ft_strcat_char(final, ' ');
          ft_strpcat_char(str, ' ');

      }
  }

  int j;
  int k;
  size_t m;


  m = 0;
  k = 0;

  if (ft_strchr_pos(str, '-') > 0)
    m = (size_t)(blksk->width);
  else
  {
    if (blksk->width == 0)
      m = 0;
    else
      m = (size_t)(blksk->width - 1);
  }
    j = ft_strlen(final);
    if (blksk->flag & 32)
      if ((blksk->flag & 32) && (fnum->sign == '-') && (ft_strlen(str) > m))
      {
        if (final[j - 1] == ' ')
          final[j - 1] = '\0';
        else
          if ((final[j - 1] == '-') && (final[j - 2] == ' '))
          {
            final[j - 1] = '\0';
            final[j - 2] = '-';
          }
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
  free(str);
  return (0);
}
