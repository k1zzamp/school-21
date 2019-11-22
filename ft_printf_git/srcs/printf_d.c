/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:52:09 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 16:23:45 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int_help2(void)
{
	if (g_pf_flags.flag_plus)
	{
		ft_putchar_g('+');
		g_pf_flags.width--;
	}
	if (g_pf_flags.flag_space && !g_pf_flags.flag_plus)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
	while (g_pf_flags.width > 0)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
}

void	print_int_help1(void)
{
	if (g_pf_flags.flag_minus)
		print_int_help2();
	if (!g_pf_flags.flag_minus)
	{
		if (g_pf_flags.flag_plus)
			g_pf_flags.width--;
		while (g_pf_flags.width > 0)
		{
			ft_putchar_g(' ');
			g_pf_flags.width--;
		}
		if (g_pf_flags.flag_plus)
			ft_putchar_g('+');
	}
}

void	print_int_help5(long x)
{
	if (g_pf_flags.flag_space && !g_pf_flags.flag_plus && x >= 0)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
	if (g_pf_flags.flag_plus && x >= 0)
	{
		ft_putchar_g('+');
		g_pf_flags.width--;
	}
}

void	print_int_help4(long x, int len, int pres, char *str)
{
	print_int_help5(x);
	if (x < 0)
	{
		ft_putchar_g('-');
		g_pf_flags.width--;
	}
	pres = g_pf_flags.precision - len;
	while (pres > 0)
	{
		ft_putchar_g('0');
		g_pf_flags.width--;
		pres--;
	}
	ft_putstr_g(str);
	g_pf_flags.width -= len;
	while (g_pf_flags.width > 0)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
}

void	print_int_help7(long x, int len, char *str)
{
	if (g_pf_flags.flag_plus || x < 0)
		g_pf_flags.width--;
	if (g_pf_flags.flag_space && !g_pf_flags.flag_plus && x >= 0)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
	while (g_pf_flags.width > 0)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
	if (g_pf_flags.flag_plus && x >= 0)
		ft_putchar_g('+');
	if (x < 0)
		ft_putchar_g('-');
	while (g_pf_flags.precision > len)
	{
		ft_putchar_g('0');
		g_pf_flags.precision--;
	}
	ft_putstr_g(str);
}
