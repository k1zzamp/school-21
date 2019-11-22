/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:29:23 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 16:39:41 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	check_mod(unsigned int i)
{
	if (g_pf_flags.h)
		i = (unsigned short)i;
	if (g_pf_flags.hh)
		i = (unsigned char)i;
	return (i);
}

long	check_mod_ull(long i) // return was unsigned
{
	if (g_pf_flags.h)
		i = (unsigned short)i;
	if (g_pf_flags.hh)
		i = (unsigned char)i;
	return (i);
}

unsigned int	check_mod_ui(int i) // return was unsigned
{
	if (g_pf_flags.h)
		i = (unsigned short)i;
	if (g_pf_flags.hh)
		i = (unsigned char)i;
	return (i);
}

long	check_mod_l(long i) // return was unsigned
{
	if (g_pf_flags.h)
		i = (short)i;
	if (g_pf_flags.hh)
		i = (char)i;
	return (i);
}

void	print_d(va_list arg)
{
	if (!(g_pf_flags.l || g_pf_flags.ll))
	{
		print_int(arg);
	}
	if ((g_pf_flags.l || g_pf_flags.ll))
	{
		print_long(arg);
	}
}
