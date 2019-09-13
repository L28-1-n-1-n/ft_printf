int check_neg(intmax_t n, t_block *blksk)
{
  if (blksk->modifier == hh)
    if (n >> 7)
      return (1);
  if (blksk->modifier == h)
    if (n >> 15)
      return (1);
  if ((blksk->modifier == ll) || (blksk->modifier == l) ||
      (blksk->modifier == L) || (blksk->modifier == z))
      {
        printf("hola !\n");
        if ((n >= 429496729) || (n <= -32769))
        {
          printf("hola 2!\n");
          printf("n is %jd\n", n);

        // actuall this is too annoying.
        // Just 15 & n -> get last 4 digits, put them in string
        // then n >> 4, repeat, until
          if (n >> 63)
            return (1);
        }
        else
        {
          if (n >> 31)
          {
            printf("n >> 31 is %jd", n >> 31);
            return (1);
          }
        }
      }

  // x is unsigned int, 2^32
  if (blksk->modifier == 0)
    if (n >> 31)
      return (1);
  return (0);
}

void string_neg_hex(intmax_t n, char *final, char *str, t_block *blksk, char *hex) //  the only type to call this is x and X
{
//  char hex[16];
  char tmp[4];
  int i;
  int count;
  intmax_t k;

  count = 0;
  printf("we got here\n");
  ft_bzero(tmp, 4);

  if ((blksk->modifier == ll) || (blksk->modifier == l) ||
      (blksk->modifier == L) || (blksk->modifier == z))
      {
        if ((n >= 429496729) || (n <= -32769))
          count = 60; //60-4
        else
          count = 28; //32-4
      }
  else
    if ((blksk->modifier == h) || (blksk->modifier == 0))
        count = 12; // 16-4
  else
    if (blksk->modifier == hh)
      count = 4; // 8-4, first get left most 4 bits
/*  if (blksk->type = 'X')
    hex = "0123456789ABCDEF";
  if (blksk->type = 'x')
    hex = "0123456789abcdef";*/
    print_n(n);
    printf("initial count is %d\n", count);
  while (count > 0)
  {
    k = (n & (15 << count));
    count -=4;
    k = k >> count;
    i = 3;
    while (i >= 0)
    {
      tmp[i] = hex[k % 16];
      k = k / 16;
      i--;
    }
    ft_strcat(str, tmp);
   // you get 8 bit 2nd time round, so need to << 4 as well
  }
  printf("str is finally %s\n", str);
  ft_strcat(final, str);
}


void	parse_remain(const char *fmt, int i, va_list ap)
{
	char *str;
	int j;

	printf("fmt is here %s\n", fmt);
	j = 0;
	if (fmt[i] == 's' || fmt[i] == 'b')
		str = va_arg(ap, char *);
	if (fmt[i] == 's')
		while (str[j])
		{
			if ((str[j] < 127) && (str[j] > 31))
				write(1, &str[j], 1);
			j++;
		}
	if (fmt[i] == 'b')
		while (str[j])
		{
			if ((str[j] < 127) && (str[j] > 31))
				if (str[j] == '0' || str[j] == '1')
					write(1, &str[j], 1);
			j++;
		}
//	ft_putstr(str);
	//printf("str is %s\n", str);
}

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

#include "printf.h"
#include <stdio.h>
char *add_one(char *str)
{
	if (*str == '0')
		*str = '1';
	else // case last digit is a "1"
	{
		if (*str == '1')
			*str = '0';
		str--;
		add_one(str);
	}
	return (str);
}

char *twos_compliment_str(char *str)
{
	int i;

	i = 0;
printf("hi");
	while (str[i])
	{
		if (str[i] == '1')
			str[i] = '0';
		else
		{
			if (str[i] == '1')
				str[i] = '0';
		}
		i++;
		printf("str[%d] is %c\n", i, str[i]);
	}
/*
	while (*str)
	{
		if (*str == '1')
			*str = '0';
		else
			*str = '1';
		str++;
	}
*/
	printf("we got here");
//	str--;
//	add_one(str);
	return (str);
}

int main()
{
	char str[8] = "10000101";
	01111010

	!!!!!should just use bitwise opearator on decimal number !!!
	twos_compliment(str);
	printf(" after 2 \", it is %s", str);
	return (0);
}
