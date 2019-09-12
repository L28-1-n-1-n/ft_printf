/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:03:56 by hlo               #+#    #+#             */
/*   Updated: 2019/01/19 17:34:43 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
	ft_memmove(&dest[ft_strlen(src)], &dest[0], ft_strlen(dest));
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}
