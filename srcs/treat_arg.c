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
  printf("n is first %jd\n", n); 
  string_digit(n, final, blksk);
}
/*
void    treat_pointer(char *final, va_list ap, t_block *blksk)
{
  unsigned long long n;
  (void)final;
  n = va_arg(ap, unsigned long long);
  string_hex(n, final, blksk);
  ft_strcat(final, string_hex(n));
  printf("n is %#llx\n", n);
  printf("\n16 is %#x and 64 is %#x\n", 16, 64);
  //ft_strcat(final, string);
}
*/
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
      (blksk->type == 'o') || (blksk->type == 'u'))
    treat_hex(final, ap, blksk);
  if((blksk->type == 'd') || (blksk->type == 'i'))
    treat_num(final, ap, blksk);
//  if (blksk->type == 'd')
  //  treat_string(final, ap);
  //if (blksk->type == 'p')
  //  treat_pointer(final, ap, blksk);
}
