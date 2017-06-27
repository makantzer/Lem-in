/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 10:48:04 by mkantzer          #+#    #+#             */
/*   Updated: 2017/03/31 11:34:46 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*cmaj_handler(t_spec spec, wchar_t c)
{
	char *str;

	if (c <= 127)
		return (c_handler(spec, (char)c));
	else
		str = wide_char(c);
	if (spec.width != 0)
		str = width_handler(str, spec);
	if (spec.precision != -1)
		str = s_precision(str, spec.precision);
	return (str);
}

char	*smaj_handler(t_spec spec, wchar_t *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (str == NULL)
		tmp = ft_strdup("(null)");
	else
	{
		tmp = ft_strnew(0);
		while (str[i])
		{
			tmp = ft_strfjoin(tmp, wide_char(str[i]), 3);
			i++;
		}
	}
	if (spec.precision != -1)
		tmp = smaj_precision(str, tmp, spec.precision);
	if (ft_strcmp(tmp, "") == 0 && spec.precision == 0)
		tmp = ft_strdup("");
	if (spec.width != 0)
		tmp = width_handler(tmp, spec);
	return (tmp);
}

char	*wide_char(wchar_t c)
{
	char *str;

	str = ft_strnew(4);
	if (c <= 127)
		str[0] = c;
	else if (c > 127 && c <= 2047)
	{
		str[0] = (c >> 6) | 192;
		str[1] = (c & 63) | 128;
	}
	else if (c <= 65535)
	{
		str[0] = (c >> 12) | 224;
		str[1] = ((c >> 6) & 63) | 128;
		str[2] = (c & 63) | 128;
	}
	else
	{
		str[0] = (c >> 18) | 240;
		str[1] = ((c >> 12) & 63) | 128;
		str[2] = ((c >> 6) & 63) | 128;
		str[3] = (c & 63) | 128;
	}
	return (str);
}
