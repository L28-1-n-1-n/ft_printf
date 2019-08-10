#include "printf.h"
#include <stdio.h>

void print_n(intmax_t n)
{
    intmax_t power;
    char str[70];

    int i;

    i = 68; // str[32] is the last element ( 33rd ) and = backslash 0, i = 0-31 store value
  //  ft_bzero(str, 64);
    power = 1;
    str[69]= '\0';
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
  }
