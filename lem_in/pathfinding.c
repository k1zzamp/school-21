/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <stross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 13:39:57 by stross            #+#    #+#             */
/*   Updated: 2019/12/28 19:18:04 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		set_var(t_path_var *var)
{
	var->index = 0;
	var->sub_index = 0;
	var->rooms_index = 0;
	var->queue = (t_room**)ft_memalloc(4001 * sizeof(t_room*));
}

static t_room	*find_path(t_room **rooms)
{
	t_path_var	var;

	set_var(&var);
	var.queue[var.sub_index++] = rooms[0];
	rooms[0]->visited = 1;
	while (var.queue[var.index])
	{
		while (var.queue[var.index]->links[var.rooms_index])
		{
			if (var.queue[var.index]->links[var.rooms_index]->visited == 1)
			{
				var.rooms_index++;
				continue ;
			}
			var.queue[var.index]->links[var.rooms_index]->visited = 1; // END
			var.queue[var.index]->links[var.rooms_index]->prev = var.queue[var.index];
			if (var.queue[var.index]->links[var.rooms_index]->index == INT_MAX)
			{
				free(var.queue);
				return (var.queue[var.index]->links[var.rooms_index]);
			}
			else
				var.queue[var.sub_index++] = var.queue[var.index]->links[var.rooms_index];
			var.rooms_index++;
		}
		var.rooms_index = 0;
		var.index++;
	}
	free(var.queue);
	return (NULL);
}

static void		set_visited_rooms(t_room **rooms, t_room ***paths)
{
	int		i;
	int 	si;

	i = 0;
	while (rooms[i])
	{
		rooms[i]->visited = 0;
		i++;
	}
	i = 0;
	while (paths[i])
	{
		si = 0;
		while (paths[i][si])
		{
			if (paths[i][si]->index != INT_MAX) //seg
				paths[i][si]->visited = 1;
			si++;
		}
		i++;
	}
}

static t_room **get_arr_path(t_room *room, int n_links)
{
	int		i;
	int		len;
	t_room	*temp;
	t_room	**path;

	path = (t_room**)ft_memalloc((n_links + 4000) * sizeof(t_room*)); //free
	i = 0;
	len = 0;
	while (room->index != 0)
	{
		path[i++] = room;
		room = room->prev;
	}
	path[i] = room;
	while (path[len])
		len++;
	i = 0;
	while (i < len / 2)
	{
		temp = path[i];
		path[i] = path[len - i - 1];
		path[len - i - 1] = temp;
		++i;
	}
	return (path);
}

t_room			***find_paths(t_room **rooms)
{
	t_room	***paths;
	t_room	*room;
	int		i;

	i = 0;
	paths = (t_room***)ft_memalloc((rooms[0]->n_links + 4000) * sizeof(t_room**)); //free
	while ((room = find_path(rooms)))
	{
		paths[i] = get_arr_path(room, rooms[0]->n_links);
		set_visited_rooms(rooms, paths);
		i++;
	}
	return (paths);
}