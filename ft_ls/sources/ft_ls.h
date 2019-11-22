/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:09:02 by stross            #+#    #+#             */
/*   Updated: 2019/11/06 14:28:41 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <errno.h>
# include <time.h>
# include <fcntl.h>
# include <sys/ttycom.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <dirent.h>

void	err_quit(int err, char *argv);

#endif
