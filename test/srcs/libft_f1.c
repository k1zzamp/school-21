/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_f1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:14:37 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 20:56:57 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			check_size(int n)
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

char				*ft_itoa(int n)
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

void				*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*arr;

	c = (unsigned char)c;
	arr = (unsigned char*)str;
	while (n--)
		*arr++ = c;
	return (str);
}

char				*ft_strnew(size_t size)
{
	void			*p;

	if (size < size + 1)
	{
		p = malloc(size + 1);
		if (p)
		{
			p = (char*)ft_memset(p, '\0', size + 1);
			return (p);
		}
		else
			return (NULL);
	}
	return (NULL);
}

int					ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == ' ' || c == '\r')
		return (1);
	else
		return (0);
}
