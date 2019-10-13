/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:07:10 by hlo               #+#    #+#             */
/*   Updated: 2019/10/13 13:15:29 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		output_final(char *final, int add)
{
	static int print_count = 0;

	format_final(final);
	print_count += ft_strlen(final);
	print_count += add;
	write(1, &final[0], ft_strlen(final));
	ft_bzero(final, ft_strlen(final));
	return (print_count);
}

void	delete_bracket(char *final, int i)
{
	ft_memmove(&final[i], &final[i + 1], ft_strlen(&final[i + 1]));
	final[ft_strlen(final) - 1] = '\0';
}

void	format_final_loop(char *final, char *mod, int i, int k)
{
	while (final[i])
	{
		if ((final[i] == '}') && (final[i + 1] == '}'))
			delete_bracket(final, i);
		if (final[i] == '{')
			if ((final[i + 1] != '{') && (final[i - 1] != '{'))
			{
				i++;
				while ((final[i + k] != '}') && (k < 9))
				{
					mod[k] = final[i + k];
					k++;
				}
				if ((final[i + k] == '}') &&
						(final[i + k + 1] != '}') && (ft_strlen(mod) > 1))
				{
					alter_format(final, mod, i - 1);
					ft_bzero(mod, 10);
				}
				k = 0;
			}
		i++;
	}
}

void	format_final(char *final)
{
	int		i;
	int		k;
	char	mod[10];

	i = 0;
	k = 0;
	ft_bzero(mod, 10);
	format_final_loop(final, mod, i, k);
}
