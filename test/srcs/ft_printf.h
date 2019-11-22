/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:27:06 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 21:58:22 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <stdio.h>

# define HEX "0x"
# define HEXU "0X"
# define OCT "0"

typedef struct		s_flags
{
	_Bool		flag_hash;
	_Bool		flag_zero;
	_Bool		flag_minus;
	_Bool		flag_plus;
	_Bool		flag_space;
	int			width;
	int			precision;
	_Bool		hh;
	_Bool		h;
	_Bool		l;
	_Bool		ll;
	_Bool		lu;
	_Bool		d;
	_Bool		i;
	_Bool		o;
	_Bool		u;
	_Bool		x;
	_Bool		xu;
	_Bool		c;
	_Bool		s;
	_Bool		p;
	_Bool		f;
	_Bool		dot;
}					t_flags;

extern t_flags		g_pf_flags;
extern int			g_pf_ret;

char				*ft_float(long double nb, long acc);
int					ft_printf(const char *format, ...);
char				*ft_itoa(int n);
void				*ft_memset(void *str, int c, size_t n);
char				*ft_strnew(size_t size);
int					ft_isspace(int c);
int					ft_atoi(const char *str);
void				ft_bzero(void *str, size_t n);
void				*ft_memalloc(size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
void				ft_putchar_g(char c);
void				ft_putstr_g(char *str);
char				*ft_itoa_base_v(long long dig, int base, char a);
char				*ft_ltoa(long n);
char				*ft_itoa_base_gt(uintmax_t num, uintmax_t base, char c);
char				*ft_itoa_ltoa(long n);
char				*ft_itoa_base_pf(uintptr_t value, unsigned int base);
void				null_struct(void);
char				*ft_itoa_nom(int n);
char				*ft_uitoa(unsigned int n);
char				*ft_ultoa(unsigned long n);
void				print_c_help(char c);
void				print_c(va_list arg);
void				print_lf_help1(double x, int len, char *str);
void				print_lf_help3(double x, int len, char *str);
void				print_lf_help2(double x, int len, char *str);
void				print_lf(va_list arg);
void				print_luf_help1(double x, int len, char *str);
void				print_luf_help3(double x, int len, char *str);
void				print_luf_help2(double x, int len, char *str);
void				print_luf(va_list arg);
void				print_fl(va_list arg);
void				print_lf_help10(void);
void				print_long_help2(void);
void				print_long_help1(void);
void				print_long_help5(long x);
void				print_long_help4(long x, int len, int pres, char *str);
void				print_long_help7(long x, int len, char *str);
void				print_long_help6(long x, char *str);
void				print_long_help3(long x, int len, int pres, char *str);
void				print_long(va_list arg);
void				print_o_l_help2(void);
void				print_o_l_help1(void);
void				print_o_l_help4(long num, char *str, int len, int z_flag);
void				print_o_l_help3(long num, char *str, int len, int z_flag);
void				print_luf_help10(void);
void				print_o_l(va_list arg);
void				print_o(va_list arg);
void				print_p_help(int len, char *str);
void				print_p(va_list arg);
void				print_s_nom_help(char *str, int len);
void				print_s_nom(char *str, int len);
void				print_s_m_help(char *str, int space);
void				print_s_m(char *str, int len);
void				print_s(va_list arg);
void				print_x_l_help1(void);
void				print_x_l_help2(long num, int len, char *str);
void				print_x_l_help4(long num, int *z_flag);
void				print_x_l_help3(long num, int len, char *str, int z_flag);
void				print_x_l(va_list arg);
void				print_x(va_list arg);
void				print_int_help2(void);
void				print_int_help1(void);
void				print_int_help5(long x);
void				print_int_help4(long x, int len, int pres, char *str);
void				print_int_help7(long x, int len, char *str);
void				print_int_help6(long x, char *str);
void				print_int_help3(long x, int len, int pres, char *str);
void				print_int(va_list arg);
void				print_ui_m_help(int len, char *str);
void				print_ui_m(va_list arg);
void				print_ui_no_f_help(char *str, int len);
void				print_ui_no_f(va_list arg);
void				print_ui_long_no_f_help(char *str, int len);
void				print_ui_long_no_f(va_list arg);
void				print_long_ui_m_help1(char *str, int len);
void				print_long_ui_m_help2(char *str, int len, unsigned long i);
void				print_long_ui_m(va_list arg);
void				print_u(va_list arg);
unsigned int		check_mod(unsigned int i);
long				check_mod_ull(long i);
void				print_arg(va_list arg);
int					set_format_3(const char **format);
int					set_format_2(const char **format);
unsigned int		check_mod_ui(int i);
long				check_mod_l(long i);
void				print_d(va_list arg);
int					set_format(const char **format);
void				set_struct_5(const char **format);
void				set_struct_4(const char **format);
void				set_struct_3(const char **format, _Bool dot_flag);
void				set_struct_2(const char **format, _Bool dot_flag);
void				set_struct(va_list arg, const char **format);
void				parser(va_list arg, const char *format);

#endif
