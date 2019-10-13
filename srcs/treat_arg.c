#include "printf.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

int    treat_char(char *final, va_list ap, t_block *blksk)
{
  char *str;
  char c;
  if (blksk->width == -1)
    blksk->width = va_arg(ap, int);
  if (blksk->width > 2048)
    str = ft_strnew(blksk->width);
  else
    str = ft_strnew(2048);
  if (str == NULL)
    return (-1);
  if (blksk->str)
    str[0] = '%';
  else
  {
    if ((blksk->flag & 2) && (!(blksk->flag & 8)) && (blksk->width > 1)) // '0' flag and not '-' flag
    {
      while (--blksk->width)
        ft_strpcat_char(str, '0');
    }
    if ((!(blksk->flag & 8)) && (blksk->width > 1)) // not '-' flag, but width > 1
    {
      while (--blksk->width)
        ft_strpcat_char(str, ' ');
    }
    c = (char)(va_arg(ap, int));
  //  ft_strcat_char(str, (char)(va_arg(ap, int)));
    //if (str[ft_strlen(str) - 1] == '\0')
    if (c == '\0')
    {
      ft_strcat(final, str);
      output_final(final, ft_strlen(final), 1);
      write(1, "\0", 1);
      ft_bzero(str, ft_strlen(str));
    }
    else
      ft_strcat_char(str, c);
    if ((blksk->flag & 8) && (blksk->width > 0))// '-' flag
    {
      while (--blksk->width)
        ft_strcat_char(str, ' ');
    }
  }
  ft_strcat(final, str);
  free(str);
  return(0);
}

void treat_string_helper(char *str, char *string, t_block *blksk)
{
  int j;
  int i;

  j = 0;
  i = 0;
  if (blksk->precision > 0)
  {
    if (string == NULL)
      j = 6;
    else
      j = ft_strlen(string);
    if (blksk->precision > j)
      blksk->precision = j;
    if (string == NULL)
    {
      ft_strcat(str, "(null)");
      j = ft_strlen(str);
      while (j > blksk->precision)
        str[--j] = '\0';
    }
    else
      while ( i < blksk->precision)
        ft_strcat_char(str, string[i++]);
  }
  else // 0 precision
  {
    if ((string == NULL) && (!(blksk->flag & 128)))
      ft_strcat(str, "(null)");
    else
      if (!(blksk->flag & 128))
        ft_strcat(str, string);
  }
}

int    treat_string(char *final, va_list ap, t_block *blksk)
{
  char *string;
  char *str;

  if (blksk->precision == -2)
    blksk->precision = 0;
  if (blksk->precision == -1)
    blksk->precision = va_arg(ap, int);
  if (blksk->precision < 0) // Try it with %.*s, negative numbers supplied to * results in zero precision
    blksk->precision = 0;
  if (blksk->precision + blksk->width  > 2048)
    str = ft_strnew(blksk->precision + blksk->width);
  else
    str = ft_strnew(2048);
  if (str == NULL)
    return (-1);
  // The above needs to change since we have freeing problem here
  string = va_arg(ap, char *);

  treat_string_helper(str, string, blksk);
  if (blksk->flag & 8) // '-' flag
  {
    blksk->width -= ft_strlen(str);
    if (blksk->width > 0)
      while (blksk->width--)
        ft_strcat_char(str, ' ');
  }
  if ((blksk->flag & 2) && (!(blksk->flag & 8)) && ((size_t)blksk->width > ft_strlen(str))) // '0' flag and not '-' flag
  {
    blksk->width -= ft_strlen(str);
    if (blksk->width > 0)
      while (--blksk->width)
        ft_strpcat_char(str, '0'); // cat before
  }
  if ((!(blksk->flag & 8)) && ((size_t)blksk->width > ft_strlen(str))) // not '-' flag, but width > 1
  {
    blksk->width -= ft_strlen(str);
    if (blksk->width > 0)
      while (blksk->width--)
        ft_strpcat_char(str, ' '); // cat before
  }
  ft_strcat(final, str);
  free(str);
  return (0);
}

int    treat_bin (char *final, va_list ap, t_block *blksk) // needs to be tested, also needs to deal with '+' and '-'
{
  intmax_t n;

  n = add_modifier(ap, blksk);
  string_bin(n, final, blksk);
  return (0);
}

int    treat_hex(const char *fmt, char *final, va_list ap, t_block *blksk)
{
  uintmax_t n;
  n = add_unsigned_modifier(ap, blksk);

  string_hex(n, final, blksk, fmt);
  return (0);
}

int    treat_non_print(char *final, va_list ap, t_block *blksk, const char *fmt)
{
  uintmax_t n;

  n = va_arg(ap, unsigned int);
  blksk->flag |= 2;
  blksk->width = 2;
  blksk->precision = 0;
  blksk->type = 'x';
  ft_strcat(final, "\\x");
  string_hex(n, final, blksk, fmt);
  return (0);
}

int    treat_num(char *final, va_list ap, t_block *blksk)
{
  intmax_t n;

  if (blksk->width == -1)
    blksk->width = va_arg(ap, int);
  if (blksk->precision == -1)
    blksk->precision = va_arg(ap, int);
  n = add_modifier(ap, blksk);
  string_digit(n, final, blksk);
  return (0);
}

int    treat_float(char *final, va_list ap, t_block *blksk)
{
  double n;
  long double long_n;
  uint64_t word[2];

  n = 0;
  long_n = 0;
  if (blksk->width == -1)
    blksk->width = va_arg(ap, int);
  if (blksk->precision == -1)
    blksk->precision = va_arg(ap, int);
  if (blksk->width < 0)
  {
    blksk->flag |= 8;
    blksk->width *= -1;
  }
  if (blksk->precision < 0)
    blksk->precision = 6;

  if ((blksk->modifier == l) || (blksk->modifier == 0))
  {
    n = va_arg(ap, double);
    ft_memcpy(&word, &n, sizeof(word));
  }
else
  if (blksk->modifier == L)
  {
    long_n = va_arg(ap, long double);
    ft_memcpy(&word, &long_n, sizeof(word));
  }
  return(decode_float(word, final, blksk));
//  return (0);
}

int    treat_plain_text(const char *fmt, char *final, t_block *blksk)
{
  unsigned int n;

    n = ft_strchr_pos(&fmt[blksk->pos + 1], '%') - blksk->pos;
    ft_strncat(final, &fmt[blksk->pos + 1], n);
    return (0);
}


int    treat_arg(const char *fmt, char *final, va_list ap, t_block *blksk)
{
  if (blksk->str)
    if ((blksk->str[0] == '%') && (blksk->type == NA))
      ft_strcat(final, "%");
  if (blksk->type == 'c')
    return(treat_char(final, ap, blksk));
  if (blksk->type == 'T')
    return(treat_plain_text(fmt, final, blksk));
  if (blksk->type == 's')
    return(treat_string(final, ap, blksk));
  if ((blksk->type == 'x') || (blksk->type == 'X') ||
      (blksk->type == 'o') || (blksk->type == 'u') || (blksk->type == 'p'))
    return(treat_hex(fmt, final, ap, blksk));
  if((blksk->type == 'd') || (blksk->type == 'i'))
    return(treat_num(final, ap, blksk));
  if ((blksk->type == 'f') || (blksk->type == 'F') || (blksk->type == 'e') ||
    (blksk->type == 'E') || (blksk->type == 'g') || (blksk->type == 'G'))
    return(treat_float(final, ap, blksk));
  if (blksk->type == 'b')
    return(treat_bin(final, ap, blksk));
  if (blksk->type == 'r')
    return(treat_non_print(final, ap, blksk, fmt));
  if (blksk->type == 'k')
    return(treat_time(final, blksk));
  return (0);
}
// idea on how to generate random number : find the time, use the last digit of no.of seconds as seed
// take the last digit of seconds, divide it with second last, given second last is non-ft_bzero
// then divide first with second, given that both are non-zero, take the first digit of the float as the number (doesn't matter if it is zero)
// second seed will be second digit of decimal, so second digit e.g. 6, divides digit 6+2 = 8, etc
