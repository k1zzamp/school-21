/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:43:56 by stross            #+#    #+#             */
/*   Updated: 2019/09/12 15:53:50 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*fill_array(t_list *list, char *arr)
{
	char	*temp;
	char	*ret;

	ret = arr;
	while (list != NULL)
	{
		temp = (char *) list->content;
		while (*temp)
			*arr++ = *temp++;
		list = list->next;
	}
	return (ret);
}

static char		*get_arr_size(t_list *list)
{
	char	*arr;
	char	*temp;
	size_t	len;

	len = 0;
	while (list != NULL)
	{
		temp = (char *) list->content;
		while (*temp)
		{
			len++;
			temp++;
		}
		list = list->next;
	}
	arr = (char *) ft_memalloc((len + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	return (arr);
}

static t_list	*get_input(const int fd, t_list *list)
{
	char		*buff[BUFF_SIZE]; // + 1 with no com
	ssize_t		nbread;

	while ((nbread = read(fd, (void *) buff, (size_t) BUFF_SIZE) != 0))
	{
		if (nbread == -1)
			return (-1);
//		buff[nbread] = '\0'; 
		ft_lst_push_b(&list, (void *) buff, (size_t) BUFF_SIZE);
	}
	return (list);
}

int 			get_next_line(const int fd, char **line)
{
	t_list		*list;
	static char	*arr;

	list = get_input(fd, list);
	arr = get_arr_size(list);
	arr = fill_array(list_arr);
	while (*arr != EOF)
	{
		if (*arr == NL)
		{
			arr++;
			return (1);
		}
		ft_putchar(*arr);
	}
	return (0);
}
