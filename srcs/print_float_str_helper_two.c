#include "printf.h"
#include <stdlib.h>

int pf_subarray_ld(char *str, t_block *blksk, t_float *fnum)
{
    int i;

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
    return (i);
}

int pf_subarray(char *str, t_block *blksk, t_float *fnum)
{
  int i;

  i = 0;
  if ((blksk->modifier == L) && (blksk->precision < 4931))
    while (blksk->precision--)
      ft_strcat_char(str,'0');
  else if (blksk->modifier == L) // include L and precision >= 4931, or ANY precision for non-L, i.e. sub_array
    i = pf_subarray_ld(str, blksk, fnum);
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
    return (i);
}

void treat_eflag(char *str, t_float *fnum, t_block *blksk)
{
  if (fnum->eflag & 4) // only here we add nan or inf
  {
    if (blksk->type == 'e')
        ft_strcat(str, fnum->big_str);
    else
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
  }
}

int modify_carry(char *str, t_block *blksk, t_float *fnum)
{
  int carry;
  int i;

  carry = 0;
  i = 0;
  if ((blksk->precision > 0) && (!(fnum->eflag & 4))) // not nan or inf
  {
    if (*(fnum->big_str) && (fnum->exponent < 0)) // sub_array
        i = pf_subarray(str, blksk, fnum);
    else
      while (blksk->precision > 0) // case normal decimals
      {
        ft_strcat_char(str,(int)(fnum->decimal * 10) + '0');
        fnum->decimal = fnum->decimal * 10 - (int)(fnum->decimal * 10);
        blksk->precision--;
      }
    if (*(fnum->big_str) && (fnum->exponent < 0))
      carry = (fnum->big_str[i] > '5') ? 1 : 0;
    else
      carry = ((int)(fnum->decimal * 10) >= 5) ? 1 : 0;
    round_float(str, carry, ft_strlen(str) - 1);
  }
  treat_eflag(str, fnum, blksk);
  return (carry);
}