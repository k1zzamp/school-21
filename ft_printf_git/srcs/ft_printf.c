/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:12:56 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 15:13:51 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags g_pf_flags;
int		g_pf_ret = 0;

int		ft_printf(const char *format, ...)
{
	va_list arg;

	if (format == NULL)
		return (0);
	va_start(arg, format);
	parser(arg, format);
	va_end(arg);
	return (g_pf_ret);
}
