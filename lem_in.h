/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 10:53:12 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/20 18:09:25 by mkantzer         ###   ########.fr       */
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
	int		tube;
}					t_parse;

/*
 ** parse.c
*/

int		parse(t_lstr **lstr);
void	sharp_line(char *line, t_parse *info);
int		nb_ants(t_parse *info);
int		start_end(t_parse *info, t_lstr **lstr);
int		final_check(t_parse info, t_lstr **lstr);

/*
 **	find.c
*/

t_lstr	*find_room(t_lstr *lstr, char *name);
t_link	*find_link(t_lstr *lstr, t_lstr *to_find);

/*
 ** room_pipe.c
*/

int		room_pipe(char *line, t_parse *info, t_lstr **lstr);
int		get_room(t_lstr **lstr, t_lstr **new, char *line);
int		get_pipe(t_lstr **lstr, char *line);
int		add_pipe(t_lstr **lstr, t_lstr *from, t_lstr *to);

/*
 ** tools.c
*/

void	init_info(t_parse *info);
int		check_alpha(char *str);

/*
 ** list.c
*/

void	add_room(t_lstr **lst_r, t_lstr *new);
void	add_link(t_link **link, t_link *new);
void	print_room(t_lstr *room);
t_lstr	*create_room();
t_link	*create_link(t_lstr *lstr, int i);

#endif
