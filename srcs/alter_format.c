/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alter_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:09:25 by hlo               #+#    #+#             */
/*   Updated: 2019/10/13 12:11:25 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		cat_format(char *final, char *adj, int pos, char *mod)
{
	int len;
	int total;

	total = 0;
	len = ft_strlen(adj) - ft_strlen(mod) - 2;
	if (len > 0)
		ft_memmove(&final[pos + len], &final[pos], ft_strlen(&final[pos]));
	if (len < 0)
	{
		ft_memmove(&final[pos + len + ft_strlen(mod) + 2], &final[pos +
				ft_strlen(mod) + 2],
				ft_strlen(&final[pos + ft_strlen(mod) + 2]));
		len = len * -1 + 1;
		total = ft_strlen(final);
		while (len--)
			final[total - len] = '\0';
	}
	ft_strncpy(&final[pos], adj, ft_strlen(adj));
	return (1);
}

int		alter_format_helper(char *final, char *mod, int pos)
{
	if (ft_strcmp(mod, "BPINK") == 0)
		return (cat_format(final, BPINK, pos, mod));
	if (ft_strcmp(mod, "BORANGE") == 0)
		return (cat_format(final, BORANGE, pos, mod));
	if (ft_strcmp(mod, "BYELLOW") == 0)
		return (cat_format(final, BYELLOW, pos, mod));
	if (ft_strcmp(mod, "BGREEN") == 0)
		return (cat_format(final, BGREEN, pos, mod));
	if (ft_strcmp(mod, "BGREY") == 0)
		return (cat_format(final, BGREY, pos, mod));
	if (ft_strcmp(mod, "BWHITE") == 0)
		return (cat_format(final, BWHITE, pos, mod));
	if (ft_strcmp(mod, "BBLACK") == 0)
		return (cat_format(final, BBLACK, pos, mod));
	if (ft_strcmp(mod, "BOLD") == 0)
		return (cat_format(final, BOLD, pos, mod));
	if (ft_strcmp(mod, "IT") == 0)
		return (cat_format(final, IT, pos, mod));
	if (ft_strcmp(mod, "ULINE") == 0)
		return (cat_format(final, ULINE, pos, mod));
	if (ft_strcmp(mod, "STHRO") == 0)
		return (cat_format(final, STHRO, pos, mod));
	if (ft_strcmp(mod, "RESETFONT") == 0)
		return (cat_format(final, RESETFONT, pos, mod));
	return (0);
}

int		alter_format(char *final, char *mod, int pos)
{
	if (ft_strcmp(mod, "BLACK") == 0)
		return (cat_format(final, BLACK, pos, mod));
	if (ft_strcmp(mod, "RED") == 0)
		return (cat_format(final, RED, pos, mod));
	if (ft_strcmp(mod, "GREEN") == 0)
		return (cat_format(final, GREEN, pos, mod));
	if (ft_strcmp(mod, "BROWN") == 0)
		return (cat_format(final, BROWN, pos, mod));
	if (ft_strcmp(mod, "BLUE") == 0)
		return (cat_format(final, BLUE, pos, mod));
	if (ft_strcmp(mod, "MAGNETA") == 0)
		return (cat_format(final, MAGNETA, pos, mod));
	if (ft_strcmp(mod, "CYAN") == 0)
		return (cat_format(final, CYAN, pos, mod));
	if (ft_strcmp(mod, "GRAY") == 0)
		return (cat_format(final, GRAY, pos, mod));
	if (ft_strcmp(mod, "WHITE") == 0)
		return (cat_format(final, WHITE, pos, mod));
	if (ft_strcmp(mod, "RESETTEXT") == 0)
		return (cat_format(final, RESETTEXT, pos, mod));
	if (ft_strcmp(mod, "BBLUE") == 0)
		return (cat_format(final, BBLUE, pos, mod));
	if (ft_strcmp(mod, "BPURPLE") == 0)
		return (cat_format(final, BPURPLE, pos, mod));
	return (alter_format_helper(final, mod, pos));
}
