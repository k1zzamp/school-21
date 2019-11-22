/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:49:19 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 21:57:57 by stross           ###   ########.fr       */
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
