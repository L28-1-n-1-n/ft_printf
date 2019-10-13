#include "printf.h"
#include <stdio.h>

int help_one(char *str, t_block *blksk)
{
  if ((blksk->type == 'x') || (blksk->type == 'X'))
  {
      blksk->precision = blksk->precision - (ft_strlen(str) - 2);
      if(blksk->precision > 0)
      {
        ft_memmove(&str[2 + blksk->precision], &str[2], ft_strlen(&str[2]));
        while (blksk->precision--)
          str[2 + blksk->precision] = '0';
      }
  }
  if (blksk->type == 'o')
  {
    blksk->precision = blksk->precision - (ft_strlen(str) - 1);
    if(blksk->precision > 0)
    {
      blksk->precision -= 1;
      ft_memmove(&str[1+blksk->precision], &str[1], ft_strlen(&str[1]));
      while (blksk->precision--)
        str[1 + blksk->precision] = '0';
    }
  }
  return ((int)ft_strlen(str));
}

int help_two(char *str, t_block *blksk)
{
  blksk->precision = blksk->precision - ft_strlen(str);
  if(blksk->precision > 0)
    while (blksk->precision--)
      ft_strpcat_char(str, '0');
  return((int)ft_strlen(str));
}

int help_three(char *str, t_block *blksk, int i, int j)
{
  if (!(blksk->flag & 128))
  {
    ft_memmove(&str[j + 2], &str[2], i - 2);
    j += 1;
    while (j >= 2)
      str[j--] = '0';
  }
  else
  {
    ft_memmove(&str[j], &str[0], ft_strlen(str));
    j-=1;
    while (j >= 0)
      str[j--] = ' ';
  }
  return (j);
}

int help_four(char *str, t_block *blksk, int j)
{
  if (!(blksk->flag & 128))
  {
  ft_memmove(&str[j+1], &str[1], ft_strlen(&str[1]));
  while (j >= 1)
    str[j--] = '0';
  }
  else
  {
    ft_memmove(&str[j], &str[0], ft_strlen(&str[0]));
    j-=1;
    while (j >= 0)
      str[j--] = ' ';
  }
  return (j);
}

void nest_one(char *str, t_block *blksk, int i, int j)
{
  if ((blksk->type == 'x') || (blksk->type == 'X'))
    j = help_three(str, blksk, i, j);
  if (blksk->type == 'o')
    j = help_four(str, blksk, j);
}
