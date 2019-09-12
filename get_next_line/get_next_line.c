/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:43:56 by stross            #+#    #+#             */
/*   Updated: 2019/09/12 12:36:53 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char	*buff[BUFF_SIZE];
	ssize_t	nbread;
	t_list	*list;

	while ((nbread = read(fd, (void *) buff, BUFF_SIZE) != 0))
	{
		if (nbread == -1)
			return (-1);

	}
}
