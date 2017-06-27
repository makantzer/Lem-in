# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 10:31:32 by mkantzer          #+#    #+#              #
#    Updated: 2017/06/16 11:11:33 by mkantzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PRINT_SRC =	ft_printf.c\
		handler_type.c\
		cs_handler.c\
		precision.c\
		width.c\
		struct_init.c\
		flag.c\
		get_arg.c\
		parse.c\
		tools.c
LIB_SRC =	ft_atoi.c\
	ft_bzero.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_isspace.c\
	ft_itoa.c\
	ft_uitoa.c\
	ft_itoa_base.c\
	ft_uitoa_base.c\
	ft_lstadd.c\
	ft_lstdel.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_memalloc.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memdel.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar.c\
	ft_putchar_fd.c\
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_putnbr.c\
	ft_putnbr_fd.c\
	ft_putstr.c\
	ft_putstr_fd.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strclr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdel.c\
	ft_strdup.c\
	ft_strequ.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strfjoin.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strsplit.c\
	ft_strstr.c\
	ft_strsub.c\
	ft_strtrim.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_factorial.c\
	ft_list_size.c\
	ft_range.c\
	ft_swap.c\
	get_next_line.c
POBJ = $(subst .c,.o,$(PRINT_SRC))
LOBJ = $(subst .c,.o,$(LIB_SRC))
LSRC = $(addprefix base/, $(LIB_SRC))
PSRC = $(addprefix ft_printf/, $(PRINT_SRC))
CFLAGS = -Wall -Werror -Wextra -g

$(NAME): 
	@gcc -c $(CFLAGS) $(LSRC) $(PSRC) -Iincludes 
	@ar rcs $(NAME) $(LOBJ) $(POBJ)
	@echo "Libft OK"

all: $(NAME)

.PHONY: clean fclean

clean:
	@rm -f $(POBJ) $(LOBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
