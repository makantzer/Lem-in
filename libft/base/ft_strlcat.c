/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:50:48 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/14 15:51:39 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	i = 0;
	len2 = ft_strlen(dst);
	len1 = ft_strlen(src);
	if (len2 < size)
	{
		while (i + len2 < size - 1 && src[i])
		{
			dst[(len2 + i)] = src[i];
			i++;
		}
		dst[len2 + i] = '\0';
		return (len1 + len2);
	}
	return (size + len1);
}
