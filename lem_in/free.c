/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <stross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:58:33 by stross            #+#    #+#             */
/*   Updated: 2019/12/25 18:03:12 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_paths(t_room ***paths)
{
	int		i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void	double_free(char *str, char *str2)
{
	if (str)
	{
		free(str);
	}
	if (str2)
	{
		free(str2);
	}
}

void	free_name(t_room **rooms)
{
	int		i;

	i = 0;
	while (rooms[i])
	{
		free(rooms[i]->name);
		i++;
	}
}

void	free_struct(t_room **rooms)
{
	int 	i;

	i = 0;
	while (rooms[i])
	{
		free(rooms[i]);
		i++;
	}
	free(rooms);
}

void	free_paths_info(t_path_info **info)
{
	int		i;

	i = 0;
	while (info[i])
	{
		free(info[i]);
		i++;
	}
	free(info);
}