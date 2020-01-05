/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <stross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:25:59 by stross            #+#    #+#             */
/*   Updated: 2019/12/25 18:10:18 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room 	*create_room(int index, char *name)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	room->index = index;
	room->n_links = 0;
	room->visited = 0;
	room->prev = NULL;
	room->name = ft_strcdup(name, ' ');
	return (room);
}

void	free_split(char **arr)
{
	unsigned int	x;

	x = 0;
	while (arr[x])
	{
		free(arr[x]);
		x++;
	}
	free(arr);
}

int 	find_char(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char 	*ft_strcdup(char *str, char c)
{
	int 	i;
	char 	*ret;
	char 	*mem;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	i++;
	ret = (char*)ft_memalloc(i--);
	mem = ret;
	while (i--)
		*ret++ = *str++;
	return (mem);
}

char	*ft_stracdup(char *str, char c)
{
	char	*ret;
	char	*mem;
	int 	len;

	while (*str && *str != c)
		str++;
	str++;
	len = ft_strlen(str) + 1;
	ret = (char*)ft_memalloc(len);
	mem = ret;
	while (*str)
		*ret++ = *str++;
	return (mem);
}