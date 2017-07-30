/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 17:11:42 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/30 16:07:33 by mkantzer         ###   ########.fr       */
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
}

char	**fill_result(char **result, t_wait **wl_last, int i)
{
	t_wait	*current;

	current = *wl_last;
	while (current->origin)
	{
		result[i] = ft_strdup(current->room->name);
		//ft_printf("result[%i] = %s\n", i, result[i]);
		current = current->origin;
		i--;
	}
	result[i] = current->room->name;
	//ft_printf("result[%i] = %s\n", i, result[i]);
	return (result);
}

void	print_line(int nb_ants, char **result, int room, int ants_base)
{
	if (room != 0 && nb_ants < ants_base)
	{
		ft_printf("L%i-%s ", nb_ants, result[room]);
		print_line(++nb_ants, result, --room, ants_base);
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
		print_line(nb_ants, result, room, info->nb_ants);
		ft_putchar('\n');
		if (room == result_size)
		{
			end++;
			room--;
			nb_ants++;
		}
	}
}
