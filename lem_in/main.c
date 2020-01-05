/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <stross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:45:33 by stross            #+#    #+#             */
/*   Updated: 2020/01/05 19:42:48 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include <stdio.h>

int		main(void)
{
	int		ants;
	char	*str;
	t_room	**rooms;
	t_room	***paths;

	rooms = NULL;
	str = get_array();
	rooms = parse(str, rooms, &ants);
	paths = find_paths(rooms);
	send_ants(paths, ants);
	//
//	write(1, str, ft_strlen(str));
//	int l = 0;
//	int i = 0;
//	while (paths[l])
//	{
//		i = 0;
//		while (paths[l][i])
//		{
//			printf("%s\n", paths[l][i]->name);
//			i++;
//		}
//		putchar('\n');
//		l++;
//	}
	//
	free(str);
	free_name(rooms);
	free_struct(rooms);
	free_paths(paths);
	return 0;
}
