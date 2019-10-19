/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:14:29 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 15:38:39 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*compose_pointer(char *str, t_block *blksk)
{
	blksk->width -= ft_strlen(str);
	if (blksk->width > 0)
	{
		if (blksk->flag & 8)
		{
			while (blksk->width--)
				ft_strcat_char(str, ' ');
		}
		else
		{
			ft_memmove(&str[blksk->width], &str[0], ft_strlen(&str[0]));
			while (blksk->width--)
				str[blksk->width] = ' ';
		}
	}
	return (str);
}

char	*comp_sni_helper(char *str, uintmax_t n, t_block *blksk)
{
	int i;
	int j;

	i = (blksk->flag & 16) ? help_one(str, blksk) : help_two(str, blksk);
	j = blksk->width - i;
	if (j > 0)
	{
		if (blksk->flag & 8)
			while (j--)
				str[i++] = ' ';
		if ((blksk->flag & 2) && (!(blksk->flag & 8)))
		{
			if ((blksk->flag & 16) && (blksk->type != 'u'))
				nest_one(str, blksk, i, j);
			else
				j = (n != 0) ? help_five(str, blksk, i, j)
					: help_six(str, blksk, j);
		}
		j = help_eight(str, blksk, n, help_seven(str, blksk, i, j));
	}
	return (str);
}

char	*compose_sni(char *str, uintmax_t n, t_block *blksk, const char *fmt)
{
	char tmp[23];

	if (blksk->precision == -2)
		blksk->precision = 0;
	ft_bzero(tmp, 23);
	if ((n == 0) && ((blksk->type == 'x') || (blksk->type == 'X')))
	{
		fmt += snippet_one(fmt, str, blksk);
		return (nest_hex(str, blksk));
	}
	if (blksk->precision == 0)
		fmt += snippet_four(fmt, blksk);
	if (blksk->type == 'p')
	{
		ft_strcat(str, group_d(ft_strrev(convert_base(n, tmp, blksk)), blksk));
		return (compose_pointer(str, blksk));
	}
	if (blksk->flag & 64)
		ft_strcat(str, group_d(ft_strrev(convert_base(n, tmp, blksk)), blksk));
	else
		ft_strcat(str, ft_strrev(convert_base(n, tmp, blksk)));
	if ((n == 0) && (blksk->flag & 128) && (!(blksk->flag & 16)))
		str[0] = '\0';
	return (comp_sni_helper(str, n, blksk));
}

void	string_hex_helper(char *str, t_block *blksk, uintmax_t n)
{
	if (blksk->type == 'x')
	{
		if ((blksk->flag & 16) && (n != 0))
			ft_strcpy(str, "0x");
		ft_strcpy(blksk->base, "0123456789abcdef");
	}
	if (blksk->type == 'o')
	{
		if ((blksk->flag & 16) && (n != 0))
			str[0] = '0';
		ft_strcpy(blksk->base, "012345678");
	}
	if (blksk->type == 'p')
	{
		ft_strcpy(str, "0x");
		ft_strcpy(blksk->base, "0123456789abcdef");
	}
	if (blksk->type == 'u')
		ft_strcpy(blksk->base, "0123456789");
}

void	string_hex(uintmax_t n, char *final, t_block *blksk, const char *fmt)
{
	char str[2048];

	(void)fmt;
	ft_bzero(str, 2048);
	if (blksk->type == 'X')
	{
		if ((blksk->flag & 16) && (n != 0))
			ft_strcpy(str, "0X");
		ft_strcpy(blksk->base, "0123456789ABCDEF");
	}
	string_hex_helper(str, blksk, n);
	ft_strcat(final, compose_sni(str, n, blksk, fmt));
}
