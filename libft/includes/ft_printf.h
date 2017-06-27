/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:43:17 by mkantzer          #+#    #+#             */
/*   Updated: 2017/04/18 18:14:02 by mkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_flag
{
	int			any;
	int			neg;
	int			plus;
	int			zero;
	int			sharp;
	int			space;
}				t_flag;

typedef struct	s_len
{
	int			any;
	int			hh;
	int			h;
	int			ll;
	int			l;
	int			j;
	int			z;
}				t_len;

typedef struct	s_spec
{
	char		type;
	char		other;
	int			width;
	int			precision;
	int			size;
	t_flag		flag;
	t_len		length;
}				t_spec;

/*
 ** ------------ parse.c ------------
*/

t_spec			get_spec(const char *format);
t_spec			parse_flag(char *str, t_spec spec);
t_spec			other_conv(const char *str, t_spec spec);
t_spec			parse_spec(t_spec spec, char *str);
t_len			parse_length_modif(char *str, t_len len);

/*
 ** ------------ ft_printf.c ------------
*/

int				ft_printf(const char *format, ...);
char			*ft_while(const char *format, va_list ap, int *i, int k);
int				ft_ret(char *buf);

/*
 ** ------------ get_arg.c ------------
*/

char			*get_arg(va_list ap, t_spec spec);
char			*get_arg_next(char *arg, va_list ap, t_spec spec);
char			*get_arg_last(char *arg, va_list ap, t_spec spec);
char			*ldi_modifier(t_spec spec, va_list ap);
char			*loux_modifier(t_spec spec, va_list ap);

/*
 ** ------------ struct_init.c ------------
*/

t_spec			spec_init();
t_flag			flag_init();
t_len			len_init();

/*
 ** ------------ handler_type.c ------------
*/

char			*oux_handler(t_spec spec, uintmax_t arg);
char			*oux_handler_flag(t_spec spec, char *str);
char			*di_handler(t_spec spec, intmax_t arg);
char			*c_handler(t_spec spec, char c);
char			*s_handler(t_spec spec, char *s);

/*
 ** ------------ cs_handler.c ------------
*/

char			*cmaj_handler(t_spec spec, wchar_t c);
char			*smaj_handler(t_spec spec, wchar_t *str);
char			*wide_char(wchar_t c);

/*
 ** ------------ precision.c ------------
*/

char			*oux_precision(uintmax_t arg, int p, uintmax_t base, char *str);
char			*di_precision(intmax_t arg, int p);
char			*neg_precision(uintmax_t arg, int p);
char			*s_precision(char *str, int p);
char			*smaj_precision(wchar_t *old, char *str, int p);

/*
 ** ------------ width.c ------------
*/

char			*width_handler(char *str, t_spec spec);
char			which_c(t_spec spec);
char			*xx_condition(int *w, int *j, char *tmp, char *str);
char			*ft_split(int *ijk, char *tmp, char *str, t_spec spec);

/*
 ** ------------ tools.c ------------
*/

int				intlen(intmax_t nb, intmax_t base);
char			*str_capitalize(char *str);
void			replace(char *str);
int				return_o(wchar_t c);

/*
 ** ------------ flag.c ------------
*/

char			*space_handler(char *str, t_spec spec);
char			*plus_handler(intmax_t nb, char *str);
char			*sharp_handler(char *str, t_spec spec);

#endif
