/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_f2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:15:33 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 15:16:09 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_atoi(const char *str)
{
	unsigned long	sum;
	int				sign;

	sum = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return ((int)sum * sign);
		sum *= 10;
		sum += (*str - '0');
		str++;
	}
	if (sum <= 9223372036854775808uL)
		return ((int)sum * sign);
	return (sign == 1 ? -1 : 0);
}

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*arr;

	arr = (unsigned char*)str;
	while (n--)
		*arr++ = 0;
}


void	*ft_memalloc(size_t size)
{
	void	*p;

	if (size == 0)
		return (NULL);
	p = malloc(size);
	if (p)
	{
		ft_bzero(p, size);
		return (p);
	}
	else
		return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}
