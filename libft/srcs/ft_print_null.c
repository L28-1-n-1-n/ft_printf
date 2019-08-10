/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:55:21 by hlo               #+#    #+#             */
/*   Updated: 2019/01/19 17:11:16 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_null(char *str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (str[i] == '\0')
			ft_putchar('*');
		else
			ft_putchar(str[i]);
		i++;
	}
}