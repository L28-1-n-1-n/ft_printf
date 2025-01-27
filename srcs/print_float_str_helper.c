/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_str_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:23:29 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 14:22:34 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

void	treat_final_space(char *str, t_block *blksk, t_float *fnum, char *final)
{
	int		j;
	int		k;
	size_t	m;

	m = 0;
	k = 0;
	if (ft_strchr_pos(str, '-') > 0)
		m = (size_t)(blksk->width);
	else if (blksk->width == 0)
		m = 0;
	else
		m = (size_t)(blksk->width - 1);
	j = ft_strlen(final);
	if (blksk->flag & 32)
		if ((blksk->flag & 32) && (fnum->sign == '-') && (ft_strlen(str) > m))
		{
			if (final[j - 1] == ' ')
				final[j - 1] = '\0';
			else if ((final[j - 1] == '-') && (final[j - 2] == ' '))
			{
				final[j - 1] = '\0';
				final[j - 2] = '-';
			}
		}
}

void	treat_extra_space_f(char *str, t_block *blksk, t_float *fnum, int carry)
{
	if ((blksk->type == 'f') || (blksk->type == 'F'))
	{
		if ((blksk->flag & 2) && (!(blksk->flag & 8)) && (!(fnum->eflag & 4)))
		{
			carry = ((fnum->sign == '-') || (blksk->flag & 4)
					|| (blksk->flag & 32)) ? carry - 1 : carry;
			while (carry--)
				ft_strpcat_char(str, '0');
		}
		if ((!(blksk->flag & 2)) && (!(blksk->flag & 8)))
		{
			carry = (blksk->flag & 32) ? carry - 1 : carry;
			while (carry--)
				ft_strpcat_char(str, ' ');
		}
	}
}

void	treat_extra_space(char *str, t_block *blksk, t_float *fnum, int carry)
{
	if ((size_t)blksk->width > ft_strlen(str))
	{
		if (blksk->flag & 8)
		{
			carry = ((blksk->flag & 32)
					&& (fnum->sign == '+')) ? carry - 1 : carry;
			while (carry--)
				ft_strcat_char(str, ' ');
			fnum->eflag |= 2;
		}
		treat_extra_space_f(str, blksk, fnum, carry);
	}
}

void	mod_final(char *final, t_block *blksk, t_float *fnum)
{
	if (((blksk->flag & 32) && (!(blksk->flag & 4))) && (!(blksk->flag & 8)) &&
			(!((fnum->sign == '-') && (blksk->flag & 2))))
		ft_strcat_char(final, ' ');
	if ((blksk->type == 'f') || (blksk->type == 'F'))
		if (((blksk->flag & 32) && (fnum->sign == '+'))
				&& (blksk->flag & 8) && (!(blksk->flag & 4)))
			ft_strcat_char(final, ' ');
	if ((blksk->type == 'e') || (blksk->type == 'E'))
		if (((blksk->flag & 32) && (fnum->sign == '+')) && (blksk->flag & 8))
			ft_strcat_char(final, ' ');
	if ((fnum->sign == '-') && (blksk->flag & 2))
		ft_strcat_char(final, '-');
	if (((fnum->sign == '+') && (blksk->flag & 4)) && (blksk->flag & 2))
		ft_strcat_char(final, '+');
}

int		pfstr_helper(char *final, char *str, t_block *blksk, t_float *fnum)
{
	int carry;
	int i;

	carry = 0;
	i = 0;
	carry = modify_carry(str, blksk, fnum);
	carry = blksk->width - ft_strlen(str);
	mod_final(final, blksk, fnum);
	treat_extra_space(str, blksk, fnum, carry);
	treat_final_space(str, blksk, fnum, final);
	if (ft_strlen(final) + ft_strlen(str) > FLEN)
	{
		output_final(final, 0);
		if (ft_strlen(str) > FLEN)
			output_final(str, 0);
		else
			ft_strcat(final, str);
	}
	else
		ft_strcat(final, str);
	free(str);
	return (0);
}
