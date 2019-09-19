/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:44:48 by stross            #+#    #+#             */
/*   Updated: 2019/09/19 18:57:18 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 50
# define NL '\n'
# define END '\0'

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct				s_buff_list
{
	char					*buff;
	int						fd;
	struct s_buff_list		*next;
}							t_buff_list;

int							get_next_line(const int fd, char **line);

#endif
