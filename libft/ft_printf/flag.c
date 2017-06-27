/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 10:59:56 by mkantzer          #+#    #+#             */
/*   Updated: 2017/03/29 20:32:19 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*space_handler(char *str, t_spec spec)
{
	char	*tmp;

	if (spec.flag.plus == 1)
		return (str);
	tmp = str;
	str = ft_strnew(ft_strlen(str) + 2);
	str[0] = 32;
	str = ft_strcat(str, tmp);
	free(tmp);
	return (str);
}

char	*plus_handler(intmax_t nb, char *str)
{
	char	*tmp;

	if (nb < 0)
		return (str);
	tmp = str;
	str = ft_strnew(ft_strlen(str) + 2);
	str[0] = '+';
	str = ft_strcat(str, tmp);
	free(tmp);
	return (str);
}

char	*sharp_handler(char *str, t_spec spec)
{
	char	*tmp;
	char	*prefix;

	if (ft_strcmp(str, "0") == 0 || ft_strcmp(str, "") == 0)
	{
		if (spec.type == 'o' && spec.precision == 0)
			return (ft_strdup("0"));
		if ((spec.type == 'x' || spec.type == 'X' || spec.type == 'o'))
			return (str);
	}
	if (ft_strlen(str) == (size_t)spec.precision && spec.type == 'o')
		return (str);
	if (spec.type == 'o' || spec.type == 'O')
		prefix = "0";
	if (spec.type == 'x' || spec.type == 'p')
		prefix = "0x";
	if (spec.type == 'X')
		prefix = "0X";
	tmp = ft_strdup(str);
	ft_strdel(&str);
	str = ft_strnew(ft_strlen(tmp) + ft_strlen(prefix) + 1);
	str = ft_strcpy(str, prefix);
	str = ft_strcat(str, tmp);
	free(tmp);
	return (str);
}
