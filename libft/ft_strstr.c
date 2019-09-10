/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:36:38 by stross            #+#    #+#             */
/*   Updated: 2019/09/07 17:08:51 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	unsigned int	count;
	unsigned int	scount;

	count = 0;
	scount = 0;
	if (*find == '\0')
		return ((char*)str);
	while (str[count])
	{
		while (str[count + scount] == find[scount])
		{
			scount++;
			if (find[scount] == '\0')
				return ((char*)(str + count));
		}
		scount = 0;
		count++;
	}
	return (NULL);
}
