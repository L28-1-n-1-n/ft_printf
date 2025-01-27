/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoamax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:53:36 by hlo               #+#    #+#             */
/*   Updated: 2019/10/13 12:19:45 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_findlen(intmax_t n)
{
	intmax_t	num;
	int			i;

	num = n;
	i = 0;
	if (n == 0)
		return (1);
	while (num)
	{
		num /= 10;
		i++;
	}
	return (n < 0 ? i + 1 : i);
}

char		*ft_itoamax(intmax_t n, char *str)
{
	int			length;
	intmax_t	orig_num;

	orig_num = n;
	length = ft_findlen(n);
	while (length--)
	{
		str[length] = (n < 0) ? (n % 10) * -1 + 48 : (n % 10) + 48;
		n /= 10;
	}
	if (orig_num < 0)
		str[0] = '-';
	return (str);
}
