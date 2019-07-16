#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef enum		e_modifier
 {
		 NA = 0,
		 hh,
		 h,
		 l,
		 ll,
		 L,
		 z
 }							t_modifier;

typedef struct	s_block
{
	unsigned int order; // n in n $, where n cannot be negative or 0, n must be valid order, e.g. 1 and 2, not 1 and 3
	char  		flag; // '0'   '+'   '-'   '#'

	int			width;
	int			precision;
 	t_modifier modifier;
	char		type; // c d i x X p e E f F g G o u s %

}				t_block;

void		ft_printf(const char *fmt, ...);
void 		parse(const char *fmt, va_list ap);
void 		parse_remain(const char *fmt, int i, va_list ap);

#endif


/*
	union		u_width
	{
		int		w;    // we do not use union becoz simply scan for * first
		char	any_w; // if * found, eventually we need a number anyway
	}			width;
	union		u_precision
	{
		int		pres;
		char	any_pres;
	}			precision;
*/
