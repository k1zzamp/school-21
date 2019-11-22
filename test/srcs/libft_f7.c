/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_f7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:28:11 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 15:29:02 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_size_ul(unsigned long n)
{
	unsigned int	len;
	unsigned long	nb;

	nb = (unsigned long)n;
	len = 0;
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char		*ft_ultoa(unsigned long n)
{
	unsigned long	buf;
	unsigned int	size;
	char			*arr;

	if (n == 0)
	{
		arr = (char*)malloc(2);
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	size = (check_size_ul(n) + 1);
	arr = (char*)malloc(size);
	if (!arr)
		return (NULL);
	buf = (unsigned long)n;
	arr[--size] = '\0';
	while (size--)
	{
		arr[size] = (buf % 10) + '0';
		buf /= 10;
	}
	return (arr);
}
