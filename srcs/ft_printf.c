/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 09:10:00 by hlo               #+#    #+#             */
/*   Updated: 2019/10/13 09:11:35 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		success;

	success = 0;
	va_start(ap, fmt);
	success = parse(fmt, ap);
	va_end(ap);

	return (success);
}
