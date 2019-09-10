/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:26:02 by stross            #+#    #+#             */
/*   Updated: 2019/09/09 12:48:41 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*arr;

	if (s1 && s2)
		len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	else if (s1)
		len = ft_strlen((char*)s1);
	else if (s2)
		len = ft_strlen((char*)s2);
	else
		return (NULL);
	arr = (char*)malloc(len + 1);
	if (!arr)
		return (NULL);
	if (s1)
		arr = ft_strcpy(arr, (char*)s1);
	else
		arr = ft_strcpy(arr, (char*)s2);
	if (s1 && s2)
		arr = ft_strcat(arr, (char*)s2);
	return (arr);
}
