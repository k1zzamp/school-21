/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <stross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:27:16 by stross            #+#    #+#             */
/*   Updated: 2019/12/23 15:27:16 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char		*ft_strnew(size_t size)
{
	void			*p;

	if (size < size + 1)
	{
		p = malloc(size + 1);
		if (p)
		{
			p = (char*)ft_memset(p, '\0', size + 1);
			return (p);
		}
		else
			return (NULL);
	}
	return (NULL);
}

static int		count_words(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			i++;
			while (*s != c && *s)
				s++;
		}
	}
	return (i);
}

static int		get_word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char		**free_mem(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str2;

	if (!s || !(str2 = (char **)malloc(sizeof(*str2) *
									   (count_words(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < count_words(s, c))
	{
		k = 0;
		if (!(str2[i] = ft_strnew(get_word_len(&s[j], c) + 1)))
			return (str2 = free_mem(str2));
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str2[i][k++] = s[j++];
		str2[i][k] = '\0';
	}
	str2[i] = 0;
	return (str2);
}