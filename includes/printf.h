#ifndef PRINTF_H
# define PRINTF_H

# define BUFF 16384
# include "libft.h"
# include <stdarg.h>

typedef enum		e_modifier
 {
		 NA = 0,
		 hh,
		 h,
		 ll,
		 l,
		 L,
		 z
 }							t_modifier;

typedef struct	s_block
{
	unsigned int      order; // n in n $, where n cannot be negative or 0, n must be valid order, e.g. 1 and 2, not 1 and 3
	unsigned int      flag; // '0'   '+'   '-'   '#', default '^' means NULL
	unsigned int			width; // -1 means '*'
	int			           precision; // -1 means '*'
 	t_modifier        modifier;
	char              type; // c d i x X p e E f F g G o u s %
  char              *str; // this is what the result of this block's gonna be
  unsigned int      pos;
}				t_block;

void		ft_printf(const char *fmt, ...);
int			count_arg(const char *str);
int 		parse(const char *fmt, va_list ap);
void 		parse_remain(const char *fmt, int i, va_list ap);
void    parse_arg(const char *fmt, unsigned int i, t_block *blks);
void    compose_str(const char *fmt, va_list ap, t_block *blks);
void    treat_arg(char *final, va_list ap, t_block *blks);
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
