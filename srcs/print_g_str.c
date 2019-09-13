#include "printf.h"
#include <stdlib.h>

void      adjust_trail(char *final, t_block *blksk, int exp)
{
  //exp is the i pos of '.'
    printf("WE GOT TO ADJUST TRAIL\n");
  int end;
  int tmp;
  tmp = 0;
  end = ft_strlen(final) - 1;
  if (blksk->flag & 8)// '-' flag , 0 ignored
    while (exp < end)
      final[exp++] = ' ';
  if ((blksk->flag & 2) && (!(blksk->flag & 8))) // zero flag without '-'
  {
    final[end] = final[exp - 1];
    exp -=1;
    while (exp < end)
      final[exp++] = '0';
  }
  if ((!(blksk->flag & 2)) &&  (!(blksk->flag & 8))) // no '-' or zero flag
  {
    final[end] = final[exp - 1];
    tmp = exp - 1;
    while ((final[tmp] >= '0') && (final[tmp] <= '9'))
      tmp--;
    if ((final[tmp] == '+') || (final[tmp] == '-'))
    {
      final[end - 1] = final[tmp];
      exp -= 1;
      end -= 1;
    }
    exp -=1;
    while (exp < end)
      final[exp++] = ' ';
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
  ft_strcpy(fnum_copy->big_str, "\0");
  return (fnum_copy);
}

void copy_blocks(t_block *blksk, t_block *blks_cpy)
{
    blks_cpy[0].order = blksk->order;
    blks_cpy[0].flag = blksk->flag;
    blks_cpy[0].width = blksk->width;
    blks_cpy[0].modifier = blksk->modifier;
    blks_cpy[0].precision = blksk->precision;
    blks_cpy[0].type = blksk->type;
    blks_cpy[0].str = blksk->str;
    blks_cpy[0].pos = blksk->pos;
}

int find_exponent(t_block *blkse, t_float *fnume)
{
  char *finalc;
  int i;
  int k;

  k = 0;
  finalc = ft_strnew(50000);
  ft_bzero(finalc, 50000);
  print_e_str(finalc, blkse, fnume);
  if (blkse->type == 'e')
    i = ft_strchr_arg(finalc, 'e') + 2;
  else
    i = ft_strchr_arg(finalc, 'E') + 2;
  if (finalc[i - 1] == '-')
    k = -1 * ft_atoi(&finalc[i]);
  else
    k = ft_atoi(&finalc[i]);
  free(finalc);
  return (k);
}
void print_g_str(char *final, t_block *blksk, t_float *fnum)
{
  t_float *fnume;
  t_block *blkse;
  int     exp;

  if (!(fnume = (t_float *)malloc(sizeof(t_float))))
    return ;
  if(!(blkse = (t_block *)malloc(sizeof(t_block))))
    return ;
  init_float(fnume);
  copy_float(fnum, fnume);
  init_blocks(blkse, 1);
  copy_blocks(blksk, blkse);
  if (blksk->type == 'g')
    blkse->type = 'e';
  else
    blkse->type = 'E';
  exp = find_exponent(blkse, fnume);
  if (blksk->precision == 0)
    blksk->precision = 1;
  if ((exp < -4) || (blksk->precision <= exp))
    {
      if (blksk->type == 'g')
        blksk->type = 'e';
      else
        blksk->type = 'E';
      blksk->precision -= 1;
      print_e_str(final, blksk, fnum);
    }
  else
  {
    blksk->type = 'f';
    blksk->precision = blksk->precision - (exp + 1);
    print_float_str(final, blksk, fnum);
  }
  if (!(blksk->flag & 16)) // if '#' flag is present, nothing changes. Only in its absence trailing zeroes are removed
  {
    exp = ft_strlen(final) - 1;
    while ((final[exp] != '0') && (final[exp] != '.'))
      exp--;
    while (final[exp] == '0')
      exp--;
    if (final[exp] == '.')
      adjust_trail(final, blksk, exp);
  }
  free(fnume);
  free(blkse);
  printf("finallll is %s\n", final);
}
