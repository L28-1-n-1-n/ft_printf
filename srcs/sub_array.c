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

unsigned int sphfour(unsigned int power, t_float *fnum)
{
  fnum->remain >>= 1;
  power--;
  return (power);
}

void sphthree(unsigned int carry, unsigned int offset, t_float *fnum)
{
  if (carry)
    fnum->big_str[offset - 1] += carry;
}

unsigned int sphtwo(unsigned int carry, unsigned int offset, t_float *fnum, int i)
{
  carry = 0;
    if (fnum->big_str[offset + i] > '9')
    {
      carry = 1;
      fnum->big_str[offset + i] -= 10;
    }
  return(carry);
}

unsigned int sum_power_helper(unsigned int power, char product[1080][1000], t_float *fnum)
{
  while (!(fnum->remain & 1))
  {
    fnum->remain >>= 1;
    power--;
  }
  first_shift(product, fnum, power);
  fnum->remain >>= 1;
  power--;
  return (power);
}

void    sum_power(char product[1080][1000], t_float *fnum)
{
  unsigned int power;
  unsigned int carry;
  unsigned int i;
  unsigned int offset;

  carry = 0;
  i = 0;
  offset = 0;
  power = sum_power_helper(52, product, fnum);
 while (power > 0)
  {
    if (fnum->remain & 1)
    {
      offset = power + 1022 - ft_strlen(product[power + 1022]);
      i = ft_strlen(product[power + 1022]);
      carry = 0;
      while (product[power + 1022][--i])
      {
        fnum->big_str[offset + i] += product[power + 1022][i] + carry - '0';
        carry = sphtwo(carry, offset, fnum, i);
      }
      sphthree(carry, offset, fnum);
    }
    power = sphfour(power, fnum);
  }
}

void aggre_helper_one(char product[1080][1000], unsigned int i, unsigned int j, unsigned int carry)
{
  unsigned int tmp;

  tmp = 0;
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
}

void aggre_helper_two(char product[1080][1000])
{
  int i;

  i = 27;
  while (i < 1079)
  {
    ft_strrev(product[i]);
    i++;
  }
}

void    aggregate(char product[1080][1000])
{
    int i;
    int j;
    unsigned int carry;

    i = 27;
    j = 0;
    carry = 0;
    aggre_helper_one(product, i, j, carry);
    aggre_helper_two(product);
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
