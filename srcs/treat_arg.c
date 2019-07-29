#include "printf.h"
#include <stdio.h>
void    treat_char(char *final, va_list ap)
{
  char str[2];

  ft_bzero(str, 2);
  str[0] = va_arg(ap, int);
  ft_strcat(final, str);
}

void    treat_string(char *final, va_list ap)
{
  char *string;

  string = va_arg(ap, char *);
  ft_strcat(final, string);
}

void    treat_arg(char *final, va_list ap, t_block *blksk)
{
  if (blksk->str)
    if (blksk->str[0] == '%')
      ft_strcat(final, "%");

  if (blksk->type == 'c')
    treat_char(final, ap);
  if (blksk->type == 's')
    treat_string(final, ap);
  if (blksk->type == 'd')
    treat_string(final, ap);
}
