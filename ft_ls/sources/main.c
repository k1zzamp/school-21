/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:07:51 by stross            #+#    #+#             */
/*   Updated: 2019/11/06 15:29:34 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	DIR				*dp;
	struct dirent	*dirp;
	struct stat		statbuf;

	if (argc != 2)
		err_quit(1, NULL);
	if ((dp = opendir(argv[1])) == NULL)
		err_quit(2, argv[1]);
	while ((dirp = readdir(dp)) != NULL)
	{
		ft_printf("%s\n", dirp->d_name);
		if (stat(dirp->d_name, &statbuf) == -1)
			continue ;
		ft_printf("%s\n", ft_itoa_base(statbuf.st_mode, 8));
	}
	closedir(dp);
	exit(0);
}
