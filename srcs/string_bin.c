/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:07:10 by hlo               #+#    #+#             */
/*   Updated: 2019/10/25 02:54:42 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

char	*mod_bin(char *str, t_block *blksk)
{
	int i;

	i = 0;
	i = blksk->width - ft_strlen(str);
	if ((i > 0) && (blksk->flag & 8))
		while (i--)
			ft_strcat_char(str, ' ');
	if ((i > 0) && (!(blksk->flag & 8)))
		while (i--)
			ft_strpcat_char(str, ' ');
	if (blksk->flag & 16)
		ft_strcat_char(str, 'b');
	return (str);
}

void	edge_bin(char *final, char *str, t_block *blksk)
{
	ft_strcat(str, "-10000000000000000000000000000000");
	ft_strcat(str, "00000000000000000000000000000000");
	ft_strcat(final, mod_bin(str, blksk));
}

void	mod_bflags(intmax_t n, char *final, t_block *blksk)
{
	if (blksk->flag & 32)
	{
		ft_strcat_char(final, ' ');
		blksk->width -= 1;
	}
	if ((blksk->flag & 4) && (n > 0))
	{
		ft_strcat_char(final, '+');
		blksk->width -= 1;
	}
	if (n < 0)
	{
		n = -1 * n;
		ft_strcat_char(final, '-');
		blksk->width -= 1;
	}
}

void	string_bin(intmax_t n, char *final, t_block *blksk)
{
	char	str[2048];
	int		i;

	ft_bzero(str, 2048);
	i = 0;
	if ((n < (long long)(0x8000000000000000)) || (n > (long long)
				(0x7FFFFFFFFFFFFFFF)) || (blksk->modifier == L))
		return ;
	if (n == (long long)(0x8000000000000000))
	{
		edge_bin(final, str, blksk);
		return ;
	}
	mod_bflags(n, final, blksk);
	if (blksk->flag & 32)
		while (n > 0)
		{
			if (n & 1)
				ft_strcat_char(str, '1');
			else
				ft_strcat_char(str, '0');
			n >>= 1;
		}
	ft_strcat(final, mod_bin(ft_strrev(str), blksk));
}

int		treat_bin(char *final, va_list ap, t_block *blksk)
{
	intmax_t n;

	if ((blksk->type == 'K') || (blksk->type == 'D'))
		return (treat_encrypt(final, ap, blksk));
	n = add_modifier(ap, blksk);
	string_bin(n, final, blksk);
	return (0);
}
