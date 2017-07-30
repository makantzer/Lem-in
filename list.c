/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:57:29 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/30 22:18:50 by mkantzer         ###   ########.fr       */
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

t_lstr	*create_room(void)
{
	t_lstr	*new;

	new = (t_lstr*)malloc(sizeof(t_lstr));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	add_room(t_lstr **lstr, t_lstr *new)
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

void	add_link(t_link **link, t_link *new)
{
	t_link *tmp;

	if (!link || !new)
		return ;
	if (!(*link))
		*link = new;
	else
	{
		tmp = *link;
		*link = new;
		new->next = tmp;
	}
}
