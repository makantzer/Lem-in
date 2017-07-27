/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 10:53:12 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/27 17:41:57 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <stdlib.h>
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

typedef	struct		s_lstr
{
	int		coord_x;
	int		coord_y;
	int		start;
	int		end; 
	char 	*name;
	int		visit;
	struct s_link *link;
	struct s_lstr *next;
	
}					t_lstr;

typedef	struct		s_link
{
	t_lstr	*adress;
	struct s_link *next;
	
}					t_link;

typedef	struct		s_wait
{
	t_lstr	*room;
	struct s_wait	*origin;
	struct s_wait	*next;
	
}					t_wait;

typedef struct		s_parse
{
	int		start;
	int		start_next;
	int		end;
	int		end_next;
	size_t	nb_ants;
	int		tube;
}					t_parse;

/*
 ** parse.c
*/

int		parse(t_lstr **lstr, t_parse *info);
void	sharp_line(char *line, t_parse *info);
int		nb_ants(t_parse *info);
int		start_end(t_parse *info, t_lstr **lstr);
int		final_check(t_parse info, t_lstr **lstr);

/*
 **	find.c
*/

t_lstr	*find_room(t_lstr *lstr, char *name);
t_lstr	*find_start(t_lstr *lstr);
t_link	*find_link(t_lstr *lstr, t_lstr *to_find, t_lstr *to_check);

/*
 **	algo.c
*/

void	waiting_list(t_lstr **lstr, t_wait **wl, t_wait **t_last);
t_wait	*create_wl(t_lstr *room, t_wait *origin);
void	add_to_wl(t_wait **wl, t_wait *new);
void	print_wl(t_wait *wl);

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
 ** print.c
*/

char	**to_tab(t_wait **wl_last, t_parse *info);
char	**fill_result(char **result, t_wait **wl_last, int i);
void	print_result(char **result, t_parse *info, int result_size, int current);
void	print_second(char **result, t_parse *info, int result_size);
char	*add_ants(int size, char **ants);
char	*pop_ants(int size, char **ants);

/*
 ** list.c
*/

void	add_room(t_lstr **lst_r, t_lstr *new);
void	add_link(t_link **link, t_link *new);
void	print_room(t_lstr *room);
t_lstr	*create_room();
t_link	*create_link(t_lstr *lstr);

#endif
