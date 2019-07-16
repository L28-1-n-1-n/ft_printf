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
	ft_printf("12345%s", s);
	return (0);
}
