/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <stross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:23:18 by stross            #+#    #+#             */
/*   Updated: 2019/12/29 14:08:42 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_bzero(void *str, size_t n)
{
	unsigned char	*arr;

	arr = (unsigned char*)str;
	while (n--)
		*arr++ = 0;
}

void		*ft_memalloc(size_t size)
{
	void	*p;

	if (size == 0)
		return (NULL);
	p = malloc(size);
	if (p)
	{
		ft_bzero(p, size);
		return (p);
	}
	else
		return (NULL);
}

void		*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*arr;

	c = (unsigned char)c;
	arr = (unsigned char*)str;
	while (n--)
		*arr++ = c;
	return (str);
}

int			ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		while (*s1 || *s2)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
		}
		return (1);
	}
	return (0);
}