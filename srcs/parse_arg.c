/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:08:27 by hlo               #+#    #+#             */
/*   Updated: 2019/10/13 14:13:09 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	flags_two(char *str, t_block *blksk)
{
	if (ft_strchr_arg(--str, '.'))
	{
		blksk->flag |= 128;
		str += 1 + ft_strchr_arg(str, '.');
		if (*str == '*')
			blksk->precision = -1;
		else
			blksk->precision = ft_atoi((char *)str);
	}
}

void	flags_one(char *str, t_block *blksk)
{
	if ((*str > '0') && (*str <= '9'))
		blksk->width = ft_atoi(str);
	if (*str == '*')
		blksk->width = -1;
	if (ft_isalpha(*str))
	{
		str += 1;
		if (*str != '.')
		{
			str -= 1;
			if (ft_strchr_arg(--str, '.'))
			{
				blksk->flag |= 128;
				str += 1 + ft_strchr_arg(str, '.');
				if (*str == '*')
					blksk->precision = -1;
				else
					blksk->precision = ft_atoi((char *)str);
			}
		}
		else
			str -= 1;
	}
	else
		flags_two(str, blksk);
}

char	*check_fwp(const char *fmt, unsigned int k, t_block *blks)
{
	char *str;

	str = (blks[k].order > 0) ? (char *)(fmt + blks[k].pos
			+ ft_strchr_arg(fmt + blks[k].pos, '$'))
		: (char *)(fmt + blks[k].pos + 1);
	while (*str && !(ft_strchr("*.cdixXpeEfFgGousbrk%hlLz123456789", *str)))
	{
		if (*str == '+')
			blks[k].flag |= 4;
		if (*str == '-')
			blks[k].flag |= 8;
		if (*str == '#')
			blks[k].flag |= 16;
		if (*str == ' ')
			blks[k].flag |= 32;
		if (*str == '0')
			blks[k].flag |= 2;
		if (*str == '\'')
			blks[k].flag |= 64;
		str++;
	}
	flags_one(str, &blks[k]);
	if (*str == '%')
		str++;
	return (str);
}

void	check_order(const char *fmt, unsigned int k, t_block *blks)
{
	if (ft_strchr_arg(fmt + blks[k].pos, '$'))
		blks[k].order = ft_atoi(fmt + blks[k].pos + 1);
}

int		parse_arg(const char *fmt, unsigned int k, t_block *blks)
{
	check_order(fmt, k, blks);
	return (check_type(check_len(check_fwp(fmt, k, blks), k, blks), k, blks));
}
