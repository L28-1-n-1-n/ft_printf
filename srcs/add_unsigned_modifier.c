/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_unsigned_modifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:15:22 by hlo               #+#    #+#             */
/*   Updated: 2019/10/13 12:16:45 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

uintmax_t	add_unsigned_modifier(va_list ap, t_block *blksk)
{
	uintmax_t n;

	if (blksk->type == 'p')
	{
		n = va_arg(ap, unsigned long long);
		return (n);
	}
	if (blksk->modifier == ll)
		n = va_arg(ap, unsigned long long);
	else if (blksk->modifier == l)
		n = va_arg(ap, unsigned long);
	else if (blksk->modifier == L)
		n = va_arg(ap, long double);
	else if (blksk->modifier == z)
		n = va_arg(ap, size_t);
	else
		n = va_arg(ap, unsigned int);
	if (blksk->modifier == hh)
		n = (unsigned char)n;
	if (blksk->modifier == h)
		n = (unsigned short)n;
	return (n);
}
