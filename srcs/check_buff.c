/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 10:09:15 by hlo               #+#    #+#             */
/*   Updated: 2019/10/13 10:09:45 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	check_buff(char *final, char *str, size_t len)
{
	unsigned int final_len;
	unsigned int loop;
	unsigned int limit;

	limit = (unsigned int)(FLEN / (unsigned int)5 * (unsigned int)4);
	final_len = ft_strlen(final);
	printf("we got to check\n");
	printf("final is %s\n", final);
	loop = 0;
	if (len + final_len >= limit)
	{
		printf("we are here\n");
		while ((loop < len) && (len + final_len >= limit))
		{
			ft_strncat(final, &str[loop], limit - final_len);
			loop += limit - final_len;
			output_final(final, 0);
			final_len = ft_strlen(final);
		}
		if (len + final_len < limit)
			ft_strncat(final, &str[loop], len);
	}
	else
	{
		printf("we are here2\n");
		ft_strncat(final, str, len);
	}
	printf("we exit check\n");
}
