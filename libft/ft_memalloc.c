/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:53:43 by stross            #+#    #+#             */
/*   Updated: 2019/09/05 19:11:18 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;
	size_t	i;

	i = 0;
	p = malloc(size);
	if (p)
	{
		ft_bzero(p, size);
		return (p);
	}
	else
		return (NULL);
}