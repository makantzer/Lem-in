/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:08:23 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/09 14:33:12 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		cpy[i] = f(cpy[i]);
		i++;
	}
	return (cpy);
}
