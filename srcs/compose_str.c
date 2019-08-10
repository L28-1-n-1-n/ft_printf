#include "printf.h"
#include <stdio.h>

void	compose_str(const char *fmt, va_list ap, t_block *blks)
{
  char final[8192];
  unsigned int i;
  unsigned int k;
  unsigned int len;

  i = 0;
  len = 0;
  k = 0;
  ft_bzero(final, 8192);
  (void)blks;
  while (*fmt)
  {
    len = 0;
    while (*fmt && (*fmt != '%'))
    {
      fmt++;
      len++;
    }
    ft_strncat(final, fmt - len, len);
    if (!(*fmt))
      break;
    treat_arg(final, ap, &blks[k]);
    // Treat '%' and ft_strncpy the result into final
    k++;
    fmt++;
    if (!(*fmt))
      break;
    while (!(ft_strchr("cdixXpeEfFgGous%", *fmt)))
      fmt++;
    fmt++;
  //  printf("and finally fmt is %s\n", fmt);
  }
  printf("FIANL is \n%s\n", final);
}