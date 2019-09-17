/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:16:53 by stross            #+#    #+#             */
/*   Updated: 2019/09/16 17:36:09 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
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
