/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:40:35 by mkantzer          #+#    #+#             */
/*   Updated: 2017/03/29 20:10:59 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	while (i <= (size))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
