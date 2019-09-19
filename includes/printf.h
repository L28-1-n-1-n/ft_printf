#ifndef PRINTF_H
# define PRINTF_H

# define BUFF 16384
# define isnan(x) ((x) != (x))
# define BLACK "\033[22;30m"
# define RED "\033[22;31m"
# define GREEN "\033[22;32m"
# define BROWN "\033[22;33m"
# define BLUE "\033[22;34m"
# define MAGNETA "\033[22;35m"
# define CYAN "\033[22;36m"
# define GRAY "\033[22;37m"
# define WHITE "\033[01;37m"
# define RESETTEXT "\033[0m"
# define BBLUE "\e[48;5;033m"
# define BPURPLE "\e[48;5;057m"
# define BPINK "\e[48;5;213m"
# define BORANGE "\e[48;5;214m"
# define BYELLOW "\e[48;5;226m"
# define BGREEN "\e[48;5;034m"
# define BGREY "\e[48;5;243m"
# define BWHITE "\e[48;5;255m"
# define BBLACK "\e[48;5;237m"
# define BOLD "\e[1m"
# define IT "\e[3m"
# define ULINE "\e[4m"
# define STHRO "\e[9m"
# define RESETFONT "\e[0m"
# define FLEN 50000
# define SLEN 4294967300
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
	int			          width; // -1 means '*'
	int			          precision; // -1 means '*'
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
  uint64_t integer;
  uint64_t remain;
  long double decimal;
  unsigned int eflag; // 1 for e flag, 2 for g flag, 4 for nan,inf,snan,qnan

  char big_str[20000];
}              t_float;

void		ft_printf(const char *fmt, ...);
int			count_arg(const char *str);
int 		parse(const char *fmt, va_list ap);
void 		parse_remain(const char *fmt, int i, va_list ap);
void    parse_arg(const char *fmt, unsigned int i, t_block *blks);
int     compose_str(const char *fmt, va_list ap, t_block *blks);
void    treat_arg(char *final, va_list ap, t_block *blks);
void    string_hex(uintmax_t n, char *final, t_block *blksk);
void    string_digit(intmax_t n, char *final, t_block *blksk);
char     *dex_to_bin_str(char *result, unsigned long long n);
uintmax_t  add_unsigned_modifier(va_list ap, t_block *blksk);
intmax_t  add_modifier(va_list ap, t_block *blksk);
void      print_n(intmax_t n);
char    *ft_itoamax(intmax_t n, char *str);
char  *group_digit(char *str, t_block *blksk);
int   decode_float(uint64_t *word, char *final, t_block *blksk);
void  big_int(t_float *fnum);
void  big_int_80(t_float *fnum);
char *group_digit(char *str, t_block *blksk);
int print_float_str(char *final, t_block *blksk, t_float *fnum);
void print_e_str(char *final, t_block *blksk, t_float *fnum);
int  float_special(t_float *fnum, unsigned int bit_value, char type);
void sub_array(t_float *fnum);
void sub_array_80(t_float *fnum);
t_float   *init_float(t_float *fnum);
void print_g_str(char *final, t_block *blksk, t_float *fnum);
void init_blocks(t_block *blks, int total);
void string_bin(intmax_t n, char *final, t_block *blksk);
void treat_time(char *final, t_block *blksk);
void output_final(char *final, size_t length);
void check_buff(char *final, char *str, size_t len);
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
