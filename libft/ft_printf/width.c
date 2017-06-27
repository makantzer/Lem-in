/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:37:53 by mkantzer          #+#    #+#             */
/*   Updated: 2017/03/31 15:28:21 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_handler(char *str, t_spec spec)
{
	char	*tmp;
	int		ijk[3];

	ijk[1] = -1;
	ijk[2] = -1;
	if (spec.flag.space == 1)
		str = space_handler(str, spec);
	tmp = str;
	ijk[0] = ft_strlen(str);
	if (spec.width < ijk[0])
		return (tmp);
	str = ft_strnew(spec.width);
	if ((tmp[0] == ' ' || tmp[0] == '-' || tmp[0] == '+') && \
			spec.precision == -1 && spec.flag.zero == 1 && spec.flag.neg == 0)
	{
		ijk[1]++;
		str[ijk[1]] = tmp[ijk[1]];
		spec.width++;
		tmp = ft_strsub(tmp, 1, ft_strlen(tmp) - 1);
	}
	return (ft_split(ijk, tmp, str, spec));
}

char	*ft_split(int *ijk, char *tmp, char *str, t_spec spec)
{
	char	c;

	c = which_c(spec);
	if ((spec.type == 'x' || spec.type == 'X') && spec.flag.sharp == 1 && \
			spec.flag.zero == 1 && spec.flag.neg == 0)
		tmp = xx_condition(&spec.width, &ijk[1], tmp, str);
	if (spec.flag.sharp == 1 && spec.flag.zero == 1 && ft_atoi(tmp) == 0)
		spec.flag.neg = 1;
	if (spec.flag.neg == 1)
	{
		while (tmp[++ijk[2]])
			str[++ijk[1]] = tmp[ijk[2]];
		while (++ijk[1] < spec.width)
			str[ijk[1]] = c;
	}
	else
		while (++ijk[1] < spec.width)
			str[ijk[1]] = (ijk[1] < spec.width - ijk[0] ? c : tmp[++ijk[2]]);
	free(tmp);
	return (str);
}

char	*xx_condition(int *w, int *j, char *tmp, char *str)
{
	(*j)++;
	str[*j] = tmp[*j];
	(*j)++;
	str[*j] = tmp[*j];
	tmp = ft_strsub(tmp, 2, ft_strlen(tmp) - 2);
	*w += 2;
	return (tmp);
}

char	which_c(t_spec spec)
{
	char c;

	if (spec.flag.zero == 1 && spec.flag.neg == 0 && (spec.precision == -1 \
				|| (spec.type == 'S' || spec.type == 's' || spec.type == 'c'\
					|| spec.type == '%')))
		c = '0';
	else if (spec.other != 0 && spec.precision == 0)
		c = '0';
	else
		c = ' ';
	return (c);
}
