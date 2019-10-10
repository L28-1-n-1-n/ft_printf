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
    while (n > 0)
    {
      tmp[i] = base[n % 10];
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


char *compose_snippet(char *str, char *base, uintmax_t n, t_block *blksk, const char *fmt)
{
  char tmp[23]; // Max octal digits = 64/3
  int i;
  int j;
  if (blksk->precision == -2)
    blksk->precision = 0;
  ft_bzero(tmp, 23);
  if ((n == 0) && ((blksk->type == 'x') || (blksk->type == 'X')))
  {
    fmt += 1;
    while (*fmt && !(ft_strchr(".xX%", *fmt)))
      fmt++;
    //if (*fmt == '.')
  //  {
      fmt++;
      blksk->precision = ft_atoi(fmt);
  //  }
    if (!(blksk->flag & 128))
      ft_strcat_char(str, '0');

    while (blksk->precision--)
      ft_strcat_char(str, '0');
  //  if (!(blksk->flag & 2))
  //  {
      while (blksk->width--)
        ft_strcat_char(str, ' ');
    //}
  //  else
  //  {
      while (blksk->width--)
        ft_strpcat_char(str, '0');
  //  }
    return(str);
  }
  if (blksk->precision == 0)
  {
    fmt += 1;
    while (*fmt && !(ft_strchr(".xXuo%", *fmt)))
      fmt++;
    fmt++;
    blksk->precision = ft_atoi(fmt);
  }

  if (blksk->type == 'p') // to skip all flags for pointer
    return (ft_strcat(str, group_digit(ft_strrev(convert_base(n, tmp, base)), blksk)));
  if (blksk->flag & 64) // apostrophe flag
    ft_strcat(str, group_digit(ft_strrev(convert_base(n, tmp, base)), blksk));
  else
    ft_strcat(str, ft_strrev(convert_base(n, tmp, base)));
    if ((n == 0) && (blksk->flag & 128) && (!(blksk->flag & 16)))
      str[0] = '\0';
  if (blksk->flag & 16)
  {
    if ((blksk->type == 'x') || (blksk->type == 'X'))
    {
      blksk->precision = blksk->precision - (ft_strlen(str) - 2);
      if(blksk->precision > 0)
      {
        blksk->precision -= 2;
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
  }
  else
  {
    blksk->precision = blksk->precision - ft_strlen(str);
    if(blksk->precision > 0)
      while (blksk->precision--)
        ft_strpcat_char(str, '0');
  }
  i = ft_strlen(str);
  j = blksk->width - i;
  if (j > 0)
    {
      if (blksk->flag & 8) // '-' flag, trumps '0' flag
      {
          while (j--)
            str[i++] = ' ';
        }
      if ((blksk->flag & 2) && (!(blksk->flag & 8))) // '0' flag without '-'
      {
          // first move content of str backwards, then pad with zero between 0x and content
        if ((blksk->flag & 16) && (blksk->type != 'u')) //'#'
        {
          if ((blksk->type == 'x') || (blksk->type == 'X'))
          {
            ft_memmove(&str[j + 2], &str[2], i - 2);
            j += 1;
            while (j >= 2)
              str[j--] = '0';
          }
          if (blksk->type == 'o')
          {
        //    ft_memmove(&str[j+1], &str[1], ft_strlen(&str[1]));
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
          }
        }
        else
        {
          if (n != 0)
          {
            ft_memmove(&str[j], &str[0], i);
            j -= 1;
            if (!(blksk->flag & 128))
            {
              while (j >= 0)
                str[j--] = '0';
            }
            else
            {
              while (j >= 0)
                str[j--] = ' ';
            }
          }
          else
          {
            if (!(blksk->flag & 128))
              while (j >= 0)
                str[j--] = '0';

          }
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
      if (j && (n == 0) &&(!((blksk->flag & 16) && (blksk->type != 'u'))))
      {
       if (ft_strlen(str) && (blksk->flag & 2) && (!(blksk->flag & 8)))
         ft_memmove(&str[j], &str[0], ft_strlen(str));// why is this not working ?
  //    if (ft_strlen(str) && (blksk->flag & 8))
        j -= 1;
        while (j >= 0)
          str[j--] = ' ';
      }
    }
  return (str);
}

void string_hex(uintmax_t n, char *final, t_block *blksk, const char *fmt)
{
  char *base;
  char str[2048];

  ft_bzero(str, 2048);
(void)fmt;
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
  if (blksk->type == 'p')
  {
    ft_strcpy(str, "0x");
    base = "0123456789abcdef";
  }
  if (blksk->type == 'u')
    base = "0123456789";
  ft_strcat(final, compose_snippet(str, base, n, blksk, fmt));
}
