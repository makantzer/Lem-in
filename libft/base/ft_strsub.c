/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:14:08 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/14 10:10:07 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == '\0')
		return (0);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	str = ft_strncpy(str, (s + start), len);
	str[len] = '\0';
	return (str);
}
