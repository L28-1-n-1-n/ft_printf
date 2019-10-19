/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e_str_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:08:49 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 13:10:05 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

void	pos_exp_helper(char *str, t_block *blksk, int tens, char *digits)
{
	if (blksk->type == 'e')
		ft_strcat(str, "e+");
	else
		ft_strcat(str, "E+");
	if (tens < 10)
		ft_strcat(str, "0");
	while (tens / 10)
	{
		ft_strcat_char(digits, (tens % 10 + '0'));
		tens /= 10;
	}
	ft_strcat_char(digits, (tens + '0'));
	ft_strcat(str, ft_strrev(digits));
	ft_strcat_char(str, '\0');
	tens = ft_strlen(str);
	while (tens < 20000)
	{
		str[tens] = '\0';
		tens++;
	}
}

void	pos_exp(char *str, t_block *blksk, int i)
{
	int		tens;
	char	digits[10];
	int		carry;

	ft_bzero(digits, 10);
	tens = 1;
	while ((str[i - tens]) && (str[i - tens] >= '0') && (str[i - tens] <= '9'))
		tens++;
	tens -= 2;
	ft_memmove(&str[i], &str[i + 1], ft_strlen(&str[i + 1]));
	ft_memmove(&str[i - tens + 1], &str[i - tens], ft_strlen(&str[i - tens]));
	i = i - tens;
	str[i] = '.';
	carry = (str[i + blksk->precision + 1] > '5') ? 1 : 0;
	round_float(str, carry, i + blksk->precision);
	str[i + blksk->precision + 1] = '\0';
	pos_exp_helper(str, blksk, tens, digits);
}

void	neg_exp_helper(char *str, int tens, char *digits, int i)
{
	int placeholder;

	while (tens / 10)
	{
		ft_strcat_char(digits, (tens % 10 + '0'));
		tens /= 10;
	}
	ft_strcat_char(digits, (tens + '0'));
	ft_strcat(str, ft_strrev(digits));
	tens = 0;
	while (str[tens] != '0')
		tens++;
	placeholder = tens + ft_strlen(&str[i - 1]);
	ft_memmove(&str[tens], &str[i - 1], ft_strlen(&str[i - 1]));
	str[placeholder] = '\0';
	tens = ft_strlen(str);
	while (tens < 20000)
	{
		str[tens] = '\0';
		tens++;
	}
}

void	neg_exp(char *str, t_block *blksk, int i)
{
	int		tens;
	char	digits[10];
	int		carry;

	ft_bzero(digits, 10);
	tens = 1;
	while (str[i + tens] == '0')
		tens++;
	ft_memmove(&str[i], &str[i + 1], ft_strlen(&str[i + 1]));
	ft_memmove(&str[i + tens + 1], &str[i + tens], ft_strlen(&str[i + tens]));
	i = i + tens;
	str[i] = '.';
	carry = (str[i + blksk->precision + 1] > '5') ? 1 : 0;
	round_float(str, carry, i + blksk->precision);
	str[i + blksk->precision] = '\0';
	if (blksk->type == 'e')
		ft_strcat(str, "e-");
	else
		ft_strcat(str, "E-");
	if (tens < 10)
		ft_strcat(str, "0");
	neg_exp_helper(str, tens, digits, i);
}
