#include "printf.h"

void	ft_printf(const char *fmt, ...)
{
	va_list ap;

	va_start(ap,fmt);
	parse(fmt, ap);
	va_end(ap);
}
