/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:32:28 by stross            #+#    #+#             */
/*   Updated: 2019/09/10 14:50:12 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int					ft_atoi(const char *str)
{
	unsigned long long	sum;
	int					sign;

	sum = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return ((int)sum * sign);
		sum *= 10;
		sum += (*str - '0');
		str++;
	}
	if (sum >= 9223372036854775808uLL)
		return (sign == 1 ? -1 : 0);
	return ((int)((int)sum == -1 ? -1 : (int)sum * sign));
}
