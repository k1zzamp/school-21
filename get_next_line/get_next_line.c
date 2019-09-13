/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:43:56 by stross            #+#    #+#             */
/*   Updated: 2019/09/13 22:44:26 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_list(void *d, size_t s)
{
	free(d);
	(void)s;
}

static size_t		get_nl_len(t_list *list, t_bool *flag)
{
	size_t	len;

	len = 0;
	while (list)
	{
		len++;
		if (*(char*)list->content == NL)
			return (len);
		if (*(char*)list->content == END)
		{
			*flag = TRUE;
			return (len);
		}
		list = list->next;
	}
	return (0);
}

static t_list		*get_input(const int fd, t_list *list)
{
	char		buff[BUFF_SIZE + 1];
	char		*pta;
	ssize_t		nbread;
	char		end;

	end = END;
	while ((nbread = read(fd, (void *)buff, (size_t)BUFF_SIZE)))
	{
		if (nbread == -1)
			return (NULL);
		buff[nbread] = END;
		pta = (char*)buff;
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
	size_t			len;
	char			*temp;
	t_bool			flag;

	flag = FALSE;
	if (!list)
		list = get_input(fd, list);
	len = get_nl_len(list, &flag);
	*line = (char*)malloc(len + 1);
	temp = *line;
	while (list)
	{
		if (*(char*)list->content == NL || *(char*)list->content == END)
		{
			list = list->next;
			break;
		}
		*temp++ = *(char*)list->content;
		list = list->next;
	}
	*temp = END;
	return (flag == TRUE ? 0 : 1);
}
