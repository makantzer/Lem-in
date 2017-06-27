/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:50:54 by mkantzer          #+#    #+#             */
/*   Updated: 2017/03/08 15:31:57 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_print(uintmax_t n, uintmax_t size, char *str, uintmax_t b)
{
	char			*ref;
	uintmax_t		i;

	i = size;
	ref = "0123456789abcdef";
	while (n >= b)
	{
		str[i] = ref[(n % b)];
		n = n / b;
		i--;
	}
	if (n < b)
		str[i] = ref[n];
	str[size + 1] = '\0';
	return (str);
}

static int		ft_size(uintmax_t size, uintmax_t i, uintmax_t b)
{
	while (i >= b)
	{
		i = i / b;
		size++;
	}
	return (size);
}

char			*ft_uitoa_base(uintmax_t n, uintmax_t b)
{
	char		*str;
	uintmax_t	size;

	str = NULL;
	size = 0;
	size = ft_size(size, n, b);
	str = (char *)malloc((size + 2) * sizeof(char));
	if (str == 0)
		return (NULL);
	return (ft_print(n, size, str, b));
}
