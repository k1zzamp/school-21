/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 22:57:01 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 23:05:37 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_color(char c)
{
	if (c == 'R')
		ft_putstr(RED);
	else if (c == 'G')
		ft_putstr(GREEN);
	else if (c == 'B')
		ft_putstr(BLUE);
	else if (c == 'E')
		ft_putstr(RESET);
}

int		check_color(const char *format)
{
	format++;
	if (*format)
	{
		if (*format == 'R' || *format == 'G' || *format == 'B'
				|| *format == 'E')
		{
			if (*(format + 1) == '}')
			{
				print_color(*format);
				return (3);
			}
		}
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (*str)
	{
		while (*str)
			ft_putchar(*str++);
	}
}
