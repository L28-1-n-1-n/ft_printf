#include "printf.h"

void print_result_helper(char *str, t_float *fnum, unsigned int bit)
{
  unsigned int i;
  int digit;

  i = 0;
  while (str[i] == '0')
    i++;
  digit = ft_strlen(&str[i]) - 2;
  ft_memmove(&str[0], &str[i], digit);
  if (bit == 64)
    ft_memset(&str[digit], '\0', 640 - digit);
  else
    ft_memset(&str[digit], '\0', 5270 - digit);
  ft_strcpy(fnum->big_str, str);
}
