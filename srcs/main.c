#include "printf.h"

#include <unistd.h>
#include <stdio.h>
#include <math.h>
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
/*	printf("%x%x%x%x%x%x%x%x%x%x%x%x");
	printf("%x%x%x%x%x%x%x%x%x%x%x%x");*/
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

	ft_printf("float=%.10lf\n", -0.00006866455078125);
	printf("float=%.10lf\n", -0.00006866455078125); //this is exponent = -12, mantissa representing 2^-14 + 2^-17 +2^-64
	*/


	/*
	ft_printf("1.float=%+-30.7f\n", 26894849843.3);
	printf("1.float=%+-30.7f\n", 26894849843.3);

	ft_printf("2.float=%+-30.7f\n", -26894849843.3);
	printf("2.float=%+-30.7f\n", -26894849843.3);

	ft_printf("3.float=%- 30.7f\n", 26894849843.3);
	printf("3.float=%- 30.7f\n", 26894849843.3);

	ft_printf("3.1float=%- 30.7f\n", -26894849843.3);
	printf("3.1float=%- 30.7f\n", -26894849843.3);

	ft_printf("4.float=%+030.7f\n", 26894849843.3);
	printf("4.float=%+030.7f\n", 26894849843.3);

	ft_printf("4.float=%+030.7f\n", -26894849843.3);
	printf("4.float=%+030.7f\n", -26894849843.3);

	ft_printf("5.float=%-30.7f\n", 26894849843.3);
	printf("5.float=%-30.7f\n", 26894849843.3);

	ft_printf("6.float=%-30.7f\n", -26894849843.3);
	printf("6.float=%-30.7f\n", -26894849843.3);

	ft_printf("7.float=%+30.7f\n", 26894849843.3);
	printf("7.float=%+30.7f\n", 26894849843.3);

	ft_printf("8.float=%+30.7f\n", -26894849843.3);
	printf("8.float=%+30.7f\n", -26894849843.3);

	ft_printf("9.float=% 30.7f\n", 26894849843.3);
	printf("9.float=% 30.7f\n", 26894849843.3);

	ft_printf("9.1float=% 030.7f\n", 26894849843.3);
	printf("9.1float=% 030.7f\n", 26894849843.3);

	ft_printf("10.float=% 30.7f\n", -26894849843.3);
	printf("10.float=% 30.7f\n", -26894849843.3);

	ft_printf("11.float=%030.7f\n", 26894849843.3);
	printf("11.float=%030.7f\n", 26894849843.3);

	ft_printf("12.float=%030.7f\n", -26894849843.3);
	printf("12.float=%030.7f\n", -26894849843.3);

	ft_printf("13.float=%+-'30.7f\n", 26894849843.3);
	ft_printf("14.float=%+0'30.7f\n", 26894849843.3);
	ft_printf("14.float=%+0'30.7f\n", -26894849843.3);*/
/*
	ft_printf("1.float=%+-30.7Lf\n", 26894849843.3L);
	printf("1.float=%+-30.7Lf\n", 26894849843.3L);

	ft_printf("2.float=%+-30.7Lf\n", -26894849843.3L);
	printf("2.float=%+-30.7Lf\n", -26894849843.3L);

	ft_printf("3.float=%- 30.7Lf\n", 26894849843.3L);
	printf("3.float=%- 30.7Lf\n", 26894849843.3L);

	ft_printf("3.1float=%- 30.7Lf\n", -26894849843.3L);
	printf("3.1float=%- 30.7Lf\n", -26894849843.3L);

	ft_printf("4.float=%+030.7Lf\n", 26894849843.3L);
	printf("4.float=%+030.7Lf\n", 26894849843.3L);

	ft_printf("4.1float=%+070.100Lf\n", 12.000000000000000000005465465910165105184063543646046451651019840532035268948498433L);
	printf("4.1float=%+070.100Lf\n", 12.000000000000000000005465465910165105184063543646046451651019840532035268948498433L);

	ft_printf("4.2float=%+070.100Lf\n", -12.000000000000000000005465465910165105184063543646046451651019840532035268948498433L);
	printf("4.2float=%+070.100Lf\n", -12.000000000000000000005465465910165105184063543646046451651019840532035268948498433L);

	ft_printf("5.float=%-30.7Lf\n", 26894849843.3L);
	printf("5.float=%-30.7Lf\n", 26894849843.3L);

	ft_printf("6.float=%-30.7Lf\n", -26894849843.3L);
	printf("6.float=%-30.7Lf\n", -26894849843.3L);

	ft_printf("7.float=%+30.7Lf\n", 26894849843.3L);
	printf("7.float=%+30.7Lf\n", 26894849843.3L);

	ft_printf("8.float=%+30.7Lf\n", -26894849843.3L);
	printf("8.float=%+30.7Lf\n", -26894849843.3L);

	ft_printf("9.float=% 30.7Lf\n", 26894849843.3L);
	printf("9.float=% 30.7Lf\n", 26894849843.3L);

	ft_printf("9.1float=% 030.7Lf\n", 26894849843.3L);
	printf("9.1float=% 030.7Lf\n", 26894849843.3L);

	ft_printf("10.float=% 30.7Lf\n", -26894849843.3L);
	printf("10.float=% 30.7Lf\n", -26894849843.3L);

	ft_printf("11.float=%030.7Lf\n", 26894849843.3L);
	printf("11.float=%030.7Lf\n", 26894849843.3L);

	ft_printf("12.float=%030.7Lf\n", -26894849843.3L);
	printf("12.float=%030.7Lf\n", -26894849843.3L);

	ft_printf("13.float=%+-'30.7Lf\n", 26894849843.3L);
	ft_printf("14.float=%+0'30.7Lf\n", 26894849843.3L);
	ft_printf("14.float=%+0'30.7Lf\n", -26894849843.3L);*/
//	ft_printf("float=%0 200'.100f\n",  -5773614722288991436857736147222889914368.0);

//	ft_printf("we have %llo\n", -9223372036854775808L);
//	printf("we have %llo\n", -9223372036854775808L);
//	ft_printf("float=%.50Lf\n", -11195354654646456545654654644645223372036854775808.0L);
//	printf("float=%.50Lf\n", -11195354654646456545654654644645223372036854775808.0L);

//	printf("float=%.40f\n", 4503599627370495);
	//ft_printf("float=%.60Lf\n", 0xFFF0000000000000L);
//	ft_printf("float=%.10lf\n", 11817445422220183552.0);
//	ft_printf("float=%f\n", 5770237022568449.0);
//	printf("float=%f\n", 5770237022568449.0);
	//ft_printf("float=%f\n", 11817445422220199936.0);
	// this is 0100 10000000 00000000 00000000 00000000 00000000 00001001, plus 1 in front, shifted till we fill up 64 bits
	//i.e. 1010010000000000000000000000000000000000000000000100100000000000
//	printf("float=%f\n", 11817445422220199936.0);

	//ft_printf("float=%0 '200.100f\n",  -5773614722288991436857736147222889914368.0);
/*	ft_printf("test value %+-020.30f\n", -(double)0);
	printf("test value %+-020.30f\n", -(double)0);
	ft_printf("test value %+-020.30f\n", (double)0);
	printf("test value %+-020.30f\n", (double)0);*/
//	ft_printf("test value %+-020.30f\n", +INFINITY);
//	printf("test value %+-020.30f\n", +INFINITY);

	//ft_printf("test for nan=%+-20.30f\n", -INFINITY);
	 //  printf("test for nan=%+-20.30f\n", -INFINITY);

	 ft_printf("printing subnormal number=%.400f\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004940656458412465441765687928682213723650598026143247);
	    printf("printing subnormal number=%.400f\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004940656458412465441765687928682213723650598026143247);
//	ft_printf("printing Max subnormal number=%.400f\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000022250738585072009);
//	   printf("printing Max subnormal number=%.400f\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000022250738585072009);

//	ft_printf("float=%.100Lf\n",  74159274159271741279512952471579215741270000000000000000000217421741247187845619849864156498561654856198198156981654986413581868978641274109817984215240145190209570250000000000000651515616165165465465465456465484561658498484654513691536451468135645816831564815773614722288991436857736147222889914368.0L);
//	   printf("float=%.100Lf\n",  74159274159271741279512952471579215741270000000000000000000217421741247187845619849864156498561654856198198156981654986413581868978641274109817984215240145190209570250000000000000651515616165165465465465456465484561658498484654513691536451468135645816831564815773614722288991436857736147222889914368.0L);

//	ft_printf("float=% -100.50f\n", 0.4564561516848431354999849465651651513212884684646);
//	printf("float=% -100.50f\n", 0.4564561516848431354999849465651651513212884684646);

//		ft_printf("digit is %+020d\n", 1234567890);
//		printf("digit is %+020d\n", 1234567890);

//	ft_printf("float=%f\n",  89736147222889914368.0);
//	printf("float=%.100f\n", 89736147222889914368.0);

//	printf("float=%.60Lf\n", -263.3L);
//	printf("float is %.50lf\n", 2345.678901019394959697);
	return (0);
}
