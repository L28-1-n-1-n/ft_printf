#include "printf.h"
#include <stdio.h>
#include <stdlib.h>

char *group_digit(char *str, t_block *blksk)
{
  int i;
  int count;
  int end;

  if (!(blksk->flag & 64)) // if not apostrophe
    return (str);
  count = 2;
  end = 0; // case '+'
  if (str[0] == '-')
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

char *compose_digit(char *str, intmax_t n, t_block *blksk)
{
  char *tmp;
  int i;
  int j;
printf("n is %jd\n", n);

  if ((blksk->flag & 4) && (n >= 0)) // '+' flag
  {
    str[0] = '+';
    tmp = group_digit(ft_itoamax(n, &str[1]), blksk);
    i = ft_strlen(str);

  }
  else
    i = ft_strlen(group_digit(ft_itoamax(n, str), blksk));

  j = blksk->width - i;
  if (j > 0)
    {
      if (blksk->flag & 8) // '-' flag, trumps '0' flag
          while (j--)
            str[i++] = ' ';
      if ((blksk->flag & 2) && (!(blksk->flag & 8))) // '0' flag without '-'
      {
          // first move content of str backwards, then pad with zero between 0x and content
        if ((blksk->flag & 4) || (str[0] == '-'))// + or -
        {
          ft_memmove(&str[j+1], &str[1], i - 1);
          while (j >= 1)
            str[j--] = '0';
        }
        else //no sign needed
        {
          ft_memmove(&str[j], &str[0], i);
          j -= 1;
          while (j >= 0)
            str[j--] = '0';
        }
      }
      if ((!(blksk->flag & 2)) && (!(blksk->flag & 8))) // no '0' flag, no '-' flag
      {
        ft_memmove(&str[j], &str[0], i);// first move content of str backwards, then pad with space
        j -= 1;
        while (j >= 0)
          str[j--] = ' ';
      }
    }
    if (blksk->flag & 32) // ' ' flag
    {
      if ((n == 0) && (!(blksk->width)))
        str[1] = '0';
      if (str[0] == '0') // '0' flag, but n != 0
        str[0] = ' ';
      else
      {
        if ((blksk->flag & 8) && (n > 0))// '-'flag and n is not negative
        {
          ft_memmove(&str[1], &str[0], ft_strlen(str));
          str[0] = ' ';
          str[ft_strlen(str) - 1] = '\0';
        }
        else
          if ((!(blksk->flag & 4)) && (blksk->width == 0) && (n > 0))//just ' 'flag and no '+' flag, and n is positive, and width = 0
            {
              ft_memmove(&str[1], &str[0], ft_strlen(str));
              str[0] = ' ';
              str[ft_strlen(str)] = '\0';
            }
      }
    }
  printf("str is %s and length is %zu\n", str, ft_strlen(str));
  return (str);
}


void string_digit(intmax_t n, char *final, t_block *blksk)
{
  char str[2048];

  ft_bzero(str, 2048);
  ft_strcat(final, compose_digit(str, n, blksk));
  printf("str is %s\n", str);
}
