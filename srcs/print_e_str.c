#include "printf.h"
#include <stdlib.h>
void adjust_str(char *str, t_block *blksk, int carry, t_float *fnum)
{
printf("we got this far\n");
printf("str is %s\n", str);
(void)fnum;
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
      printf("str is during loop %s\n", str);
    }
  if ((!(blksk->flag & 2)) &&  (!(blksk->flag & 8))) // no '-' or zero flag
    while (carry--)
      ft_strpcat_char(str, ' ');
  printf("str is %s\n", str);
}

void round_e_float(char *str, int carry, size_t i)
{
  if (!carry)
    return ;
  if (str[i] == '9') // i.e. carry is 1
    if (str[i - 1] == '9')
    {
      str[i] = '0';
      round_e_float(str, 1, i - 1);
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

void pos_exp(char *str, t_block *blksk, int i)
{
  int tens;
  char digits[10];
  int carry;
  //int placeholder;
  printf("i is %d\n",i);
  ft_bzero(digits, 10);
  tens = 1;
  while ((str[i - tens]) && (str[i - tens] >= '0') && (str[i - tens] <= '9'))
    tens++;
  tens -= 2;
  printf("tens is %d\n",tens);
  ft_memmove(&str[i], &str[i + 1], ft_strlen(&str[i + 1]));
  ft_memmove(&str[i - tens + 1], &str[i - tens], ft_strlen(&str[i - tens]));
  i = i - tens;
  str[i] = '.';
  carry = (str[i + blksk->precision + 1] > '5') ? 1 : 0;
  round_e_float(str, carry, i + blksk->precision);
  printf("str is first %s\n", str);
  printf("i + blksk->precision is first %d\n", i + blksk->precision);
  str[i + blksk->precision + 1] = '\0';

  if (blksk->type == 'e')
    ft_strcat(str, "e+");
  else
    ft_strcat(str, "E+");
  if (tens < 10)
    ft_strcat(str, "0");
  while (tens / 10)
  {
    ft_strcat_char(digits, (tens % 10 + '0'));
    tens /= 10;
  }
  ft_strcat_char(digits, (tens + '0'));
  ft_strcat(str, ft_strrev(digits));
  printf("digits is %s\n", digits);
  printf("str after cat digits is %s\n", str);
  ft_strcat_char(str, '\0');
  tens = ft_strlen(str);
  while(tens < 20000)
  {
    str[tens] = '\0';
    tens++;
  }
  printf("tens has been augmented to %d\n", tens);
}

void neg_exp(char *str, t_block *blksk, int i)
{
  int tens;
  char digits[10];
  int placeholder;
  int carry;

  ft_bzero(digits, 10);
  tens = 1;
  while (str[i + tens] == '0')
    tens++;
  ft_memmove(&str[i], &str[i + 1], ft_strlen(&str[i + 1]));
  ft_memmove(&str[i + tens + 1], &str[i + tens], ft_strlen(&str[i + tens]));
  i = i + tens;
  str[i] = '.';
  printf("before rounding, str is %s\n", str);
  carry = (str[i + blksk->precision + 1] > '5') ? 1 : 0;
  round_e_float(str, carry, i + blksk->precision);
  str[i + blksk->precision] = '\0';

  if (blksk->type == 'e')
    ft_strcat(str, "e-");
  else
    ft_strcat(str, "E-");
  if (tens < 10)
    ft_strcat(str, "0");
  while (tens / 10)
  {
    ft_strcat_char(digits, (tens % 10 + '0'));
    tens /= 10;
  }
  ft_strcat_char(digits, (tens + '0'));
  ft_strcat(str, ft_strrev(digits));
  tens = 0;
  while (str[tens] != '0')
    tens++;
  placeholder = tens + ft_strlen(&str[i - 1]);
  ft_memmove(&str[tens], &str[i - 1], ft_strlen(&str[i - 1]));
  str[placeholder] = '\0';
  tens = ft_strlen(str);
  while(tens < 20000)
  {
    str[tens] = '\0';
    tens++;
  }
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
  printf("str is now %s\n", str);
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
void print_e_str(char *final, t_block *blksk, t_float *fnum)
{
  char str[20000];
  int carry;
  int i;
  int pres_holder;
  int final_len;

  if (((fnum->integer == 0) && (fnum->decimal != 0)) || ((*(fnum->big_str)) && (fnum->exponent < 0)))
  {
    blksk->precision++;
    fnum->eflag |= 1;
  }
  pres_holder = blksk->precision;
  if ((fnum->integer == 0) && (fnum->decimal != 0))
    blksk->precision += change_precision(fnum->decimal); // case 0.00000000sth
  final_len = ft_strlen(final);
  i = 0;
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
  }
  else
  {
    if ((fnum->exponent > 0) && (!(fnum->eflag & 4)))// case big_int and big_int only
      ft_strcat(str, fnum->big_str);
    if (fnum->exponent < 0)
    ft_strcat_char(str, fnum->integer + '0');
  }
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
      carry = ((int)(fnum->decimal * 10) > 5) ? 1 : 0;
    round_e_float(str, carry, ft_strlen(str) - 1);
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
  if (blksk->width > ft_strlen(str))
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
  blksk->precision = pres_holder;
  if (!(fnum->eflag & 4))
  {
    move_dot(str, blksk);
    carry = blksk->width - (ft_strlen(final) - final_len + ft_strlen(str));
    if (carry > 0)
      adjust_str(str, blksk, carry, fnum);
  }
  ft_strcat(final, str);
}
