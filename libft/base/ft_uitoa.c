/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:50:54 by mkantzer          #+#    #+#             */
/*   Updated: 2017/02/23 16:28:19 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_print(uintmax_t n, uintmax_t size, char *str, uintmax_t i)
{
	while (n >= 10)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	if (n < 10)
		str[i] = n + 48;
	str[size + 1] = '\0';
	return (str);
}

static int		ft_size(int size, uintmax_t i)
{
	while (i >= 10)
	{
		i = i / 10;
		size++;
	}
	return (size);
}

char			*ft_uitoa(uintmax_t n)
{
	char		*str;
	uintmax_t	size;
	uintmax_t	i;

	str = NULL;
	size = 0;
	size = ft_size(size, n);
	i = size;
	str = (char *)malloc((size + 2) * sizeof(char));
	if (str == 0)
		return (NULL);
	return (ft_print(n, size, str, i));
}
