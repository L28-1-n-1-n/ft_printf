/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dblptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:11:45 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 16:11:56 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_free_dblptr(char **var, int return_value)
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
