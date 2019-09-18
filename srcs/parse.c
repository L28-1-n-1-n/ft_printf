#include "printf.h"
#include <stdlib.h>
#include <stdio.h>
/*
void shift_position(unsigned int m, t_block *blks)
{
  unsigned int order;
  unsigned int i;
  unsigned int copy

  i = 0;
  order = 1;
  while (i < m)
  {
    while (!(ft_strcmp(blks[i].str, "%")))
      i++;
    blk[i].order = blk[i - 1].order + 1;

  }
}
*/
void init_blocks(t_block *blks, int total)
{
  total = total - 1; /*For example, if 3 blocks to initialize, we will have blk[2], blk[1], blk[0]*/
  while (total >= 0)
  {
    blks[total].order = 0;
    blks[total].flag = 0;
    blks[total].width = 0;
    blks[total].modifier = NA;
    blks[total].precision = 6;
    blks[total].type = NA;
    blks[total].str = 0;
    blks[total].pos = 0;
    total--;
  }
}

int   parse(const char *fmt, va_list ap)
{
	unsigned int i;
  unsigned int k;
  unsigned int m; // to delete later

  t_block *blks;
	i = 0;
  k = 0; /*keep track on argument or blk number */
  m = count_arg(fmt);
  if(!(blks = (t_block *)malloc(sizeof(t_block) * count_arg(fmt))))
    return (ft_free(blks));
  init_blocks(blks, m);
  while (fmt[i])
  {
    while (fmt[i] && (fmt[i] != '%'))
      i++;
    if ((fmt[i] == '%') && (fmt[i + 1] == '%'))
    {
      blks[k].str = "%";
      blks[k].pos = i; // i is pos of '%', ft_strchr_arg has 0 at '%'
      k++;
      i += 2; /*skip till next argument*/
    }
    else
      if (fmt[i] == '%')
      {
        blks[k].pos = i;
        parse_arg(fmt, k, blks);
        k++;
        i++;
        while (fmt[i] && (fmt[i] != '%'))
          i++; /*skip until you find the next argument*/
      }
  }
  compose_str(fmt, ap, blks);
  return (1);
}
/*  k = 0;
  while (k < m)
  {
   printf("blks[%d].str is %s\n", k, blks[k].str);
    k++;
  }*/
/*

Initial ideas:
1. Scan for '%'
2. For '%%', pass to function "treat %%"
3. Else, pass to another function to tread all other '%'
4. In this "other function for 1 '%' only", read until you reach another '%'
5. %% %% % will give  %%% --> the 3rd % will be treated as invalid argument and thus printed as normal text

After that, process result and put each result in blk[i]
Then, loop over fmt one last time and form final result reading all tabs
*/
