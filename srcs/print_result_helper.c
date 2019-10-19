/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:43:09 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 14:44:50 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		loop_big_int(uint64_t raw[31], int z)
{
	while (z > 8)
	{
		within_row(raw, 8);
		z -= 8;
	}
	return (z);
}

void	print_result_helper(char *str, t_float *fnum, unsigned int bit)
{
	unsigned int	i;
	int				digit;

	i = 0;
	while (str[i] == '0')
		i++;
	digit = ft_strlen(&str[i]) - 2;
	ft_memmove(&str[0], &str[i], digit);
	if (bit == 64)
		ft_memset(&str[digit], '\0', 640 - digit);
	else
		ft_memset(&str[digit], '\0', 5270 - digit);
	ft_strcpy(fnum->big_str, str);
}
