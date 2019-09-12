// malloc final
// copy fnum
// copy blksk

#include "printf.h"
#include <stdlib.h>
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
    blks_cpy[0].order = blksk.order;
    blks_cpy[0].flag = blksk.flag;
    blks_cpy[0].width = blksk.width;
    blks_cpy[0].modifier = blksk.modifier;
    blks_cpy[0].precision = blksk.precision;
    blks_cpy[0].type = blksk.type;
    blks_cpy[0].str = blksk.str;
    blks_cpy[0].pos = blksk.pos;
}

void print_g_str(char *final, t_block *blksk, t_float *fnum)
{
  char *finalc;
  t_float *fnumf;
  t_float *fnume;
  t_block *blksf;
  t_block *blkse;

  finalc = ft_strnew(50000);
  ft_bzero(finalc, 50000);
  if ((!(fnumf = (t_float *)malloc(sizeof(t_float)))) || (!(fnume = (t_float *)malloc(sizeof(t_float)))))
    return (0);
  if((!(blksf = (t_block *)malloc(sizeof(t_block)))) || (!(blkse = (t_block *)malloc(sizeof(t_block)))))
      return (0);
  init_float(fnumf);
  init_float(fnume);
  copy_float(fnum, fnumf);
  copy_float(fnum, fnume);
  init_blocks(blksf, 1);
  init_blocks(blkse, 1);
  copy_blocks(blksk, blksf);
  copy_blocks(blksk, blkse);
  print_float_str(finalc, blksf, fnumf);
  ft_bzero(finalc, 50000);
  print_e_str(finalc, blkse, fnume);
// This is the part where you compare e and original precision


}
