#include "printf.h"

void    aggregate(char product[50][1000])
{
    int i;
    int j;
    unsigned int tmp;
    unsigned int carry;

    i = 27; //i is row number
    j = 0; //j is index number
    carry = 0;
    while (i < 30)
    {
      printf("i is %d\n", i);
      while(product[i][j])
      {
        tmp  = (product[i][j] - '0') * 5;
        printf("tmp = %u, i = %d, j = %d\n", tmp, i, j);
        //product[i + 1][j] = product[i + 1][j] + carry + '0';
        product[i + 1][j] += carry + '0';
        printf("product[%d][%d] = %c\n", i + 1, j, product[i + 1][j]);
        carry = tmp / 10;
        tmp = tmp % 10;
        product[i + 1][j] += tmp;
        if (product[i + 1][j] > '9')
        {
          product[i + 1][j] -= 10;
          carry += 1;
        }
        printf("%c ", product[i][j]);
        j++;
      }

      if (carry)
        product[i][j] += carry + '0';
      printf("\nnext line\n");

      j = 0;
      i++;
    }
    i = 27;
    while (i < 30)
    {
      printf("product[%d] is %s\n", i, product[i]);
      i++;
    }
}
void    sub_array()
{
   // 50 rows, each 1000 characters long, fit till ^ 50
  char product[50][1000];
  int i;
  long double seed;

  i = 0;
  while (i < 50)
  {
    ft_bzero(&product[i], 1000);
    i++;
  }
  ft_strcpy(product[0], "0");
  i = 1;
  seed = 1;
  while (i < 28) // 2^27, or 5*27 is the last accurate one
  {
    seed = seed * ((long double)5);
    ft_itoamax(seed, product[i]);
    i++;
  }
  ft_strrev(product[27]);

  i = 0;
  while(i < 28)
  {
    printf("product[%d] is %s\n", i, product[i]);
    i++;
  }
  aggregate(product);
}
