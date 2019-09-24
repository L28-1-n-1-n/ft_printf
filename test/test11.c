/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test11.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 04:29:59 by hlo               #+#    #+#             */
/*   Updated: 2019/09/24 04:31:58 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned int	sample(void)
{
	static unsigned int count = 0;

	count++;
	return (count);
}

int				main(void)
{
	printf("count is %u\n", sample());
	printf("count is %u\n", sample());
	printf("count is %u\n", sample());
	printf("count is %u\n", sample());
	return (0);
}
