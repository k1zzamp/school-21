/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:32:09 by stross            #+#    #+#             */
/*   Updated: 2019/09/07 18:16:12 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	len;
	unsigned int	i;
	char			*arr;

	if (s && f)
	{
		i = 0;
		len = ft_strlen(s);
		arr = (char*)malloc(len + 1);
		if (!arr)
			return (NULL);
		while (*s)
			arr[i++] = (*f)(*s++);
		arr[i] = '\0';
		return (arr);
	}
	return (NULL);
}
