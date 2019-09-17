/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:03:14 by stross            #+#    #+#             */
/*   Updated: 2019/09/09 14:54:22 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_size(int n)
{
	unsigned int	len;
	long int		nb;

	nb = (long int)n;
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

char		*ft_itoa(int n)
{
	long int		buf;
	unsigned int	size;
	char			*arr;

	if (n == 0)
	{
		arr = (char*)malloc(2);
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	size = (check_size((n)) + (n < 0 ? 2 : 1));
	arr = (char*)malloc(size);
	if (!arr)
		return (NULL);
	buf = (long int)n;
	arr[--size] = '\0';
	buf = buf < 0 ? buf * -1 : buf * 1;
	while (size--)
	{
		arr[size] = (buf % 10) + '0';
		buf /= 10;
	}
	arr[0] = (n < 0 ? '-' : arr[0]);
	return (arr);
}
