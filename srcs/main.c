#include "printf.h"

#include <unistd.h>
#include <stdio.h>

/*
void	vafunc(char *fmt, ...)
{
	va_list ap;
	char *s;

	va_start(ap, fmt);
	printf("we got to vafunc\n");
//	printf("here we print fmt: %s", fmt);
	while (*fmt)
	{
		if ((*fmt) == 's')
		{
			s = va_arg(ap, char *);
		//	ft_putstr(s);
			printf("string %s\n", s);
			break;
		}
	}
	va_end(ap);
}
*/

int		main()
{
	char s[400];

	ft_strcpy(s, "hello");
/*
	printf("Test for formats:\n\n");
	ft_printf("HEX 42 %u\n", 42);
	printf("HEX 42 %u\n\n", 42);

	ft_printf("HEX 4242 %-u\n", 4242);
	printf("HEX 4242 %-u\n\n", 4242);

	ft_printf("HEX 4242 %0u\n", 4242);
	printf("HEX 4242 %0u\n\n", 4242);

	ft_printf("HEX 4242 %030u\n", 4242);
	printf("HEX 4242 %030u\n\n", 4242);

	ft_printf("HEX 4242 %-30u\n", 4242);
	printf("HEX 4242 %-30u\n\n", 4242);

	ft_printf("HEX 4242 %-030u\n", 4242);
	printf("HEX 4242 %-30u\n\n", 4242);

	printf("Test for limits:\n\n");
  ft_printf("HEX 2^31 = 2147483648 %lu\n", 2147483648);
  printf("HEX 2^31 = 2147483648 %lu\n\n", 2147483648);

  ft_printf("HEX -2^31 = -2147483648 %lu\n", -2147483648);
  printf("HEX -2^31 = -2147483648 %lu\n\n", -2147483648);

  ft_printf("HEX 2^63 - 1 = 9223372036854775807 %lu\n", 9223372036854775807);
  printf("HEX 2^63 - 1 = 9223372036854775807 %lu\n\n", 9223372036854775807);

  ft_printf("HEX 2^63 = -9223372036854775807 %lu\n", -9223372036854775807);
  printf("HEX 2^63 = -9223372036854775807 %lu\n\n", -9223372036854775807);*/
/*
	ft_printf("ft_printf-->% 30d\n", -642345234);
	printf("___printf-->% 30d\n", -642345234);

	ft_printf("ft_printf-->% 30d\n", 642345234);
	printf("___printf-->% 30d\n", 642345234);

	ft_printf("ft_printf-->% '30d\n", -642345234);
	printf("___printf-->% 30d\n", -642345234);

	ft_printf("ft_printf-->% '30d\n", 642345234);
	printf("___printf-->% 30d\n", 642345234);

	ft_printf("ft_printf-->% -30d\n", -642345234);
	printf("___printf-->% -30d\n", -642345234);

	ft_printf("ft_printf-->% -30d\n", 642345234);
	printf("___printf-->% -30d\n", 642345234);

	ft_printf("ft_printf-->% 030d\n", -642345234);
	printf("___printf-->% 030d\n", -642345234);

	ft_printf("ft_printf-->% 030d\n", 642345234);
	printf("___printf-->% 030d\n", 642345234);

	ft_printf("ft_printf-->% -0'30d\n", -642345234);
	printf("___printf-->% -'30d\n", -642345234);

	ft_printf("ft_printf-->% d\n", -642345234);
	printf("___printf-->%d\n", -642345234);

	ft_printf("ft_printf-->% d\n", 642345234);
	printf("___printf-->% d\n", 642345234);


	ft_printf("ft_printf-->%'30u\n", -642345234);
	printf("___printf-->%30u\n", -642345234);

	ft_printf("ft_printf-->%'30u\n", 642345234);
	printf("___printf-->%30u\n", 642345234);

	ft_printf("ft_printf-->%30u\n", -642345234);
	printf("___printf-->%30u\n", -642345234);

	ft_printf("ft_printf-->%30u\n", 642345234);
	printf("___printf-->%30u\n", 642345234);

	ft_printf("ft_printf-->%-'30u\n", -642345234);
	printf("___printf-->%-30u\n", -642345234);

	ft_printf("ft_printf-->%-'30u\n", 642345234);
	printf("___printf-->%-30u\n", 642345234);


	ft_printf("ft_printf-->% 0d\n", 0);
	printf("___printf-->% 0d\n", 0);

	ft_printf("ft_printf-->% d\n", 0);
	printf("___printf-->% d\n", 0);

	ft_printf("ft_printf-->% 5d\n", 0);
	printf("___printf-->% 5d\n", 0);

	ft_printf("ft_printf-->%+d\n", 0);
	printf("___printf-->%+d\n", 0);

	ft_printf("ft_printf-->%-5d\n", 0);
	printf("___printf-->%-5d\n", 0);

	ft_printf("ft_printf-->%05d\n", 0);
	printf("___printf-->%05d\n", 0);

	ft_printf("ft_printf-->%5d\n", 0);
	printf("___printf-->%5d\n", 0);

	ft_printf("ft_printf-->% 'd\n", 0);
	ft_printf("___printf-->%-0#5d\n", 0);


	ft_printf("ft_printf-->%0x\n", 0);
	printf("___printf-->%0x\n", 0);

	ft_printf("ft_printf-->%#x\n", 0);
	printf("___printf-->%#x\n", 0);

	ft_printf("ft_printf-->%5x\n", 0);
	printf("___printf-->%5x\n", 0);

	ft_printf("ft_printf-->%0#x\n", 0);
	printf("___printf-->%0#x\n", 0);

	ft_printf("ft_printf-->%-5x\n", 0);
	printf("___printf-->%-5x\n", 0);

	ft_printf("ft_printf-->%05x\n", 0);
	printf("___printf-->%05x\n", 0);

	ft_printf("ft_printf-->%5x\n", 0);
	printf("___printf-->%5x\n", 0);

	ft_printf("ft_printf-->%-0#5x\n", 0);
//	printf("___printf-->%-0#5x\n", 0);

	ft_printf("ft_printf-->% 'x\n", 0);
//	printf("___printf-->% 'x\n", 0);




	ft_printf("ft_printf-->%0u\n", 0);
	printf("___printf-->%0u\n", 0);

	ft_printf("ft_printf-->%#u\n", 0);
	//printf("___printf-->%#u\n", 0);

	ft_printf("ft_printf-->%5u\n", 0);
	printf("___printf-->%5u\n", 0);

	ft_printf("ft_printf-->%0#u\n", 0);
	//printf("___printf-->%0#u\n", 0);

	ft_printf("ft_printf-->%-5u\n", 0);
	printf("___printf-->%-5u\n", 0);

	ft_printf("ft_printf-->%05u\n", 0);
	printf("___printf-->%05u\n", 0);

	ft_printf("ft_printf-->%5u\n", 0);
	printf("___printf-->%5u\n", 0);

	ft_printf("ft_printf-->%-0#5u\n", 0);
	//	printf("___printf-->%-0#5x\n", 0);

	ft_printf("ft_printf-->% 'u\n", 0);
	//	printf("___printf-->% 'x\n", 0);
*/
/*
	ft_printf("pointer=%020p\n", s);
	printf("pointer=%p\n", s);
	ft_printf("pointer=%020p\n", &s[12]);
	printf("pointer=%p\n", &s[12]);

	int *num1;
	num1 = NULL;

	int num2;
	num2 = 4;

	ft_printf("pointer=%020p\n", num1);
	printf("pointer=%p\n", num1);

	ft_printf("pointer=%020p\n", &num2);
	printf("pointer=%p\n", &num2);
	*/
	//ft_printf("we have %llo\n", -9223372036854775808);
//	ft_printf("float=%Lf\n", 3.123456789012345678901234567890L);
	ft_printf("float=%lf\n", 263.3L);
	printf("float is %.100lf\n", 263.3);
	return (0);
}
