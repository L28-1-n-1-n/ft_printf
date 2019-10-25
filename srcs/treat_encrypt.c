/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_encrypt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 05:53:33 by hlo               #+#    #+#             */
/*   Updated: 2019/10/25 05:54:56 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <time.h>
#include <stdlib.h>

char	*decrypt_str(char *string, char *str)
{
	unsigned int	seed;
	char			c;
	unsigned int	i;

	i = 0;
	c = string[ft_strlen(string) - 1];
	seed = c + 10 - '0';
	while (string[i])
	{
		if (string[i] - seed < 33)
			str[i] = string[i] - seed + 126 - 33;
		else
			str[i] = string[i] - seed;
		str[i] = 126 - str[i] + 33;
		i++;
	}
	str[ft_strlen(str) - 1] = '\0';
	return (str);
}

char	*encrypt_str(char *string, char *str)
{
	time_t			seconds;
	unsigned int	seed;
	unsigned int	i;

	i = 0;
	time(&seconds);
	seed = seconds % 10;
	if (seed == 0)
		seed = 1;
	while (string[i])
	{
		str[i] = 126 - string[i] + 33;
		if (str[i] + seed > 126)
			str[i] = str[i] + seed - 126 + 33;
		else
			str[i] = str[i] + seed;
		i++;
	}
	ft_strcat_char(str, seed + '0' - 10);
	return (str);
}

int		treat_encrypt(char *final, va_list ap, t_block *blksk)
{
	char	*string;
	char	*str;

	string = va_arg(ap, char *);
	str = ft_strnew(ft_strlen(string) + 1);
	if (str == NULL)
		return (ft_free(str, -1));
	if (blksk->type == 'K')
		ft_strcat(final, encrypt_str(string, str));
	else
		ft_strcat(final, decrypt_str(string, str));
	free(str);
	return (0);
}
