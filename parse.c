/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 10:50:18 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/08 20:22:19 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		parse(void)
{
	int		ret;
	t_parse	info;
	char *line;
	t_lstr	*lstr;

	//line = ft_strnew(0);
	init_info(&info);
	lstr = NULL;
	if (nb_ants(&info) == 0)
		return (0);
	while ((ret = get_next_line(0, &line) > 0))
	{
		if (line[0] == '#')
			sharp_line(line, &info);
		else
		{
			ft_printf("%s\n", line);
			if (ft_strchr(line, '-') != NULL)
			{
				ft_printf("toto\n");
				if (!get_pipe(&lstr, line))
					return (0);
			}
			if (!room_pipe(line, &info, &lstr))
				return (0);
		}
		//ft_printf("%s\n", line);
		//print_room(lstr);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}

int		room_pipe(char *line, t_parse *info, t_lstr **lstr)
{
	t_lstr	*new;

	new = create_room();
	//print_info(info);
	//Ici faire recuperation salle
	if (!get_room(&new, line))
		return (0);
	start_end(info, &new);
	add_room(lstr, new);
	//print_room(*lstr);
	return(1);
}
//Faire une fonction de fin qui check si il y a un start et un end et qu'ils etaient differents.

t_lstr	*find_room(t_lstr **lstr, char *name)
{
	while (lstr)
	{
		ft_printf("%s\n", (*lstr)->name);
		if ((*lstr)->name == name)
		{
			ft_printf("%p\n", lstr);
			return (*lstr);
		}
		*lstr = (*lstr)->next;
	}
	return (NULL);
}

int		get_pipe(t_lstr **lstr, char *line)
{
	char **data;
	int i;
	t_lstr	*from;
	t_lstr	*to;
	//t_link	link;

	i = 0;
	data = ft_strsplit(line, '-');
	while (data[i])
		i++;
	ft_printf("%i\n", i);
	if (i != 1)
		return (0);
	from = find_room(lstr, data[0]);
	to = find_room(lstr, data[1]);
	ft_printf("from - %p\nto - %p\n", from, to);
	/*if (from != NULL && to != NULL)
	{
		link = create_link(find_room(lstr, data[1]), 1);
		add_link((*lstr)->link, link);
	}
	else
		return (0);*/
	print_room(*lstr);
	//Faire l'inverse (les directions n'ont pas de sens)
	// /!\. Sans tmp le deplacement dans la liste chaine est garde.
	return (1);
}
int		get_room(t_lstr **new, char *line)
{
	char **data;
	int i;

	i = 0;
	data = ft_strsplit(line, ' ');
	while (data[i])
		i++;
	if (i != 3)
		return (0);
	(*new)->name = data[0];
	(*new)->coord_x = ft_atoi(data[1]);
	(*new)->coord_y = ft_atoi(data[2]);
	return (1);
}

void	start_end(t_parse *info, t_lstr **lstr)
{
	if (info->start_next == 1)
	{
		(*lstr)->start = 1;
		info->start_next = 0;
	}
	else
		(*lstr)->start = 0;
	if (info->end_next == 1)
	{
		(*lstr)->end = 1;
		info->end_next = 0;
	}
	else
		(*lstr)->end = 0;
}

int		nb_ants(t_parse *info)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	while (line[i])
	{
		if (ft_isalpha(line[i] == 1) || ft_isspace(line[i]) == 1)
			return(0);
		i++;
	}
	if (ft_atoi(line) <= 0)
		return(0);
	info->nb_ants = ft_atoi(line);
	ft_strdel(&line);
	return (1);
}

void	sharp_line(char *line, t_parse *info)
{
	if (line[1] == '#')
	{
		if (ft_strcmp(line + 2, "start") == 0)
		{
			info->start = 1;
			info->start_next = 1;
		}
		else if (ft_strcmp(line + 2, "end") == 0)
		{
			info->end = 1;
			info->end_next = 1;
		}
	}
}

void	init_info(t_parse *info)
{
	info->start = 0;
	info->start_next = 0;
	info->end = 0;
	info->end_next = 0;
	info->nb_ants = 0;
}

void	print_info(t_parse *info)
{
	ft_printf("Info struct :\n");
	ft_printf(" start = %i\n", info->start);
	ft_printf(" start_next = %i\n", info->start_next);
	ft_printf(" end = %i\n", info->end);
	ft_printf(" end_next = %i\n", info->end_next);
	ft_printf(" nb_ants = %i\n", info->nb_ants);
}
