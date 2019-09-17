/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:18:42 by stross            #+#    #+#             */
/*   Updated: 2019/09/05 14:09:35 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = 1;
	c = (unsigned char)c;
	while (*str)
	{
		str++;
		i++;
	}
	if (c == '\0')
		return ((char*)str);
	while (i--)
	{
		if (c == *str)
			return ((char*)str);
		str--;
	}
	return (NULL);
}
