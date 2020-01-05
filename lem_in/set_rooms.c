/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <stross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:32:25 by stross            #+#    #+#             */
/*   Updated: 2019/12/28 17:49:49 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			count_rooms(char **arr)
{
	int		n_rooms;
	int 	i;

	i = 1;
	n_rooms = 0;
	while (arr[i])
	{
		if (find_char(arr[i], '#'))
		{
			i++;
			continue ;
		}
		else if (find_char(arr[i], '-'))
			break ;
		i++;
		n_rooms++;
	}
	return (n_rooms);
}

static void		fill_info_help(t_room **rooms, char **arr, int *i, int *r_num)
{
	while (arr[*i])
	{
		if (arr[*i][0] == '#')
		{
			if (ft_strequ(arr[*i], "##start"))
			{
				rooms[0] = create_room(0, arr[*i + 1]);
				*i += 2;
			}
			else if (ft_strequ(arr[*i], "##end"))
			{
				rooms[*r_num] = create_room(2147483647, arr[*i + 1]);
				*i += 2;
				(*r_num)++;
			}
			else
				(*i)++;
			continue ;
		}
		if (find_char(arr[*i], '-'))
			break;
		rooms[*r_num] = create_room(*r_num, arr[*i]);
		(*r_num)++;
		(*i)++;
	}
}

static t_room	**fill_info(t_room **rooms, char **arr)
{
	int		i;
	int 	r_num;

	r_num = 1;
	i = 1;
	fill_info_help(rooms, arr, &i, &r_num);
	return (rooms);
}

static void		null_room_links(t_room **rooms)
{
	int		i;

	i = 0;
	while (rooms[i])
	{
		rooms[i]->links[rooms[i]->n_links] = NULL;
		i++;
	}
}

t_room			**create_rooms(t_room **rooms, char **arr)
{
	int		n_rooms;

	n_rooms = count_rooms(arr);
	rooms = (t_room**)ft_memalloc(n_rooms * sizeof(t_room*) + 1);
//	rooms[n_rooms] = NULL; // was no - 1
	rooms = fill_info(rooms, arr);
	set_links(rooms, arr);
	null_room_links(rooms);
	return (rooms);
}