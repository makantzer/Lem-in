/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 11:42:19 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/30 19:43:51 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*oux_handler(t_spec spec, uintmax_t arg)
{
	char *str;

	if (spec.type == 'u' || spec.type == 'U')
		str = ft_uitoa_base(arg, 10);
	if (spec.type == 'o' || spec.type == 'O')
		str = ft_uitoa_base(arg, 8);
	if (spec.type == 'p' || spec.type == 'x' || spec.type == 'X')
		str = ft_uitoa_base(arg, 16);
	if (spec.type == 'X')
		str = str_capitalize(str);
	if (spec.precision == -1 && spec.width == 0 && spec.flag.any == 0)
		return (str);
	if (spec.precision != -1 && (spec.type == 'x' || spec.type == 'p' || \
				spec.type == 'X'))
		str = oux_precision(arg, spec.precision, 16, str);
	else if (spec.precision != -1 && (spec.type == 'o' || spec.type == 'O'))
		str = oux_precision(arg, spec.precision, 8, str);
	else if (spec.precision != -1)
		str = oux_precision(arg, spec.precision, 10, str);
	if (arg == 0 && spec.precision == 0)
		str = ft_strdup("");
	return (oux_handler_flag(spec, str));
}

char	*oux_handler_flag(t_spec spec, char *str)
{
	if (spec.flag.sharp == 1 && spec.type != 'u')
		str = sharp_handler(str, spec);
	if (spec.width != 0)
		str = width_handler(str, spec);
	if (spec.type == 'X')
		str = str_capitalize(str);
	return (str);
}

char	*di_handler(t_spec spec, intmax_t arg)
{
	char	*str;

	str = ft_itoa_base(arg, 10);
	if (spec.precision == -1 && spec.width == 0 && spec.flag.any == 0)
		return (str);
	if (spec.precision != -1)
	{
		free(str);
		str = di_precision(arg, spec.precision);
	}
	if (arg == 0 && spec.precision == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (spec.flag.plus == 1)
		str = plus_handler(arg, str);
	if (spec.width != 0)
		str = width_handler(str, spec);
	else if (spec.flag.space == 1 && spec.flag.plus == 0 && arg > 0)
		str = space_handler(str, spec);
	return (str);
}

char	*s_handler(t_spec spec, char *s)
{
	char *str;

	if (s == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(s);
	if (spec.precision != -1)
		str = s_precision(str, spec.precision);
	if (spec.width != 0)
		str = width_handler(str, spec);
	return (str);
}

char	*c_handler(t_spec spec, char c)
{
	char *str;

	str = ft_strnew(2);
	if (c == 0)
		str[0] = -1;
	else
		str[0] = c;
	str[1] = '\0';
	if (ft_strcmp(str, "") == 0 && spec.precision == 0)
		str = "";
	if (spec.width != 0)
		str = width_handler(str, spec);
	return (str);
}
