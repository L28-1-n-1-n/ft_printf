/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_float_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 08:45:57 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 09:02:34 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

void	underf_exp(t_float *fnum, long double *fraction, unsigned int bit_value)
{
	if (uf_subnormal(fnum))
		return ;
	else
	{
		fnum->remain = (bit_value == 64) ? (0x10000000000000 + fnum->mantissa)
			: fnum->mantissa;
		uf_nsn(fnum, fraction, bit_value);
	}
}

void	print_small_range(unsigned int i, t_float *fnum, long double *fraction)
{
	while (i > 0)
	{
		if (fnum->remain & 1)
			fnum->decimal += (((long double)1) / fraction[i]);
		fnum->remain >>= 1;
		i--;
	}
}

void	normal_range(unsigned int i, t_float *fnum, long double *fraction)
{
	i = 52 - fnum->exponent;
	fnum->integer = (0x10000000000000 + fnum->mantissa) >> i;
	fnum->remain = (fnum->mantissa << (12 + fnum->exponent))
		>> (12 + fnum->exponent);
	print_small_range(i, fnum, fraction);
}

void	compose_float_64(t_float *fnum, long double *fraction)
{
	unsigned int i;

	i = 0;
	fnum->decimal = 0;
	if ((fnum->exponent >= 0) && (fnum->exponent < 53))
		normal_range(i, fnum, fraction);
	else if ((fnum->exponent >= 53) && (fnum->exponent <= 63))
	{
		i = 0;
		fnum->integer = (0x10000000000000 + fnum->mantissa)
			<< (fnum->exponent - 52);
		fnum->remain = 0;
		print_small_range(i, fnum, fraction);
	}
	else if ((fnum->exponent > -12) && (fnum->exponent < 0))
		exp_0_to_neg_12(fnum, fraction);
	else if (fnum->exponent > 63)
		big_int(fnum);
	else if (fnum->exponent <= -12)
		underf_exp(fnum, fraction, 64);
}

void	compose_float_80(t_float *fnum, long double *fraction)
{
	unsigned int i;

	i = 63 - fnum->exponent;
	if ((fnum->exponent >= 0) && (fnum->exponent < 65))
	{
		fnum->decimal = 0;
		fnum->integer = (uint64_t)fnum->mantissa >> i;
		fnum->remain = (uint64_t)(fnum->mantissa
				<< (1 + fnum->exponent)) >> (1 + fnum->exponent);
		print_small_range(i, fnum, fraction);
	}
	if (fnum->exponent > 64)
		big_int_80(fnum);
	if (fnum->exponent < 0)
		underf_exp(fnum, fraction, 80);
}
