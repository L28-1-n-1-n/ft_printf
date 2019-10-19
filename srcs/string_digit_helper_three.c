/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_digit_helper_three.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:13:25 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 15:13:44 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	digit_two(char *str, intmax_t n, t_block *blksk)
{
	if (n > 0)
		blksk->precision -= 1;
	if (str[0] == '-')
	{
		if (blksk->precision > 0)
		{
			ft_memmove(&str[1 + blksk->precision], &str[1], ft_strlen(&str[1]));
			while (blksk->precision--)
				str[1 + blksk->precision] = '0';
		}
	}
	else if (blksk->precision > 0)
		while (blksk->precision--)
			ft_strpcat_char(str, '0');
}

int		nest(char *str, intmax_t n, t_block *blksk)
{
	if (blksk->flag & 4)
	{
		if (n > 0)
			blksk->precision -= 1;
		if (blksk->precision > 0)
		{
			ft_memmove(&str[1 + blksk->precision], &str[1], ft_strlen(&str[1]));
			while (blksk->precision--)
				str[1 + blksk->precision] = '0';
		}
	}
	else
		digit_two(str, n, blksk);
	return (ft_strlen(str));
}
