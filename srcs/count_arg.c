/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:17:16 by hlo               #+#    #+#             */
/*   Updated: 2019/10/13 12:17:58 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		count_percent(const char *str, int i)
{
	int consec_percent;
	int start;

	consec_percent = 0;
	start = i;
	while (str[i] == '%')
	{
		consec_percent++;
		i++;
	}
	return (consec_percent / 2);
}

int		count_arg(const char *str)
{
	int count;
	int i;
	int m;

	count = 0;
	i = 0;
	m = 0;
	while (str[i])
	{
		if ((str[i] == '%') && (str[i + 1] == '%'))
		{
			m = count_percent(str, i);
			count += m;
			i += m * 2;
			continue;
		}
		else if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}
