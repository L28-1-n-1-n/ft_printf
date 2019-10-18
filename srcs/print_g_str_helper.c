#include "printf.h"
#include <stdlib.h>

void remove_finalz_helper(char *final, int exp, t_float *fnum, t_block *blksk)
{
  int tmp;

  tmp = 0;
  if ((blksk->type == 'f') || (blksk->type == 'F'))
  {
    tmp = ft_strlen(final) - 1;
    while (!((final[tmp] >= '0') && (final[tmp] <= '9')))
      tmp--;
    exp = tmp;
    while(final[tmp] == '0')
      tmp--;
    while (++tmp <= exp)
    {
      if (fnum->eflag & 2)
        final[tmp] = ' ';
      else
        final[tmp] = '\0';
    }
    final[tmp] = '\0';
  }
}

void      remove_finalz(char *final, t_block *blksk, int exp, t_float *fnum)
{
  int tmp;
  int count_del;
  int dot_pos;

  dot_pos = exp;
  count_del = 0;
  tmp = 0;
  remove_finalz_helper(final, exp, fnum, blksk);
  if (!((blksk->type == 'f') || (blksk->type == 'F')))
  {
    if (blksk->type == 'e')
      while (final[exp] != 'e')
        exp++;
    else // case 'E'
      while (final[exp] != 'E')
        exp++;
    exp -= 1;
    tmp = exp;
    while(final[tmp] == '0')
      tmp--;
    count_del = exp - tmp;
   if (count_del != 0) // so trailing zeroes present
      ft_memmove(&final[tmp + 1], &final[exp + 1], ft_strlen(&final[exp + 1]));
  }
}

t_float   *copy_float(t_float *fnum, t_float *fnum_copy)
{
  fnum_copy->sign = fnum->sign;
  fnum_copy->exponent = fnum->exponent;
  fnum_copy->mantissa = fnum->mantissa;
  fnum_copy->integer = fnum->integer;
  fnum_copy->remain = fnum->remain;
  fnum_copy->decimal = fnum->decimal;
  fnum_copy->eflag = fnum->eflag;
  fnum_copy->final_len = fnum->final_len;
  ft_strcpy(fnum_copy->big_str, "\0");
  return (fnum_copy);
}

void copy_blocks(t_block *blksk, t_block *blks_cpy)
{
    blks_cpy[0].order = blksk->order;
    blks_cpy[0].flag = blksk->flag;
    blks_cpy[0].width = blksk->width;
    blks_cpy[0].modifier = blksk->modifier;
    blks_cpy[0].orig = blksk->orig;
    blks_cpy[0].precision = blksk->precision;
    blks_cpy[0].type = blksk->type;
    blks_cpy[0].str = blksk->str;
    blks_cpy[0].pos = blksk->pos;
}

void duplicate_g(t_float *fnum, t_float *fnume, t_block *blksk, t_block *blkse)
{
  if (blksk->precision == -2)
    blksk->precision = 6;
  init_float(fnume);
  copy_float(fnum, fnume);
  init_blocks(blkse, 1);
  copy_blocks(blksk, blkse);
  if (blksk->type == 'g')
    blkse->type = 'e';
  else
    blkse->type = 'E';
}
