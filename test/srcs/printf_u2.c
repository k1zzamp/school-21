/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:45:13 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 20:41:56 by mtytos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ui_long_no_f_help(char *str, int len)
{
	while (g_pf_flags.width > len && g_pf_flags.width > g_pf_flags.precision)
	{
		g_pf_flags.width--;
		g_pf_flags.flag_zero == 1 &&
			g_pf_flags.precision == 0 ? ft_putchar_g('0') : ft_putchar_g(' ');
	}
	while ((g_pf_flags.precision - len) > 0)
	{
		g_pf_flags.precision--;
		ft_putchar_g('0');
	}
	ft_putstr_g(str);
}

void	print_ui_long_no_f(va_list arg)
{
	unsigned long	i;
	int				len;
	char			*str;

	i = va_arg(arg, unsigned long);
	str = ft_ultoa(i);
	len = ft_strlen(str);
	if (i == 0 && g_pf_flags.dot && g_pf_flags.precision == 0)
	{
		while (g_pf_flags.width > 0)
		{
			ft_putchar_g(' ');
			g_pf_flags.width--;
		}
	}
	else
		print_ui_long_no_f_help(str, len);
	free(str);
}

void	print_long_ui_m_help1(char *str, int len)
{
	while (g_pf_flags.precision - len > 0)
	{
		ft_putchar_g('0');
		g_pf_flags.precision--;
		g_pf_flags.width--;
	}
	while (g_pf_flags.width - len > 0)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
	ft_putstr_g(str);
}

void	print_long_ui_m_help2(char *str, int len, unsigned long i)
{
	if (i != 0 || g_pf_flags.dot == 0)
		ft_putstr_g(str);
	else
		ft_putchar_g(' ');
	while (g_pf_flags.width - len > 0)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
}

void	print_long_ui_m(va_list arg)
{
	unsigned long	i;
	int				len;
	char			*str;

	i = va_arg(arg, unsigned long);
	str = ft_ultoa(i);
	len = ft_strlen(str);
	if (g_pf_flags.precision - len > 0)
		print_long_ui_m_help1(str, len);
	else
		print_long_ui_m_help2(str, len, i);
	free(str);
}
