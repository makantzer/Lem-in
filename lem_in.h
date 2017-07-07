/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 10:53:12 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/07 16:14:58 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <stdlib.h>
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

typedef	struct		s_lstr
{
	int		i;
	int		coord_x;
	int		coord_y;
	int		start;
	int		end; 
	char 	*name;
	struct s_link *link;
	struct s_lstr *next;
	
}					t_lstr;

typedef	struct		s_link
{
	int		i;
	t_lstr	*adress;
	struct s_link *next;
	
}					t_link;

typedef struct		s_parse
{
	int		start;
	int		start_next;
	int		end;
	int		end_next;
	int		nb_ants;
}					t_parse;

/*
 ** parse.c
*/

int		parse(void);
void	sharp_line(char *line, t_parse *info);
int		nb_ants(t_parse *info);
int		room_pipe(char *line, t_parse *info, t_lstr **lstr);
void	start_end(t_parse *info, t_lstr **lstr);
void	init_info(t_parse *info);
void	print_info(t_parse *info);
int		get_room(t_lstr **new, char *line);


/*
 ** parse.c
*/

void	add_room(t_lstr **lst_r, t_lstr *new);
void	add_link(t_link **link, t_link *new);
void	print_room(t_lstr *room);
t_lstr	*create_room();
t_link	*create_link(t_lstr **lstr, int i);

#endif
