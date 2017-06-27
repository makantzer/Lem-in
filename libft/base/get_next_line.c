/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:38:24 by mkantzer          #+#    #+#             */
/*   Updated: 2017/06/12 13:48:19 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_line(char *all)
{
	int		i;

	i = 0;
	while (all[i] != '\n' && all[i])
		i++;
	return (ft_strsub(all, 0, i));
}

char	*ft_stock(char *all, char *line)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(line) + 1;
	if (ft_strchr(all, '\n') == NULL)
		return (ft_strnew(0));
	str = ft_strsub(all, len, (ft_strlen(all) - len));
	return (str);
}

char	*ft_read(int *ret, char **stock, int fd, char **all)
{
	int			flag;
	char		buf[BUFF_SIZE + 1];

	flag = 0;
	while (!flag && (*ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (*stock != NULL)
		{
			*all = ft_strfjoin(*stock, *all, 3);
			*stock = NULL;
		}
		buf[*ret] = '\0';
		*all = ft_strfjoin(*all, buf, 1);
		if (ft_strchr(*all, '\n') != NULL)
			flag = 1;
	}
	return (*all);
}

void	ft_end(char **all, char **line, char **stock)
{
	char	*erase;

	if (*all[0] == '\0')
	{
		*line = ft_get_line(*stock);
		erase = *stock;
		*stock = ft_stock(*stock, *line);
		ft_strdel(&erase);
	}
	else
	{
		*line = ft_get_line(*all);
		erase = *stock;
		*stock = ft_stock(*all, *line);
		ft_strdel(&erase);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*stock;
	char		*all;
	int			ret;
	char		*erase;

	erase = NULL;
	if (!stock)
		stock = ft_strnew(0);
	all = ft_strnew(0);
	if (fd < 0)
		return (-1);
	if (stock && ft_strchr(stock, '\n') != NULL)
		ret = 1;
	else
		all = ft_read(&ret, &stock, fd, &all);
	if (ret == -1)
		return (-1);
	ft_end(&all, line, &stock);
	erase = all;
	free(erase);
	if (ft_strlen(*line) == 0 && ft_strlen(stock) == 0 && ret == 0)
		return (0);
	return (1);
}
