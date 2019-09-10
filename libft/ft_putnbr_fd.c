/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:17:08 by stross            #+#    #+#             */
/*   Updated: 2019/09/09 15:57:31 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (fd > 0)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			nbr = (unsigned int)(n * -1);
		}
		else
			nbr = (unsigned int)n;
		if (nbr >= 10)
			ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((char)(nbr % 10 + '0'), fd);
	}
}
