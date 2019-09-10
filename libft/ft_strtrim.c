/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:20:06 by stross            #+#    #+#             */
/*   Updated: 2019/09/09 21:27:33 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (ISSP(s[start]))
		start++;
	end = ft_strlen(s);
	while (ISSP(s[end - 1]))
		end--;
	if (end < start)
		end = start;
	return (ft_strsub(s, start, end - start));
}
