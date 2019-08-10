#include "printf.h"
#include <stdio.h>
#include <inttypes.h>
intmax_t twos_comp_int(intmax_t n)
{
    intmax_t power;
    unsigned long long k;
    unsigned long int result; // this needs to be 32 bits
    char str[70];

    int i;

    i = 69; // str[32] is the last element ( 33rd ) and = backslash 0, i = 0-31 store value
  //  ft_bzero(str, 64);
    power = 1;

    while (i >= 0)
    {
      if (n & power)
        str[i] = '1';
      else
        str[i] = '0';
      power = power << 1;
      i --;
    }
    printf("we have : %s\n", str);
    return (n);
/*
    power = 0;
    result = 0;
    //k = -n;

    while (n > 0)
    {
      n = n >> 1;
      power++;
    }
    power --; // 64 is 2 ^6
    printf("power is %lu\n", power);
    power = 1 << power;
    printf("power is %lu\n", power);
  //  power = raise_to_power(2, power, result);

    n = n ^ power;

    n = n ^ 1;
    n += 1;
    return (n);*/
}

int main()
{
  printf("we have : %llx", twos_comp_int(-64));
  return (0);
}
