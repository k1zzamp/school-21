/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:36:38 by stross            #+#    #+#             */
/*   Updated: 2019/09/07 17:11:00 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	unsigned int pos;
	unsigned int i;

	if (!*find)
		return ((char*)str);
	pos = 0;
	while (str[pos] != '\0' && (size_t)pos < n)
	{
		if (str[pos] == find[0])
		{
			i = 1;
			while (find[i] != '\0' && str[pos + i] == find[i] &&
					(size_t)(pos + i) < n)
				++i;
			if (find[i] == '\0')
				return ((char*)&str[pos]);
		}
		++pos;
	}
	return (0);
}
