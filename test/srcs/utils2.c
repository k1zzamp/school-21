/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:00:22 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 21:03:36 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(va_list arg)
{
	if (g_pf_flags.u)
		print_u(arg);
	if (g_pf_flags.d || g_pf_flags.i)
		print_d(arg);
	if (g_pf_flags.c)
		print_c(arg);
	if (g_pf_flags.s)
		print_s(arg);
	if (g_pf_flags.p)
		print_p(arg);
	if (g_pf_flags.x || g_pf_flags.xu)
		print_x(arg);
	if (g_pf_flags.o)
		print_o(arg);
	if (g_pf_flags.f)
		print_fl(arg);
}

int		set_format_3(const char **format)
{
	if (**format == 'c')
	{
		g_pf_flags.c = 1;
		(*format)++;
		return (1);
	}
	if (**format == 'f')
	{
		g_pf_flags.f = 1;
		(*format)++;
		return (1);
	}
	if (**format == 's')
	{
		g_pf_flags.s = 1;
		(*format)++;
		return (1);
	}
	if (**format == 'p')
	{
		g_pf_flags.p = 1;
		(*format)++;
		return (1);
	}
	return (0);
}

int		set_format_2(const char **format)
{
	if (**format == 'u')
	{
		g_pf_flags.u = 1;
		(*format)++;
		return (1);
	}
	if (**format == 'x')
	{
		g_pf_flags.x = 1;
		(*format)++;
		return (1);
	}
	if (**format == 'X')
	{
		g_pf_flags.xu = 1;
		(*format)++;
		return (1);
	}
	return (set_format_3(format));
}

int		set_format(const char **format)
{
	if (**format == 'd')
	{
		g_pf_flags.d = 1;
		(*format)++;
		return (1);
	}
	if (**format == 'i')
	{
		g_pf_flags.i = 1;
		(*format)++;
		return (1);
	}
	if (**format == 'o')
	{
		g_pf_flags.o = 1;
		(*format)++;
		return (1);
	}
	return (set_format_2(format));
}

void	set_struct_5(const char **format)
{
	if (**format == 'L')
	{
		g_pf_flags.lu = 1;
		(*format)++;
	}
	if (**format != 'L' && **format != 'l' && **format != 'h'
		&& **format != '#' && **format != '+' && **format != '-'
		&& **format != ' ' && **format != '0' && **format != 'd'
		&& **format != 'i' && **format != 'u' && **format != 'o'
		&& **format != 'x' && **format != 'X' && !(**format >= '1'
		&& **format <= '9') && **format != 'c' && **format != 's'
		&& **format != 'p' && **format != '.' && **format != 'f')
		(*format)++;
}
