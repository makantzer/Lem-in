/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:08:23 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/09 14:45:07 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*cpy;
	int		i;

	i = 0;
	if (s == '\0')
		return (NULL);
	cpy = ft_strdup(s);
	if (cpy == 0)
		return (NULL);
	while (cpy[i])
	{
		cpy[i] = f(i, cpy[i]);
		i++;
	}
	return (cpy);
}
