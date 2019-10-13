#include "printf.h"

void    first_shift(char product[1080][1000], t_float *fnum, unsigned int power)
{
  unsigned int offset;

  offset = 0;
  if (fnum->remain & 1)
  {
    offset = power + 1022 - ft_strlen(product[power + 1022]);
    while (offset)
    {
      ft_strcat_char(fnum->big_str, '0');
      offset--;
    }
  ft_strcat(fnum->big_str, product[power + 1022]);
  }
}

void    sum_power(char product[1080][1000], t_float *fnum)
{
  unsigned int power;
  unsigned int offset;
  unsigned int carry;
  int i;

  power = 52;
  offset = 0;
  i = 0;
  carry = 0;
  while (!(fnum->remain & 1))
  {
    fnum->remain >>= 1;
    power--;
  }
  first_shift(product, fnum, power);
  fnum->remain >>= 1;
  power--;
  while (power > 0)
  {
    if (fnum->remain & 1)
    {
      offset = power + 1022 - ft_strlen(product[power + 1022]);
      i = ft_strlen(product[power + 1022]) - 1;
      carry = 0;
      while (product[power + 1022][i])
      {
        fnum->big_str[offset + i] += product[power + 1022][i] + carry - '0';
        carry = 0;
        if (fnum->big_str[offset + i] > '9')
        {
          carry = 1;
          fnum->big_str[offset + i] -= 10;
        }
        i--;
      }
      if (carry)
        fnum->big_str[offset - 1] += carry;
    }
    fnum->remain >>= 1;
    power--;
  }
}


void    aggregate(char product[1080][1000])
{
    int i;
    int j;
    unsigned int tmp;
    unsigned int carry;

    i = 27; //i is row number
    j = 0; //j is index number
    carry = 0;
    while (i < 1079)
    {
      while(product[i][j])
      {
        tmp  = (product[i][j] - '0') * 5;
        product[i + 1][j] += carry + '0';
        carry = tmp / 10;
        tmp = tmp % 10;
        product[i + 1][j] += tmp;
        if (product[i + 1][j] > '9')
        {
          product[i + 1][j] -= 10;
          carry += 1;
        }
        j++;
      }
      if (carry)
        product[i + 1][j] += carry + '0';
      carry = 0;
      j = 0;
      i++;
    }
    i = 27;
    while (i < 1079)
    {
      ft_strrev(product[i]);
      i++;
    }
}
void    sub_array(t_float *fnum)
{
  char product[1080][1000];
  int i;
  long double seed;

  i = 0;
  while (i < 1080)
  {
    ft_bzero(&product[i], 1000);
    i++;
  }
  ft_strcpy(product[0], "0");
  i = 1;
  seed = 1;
  while (i < 28)
  {
    seed = seed * ((long double)5);
    ft_itoamax(seed, product[i]);
    i++;
  }
  ft_strrev(product[27]);
  aggregate(product);
  sum_power(product, fnum);
}
