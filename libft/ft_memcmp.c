/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:21:19 by stross            #+#    #+#             */
/*   Updated: 2019/09/10 18:46:35 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (n == 0)
		return (0);
	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	while (*s1 == *s2 && n--)
	{
		if (n)
		{
			s1++;
			s2++;
		}
	}
	return ((int)*s1 - *s2);
}
