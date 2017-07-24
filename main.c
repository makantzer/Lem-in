/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 10:52:28 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/24 21:01:53 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_lstr	*lstr;
	t_wait	*wl;
	t_wait	*wl_last;
	t_parse	*info;
	char	**result;

	lstr = NULL;
	info = NULL;
	wl = NULL;
	wl_last = NULL;
	if (parse(&lstr) == 0)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	print_room(lstr);
	waiting_list(&lstr, &wl, &wl_last);
	print_wl(wl);
	print_wl(wl_last);
	result = to_tab(&wl_last);
	//print_result(result, &info);
	//freeeeeeeeeeeeeeeeeee
	return (1);
}
