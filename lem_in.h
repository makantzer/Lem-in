/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 10:53:12 by mkantzer          #+#    #+#             */
/*   Updated: 2017/07/30 22:29:58 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <stdlib.h>
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

typedef	struct		s_lstr
{
	int				coord_x;
	int				coord_y;
	int				start;
	int				end;
	char			*name;
	int				visit;
	struct s_link	*link;
	struct s_lstr	*next;
}					t_lstr;

typedef	struct		s_link
{
	t_lstr			*adress;
	struct s_link	*next;
}					t_link;

typedef	struct		s_wait
{
	t_lstr			*room;
	struct s_wait	*origin;
	struct s_wait	*next;
}					t_wait;

typedef struct		s_parse
{
	int				start;
	int				start_next;
	int				end;
	int				end_next;
	int				nb_ants;
	int				tube;
}					t_parse;

/*
 ** parse.c
*/

int					parse(t_lstr **lstr, t_parse *info);
void				sharp_line(char *line, t_parse *info);
int					nb_ants(t_parse *info);
int					start_end(t_parse *info, t_lstr **lstr);
int					final_check(t_parse info, t_lstr **lstr);

/*
 **	find.c
*/

t_lstr				*find_room(t_lstr *lstr, char *name);
t_lstr				*find_start(t_lstr *lstr);
t_link				*find_link(t_lstr *lstr, t_lstr *to_find, t_lstr *to_check);

/*
 **	algo.c
*/

int					waiting_list(t_lstr **lstr, t_wait **wl, t_wait **t_last);
t_wait				*create_wl(t_lstr *room, t_wait *origin);
void				add_to_wl(t_wait **wl, t_wait *new);

/*
 ** room_pipe.c
*/

int					room_pipe(char *line, t_parse *info, t_lstr **lstr);
int					get_room(t_lstr **lstr, t_lstr **new, char *line);
int					get_pipe(t_lstr **lstr, char *line);
int					add_pipe(t_lstr **lstr, t_lstr *from, t_lstr *to);
int					check_alpha(char *str);

/*
 ** tools.c
*/

void				init_info(t_parse *info);
void				free_lstr(t_lstr **lstr);
void				free_wl(t_wait **wl);
void				free_link(t_link **link);
void				free_tab(char **result, int i);

/*
 ** print.c
*/

void				print_result(t_wait **wl_last, t_parse *info);
char				**fill_result(char **result, t_wait **wl_last, int i);
void				print_ants(char **result, t_parse *info, int result_size);
void				pl(int nb_ants, char **result, int room, int ants_base);

/*
 ** list.c
*/

void				add_room(t_lstr **lst_r, t_lstr *new);
void				add_link(t_link **link, t_link *new);
t_lstr				*create_room();
t_link				*create_link(t_lstr *lstr);

#endif
