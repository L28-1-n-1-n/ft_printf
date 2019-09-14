#include "printf.h"
#include <stdio.h>
#include <stdint.h>
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
/*
void    treat_bin (char *final, va_list ap) // needs to be tested, also needs to deal with '+' and '-'
{
  int orig_num;
  char str[32];
  ft_bzero(str, 32);
  orig_num = va_arg(ap, int);
  while (orig_num / 2)
  {
    if (orig_num % 2)
      ft_strcat(str, '1');
    else
      ft_strcat(str, '0,');
    orig_nmum /= 2;
  }
  ft_strrev(str);
  ft_strcat(final, str);
}
*/
void    treat_hex(char *final, va_list ap, t_block *blksk)
{
  uintmax_t n;

  n = add_unsigned_modifier(ap, blksk);
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

  printf("word[0] is %llu\n", word[0]);
  printf("word[1] is %hu\n", (uint16_t)word[1]);
  printf("word[1] is %llu\n", word[1]);
  decode_float(word, final, blksk);
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
  if ((blksk->type == 'x') || (blksk->type == 'X') ||
      (blksk->type == 'o') || (blksk->type == 'u') || (blksk->type == 'p'))
    treat_hex(final, ap, blksk);
  if((blksk->type == 'd') || (blksk->type == 'i'))
    treat_num(final, ap, blksk);
  if ((blksk->type == 'f') || (blksk->type == 'F') || (blksk->type == 'e') || 
    (blksk->type == 'E') || (blksk->type == 'g') || (blksk->type == 'G'))
    treat_float(final, ap, blksk);
//  if (blksk->type == 'b')
  //  treat_bin(final, ap);
}
