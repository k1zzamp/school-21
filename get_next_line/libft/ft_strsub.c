/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:00:49 by stross            #+#    #+#             */
/*   Updated: 2019/09/09 20:15:25 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	char	*ret;

	if (s)
	{
		s += start;
		subs = (char*)malloc(len + 1);
		if (subs)
		{
			ret = subs;
			while (*s && len--)
				*subs++ = *s++;
			*subs = '\0';
			return (ret);
		}
		else
			return (NULL);
	}
	return (NULL);
}
