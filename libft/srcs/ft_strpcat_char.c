/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpcat_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:03:56 by hlo               #+#    #+#             */
/*   Updated: 2019/01/19 17:34:43 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpcat_char(char *dest, const char c)
{
	ft_memmove(&dest[1], &dest[0], ft_strlen(dest));
	dest[0] = c;
	ft_strcat(dest, "\0");
	return (dest);
}
