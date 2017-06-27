/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:34:12 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/14 15:52:34 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	len1;
	size_t	j;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		j = 0;
		len = len1 + ft_strlen(s2);
		str = (char *)malloc((len + 1) * sizeof(char));
		if (str == 0)
			return (0);
		str = ft_strncpy(str, s1, len1);
		while (len1 < len)
		{
			str[len1] = s2[j];
			len1++;
			j++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (0);
}
