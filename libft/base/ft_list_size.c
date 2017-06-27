/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:08:06 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/14 17:08:56 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = begin_list;
	if (tmp)
	{
		count = 1;
		while (tmp->next)
		{
			count++;
			tmp = tmp->next;
		}
	}
	return (count);
}
