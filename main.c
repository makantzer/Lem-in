/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 10:52:28 by mkantzer          #+#    #+#             */
/*   Updated: 2017/06/27 14:05:43 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	/*t_lstr	*lstr;
	t_lstr	*plus;
	int i;*/

	if (parse() == 0)
	{
		ft_printf("Wrong Map\n");
		exit(0);
	}
	/*lstr = create_room();
	lstr->i = 3;
	lstr->coord_x = 35;
	lstr->coord_y = 6;
	lstr->name = "test";
	i = 0;
	lstr->link = create_link(&lstr, i); 
	plus = create_room();
	plus->i = 4;
	plus->coord_x = 4;
	plus->coord_y = 6;
	plus->name = "test2";
	add_room(&lstr, plus);
	plus->link = create_link(&plus, i);
	add_link(&plus->link, create_link(&plus, i));
	print_room(lstr);*/
	//Delete stuct a chaque passage?
	return (1);
}

/*t_link	retrieve_room(t_link link)
{

}*/
