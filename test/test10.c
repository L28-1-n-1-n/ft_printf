#include <stdio.h>
#include <stdlib.h>

int ft_free(void *num, void *str)
{
	free(num);
	free(str);
	printf("free complete\n");
	return (0);
}

int main()
{
	char *str;
	int *num;

	if (!(str = malloc(sizeof(char) * 10)))
		return (0);
	if (!(num = malloc(sizeof(char) * 15)))
		return (0);
	return(ft_free(num, str));
	return (0);
}
