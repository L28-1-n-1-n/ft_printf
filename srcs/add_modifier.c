#include "printf.h"
#include <stdio.h>

intmax_t add_modifier(va_list ap, t_block *blksk)
{
  intmax_t n;

    if (blksk->modifier == ll)
      n = va_arg(ap, long long);
  else
    if (blksk->modifier == l)
      n = va_arg(ap, long);
  else
    if (blksk->modifier == L)
      n = va_arg(ap, long double);
  else
    if (blksk->modifier == z)
      n = va_arg(ap, size_t);
  else
      n = va_arg(ap, int);
    if (blksk->modifier == hh)
      n = (signed char)n;
    if (blksk->modifier == h)
      n = (short)n;
  return (n);
}