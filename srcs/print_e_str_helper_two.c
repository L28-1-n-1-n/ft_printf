#include "printf.h"
#include <stdlib.h>

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



void treat_extra_e_space(char *final, t_block *blksk, t_float *fnum, int carry)
{
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

int pestr_helper_two(char *final, char *str)
{
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

int pestr_helper(char *final, char *str, t_block *blksk, t_float *fnum)
{
  int carry;
  int i;

  carry = 0;
  i = 0;
  carry = modify_carry(str, blksk, fnum);
  carry = blksk->width - ft_strlen(str);
  mod_final(final, blksk, fnum);
  if ((size_t)blksk->width > ft_strlen(str))
  {
      treat_extra_space(str, blksk, fnum, carry);
      treat_extra_e_space(final, blksk, fnum, carry);
  }
  blksk->precision = blksk->orig;
  if (!(fnum->eflag & 4))
  {
    move_dot(str, blksk);
    carry = blksk->width - (ft_strlen(final) - fnum->final_len + ft_strlen(str));
    if (carry > 0)
      adjust_str(str, blksk, carry);
  }
return (pestr_helper_two(final, str));
}
