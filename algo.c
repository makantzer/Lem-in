/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:44:18 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/22 21:50:05 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	waiting_list(t_lstr **lstr)
{
	t_lstr	*start;
	t_wait	*wl;
	t_link	*tmp;
	t_wait	*tmp2;
	t_lstr	*origin;

	origin = NULL;
	start = find_start(*lstr);
	wl = create_wl(start, 0);
	tmp2 = wl;
	while (wl)
	{
		if (wl->room->end == 1)
		{
			print_wl(tmp2);
			ft_printf("TROUVE");
			exit(0);
		}
		tmp = wl->room->link;
		while (tmp)
		{
			origin = wl->room;
			if (tmp->adress->visit == 0 && tmp->adress->start != 1)
			{
				add_to_wl(&wl, create_wl(tmp->adress, origin));
				tmp->adress->visit = 1;
			}
			tmp = tmp->next;
		}
		wl = wl->next;
	}
	//print_wl(tmp2);
}

void	add_to_wl(t_wait **wl, t_wait *new)
{
	t_wait	*tmp;

	if (!wl || !new)
		return;
	if (!(*wl))
		*wl = new;
	else
	{
		tmp = *wl;
		while (tmp)
		{
			if (tmp->next == NULL)
			{
				tmp->next = new;
				break;
			}
			tmp = tmp->next;
		}
	}
}

t_wait	*create_wl(t_lstr *room, t_lstr *origin)
{
	t_wait	*new;

	new = (t_wait*)malloc(sizeof(t_wait));
	if (!new)
		return (NULL);
	new->room = room;
	new->origin = origin;
	new->next = NULL;
	return (new);
}

void	print_wl(t_wait *wl)
{
	t_wait	*tmp;
	int		i;

	tmp = wl;
	i = 0;
	ft_printf("WAITING LIST -----------\n");
	while (tmp)
	{
		ft_printf("NAME = %s\n", tmp->room->name);
		ft_printf(" Position = %i\n", i);
		//ft_printf(" Adress = %p\n", tmp);
		ft_printf(" Room = %p\n", tmp->room);
		ft_printf(" Origin = %p\n", tmp->origin);
		if (tmp->origin != NULL)
			ft_printf(" name = %s\n", tmp->origin->name);
		tmp = tmp->next;
		ft_putchar('\n');
		i++;
	}
}
