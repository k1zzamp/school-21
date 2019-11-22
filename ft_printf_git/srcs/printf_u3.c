/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:49:42 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 15:50:15 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(va_list arg)
{
	if (!(g_pf_flags.l || g_pf_flags.ll))
	{
		if (!(g_pf_flags.flag_hash || g_pf_flags.flag_plus
			  || g_pf_flags.flag_minus || g_pf_flags.flag_space))
			print_ui_no_f(arg);
		else
			print_ui_m(arg);
	}
	if ((g_pf_flags.l || g_pf_flags.ll))
	{
		if (!(g_pf_flags.flag_hash || g_pf_flags.flag_plus
			  || g_pf_flags.flag_minus || g_pf_flags.flag_space))
			print_ui_long_no_f(arg);
		else
			print_long_ui_m(arg);
	}
}
