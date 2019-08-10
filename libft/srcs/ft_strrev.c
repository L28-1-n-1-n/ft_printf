/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:05:51 by hlo               #+#    #+#             */
/*   Updated: 2019/01/24 23:43:20 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		total;
	char	tmp;

	if (!str)
		return (NULL);
	total = ft_strlen(str) - 1;
	i = 0;
	while (i <= total / 2)
	{
		tmp = str[i];
		str[i] = str[total - i];
		str[total - i] = tmp;
		i++;
	}
	return (str);
}
