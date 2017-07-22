/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:04:42 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/22 21:23:00 by mkantzer         ###   ########.fr       */
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

t_link	*find_link(t_lstr *lstr, t_lstr *to_find, t_lstr *to_check)
{
	t_lstr	*tmp;
	t_link	*tmp2;

	tmp = lstr;
	while (tmp)
	{
		if (tmp == to_check)
		{
			tmp2 = tmp->link;
			while (tmp2)
			{
				if (tmp2->adress == to_find)
					return (tmp2);
				tmp2 = tmp2->next;
			}
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_lstr	*find_start(t_lstr *lstr)
{
	t_lstr *tmp;

	tmp = lstr;
	while (tmp)
	{
		if (tmp->start == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
