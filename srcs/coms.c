/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coms.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:02:49 by hlo               #+#    #+#             */
/*   Updated: 2019/10/13 12:08:46 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

unsigned int	small_loop(const char *fmt, unsigned int len)
{
	while (*fmt && (*fmt != '%'))
	{
		fmt++;
		len++;
	}
	return (len);
}

unsigned int	check_k(unsigned int k, unsigned int m, char type)
{
	if ((k < m) && (type == 'T'))
		return (1);
	else
		return (0);
}

unsigned int	increment_fmt(const char *fmt)
{
	unsigned int count;

	count = 0;
	while (!(ft_strchr("cdixXpeEfFgGousbrk%", *fmt)))
	{
		fmt++;
		count++;
	}
	count++;
	return (count);
}

int				return_snippet(int ret, char *final)
{
	printf("we got hereagain\n");
	if (ret != -1)
		ret = output_final(final, 0);
	free(final);
	return (ret);
}

int				coms(const char *fmt, va_list ap, t_block *blks, unsigned int m)
{
	char			*final;
	unsigned int	k;
	unsigned int	len;
	int				ret;

	len = 0;
	k = 0;
	ret = 0;
	if (((final = ft_strnew(FLEN)) == NULL))
		return (ft_free(final, -1));
	fmt += (len = small_loop(fmt, len));
	check_buff(final, (char *)(fmt - len), len);
	while (*fmt)
	{
		fmt += (len = small_loop(fmt, 0));
		check_buff(final, (char *)(fmt - len), len);
		k += check_k(k, m, blks[k].type);
		printf("we completed this part1\n");

		if ((!(*fmt)) || ((ret = treat_arg(fmt, final, ap, &blks[k])) == -1))
			break ;
		if (!(*fmt++))
			break ;
		printf("here\n");
		fmt += increment_fmt(fmt);
		k++;
	}
	printf("we completed this part\n");
	return (return_snippet(ret, final));
}
