/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:56:25 by hlo               #+#    #+#             */
/*   Updated: 2019/01/19 15:56:27 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int k;

	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
			return ;
		}
		else
			k = -1 * n;
	}
	else
		k = n;
	if ((k / 10) != 0)
	{
		ft_putnbr(k / 10);
		ft_putnbr(k % 10);
	}
	else
		ft_putchar(k + '0');
}
