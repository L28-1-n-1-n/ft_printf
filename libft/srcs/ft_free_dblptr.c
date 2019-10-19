#include "libft.h"
#include <stdlib.h>

int ft_free_dblptr(char **var, int return_value)
{
	int i;

	i = 0;
	while (var[i] != 0)
	{
		free(var[i]);
		i++;
	}
	free(var);
	return (return_value);
}
