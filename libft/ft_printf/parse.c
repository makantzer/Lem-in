/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:07:31 by mkantzer          #+#    #+#             */
/*   Updated: 2017/03/31 16:54:24 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec		get_spec(const char *format)
{
	char	*conv;
	char	*str;
	t_spec	spec;
	int		i;
	int		j;

	conv = "sSpdDioOuUxXcC%";
	i = 0;
	spec = spec_init();
	while (format[++i] != '\0')
	{
		j = -1;
		if (ft_strchr(conv, format[i]))
		{
			str = ft_strsub(format, 1, i);
			spec = parse_flag(str, spec);
			spec.size = i;
			free(str);
			return (spec);
		}
		if (ft_isalpha(format[i]) == 1 && format[i] != 'l' && format[i] != 'j' \
				&& format[i] != 'h' && format[i] != 'z')
			return (other_conv(format + 1, spec));
	}
	return (spec);
}

t_spec		other_conv(const char *str, t_spec spec)
{
	int		i;
	char	*tmp;

	i = 0;
	while (ft_isalpha(str[i]) != 1)
		i++;
	spec.other = str[i];
	tmp = ft_strdup(str);
	spec = parse_flag(tmp, spec);
	ft_strdel(&tmp);
	if (spec.width != 0 || spec.precision != -1)
		i++;
	spec.size = i;
	spec.type = str[i];
	return (spec);
}

t_spec		parse_flag(char *str, t_spec spec)
{
	int			i;

	i = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == '0' || str[i] == '#' ||\
			str[i] == ' ')
	{
		if (str[i] == '-')
			spec.flag.neg = 1;
		if (str[i] == '+')
			spec.flag.plus = 1;
		if (str[i] == '0')
			spec.flag.zero = 1;
		if (str[i] == '#')
			spec.flag.sharp = 1;
		if (str[i] == ' ')
			spec.flag.space = 1;
		i++;
	}
	if (i == 0)
		spec.flag.any = 0;
	return (parse_spec(spec, str + i));
}

t_spec		parse_spec(t_spec spec, char *str)
{
	int		i;
	int		j;
	char	*erase;

	i = 0;
	spec.length = parse_length_modif(str + i, spec.length);
	j = i;
	while (str[i] != '.' && str[i] >= 48 && str[i] <= 57)
		i++;
	erase = ft_strsub(str, j, i);
	if (erase != 0)
		spec.width = ft_atoi(erase);
	ft_strdel(&erase);
	if (str[i] == '.')
	{
		j = i + 1;
		i++;
		while (str[i] >= 48 && str[i] <= 57)
			i++;
		erase = ft_strsub(str, j, i - j);
		spec.precision = ft_atoi(erase);
		ft_strdel(&erase);
	}
	spec.type = str[ft_strlen(str) - 1];
	return (spec);
}

t_len		parse_length_modif(char *str, t_len len)
{
	if (str[0] == 'h')
	{
		if (str[1] == 'h')
			len.hh = 1;
		else
			len.h = 1;
		len.any = 1;
	}
	if (str[0] == 'l')
	{
		if (str[1] == 'l')
			len.ll = 1;
		else
			len.l = 1;
		len.any = 1;
	}
	if (str[0] == 'j' || str[0] == 'z')
		len.any = 1;
	if (str[0] == 'j')
		len.j = 1;
	if (str[0] == 'z')
		len.z = 1;
	return (len);
}
