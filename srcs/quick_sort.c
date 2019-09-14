#include "printf.h"
#include <stdio.h>

void sort_array(unsigned int m)
{
  unsigned int arr[m];
  printf("size of array is %d\n", sizeof(arr));
}

void quick_sort(unsigned int m, t_block* blks)
{
  t_block *new_blks;
  if(!(new_blks = (t_block *)malloc(sizeof(t_block) * m)))
    return ;
  init_blocks(new_blks, m);
  sort_array(m);
}
