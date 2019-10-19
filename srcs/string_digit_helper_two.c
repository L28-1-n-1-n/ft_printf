/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_digit_helper_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:00:21 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 15:13:10 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

char	*group_d(char *str, t_block *blksk)
{
	int i;
	int count;
	int end;

	if (!(blksk->flag & 64))
		return (str);
	count = 2;
	end = 0;
	if ((str[0] == '-') || (str[0] == '+'))
		end = 1;
	i = ft_strlen(str) - 1;
	while (i > end)
	{
		if (!count)
		{
			ft_memmove(&str[i + 1], &str[i], ft_strlen(&str[i]));
			str[i] = ',';
			count = 3;
		}
		i--;
		count--;
	}
	return (str);
}

int		valueofi(char *str, intmax_t n, t_block *blksk)
{
	int i;

	if ((blksk->flag & 4) && (n >= 0))
	{
		str[0] = '+';
		if (!((n == 0) && (blksk->flag & 128)))
			i = ft_strlen(group_d(ft_itoamax(n, &str[1]), blksk));
		else
			i = ft_strlen(str);
	}
	else if (!((n == 0) && (blksk->flag & 128)))
		i = ft_strlen(group_d(ft_itoamax(n, str), blksk));
	else
		i = ft_strlen(str);
	if ((blksk->precision > 0) && (i > 0))
		blksk->precision -= (i - 1);
	return (i);
}

void	empty_width_or_zero_start(char *str, t_block *blksk, intmax_t n)
{
	if ((n == 0) && (!(blksk->width)))
	{
		if (blksk->orig > 1)
			str[1] = '0';
		else if (ft_strlen(str) == 0)
			ft_strpcat_char(str, ' ');
	}
	if (str[0] == '0')
	{
		ft_strpcat_char(str, ' ');
		if (str[ft_strlen(str) - 1] == ' ')
			str[ft_strlen(str) - 1] = '\0';
	}
}

void	dash_and_non_neg(char *str, t_block *blksk, int width, intmax_t n)
{
	if ((blksk->flag & 8) && (n > 0))
	{
		if ((str[0] != '+') && (str[0] != '-') && (str[0] != ' '))
		{
			ft_memmove(&str[1], &str[0], ft_strlen(str));
			str[0] = ' ';
			if (str[ft_strlen(str) - 1] == ' ')
				str[ft_strlen(str) - 1] = '\0';
		}
	}
	else
	{
		if ((!(blksk->flag & 4)) && (blksk->width == 0)
				&& (n > 0) && (str[0] != ' '))
		{
			ft_memmove(&str[1], &str[0], ft_strlen(str));
			str[0] = ' ';
			str[ft_strlen(str)] = '\0';
		}
		else if (((ft_strlen(str) < (size_t)width))
				|| ((str[0] != ' ') && (str[0] != '+') && (str[0] != '-')))
			if (str[0] != ' ')
				ft_strpcat_char(str, ' ');
	}
}

char	*digit_space(char *str, int width, t_block *blksk, intmax_t n)
{
	if (blksk->flag & 32)
	{
		empty_width_or_zero_start(str, blksk, n);
		if ((str[0] == '0') && (n != 0))
			str[0] = ' ';
		else
			dash_and_non_neg(str, blksk, width, n);
	}
	return (str);
}
