/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:23:42 by stross            #+#    #+#             */
/*   Updated: 2019/09/11 22:53:39 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!src && !dest)
		return (NULL);
	d = (unsigned char*)dest;
	s = (const unsigned char*)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
