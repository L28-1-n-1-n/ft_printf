#include "printf.h"
#include <stdio.h>

int cat_format(char *final, char *adj, int pos, char *mod)
{
  int len;

  len = ft_strlen(adj) - ft_strlen(mod) - 2; // 2 is for brackets{}
  if (len < 0)
      ft_memmove(&final[pos + len + ft_strlen(mod)], &final[pos + ft_strlen(mod) + 2], ft_strlen(&final[pos + ft_strlen(mod)]));
  if (len > 0)
    ft_memmove(&final[pos + len], &final[pos], ft_strlen(&final[pos]));
  ft_strncpy(&final[pos], adj, ft_strlen(adj));
  return (1);
}

int alter_format(char *final, char *mod, int pos)
{
  printf("mod is %s\n", mod);
  printf("final[%d] is %c\n", pos, final[pos]);
  if (ft_strcmp(mod, "CYAN") == 0)
    return(cat_format(final, CYAN, pos, mod));
  if (ft_strcmp(mod, "RED") == 0)
    return(cat_format(final, RED, pos, mod));
    //remove where CYAN where it is, with width ft_strlen(mod) + 2,
    //and then ft_memmove the current str for ft_strlen(CYAN), i.e. ft_stren(""\033[22;36m") units backwards,
    //then write  CYAN into original position in final
  return (0);
}
void format_final(char *final)
{
  int i;
  int k;
  char mod[10];

  i = 0;
  k = 0;
  ft_bzero(mod, 10);
  while (final[i])
  {
    if (final[i] == '{')
      if ((final[i + 1] != '{') && (final[i - 1] != '{'))
      {
        i++;
      //  printf("inside loop, final[%d] is %c\n", i, final[i]);
        while ((final[i + k] != '}') && (k < 9))
          {
            mod[k] = final[i + k];
            k++;
          }
      //  printf("after copy, mod is %s\n", mod);
        if ((final[i + k] == '}') && (final[i + k + 1] != '}') && (ft_strlen(mod) > 1))
        {
          printf("i = %d and k = %d\n", i, k);
          alter_format(final, mod, i - 1);
          ft_bzero(mod, 10);
        }
        k = 0;
      }
    i++;
  //  printf("final[%d] is %c\n",i, final[i]);
  }
}

void	compose_str(const char *fmt, va_list ap, t_block *blks)
{
  char final[50000];
  unsigned int i;
  unsigned int k;
  unsigned int len;

  i = 0;
  len = 0;
  k = 0;
  ft_bzero(final, 50000);
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
    printf("we are still in compose str\n");
    k++;
    fmt++;
    if (!(*fmt))
      break;
    while (!(ft_strchr("cdixXpeEfFgGousb%", *fmt)))
      fmt++;
    fmt++;
  //  printf("and finally fmt is %s\n", fmt);
  }
  format_final(final);
  printf("FIANL is \n%s\n", final);
}
