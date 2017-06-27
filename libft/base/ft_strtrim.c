/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:11:27 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/14 15:54:20 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	size_t	len;

	i = 0;
	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	if (len == 0)
		return (ft_strdup(s));
	j = len - 1;
	while ((s[i] == 32 || s[i] == '\n' || s[i] == '\t') && s)
	{
		i++;
		len--;
	}
	while ((s[j] == 32 || s[j] == '\n' || s[j] == '\t') && j >= i)
	{
		len--;
		j--;
	}
	str = ft_strsub(s, i, len);
	return (str);
}
