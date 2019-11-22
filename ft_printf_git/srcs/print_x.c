/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:32:51 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 17:33:09 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x_l_help1(void)
{
	if (g_pf_flags.flag_minus)
	{
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
	if (!g_pf_flags.flag_minus)
	{
		if (g_pf_flags.flag_plus)
			g_pf_flags.width--;
		while (g_pf_flags.width > 0)
		{
			ft_putchar_g(' ');
			g_pf_flags.width--;
		}
	}
}

void	print_x_l_help2(long num, int len, char *str)
{
	if (g_pf_flags.flag_hash && num != 0)
	{
		g_pf_flags.x == 1 ? ft_putstr_g(HEX) : ft_putstr_g(HEXU);
		g_pf_flags.width -= 2;
	}
	while (g_pf_flags.precision > 0 && g_pf_flags.precision > len)
	{
		ft_putchar_g('0');
		g_pf_flags.precision--;
		g_pf_flags.width--;
	}
	ft_putstr_g(str);
	while (g_pf_flags.width > len)
	{
		ft_putchar_g(' ');
		g_pf_flags.width--;
	}
}

void	print_x_l_help4(long num, char *str, int *z_flag)
{
	if (g_pf_flags.flag_hash && num != 0 && !(*z_flag))
		g_pf_flags.x == 1 ? ft_putstr_g(HEX) : ft_putstr_g(HEXU);
	ft_putchar_g('0');
	*z_flag = 1;
}

void	print_x_l_help3(long num, int len, char *str, int z_flag)
{
	if (g_pf_flags.flag_hash && num != 0)
		g_pf_flags.width -= 2;
	while (g_pf_flags.width > len && g_pf_flags.width > g_pf_flags.precision)
	{
		if (g_pf_flags.flag_zero == 1 && ! g_pf_flags.dot)
			print_x_l_help4(num, &z_flag)
		else
			ft_putchar_g(' ');
		g_pf_flags.width--;
	}
	while (g_pf_flags.precision > len)
	{
		if (!z_flag && g_pf_flags.flag_hash && num != 0)
		{
			g_pf_flags.x == 1 ? ft_putstr_g(HEX) : ft_putstr_g(HEXU);
			z_flag = 1;
		}
		ft_putchar_g('0');
		g_pf_flags.precision--;
	}
	if (g_pf_flags.flag_hash && !z_flag && num != 0)
		g_pf_flags.x == 1 ? ft_putstr_g(HEX) : ft_putstr_g(HEXU);
	ft_putstr_g(str);
}

void	print_x_l(va_list arg)
{
	long 	num;
	char	*str;
	int 	len;
	int 	z_flag;

	z_flag = 0;
	num = va_arg(arg, long);
	num = check_mod_ull(num);
	str = ft_itoa_base_gt(num, 16, g_pf_flags.x == 1 ? 'a' : 'A');
	len = ft_strlen(str);
	if (num == 0 && g_pf_flags.precision == 0 && g_pf_flags.dot)
		print_x_l_help1();
	else
	{
		if (g_pf_flags.flag_minus)
			print_x_l_help2(num, len, str);
		else
			print_x_l_help3(num, len, str, z_flag);
	}
	free(str);
}
