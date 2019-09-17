/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:30:26 by stross            #+#    #+#             */
/*   Updated: 2019/09/12 12:30:34 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_b(t_list **begin_list, void *content, size_t content_size)
{
	t_list	*list;

	if (begin_list)
	{
		if (*begin_list == NULL)
			*begin_list = ft_lstnew(content, content_size);
		else
		{
			list = *begin_list;
			while (list->next != NULL)
				list = list->next;
			list->next = ft_lstnew(content, content_size);
		}
	}
}
