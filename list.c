/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:57:29 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/21 11:04:56 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*create_link(t_lstr *lstr)
{
	t_link *new;

	new = (t_link*)malloc(sizeof(t_link));
	if (!new)
		return (NULL);
	new->adress = lstr;
	new->next = NULL;
	return (new);
}

t_lstr	*create_room()
{
	t_lstr	*new;

	new = (t_lstr*)malloc(sizeof(t_lstr));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

void 	add_room(t_lstr **lstr, t_lstr *new)
{
	t_lstr *tmp;

	if (!lstr || !new)
		return ;
	if (!(*lstr))
		*lstr = new;
	else
	{
		tmp = *lstr;
		*lstr = new;
		new->next = tmp;
	}
}

void 	add_link(t_link **link, t_link *new)
{
	t_link *tmp;

	if (!link || !new)
		return;
	if (!(*link))
		*link = new;
	else
	{
		tmp = *link;
		*link = new;
		new->next = tmp;
	}
}

void	print_room(t_lstr *room)
{
	int i;
	int j;
	t_lstr	*tmp;
	t_link	*tmp2;

	i = 0;
	tmp = room;
	while(room)
	{
		printf("Maillon nº%i a l'adresse %p\n", i, room);
		ft_printf("  visit = %i\n", room->visit);
		ft_printf("  name = %s\n", room->name);
		ft_printf("  coord_x = %i\n", room->coord_x);
		ft_printf("  coord_y = %i\n", room->coord_y);
		ft_printf("  start = %i\n", room->start);
		ft_printf("  end = %i\n", room->end);
		j = 0;
		tmp2 = room->link;
		while (tmp2)
		{
			//ft_printf("j = %i\n", j);
			printf(" Link nº%i\n", j);
			printf("  adress = %p\n", tmp2->adress);
			tmp2 = tmp2->next;
			j++;
		}
		ft_printf("\n");
		room = room->next;
		i++;
	}
	room = tmp;
}
