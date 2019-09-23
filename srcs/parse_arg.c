#include "printf.h"
#include <stdio.h>
int check_type(char *str, unsigned int k, t_block *blks)
{
  while (*str && !(ft_strchr("cdixXpeEfFgGousbrk%", *str)))
    str++;
  if (*str)
  {
    if (*str == 'c')
      blks[k].type = 'c';
    if (*str == 'd')
      blks[k].type = 'd';
    if (*str == 'i')
      blks[k].type = 'i';
    if (*str == 'x')
      blks[k].type = 'x';
    if (*str == 'X')
      blks[k].type = 'X';
    if (*str == 'p')
      blks[k].type = 'p';
    if (*str == 'e')
      blks[k].type = 'e';
    if (*str == 'E')
      blks[k].type = 'E';
    if (*str == 'f')
      blks[k].type = 'f';
    if (*str == 'F')
      blks[k].type = 'F';
    if (*str == 'g')
      blks[k].type = 'g';
    if (*str == 'G')
      blks[k].type = 'G';
    if (*str == 'o')
      blks[k].type = 'o';
    if (*str == 'u')
      blks[k].type = 'u';
    if (*str == 's')
      blks[k].type = 's';
    if (*str == 'b')
      blks[k].type = 'b';
    if (*str == 'r')
      blks[k].type = 'r';
    if (*str == 'k')
      blks[k].type = 'k';
    if (*str == '%')
    {
      blks[k].str = "%";
      blks[k].type = 'c';
    }
  }
  printf("type complete\n");
  return(0);
}

char *check_length(char *str, unsigned int k, t_block *blks)
{
  while (*str && !(ft_strchr("hlLzcdixXpeEfFgGousbrk%", *str)))
    str++;
  if (*str == 'L')
    blks[k].modifier = L; //5
  if (*str == 'z')
    blks[k].modifier = z; //6
  if (*str == 'h')
  {
    str++;
    if (*str == 'h')
      blks[k].modifier = hh; //1
    else
      blks[k].modifier = h; //2
  }
  if (*str == 'l')
  {
    str++;
    if (*str == 'l')
      blks[k].modifier = ll; //3
    else
      blks[k].modifier = l; //4
  }
  return(str);
}

// 0 = 2, '+' = 4, '-' = 8, '#' = 16, space = 32, 'apostrophe'  = 64
char *check_flags_width_pres(const char *fmt, unsigned int k, t_block *blks)
{
  char *str;

  if(blks[k].order > 0)
    str = (char *)(fmt + blks[k].pos + ft_strchr_arg(fmt + blks[k].pos, '$'));
  else
    str = (char *)(fmt + blks[k].pos + 1);
  while (*str && !(ft_strchr("*.cdixXpeEfFgGousbrk%hlLz123456789", *str)))
    {
      if (*str == '+')
        blks[k].flag |= 4;
      if (*str == '-')
        blks[k].flag |= 8;
      if (*str == '#')
        blks[k].flag |= 16;
      if (*str == ' ')
        blks[k].flag |= 32;
      if (*str == '0')
        blks[k].flag |= 2;
      if (*str == '\'')
        blks[k].flag |= 64;
      str++;
    }
  // now we arrive at either * .  or letter or digit
  printf("next *str is %c\n", *str);
  if ((*str > '0') && (*str <= '9'))
    blks[k].width = ft_atoi(str);
  if (*str == '*')
    blks[k].width = -1;
  if (ft_strchr_arg(--str, '.')) // we need the -- before str, becoz if width == 0, strchr_arg skips the dot right away
  {
    str += 1 + ft_strchr_arg(str, '.');
    if (*str == '*')
      blks[k].precision = -1;
    else
      blks[k].precision = ft_atoi((char *)str);
  }
  str++;
  return (str);
}

void check_order(const char *fmt, unsigned int k, t_block *blks)
{
  if (ft_strchr_arg(fmt + blks[k].pos, '$'))
    blks[k].order = ft_atoi(fmt + blks[k].pos + 1);
}

int    parse_arg(const char *fmt, unsigned int k, t_block *blks)
{
  check_order(fmt, k, blks);
  return(check_type(check_length(check_flags_width_pres(fmt, k, blks), k , blks), k, blks));
}
