#include "printf.h"
#include <unistd.h>
#include <stdlib.h>

unsigned int alter_carry_80(int carry, t_float *fnum, unsigned int i)
{
  carry = 0;
  if (fnum->big_str[i] > '9')
  {
    carry = 1;
    fnum->big_str[i] -= 10;
  }
  return (carry);
}

int  alter_power_80(int power, t_float *fnum, char **product)
{
  while (!(fnum->remain & 1))
  {
    fnum->remain >>= 1;
    power--;
  }
  ft_strcat(fnum->big_str, product[power]);
  fnum->remain >>= 1;
  power--;
  return (power);
}

void    sum_power_80(char **product, t_float *fnum)
{
  int power;
  unsigned int carry;
  int i;

  power = 62;
  i = 16425;
  carry = 0;
  power = alter_power_80(power, fnum, product);
  while (power >= 0)
  {
    if (fnum->remain & 1)
    {
      carry = 0;
      i = 16425;
      while (product[power][i])
      {
        fnum->big_str[i] += product[power][i] + carry - '0';
        carry = alter_carry_80(carry, fnum, i);
        i--;
      }
    }
    fnum->remain >>= 1;
    power--;
  }
}

void ft_cat_array(char *p)
{
    unsigned int i;
    i = 0;
    while (i < 160)
    {
      ft_strcat(p, g_test[i]);
      i++;
    }
}

void    sub_array_80(t_float *fnum)
{
  char **product;
  int i;

  i = 0;
  product = (char **)malloc(sizeof(char *) * 64);
  while (i < 64)
  {
    if (!(product[i]=(char*)ft_strnew(16426)))
      return ;
    i++;
  }
  i = 0;
  while (i < 64)
  {
    ft_strcpy(product[i], "\0");
    i++;
  }
  i = 0;
  while (i++ < 4931)
    ft_strcat_char(product[62], '0');
  ft_cat_array(product[62]);
  ft_strcat_char(product[62], '\0');
  aggregate_80(product);
  sum_power_80(product, fnum);
}
