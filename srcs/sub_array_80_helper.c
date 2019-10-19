/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_array_80_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:49:36 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 15:51:44 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int	aggre_help_80(char **product,
		unsigned int i, unsigned int j, unsigned int carry)
{
	if (product[i - 1][j] > '9')
	{
		product[i - 1][j] -= 10;
		carry += 1;
	}
	return (carry);
}

unsigned int	save_line(unsigned int tmp,
		char **product, unsigned int i, unsigned int j)
{
	tmp = tmp % 10;
	product[i - 1][j] += tmp;
	return (tmp);
}

void			aggregate_80(char **product)
{
	int				i;
	int				j;
	unsigned int	carry;
	unsigned int	tmp;

	i = 62;
	j = 16425;
	carry = 0;
	while (i > 0)
	{
		while (product[i][j])
		{
			tmp = (product[i][j] - '0') * 2;
			product[i - 1][j] += carry + '0';
			carry = tmp / 10;
			tmp = save_line(tmp, product, i, j);
			carry = aggre_help_80(product, i, j, carry);
			j--;
		}
		if (carry)
			product[i - 1][j] += carry + '0';
		carry = 0;
		j = 16425;
		i--;
	}
}
