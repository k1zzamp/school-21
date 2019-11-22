/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:57:14 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 20:47:55 by mtytos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s_nom_help(char *str, int len)
{
	while (g_pf_flags.width > g_pf_flags.precision || g_pf_flags.width > len)
	{
		g_pf_flags.flag_zero == 1 ? ft_putchar_g('0') : ft_putchar_g(' ');
		g_pf_flags.width--;
	}
	while (g_pf_flags.precision && *str)
	{
		ft_putchar_g(*str++);
		g_pf_flags.precision--;
	}
}

void	print_s_nom(char *str, int len)
{
	if (g_pf_flags.dot && g_pf_flags.precision == 0)
	{
		while (g_pf_flags.width > 0)
		{
			ft_putchar_g(' ');
			g_pf_flags.width--;
		}
	}
	else
	{
		if (g_pf_flags.precision == 0)
		{
			while (g_pf_flags.width - len > 0)
			{
				g_pf_flags.flag_zero == 1 ?
					ft_putchar_g('0') : ft_putchar_g(' ');
				g_pf_flags.width--;
			}
			ft_putstr_g(str);
		}
		if (g_pf_flags.precision > 0)
			print_s_nom_help(str, len);
	}
}

void	print_s_m_help(char *str, int space)
{
	while (g_pf_flags.precision && *str)
	{
		ft_putchar_g(*str++);
		g_pf_flags.precision--;
		space++;
	}
	while (g_pf_flags.width > space)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
}

void	print_s_m(char *str, int len)
{
	int	space;

	space = 0;
	if (g_pf_flags.dot && g_pf_flags.precision == 0)
	{
		while (g_pf_flags.width > 0)
		{
			ft_putchar_g(' ');
			g_pf_flags.width--;
		}
	}
	else
	{
		if (g_pf_flags.precision == 0)
		{
			ft_putstr_g(str);
			while (g_pf_flags.width - len > 0)
			{
				ft_putchar_g(' ');
				g_pf_flags.width--;
			}
		}
		if (g_pf_flags.precision > 0)
			print_s_m_help(str, space);
	}
}

void	print_s(va_list arg)
{
	char		*str;
	static char	null_s[7] = "(null)";
	int			len;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = null_s;
	len = ft_strlen(str);
	if (!(g_pf_flags.flag_minus))
		print_s_nom(str, len);
	if (g_pf_flags.flag_minus)
		print_s_m(str, len);
}
