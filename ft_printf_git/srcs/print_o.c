/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:48:45 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 19:03:03 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_o_l_help2(void)
{
	if (g_pf_flags.flag_hash)
	{
		ft_putchar_g('0');
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

void	print_o_l_help1(void)
{
	if (g_pf_flags.flag_minus)
		print_o_l_help2();
	if (!g_pf_flags.flag_minus)
	{
		if (g_pf_flags.flag_hash)
			g_pf_flags.width--;
		if (g_pf_flags.flag_plus)
			g_pf_flags.width--;
		while (g_pf_flags.width > 0)
		{
			ft_putchar_g(' ');
			g_pf_flags.width--;
		}
		if (g_pf_flags.flag_hash)
			ft_putchar_g('0');
	}
}

void	print_o_l_help4(long num, char *str, int len, int z_flag)
{
	if (g_pf_flags.flag_hash && num != 0 && g_pf_flags.precision < len)
		g_pf_flags.width--;
	while (g_pf_flags.width > len && g_pf_flags.width > g_pf_flags.precision)
	{
		if (g_pf_flags.flag_zero == 1 && ! g_pf_flags.dot)
		{
			if (g_pf_flags.flag_hash && num != 0 && !z_flag)
				g_pf_flags.x == 1 ? ft_putstr_g(OCT) : ft_putstr_g(OCT);
			ft_putchar_g('0');
			z_flag = 1;
		}
		else
			ft_putchar_g(' ');
		g_pf_flags.width--;
	}
	while (g_pf_flags.precision > len)
	{
		if (!z_flag && g_pf_flags.flag_hash && num != 0)
		{
			g_pf_flags.x == 1 ? ft_putstr_g(OCT) : ft_putstr_g(OCT);
			z_flag = 1;
			g_pf_flags.precision--;
		}
		ft_putchar_g('0');
		g_pf_flags.precision--;
	}
	if (g_pf_flags.flag_hash && !z_flag && num != 0)
		g_pf_flags.x == 1 ? ft_putstr_g(OCT) : ft_putstr_g(OCT);
	ft_putstr_g(str);
}

void	print_o_l_help3(long num, char *str, int len, int z_flag)
{
	if (g_pf_flags.flag_minus)
	{
		if (g_pf_flags.flag_hash && num != 0)
		{
			g_pf_flags.x == 1 ? ft_putstr_g(OCT) : ft_putstr_g(OCT);
			g_pf_flags.width -= 1;
			g_pf_flags.precision--;
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
	else
		print_o_l_help4(num, str, len, z_flag);
}

void	print_o_l(va_list arg)
{
	long 	num;
	char	*str;
	int 	len;
	int 	z_flag;

	z_flag = 0;
	num = va_arg(arg, long);
	num = check_mod_ull(num);
	str = ft_itoa_base_gt(num, 8, g_pf_flags.x == 1 ? 'a' : 'A');
	len = ft_strlen(str);
	if (num == 0 && g_pf_flags.precision == 0 && g_pf_flags.dot)
		print_o_l_help1();
	else
		print_o_l_help3(num, str, len, z_flag);
	free(str);
}
