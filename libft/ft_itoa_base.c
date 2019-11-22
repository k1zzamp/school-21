/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:34:05 by stross            #+#    #+#             */
/*   Updated: 2019/10/16 16:31:16 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static size_t	digit_count(int value, unsigned int base)
{
	unsigned int	temp;
	size_t			i;

	i = 0;
	temp = (value < 0) ? -(value) : value;
	if (value == 0)
		return (1);
	while (temp)
	{
		i++;
		temp /= base;
	}
	return (i);
}

char			*ft_itoa_base(int value, unsigned int base)
{
	static char		simbols[17] = "0123456789abcdef";
	char			*arr;
	size_t			size;
	unsigned int	temp;

	temp = value < 0 ? -value : value;
	size = digit_count(value, base);
	if (!(arr = (char *)ft_memalloc((size + (value < 0
							&& base == 10 ? 2 : 1)) * sizeof(char))))
		return (NULL);
	if (value < 0 && base == 10)
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
