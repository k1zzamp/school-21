/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:58:53 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 18:23:48 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_Lf_help1(double x, int len, char *str)
{
	if (g_pf_flags.flag_plus && x > 0)
	{
		ft_putchar_g('+');
		len++;
	}
	if (!g_pf_flags.flag_plus && g_pf_flags.flag_space && x > 0)
	{
		ft_putchar_g(' ');
		len++;
	}
	ft_putstr_g(str);
	if (g_pf_flags.dot && g_pf_flags.precision == 0 && g_pf_flags.flag_hash)
		ft_putchar_g('.');
	while (g_pf_flags.width > len)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
}

void	print_Lf_help3(double x, int len, char *str)
{
	if (x < 0)
	{
		ft_putchar_g('-');
		str++;
	}
	if (x > 0 && g_pf_flags.flag_plus)
	{
		ft_putchar_g('+');
		len++;
	}
	if (g_pf_flags.flag_space && g_pf_flags.width > len && x >= 0)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
	while (g_pf_flags.width > len)
	{
		ft_putchar_g('0');
		g_pf_flags.width--;
	}
	ft_putstr_g(str);
	if (g_pf_flags.dot && g_pf_flags.precision == 0 && g_pf_flags.flag_hash)
		ft_putchar_g('.');
}

void	print_Lf_help2(double x, int len, char *str)
{
	if (g_pf_flags.flag_zero && g_pf_flags.width > len)
		print_Lf_help3(x, len, str);
	else
	{
		if (g_pf_flags.flag_space && g_pf_flags.width <= len && !g_pf_flags.flag_plus && x > 0)
		{
			ft_putchar_g(' ');
			len++;
		}
		if (g_pf_flags.flag_plus)
		{
			if(x > 0)
				len++;
		}
		while (g_pf_flags.width > len)
		{
			ft_putchar_g(' ');
			g_pf_flags.width--;
		}
		if (g_pf_flags.flag_plus && x > 0)
			ft_putchar_g('+');
		ft_putstr_g(str);
		if (g_pf_flags.dot && g_pf_flags.precision == 0 && g_pf_flags.flag_hash)
			ft_putchar_g('.');
	}
}

void	print_Lf(va_list arg)
{
	double		x;
	char 		*str;
	char 		*to_free;
	int			len;

	x = va_arg(arg, long double);
	str = ft_float(x, (g_pf_flags.precision == 0 ? 6 : g_pf_flags.precision));
	if (g_pf_flags.dot && g_pf_flags.precision == 0)
	{
		free(str);
		str = ft_float(x, 0);
	}
	len = ft_strlen(str);
	if (g_pf_flags.dot && g_pf_flags.precision == 0 && g_pf_flags.flag_hash)
		len++;
	to_free = str;
	if (g_pf_flags.flag_minus)
		print_Lf_help1(x, len, str);
	else
	print_Lf_help2(x, len, str);
	free(to_free);
}

void	print_fl(va_list arg)
{
	if (g_pf_flags.f && !g_pf_flags.L)
		print_lf(arg);
	if (g_pf_flags.f && g_pf_flags.L)
		print_Lf(arg);
}
