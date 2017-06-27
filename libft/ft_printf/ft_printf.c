/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:36:14 by mkantzer          #+#    #+#             */
/*   Updated: 2017/03/31 14:15:10 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			k;
	char		*buf;

	i = -1;
	buf = ft_strnew(0);
	va_start(ap, format);
	while (format[++i])
	{
		k = i;
		while (format[i] && format[i] != '%')
			i++;
		if (format[i] == '\0')
		{
			buf = ft_strfjoin(buf, ((char*)format + k), 1);
			replace(buf);
			return (ft_ret(buf));
		}
		else
			buf = ft_strfjoin(buf, ft_while(format, ap, &i, k), 3);
	}
	va_end(ap);
	replace(buf);
	return (ft_ret(buf));
}

char	*ft_while(const char *format, va_list ap, int *i, int k)
{
	t_spec	spec;
	char	*buf;
	char	*arg;

	arg = NULL;
	buf = NULL;
	buf = ft_strsub(format, k, *i - k);
	spec = get_spec(format + *i);
	arg = get_arg(ap, spec);
	buf = ft_strfjoin(buf, arg, 1);
	*i = *i + spec.size;
	ft_strdel(&arg);
	return (buf);
}

int		ft_ret(char *buf)
{
	int	ret;

	ret = ft_strlen(buf);
	ft_strdel(&buf);
	return (ret);
}
