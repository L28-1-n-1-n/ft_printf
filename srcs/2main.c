#include "../includes/printf.h"
#include "../includes/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
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
//	printf("%d", printf("%5%"));
/*	ft_printf("%+-0    5% s%%  c  %%%+-0    5%roar%k\n");
	printf("%+-0    5% s%%  c  %%%+-0    5%roar%k\n");
ft_printf("@moulitest1: %x", 0);
printf("@moulitest1: %x", 0);
ft_printf("@moulitest2: %.x", 0);
printf("@moulitest2: %.x", 0);
ft_printf("@moulitest3: %#.3x", 0);
printf("@moulitest3: %#.3x", 0);
ft_printf("@moulitest4: %.x %#.3x", 0, 0);
printf("@moulitest4: %.x %#.3x", 0, 0);
ft_printf("%5%");
printf("%5%");
ft_printf("@moulitest5: %5.x %5.0x", 0, 0);
printf("@moulitest5: %5.x %5.0x", 0, 0);
ft_printf("@moulitest: %15.6x\n", 82);
printf("@moulitest: %15.6x\n", 82);*/
//ft_printf("%lX\n", 4294967296);
//printf("%lX\n", 4294967296);
//ft_printf("%10s is a string\n", "this");
//printf("%10s is a string\n", "this");
//ft_printf("%.2s is a string\n", "this");
//printf("%.2s is a string\n", "this");
//ft_printf("%5.2s is a string", "this");
//printf("%5.2s is a string", "this");
//ft_printf("%10s is a string\n", "");
//printf("%10s is a string\n", "");
//  ft_printf("%-10s is a string\n", "this");
//	  printf("%-10s is a string\n", "this");
	 // ft_printf("%5.2s is a string\n", "");
		//  printf("%5.2s is a string\n", "");
//ft_printf("%#-08x\n", 42);
//printf("%#-08x\n", 42);
//ft_printf("%.5d|%-.5d|%+.5d|% .5d|%0.5d\n", 0, 0, 0, 0, 0);
//ft_printf("%.5d\n", 0);
//printf("%.5d|%-.5d|%+.5d|% .5d|%0.5d\n", 0, 0, 0, 0, 0);

//ft_printf("%.5d|%-.5d|%+.5d|% .5d|%0.5d\n", 0, 0, 0, 0, 0);
//printf("%.5d|%-.5d|%+.5d|% .5d|%0.5d\n", 0, 0, 0, 0, 0);
/*
ft_printf("%d|%-d|%+d|% .1d|%0d\n", 0, 0, 0, 0, 0);
printf("%d|%-d|%+d|% .1d|%0d\n", 0, 0, 0, 0, 0);

ft_printf("%d|%-d|%+d|% d|%0d\n", 0, 0, 0, 0, 0);
printf("%d|%-d|%+d|% d|%0d\n", 0, 0, 0, 0, 0);


ft_printf("%+1.d|%-1.d|%+1.d|% 1.d|%01.d\n", 0, 0, 0, 0, 0);
printf("%+1.d|%-1.d|%+1.d|% 1.d|%01.d\n", 0, 0, 0, 0, 0);

ft_printf("%23.d|%-23.d|%+23.d|% 23.d|%023.d\n", 0, 0, 0, 0, 0);
printf("%23.d|%-23.d|%+23.d|% 23.d|%023.d\n", 0, 0, 0, 0, 0);

ft_printf("%-+1.5d|%- 1.5d|%-01.5d|%+ 1.5d|%+01.5d|% 01.5d|%-+ 01.5d\n", 0, 0, 0, 0, 0, 0, 0);
printf("%-+1.5d|%- 1.5d|%-01.5d|%+ 1.5d|%+01.5d|% 01.5d|%-+ 01.5d\n", 0, 0, 0, 0, 0, 0, 0);

ft_printf("%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\n", 0, 0, 0, 0, 0, 0, 0);
printf("%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\n", 0, 0, 0, 0, 0, 0, 0);

ft_printf("%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\n", -0, -0, -0, -0, -0, -0, -0);
printf("%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\n", -0, -0, -0, -0, -0, -0, -0);

ft_printf("%.d|%-.d|%+.d|% .d|%0.d\n", -0, -0, -0, -0, -0);
printf("%.d|%-.d|%+.d|% .d|%0.d\n", -0, -0, -0, -0, -0);

ft_printf("%.5d|%-.5d|%+.5d|% .5d|%0.5d\n", -0, -0, -0, -0, -0);
printf("%.5d|%-.5d|%+.5d|% .5d|%0.5d\n", -0, -0, -0, -0, -0);

*/
//passed above
/*

ft_printf("%11.5d|%-11.5d|%+11.5d|% 11.5d|%011.5d\n", 23, 23, 23, 23, 23);
printf("%11.5d|%-11.5d|%+11.5d|% 11.5d|%011.5d\n", 23, 23, 23, 23, 23);

ft_printf("%11.5d|%-11.5d|%+11.5d|% 11.5d|%011.5d\n", -23, -23, -23, -23, -23);
printf("%11.5d|%-11.5d|%+11.5d|% 11.5d|%011.5d\n", -23, -23, -23, -23, -23);

ft_printf("%11.5d|%-11.5d|%+11.5d|% 11.5d|%011.5d\n", 0, 0, 0, 0, 0);
printf("%11.5d|%-11.5d|%+11.5d|% 11.5d|%011.5d\n", 0, 0, 0, 0, 0);

ft_printf("%11.5d|%-11.5d|%+11.5d|% 11.5d|%011.5d\n", -0, -0, -0, -0, -0);
printf("%11.5d|%-11.5d|%+11.5d|% 11.5d|%011.5d\n", -0, -0, -0, -0, -0);

ft_printf("%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d\n", 0, 0, 0, 0, 0);
printf("%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d\n", 0, 0, 0, 0, 0);

ft_printf("%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d\n", -0, -0, -0, -0, -0);
printf("%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d\n", -0, -0, -0, -0, -0);

ft_printf("%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\n", 0, 0, 0, 0, 0, 0, 0);
printf("%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\n", 0, 0, 0, 0, 0, 0, 0);

ft_printf("%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\n", -0, -0, -0, -0, -0, -0, -0);
printf("%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\n", -0, -0, -0, -0, -0, -0, -0);


ft_printf("%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n", 0, 0, 0, 0, 0, 0, 0);
   printf("%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n", 0, 0, 0, 0, 0, 0, 0);

ft_printf("%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n", -0, -0, -0, -0, -0, -0, -0);
printf("%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n", -0, -0, -0, -0, -0, -0, -0);

ft_printf("%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\n", 0, 0, 0, 0, 0, 0, 0);
printf("%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\n", 0, 0, 0, 0, 0, 0, 0);



ft_printf("%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\n", -0, -0, -0, -0, -0, -0, -0);
printf("%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\n", -0, -0, -0, -0, -0, -0, -0);

ft_printf("%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n", 0, 0, 0, 0, 0, 0, 0);
   printf("%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n", 0, 0, 0, 0, 0, 0, 0);
*/
//passed above

/*
ft_printf("%23d|%-23d|%+23d|% 23d|%023d\n", 0, 0, 0, 0, 0);
printf("%23d|%-23d|%+23d|% 23d|%023d\n", 0, 0, 0, 0, 0);

ft_printf("%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\n", 0, 0, 0, 0, 0, 0, 0);
printf("%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\n", 0, 0, 0, 0, 0, 0, 0);

ft_printf("%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\n", 0, 0, 0, 0, 0, 0, 0);
printf("%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\n", 0, 0, 0, 0, 0, 0, 0);

ft_printf("%23d|%-23d|%+23d|% 23d|%023d\n", -0, -0, -0, -0, -0);
printf("%23d|%-23d|%+23d|% 23d|%023d\n", -0, -0, -0, -0, -0);

ft_printf("%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\n", -0, -0, -0, -0, -0, -0, -0);
printf("%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\n", -0, -0, -0, -0, -0, -0, -0);

ft_printf("|%+023.d|%+023.d|%023.5d|%023.5d|\n", -0, 0, -0, 0);
printf("|%+023.d|%+023.d|%023.5d|%023.5d|\n", -0, 0, -0, 0);

*/

//ft_printf("%.5o|%-.5o|%#.5o|%0.5o\n", 0U, 0U, 0U, 0U);
//printf("%.5o|%-.5o|%#.5o|%0.5o\n", 0U, 0U, 0U, 0U);

//ft_printf("%23.5o|%-23.5o|%#23.5o|%023.5o\n", 0U, 0U, 0U, 0U);
//printf("%23.5o|%-23.5o|%#23.5o|%023.5o\n", 0U, 0U, 0U, 0U);
ft_printf("%-#23o|%-023o|%#023o|%-#023o\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
ft_printf("%-#23o|%-023o|%#023o|%-#023o\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);

//ft_printf("%-#23.5o|%-023.5o|%#023.5o|%-#023.5o\n", 0U, 0U, 0U, 0U);
//printf("%-#23.5o|%-023.5o|%#023.5o|%-#023.5o\n", 0U, 0U, 0U, 0U);
/*
test: "%-#23.5o|%-023.5o|%#023.5o|%-#023.5o", 0U, 0U, 0U, 0U
test: "%-#23o|%-023o|%#023o|%-#023o", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX
test: "%-#23.o|%-023.o|%#023.o|%-#023.o", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX
test: "%-#23.5o|%-023.5o|%#023.5o|%-#023.5o", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX
test: "%-#23o|%-023o|%#023o|%-#023o", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX
test: "%-#23.o|%-023.o|%#023.o|%-#023.o", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX
test: "%-#23.5o|%-023.5o|%#023.5o|%-#023.5o", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX
test: "%-#23o|%-023o|%#023o|%-#023o", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX
test: "%-#23.o|%-023.o|%#023.o|%-#023.o", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX
test: "%-#23.5o|%-023.5o|%#023.5o|%-#023.5o", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX
*/

//ft_printf("%.o|%-.o|%#.o|%0.o\n", 0U, 0U, 0U, 0U);
//printf("%.o|%-.o|%#.o|%0.o\n", 0U, 0U, 0U, 0U);

/*
test: "%.o|%-.o|%#.o|%0.o", 0U, 0U, 0U, 0U
test: "%.5o|%-.5o|%#.5o|%0.5o", 0U, 0U, 0U, 0U
test: "%1.o|%-1.o|%#1.o|%01.o", 0U, 0U, 0U, 0U
test: "%23.o|%-23.o|%#23.o|%023.o", 0U, 0U, 0U, 0U
test: "%1.5o|%-1.5o|%#1.5o|%01.5o", 0U, 0U, 0U, 0U
test: "%23.5o|%-23.5o|%#23.5o|%023.5o", 0U, 0U, 0U, 0U
*/

/*
test: "%23u|%-23u|%023u", 0U, 0U, 0U
test: "%-023u", 0U
test: "%-023.5u", 0U
test: "%23o|%-23o|%#o|%023o", 0U, 0U, 0U, 0U
*/
/*
ft_printf("%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
printf("%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);

ft_printf("%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
printf("%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);

ft_printf("%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
printf("%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
*/
/*
test: "%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX
test: "%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX
test: "%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX
test: "%.5d|%-.5d|%+.5d|% .5d|%0.5d", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN
test: "%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN
test: "%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN
test: "%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN

*/
/*
ft_printf("%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 023.2d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, -INT_MAX);
printf("%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 023.2d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, -INT_MAX);

ft_printf("%23.d|%-23.d|%+23.d|% 23.d|%023.d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
printf("%23.d|%-23.d|%+23.d|% 23.d|%023.d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);

ft_printf("%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
printf("%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);

ft_printf("%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
printf("%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);

ft_printf("%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
printf("%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);

ft_printf("%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
printf("%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
*/

/*
test: "%23.d|%-23.d|%+23.d|% 23.d|%023.d", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX
test: "%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX
test: "%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX
test: "%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX
test: "%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX
test: "%23d|%-23d|%+23d|% 23d|%023d", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN
test: "%.d|%-.d|%+.d|% .d|%0.d", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN
test: "%.5d|%-.5d|%+.5d|% .5d|%0.5d", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN
test: "%1.d|%-1.d|%+1.d|% 1.d|%01.d", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN
test: "%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN
test: "%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN
test: "%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN
test: "%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN
*/

//	ft_printf("%10.5d\n", 0);
//	ft_printf("%10.5d\n", 0);
//ft_printf("|% 020d|\n", 12);
//printf("|% 020d|\n", 12);
//ft_printf("@moulitest6: %#.x %#.0x", 0, 0);
//printf("@moulitest6: %#.x %#.0x", 0, 0);
//ft_printf("@moulitest7: %#.x", 0);
//printf("@moulitest7: %#.x", 0);

//printf("@moulitest: %#.x %#.0x", 0, 0);
//ft_printf("%5%");
//printf("%.0%");
	//NEED to DO : deal with s between two arguments
	// idea : when you have %   %, need to delete whatever type that comes in the next %
	// and then make everything between the next 2 % as plain string
	// also need to deal with difference between %% and %    % (type NA)?

//	ft_printf("%5%  %\n");
//	printf("%5%  %\n");
//	printf("%d", printf("%5"));
	/*char s[400];

	ft_strcpy(s, "hello");
	ft_printf("=%+40f\n", 0.00123);
	printf("=%+40f\n", 0.00123);
	ft_printf("=%+40F\n", 0.00123);
	printf("=%+40F\n", 0.00123);
	ft_printf("=%+40E\n", 0.00123);
	printf("=%+40E\n", 0.00123);
	ft_printf("=%+40e\n", 0.00123);
	printf("=%+40e\n", 0.00123);
	ft_printf("=%+40g\n", 0.00123);
	printf("=%+40g\n", 0.00123);
	ft_printf("=%-40G\n", 0.00123);
	printf("=%-40G\n", 0.00123);*/

//	ft_printf("bin=%-Lb\n", -9223372036854775808);
//	ft_printf("zero=%+ 30.788f\n", -0);
//	printf("zero=%+ 30.788f\n", -0);
//		ft_printf("flaot=%*.*f\n",-50, 23, 123.544);
	/*	ft_printf("flaot=%*.*f\n", -50, -23, 123.544);
	   	 printf("flaot=%*.*f\n", -50, -23, 123.544);
		ft_printf("flaot=%*.*f\n", 50, -23, 123.544);
		   printf("flaot=%*.*f\n", 50, -23, 123.544);*/
		//	 ft_printf("string=%2$.*s and then %%%% %3$d\n", 3, "hello", 23);
	/*	ft_printf("♞  🐤🙊 {BBLUE}{WHITE}⏎{RESETTEXT}{RESETFONT}");
		ft_printf("Because {BBLUE}{WHITE}everything{RESETTEXT}{RESETFONT}{GREEN} is {RESETTEXT}{BWHITE}{RED}AWESOME{RESETTEXT}{RESETFONT} {BORANGE}{BLACK}{IT}!!!{RESETTEXT}{RESETFONT}\n");
		ft_printf("{BGREY}{BLUE}I feel {RESETTEXT}{RESETFONT}{BOLD}{BYELLOW}{BROWN}MORE{RESETTEXT}{RESETFONT}{BPURPLE}{WHITE} AWESOME {RESETTEXT}{RESETFONT}{BBLACK}{MAGNETA}than an {RESETTEXT}{RESETFONT}{ULINE}{BPINK}{CYAN}awesome possum{RESETTEXT}{RESETFONT}\n");
		ft_printf("You know what's {BGREEN}{STHRO}{GRAY}%s{RESETTEXT}{RESETFONT}? Everything 😎 ✊ ! {RED}✽{GREEN}✼{MAGNETA}❉{CYAN}✲{BLUE}🃑{BPINK}{BLACK}🃒{WHITE}☺︎{BPURPLE}{CYAN}♠︎{RED}♣︎{BROWN}♥︎{GREEN}♦︎{BYELLOW}{BLACK}☂{RESETTEXT}{RESETFONT}☀︎\n", "awesome");
		ft_printf("And below we test errors:\n{BYELLOW}{BLACK}Invalid colour {RESETTEXT}{RESETFONT} shall print as text :{YELLOW}\n");
		ft_printf("{STHRO}And so many bad spellings:{RESETTEXT}{RESETFONT}\n{BLACKK}{BBLACK}{{BLACK}}{RED}<--double brackets are printed as single ones{RESETTEXT}{RESETFONT}\n");
		ft_printf("Here's a bunch of random brackets\n{{{{}}}}{{}{}{{{}}}}{MAGNETA}{{more %s}}{BLUE} and invalid formats{{IT}}{U_LINE}{RESETTEXT}{RESETFONT}\n", "brackets");
		ft_printf("We want to {CYAN}say {{%s}} to {RED}the{RESETTEXT}%.*s and {GREEEN}{GREEN}then\n", "hello", 3, "{{world}}");
		ft_printf("{BORANGE}{BLACK}And now we print first 5 chracters of the string \"0123456789\": %.*s{RESETTEXT}{RESETFONT}\n", 5, "0123456789");
			ft_printf("Testing \t");
		ft_printf("\\x%02x\n", '\t');
		ft_printf("non-printable character=%r%%%r%r{CYAN}%s{RESETTEXT}\n", '\t', '\n', '\b', "YAAAYYY!!!");
		ft_printf("time is %k\n");
		ft_printf("%s", "dorem12345hello");*/
	//	ft_printf("{RED}Hola!!\n");
		//ft_printf("dec=%llx\n",-9223372036854775808);
	//printf("dec=%llx\n", -9223372036854775808);
//	printf("digit=% -5d\n", 12);
//	ft_printf("bin=% #5b\n", 4);
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
	ft_printf("14.float=%+0'30.7f\n", -26894849843.3);

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

	 /*Below is Max subnormal positive number for f, basically = 2^-1074*/
//	 ft_printf("printing subnormal number=%.400f\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004940656458412465441765687928682213723650598026143247);
//	    printf("printing subnormal number=%.400f\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004940656458412465441765687928682213723650598026143247);

/*2^-1074 + 2 ^-1073*/
//	ft_printf("printing subnormal nummber=%.400f\n", 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001482196937523739632529706378604664117095179407842974);
//	   printf("printing subnormal nummber=%.400f\n", 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001482196937523739632529706378604664117095179407842974);

/*2^-1073*/
//		ft_printf("printing subnormal number=%.400f\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000009881312916824930883531375857364427447301196052286495);
//		   printf("printing subnormal number=%.400f\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000009881312916824930883531375857364427447301196052286495);

//	ft_printf("printing Max subnormal number=%.400f\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000022250738585072009);
//	   printf("printing Max subnormal number=%.400f\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000022250738585072009);
	//ft_printf("printing exactly zero=%+-23.10f\n", 0.0);
	 //  printf("printing exactly zero=%+-23.10f\n", 0.0);
	// ft_printf("float=%f\n", -INFINITY/INFINITY);
	 //   printf("float=%f\n", -INFINITY/INFINITY);
	// ft_printf("Max double is=%f\n", 17976931348623157000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0);
// 		 printf("Max double is=%f\n", 17976931348623157000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0);

//	ft_printf("float=%.100Lf\n",  74159274159271741279512952471579215741270000000000000000000217421741247187845619849864156498561654856198198156981654986413581868978641274109817984215240145190209570250000000000000651515616165165465465465456465484561658498484654513691536451468135645816831564815773614722288991436857736147222889914368.0L);
//	   printf("float=%.100Lf\n",  74159274159271741279512952471579215741270000000000000000000217421741247187845619849864156498561654856198198156981654986413581868978641274109817984215240145190209570250000000000000651515616165165465465465456465484561658498484654513691536451468135645816831564815773614722288991436857736147222889914368.0L);
//ft_printf("float=%f\n", 7450580596923828125);
//printf("float=%f\n", 7450580596923828125);
//ft_printf("float=%f\n", 7450580596923828125.0);
//printf("float=%f\n", 7450580596923828125.0);
//	ft_printf("float=% -100.50f\n", 0.4564561516848431354999849465651651513212884684646);
//	printf("float=% -100.50f\n", 0.4564561516848431354999849465651651513212884684646);

//		ft_printf("digit is %+020d\n", 1234567890);
//		printf("digit is %+020d\n", 1234567890);

//	ft_printf("float=%f\n",  89736147222889914368.0);
//	printf("float=%.100f\n", 89736147222889914368.0);

//	printf("float=%.60Lf\n", -263.3L);
//	printf("float is %.50lf\n", 2345.678901019394959697);

//ft_printf("Min float80 subnormal=%.5000Le\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000364519953188247460252840593361941981639905081569356L);
/*
ft_printf("1.float=%+-30.7e\n", 26894849843.3);
printf("1.float=%+-30.7e\n", 26894849843.3);

ft_printf("2.float=%+-30.7e\n", -26894849843.3);
printf("2.float=%+-30.7e\n", -26894849843.3);

ft_printf("3.float=%- 30.7e\n", 26894849843.3);
printf("3.float=%- 30.7e\n", 26894849843.3);

ft_printf("3.1float=%- 30.7e\n", -26894849843.3);
printf("3.1float=%- 30.7e\n", -26894849843.3);

ft_printf("4.float=%+030.7e\n", 26894849843.3);
printf("4.float=%+030.7e\n", 26894849843.3);

ft_printf("4.float=%+030.7e\n", -26894849843.3);
printf("4.float=%+030.7e\n", -26894849843.3);

ft_printf("5.float=%-30.7e\n", 26894849843.3);
printf("5.float=%-30.7e\n", 26894849843.3);

ft_printf("6.float=%-30.7e\n", -26894849843.3);
printf("6.float=%-30.7e\n", -26894849843.3);

ft_printf("7.float=%+30.7e\n", 26894849843.3);
printf("7.float=%+30.7e\n", 26894849843.3);

ft_printf("8.float=%+30.7e\n", -26894849843.3);
printf("8.float=%+30.7e\n", -26894849843.3);

ft_printf("9.float=% 30.7e\n", 26894849843.3);
printf("9.float=% 30.7e\n", 26894849843.3);

ft_printf("9.1float=% 030.7e\n", 26894849843.3);
printf("9.1float=% 030.7e\n", 26894849843.3);

ft_printf("10.float=% 30.7e\n", -26894849843.3);
printf("10.float=% 30.7e\n", -26894849843.3);

ft_printf("11.float=%030.7e\n", 26894849843.3);
printf("11.float=%030.7e\n", 26894849843.3);

ft_printf("12.float=%030.7e\n", -26894849843.3);
printf("12.float=%030.7e\n", -26894849843.3);

ft_printf("13.float=%+-'30.7e\n", 26894849843.3);
ft_printf("14.float=%+0'30.7e\n", 26894849843.3);
ft_printf("15.float=%+0'30.7e\n", -26894849843.3);



ft_printf("1.float=%+-30.7e\n", 0.268948498433);
printf("1.float=%+-30.7e\n", 0.268948498433);

ft_printf("2.float=%+-30.7e\n", -0.268948498433);
printf("2.float=%+-30.7e\n", -0.268948498433);

ft_printf("3.float=%- 30.7e\n", 0.268948498433);
printf("3.float=%- 30.7e\n", 0.268948498433);

ft_printf("3.1float=%- 30.7e\n", -0.268948498433);
printf("3.1float=%- 30.7e\n", -0.268948498433);

ft_printf("4.float=%+030.7e\n", 0.268948498433);
printf("4.float=%+030.7e\n", 0.268948498433);

ft_printf("4.float=%+030.7e\n", -0.268948498433);
printf("4.float=%+030.7e\n", -0.268948498433);

ft_printf("5.float=%-30.7e\n", 0.268948498433);
printf("5.float=%-30.7e\n", 0.268948498433);

ft_printf("6.float=%-30.7e\n", -0.268948498433);
printf("6.float=%-30.7e\n", -0.268948498433);

ft_printf("7.float=%+30.7e\n", 0.268948498433);
printf("7.float=%+30.7e\n", 0.268948498433);

ft_printf("8.float=%+30.7e\n", -0.268948498433);
printf("8.float=%+30.7e\n", -0.268948498433);

ft_printf("9.float=% 30.7e\n", 0.268948498433);
printf("9.float=% 30.7e\n", 0.268948498433);

ft_printf("9.1float=% 030.7e\n", 0.268948498433);
printf("9.1float=% 030.7e\n", 0.268948498433);

ft_printf("10.float=% 30.7e\n", -0.268948498433);
printf("10.float=% 30.7e\n", -0.268948498433);

ft_printf("11.float=%030.7e\n", 0.268948498433);
printf("11.float=%030.7e\n", 0.268948498433);

ft_printf("12.float=%030.7e\n", -0.268948498433);
printf("12.float=%030.7e\n", -0.268948498433);

ft_printf("13.float=%+-'30.7e\n", 0.268948498433);
ft_printf("14.float=%+0'30.7e\n", 0.268948498433);
ft_printf("15.float=%+0'30.7e\n", -0.268948498433);*/
/*
ft_printf("float=%#.8f\n", 0.0000000378123);
printf("float=%#.8f\n", 0.0000000378123);
ft_printf("float=%#.8e\n", 0.0000000378123);
printf("float=%#.8e\n", 0.0000000378123);
ft_printf("float=%-30.8g\n", 0.0000000378123);
printf("float=%-30.8g\n", 0.0000000378123);

ft_printf("float=%#.8f\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000378123);
printf("float=%#.8f\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000378123);
ft_printf("float=%#.8e\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000378123);
printf("float=%#.8e\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000378123);*/
//ft_printf("float=%- 30.8g\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000378123);
//printf("float=%- 30.8g\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000378123);

/*
ft_printf("1.float=%+-30.8g\n", 0.0000000378123);
printf("1.float=%+-30.8g\n", 0.0000000378123);

ft_printf("2.float=%+-30.8g\n", -0.0000000378123);
printf("2.float=%+-30.8g\n", -0.0000000378123);

ft_printf("3.float=%- 30.8g\n", 0.0000000378123);
printf("3.float=%- 30.8g\n", 0.0000000378123);

ft_printf("3.1float=%- 30.8g\n", -0.0000000378123);
printf("3.1float=%- 30.8g\n", -0.0000000378123);

ft_printf("4.float=%+030.8g\n", 4.0000000378123);
printf("4.float=%+030.8g\n", 4.0000000378123);

ft_printf("4.float=%+030.8g\n", -4.0000000378123);
printf("4.float=%+030.8g\n", -4.0000000378123);

ft_printf("5.float=%-30.8g\n", 4.0000000378123);
printf("5.float=%-30.8g\n", 4.0000000378123);

ft_printf("6.float=%-30.8g\n", -4.0000000378123);
printf("6.float=%-30.8g\n", -4.0000000378123);

ft_printf("7.float=%+30.8g\n", 4.0000000378123);
printf("7.float=%+30.8g\n", 4.0000000378123);

ft_printf("8.float=%+30.8g\n", -4.0000000378123);
printf("8.float=%+30.8g\n", -4.0000000378123);

ft_printf("9.float=% 30.8g\n", 4.0000000378123);
printf("9.float=% 30.8g\n", 4.0000000378123);

ft_printf("9.1float=% 030.8g\n", 4.0000000378123);
printf("9.1float=% 030.8g\n", 4.0000000378123);

ft_printf("10.float=% 30.8g\n", -4.0000000378123);
printf("10.float=% 30.8g\n", -4.0000000378123);

ft_printf("11.float=%030.8g\n", 4.0000000378123);
printf("11.float=%030.8g\n", 4.0000000378123);

ft_printf("12.float=%030.8g\n", -4.0000000378123);
printf("12.float=%030.8g\n", -4.0000000378123);

ft_printf("13.float=%+-'30.8g\n", 4.0000000378123);
ft_printf("14.float=%+0'30.8g\n", 4.0000000378123);
ft_printf("15.float=%+0'30.8g\n", -4.0000000378123);*/








//printf("2^-16383 + 2^-16445=%+030.16500Le\n", 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000016810515715560467534958588618491237615518802657851776016943186964737276840674625322243835220458678851122070241969944571332697904705841921805704456608575190815807140033014801936578295046521636340132141197304932697181507334924575774385740830279103376500158961238188773209635139278396495019928090496440607976911179008606629957159487777899515605188277319107381590018631696245446224009165269983011038503264654491500420810429874464246233219627992731859528270766996104761265005158360230997193810979079825322805334669957878461570709896689675964672514678526075222228373558092841635564706470770014263205266005950101046863460759525777758517191715137524344274051094007729352470304044866362190961937800611776081433906039547529809863310056587358833718953555405037432714999359691686034159775508320216932353823619904604318496055278255699795263486701883940605665832451931911728974845939970054053889583743427223507105404727773074094491890971732422145129930898370146052342335132897842440993992913877905225518568028548977475615507060050346975531180223125265926433879137971857793217905283578451532745612866265832944057512276174512598576663917783722779151007608232018282229797730247369485101693677845171981338386712403792529395445569020182044760862976693043088470206379867212977371639377279170341398973465640449021922073374535520928343601869172768173300229000482128736564952226285586573479300364902200106530653648893547065937251019963354245183622956173395126843312506682177664181018142885188820145861485145636220952616495392180978777630301867568327729586967061918308605612799433995111779172183402117049896865014261055679327939638901514909723497950143768788330404068886455773150061528729801435568155969944493853506210292008012224184097514389042110152734169118288109230349233569786230874218563676513687104267678800387021683792715464948800136192713070021811814149487587295387493030722856013180136566000335477270745910494361340822286438304457217121254646834531339493483646649108668246171791389310933205637005757419071342152210791056288101181752309408870017798753100791376649633546206908318197577034433919627384001253142926506911592924629720757002420172410601692428192481566912553865499217765761957322545871421294579915208401157761757541840332557546281954119393366514588459496933825007839374864557529713637825722252222412881354413835621676654532842349297491472851667680012195236821639344638653327024757708725197731446085381808413908382217443775378403435018245876232954698451161665306235963466555988816211221816492220373582813267850402883891569840352004525840161402021635021018787996621822397773387443522008852513287013268628280583836943773906077410203459032239075015342626076133445275414763685100800838694219629029230928911928984622682046685590359736838725133382006033751791934024901818101556334276007313227709521803500790553908022318488040515473655760501086611178972015150177560273783626964156977129194918457551418462945046748331968393496888272707746157865554713590280446041784145280279120371362622405162386937556147161964907786670034860560561329169133493661191461200140252019756479880580596613086151761908017754716488113618556866510543746480064723003252751798372793909950352995500995220232030542542772308600744249756865710694336865615695788662334557238731597118029410570047300744819622507801436032269944292125253791367639460200364481084108005405063785090715654838663139125229157793385901114976654376173437942108596904044229413402462630567078325552964551113899461828993399115934327243177439672101375785760904115976618017374148429942140031022583392507347120051793501873295713327522017174744776864142731499118448134136567964945524015165486460748254168469939579437583838L);


//ft_printf("2^-16383 + 2^-16400 + 2^-16445=%.16500Lf\n", 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000077970243279731540956660323229893075321713111013556894923009217084343016369716178904972564592893102647877005311006428971591117529501446139168327250630512804238516003429810496964011180138137612900496332928416621254871393728255163418851035117508730168179166041761702616950720879349808244896301048515140410213539565755650590701277918839253518949640232973265624453870404755789517128818509126751724997558650850078334793380783968607248756920244230596692499539535147387006372529285297956800765202014822058772511187797010573864159794465214524242977659282979594116400750374058200391512183362237130535253137251824518741296060420384246267539958883966295600554124120844621957814588119126977441801449750127551767208111947010686360501556285367876037858737506485304802844441655968717057054210647468172727695858056220602640176103964736810256360720931532056369840603800653451953936007393571730576356251931199510255840094713650114691398577111371761714896974646348490329830195335069265669733588917150064802511393448098715299918974027967013410374509225967487595440286098214197986471985976031560746876324998789051764434648450033774164470638108860062368892039458893855987335754170450498484285496635826762270648424488301104510642123892741058555316266277291864563339984686855201124266405238714685510176789908512078475222192237382366563869427764759790104732753385676065991402949659287327440941941731987233010682431604753739515049836163605246514151300176169199294454921246426668846972605430449802880297532381597666578695263659450005195105276352231167568916208219381688699626455276691048974135834053974069265124996123973407874131237404372839145582668652725129747126188792735754836653685666398606000580662976216834051281266714820788964403712196499701279083647733747693021382219174090326988974827120893832454080739820303632897242968729292231851666617774809727213749558065700939042163859471037106759212387249773600831472455422787208601367704638907677812655442808470302832437366313396839493212960617539826579990680903989428440191243723870900157211477394706814626504992153820951974762646902088854958718956581588049939383970754491188684483936252695721292855121205497097217058546209328202512720438006764374152052005414916943992259956920296019158004598128991515961163508414095420568447737999530979180931615259899782569521530101668815770384648945737185042570044796114131586458400427402234416503388808499678091737591509096328374532759808435857274314312076381304086997219225407949407217452919901866718291020321172633658376942464113090085007326702034409031852831642882646072901444115137384618214995620182644529996948465680163543740790718648236603475831217068030538615989632993867922406239947103482954004985560674442288000527446680448633788010448390427048970554810514435229424403147971888662552881759932574001198562546383271821647618789334741150974771767937110259384347308570700655769892330322311339931810792840465004113968490722228433318336756469872584549093721229224938038373733783592560725217692931427326515240653756123325890667517670095716434197701373465359636359474955871319469655098397104940640211594497942853185623363911038068350558153362765811089780705872124015442974479058773201818117981284419928875352398885979347813235201683573965071243654980117454262864941863172618822294990714490349231322653820792377887568260149203327596153999784165225083140457637996933675338576219819139855309937107288998464803368340030221723498630422904264428749016204307659375243229551573485888731907366089809544551732592503620095404054696516217536778657427843021022211339953176405934684622258547767801616499098736346326133923155928525170730495127504190900492309653045138364688742015378402206297755L);


//printf("number of digits=%zu", ft_strlen("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));

//printf("Min float80 subnormal=%.5000Lf\n", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000364519953188247460252840593361941981639905081569356L);


//printf("MAX float80 subnormal=2^-16383%.16500Lf\n", 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000016810515715560467531313389086608763012990396724232356200544136149043713496953644835215463531825281114312509533344117366135450557358638390703737470975953158645833631957424992931094472465343704661562915933499299137424885772358592363656800510485549849231567720438234600398619620740013448965159375073991312671051460740392367335091955422438671537109017565367693363679659793432091559797207976171010821740592362459222987171399028858716437700772693519604207099603508475622802075122846378247033497694501237976238476586608825337865515907985692656084674732203573753625914091716254765108282836059771866010607145592532979728982776761558022224373963841963807428289826161081443952840793942626151449215019195822715337506595144127692809821608565381070114515646717414183680882450397135501876220904065200461305312629749354623675679103182925273665561872619775932836453227097533206825998415508400713436442844892284606025405261688078301551023889507254247037304566086012418805104767187235768282976812180918316973041212455530690039683514763890305066270936062203338871948918779018218531825551177709600074820279681585040804910561672000946557930212227245109294604546560157293928775641238617080863399865723756222811207165122164296684559574561607329727010099097617063669414659885257633219722778275666512576773109974481063150982436847111697292838124290673716979744727766005938415115864624996978270216788014945873997698419143654425386488060525112966687429136791317580937851334134216323711200451719512725884540759418323613469678842251759359091527242338368906297649517495818971209549724215692867933696841724144587858738387357647512241422093515132754714541884188358395415451444958574925990528344194314769087675406536962425120880991485534539967046563124294655516979302903503167688034122531155546482793351237209496520145304577414737077255230412484151480822993970995051295861926590298176714557655875883752709126483303086305954542816139591191311018591019077958575768278532161965032763901062129657994344119004194970738502780516218340787660385829001007241693983620284560430098108835110786583462734820695131556131055000137463026062313504904901210885151948673601758653255628996991610176545001645288807169592226998428374894658209772077805587308534216599767017156431019619242577404427147157240375386095338767634351747700554151609228724800436139618664637827966544494146008050215942912114796113421670433705745540764609428624268263636299900912517512742271582568185213567828076616468743180318658421860631471719982643904124339452591045714089272247958659530406605313914968475980803800851167408101447541635488596492953085526933691768135574753900733434172542121186830241923217813521409194486763843377720889026140241450039708384351833426702110521084388650708068854496416043852702037113946039760088321502584458785965144558670976711790872457830810460136432834988287128547973158998882963996382519078026107161569892758048629925638729181712153653521850167268682530230920273925759094072557530017232023689455989576786960078317479778596982028150445372743889428985483515283144289432785963657952965824615485683376053861278147047674922431029135479409261975048607016190745033089509564309466047381730447913700732989588177321851784025638134358330859037284262618669894550413753873600188763299681912163833941924546371051276950138876420962175783704745109650473045026676548295781285568604998426473407984539497985297464988447361834760744566278790600498639024523060503527292850499580052118379811605381202222886350590119735822306895829147133950577465308109273549091515577295518079031852745944920187109249968931230109899518188008304871608582498121190668586991223552519592399498837400346000541141245318016403035437085L);



//printf("total no. of zeores=%zu\n", ft_strlen("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
//ft_printf("%.60f\n", 42.4242);
//printf("%.60f\n", 42.4242);
//ft_printf("Min float80 subnormal=2^-16445%.16500Lf\n", 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000036451995318824746025284059336194198163990508156935633437209804870283716886333977368095607086258272051972473473472035311019669856326220321699735080755898090054838225811779316785692252638056335597566215625659834107289403197935535272685912407999541728110155185383830460547687154224492953058597182682142626220675323554608440680792597537396882263389719028133546642119572938120002167626722920322774336390308456055297955188552992122553211711634876291384629300355138527501603132845785873465668580833490531237051939887039833085878399463225014686024594663765868704564236347102423971946588603575680671344779827642197362928177512955605368457612678466479085174632509237360395127227814159533660963994444034021170534884480219777636044379086876232490341169092945505322835546042550164710485109901552496948203761750727745215979248292641646728293792248343785221488475244616533404531408985349389010799994660849957929408670822251678980926263322841336335372303657106066727110161016969869085455268160934467855758235452864566704649092870630625875619302191928395746860797324007419326707925865842479032526017145025116520187337055564776698564030616718609883010220890087524042382938121214157585271795472816282327108859944585747150338528775954260248007917199819553441519165990035038288222003556659679587710909376884092310507637448820944563204842727161227981498363616605895952090835768872542325329552297498926405507629594382412784961938193820775459054611725479613404698176911656760942613207257273126074829376531404216196861030595291994214319374495660993373960630752183022438454753416779724620381266269034081670865175453863821550089560659554103929149526239278808471595331845354866664804805634075314283853293005224776842170509512647474546357548662147849415423151110386306843914252124393041905841223742229722846065374850524646486553697190990267605182875609969972107784730669801294274274395170323909647913676782217496309754197134381391626788785559991775284508827480465385881774472703067382348985029769028530013645504052272870939400583257885854573686549919562658630500834720876230660209033789194899209751908294216020103820394777720834006615191549726954365823050219109085766920481735349588941709767630848078374028138492275409420733154011152623348768159620874413022565584389125006072302057820130836741130234976124452147951709838486879883482032894412569087555652160818151512056388931125624153290844569340951461844692909011661106348755901648356069416294074897743797927398046747642434839120846918717692254465062843105653091908724772862559253835285450363605508542269195712463611332259048203019165883170843777122593678948464112948225870758354869856455108298805285787826984125562492745222350610924543423862023271204078275403339146131921891743158841366880194359662736634704314404430321364117756050306014368370639726903304174751873302009119675004967616181226147964529371240703987038908689155270514904657367453977649410948794796494381625766143469486520853080246963582567565857945684933190420538828438081803587871107744180754788011865195774162718963831698357082256365846545686437026186024335489381637207327725383454545130650115406757655106569705004135372053700679248802092173634073236733684480049044084139777417069654942470407997864518618221884735712575568194332840874860236762494678694836313804738564862395470156033183226127836520686997985394004066373116827311153406778416602407104315511403704103755855729393030840738435407021205519630505149599457413591699116765754784032793801120203473482925381507983204527948424275265017968529118631081782766384723202378700828622717633961951395137123031361943660215408305314569105840483725460251777651404602071129231519231764021467528682219668899153815L);


/*
printf("total length of digts is %zu\n", ft_strlen("36451995318824746025284059336194198163990508156935633437209804870283716886333977368095607086258272051972473473472035311019669856326220321699735080755898090054838225811779316785692252638056335597566215625659834107289403197935535272685912407999541728110155185383830460547687154224492953058597182682142626220675323554608440680792597537396882263389719028133546642119572938120002167626722920322774336390308456055297955188552992122553211711634876291384629300355138527501603132845785873465668580833490531237051939887039833085878399463225014686024594663765868704564236347102423971946588603575680671344779827642197362928177512955605368457612678466479085174632509237360395127227814159533660963994444034021170534884480219777636044379086876232490341169092945505322835546042550164710485109901552496948203761750727745215979248292641646728293792248343785221488475244616533404531408985349389010799994660849957929408670822251678980926263322841336335372303657106066727110161016969869085455268160934467855758235452864566704649092870630625875619302191928395746860797324007419326707925865842479032526017145025116520187337055564776698564030616718609883010220890087524042382938121214157585271795472816282327108859944585747150338528775954260248007917199819553441519165990035038288222003556659679587710909376884092310507637448820944563204842727161227981498363616605895952090835768872542325329552297498926405507629594382412784961938193820775459054611725479613404698176911656760942613207257273126074829376531404216196861030595291994214319374495660993373960630752183022438454753416779724620381266269034081670865175453863821550089560659554103929149526239278808471595331845354866664804805634075314283853293005224776842170509512647474546357548662147849415423151110386306843914252124393041905841223742229722846065374850524646486553697190990267605182875609969972107784730669801294274274395170323909647913676782217496309754197134381391626788785559991775284508827480465385881774472703067382348985029769028530013645504052272870939400583257885854573686549919562658630500834720876230660209033789194899209751908294216020103820394777720834006615191549726954365823050219109085766920481735349588941709767630848078374028138492275409420733154011152623348768159620874413022565584389125006072302057820130836741130234976124452147951709838486879883482032894412569087555652160818151512056388931125624153290844569340951461844692909011661106348755901648356069416294074897743797927398046747642434839120846918717692254465062843105653091908724772862559253835285450363605508542269195712463611332259048203019165883170843777122593678948464112948225870758354869856455108298805285787826984125562492745222350610924543423862023271204078275403339146131921891743158841366880194359662736634704314404430321364117756050306014368370639726903304174751873302009119675004967616181226147964529371240703987038908689155270514904657367453977649410948794796494381625766143469486520853080246963582567565857945684933190420538828438081803587871107744180754788011865195774162718963831698357082256365846545686437026186024335489381637207327725383454545130650115406757655106569705004135372053700679248802092173634073236733684480049044084139777417069654942470407997864518618221884735712575568194332840874860236762494678694836313804738564862395470156033183226127836520686997985394004066373116827311153406778416602407104315511403704103755855729393030840738435407021205519630505149599457413591699116765754784032793801120203473482925381507983204527948424275265017968529118631081782766384723202378700828622717633961951395137123031361943660215408305314569105840483725460251777651404602071129231519231764021467528682219668899153815964812531606968222607231942595218130543034572223679679292687630728923552788547142782438631107830670601244590393155281768403049315228131487458243508921305950151980025572043324832155514470975125100762233648012028880876356506546349468872327276239064590766702271086341623192103570072733693546571875690463948848950837941035318359596139945753778977755254619774647475181629750100914635619250327426455946458005816006983478170231943799213973476811504926872373490215642064630961387032012502777579804107726470143915791444243752525197667646704580085152976476241448144534960696851274398006295520756926486086815068790443764289774631751752051815479584595151590747012858384936940340076624101001835331415166841854607581750664815610189011330319510420990532971188374489844432308566427376064787878802852999035218550256124134710344666241715592090775384984751068112940290603342718033205664939350246217197176848044433518669466905252660607583321905318072325655018902937542595909474331403843353669733988168992536983021199161428916310053493353721580057799445291767358871939804092884746216945903030985523823769694423651860231309855078236176700511918890153514796597786761324496716420150595404382373039229030560790683446354402767725654259443299276549062629524755557509120238794246360214620433216314283656758518656549016934743434114062209075500900456895883239368146751261034644012237280581850483204752512668828752991205822530900331778836744323438127341239220429265549085482314732853495722109622898898009940265336293214647005520293915172930551962180656672512762374901292060984143389032109424889027922539246679410822732675635286538633434434864957624004099789959850520823107302770769652428462784025682851873655888766532454230472059434786129319642112934893741195657514867872048845023075123729239731191911256140687560945268927833216880303109005580256834554518984874011393152907434774619210259879053322362993988594489387420874873162887307110687527634493923668972362589970911769962532843066876354543618621794071916521552436506195717202321286241307854049305668050292332713755462533132874462858122199615650226545103738705816482147911391708709705090741587219676334254715505158014981911072162776206923470142349135273858121648344750020070994021229914395427839819849271813006696032901904951061957842485312997402627061067983385735239773652409412936952141886756327154470813722525510229819212511256751318392100741322860296214432621271458720224043142582192556064152802184450746540347901150755585133744227536171881983859311648101828170027941722798030282020865670812674533493413454963892393797764944190223010420679866005010454669500040571347269341476916780319866988453702999870673844073103374338281165148307453744907601716721529785950403514055725265230260512150937099005678735683852425745463850085677382639515326765492943564175657977715956384967191495778042162918921255410551471737237449917566696724590213751112887541253729183944179762430930282147033293860317993139495351613438927204090460650099589809789479976625455146641942620976652972426123679687660006291746558870908243635836538436589802775660312864296284763185729150458238958058260101327129778344186134682888329885473771745507968025731486842532941722850567778269273771580586471454035577212335120024954373394139988427825997101862157234379581542753405098110723490410464838062846088733942757188785904186928092883334235227812406989744418298793037942414558527767133213548706472510947206755723227884479087787788921162341316176084167322809874931413318849278602593243927812557861508918592034972126159164049990970677787399148579613058849346787620435155211905818982566246359578309278114211549921399869999362036311498523728025643148961517493264044287720082504285693383296981618501712654114267081137235583250590628715067128384609860311470603514915063160125325387933544995456670095275738108920480046524524521396887893929129382518883412981222352328611387339031535609672921042411909463505167697693050307623869083995925550431922360692794912244658266842033120812554318517563412345669139725893906015586508304374020455952076899961595975457118082036883181129189476616621158029195786364034303230416100180636967072212498263837152633888503074184694239734867470092339450362209015181857669427338368461268166381583450487827282412512798203101932235129591110298840022305716882168542822578732186317444509505523274289525381495452627798898243990285131322086386330706021355227520766615678724723251256742912688818491014163827036474514282328479933321571807940150363653616458881463557493661502090854571891872327863995858799416803703481411054047422984524978953692871939744961404456773012714035896658229110968329520211813435711369576078163183427557705604065699202616339664034841216798695426848436869083543736884379686835257236661214859479467478875727163608006964428164741135934661060892041795546771453745824379626646188830186286875100795112525560022417883462840197508639922839065135723259180534640806435215321548250748202390779907790070695880340296195621904167473597128840843245215986781788901864094514806867817331768249202768350024775234860935869637331554244918975754958515495270345383376943149530571640192150266707739109974432797600052906415115847071932263512716704397751410765526327361661176113949343256737438823655183185612089415529316291251367997115745789167410235872514289989469631824116505544042064163364874186561053330385457739601909496028500962085690852302287088948745775235125582819733929612639216561639633693884117634763886259524069015182734130370686433835502829622377291959017885993928766510865998492239942591452592404793843806578034980587190625290073394283162299977568998577121169227586830717074729355744992449784197881713384684717511253038609115892894008066372029204294899198702634159516608889754348273042974513623250526934820015248431712290784679105379131381154586266120249707308995151143019152816139292393293515010498592252745641078468181129383391613089431532051176517163804684622961938824442933704843685300968988127789731782849127985502452460634119184826382616940292452732916467073315946752134281587552738824383579602450640510158889185418011397716197432214050377972856694814558106533200089042159975979759073915120262140200120101347075367742276364775809181675078504851970653263910911714517637512376127394984685100090554800250960159855817693701796567811513065659525901019773983351850426376819823064484137221778956652903027962230041985260791431040700078745405482215823473895787419076942400727481338608233691306518076204361009674221579290719040619858762532542927481005014913765764511576139421431541604676635409021586558797152327419024652190612044660693995435376237453269257301351968475833102403001369008236966611120591489492515903721090781653063244581176729675960068856111942740131146840740541811184282840103004930033587050301900280487212275329820719538229025584586853416012880693465359149039189696272389562977393988534711551019333954374699288583646053249971063453730263564728856760186110311977064212243833134357208256222160645522427147562668961335127742514704508066065350492888477275980124150117639708989422759831098626780358600183566986993645900959533847966610129802053717740681727113599896621245073184945019268969821281470919288094309836935086280049529210899513358900892946097845649234235447752769274825864761270613428690709421136820281174870155241002571199674103957710112670611141230259423720618775007941625687469437425631850080526365777429066862274710511444737925672781712002353779026307058832211008928435045237483068464864135552613382236283996029971083220897986305897891731966709434578109722499468955961728119019245987541050221232627731661646957854925001791688432728730998876898269318290667599988068020564509132663190036411682160975457987265596336140953842411883537930043774357363620998602506078671956559415254590575394512979922359917893695680863804210613237189662157069244179283987801793513468553063862900533945505275994496303948455562249364447779953479766845703125"));
*/
//ft_printf("Min float80 subnormal=%.5000Lf\n", 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000168105157155604675313133890866087630129903967242323L);

//printf("Min float80 subnormal=%.5000Lf\n", 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000168105157155604675313133890866087630129903967242323L);
	return (0);
}
