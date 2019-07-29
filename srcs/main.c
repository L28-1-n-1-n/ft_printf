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
//	ft_printf("12345%s", s);
//	ft_printf("%dc12 %% sdfw % sdf %%%%asdfadf %%%%%\n");
//	ft_printf("THIS_IS_A_TEST %23$   ' +- 07hf%%%14.*  % 54.222Lc %% %*$970.25hhd%%we \n");
	ft_printf("THIS_IS_A_TEST%% %c 123 %c and %c then finally %s\n", 'm', 'a', 'b', "Hello World!\n");
	return (0);
}
