/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 08:27:38 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 08:30:21 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int	base_u(char *tmp, t_block *blksk, uintmax_t n, unsigned int i)
{
	while (n > 0)
	{
		tmp[i] = blksk->base[n % 10];
		n /= 10;
		i++;
	}
	return (i);
}

char			*convert_base(uintmax_t n, char *tmp, t_block *blksk)
{
	unsigned int k;
	unsigned int i;
	unsigned int mask;
	unsigned int step;

	i = 0;
	k = 0;
	tmp[0] = '0';
	if (ft_strlen(blksk->base) == 10)
	{
		i = base_u(tmp, blksk, n, i);
		return (tmp);
	}
	mask = (ft_strlen(blksk->base) < 10) ? 7 : 15;
	step = (ft_strlen(blksk->base) < 10) ? 3 : 4;
	while (n > 0)
	{
		k = n & mask;
		n = n >> step;
		tmp[i] = blksk->base[k];
		i++;
	}
	return (tmp);
}
