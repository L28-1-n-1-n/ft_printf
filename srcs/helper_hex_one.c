/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_hex_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:53:11 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 15:42:47 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		help_five(char *str, t_block *blksk, int i, int j)
{
	ft_memmove(&str[j], &str[0], i);
	j -= 1;
	if (!(blksk->flag & 128))
	{
		while (j >= 0)
			str[j--] = '0';
	}
	else
	{
		while (j >= 0)
			str[j--] = ' ';
	}
	return (j);
}

int		help_six(char *str, t_block *blksk, int j)
{
	if (!(blksk->flag & 128))
		while (j >= 0)
			str[j--] = '0';
	return (j);
}

int		help_seven(char *str, t_block *blksk, int i, int j)
{
	if ((!(blksk->flag & 2)) && (!(blksk->flag & 8)))
	{
		ft_memmove(&str[j], &str[0], i);
		j -= 1;
		while (j >= 0)
			str[j--] = ' ';
	}
	return (j);
}

int		help_eight(char *str, t_block *blksk, uintmax_t n, int j)
{
	if (j && (n == 0) && (!((blksk->flag & 16) && (blksk->type != 'u'))))
	{
		if (ft_strlen(str) && (blksk->flag & 2) && (!(blksk->flag & 8)))
			ft_memmove(&str[j], &str[0], ft_strlen(str));
		j -= 1;
		while (j >= 0)
			str[j--] = ' ';
	}
	return (j);
}

char	*nest_hex(char *str, t_block *blksk)
{
	if (!(blksk->flag & 2))
		snippet_two(str, blksk);
	else
		snippet_three(str, blksk);
	return (str);
}
