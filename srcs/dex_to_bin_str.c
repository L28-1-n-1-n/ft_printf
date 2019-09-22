#include "printf.h"
#include <stdio.h>

void				ft_bzero(void *s, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);


char *dex_to_bin_str(char *result, unsigned long long n)
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

/*
int main()
{
  char result[64];
  ft_bzero(result, 64);
  dex_to_bin_str(result, -62);
  printf("result is %s\n", result);
  return (0);
}*/
