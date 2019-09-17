/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:13:03 by stross            #+#    #+#             */
/*   Updated: 2019/09/07 18:18:15 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		{
			arr[i] = (*f)(i, *s);
			s++;
			i++;
		}
		arr[i] = '\0';
		return (arr);
	}
	return (NULL);
}
