#include "printf.h"
#include <stdio.h>

char *convert_base(uintmax_t n, char *tmp, char *base)
{
  unsigned int k;
  unsigned int i;
  unsigned int mask;
  unsigned int step;

  i = 0;
  k = 0;
  tmp[0] = '0'; // preset '0' for case n = 0
  if (ft_strlen(base) == 10) // case unsigned 0123456789 has length 10
  {
  //  printf("we are base 10\n");
    while (n > 0)
    {
    //  printf("n is %ju\n", n);
    //  printf("and n mod 10 is %ju\n", n);
      tmp[i] = base[n % 10];
    //  printf("we have put %d into tmp[%d]\n", base[n%10], i);
      n /= 10;
      i++;
    }
    return (tmp);
  }

  mask = 15;
  step = 4;
  if (ft_strlen(base) < 10) // case octal 012345678 has length 9
  {
    mask = 7;
    step = 3;
  }

  while (n > 0) // this is a logical problem, after 32 bits, will need to be
  {
    k = n & mask; // 7 for octal
    n = n >> step; // 3 for octal
    tmp[i] = base[k];
    i++;
  }
  return (tmp);
}


char *compose_snippet(char *str, char *base, uintmax_t n, t_block *blksk)
{
  char tmp[23]; // Max octal digits = 64/3
  int i;
  int j;

  ft_bzero(tmp, 23);
  if (blksk->flag & 64) // apostrophe flag
    i = ft_strlen(ft_strcat(str, group_digit(ft_strrev(convert_base(n, tmp, base)), blksk)));
  else
    i = ft_strlen(ft_strcat(str, ft_strrev(convert_base(n, tmp, base))));
  j = blksk->width - i;
  if (j > 0)
    {
      if (blksk->flag & 8) // '-' flag, trumps '0' flag
          while (j--)
            str[i++] = ' ';
      if ((blksk->flag & 2) && (!(blksk->flag & 8))) // '0' flag without '-'
      {
          // first move content of str backwards, then pad with zero between 0x and content
        if ((blksk->flag & 16) && (blksk->type != 'u')) //'#'
        {
          ft_memmove(&str[j], &str[2], i - 2);
          j -= 1;
          while (j >= 2)
            str[j--] = '0';
        }
        else
        {
          ft_memmove(&str[j], &str[0], i);
          j -= 1;
          while (j >= 0)
            str[j--] = '0';
        }
      }
      if ((!(blksk->flag & 2)) && (!(blksk->flag & 8))) // no '0' flag, no '-' flag
      {
          // first move content of str backwards, then pad with zero
        ft_memmove(&str[j], &str[0], i);
        j -= 1;
        while (j >= 0)
          str[j--] = ' ';
      }
    }
//  printf("str is %s and length is %zu\n", str, ft_strlen(str));
  return (str);
}


void string_hex(uintmax_t n, char *final, t_block *blksk)
{
  char *base;
  char str[2048];

  ft_bzero(str, 2048);

  if (blksk->type == 'X')
  {
    if ((blksk->flag & 16) && (n != 0)) // '#'
      ft_strcpy(str, "0X");
    base = "0123456789ABCDEF";
  }
  if (blksk->type == 'x')
  {
    if ((blksk->flag & 16) && (n != 0)) // '#''
      ft_strcpy(str, "0x");
    base = "0123456789abcdef";
  }
  if (blksk->type == 'o')
  {
    if ((blksk->flag & 16) && (n != 0)) // '#'
      str[0] = '0';
    base = "012345678";
  }
  if (blksk->type == 'u')
    base = "0123456789";
  ft_strcat(final, compose_snippet(str, base, n, blksk));
}
