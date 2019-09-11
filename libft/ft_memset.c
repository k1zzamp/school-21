/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:12:52 by stross            #+#    #+#             */
/*   Updated: 2019/09/11 18:50:11 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*arr;

	c = (unsigned char)c;
	arr = (unsigned char*)str;
	while (n--)
		*arr++ = c;
	return (str);
}
