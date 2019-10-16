#include "printf.h"
#include <stdio.h>
#include <stdlib.h>

char *group_digit(char *str, t_block *blksk)
{
  int i;
  int count;
  int end;

  if (!(blksk->flag & 64))
    return (str);
  count = 2;
  end = 0;
  if ((str[0] == '-') || (str[0] == '+'))
    end = 1;
  i = ft_strlen(str) - 1;
  while (i > end)
  {
    if (!count)
    {
      ft_memmove(&str[i + 1], &str[i], ft_strlen(&str[i]));
      str[i] = ',';
      count = 3;
    }
    i--;
    count--;
  }
  return(str);
}

void empty_width_or_zero_start(char *str, t_block *blksk, intmax_t n)
{
  if ((n == 0) && (!(blksk->width)))
  {
    if (blksk->orig > 1)
      str[1] = '0';
    else
      if (ft_strlen(str) == 0)
        ft_strpcat_char(str, ' ');
  }
  if (str[0] == '0')
  {
    ft_strpcat_char(str, ' ');
    if (str[ft_strlen(str) - 1] == ' ')
      str[ft_strlen(str) - 1] = '\0';
  }
}

void dash_and_non_neg(char *str, t_block *blksk, int width, intmax_t n)
{
  if ((blksk->flag & 8) && (n > 0))// '-'flag and n is not negative
  {
    if ((str[0] != '+') && (str[0] != '-') && (str[0] != ' '))
    {
      ft_memmove(&str[1], &str[0], ft_strlen(str));
      str[0] = ' ';
      if (str[ft_strlen(str) - 1] == ' ')
        str[ft_strlen(str) - 1] = '\0';
    }
  }
  else
  {
    if ((!(blksk->flag & 4)) && (blksk->width == 0) && (n > 0) && (str[0] != ' '))
      {
          ft_memmove(&str[1], &str[0], ft_strlen(str));
          str[0] = ' ';
          str[ft_strlen(str)] = '\0';
      }
    else
      if (((ft_strlen(str) < (size_t)width)) || ((str[0] != ' ') && (str[0] != '+') && (str[0] != '-')))
        if (str[0] != ' ')
          ft_strpcat_char(str, ' ');
  }
}

char *digit_space(char *str,int width, t_block *blksk, intmax_t n)
{
  if (blksk->flag & 32) // ' ' flag
  {
    empty_width_or_zero_start(str, blksk, n);
    if ((str[0] == '0') && (n!= 0)) // '0' flag, but n != 0
      str[0] = ' ';
    else
      dash_and_non_neg(str, blksk, width, n);
  }
  return(str);
}

int di_nosign(char *str, int j, t_block *blksk, int i)
{
    ft_memmove(&str[j], &str[0], i);
    j -= 1;
    if ((blksk->flag & 2) && (blksk->flag & 32) && (!(blksk->flag & 128)))
    {
      while (j > 0)
        str[j--] = '0';
      str[0] = ' ';
    }
    else
    {
      if ((blksk->orig) || (blksk->flag & 128))
        while (j >= 0)
          str[j--] = ' ';
      else
        while (j >= 0)
          str[j--] = '0';
    }
  return (j);
}

int no_zero_nor_space(char *str, int j)
{
  ft_memmove(&str[j], &str[0], ft_strlen(str));// first move content of str backwards, then pad with space
  j -= 1;
  while (j >= 0)
    str[j--] = ' ';
  return (j);
}

int zero_not_space(char *str, int j, t_block *blksk, intmax_t n)
{
  if ((blksk->flag & 2) && (!(blksk->flag & 32))) //'0' & not ' '
  {
    if ((n == 0) && (blksk->orig != 0))
      while (j >= 0)
        str[j--] = ' ';
    else
      while (j >= 0)
        str[j--] = '0';
  }
  else
    while (j >= 0)
      str[j--] = ' ';
  return (j);
}

int zero_di_one(char *str, int j, t_block *blksk, intmax_t n)
{
  if ((blksk->flag & 2) && (blksk->flag & 32))
  {
    if(n != 0)
      while (j > 0)
        str[j--] = '0';
    else
    {
      if(blksk->orig)
        while (j > 0)
          str[j--] = ' ';
      else
        while (j > 0)
          str[j--] = '0';
    str[0] = ' ';
    }
  }
  else
    j = zero_not_space(str, j, blksk, n);
  return (j);
}

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

void digit_two(char *str, intmax_t n, t_block *blksk)
{
  if (n > 0)
    blksk->precision -= 1;
  if (str[0] == '-')
  {
    if (blksk->precision > 0)
    {
      ft_memmove(&str[1 + blksk->precision], &str[1], ft_strlen(&str[1]));
      while (blksk->precision--)
        str[1 + blksk->precision] = '0';
    }
  }
  else if (blksk->precision > 0)
      while (blksk->precision--)
        ft_strpcat_char(str, '0');
}

int nest(char *str, intmax_t n, t_block *blksk)
{
  if (blksk->flag & 4)
      {
        if (n > 0)
          blksk->precision -= 1;
        if (blksk->precision > 0)
        {
          ft_memmove(&str[1 + blksk->precision], &str[1], ft_strlen(&str[1]));
          while (blksk->precision--)
            str[1 + blksk->precision] = '0';
        }
      }
    else
      digit_two(str, n, blksk);
    return (ft_strlen(str));
}

int valueofi(char *str, intmax_t n, t_block *blksk)
{
  int i;

  if ((blksk->flag & 4) && (n >= 0)) // '+' flag
  {
    str[0] = '+';
    if (!((n == 0) && (blksk->flag & 128)))
      i = ft_strlen(group_digit(ft_itoamax(n, &str[1]), blksk));
    else
      i = ft_strlen(str);
  }
  else if (!((n == 0) && (blksk->flag & 128)))
      i = ft_strlen(group_digit(ft_itoamax(n, str), blksk));
      else
      i = ft_strlen(str);
  if ((blksk->precision > 0) && (i > 0))
    blksk->precision -= (i - 1);
  return (i);
}

int case_n_zero(char *str, int j, intmax_t n, t_block *blksk)
{
    if (str[0])
    {
      ft_memmove(&str[j], &str[0], ft_strlen(str));
      j -= 1;
      j = zero_di_one(str, j, blksk, n);
    }
    else
      while (j >= 1)
      {
        ft_strcat_char(str, ' ');
        j--;
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
  char str[2048];
  ft_bzero(str, 2048);
/*  if (blksk->width + blksk->precision > 2048)
    str = ft_strnew(blksk->width + blksk->precision);
  else
    str = ft_strnew(2048);*/
  if (ft_strlen(final) + ft_strlen(str) > FLEN)
    output_final(final, 0);
  ft_strcat(final, compose_digit(str, n, blksk));
//  free(str);
}
