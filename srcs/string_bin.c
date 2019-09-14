#include "printf.h"
#include <stdio.h>

char *mod_bin(char *str, t_block *blksk)
{
  int i;

  i = 0;
  i = blksk->width - ft_strlen(str);
  if ((i > 0) && (blksk->flag & 8)) // '-' flag
    while (i--)
      ft_strcat_char(str, ' ');
  if ((i > 0) && (!(blksk->flag & 8))) // '-' flag
    while (i--)
      ft_strpcat_char(str, ' ');
  if (blksk->flag & 16)
    ft_strcat_char(str, 'b');
  return (str);
}
void string_bin(intmax_t n, char *final, t_block *blksk)
{
  char str[2048];
  ft_bzero(str, 2048);
  int i;
  i = 0;
  if ((n < (long long)(0x8000000000000000)) || (n > (long long)(0x7FFFFFFFFFFFFFFF)) ||
    (blksk->modifier == L))
      return ;
  if (n == (long long)(0x8000000000000000))
  {
      ft_strcat(final, mod_bin(ft_strcat(str, "-1000000000000000000000000000000000000000000000000000000000000000"), blksk));
    return ;
  }
  if (blksk->flag & 32) // ' ' flag
  {
    ft_strcat_char(final, ' ');
    blksk->width -= 1;
  }
  if ((blksk->flag & 4) && (n > 0)) //'+' flag
  {
    ft_strcat_char(final, '+');
    blksk->width -= 1;
  }
  if (n < 0)
  {
    n = -1 * n;
    ft_strcat_char(final, '-');
    blksk->width -= 1;
  }
  if (blksk->flag & 32)
  while (n > 0)
  {
    if (n & 1)
      ft_strcat_char(str, '1');
    else
      ft_strcat_char(str, '0');
    n >>= 1;
  }
  ft_strrev(str);
  ft_strcat(final, mod_bin(str, blksk));
  (void)blksk;
}
