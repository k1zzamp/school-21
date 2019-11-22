/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:34:44 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 19:00:11 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_long_help6(long x, char *str)
{
	if (g_pf_flags.flag_plus && x >= 0)
	{
		ft_putchar_g('+');
		g_pf_flags.width--;
	}
	if (x < 0)
	{
		g_pf_flags.width--;
		ft_putchar_g('-');
	}
	if (g_pf_flags.flag_space && !g_pf_flags.flag_plus && x >= 0)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
	while (g_pf_flags.width > 0)
	{
		ft_putchar_g('0');
		g_pf_flags.width--;
	}
	ft_putstr_g(str);
}

void	print_long_help3(long x, int len, int pres, char *str)
{
	if (g_pf_flags.flag_minus)
		print_long_help4(x, len, pres, str);
	else
	{
		if (g_pf_flags.precision > 0)
			g_pf_flags.flag_zero = 0;
		if (g_pf_flags.precision > len)
		{
			g_pf_flags.width -= g_pf_flags.precision;
		}
		else
			g_pf_flags.width -= len;
		if (g_pf_flags.flag_zero)
			print_long_help6(x, str);
		if (!g_pf_flags.flag_zero)
			print_long_help7(x, len, str);
	}
}

void	print_long(va_list arg)
{
	long		x;
	char 		*str;
	char 		*to_free;
	int			len;
	int 		pres;

	pres = 0;
	x = va_arg(arg, long);
	str = ft_ltoa(x);
	to_free = str;
	to_free = str;
	if (x < 0)
		str++;
	len = ft_strlen(str);
	if (x == 0 && g_pf_flags.precision == 0 && g_pf_flags.dot)
		print_long_help1();
	else
		print_long_help3(x, len, pres, str);
	free(to_free);
}
