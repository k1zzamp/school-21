/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:01:11 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 22:56:37 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_struct_4(const char **format)
{
	if (**format == 'l')
	{
		g_pf_flags.l = 1;
		(*format)++;
		if (**format == 'l')
		{
			g_pf_flags.l = 0;
			g_pf_flags.ll = 1;
			(*format)++;
		}
	}
	if (**format == '#')
	{
		g_pf_flags.flag_hash = 1;
		(*format)++;
	}
	if (**format == '0')
	{
		g_pf_flags.flag_zero = 1;
		(*format)++;
	}
	set_struct_5(format);
}

void	set_struct_3(const char **format, _Bool dot_flag)
{
	char	*temp;

	if (**format >= '0' && **format <= '9' && dot_flag)
	{
		g_pf_flags.precision = ft_atoi((*format));
		temp = ft_itoa(g_pf_flags.precision);
		(*format) += ft_strlen(temp);
		free(temp);
	}
	if (**format == 'h')
	{
		g_pf_flags.h = 1;
		(*format)++;
		if (**format == 'h')
		{
			g_pf_flags.h = 0;
			g_pf_flags.hh = 1;
			(*format)++;
		}
	}
	set_struct_4(format);
}

void	set_struct_2(const char **format, _Bool dot_flag)
{
	char	*temp;

	if (**format >= '1' && **format <= '9' && !(dot_flag))
	{
		g_pf_flags.width = ft_atoi((*format));
		temp = ft_itoa(g_pf_flags.width);
		(*format) += ft_strlen(temp);
		free(temp);
	}
	if (**format == '-')
	{
		g_pf_flags.flag_minus = 1;
		(*format)++;
	}
	if (**format == '+')
	{
		g_pf_flags.flag_plus = 1;
		(*format)++;
	}
	if (**format == ' ')
	{
		g_pf_flags.flag_space = 1;
		(*format)++;
	}
	set_struct_3(format, dot_flag);
}

void	set_struct(va_list arg, const char **format)
{
	_Bool	dot_flag;

	dot_flag = 0;
	while (**format)
	{
		if (**format == '.')
		{
			g_pf_flags.dot = 1;
			dot_flag = 1;
			(*format)++;
		}
		set_struct_2(format, dot_flag);
		if (set_format(format))
		{
			print_arg(arg);
			break ;
		}
	}
}

void	parser(va_list arg, const char *format)
{
	while (*format)
	{
		if (*format == '{')
			format += check_color(format);
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				format++;
				ft_putchar_g('%');
				continue ;
			}
			set_struct(arg, &format);
			null_struct();
			continue ;
		}
		if (*format != '\0')
		{
			ft_putchar_g(*format);
			format++;
		}
	}
}
