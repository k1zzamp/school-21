/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_f4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:18:39 by stross            #+#    #+#             */
/*   Updated: 2019/11/22 15:21:40 by stross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_calculate_char(int mod, char c)
{
	char	return_char;

	if (mod > 36)
		return (0);
	return_char = '0';
	while (mod--)
	{
		return_char++;
		if (return_char == ':')
			return_char = c;
	}
	return (return_char);
}

static int	ft_get_len(uintmax_t num, uintmax_t base)
{
	int		len;

	len = 0;
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

static char	*ft_generate_string(uintmax_t num, uintmax_t base, char c)
{
	uintmax_t	sum;
	int			mod;
	int			len;
	int			i;
	char		*str;

	if (num == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		*str = '0';
		return (str);
	}
	sum = num;
	i = 0;
	len = ft_get_len(num, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (sum)
	{
		mod = sum % base;
		sum /= base;
		str[(len--) - 1] = ft_calculate_char(mod, c);
	}
	return (str);
}

char		*ft_itoa_base_gt(uintmax_t num, uintmax_t base, char c)
{
	char	*str;

	str = ft_generate_string(num, base, c);
	return (str);
}
