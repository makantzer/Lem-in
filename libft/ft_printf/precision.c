/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:37:53 by mkantzer          #+#    #+#             */
/*   Updated: 2017/03/31 11:35:46 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*oux_precision(uintmax_t arg, int p, uintmax_t base, char *str)
{
	int			i;
	int			j;
	uintmax_t	k;
	char		*tmp;

	j = 0;
	i = intlen(arg, base);
	k = -1;
	if (p < i)
		return (str);
	tmp = ft_strdup(str);
	ft_strdel(&str);
	str = ft_strnew(p + 1);
	while (j <= p - 1)
	{
		if (j < p - i)
			str[j] = '0';
		else
			str[j] = tmp[++k];
		j++;
	}
	free(tmp);
	return (str);
}

char	*di_precision(intmax_t arg, int p)
{
	int			i;

	i = intlen(arg, 10);
	if (p < i)
		return (ft_itoa_base(arg, 10));
	if (arg < 0)
		return (neg_precision((arg * -1), p));
	else
		return (oux_precision(arg, p, 10, ft_itoa_base(arg, 10)));
}

char	*neg_precision(uintmax_t arg, int p)
{
	int			i;
	int			j;
	uintmax_t	k;
	char		*tmp;
	char		*str;

	j = 0;
	i = intlen(arg, 10);
	k = -1;
	p++;
	str = ft_strnew(p + 1);
	str[j++] = '-';
	tmp = ft_itoa_base(arg, 10);
	while (j <= p - 1)
	{
		if (j < p - i)
			str[j] = '0';
		else
			str[j] = tmp[++k];
		j++;
	}
	free(tmp);
	return (str);
}

char	*s_precision(char *str, int p)
{
	int			j;
	char		*tmp;

	j = 0;
	tmp = str;
	str = ft_strnew(p + 1);
	while (j <= p - 1 && tmp[j])
	{
		str[j] = tmp[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*smaj_precision(wchar_t *old, char *str, int p)
{
	int			j;
	int			o;
	int			k;
	int			m;
	char		*tmp;

	j = 0;
	o = 0;
	m = 0;
	tmp = str;
	str = ft_strnew(p + 1);
	while (j < p && tmp[j])
	{
		k = -1;
		o = return_o(old[m]);
		if (j + o <= p)
			while (++k < o)
				str[j + k] = tmp[j + k];
		j += o;
		m++;
	}
	str[j] = '\0';
	return (str);
}
