include "../includes/printf.h"
#include "../includes/libft.h"
#include <stdio.h>

char *dex_to_bin(char *result, unsigned long long n)
{
  int i;

  i = 62; // 0-63, and 63 = '\0' to make it a valid string
  while (n > 0)
  {
    if (n % 2)
      result[i] = '1';
    else
      result[i] = '0';
    n = n / 2;
    i--;
  }
  ft_memmove(&result[0], &result[i + 1], 62 - i);
  ft_bzero(&result[i + 1], 62 - i);
  return (result);
}
