/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:23:35 by stross            #+#    #+#             */
/*   Updated: 2019/09/16 18:39:30 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t prev, size_t new_s)
{
	void	*ret;

	if (!ptr)
		return (NULL);
	ret = ft_memalloc(new_s);
	if (!ret)
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(ret, ptr, prev < new_s ? prev : new_s);
	free(ptr);
	return (ret);
}
