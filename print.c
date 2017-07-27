/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 17:11:42 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/27 17:45:12 by mkantzer         ###   ########.fr       */
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
	//print_result(result, info, i, 0);
	print_second(result, info, i);
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

char	*add_ants(int size, char **ants)
{
	char	*new;

	new = ft_strnew(size + 2);
	new = ft_strjoin(*ants, ft_itoa(size + 1));
	//ft_strdel(ants);
	return (new);
}

char 	*pop_ants(int size, char **ants)
{
	char *new;
	
	new = ft_strsub(*ants, 1, size - 1);
	return(new);
}

void	print_second(char **result, t_parse *info, int result_size)
{
	char	*ants;
	size_t	j;
	size_t	end;
	int		start;
	int		current;

	current = 0;
	end = 0;
	start = 0;
	ants = ft_strdup("1");
	while (end < info->nb_ants - 1)
	{
		j = 1;
		if (start == result_size + 1)
		{
			ants = pop_ants(ft_strlen(ants), &ants);
			start--;
			end++;
		}
		current = start;
		while (j <= ft_strlen(ants))
			ft_printf("L%i-%s ", j++, result[current--]);
		start++;
		if (ft_strlen(ants) < info->nb_ants && start != result_size + 1)
			ants = add_ants(ft_strlen(ants), &ants);
		ft_putchar('\n');
	}
	ft_strdel(&ants);
}

void	print_result(char **result, t_parse *info, int result_size, int current)
{
	char	*ants;
	size_t	j;
	size_t	end;
	int		start;

	end = 0;
	start = 0;
	ants = ft_strdup("1");
	while (end < info->nb_ants - 1)
	{
		j = 0;
		if (start == result_size + 1)
		{
			ants = pop_ants(ft_strlen(ants), &ants);
			start--;
			end++;
		}
		current = start;
		while (j < ft_strlen(ants))
			ft_printf("L%c-%s ", ants[j++], result[current--]);
		start++;
		if (ft_strlen(ants) < info->nb_ants && start != result_size + 1)
			ants = add_ants(ft_strlen(ants), &ants);
		ft_putchar('\n');
	}
	ft_strdel(&ants);
}
