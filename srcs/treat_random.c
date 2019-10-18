#include "printf.h"
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void generate_random(char *str, uintmax_t n)
{
  time_t	seconds;
  unsigned int seed;
  unsigned int i;
  unsigned int tmp;

  i = 1;
  time(&seconds);
  seed = seconds % 10;
  str[0] = g_pi[0][seed];
  tmp = (unsigned int)(g_pi[0][seed] - '0');
  (void)n;
  while (i < n)
  {
    if (tmp == 0)
      tmp = 1;
    seed = seed + tmp;
    if (seed > 9999)
    {
      time(&seconds);
      seed = seconds % 10;
    }
    str[i] = g_pi[seed / 139][seed % 139];
    tmp = (unsigned int)(str[i] - '0');
    i++;
  }
}

int treat_random(char *final, uintmax_t n)
{
  char *str;

  str = (n < 2048) ? ft_strnew(2048) : ft_strnew(n);
  if (str == NULL)
    {
      free(str);
      return (-1);
    }
  generate_random(str, n);
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
  free(str);
  return (0);
}
