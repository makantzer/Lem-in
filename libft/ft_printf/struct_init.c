/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:24:35 by mkantzer          #+#    #+#             */
/*   Updated: 2017/03/31 14:41:07 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	spec_init(void)
{
	t_spec	spec;

	spec.type = 0;
	spec.other = 0;
	spec.width = 0;
	spec.precision = -1;
	spec.size = 0;
	spec.flag = flag_init();
	spec.length = len_init();
	return (spec);
}

t_flag	flag_init(void)
{
	t_flag	flag;

	flag.any = 1;
	flag.neg = 0;
	flag.plus = 0;
	flag.zero = 0;
	flag.sharp = 0;
	flag.space = 0;
	return (flag);
}

t_len	len_init(void)
{
	t_len	len;

	len.any = 0;
	len.hh = 0;
	len.h = 0;
	len.ll = 0;
	len.l = 0;
	len.j = 0;
	len.z = 0;
	return (len);
}
