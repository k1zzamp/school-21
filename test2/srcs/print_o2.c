/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:49:19 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 22:07:34 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_luf_help10(void)
{
	ft_putchar_g(' ');
	g_pf_flags.width--;
}

void	print_o(va_list arg)
{
	print_o_l(arg);
}

void	print_lf_help10(void)
{
	ft_putchar_g(' ');
	g_pf_flags.width--;
}

void	print_o_l_help5(long num, int *z_flag)
{
	if (g_pf_flags.flag_zero == 1 && !g_pf_flags.dot)
	{
		if (g_pf_flags.flag_hash && num != 0 && !(*z_flag))
			g_pf_flags.x == 1 ? ft_putstr_g(OCT) : ft_putstr_g(OCT);
		ft_putchar_g('0');
		*z_flag = 1;
	}
	else
		ft_putchar_g(' ');
	g_pf_flags.width--;
}
