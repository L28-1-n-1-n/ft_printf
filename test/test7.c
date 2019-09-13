#include <stdlib.h>
#include <stdio.h>
#include "../libft/includes/libft.h"
int main()
{
	char **product;
	int i;

	product = 0;
	i = 0;
	while (i < 63 + 1)
	{
		if (!(product[i] = (char *)ft_strnew(16427)))
			return (0);
		i++;
	}
	printf("size of product is %lu\n", sizeof(product));
	return (0);
}
