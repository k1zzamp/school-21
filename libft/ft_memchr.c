/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:21:14 by stross            #+#    #+#             */
/*   Updated: 2019/09/11 18:50:55 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*s;

	s = (const unsigned char*)str;
	c = (unsigned char)c;
	while (n--)
	{
		if (*s == c)
			return ((void*)s);
		s++;
	}
	return (NULL);
}
