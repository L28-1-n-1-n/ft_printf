/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 06:34:21 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 15:47:05 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	first_shift(char product[1080][1000], t_float *fnum, unsigned int power)
{
	unsigned int offset;

	offset = 0;
	if (fnum->remain & 1)
	{
		offset = power + 1022 - ft_strlen(product[power + 1022]);
		while (offset)
		{
			ft_strcat_char(fnum->big_str, '0');
			offset--;
		}
		ft_strcat(fnum->big_str, product[power + 1022]);
	}
}

void	aggre_helper_one(char product[1080][1000],
		unsigned int i, unsigned int j, unsigned int carry)
{
	unsigned int tmp;

	tmp = 0;
	while (i < 1079)
	{
		while (product[i][j])
		{
			tmp = (product[i][j] - '0') * 5;
			product[i + 1][j] += carry + '0';
			carry = tmp / 10;
			tmp = tmp % 10;
			product[i + 1][j] += tmp;
			if (product[i + 1][j] > '9')
			{
				product[i + 1][j] -= 10;
				carry += 1;
			}
			j++;
		}
		if (carry)
			product[i + 1][j] += carry + '0';
		carry = 0;
		j = 0;
		i++;
	}
}

void	aggre_helper_two(char product[1080][1000])
{
	int i;

	i = 27;
	while (i < 1079)
	{
		ft_strrev(product[i]);
		i++;
	}
}

void	aggregate(char product[1080][1000])
{
	int				i;
	int				j;
	unsigned int	carry;

	i = 27;
	j = 0;
	carry = 0;
	aggre_helper_one(product, i, j, carry);
	aggre_helper_two(product);
}

void	sub_array(t_float *fnum)
{
	char		product[1080][1000];
	int			i;
	long double	seed;

	i = 0;
	while (i < 1080)
	{
		ft_bzero(&product[i], 1000);
		i++;
	}
	ft_strcpy(product[0], "0");
	i = 1;
	seed = 1;
	while (i < 28)
	{
		seed = seed * ((long double)5);
		ft_itoamax(seed, product[i]);
		i++;
	}
	ft_strrev(product[27]);
	aggregate(product);
	sum_power(product, fnum);
}
