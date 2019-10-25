/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:30:24 by hlo               #+#    #+#             */
/*   Updated: 2019/10/25 05:55:56 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdint.h>
#include <stdlib.h>

int		treat_hex(const char *fmt, char *final, va_list ap, t_block *blksk)
{
	uintmax_t n;

	n = add_unsigned_modifier(ap, blksk);
	string_hex(n, final, blksk, fmt);
	return (0);
}

int		treat_num(char *final, va_list ap, t_block *blksk)
{
	intmax_t n;

	if (blksk->width == -1)
		blksk->width = va_arg(ap, int);
	if (blksk->precision == -1)
		blksk->precision = va_arg(ap, int);
	n = add_modifier(ap, blksk);
	blksk->precision = (blksk->precision == -2) ? 0 : blksk->precision;
	blksk->orig = blksk->precision;
	string_digit(n, final, blksk);
	return (0);
}

void	mod_float_size(va_list ap, t_block *blksk)
{
	if (blksk->width == -1)
		blksk->width = va_arg(ap, int);
	if (blksk->precision == -1)
		blksk->precision = va_arg(ap, int);
	if (blksk->width < 0)
	{
		blksk->flag |= 8;
		blksk->width *= -1;
	}
	if (blksk->precision < 0)
		blksk->precision = 6;
}

int		treat_float(char *final, va_list ap, t_block *blksk)
{
	double		n;
	long double	long_n;
	uint64_t	word[2];

	n = 0;
	long_n = 0;
	mod_float_size(ap, blksk);
	if ((blksk->modifier == l) || (blksk->modifier == 0))
	{
		n = va_arg(ap, double);
		ft_memcpy(&word, &n, sizeof(word));
	}
	else if (blksk->modifier == L)
	{
		long_n = va_arg(ap, long double);
		ft_memcpy(&word, &long_n, sizeof(word));
	}
	return (decode_float(word, final, blksk));
}

int		treat_arg(const char *fmt, char *final, va_list ap, t_block *blksk)
{
	if (blksk->str)
		if ((blksk->str[0] == '%') && (blksk->type == NA))
			ft_strcat(final, "%");
	if (blksk->type == 'c')
		return (treat_char(final, ap, blksk));
	if (blksk->type == 'T')
		return (treat_plain_text(fmt, final, blksk));
	if (blksk->type == 's')
		return (treat_string(final, ap, blksk));
	if (blksk->type == 'x' || blksk->type == 'X' || blksk->type == 'o'
			|| blksk->type == 'u' || blksk->type == 'p')
		return (treat_hex(fmt, final, ap, blksk));
	if ((blksk->type == 'd') || (blksk->type == 'i'))
		return (treat_num(final, ap, blksk));
	if (blksk->type == 'f' || blksk->type == 'F' || blksk->type == 'e'
			|| blksk->type == 'E' || blksk->type == 'g' || blksk->type == 'G')
		return (treat_float(final, ap, blksk));
	if (blksk->type == 'b' || blksk->type == 'K' || blksk->type == 'D')
		return (treat_bin(final, ap, blksk));
	if ((blksk->type == 'r') || (blksk->type == 'R'))
		return (treat_nonpri(final, ap, blksk, fmt));
	if (blksk->type == 'k')
		return (treat_time(final));
	return (0);
}
