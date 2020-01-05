/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <stross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:47:31 by stross            #+#    #+#             */
/*   Updated: 2020/01/05 19:32:50 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFF_SIZE 131072
# define START 1
# define END 2147483647

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>

typedef struct		s_room
{
	int				index;
	struct s_room	*links[4001];
	int				n_links;
	struct s_room 	*prev;
	bool			visited;
	char 			*name;
}					t_room;

typedef struct		s_links
{
	int				index;
	int 			sub_index;
	t_room			*first_room;
	t_room			*second_room;
	char 			*first;
	char 			*second;
}					t_links;

typedef struct		s_path_var
{
	t_room			**queue;
	int 			index;
	int 			sub_index;
	int 			rooms_index;
}					t_path_var;

typedef struct		s_ant
{
	int				delay;
	int 			position;
	bool			end;
	char			*name;
	t_room			**path;
}					t_ant;

typedef struct		s_path_info
{
	int				path_len;
	int				ants;
	t_room			**path;
}					t_path_info;

char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strdup(char *str);
char				*get_array(void);
char				*ft_itoa(int nbr);
char 				*ft_strcdup(char *str, char c);
char				*ft_stracdup(char *str, char c);
char				**ft_strsplit(char const *s, char c);
int 				ft_strlen(char *str);
int					ft_strequ(char const *s1, char const *s2);
int 				find_char(char *str, char c);
int					ft_atoi(const char *str);
void				*ft_memalloc(size_t size);
void				free_split(char **arr);
void				*ft_memset(void *str, int c, size_t n);
void				set_links(t_room **rooms, char **arr);
void				free_name(t_room **rooms);
void				free_struct(t_room **rooms);
void				double_free(char *str, char *str2);
void				free_paths(t_room ***paths);
void				free_paths_info(t_path_info **info);
void				send_ants(t_room ***paths, int ant_n);
t_room 				*create_room(int index, char *name);
t_room				**create_rooms(t_room **room, char **arr);
t_room				**parse(char *str, t_room **rooms, int *ants);
t_room				***find_paths(t_room **rooms);

#endif
