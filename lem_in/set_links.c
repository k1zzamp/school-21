/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <stross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:22:04 by stross            #+#    #+#             */
/*   Updated: 2019/12/28 17:30:45 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//author

static void	null_struct(t_links *links)
{
	links->index = 0;
	links->first_room = 0;
	links->second_room = 0;
	links->sub_index = 0;
	links->first = NULL;
	links->second = NULL;
}

static void	set_second_part(t_room **rooms, t_links *links)
{
	links->sub_index = 0;
	while (rooms[links->sub_index])
	{
		if (ft_strequ(rooms[links->sub_index]->name, links->first))
		{
			rooms[links->sub_index]->links[rooms[links->sub_index]->n_links] = links->second_room;
			rooms[links->sub_index]->n_links++;
		}
		if (ft_strequ(rooms[links->sub_index]->name, links->second))
		{
			rooms[links->sub_index]->links[rooms[links->sub_index]->n_links] = links->first_room;
			rooms[links->sub_index]->n_links++;
		}
		links->sub_index++;
	}
}

static void	set_first_part(t_room **rooms, char **arr)
{
	t_links links;

	null_struct(&links);
	while (arr[links.index])
	{
		if (arr[links.index][0] == '#')
		{
			links.index++;
			continue ;
		}
		links.sub_index = 0;
		links.first = ft_strcdup(arr[links.index], '-');
		links.second = ft_stracdup(arr[links.index], '-');
		while (rooms[links.sub_index])
		{
			if (ft_strequ(links.first, rooms[links.sub_index]->name))
				links.first_room = rooms[links.sub_index];
			if (ft_strequ(links.second, rooms[links.sub_index]->name))
				links.second_room = rooms[links.sub_index];
			links.sub_index++;
		}
		set_second_part(rooms, &links);
		double_free(links.first, links.second);
		links.index++;
	}
}

void		set_links(t_room **rooms, char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (find_char(arr[i], '-'))
			break ;
		i++;
	}
	set_first_part(rooms, arr + i);
}