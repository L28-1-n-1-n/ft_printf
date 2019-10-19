/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_array_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 06:37:50 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 15:52:28 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int	sphfour(unsigned int pow, t_float *fnum)
{
	fnum->remain >>= 1;
	pow--;
	return (pow);
}

void			sphthree(unsigned int carry, unsigned int offs, t_float *fnum)
{
	if (carry)
		fnum->big_str[offs - 1] += carry;
}

unsigned int	sphtwo(unsigned int carry,
		unsigned int offs, t_float *fnum, int i)
{
	carry = 0;
	if (fnum->big_str[offs + i] > '9')
	{
		carry = 1;
		fnum->big_str[offs + i] -= 10;
	}
	return (carry);
}

unsigned int	sum_power_helper(unsigned int pow,
		char product[1080][1000], t_float *fnum)
{
	while (!(fnum->remain & 1))
	{
		fnum->remain >>= 1;
		pow--;
	}
	first_shift(product, fnum, pow);
	fnum->remain >>= 1;
	pow--;
	return (pow);
}

void			sum_power(char product[1080][1000], t_float *fnum)
{
	unsigned int	pow;
	unsigned int	carry;
	int				i;
	unsigned int	offs;

	carry = 0;
	i = 0;
	offs = 0;
	pow = sum_power_helper(52, product, fnum);
	while (pow > 0)
	{
		if (fnum->remain & 1)
		{
			offs = pow + 1022 - ft_strlen(product[pow + 1022]);
			i = ft_strlen(product[pow + 1022]);
			carry = 0;
			while (product[pow + 1022][--i])
			{
				fnum->big_str[offs + i] += product[pow + 1022][i] + carry - '0';
				carry = sphtwo(carry, offs, fnum, i);
			}
			sphthree(carry, offs, fnum);
		}
		pow = sphfour(pow, fnum);
	}
}
