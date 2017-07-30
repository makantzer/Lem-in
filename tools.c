/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:57:34 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/30 22:16:05 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_info(t_parse *info)
{
	info->start = 0;
	info->start_next = 0;
	info->end = 0;
	info->end_next = 0;
	info->nb_ants = 0;
	info->tube = 0;
}

void	free_wl(t_wait **wl)
{
	if ((*wl)->next)
		free_wl(&((*wl)->next));
	if (*wl)
		free(*wl);
}

void	free_link(t_link **link)
{
	if ((*link)->next)
		free_link(&((*link)->next));
	if (*link)
		free(*link);
}

void	free_lstr(t_lstr **lstr)
{
	if ((*lstr)->link)
		free_link(&(*lstr)->link);
	if ((*lstr)->next)
	{
		free((*lstr)->name);
		free_lstr(&((*lstr)->next));
	}
	if (*lstr)
		free(*lstr);
}

void	free_tab(char **result, int i)
{
	while (i >= 0)
	{
		ft_strdel(&result[i]);
		result[i] = NULL;
		i--;
	}
	free(result);
}
