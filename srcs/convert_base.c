#include "printf.h"
#include <stdio.h>

unsigned int base_u(char *tmp, t_block *blksk, uintmax_t n, unsigned int i)
{
  while (n > 0)
  {
    tmp[i] = blksk->base[n % 10];
    n /= 10;
    i++;
  }
  return (i);
}

char *convert_base(uintmax_t n, char *tmp, t_block *blksk)
{
  unsigned int k;
  unsigned int i;
  unsigned int mask;
  unsigned int step;

  i = 0;
  k = 0;
  tmp[0] = '0'; // preset '0' for case n = 0
  if (ft_strlen(blksk->base) == 10) // case unsigned 0123456789 has length 10
  {
    i = base_u(tmp, blksk, n, i);
    return (tmp);
  }
  mask = (ft_strlen(blksk->base) < 10) ? 7 : 15;
  step = (ft_strlen(blksk->base) < 10) ? 3 :4;
  while (n > 0) // this is a logical problem, after 32 bits, will need to be
  {
    k = n & mask; // 7 for octal
    n = n >> step; // 3 for octal
    tmp[i] = blksk->base[k];
    i++;
  }
  return (tmp);
}
