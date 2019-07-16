#include "printf.h"
#include <unistd.h>
#include <stdio.h>

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
