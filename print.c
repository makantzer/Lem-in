/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 17:11:42 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/24 20:56:53 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**to_tab(t_wait **wl_last)
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
	ft_printf("nb = %i\n", i);
	result = (char **)ft_memalloc((i + 1) * sizeof(char*));
	result = fill_result(result, wl_last, i);
	//print_result(result);
	return (result);
}

char	**fill_result(char **result, t_wait **wl_last, int i)
{
	t_wait	*current;

	current = *wl_last;
	while (current->origin)
	{
		result[i] = ft_strdup(current->room->name);
		ft_printf("result[%i] = %s\n", i, result[i]);
		current = current->origin;
		i--;
	}
	result[i] = current->room->name;
	ft_printf("result[%i] = %s\n", i, result[i]);
	return (result);
}

void	print_result(char **result, t_parse **info)
{
	result[1] = NULL;
	ft_printf("NB ANTS IN PRINT = %i\n", (*info)->nb_ants);
}
