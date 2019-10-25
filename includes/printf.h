/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:17:28 by hlo               #+#    #+#             */
/*   Updated: 2019/10/19 16:43:31 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define BUFF 16384
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

extern const char	g_test[160][72];
extern const char	g_pi[139][72];
typedef enum		e_modifier
{
	NA = 0,
	hh,
	h,
	ll,
	l,
	L,
	z
}					t_modifier;

typedef struct		s_block
{
	unsigned int	order;
	unsigned int	flag;
	int				width;
	int				precision;
	int				orig;
	t_modifier		modifier;
	char			type;
	char			*str;
	unsigned int	pos;
	char			base[17];
}					t_block;

typedef struct		s_float
{
	char			sign;
	int16_t			exponent;
	int64_t			mantissa;
	uint64_t		integer;
	uint64_t		remain;
	long double		decimal;
	unsigned int	eflag;
	int				final_len;
	char			big_str[20000];
}					t_float;

int					ft_printf(const char *fmt, ...);
int					count_arg(const char *str);
int					parse(const char *fmt, va_list ap);
void				parse_remain(const char *fmt, int i, va_list ap);
int					parse_arg(const char *fmt, unsigned int i, t_block *blks);
int					coms(const char *fmt,
		va_list ap, t_block *blks, unsigned int m);
int					treat_arg(const char *fmt,
		char *final, va_list ap, t_block *blks);
void				string_hex(uintmax_t n,
		char *final, t_block *blksk, const char *fmt);
void				string_digit(intmax_t n, char *final, t_block *blksk);
char				*dex_to_bin_str(char *result, unsigned long long n);
uintmax_t			add_unsigned_modifier(va_list ap, t_block *blksk);
intmax_t			add_modifier(va_list ap, t_block *blksk);
void				print_n(intmax_t n);
char				*ft_itoamax(intmax_t n, char *str);
char				*group_d(char *str, t_block *blksk);
int					decode_float(uint64_t *word, char *final, t_block *blksk);
void				big_int(t_float *fnum);
void				big_int_80(t_float *fnum);
int					print_float_str(char *final, t_block *blksk, t_float *fnum);
int					print_e_str(char *final,
		t_block *blksk, t_float *fnum);
int					float_special(t_float *fnum,
		unsigned int bit_value, char type);
void				sub_array(t_float *fnum);
void				sub_array_80(t_float *fnum);
t_float				*init_float(t_float *fnum);
int					print_g_str(char *final, t_block *blksk, t_float *fnum);
void				init_blocks(t_block *blks, int total);
void				string_bin(intmax_t n, char *final, t_block *blksk);
int					treat_time(char *final);
int					output_final(char *final, int add);
void				check_buff(char *final, char *str, size_t len);
void				format_final(char *final);
int					alter_format(char *final, char *mod, int pos);
char				*check_len(char *str, unsigned int k, t_block *blks);
int					check_type(char *str, unsigned int k, t_block *blks);
int					treat_string(char *final, va_list ap, t_block *blksk);
int					treat_char(char *final, va_list ap, t_block *blksk);
int					treat_nonpri(char *final,
		va_list ap, t_block *blksk, const char *fmt);
int					treat_plain_text(const char *fmt,
		char *final, t_block *blksk);
int					treat_bin (char *final, va_list ap, t_block *blksk);
char				*convert_base(uintmax_t n, char *tmp, t_block *blksk);
unsigned int		snippet_one(const char *fmt, char *str, t_block *blksk);
void				snippet_two(char *str, t_block *blksk);
void				snippet_three(char *str, t_block *blksk);
unsigned int		snippet_four(const char *fmt, t_block *blksk);
int					help_one(char *str, t_block *blksk);
int					help_two(char *str, t_block *blksk);
int					help_three(char *str, t_block *blksk, int i, int j);
int					help_four(char *str, t_block *blksk, int j);
int					help_five(char *str, t_block *blksk, int i, int j);
int					help_six(char *str, t_block *blksk, int j);
int					help_seven(char *str, t_block *blksk, int i, int j);
int					help_eight(char *str, t_block *blksk, uintmax_t n, int j);
char				*nest_hex(char *str, t_block *blksk);
void				nest_one(char *str, t_block *blksk, int i, int j);
void				print_result_helper(char *str,
		t_float *fnum, unsigned int bit);
unsigned int		uf_subnormal(t_float *fnum);
void				uf_nsn(t_float *fnum,
		long double *fr, unsigned int bit_value);
void				compose_float_64(t_float *fnum, long double *fraction);
void				compose_float_80(t_float *fnum,
		long double *fraction);
void				first_shift(char product[1080][1000],
		t_float *fnum, unsigned int power);
void				sum_power(char product[1080][1000], t_float *fnum);
int					pfstr_helper(char *final, char *str,
		t_block *blksk, t_float *fnum);
void				round_float(char *str,
		int carry, size_t i);
int					modify_carry(char *str, t_block *blksk, t_float *fnum);
unsigned int		aggre_help_80(char **product,
		unsigned int i, unsigned int j, unsigned int carry);
int					case_n_zero(char *str, int j, intmax_t n, t_block *blksk);
void				aggregate_80(char **product);
int					di_nosign(char *str, int j, t_block *blksk, int i);
int					no_zero_nor_space(char *str, int j);
char				*digit_space(char *str, int width,
		t_block *blksk, intmax_t n);
int					valueofi(char *str, intmax_t n, t_block *blksk);
int					nest(char *str, intmax_t n, t_block *blksk);
void				round_float(char *str, int carry, size_t i);
void				pos_exp(char *str, t_block *blksk, int i);
void				neg_exp(char *str, t_block *blksk, int i);
void				non_big_str(char *str, t_block *blksk, t_float *fnum);
void				mod_final(char *final, t_block *blksk, t_float *fnum);
void				treat_extra_space(char *str,
		t_block *blksk, t_float *fnum, int carry);
int					pestr_helper(char *final,
		char *str, t_block *blksk, t_float *fnum);
int					pf_subarray(char *str, t_block *blksk, t_float *fnum);
void				treat_extra_space(char *str,
		t_block *blksk, t_float *fnum, int carry);
void				dup_g(t_float *fnum,
		t_float *fnume, t_block *blksk, t_block *blkse);
void				remove_finalz(char *final,
		t_block *blksk, int exp, t_float *fnum);
int					find_exponent(t_block *blkse, t_float *fnume);
int					treat_random(char *final, uintmax_t n);
int					loop_big_int(uint64_t raw[31], int z);
void				within_row(uint64_t *raw, unsigned int shift);
void				exp_0_to_neg_12(t_float *fnum, long double *fraction);
void				print_small_range(unsigned int i,
		t_float *fnum, long double *fraction);
int					treat_encrypt(char *final, va_list ap, t_block *blksk);

#endif
