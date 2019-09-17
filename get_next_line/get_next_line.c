/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:40:43 by stross            #+#    #+#             */
/*   Updated: 2019/09/17 20:40:30 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_l_push(t_buff_list **start, char *cont, const int fd)
{
	t_buff_list *list;

	if (start == NULL)
	{
		*start = (t_buff_list*)ft_memalloc(sizeof(t_buff_list));
		(*start)->buff = cont;
		(*start)->fd = fd;
	}
	else
	{
		list = (t_buff_list*)ft_memalloc(sizeof(t_buff_list));
		list->buff = cont;
		list->fd = fd;
		list->next = *start;
		*start = list;
	}
}

static ssize_t	get_input(t_buff_list **list, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	ssize_t	nbread;
	char	*str;
	char	*tmp;

	str = NULL;
	while ((nbread = read(fd, (void*)buff, BUFF_SIZE)))
	{
		if (str == NULL)
		{
			buff[nbread] = END;
			str = ft_strdup(buff);
		}
		else
		{
			tmp = str;
			buff[nbread] = END;
			str = ft_strjoin(tmp, buff);
			free(tmp);
		}
	}
	ft_l_push(list, (char*)str, fd);
	return (nbread);
}

static ssize_t	fill_line(const int fd, char **line, t_buff_list *list)
{
	char	*temp;
	char	*ptt;

	while (list)
	{
		if (list->fd == fd)
			break ;
		list = list->next;
	}
	if (*(list->buff) == END)
		return (0);
	temp = list->buff;
	ptt = temp;
	while (*ptt && *ptt != NL)
		ptt++;
	*line = ft_strsub(temp, 0, ptt - temp);
	if (*ptt == NL)
		ptt++;
	ptt = ft_strdup(ptt);
	free(list->buff);
	list->buff = ptt;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_buff_list	*list;
	t_buff_list			*temp;
	ssize_t				ret;
	char				test[1];

	if (!line || fd < 0 || read(fd, test, 0) == -1)
		return (-1);
	temp = list;
	while (temp)
	{
		if (temp->fd == fd)
			break ;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		if ((ret = get_input(&list, fd) == -1))
			return (-1);
	}
	ret = fill_line(fd, line, list);
	return (ret);
}
