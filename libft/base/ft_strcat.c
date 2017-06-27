/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:17:05 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/14 15:51:16 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	i = 0;
	len2 = ft_strlen(s2);
	len1 = ft_strlen(s1);
	while (i < len2)
	{
		s1[(len1 + i)] = s2[i];
		i++;
	}
	s1[len1 + i] = '\0';
	return (s1);
}
