/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:28:51 by mkantzer          #+#    #+#             */
/*   Updated: 2016/11/11 15:33:59 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_number(char const *s, char c)
{
	int i;
	int j;
	int nb;

	i = 0;
	j = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (nb);
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		if (j != 0)
			nb++;
		if (s[j] == '\0')
			return (nb);
		i = j;
	}
	return (nb);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (s == '\0')
		return (NULL);
	i = 0;
	k = 0;
	tab = (char**)malloc((ft_words_number(s, c) + 1) * sizeof(char*));
	if (tab == 0)
		return (0);
	while (k < ft_words_number(s, c))
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		tab[k] = ft_strsub(s, i, (j - i));
		k++;
		i = j;
	}
	tab[k] = 0;
	return (tab);
}
