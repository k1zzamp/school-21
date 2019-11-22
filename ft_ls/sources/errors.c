/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:37:28 by stross            #+#    #+#             */
/*   Updated: 2019/11/05 17:27:37 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	err_quit(int err, char *argv)
{

	if (err == 1)
	{
		ft_printf("usage: ls directory_name\n");
		exit(1);
	}
	if (err == 2)
	{
		ft_printf("can't open %s: %s\n", argv, strerror(errno));
		exit(1);
	}
}
