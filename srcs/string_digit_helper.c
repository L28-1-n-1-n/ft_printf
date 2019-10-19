/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_digit_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:56:30 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 15:00:00 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

int		no_zero_nor_space(char *str, int j)
{
	ft_memmove(&str[j], &str[0], ft_strlen(str));
	j -= 1;
	while (j >= 0)
		str[j--] = ' ';
	return (j);
}

int		di_nosign(char *str, int j, t_block *blksk, int i)
{
	ft_memmove(&str[j], &str[0], i);
	j -= 1;
	if ((blksk->flag & 2) && (blksk->flag & 32) && (!(blksk->flag & 128)))
	{
		while (j > 0)
			str[j--] = '0';
		str[0] = ' ';
	}
	else
	{
		if ((blksk->orig) || (blksk->flag & 128))
			while (j >= 0)
				str[j--] = ' ';
		else
			while (j >= 0)
				str[j--] = '0';
	}
	return (j);
}

int		zero_not_space(char *str, int j, t_block *blksk, intmax_t n)
{
	if ((blksk->flag & 2) && (!(blksk->flag & 32)))
	{
		if ((n == 0) && (blksk->orig != 0))
			while (j >= 0)
				str[j--] = ' ';
		else
			while (j >= 0)
				str[j--] = '0';
	}
	else
		while (j >= 0)
			str[j--] = ' ';
	return (j);
}

int		zero_di_one(char *str, int j, t_block *blksk, intmax_t n)
{
	if ((blksk->flag & 2) && (blksk->flag & 32))
	{
		if (n != 0)
			while (j > 0)
				str[j--] = '0';
		else
		{
			if (blksk->orig)
				while (j > 0)
					str[j--] = ' ';
			else
				while (j > 0)
					str[j--] = '0';
			str[0] = ' ';
		}
	}
	else
		j = zero_not_space(str, j, blksk, n);
	return (j);
}

int		case_n_zero(char *str, int j, intmax_t n, t_block *blksk)
{
	if (str[0])
	{
		ft_memmove(&str[j], &str[0], ft_strlen(str));
		j -= 1;
		j = zero_di_one(str, j, blksk, n);
	}
	else
		while (j >= 1)
		{
			ft_strcat_char(str, ' ');
			j--;
		}
	return (j);
}
