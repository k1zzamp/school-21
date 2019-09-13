/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:43:56 by stross            #+#    #+#             */
/*   Updated: 2019/09/13 11:35:18 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*get_input(const int fd, t_list *list)
{
	char		buff[BUFF_SIZE + 1];
	char		*pta;
	ssize_t		nbread;
	char		end;

	end = '\0';
	pta = buff;
	while ((nbread = read(fd, (void *)buff, (size_t)BUFF_SIZE) != 0))
	{
		if (nbread == -1)
			return (NULL);
		buff[nbread] = '\0';
		while (*pta)
		{
			ft_lst_push_b(&list, (void *)pta, 1);
			pta++;
		}
	}
	ft_lst_push_b(&list, (void *) &end, 1);
	return (list);
}

int 				get_next_line(const int fd, char **line)
{
	static t_list	*list;

	list = get_input(fd, list);
	while (list->next)
	{
		if (*((char)(list->content)) == NL)
		{
			list = list->next;
			return (0);
		}
		if (*((char)(list->content)) == END)
			return (1);
		list = list->next;
	}
	return (-1);
}
