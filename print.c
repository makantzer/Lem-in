/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 17:11:42 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/30 22:27:36 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_result(t_wait **wl_last, t_parse *info)
{
	t_wait	*current;
	char	**result;
	int		i;

	i = 0;
	result = NULL;
	current = *wl_last;
	while (current->origin)
	{
		current = current->origin;
		i++;
	}
	result = (char **)ft_memalloc((i + 1) * sizeof(char*));
	result = fill_result(result, wl_last, i);
	print_ants(result, info, i);
	free_tab(result, i);
}

char	**fill_result(char **result, t_wait **wl_last, int i)
{
	t_wait	*current;

	current = *wl_last;
	while (current->origin)
	{
		result[i] = ft_strdup(current->room->name);
		current = current->origin;
		i--;
	}
	result[i] = current->room->name;
	return (result);
}

void	pl(int nb_ants, char **result, int room, int ants_base)
{
	if (room != 0 && nb_ants < ants_base)
	{
		ft_printf("L%i-%s ", nb_ants, result[room]);
		pl(++nb_ants, result, --room, ants_base);
	}
	else
		ft_printf("L%i-%s ", nb_ants, result[room]);
}

void	print_ants(char **result, t_parse *info, int result_size)
{
	int	end;
	int	nb_ants;
	int	room;

	end = 0;
	nb_ants = 1;
	room = -1;
	while (end < info->nb_ants)
	{
		room++;
		pl(nb_ants, result, room, info->nb_ants);
		ft_putchar('\n');
		if (room == result_size)
		{
			end++;
			room--;
			nb_ants++;
		}
	}
}
