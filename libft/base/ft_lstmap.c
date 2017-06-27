/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:05:26 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/14 15:41:57 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;

	first = NULL;
	if (!lst || !f)
		return (NULL);
	if (lst)
	{
		first = f(ft_lstnew(lst->content, lst->content_size));
		new = first;
		while ((lst = lst->next))
		{
			new->next = f(ft_lstnew(lst->content, lst->content_size));
			new = new->next;
		}
		return (first);
	}
	return (NULL);
}
