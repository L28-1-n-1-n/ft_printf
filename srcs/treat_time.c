/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:00:33 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 16:07:19 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <time.h>
#include <stdlib.h>

char	*find_month(char *month)
{
	if (!(ft_strcmp(month, "Jan")))
		return ("01");
	if (!(ft_strcmp(month, "Feb")))
		return ("02");
	if (!(ft_strcmp(month, "Mar")))
		return ("03");
	if (!(ft_strcmp(month, "Apr")))
		return ("04");
	if (!(ft_strcmp(month, "May")))
		return ("05");
	if (!(ft_strcmp(month, "Jun")))
		return ("06");
	if (!(ft_strcmp(month, "Jul")))
		return ("07");
	if (!(ft_strcmp(month, "Aug")))
		return ("08");
	if (!(ft_strcmp(month, "Sep")))
		return ("09");
	if (!(ft_strcmp(month, "Oct")))
		return ("10");
	if (!(ft_strcmp(month, "Nov")))
		return ("11");
	if (!(ft_strcmp(month, "Dec")))
		return ("12");
	return (0);
}

void	find_timezone(char *iso, time_t seconds)
{
	char		buf[6];
	struct tm	*ptm;

	ft_bzero(buf, 6);
	ptm = localtime(&seconds);
	strftime(buf, 6, "%z", ptm);
	strftime(buf, 6, "%z", ptm);
	ft_strncat(iso, buf, 5);
}

int		treat_time(char *final)
{
	time_t	seconds;
	char	str[25];
	char	**result;
	char	iso[26];
	int		i;

	i = 0;
	ft_bzero(str, 25);
	ft_bzero(iso, 26);
	time(&seconds);
	ft_strcpy(str, ctime(&seconds));
	result = ft_strsplit(str, ' ');
	ft_strncpy(iso, result[4], 4);
	iso[4] = '-';
	ft_strncat(iso, find_month(result[1]), 3);
	iso[7] = '-';
	ft_strcat(iso, result[2]);
	ft_strcat_char(iso, 'T');
	ft_strcat(iso, result[3]);
	ft_free_dblptr(result, 0);
	find_timezone(iso, seconds);
	ft_strcat(final, iso);
	return (0);
}
