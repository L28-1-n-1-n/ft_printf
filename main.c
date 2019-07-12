#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, &s, 1);
		s++;
	}
}
void	vafunc(char *fmt, ...)
{
	va_list ap;
	char *s;

	va_start(ap, fmt);
	printf("we got to vafunc\n");
	printf("here we print fmt: %s", fmt);
	while (*fmt)
	{
		if (*fmt == 's')
		{
			s = va_arg(ap, char *);
			ft_putstr(s);
			break;
		}
	}
	va_end(ap);
}

void	ft_printf(char *s, ...)
{
	int i;

	i = 0;
	while (*s != '%')
		s++;
	vafunc(s);
}
int		main()
{
	char s[400];

	ft_strcpy(s, "hello");
	ft_printf("This is the sentence %s", s);
	return (0);	
}
