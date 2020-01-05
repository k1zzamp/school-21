static t_room	**fill_info(t_room **rooms, char **arr)
{
	int		i;
	int 	r_num;

	r_num = 1;
	i = 1;
	while (arr[i])
	{
		if (arr[i][0] == '#')
		{
			if (ft_strequ(arr[i], "##start"))
			{
				rooms[0] = create_room(0, arr[i + 1]);
				i += 2;
				continue ;
			}
			else if (ft_strequ(arr[i], "##end"))
			{
				rooms[r_num] = create_room(2147483647, arr[i + 1]);
				i += 2;
				r_num++;
				continue ;
			}
			else
			{
				i++;
				continue ;
			}
		}
		if (find_char(arr[i], '-'))
			break;
		rooms[r_num] = create_room(r_num, arr[i]);
		r_num++;
		i++;
	}
	return (rooms);
}

static t_room	**fill_info(t_room **rooms, char **arr)
{
	int		i;
	int 	r_num;

	r_num = 1;
	i = 1;
	while (arr[i])
	{
		if (arr[i][0] == '#')
		{
			if (ft_strequ(arr[i], "##start"))
			{
				rooms[0] = create_room(0, arr[i + 1]);
				i += 2;
			}
			else if (ft_strequ(arr[i], "##end"))
			{
				rooms[r_num] = create_room(2147483647, arr[i + 1]);
				i += 2;
				r_num++;
			}
			else
				i++;
			continue ;
		}
		if (find_char(arr[i], '-'))
			break;
		rooms[r_num] = create_room(r_num, arr[i]);
		r_num++;
		i++;
	}
	return (rooms);
}

//SORT

static int	strchlen(char *str, char c)
{
	int		i;

	i = 0;
	while (*str && *str != c)
	{
		i++;
		str++;
	}
	return (i);
}

static char *get_prev_name(char *str, char *room)
{
	bool	pos;
	char	*ret;

	if (ft_strequ(room, str))
		pos = 0;
	else
		pos = 1;
	if (pos)
	{
		ret = (char*)ft_memalloc(strchlen(str, '-') + 1);
		while (*str && *str != '-')
			*ret++ = *str++;
	}
	else
	{
		while (*str != '-' && *str)
			str++;
		str++;
		ret = (char*)ft_memalloc(ft_strlen(str) + 1);
		while (*str)
			*ret++ = *str++;
	}
	return (ret);
}

static void	sort_array(char **arr, char *room)
{
	int		i;
	int 	si;
	char 	*temp;
	bool	new;

	i = 0;
	while (arr[i])
	{
		new = 0;
		si = 0;
		while (arr[si])
		{
			if (ft_strstr(arr[si], room) && arr[i])
			{
				temp = arr[i];
				arr[i] = arr[si];
				arr[si] = temp;
				i++;
				new = 1;
			}
			si++;
		}
		if (new == 0)
			room = get_prev_name(arr[i - 1], room);
	}
}


////
typedef struct		s_links
{
	int				index;
	int 			sub_index;
	int 			first_room;
	int 			second_room;
	char 			*first;
	char 			*second;
}					t_links;

typedef struct		s_room
{
	int				index;
	int 			links[4001];
	int				n_links;
	int 			prev_index;
	bool			visited;
	char 			*name;
}					t_room;


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
	w
}

static void	set_first_part(t_room **rooms, char **arr)
{
	t_links links;

	null_struct(&links);
	while (arr[links.index])
	{
		links.sub_index = 0;
		links.first = ft_strcdup(arr[links.index], '-');
		links.second = ft_stracdup(arr[links.index], '-');
		while (rooms[links.sub_index])
		{
			if (ft_strequ(links.first, rooms[links.sub_index]->name))
				links.first_room = rooms[links.sub_index]->index;
			if (ft_strequ(links.second, rooms[links.sub_index]->name))
				links.second_room = rooms[links.sub_index]->index;
			links.sub_index++;
		}
		set_second_part(rooms, &links);
		free(links.first);
		free(links.second);
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


void	set_levels(t_room **rooms)
{
	int 	i;
	int 	si;
	int 	level;
	int 	n_links;
	t_room	*start;
	t_room	*temp;

	start = rooms[0];
	level = 1;
	i = 0;
	si = 0;
	start->visited = 1;
	while (start->links[0])
	{
		while (start->links[si])
		{
			if (start->links[si]->visited == 1)
			{
				si++;
				continue ;
			}
			else
				start->links[si]->level = level;
		}
		level++;
		if ()
		{

		}
	}
}

t_room			***find_paths(t_room **rooms)
{
	t_room	***paths;
	int		i;

	i = 0;
	paths = (t_room***)ft_memalloc((rooms[0]->n_links + 1) * sizeof(t_room**)); //free
	while ((paths[i] = get_arr_path(find_path(rooms), rooms[0]->n_links)))
	{
		set_visited_rooms(rooms, paths);
		i++;
	}
	return (paths);
}

t_room			**create_rooms(t_room **rooms, char **arr)
{
	int		n_rooms;

	n_rooms = count_rooms(arr);
	rooms = (t_room**)ft_memalloc(n_rooms * sizeof(t_room*) + 1);
	rooms[n_rooms] = NULL; // was no - 1
	rooms = fill_info(rooms, arr);
	set_links(rooms, arr);
	null_room_links(rooms);
	return (rooms);
}

int			ft_strstr(const char *str, const char *find)
{
	unsigned int	count;
	unsigned int	scount;

	count = 0;
	scount = 0;
	if (*find == '\0')
		return (0);
	while (str[count])
	{
		while (str[count + scount] == find[scount])
		{
			scount++;
			if (find[scount] == '\0')
				return (1);
		}
		scount = 0;
		count++;
	}
	return (0);
}

typedef struct		s_send
{
	int 			i;
	int 			num;
	int 			prev;
	int 			len;
	t_ant			**ants;
}					t_send;

void			send_ants(t_room ***paths, int ant_n)
{
	t_send	send;

	send.num = 0;
	send.ants = (t_ant**)ft_memalloc(sizeof(t_ant*) * (ant_n + 1));
	while (ant_n > 0)
	{
		send.i = 0;
		send.prev = 0;
		while (paths[send.i])
		{
			send.len = find_path_len(paths[send.i]);
			if (ant_n > send.prev)
				send.ants[send.num++] = create_ant(paths[send.i], )
		}
	}
}

static int 			find_path_len(t_room **path)
{
	int	len;

	len = 0; // or 1 ??????????? first room is start
	while (path[len])
		len++;
	return (len);
}