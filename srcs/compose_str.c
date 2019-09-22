#include "printf.h"
#include <stdio.h>
#include <unistd.h>
void output_final(char *final, size_t length)
{
  format_final(final);
  write(1, &final[0], ft_strlen(final));
  ft_bzero(final, length);
}

int cat_format(char *final, char *adj, int pos, char *mod)
{
  int len;
  int total;
  char tmp[20];
  unsigned int k;

  k = 0;
  printf("pos is %d\n", pos);
  total = 0;
  ft_bzero(tmp, 20);
  len = ft_strlen(adj) - ft_strlen(mod) - 2; // 2 is for brackets{}
  if (len > 0)
    {
      if (ft_strlen(final) + len > FLEN)
      {
        if (pos == 0)
        {
          ft_strcpy(tmp, adj);
          printf("pos + mod + 1 is %lu\n", pos + ft_strlen(mod) + 1);
          printf("at this pos, final is %s\n", &final[pos + ft_strlen(mod) + 2]);
          total = ft_strlen(final);
          ft_memmove(&final[pos], &final[pos + ft_strlen(mod) + 2], ft_strlen(&final[pos + ft_strlen(mod) + 2]));
          printf("then final is %s\n", final);
          len = ft_strlen(mod) + 3;
          while (len--)
            final[total - len] = '\0';
          output_final(tmp, ft_strlen(tmp));
        }
        else
        {
          write(1, &final[0], pos - 1);
          ft_memmove(&final[0], &final[pos], ft_strlen(&final[pos]));
        }
      }
      else
        // split it into 2 and then
      //  ft_strncpy(tmp, &final, ft_strchr_pos(&final[pos], '}');

    /*  if (len + ft_strlen(final) >=FLEN)
        // the idea is to print the first bracket {} as colour first, the rest of the string in another iteration
        // while pos is not zero, write whatever is in front of the pos first; if {} is at the beginning of final
        // then copy whatever that is in {} into a char declared on stack, then memmove whatever that was in final after the {} into final[0]
        output_final(final);
      else
      //check_buff(final, str, len);*/
      ft_memmove(&final[pos + len], &final[pos], ft_strlen(&final[pos]));
    }
  if (len < 0) // no problem with this part since we will not overflow final
    {
      ft_memmove(&final[pos + len + ft_strlen(mod) + 2], &final[pos + ft_strlen(mod)+ 2], ft_strlen(&final[pos + ft_strlen(mod) + 2]));
      len = len * -1 + 1;
      total = ft_strlen(final);
      while (len--)
        final[total - len] = '\0';
    }
  ft_strncpy(&final[pos], adj, ft_strlen(adj));
  return (1);
}

int alter_format(char *final, char *mod, int pos)
{
  if (ft_strcmp(mod, "BLACK") == 0)
    return(cat_format(final, BLACK, pos, mod));
  if (ft_strcmp(mod, "RED") == 0)
    return(cat_format(final, RED, pos, mod));
  if (ft_strcmp(mod, "GREEN") == 0)
    return(cat_format(final, GREEN, pos, mod));
  if (ft_strcmp(mod, "BROWN") == 0)
    return(cat_format(final, BROWN, pos, mod));
  if (ft_strcmp(mod, "BLUE") == 0)
    return(cat_format(final, BLUE, pos, mod));
  if (ft_strcmp(mod, "MAGNETA") == 0)
    return(cat_format(final, MAGNETA, pos, mod));
  if (ft_strcmp(mod, "CYAN") == 0)
    return(cat_format(final, CYAN, pos, mod));
  if (ft_strcmp(mod, "GRAY") == 0)
    return(cat_format(final, GRAY, pos, mod));
  if (ft_strcmp(mod, "WHITE") == 0)
    return(cat_format(final, WHITE, pos, mod));
  if (ft_strcmp(mod, "RESETTEXT") == 0)
    return(cat_format(final, RESETTEXT, pos, mod));
  if (ft_strcmp(mod, "BBLUE") == 0)
    return(cat_format(final, BBLUE, pos, mod));
  if (ft_strcmp(mod, "BPURPLE") == 0)
    return(cat_format(final, BPURPLE, pos, mod));
  if (ft_strcmp(mod, "BPINK") == 0)
    return(cat_format(final, BPINK, pos, mod));
  if (ft_strcmp(mod, "BORANGE") == 0)
    return(cat_format(final, BORANGE, pos, mod));
  if (ft_strcmp(mod, "BYELLOW") == 0)
    return(cat_format(final, BYELLOW, pos, mod));
  if (ft_strcmp(mod, "BGREEN") == 0)
    return(cat_format(final, BGREEN, pos, mod));
  if (ft_strcmp(mod, "BGREY") == 0)
    return(cat_format(final, BGREY, pos, mod));
  if (ft_strcmp(mod, "BWHITE") == 0)
    return(cat_format(final, BWHITE, pos, mod));
  if (ft_strcmp(mod, "BBLACK") == 0)
    return(cat_format(final, BBLACK, pos, mod));
  if (ft_strcmp(mod, "BOLD") == 0)
    return(cat_format(final, BOLD, pos, mod));
  if (ft_strcmp(mod, "IT") == 0)
    return(cat_format(final, IT, pos, mod));
  if (ft_strcmp(mod, "ULINE") == 0)
    return(cat_format(final, ULINE, pos, mod));
  if (ft_strcmp(mod, "STHRO") == 0)
    return(cat_format(final, STHRO, pos, mod));
  if (ft_strcmp(mod, "RESETFONT") == 0)
    return(cat_format(final, RESETFONT, pos, mod));
  return (0);
}

void delete_bracket(char *final, int i)
{
    ft_memmove(&final[i], &final[i + 1], ft_strlen(&final[i + 1]));
    final[ft_strlen(final) - 1] = '\0';
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
    if ((final[i] == '}') && (final[i + 1] == '}'))
      delete_bracket(final, i);
    if (final[i] == '{')
      if ((final[i + 1] != '{') && (final[i - 1] != '{'))
      {
        i++;
        while ((final[i + k] != '}') && (k < 9))
          {
            mod[k] = final[i + k];
            k++;
          }
        if ((final[i + k] == '}') && (final[i + k + 1] != '}') && (ft_strlen(mod) > 1))
        {
          alter_format(final, mod, i - 1);
          ft_bzero(mod, 10);
        }
        k = 0;
      }
    i++;
  }
}

int	compose_str(const char *fmt, va_list ap, t_block *blks)
{
  char *final;
  unsigned int i;
  unsigned int k;
  unsigned int len;

  i = 0;
  len = 0;
  k = 0;
  final = ft_strnew(FLEN);

  while (*fmt)
  {
    len = 0;
    while (*fmt && (*fmt != '%'))
    {
      fmt++;
      len++;
    }
    //ft_strncat(final, fmt - len, len);
//    printf("final is %s, str is %s and and len is %u\n", final, (char *)(fmt - len), len);
    printf("we got here\n");
    check_buff(final, (char *)(fmt - len), len);
    if (!(*fmt))
      break;
    treat_arg(final, ap, &blks[k]);
    k++;
    fmt++;
    if (!(*fmt))
      break;
    while (!(ft_strchr("cdixXpeEfFgGousbrk%", *fmt)))
      fmt++;
    fmt++;
  }
  output_final(final, FLEN);
  return (0);
}
