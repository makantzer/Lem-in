/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:44:18 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/30 22:10:30 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		waiting_list(t_lstr **lstr, t_wait **wl, t_wait **tmp2)
{
	t_lstr	*start;
	t_link	*tmp;
	t_wait	*origin;

	start = find_start(*lstr);
	*wl = create_wl(start, 0);
	*tmp2 = *wl;
	while (*tmp2)
	{
		if ((*tmp2)->room->end == 1)
			return (1);
		tmp = (*tmp2)->room->link;
		while (tmp)
		{
			origin = (*tmp2);
			if (tmp->adress->visit == 0 && tmp->adress->start != 1)
			{
				add_to_wl(tmp2, create_wl(tmp->adress, origin));
				tmp->adress->visit = 1;
			}
			tmp = tmp->next;
		}
		*tmp2 = (*tmp2)->next;
	}
	return (0);
}

void	add_to_wl(t_wait **wl, t_wait *new)
{
	t_wait	*tmp;

	if (!wl || !new)
		return ;
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
				return ;
			}
			tmp = tmp->next;
		}
	}
}

t_wait	*create_wl(t_lstr *room, t_wait *origin)
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
