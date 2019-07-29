#include "printf.h"
#include <stdio.h>
void	ft_printf(const char *fmt, ...)
{
	va_list ap;
	int success;
//	char *str;

	success = 0;
	va_start(ap,fmt);
//	str = va_arg(ap, char *);
	//printf("first str %s\n", str);
	success = parse(fmt, ap);
	va_end(ap);
}
