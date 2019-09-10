/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:16:53 by stross            #+#    #+#             */
/*   Updated: 2019/09/10 14:49:57 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char	*ft_strnew(size_t size)
{
	void	*p;

	if (size + 1 > SIZE_MAX)
		return (NULL);
	p = malloc(size + 1);
	if (p)
	{
		p = (char*)ft_memset(p, '\0', size + 1);
		return (p);
	}
	else
		return (NULL);
}
