/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:26:54 by mkantzer          #+#    #+#             */
/*   Updated: 2017/03/31 11:40:02 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		intlen(intmax_t nb, intmax_t base)
{
	int i;

	i = 1;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > base)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char	*str_capitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

void	replace(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == 255)
		{
			ft_putchar('\0');
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

int		return_o(wchar_t c)
{
	int o;

	o = 0;
	if (c <= 127)
		o = 1;
	else if (c > 127 && c <= 2047)
		o = 2;
	else if (c <= 65535)
		o = 3;
	else if (c > 65535)
		o = 4;
	return (o);
}
