/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:48:04 by stross            #+#    #+#             */
/*   Updated: 2019/11/05 16:02:40 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_str(va_list arg)
{
	char	*str;

	str = va_arg(arg, char*);
	ft_putstr(str);
}

static void	print_dec(va_list arg)
{
	int	num;

	num = va_arg(arg, int);
	ft_putnbr(num);
}

static int	parser(va_list arg, const char *format)
{
	int	space;
	int	ret;

	ret = 2;
	space = 0;
	if (*format >= '0' && *format <= '9')
	{
		space = ft_atoi(format);
		format += 1;
		ret++;
	}
	while (space--)
		ft_putchar(' ');
	if (*format == 'd')
		print_dec(arg);
	else if (*format == 's')
		print_str(arg);
	return (ret);
}

void		ft_printf(const char *format, ...)
{
	va_list arg;

	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format += parser(arg, format + 1);
			continue ;
		}
		ft_putchar(*format);
		format++;
	}
	va_end(arg);
}
