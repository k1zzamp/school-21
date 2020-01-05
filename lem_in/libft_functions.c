/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <stross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:22:05 by stross            #+#    #+#             */
/*   Updated: 2019/12/23 14:29:32 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_strdup(char *str)
{
	char			*copy;
	unsigned int	i;

	i = 0;
	copy = (char*)malloc(ft_strlen(str) + 1);
	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strcat(char *s1, const char *s2)
{
	char	*copy;

	copy = s1;
	while (*copy)
		copy++;
	while (*s2)
		*copy++ = *s2++;
	*copy = '\0';
	return (s1);
}

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int 	ft_strlen(char *str)
{
	int 	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

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