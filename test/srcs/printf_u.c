/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:36:35 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 20:40:45 by mtytos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ui_m_help(int len, char *str)
{
	while (g_pf_flags.precision - len > 0)
	{
		ft_putchar_g('0');
		g_pf_flags.precision--;
		g_pf_flags.width--;
	}
	ft_putstr_g(str);
	while (g_pf_flags.width - len > 0)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
}

void	print_ui_m(va_list arg)
{
	unsigned int	i;
	int				len;
	char			*str;

	i = va_arg(arg, unsigned int);
	i = check_mod(i);
	str = ft_uitoa(i);
	len = ft_strlen(str);
	if (g_pf_flags.precision - len > 0)
		print_ui_m_help(len, str);
	else
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
	free(str);
}

void	print_ui_no_f_help(char *str, int len)
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

void	print_ui_no_f(va_list arg)
{
	unsigned int	i;
	int				len;
	char			*str;

	i = va_arg(arg, unsigned int);
	i = check_mod(i);
	str = ft_uitoa(i);
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
		print_ui_no_f_help(str, len);
	free(str);
}
