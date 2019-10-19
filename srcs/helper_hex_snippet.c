/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_hex_snippet.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:50:03 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 12:50:48 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int	snippet_one(const char *fmt, char *str, t_block *blksk)
{
	unsigned int count;

	fmt += 1;
	count = 2;
	while (*fmt && !(ft_strchr(".xX%", *fmt)))
	{
		fmt++;
		count++;
	}
	fmt++;
	blksk->precision = ft_atoi(fmt);
	if (!(blksk->flag & 128))
		ft_strcat_char(str, '0');
	while (blksk->precision--)
		ft_strcat_char(str, '0');
	return (count);
}

void			snippet_two(char *str, t_block *blksk)
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
}

void			snippet_three(char *str, t_block *blksk)
{
	blksk->width -= ft_strlen(str);
	if ((blksk->width > 0) && (!(blksk->flag & 128)) && (!(blksk->flag & 8)))
	{
		while (blksk->width--)
			ft_strpcat_char(str, '0');
	}
	else if (blksk->width > 0)
	{
		if (!(blksk->flag & 8))
		{
			while (blksk->width--)
				ft_strpcat_char(str, ' ');
		}
		else
		{
			while (blksk->width--)
				ft_strcat_char(str, ' ');
		}
	}
}

unsigned int	snippet_four(const char *fmt, t_block *blksk)
{
	unsigned int count;

	fmt += 1;
	count = 2;
	while (*fmt && !(ft_strchr(".xXuo%", *fmt)))
	{
		fmt++;
		count++;
	}
	fmt++;
	blksk->precision = ft_atoi(fmt);
	return (count);
}
