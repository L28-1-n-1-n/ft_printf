#include "printf.h"
#include <stdlib.h>

int find_exponent(t_block *blkse, t_float *fnume)
{
  char *finalc;
  int i;
  int k;

  k = 0;
  finalc = ft_strnew(50000);
  ft_bzero(finalc, 50000);
  print_e_str(finalc, blkse, fnume);
  if (blkse->type == 'e')
    i = ft_strchr_arg(finalc, 'e') + 2;
  else
    i = ft_strchr_arg(finalc, 'E') + 2;
  if (finalc[i - 1] == '-')
    k = -1 * ft_atoi(&finalc[i]);
  else
    k = ft_atoi(&finalc[i]);
  free(finalc);
  return (k);
}