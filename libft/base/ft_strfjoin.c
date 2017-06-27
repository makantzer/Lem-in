/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:34:12 by mkantzer          #+#    #+#             */
/*   Updated: 2017/03/30 16:24:08 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char *s1, char *s2, int f)
{
	size_t	len;
	size_t	len1;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	j = 0;
	len = len1 + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str = ft_strncpy(str, s1, len1);
	while (len1 < len)
	{
		str[len1++] = s2[j];
		j++;
	}
	str[len1] = '\0';
	if (f == 1 || f == 3)
		ft_strdel(&s1);
	if (f == 2 || f == 3)
		ft_strdel(&s2);
	return (str);
}
