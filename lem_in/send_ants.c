/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <stross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 14:15:34 by stross            #+#    #+#             */
/*   Updated: 2020/01/05 20:09:47 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//static t_ant		*create_ant(t_room **path, int delay)
//{
//	t_ant		*ant;
//	char		*temp;
//	static int	name;
//
//	ant = (t_ant*)ft_memalloc(sizeof(t_ant));
//	ant->delay = delay;
//	ant->position = 1;
//	ant->end = 0;
//	ant->path = path;
//	temp = ft_itoa(++name);
//	ant->name = ft_strjoin("L", temp); //free
//	free(temp);
//	return (ant);
//}

static t_path_info	*create_path_struct(t_room **path)
{
	int			len;
	t_path_info	*info;

	len = 0;
	info = (t_path_info*)ft_memalloc(sizeof(t_path_info));
	info->path = path;
	while (path[len])
		len++;
	info->path_len = len;
	info->ants = 0;
	return (info);
}

static t_path_info	**get_paths_info(t_room ***paths)
{
	int			len;
	t_path_info	**info;

	len = 0;
	while (paths[len])
		len++;
	info = (t_path_info**)ft_memalloc(sizeof(t_path_info*) * (len + 1));
	len = 0;
	while (paths[len])
	{
		info[len] = create_path_struct(paths[len]);
		len++;
	}
	return (info);
}

void			send_ants(t_room ***paths, int ant_n)
{
	t_path_info **info;
	int 		i;
	int 		len;
	int 		prev;
	int 		stat;

	info = get_paths_info(paths);
	while (ant_n > 0)
	{
		i = 0;
		len = 0;
		prev = 0;
		stat = 0;
		while (info[i] && ant_n > 0)
		{
			if (prev > 0)
				len = info[i]->path_len;
			stat += len - prev;
			if (ant_n > stat)
			{
				info[i]->ants++;
				ant_n--;
			}
			prev = info[i]->path_len;
			i++;
		}
	}
	for (int x = 0; info[x]; x++)
		printf("%d\n", info[x]->ants);
	free_paths_info(info);
}