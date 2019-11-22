/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:44:44 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 18:55:38 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c_help(char c)
{
	ft_putchar_g(c);
	while (g_pf_flags.width > 1)
	{
		g_pf_flags.width--;
		g_pf_flags.flag_zero == 1 ? ft_putchar_g('0') : ft_putchar_g(' ');
	}
}

void	print_c(va_list arg)
{
	char 	c;

	c = va_arg(arg, int);
	if (g_pf_flags.flag_minus)
		print_c_help(c);
	else
	{
		while (g_pf_flags.width > 1)
		{
			g_pf_flags.width--;
			g_pf_flags.flag_zero == 1 ? ft_putchar_g('0') : ft_putchar_g(' ');
		}
		ft_putchar_g(c);
	}
}
