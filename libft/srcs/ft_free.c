#include "libft.h"
#include <stdlib.h>

int ft_free(void *var)
{
	free(var);
	return (0);
}
