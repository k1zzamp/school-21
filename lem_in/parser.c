/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <stross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:20:43 by stross            #+#    #+#             */
/*   Updated: 2019/12/25 17:48:49 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*get_array(void)
{
	char	buff[BUFF_SIZE + 1];
	ssize_t	nbread;
	char	*str;
	char	*tmp;

	str = NULL;
	while ((nbread = read(0, (void*)buff, BUFF_SIZE)))
	{
		if (str == NULL)
		{
			buff[nbread] = '\0';
			str = ft_strdup(buff);
		}
		else
		{
			tmp = str;
			buff[nbread] = '\0';
			str = ft_strjoin(tmp, buff);
			free(tmp);
		}
	}
	return (str);
}

t_room	**parse(char *str, t_room **rooms, int *ants)
{
	  char	**arr;

	  arr = ft_strsplit(str, '\n');
	  //check errors
	  *ants = ft_atoi(arr[0]);
	  rooms = create_rooms(rooms, arr);
	  free_split(arr);
	  return (rooms);
}