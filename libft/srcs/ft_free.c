#include "libft.h"
#include <stdlib.h>

int ft_free(void *var, int return_value)
{
	free(var);
	return (return_value);
}
