#include "printf.h"

void	parse(const char *fmt, va_list ap)
{
	int i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			parse_remain(fmt, i, ap);
		}
		else
			while (fmt[i] && fmt[i] != '%')
				i++;
	}
}
