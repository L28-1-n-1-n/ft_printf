/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_g_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:25:27 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 14:34:43 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

int		adjust_trail_helper(char *final, t_block *blksk, int end, int exp)
{
	if (blksk->flag & 8)
		while (exp < end)
			final[exp++] = ' ';
	if ((blksk->flag & 2) && (!(blksk->flag & 8)))
	{
		final[end] = final[exp - 1];
		exp -= 1;
		while (exp < end)
			final[exp++] = '0';
	}
	return (exp);
}

void	adjust_trail(char *final, t_block *blksk, int exp)
{
	int end;
	int tmp;

	tmp = 0;
	end = ft_strlen(final) - 1;
	exp = adjust_trail_helper(final, blksk, end, exp);
	if ((!(blksk->flag & 2)) && (!(blksk->flag & 8)))
	{
		final[end] = final[exp - 1];
		tmp = exp - 1;
		while ((final[tmp] >= '0') && (final[tmp] <= '9'))
			tmp--;
		if ((final[tmp] == '+') || (final[tmp] == '-'))
		{
			final[end - 1] = final[tmp];
			exp -= 1;
			end -= 1;
		}
		exp -= 1;
		while (exp < end)
			final[exp++] = ' ';
	}
}

void	print_g_str_help2(char *final, t_block *blksk, int exp, t_float *fnum)
{
	if (!(blksk->flag & 16))
	{
		exp = ft_strlen(final) - 1;
		while ((final[exp] != '0') && (final[exp] != '.'))
			exp--;
		while (final[exp] == '0')
			exp--;
		if (final[exp] == '.')
			adjust_trail(final, blksk, exp);
		remove_finalz(final, blksk, exp, fnum);
	}
}

int		print_g_str_helper(t_block *blksk, int exp, char *final, t_float *fnum)
{
	int return_value;

	return_value = 0;
	if (blksk->precision == 0)
		blksk->precision = 1;
	if ((exp < -4) || (blksk->precision <= exp))
	{
		if (blksk->type == 'g')
			blksk->type = 'e';
		else
			blksk->type = 'E';
		blksk->precision -= 1;
		return_value = print_e_str(final, blksk, fnum);
	}
	else
	{
		blksk->type = (blksk->type == 'g') ? 'f' : 'F';
		blksk->precision = blksk->precision - (exp + 1);
		return_value = print_float_str(final, blksk, fnum);
	}
	return (return_value);
}

int		print_g_str(char *final, t_block *blksk, t_float *fnum)
{
	t_float	*fnume;
	t_block	*blkse;
	int		exp;
	int		return_value;

	return_value = 0;
	if (!(fnume = (t_float *)malloc(sizeof(t_float))))
		return (ft_free(fnume, -1));
	if (!(blkse = (t_block *)malloc(sizeof(t_block))))
	{
		free(fnume);
		return (ft_free(blkse, -1));
	}
	dup_g(fnum, fnume, blksk, blkse);
	exp = find_exponent(blkse, fnume);
	return_value = print_g_str_helper(blksk, exp, final, fnum);
	if (return_value == -1)
	{
		free(fnume);
		return (ft_free(blkse, -1));
	}
	print_g_str_help2(final, blksk, exp, fnum);
	free(fnume);
	free(blkse);
	return (0);
}
