/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:01:42 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/20 18:02:54 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		room_pipe(char *line, t_parse *info, t_lstr **lstr)
{
	t_lstr	*new;

	if (ft_strchr(line, '-') != NULL)
		info->tube = 1;
	if (info->tube == 0)
	{
		new = create_room();
		if (!get_room(lstr, &new, line))
			return (0);
		if (!(start_end(info, &new)))
			return (0);
		add_room(lstr, new);
	}
	else
	{
		info->tube = 1;
		if (!get_pipe(lstr, line))
			return (0);
	}
	return (1);
}

int		get_room(t_lstr **lstr, t_lstr **new, char *line)
{
	char	**data;
	int		i;

	i = 0;
	data = ft_strsplit(line, ' ');
	while (data[i])
		i++;
	if (i != 3)
		return (0);
	if (find_room(*lstr, data[0]) != NULL)
		return (0);
	(*new)->name = data[0];
	if (!(check_alpha(data[1])) || !(check_alpha(data[2])))
		return (0);
	(*new)->coord_x = ft_atoi(data[1]);
	(*new)->coord_y = ft_atoi(data[2]);
	return (1);
}

int		get_pipe(t_lstr **lstr, char *line)
{
	char	**data;
	t_lstr	*from;
	t_lstr	*to;
	int		i;

	i = 0;
	data = ft_strsplit(line, '-');
	while (data[i])
		i++;
	if (i != 2)
		return (0);
	from = find_room(*lstr, data[0]);
	to = find_room(*lstr, data[1]);
	if (find_link(*lstr, from) != NULL && find_link(*lstr, to) != NULL)
		return (1);
	if (from != NULL && to != NULL)
		add_pipe(lstr, from, to);
	else
		return (0);
	return (1);
}

int		add_pipe(t_lstr **lstr, t_lstr *from, t_lstr *to)
{
	t_link	*link1;
	t_link	*link2;
	t_lstr	*tmp;

	tmp = *lstr;
	link1 = create_link(from, 1);
	link2 = create_link(to, 1);
	while (tmp)
	{
		if (tmp == from)
			add_link((&(tmp)->link), link2);
		if (tmp == to)
			add_link((&(tmp)->link), link1);
		tmp = (tmp)->next;
	}
	return (1);
}
