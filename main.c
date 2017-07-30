/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 10:52:28 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/30 22:08:45 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_lstr	*lstr;
	t_wait	*wl;
	t_wait	*wl_last;
	t_parse	info;

	lstr = NULL;
	if (parse(&lstr, &info) == 0)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	if (waiting_list(&lstr, &wl, &wl_last) == 0)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	print_result(&wl_last, &info);
	free_wl(&wl);
	free_lstr(&lstr);
	return (1);
}
