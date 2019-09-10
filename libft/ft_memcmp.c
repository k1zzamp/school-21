/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:21:19 by stross            #+#    #+#             */
/*   Updated: 2019/09/09 22:42:47 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (!str1)
		CRASH[0] += 1;
	if (n == 0)
		return (0);
	i = 0;
	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	while (*s1 == *s2 && ++i < n)
	{
		s1++;
		s2++;
	}
	return ((int)*s1 - *s2);
}
