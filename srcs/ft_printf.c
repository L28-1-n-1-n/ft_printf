#include "printf.h"
#include <stdio.h>
void	ft_printf(const char *fmt, ...)
{
	va_list ap;
	int success;

	success = 0;
	va_start(ap,fmt);
	success = parse(fmt, ap);
	va_end(ap);
}
