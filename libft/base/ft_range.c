/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:10:38 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/14 17:10:57 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int	size;
	int *tabint;

	size = max - min;
	if (size > 0)
	{
		tabint = (int*)malloc(sizeof(int*) * size);
		if (tabint != 0)
		{
			i = 0;
			while (min < max)
			{
				tabint[i] = min;
				min++;
				i++;
			}
			return (tabint);
		}
		return (0);
	}
	return (0);
}
