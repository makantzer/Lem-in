/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 10:50:18 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/25 13:57:30 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		parse(t_lstr **lstr, t_parse *info)
{
	int		ret;
	char	*line;

	//line = ft_strnew(0);
	init_info(info);
	if (nb_ants(info) == 0)
		return (0);
	while ((ret = get_next_line(0, &line) > 0))
	{
		if (line[0] == '#')
			sharp_line(line, info);
		else
		{
			if (!room_pipe(line, info, lstr))
				return (0);
		}
		ft_putendl(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!final_check(*info, lstr))
		return (0);
	return (1);
}

int		final_check(t_parse info, t_lstr **lstr)
{
	t_lstr	*tmp;
	char	*start;
	char	*end;

	tmp = *lstr;
	while (tmp)
	{
		if (tmp->start == 1)
			start = tmp->name;
		if (tmp->end == 1)
			end = tmp->name;
		tmp = tmp->next;
	}
	if (ft_strcmp(start, end) == 0)
		return (0);
	if (info.start == 0)
		return (0);
	if (info.tube == 0)
		return (0);
	if (info.end == 0)
		return (0);
	return (1);
}

int		start_end(t_parse *info, t_lstr **lstr)
{
	if (info->start_next == 1)
	{
		(*lstr)->start = 1;
		info->start = 1;
		info->start_next = 0;
	}
	else
		(*lstr)->start = 0;
	if (info->end_next == 1)
	{
		(*lstr)->end = 1;
		info->end = 1;
		info->end_next = 0;
	}
	else
		(*lstr)->end = 0;
	return (1);
}

int		nb_ants(t_parse *info)
{
	char	*line;
	int		i;
	int		nb;

	i = 0;
	get_next_line(0, &line);
	while (line[i])
	{
		if (ft_isalpha(line[i] == 1) || ft_isspace(line[i]) == 1)
			return (0);
		i++;
	}
	nb = ft_atoi(line);
	if (nb <= 0 || nb == 2147483647)
		return (0);
	info->nb_ants = nb;
	ft_putendl(line);
	ft_strdel(&line);
	return (1);
}

void	sharp_line(char *line, t_parse *info)
{
	if (line[1] == '#')
	{
		if (ft_strcmp(line + 2, "start") == 0)
			info->start_next = 1;
		else if (ft_strcmp(line + 2, "end") == 0)
			info->end_next = 1;
	}
}
