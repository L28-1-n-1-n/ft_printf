#include "printf.h"
#include <stdio.h>
#include <stdlib.h>

int di_two(char *str, int j, t_block *blksk, intmax_t n)
{
  if ((blksk->flag & 4) && (blksk->flag & 2) && !(blksk->flag & 128))
  {
    ft_memmove(&str[j+1], &str[1], ft_strlen(str));
    if ((n != 0) || (blksk->orig == 0))
      while (j >= 1)
        str[j--] = '0';
  }
  ft_memmove(&str[j], &str[0], ft_strlen(str));
  j-=1;
  while (j >= 0)
    str[j--] = ' ';
  return (j);
}

int di_one(char *str, int j, t_block *blksk)
{
  if (((blksk->flag & 4) || (str[0] == '-')) && (blksk->flag & 2) && (!(blksk->flag & 128)))
  {
    ft_memmove(&str[j+1], &str[1], ft_strlen(str));
    while (j >= 1)
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

char *compose_digit(char *str, intmax_t n, t_block *blksk)
{
  int i;
  int j;
  int width;

  width = blksk->width;
  i = valueofi(str, n, blksk);
  i = nest(str, n, blksk);
  j = blksk->width - i;
  if (j > 0)
    {
      if (blksk->flag & 8) // '-' flag, trumps '0' flag
          while (j--)
            str[i++] = ' ';
      if ((blksk->flag & 2) && (!(blksk->flag & 8))) // '0' flag without '-'
      {
        if ((blksk->flag & 4) || (str[0] == '-'))// + or -
          j = (n == 0) ? di_two(str, j, blksk, n) : di_one(str, j, blksk);
        else //no sign needed
         j = (n == 0) ? case_n_zero(str, j, n, blksk) : di_nosign(str, j, blksk, i);
      }
      j = blksk->width - ft_strlen(str);
      if ((!(blksk->flag & 2)) && (!(blksk->flag & 8))) // no '0' flag, no '-' flag
        no_zero_nor_space(str, j);
    }
    return (digit_space(str, width, blksk, n));
}


void string_digit(intmax_t n, char *final, t_block *blksk)
{
 // char str[2048];
  //ft_bzero(str, 2048);
  char *str;
  if (blksk->width + blksk->precision > 2048)
    str = ft_strnew(blksk->width + blksk->precision);
  else
    str = ft_strnew(2048);
  if (str == NULL)
  {
    ft_free(str, -1);
    return ;
  }
  //if (ft_strlen(final) + ft_strlen(str) > FLEN)
    //output_final(final, 0);
  compose_digit(str, n, blksk);
  check_buff(final, str, ft_strlen(str));
  //ft_strcat(final, compose_digit(str, n, blksk));
  free(str);
}
