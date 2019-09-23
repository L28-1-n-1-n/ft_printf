#include "printf.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
void    treat_char(char *final, va_list ap, t_block *blksk)
{
  char *str;

  str = ft_strnew(FLEN);
  if (blksk->flag & 8) // '-' flag
  {
    str[0] = (blksk->str) ? '%' : va_arg(ap, int);
    while (--blksk->width)
      ft_strcat_char(str, ' ');
  }
  if ((blksk->flag & 2) && (!(blksk->flag & 8)) && (blksk->width > 1)) // '0' flag and not '-' flag
  {
    while (--blksk->width)
      ft_strcat_char(str, '0');
    if (blksk->str)
      ft_strcat_char(str, '%');
    else
      ft_strcat_char(str, (char)va_arg(ap, int));
  }
  if ((!(blksk->flag & 8)) && (blksk->width > 1)) // not '-' flag, but width > 1
  {
    while (--blksk->width)
      ft_strcat_char(str, ' ');
    if (blksk->str)
      ft_strcat_char(str, '%');
    else
      ft_strcat_char(str, (char)va_arg(ap, int));
  }
  ft_strcat(final, str);
  free(str);
}

void treat_string_helper(char *str, char *string, t_block *blksk)
{
  int j;
  int i;

  j = 0;
  i = 0;
  if (blksk->precision)
  {
    j = ft_strlen(string);
    if (blksk->precision > j)
      blksk->precision = j;
    while ( i < blksk->precision)
      ft_strcat_char(str, string[i++]);
  }
  else // 0 precision
    ft_strcat(str, string);
}

void    treat_string(char *final, va_list ap, t_block *blksk)
{
  char *string;
  char *str;

  str = ft_strnew(FLEN);
  if (blksk->precision == 6)
    blksk->precision = 0;
  if (blksk->precision == -1)
    blksk->precision = va_arg(ap, int);
  if (blksk->precision < 0)
    blksk->precision = 0;

  string = va_arg(ap, char *);

  if (blksk->flag & 8) // '-' flag
  {
    treat_string_helper(str, string, blksk);
    while (--blksk->width)
      ft_strcat_char(str, ' ');
  }
  treat_string_helper(str, string, blksk);
  if ((blksk->flag & 2) && (!(blksk->flag & 8)) && (blksk->width > ft_strlen(str))) // '0' flag and not '-' flag
  {
    blksk->width -= ft_strlen(str);
    while (--blksk->width)
      ft_strpcat_char(str, '0'); // cat before
  }
  if ((!(blksk->flag & 8)) && (blksk->width > ft_strlen(str))) // not '-' flag, but width > 1
  {
    blksk->width -= ft_strlen(str);
    while (--blksk->width)
      ft_strpcat_char(str, ' '); // cat before
  }
  ft_strcat(final, str);
  free(str);
}

void    treat_bin (char *final, va_list ap, t_block *blksk) // needs to be tested, also needs to deal with '+' and '-'
{
  intmax_t n;

  n = add_modifier(ap, blksk);
  string_bin(n, final, blksk);
}

void    treat_hex(char *final, va_list ap, t_block *blksk)
{
  uintmax_t n;
  n = add_unsigned_modifier(ap, blksk);
  string_hex(n, final, blksk);
}

void    treat_non_print(char *final, va_list ap, t_block *blksk)
{
  uintmax_t n;

  n = va_arg(ap, unsigned int);
  blksk->flag |= 2;
  blksk->width = 2;
  blksk->precision = 0;
  blksk->type = 'x';
  ft_strcat(final, "\\x");
  string_hex(n, final, blksk);
}

void    treat_num(char *final, va_list ap, t_block *blksk)
{
  intmax_t n;

  n = add_modifier(ap, blksk);
  string_digit(n, final, blksk);
}

void    treat_float(char *final, va_list ap, t_block *blksk)
{
  double n;
  long double long_n;
  uint64_t word[2];

  n = 0;
  long_n = 0;
  if (blksk->width == -1)
    blksk->width = va_arg(ap, int);
  printf("width is %d\n", blksk->width);
  if (blksk->precision == -1)
    blksk->precision = va_arg(ap, int);
  if (blksk->width < 0)
  {
    printf("we got here\n");
    blksk->flag |= 8;
    blksk->width *= -1;
  }
  if (blksk->precision < 0)
    blksk->precision = 6;

  printf("width is %d\n", blksk->width);
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

  //printf("word[0] is %llu\n", word[0]);
  //printf("word[1] is %hu\n", (uint16_t)word[1]);
  //printf("word[1] is %llu\n", word[1]);
  decode_float(word, final, blksk);
}

void    treat_plain_text(const char *fmt, char *final, va_list ap, t_block *blksk)
{
  unsigned int n;

  n = ft_strchr(&fmt[blksk->pos + 1], '%') - blksk->pos;
  ft_strncat(final, &fmt[blksk->pos + 1], n);
}


void    treat_arg(const char *fmt, char *final, va_list ap, t_block *blksk)
{
  if (blksk->str)
    if ((blksk->str[0] == '%') && (blksk->type == NA))
      ft_strcat(final, "%");

  if (blksk->type == 'c')
    treat_char(final, ap, blksk);
  if (blksk->type == 'T')
    treat_plain_text(fmt, final, ap, blksk);
  if (blksk->type == 's')
    treat_string(final, ap, blksk);
  if ((blksk->type == 'x') || (blksk->type == 'X') ||
      (blksk->type == 'o') || (blksk->type == 'u') || (blksk->type == 'p'))
    treat_hex(final, ap, blksk);
  if((blksk->type == 'd') || (blksk->type == 'i'))
    treat_num(final, ap, blksk);
  if ((blksk->type == 'f') || (blksk->type == 'F') || (blksk->type == 'e') ||
    (blksk->type == 'E') || (blksk->type == 'g') || (blksk->type == 'G'))
    treat_float(final, ap, blksk);
  if (blksk->type == 'b')
    treat_bin(final, ap, blksk);
  if (blksk->type == 'r')
    treat_non_print(final, ap, blksk);
  if (blksk->type == 'k')
    treat_time(final, blksk);
}
// idea on how to generate random number : find the time, use the last digit of no.of seconds as seed
// take the last digit of seconds, divide it with second last, given second last is non-ft_bzero
// then divide first with second, given that both are non-zero, take the first digit of the float as the number (doesn't matter if it is zero)
// second seed will be second digit of decimal, so second digit e.g. 6, divides digit 6+2 = 8, etc
