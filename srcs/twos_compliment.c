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
