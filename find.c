/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:04:42 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/20 18:05:12 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lstr	*find_room(t_lstr *lstr, char *name)
{
	while (lstr)
	{
		if (!(ft_strcmp(lstr->name, name)))
			return (lstr);
		lstr = lstr->next;
	}
	return (NULL);
}

t_link	*find_link(t_lstr *lstr, t_lstr *to_find)
{
	while (lstr)
	{
		while (lstr->link)
		{
			if (lstr->link->adress == to_find)
				return (lstr->link);
			lstr->link = lstr->link->next;
		}
		lstr = lstr->next;
	}
	return (NULL);
}
