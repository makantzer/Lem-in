/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:53:16 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/07 20:45:23 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int k;

	i = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i])
	{
		if (big[i] == little[0])
		{
			j = i;
			k = 0;
			while (big[j] == little[k] && little[k])
			{
				j++;
				k++;
			}
			if (little[k] == '\0')
				return ((char*)&big[i]);
		}
		i++;
	}
	return (NULL);
}
