#ifndef PRINTF_H
# define PRINTF_H

# define BUFF 16384
# define isnan(x) ((x) != (x))
# include "libft.h"
# include <stdarg.h>
# include <inttypes.h>
# include <stdio.h>
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
}				        t_block;

typedef struct s_float
{
  char sign;
  int16_t exponent;
  int64_t mantissa;
}              t_float;

void		ft_printf(const char *fmt, ...);
int			count_arg(const char *str);
int 		parse(const char *fmt, va_list ap);
void 		parse_remain(const char *fmt, int i, va_list ap);
void    parse_arg(const char *fmt, unsigned int i, t_block *blks);
void    compose_str(const char *fmt, va_list ap, t_block *blks);
void    treat_arg(char *final, va_list ap, t_block *blks);
void    string_hex(uintmax_t n, char *final, t_block *blksk);
void    string_digit(intmax_t n, char *final, t_block *blksk);
char     *dex_to_bin_str(char *result, unsigned long long n);
uintmax_t  add_unsigned_modifier(va_list ap, t_block *blksk);
intmax_t  add_modifier(va_list ap, t_block *blksk);
void      print_n(intmax_t n);
char    *ft_itoamax(intmax_t n, char *str);
char  *group_digit(char *str, t_block *blksk);
void   decode_float(uint64_t *word, char *final, t_block *blksk);
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
