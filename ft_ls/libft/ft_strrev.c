/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:03:37 by stross            #+#    #+#             */
/*   Updated: 2019/09/06 15:07:16 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	temp;

	i = 0;
	size = 0;
	if (str)
	{
		while (str[size] != '\0')
		{
			size++;
		}
		while (i < size / 2)
		{
			temp = str[i];
			str[i] = str[size - i - 1];
			str[size - i - 1] = temp;
			++i;
		}
	}
	return (str);
}
