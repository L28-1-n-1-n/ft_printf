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

	ft_printf("float=%.10lf\n", -0.00006866455078125);
	printf("float=%.10lf\n", -0.00006866455078125); //this is exponent = -12, mantissa representing 2^-14 + 2^-17 +2^-64
	*/
//	ft_printf("we have %llo\n", -9223372036854775808L);
//	printf("we have %llo\n", -9223372036854775808L);
//	ft_printf("float=%Lf\n", -11195354654646456545654654644645223372036854775808.0L);
	//printf("float=%.100Lf\n", -11195354654646456545654654644645223372036854775808.0L);
//	ft_printf("float=%Lf\n", 110680464442257309696.0L); //2^66+2^65
	ft_printf("float=%Lf\n", 110968694818409021448.0L);
//	printf("float=%.40f\n", 4503599627370495);
	//ft_printf("float=%.60Lf\n", 0xFFF0000000000000L);
//	ft_printf("float=%.10lf\n", 11817445422220183552.0);
//	ft_printf("float=%f\n", 5770237022568449.0);
//	printf("float=%f\n", 5770237022568449.0);
	//ft_printf("float=%f\n", 11817445422220199936.0);
	// this is 0100 10000000 00000000 00000000 00000000 00000000 00001001, plus 1 in front, shifted till we fill up 64 bits
	//i.e. 1010010000000000000000000000000000000000000000000100100000000000
//	printf("float=%f\n", 11817445422220199936.0);
//	ft_printf("float=%f\n",  5773614722288991436857736147222889914368.0);
//	printf("float=%.100f\n", 5773614722288991436857736147222889914368.0);
	//ft_printf("float=%f\n",0.00000000000000000000000000000000000001175494350822287507968736537222245677818665556772087521508751706278417259454727172851562500000000000000);
	//printf("float=%.140f\n",0.00000000000000000000000000000000000001175494350822287507968736537222245677818665556772087521508751706278417259454727172851562500000000000000);
	//ft_printf("float=%f\n", 0.0000000000000000001084202172485504434007452800869941711425781250000000);
	//	ft_printf("float=%f\n", 0.0000000000000000001355252715606880542509316001874271392822265625); //2^-63 + 2^-65
		//ft_printf("float=%f\n", 0.0000000012837410983741098237409182734019823740192387410923847102938471029384710293847102938471912346912639817263948716234123487264387264287346287348768900000012346283746723647632680000192387413984712304172394871329471298374019283741098237410982374109283741098237410982374123492870000001355252715606880542509316001874271392822265625); //2^-63 + 2^-65
		//printf("float=%.100f\n", 0.0000000012837410983741098237409182734019823740192387410923847102938471029384710293847102938471912346912639817263948716234123487264387264287346287348768900000012346283746723647632680000192387413984712304172394871329471298374019283741098237410982374109283741098237410982374123492870000001355252715606880542509316001874271392822265625); //2^-63 + 2^-65
	//	ft_printf("float=%Lf\n", 263.8L);
//	ft_printf("float=%f\n",  89736147222889914368.0);
//	printf("float=%.100f\n", 89736147222889914368.0);
//		ft_printf("float is %Lf\n", 0.0000000000000035527136788005009293556272153623791114375398436826861112283890933277838604376075437585313920862972736358642578125L);
//		printf("float is %.100Lf\n", 0.0000000000000035527136788005009293556272153623791114375398436826861112283890933277838604376075437585313920862972736358642578125L);
//		ft_printf("float=%f\n", 134613846192873461982736419872364891276349187263491827634918276349182763491872364918723649182736417283641789263498172634981726349817263491872364918726349817263491872364918726349187263491872364918723649187236498172364918273641982734619827346918726349878273469187263410928374109823374109283741098410982399.0);
//		printf("float=%.100f\n", 134613846192873461982736419872364891276349187263491827634918276349182763491872364918723649182736417283641789263498172634981726349817263491872364918726349817263491872364918726349187263491872364918723649187236498172364918273641982734619827346918726349878273469187263410928374109823374109283741098410982399.0);

//	printf("float=%.60Lf\n", -263.3L);
//	printf("float is %.50lf\n", 2345.678901019394959697);
	return (0);
}
