/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_f5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:22:09 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 15:23:52 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_size_ltoa(long n)
{
	unsigned int	len;
	long int		nb;

	nb = (long)n;
	if (nb < 0)
		nb *= -1;
	len = 0;
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char		*ft_itoa_ltoa(long n)
{
	long			buf;
	unsigned int	size;
	char			*arr;

	if (n == 0)
	{
		arr = (char*)malloc(2);
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	buf = (long)(n * (n < 0 ? -1 : 1));
	size = (check_size_ltoa((n)) + 1);
	arr = (char*)malloc(size);
	if (!arr)
		return (NULL);
	arr[--size] = '\0';
	while (size--)
	{
		arr[size] = (buf % 10) + '0';
		buf /= 10;
	}
	return (arr);
}

static size_t	digit_count_pf(uintptr_t value, unsigned int base)
{
	uintptr_t		temp;
	size_t			i;

	i = 0;
	temp = value;
	if (value == 0)
		return (1);
	while (temp)
	{
		i++;
		temp /= base;
	}
	return (i);
}

char			*ft_itoa_base_pf(uintptr_t value, unsigned int base)
{
	static char		simbols[17] = "0123456789abcdef";
	char			*arr;
	size_t			size;
	uintptr_t		temp;

	temp = value;
	size = digit_count_pf(value, base);
	if (!(arr = (char *)ft_memalloc((size + (1)) * sizeof(char))))
		return (NULL);
	if (base == 10)
	{
		arr[0] = '-';
		size++;
	}
	else if (value == 0)
		arr[0] = simbols[0];
	while (temp != 0)
	{
		arr[size - 1] = simbols[(temp % base)];
		temp /= base;
		size--;
	}
	return (arr);
}

void	null_struct(void)
{
	g_pf_flags.flag_hash = 0;
	g_pf_flags.flag_zero = 0;
	g_pf_flags.flag_minus = 0;
	g_pf_flags.flag_plus = 0;
	g_pf_flags.flag_space = 0;
	g_pf_flags.width = 0;
	g_pf_flags.precision = 0;
	g_pf_flags.hh = 0;
	g_pf_flags.h = 0;
	g_pf_flags.l = 0;
	g_pf_flags.ll = 0;
	g_pf_flags.L = 0;
	g_pf_flags.d = 0;
	g_pf_flags.i = 0;
	g_pf_flags.o = 0;
	g_pf_flags.u = 0;
	g_pf_flags.x = 0;
	g_pf_flags.X = 0;
	g_pf_flags.c = 0;
	g_pf_flags.s = 0;
	g_pf_flags.p = 0;
	g_pf_flags.f = 0;
	g_pf_flags.dot = 0;
}
