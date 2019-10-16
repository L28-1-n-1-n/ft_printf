/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 09:55:16 by hlo               #+#    #+#             */
/*   Updated: 2019/10/13 10:00:50 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
#include <stdio.h>
void	init_blocks(t_block *blks, int total)
{
	total = total - 1;
	while (total >= 0)
	{
		blks[total].order = 0;
		blks[total].flag = 0;
		blks[total].width = 0;
		blks[total].orig = 0;
		blks[total].modifier = NA;
		blks[total].precision = -2;
		blks[total].type = NA;
		blks[total].str = 0;
		blks[total].pos = 0;
		ft_bzero(blks[total].base, 16);
		total--;
	}
}

void	p_help(const char *fmt, unsigned int i, unsigned int k, t_block *blks)
{
	while (fmt[i])
	{
		while (fmt[i] && (fmt[i] != '%'))
			i++;
		if ((fmt[i] == '%') && (fmt[i + 1] == '%'))
		{
			blks[k].str = "%";
			blks[k].pos = i;
			k++;
			i += 2;
		}
		else if (fmt[i] == '%')
		{
			blks[k].pos = i;
			if ((k > 0) && (blks[k - 1].str) && (blks[k - 1].type == 'c'))
				blks[k].type = 'T';
			else
				parse_arg(fmt, k, blks);
			k++;
			i++;
			while (fmt[i] && (fmt[i] != '%'))
				i++;
		}
	}
}

int		parse(const char *fmt, va_list ap)
{
	unsigned int	i;
	unsigned int	m;
	unsigned int	k;
	t_block			*blks;

	i = 0;
	k = 0;
	m = count_arg(fmt);
	if (!(blks = (t_block *)malloc(sizeof(t_block) * m)))
		return (ft_free(blks, -1));
	init_blocks(blks, m);
	p_help(fmt, i, k, blks);
	m = coms(fmt, ap, blks, m);
	free(blks);
	return (m);
}
