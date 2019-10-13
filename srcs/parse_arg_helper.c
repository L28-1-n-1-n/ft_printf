#include "printf.h"

void check_type_helper(char *str, unsigned int k, t_block *blks)
{
   if (*str == 'F')
    blks[k].type = 'F';
  else if (*str == 'g')
    blks[k].type = 'g';
  else if (*str == 'G')
    blks[k].type = 'G';
  else if (*str == 'o')
    blks[k].type = 'o';
  else if (*str == 'u')
    blks[k].type = 'u';
  else if (*str == 's')
    blks[k].type = 's';
  else if (*str == 'b')
    blks[k].type = 'b';
  else if (*str == 'r')
    blks[k].type = 'r';
  else if (*str == 'k')
    blks[k].type = 'k';
  if (*str == '%')
  {
    blks[k].str = "%";
    blks[k].type = 'c';
  }
}

int check_type(char *str, unsigned int k, t_block *blks)
{
  while (*str && !(ft_strchr("cdixXpeEfFgGousbrk%", *str)))
    str++;
  if (*str)
  {
    if (*str == 'c')
      blks[k].type = 'c';
    else if (*str == 'd')
      blks[k].type = 'd';
    else if (*str == 'i')
      blks[k].type = 'i';
    else if (*str == 'x')
      blks[k].type = 'x';
    else if (*str == 'X')
      blks[k].type = 'X';
    else if (*str == 'p')
      blks[k].type = 'p';
    else if (*str == 'e')
      blks[k].type = 'e';
    else if (*str == 'E')
      blks[k].type = 'E';
    else if (*str == 'f')
        blks[k].type = 'f';
    else check_type_helper(str, k, blks);
  }
  return (0);
}

char *check_len(char *str, unsigned int k, t_block *blks)
{
  while (*str && !(ft_strchr("hlLzcdixXpeEfFgGousbrk%", *str)))
    str++;
  if (*str == 'L')
    blks[k].modifier = L;
  if (*str == 'z')
    blks[k].modifier = z;
  if (*str == 'h')
  {
    str++;
    if (*str == 'h')
      blks[k].modifier = hh;
    else
      blks[k].modifier = h;
  }
  if (*str == 'l')
  {
    str++;
    if (*str == 'l')
      blks[k].modifier = ll;
    else
      blks[k].modifier = l;
  }
  return(str);
}
