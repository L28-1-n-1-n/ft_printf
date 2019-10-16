/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_array_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 06:37:50 by hlo               #+#    #+#             */
/*   Updated: 2019/10/16 06:39:42 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int	sphfour(unsigned int power, t_float *fnum)
{
	fnum->remain >>= 1;
	power--;
	return (power);
}

void			sphthree(unsigned int carry, unsigned int offset, t_float *fnum)
{
	if (carry)
		fnum->big_str[offset - 1] += carry;
}

unsigned int	sphtwo(unsigned int carry, unsigned int offset, t_float *fnum, int i)
{
	carry = 0;
	if (fnum->big_str[offset + i] > '9')
	{
		carry = 1;
		fnum->big_str[offset + i] -= 10;
	}
	return (carry);
}

unsigned int	sum_power_helper(unsigned int power, char product[1080][1000], t_float *fnum)
{
	while (!(fnum->remain & 1))
	{
		fnum->remain >>= 1;
		power--;
	}
	first_shift(product, fnum, power);
	fnum->remain >>= 1;
	power--;
	return (power);
}

void			sum_power(char product[1080][1000], t_float *fnum)
{
	unsigned int	power;
	unsigned int	carry;
	int				i;
	unsigned int	offset;

	carry = 0;
	i = 0;
	offset = 0;
	power = sum_power_helper(52, product, fnum);
	while (power > 0)
	{
		if (fnum->remain & 1)
		{
			offset = power + 1022 - ft_strlen(product[power + 1022]);
			i = ft_strlen(product[power + 1022]);
			carry = 0;
			while (product[power + 1022][--i])
			{
				fnum->big_str[offset + i] += product[power + 1022][i] + carry - '0';
				carry = sphtwo(carry, offset, fnum, i);
			}
			sphthree(carry, offset, fnum);
		}
		power = sphfour(power, fnum);
	}
}
