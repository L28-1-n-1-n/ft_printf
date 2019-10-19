/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_80.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 08:02:47 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 08:07:16 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	print_result_80(uint64_t *raw, t_float *fnum)
{
	unsigned int	i;
	uint64_t		mask;
	int				digit;
	uint64_t		block;
	char			str[5270];

	ft_bzero(str, 5270);
	digit = 0;
	mask = 0xF000000000000000;
	i = 0;
	while (i < 310)
	{
		block = 0;
		while (block < 16)
		{
			digit = (raw[i] & mask) >> ((15 - block) * 4);
			ft_strcat_char(str, digit + '0');
			block++;
			mask = (block == 16) ? 0xF000000000000000 : mask >> 4;
		}
		i++;
	}
	print_result_helper(str, fnum, 80);
}

void	cmp_blocks_80(uint64_t *raw, unsigned int row_no, uint64_t origin_mask)
{
	uint64_t		block;
	uint64_t		b_limit;
	uint64_t		extra_shift;
	unsigned int	digit;
	uint64_t		mask;

	digit = 0;
	block = 0;
	b_limit = (row_no == 309) ? 14 : 16;
	extra_shift = (row_no == 309) ? 8 : 0;
	mask = origin_mask;
	while (block < b_limit)
	{
		digit = (raw[row_no] & mask) >> (extra_shift + block * 4);
		if (digit > 4)
			raw[row_no] += ((uint64_t)3 << (extra_shift + block * 4));
		block++;
		mask = (block == b_limit) ? origin_mask : mask << 4;
	}
	if ((raw[row_no - 1]) && (row_no != 0))
		cmp_blocks_80(raw, row_no - 1, 0xF);
}

void	carry_bit_80(uint64_t *raw, unsigned int row_no, unsigned int carry)
{
	unsigned int mem;

	if (!(row_no))
		return ;
	mem = carry;
	if (raw[row_no - 1] & 0x8000000000000000)
		carry = 1;
	else
		carry = 0;
	if (raw[row_no - 1])
		raw[row_no - 1] <<= 1;
	if (mem)
		raw[row_no - 1] |= 1;
	carry_bit_80(raw, row_no - 1, carry);
}

void	within_row_80(uint64_t *raw, unsigned int shift)
{
	uint64_t		block;
	unsigned int	digit;
	uint64_t		mask;
	static int		shift_count = 0;

	block = 0;
	mask = 0xF00;
	digit = 0;
	while (shift)
	{
		carry_bit_80(raw, 309, (raw[309] & 0x8000000000000000) >> 63);
		raw[309] <<= 1;
		shift_count++;
		block = 0;
		cmp_blocks_80(raw, 309, 0xF00);
		shift--;
	}
}

void	big_int_80(t_float *fnum)
{
	uint64_t	raw[311];
	uint64_t	man_mask;
	int			z;

	z = 56;
	man_mask = 0xFF00000000000000;
	ft_bzero(&raw[0], 311 * sizeof(uint64_t));
	raw[309] |= ((fnum->mantissa & 0xFF00000000000000) >> z);
	while (z > 0)
	{
		within_row_80(raw, 8);
		man_mask >>= 8;
		z -= 8;
		raw[309] |= ((fnum->mantissa & man_mask) >> z);
	}
	within_row_80(raw, 8);
	z = fnum->exponent - 64;
	while (z > 8)
	{
		within_row_80(raw, 8);
		z -= 8;
	}
	within_row_80(raw, z);
	carry_bit_80(raw, 310, 0);
	print_result_80(raw, fnum);
}
