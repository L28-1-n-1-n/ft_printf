#include "printf.h"
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

int    treat_plain_text(const char *fmt, char *final, t_block *blksk)
{
  unsigned int n;

    n = ft_strchr_pos(&fmt[blksk->pos + 1], '%') - blksk->pos;
    ft_strncat(final, &fmt[blksk->pos + 1], n);
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


void protect_overflow(char *final, char *str)
{
  if (ft_strlen(final) + ft_strlen(str) > FLEN)
  {
    output_final(final, 0);
    if (ft_strlen(str) > FLEN)
      output_final(str, 0);
    else
      ft_strcat(final, str);
  }
  else
    ft_strcat(final, str);
}

void mod_char_flags(char *str, char *final, t_block *blksk, va_list ap)
{
  char c;
  if ((blksk->flag & 2) && (!(blksk->flag & 8)) && (blksk->width > 1))
    while (--blksk->width)
      ft_strpcat_char(str, '0');
  if ((!(blksk->flag & 8)) && (blksk->width > 1))
    while (--blksk->width)
      ft_strpcat_char(str, ' ');
  c = (char)(va_arg(ap, int));
  if (c == '\0')
  {
    ft_strcat(final, str);
    output_final(final, 1);
    write(1, "\0", 1);
    ft_bzero(str, ft_strlen(str));
  }
  else
    ft_strcat_char(str, c);
  if ((blksk->flag & 8) && (blksk->width > 0))
    while (--blksk->width)
      ft_strcat_char(str, ' ');
}

int    treat_char(char *final, va_list ap, t_block *blksk)
{
  char *str;

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
    mod_char_flags(str, final, blksk, ap);
  protect_overflow(final, str);
  free(str);
  return(0);
}
