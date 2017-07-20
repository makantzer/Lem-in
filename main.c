/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 10:52:28 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/20 14:27:35 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_lstr	*lstr;

	lstr = NULL;
	if (parse(&lstr) == 0)
	{
		//ft_putendl("MAIN");
		//print_room(lstr);
		ft_printf("ERROR\n");
		exit(0);
	}
	print_room(lstr);
	//freeeeeeeeeeeeeeeeeee
	return (1);
}
