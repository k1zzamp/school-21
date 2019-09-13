/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:43:56 by stross            #+#    #+#             */
/*   Updated: 2019/09/13 16:54:21 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_list(void *d, size_t s)
{
	free(d);
	(void)s;
}

static char			*fill_arr(t_list *list, size_t len)
{
	char	*arr;
	char	*temp;

	arr = (char*)malloc(len + 1);
	temp = arr;
	while (list)
	{
		*arr = *((char*)list->content);
		arr++;
		list = list->next;
	}
	return (temp);
}

static size_t		get_len(t_list *list)
{
	size_t	len;

	len = 0;
	ft_putnbr(1);
	while (list)
	{
		len++;
		list = list->next;
	}
	ft_putnbr(len);
	return (len);
}

static t_list		*get_input(const int fd, t_list *list)
{
	char		buff[BUFF_SIZE + 1];
	char		*pta;
	ssize_t		nbread;
	char		end;

	end = END;
	while ((nbread = read(fd, (void *)buff, (size_t)BUFF_SIZE) != 0))
	{
		if (nbread == -1)
			return (NULL);
		buff[BUFF_SIZE] = END;
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
	static char	*arr;
	t_list		*list;
	size_t		len;

	list = NULL;
	ft_putnbr(1);
	list = get_input(fd, list);
	ft_putnbr(2);
	len = get_len(list);
	ft_putnbr(3);
	arr = fill_arr(list, len);
	ft_lstdel(&list, &free_list);
	*line = arr;
//	if (list == NULL)
//		return (-1);

	return (-1);
}
