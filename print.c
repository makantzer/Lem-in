/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 17:11:42 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/25 17:28:37 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**to_tab(t_wait **wl_last, t_parse *info)
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
	print_result(result, info, i);
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

/*void	print_test()
{
	int l;

	l = 0;
	while (l < )
}*/

void	print_result(char **result, t_parse *info, int result_size)
{
	int i;
	int	j;
	int	k;
	int	ants_count;

	k = 0;
	ants_count = 1;
	i = 0;
	j = 0;
	ft_printf("\nnb ants = %i\n", info->nb_ants);
	ft_printf("size_result = %i\n", result_size);
	while (ants_count <= info->nb_ants)
	{
		//ft_printf("i = %i\n", i);
		k = 0;
		while (k <= result_size)
		{
			ft_printf("k = %i\n", k);
			ft_printf("L%i-%s\n", ants_count, result[k]);
			k++;
		}
		ants_count++;
		//i++;
	}
}
