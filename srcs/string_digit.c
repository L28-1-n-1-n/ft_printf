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
  int i;
  int j;
  int pres;
  int width;
  if (blksk->precision == -2)
    blksk->precision = 0;
  width = blksk->width;
  pres = blksk->precision;
  i = 0;
  if ((blksk->flag & 4) && (n >= 0)) // '+' flag
  {
    str[0] = '+';
    if (!((n == 0) && (blksk->flag & 128)))
      i = ft_strlen(group_digit(ft_itoamax(n, &str[1]), blksk));
    else
      i = ft_strlen(str);
  }
  else
  {
    if (!((n == 0) && (blksk->flag & 128)))
      i = ft_strlen(group_digit(ft_itoamax(n, str), blksk));
    else
      i = ft_strlen(str);
  }

  if ((blksk->precision > 0) && (i > 0))
    blksk->precision -= (i - 1);

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
    else
    {
      if (blksk->precision > 0)
      {
        while (blksk->precision--)
          ft_strpcat_char(str, '0');
      }
    }
  }
  i = ft_strlen(str);
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
          if (n != 0)
          {
            //ft_memmove(&str[j+1], &str[1], i - 1);
            if (((blksk->flag & 4) || (str[0] == '-')) && (blksk->flag & 2) && (!(blksk->flag & 128)))
            {
              ft_memmove(&str[j+1], &str[1], ft_strlen(str));
              //j-=1;
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
          }
          else
          {
              if ((blksk->flag & 4) && (blksk->flag & 2) && !(blksk->flag & 128)) //'+' and '0'
              {
                ft_memmove(&str[j+1], &str[1], ft_strlen(str));
                //j-=1;
                if ((n != 0) || (pres == 0))
                  while (j >= 1)
                    str[j--] = '0';
              }
              ft_memmove(&str[j], &str[0], ft_strlen(str));
              j-=1;
              while (j >= 0)
                str[j--] = ' ';
            }
        }
        else //no sign needed
        {
          if (n != 0)
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
            //  if ((pres) || (ft_strlen(str) < (size_t)width))
              if ((pres) || (blksk->flag & 128))
                while (j >= 0)
                  str[j--] = ' ';
              //roll
              else
                while (j >= 0)
                  str[j--] = '0';
            }

          }
          else // case n == 0
          {
            if (str[0])
            {
              ft_memmove(&str[j], &str[0], ft_strlen(str));
              j -= 1;
              if ((blksk->flag & 2) && (blksk->flag & 32))
              {
                if(n != 0)
                  while (j > 0)
                    str[j--] = '0';
                else
                {
                  if(pres)
                    while (j > 0)
                      str[j--] = ' ';
                  else
                    while (j > 0)
                      str[j--] = '0';
                str[0] = ' ';
                }
              }
              else
              {
                if ((blksk->flag & 2) && (!(blksk->flag & 32))) //'0' & not ' '
                {
                  if ((n == 0) && (pres != 0))
                    while (j >= 0)
                      str[j--] = ' ';
                  else
                    while (j >= 0)
                      str[j--] = '0';
                }
                else
                  while (j >= 0)
                    str[j--] = ' ';

              }
            }
            else
              while (j >= 1)
              {
                ft_strcat_char(str, ' ');
                j--;

              }

          }
        }
      }

j = blksk->width - ft_strlen(str);

      if ((!(blksk->flag & 2)) && (!(blksk->flag & 8))) // no '0' flag, no '-' flag
      {

          ft_memmove(&str[j], &str[0], ft_strlen(str));// first move content of str backwards, then pad with space
          j -= 1;
          while (j >= 0)
        //  while (j > 0)
            str[j--] = ' ';
      }
    }

    if (blksk->flag & 32) // ' ' flag
    {
      if ((n == 0) && (!(blksk->width)))
      {
        if (pres > 1)
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
      if ((str[0] == '0') && (n!= 0)) // '0' flag, but n != 0
      {
        str[0] = ' ';
      //  if (n == 0)
        //  ft_strcat_char(str, '0');
        //if (n == 0) // <-- this is the % .5d bug
          //str[1] = '0';

      }
      else
      {
        if ((blksk->flag & 8) && (n > 0))// '-'flag and n is not negative
        {
          if ((str[0] != '+') && (str[0] != '-'))
          {
            ft_memmove(&str[1], &str[0], ft_strlen(str));
            str[0] = ' ';
            if (str[ft_strlen(str) - 1] == ' ')
            {
              str[ft_strlen(str) - 1] = '\0';
            }
          }
        }
        else
        {
          if ((!(blksk->flag & 4)) && (blksk->width == 0) && (n > 0))//just ' 'flag and no '+' flag, and n is positive, and width = 0
            {
              ft_memmove(&str[1], &str[0], ft_strlen(str));
              str[0] = ' ';
              str[ft_strlen(str)] = '\0';
            }
          else
          {
            if (((ft_strlen(str) < (size_t)width)) || ((str[0] != ' ') && (str[0] != '+') && (str[0] != '-')))
              ft_strpcat_char(str, ' ');

          }
        }
      //  if ((n == 0) && (blksk->flag & 128) && (pres > 1))
      //    ft_strcat_char(str, ' ');
      }
    }

  //printf("str is %s and length is %zu\n", str, ft_strlen(str));
  return (str);
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
    output_final(final, FLEN, 0);
  ft_strcat(final, compose_digit(str, n, blksk));
//  free(str);
}
