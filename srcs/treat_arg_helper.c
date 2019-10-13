#include "printf.h"
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

void nul_str_with_precision(char *str, int j, t_block *blksk)
{
  ft_strcat(str, "(null)");
  j = ft_strlen(str);
  while (j > blksk->precision)
    str[--j] = '\0';
}

void treat_string_helper(char *str, char *string, t_block *blksk)
{
  int j;
  int i;

  j = 0;
  i = 0;
  if (blksk->precision > 0)
  {
    j = (string == NULL) ? 6 : ft_strlen(string);
    if (blksk->precision > j)
      blksk->precision = j;
    if (string == NULL)
      nul_str_with_precision(str, j, blksk);
    else
      while ( i < blksk->precision)
        ft_strcat_char(str, string[i++]);
  }
  else
  {
    if ((string == NULL) && (!(blksk->flag & 128)))
      ft_strcat(str, "(null)");
    else
      if (!(blksk->flag & 128))
        ft_strcat(str, string);
  }
}

void mod_string_flag(char *str, t_block *blksk)
{
  if (blksk->flag & 8)
  {
    blksk->width -= ft_strlen(str);
    if (blksk->width > 0)
      while (blksk->width--)
        ft_strcat_char(str, ' ');
  }
  if ((blksk->flag & 2) && (!(blksk->flag & 8)) && ((size_t)blksk->width > ft_strlen(str)))
  {
    blksk->width -= ft_strlen(str);
    if (blksk->width > 0)
      while (--blksk->width)
        ft_strpcat_char(str, '0');
  }
  if ((!(blksk->flag & 8)) && ((size_t)blksk->width > ft_strlen(str)))
  {
    blksk->width -= ft_strlen(str);
    if (blksk->width > 0)
      while (blksk->width--)
        ft_strpcat_char(str, ' ');
  }
}

void mod_string_size(va_list ap, t_block *blksk)
{
  if (blksk->precision == -2)
    blksk->precision = 0;
  if (blksk->precision == -1)
    blksk->precision = va_arg(ap, int);
  if (blksk->precision < 0)
    blksk->precision = 0;
}

int    treat_string(char *final, va_list ap, t_block *blksk)
{
  char *string;
  char *str;

  mod_string_size(ap, blksk);
  if (blksk->precision + blksk->width  > 2048)
    str = ft_strnew(blksk->precision + blksk->width);
  else
    str = ft_strnew(2048);
  if (str == NULL)
    return (-1);
  string = va_arg(ap, char *);
  treat_string_helper(str, string, blksk);
  mod_string_flag(str, blksk);
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
