/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:34:11 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/14 15:29:08 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (!alst || !new)
		return ;
	if (!(*alst))
		*alst = new;
	else
	{
		tmp = *alst;
		*alst = new;
		new->next = tmp;
	}
}
