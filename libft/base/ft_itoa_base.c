/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:50:54 by mkantzer          #+#    #+#             */
/*   Updated: 2017/03/29 10:06:55 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		*ft_print(unsigned long long n, int size, char *str, \
		unsigned long long base)
{
	char	*ref;
	int		i;

	i = size;
	ref = "0123456789abcdef";
	while (n >= base)
	{
		str[i] = ref[(n % base)];
		n = n / base;
		i--;
	}
	if (n < base)
		str[i] = ref[n];
	str[size + 1] = '\0';
	return (str);
}

static int		ft_size(intmax_t size, unsigned long long i, \
		unsigned long long base)
{
	while (i >= base)
	{
		i = i / base;
		size++;
	}
	return (size);
}

char			*ft_itoa_base(intmax_t n, int base)
{
	unsigned long long	tmp;
	char				*str;
	int					size;
	int					neg;

	str = NULL;
	size = 0;
	neg = 0;
	if (n < 0)
	{
		tmp = n * -1;
		size++;
		neg = 1;
	}
	else
		tmp = n;
	size = ft_size(size, tmp, base);
	str = (char *)malloc((size + 2) * sizeof(char));
	if (str == 0)
		return (NULL);
	if (neg)
		str[0] = '-';
	return (ft_print(tmp, size, str, base));
}
