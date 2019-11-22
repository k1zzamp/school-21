/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_f6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:26:22 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 15:27:45 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_size_nom(int n)
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

char		*ft_itoa_nom(int n)
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
	size = (check_size_nom((n)) + 1);
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
	return (arr);
}

static int	check_size_ui(unsigned int n)
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

char		*ft_uitoa(unsigned int n)
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
	size = (check_size_ui(n) + 1);
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
