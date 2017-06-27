/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:22:55 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/14 15:53:43 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s) - 1;
	while (s[len])
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[len]);
	return (NULL);
}
