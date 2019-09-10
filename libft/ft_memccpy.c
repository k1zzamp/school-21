/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:55:49 by stross            #+#    #+#             */
/*   Updated: 2019/09/06 14:29:29 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	t_bool				flag;

	d = (unsigned char*)dest;
	s = (const unsigned char*)src;
	c = (unsigned char)c;
	flag = FALSE;
	while (n--)
	{
		*d = *s;
		if (*s == c)
		{
			*d = *s;
			flag = TRUE;
			break ;
		}
		d++;
		s++;
	}
	if (flag)
		return ((void*)++d);
	else
		return (NULL);
}
