/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:53:16 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/12 15:31:13 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = i;
			k = 0;
			while (big[j] == little[k] && little[k] && j < len)
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
