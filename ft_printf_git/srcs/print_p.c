/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:09:17 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 17:09:44 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p_help(int len, char *str)
{
	while (g_pf_flags.width > len)
	{
		g_pf_flags.flag_zero == 1 ? ft_putchar_g('0') : ft_putchar_g(' ');
		g_pf_flags.width--;
	}
	ft_putstr_g(HEX);
	ft_putstr_g(str);
}

void	print_p(va_list arg)
{
	uintptr_t 	p;
	char 	*str;
	int 	len;

	p = (uintptr_t)va_arg(arg, void *);
	str = ft_itoa_base_pf(p, 16);
	len = ft_strlen(str) + 2;
	if (g_pf_flags.flag_minus)
	{
		ft_putstr_g(HEX);
		ft_putstr_g(str);
		while (g_pf_flags.width > len)
		{
			ft_putchar_g(' ');
			g_pf_flags.width--;
		}
	}
	else
		print_p_help(len, str);
	free(str);
}
