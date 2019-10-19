/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 10:09:15 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 08:26:56 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	check_buff(char *final, char *str, size_t len)
{
	unsigned int final_len;
	unsigned int limit;

	limit = (unsigned int)(FLEN / (unsigned int)5 * (unsigned int)4);
	final_len = (unsigned int)ft_strlen(final);
	if (len + final_len < limit)
		ft_strncat(final, &str[0], len);
	else
	{
		output_final(final, 0);
		if (ft_strlen(str) < limit)
			ft_strncat(final, str, len);
		else
			output_final(str, 0);
	}
}
