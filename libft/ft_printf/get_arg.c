/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:35:15 by mkantzer          #+#    #+#             */
/*   Updated: 2017/03/31 16:05:27 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_arg(va_list ap, t_spec spec)
{
	char *arg;

	arg = NULL;
	if (spec.type == 0)
		return (ft_strdup(""));
	if (spec.type == 'D' || spec.type == 'O' || spec.type == 'U')
	{
		spec.length.any = 1;
		spec.length.ll = 1;
	}
	if (spec.type == 'C')
		arg = cmaj_handler(spec, va_arg(ap, wchar_t));
	else if (spec.type == 'S')
		arg = smaj_handler(spec, va_arg(ap, wchar_t *));
	else if (spec.type == 's')
	{
		if (spec.length.l == 1)
			arg = smaj_handler(spec, va_arg(ap, wchar_t *));
		else
			arg = s_handler(spec, va_arg(ap, char *));
	}
	else
		return (get_arg_next(arg, ap, spec));
	return (arg);
}

char	*get_arg_next(char *arg, va_list ap, t_spec spec)
{
	if (spec.type == 'c')
	{
		if (spec.length.l == 1)
			arg = cmaj_handler(spec, va_arg(ap, wchar_t));
		else
			arg = c_handler(spec, (char)va_arg(ap, int));
	}
	else if (spec.type == 'd' || spec.type == 'D' || spec.type == 'i')
	{
		if (spec.length.any == 1)
			arg = ldi_modifier(spec, ap);
		else
			arg = di_handler(spec, va_arg(ap, int));
	}
	else if (spec.type == 'o' || spec.type == 'O' || spec.type == 'u' || \
			spec.type == 'U' || spec.type == 'x' || spec.type == 'X')
	{
		if (spec.length.any == 1)
			arg = loux_modifier(spec, ap);
		else
			arg = oux_handler(spec, va_arg(ap, unsigned int));
	}
	else
		return (get_arg_last(arg, ap, spec));
	return (arg);
}

char	*get_arg_last(char *arg, va_list ap, t_spec spec)
{
	if (spec.type == 'p')
	{
		spec.flag.sharp = 1;
		spec.flag.any = 1;
		arg = oux_handler(spec, (size_t)va_arg(ap, void *));
	}
	else if (spec.type == '%')
	{
		arg = ft_strdup("%");
		if (spec.width != 0)
			arg = width_handler(arg, spec);
	}
	else
	{
		arg = ft_strdup("");
		if (spec.width != 0 || spec.precision != -1)
			arg = c_handler(spec, spec.other);
	}
	return (arg);
}

char	*loux_modifier(t_spec spec, va_list ap)
{
	char	*arg;

	if (spec.length.ll == 1)
		arg = oux_handler(spec, va_arg(ap, unsigned long long int));
	else if (spec.length.hh == 1)
		arg = oux_handler(spec, (unsigned char)va_arg(ap, unsigned int));
	else if (spec.length.h == 1)
		arg = oux_handler(spec, (unsigned short int)va_arg(ap, unsigned int));
	else if (spec.length.l == 1)
		arg = oux_handler(spec, va_arg(ap, unsigned long int));
	else if (spec.length.j == 1)
		arg = oux_handler(spec, va_arg(ap, uintmax_t));
	else if (spec.length.z == 1)
		arg = oux_handler(spec, va_arg(ap, size_t));
	else
		arg = oux_handler(spec, va_arg(ap, uintmax_t));
	return (arg);
}

char	*ldi_modifier(t_spec spec, va_list ap)
{
	char	*arg;

	if (spec.length.ll == 1)
		arg = di_handler(spec, va_arg(ap, long long int));
	else if (spec.length.hh == 1)
		arg = di_handler(spec, (char)va_arg(ap, int));
	else if (spec.length.h == 1)
		arg = di_handler(spec, (short int)va_arg(ap, int));
	else if (spec.length.l == 1)
		arg = di_handler(spec, va_arg(ap, long int));
	else if (spec.length.j == 1)
		arg = di_handler(spec, va_arg(ap, intmax_t));
	else if (spec.length.z == 1)
		arg = di_handler(spec, va_arg(ap, size_t));
	else
		arg = oux_handler(spec, va_arg(ap, intmax_t));
	return (arg);
}
