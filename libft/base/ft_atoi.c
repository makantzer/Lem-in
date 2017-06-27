/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:59:01 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/12 14:50:58 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int nb;
	int i;
	int n;

	i = 0;
	nb = 0;
	n = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] <= 90 && str[i] >= 65) || (str[i] <= 122 && str[i] >= 97))
		return (0);
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			n = 1;
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	if (n == 1)
		nb = nb * -1;
	return (nb);
}
