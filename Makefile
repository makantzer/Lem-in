# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 15:03:23 by mkantzer          #+#    #+#              #
#    Updated: 2017/06/26 14:59:50 by mkantzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SRC = parse.c\
	  main.c\
	  list.c
CFLAGS = -Wall -Werror -Wextra
$(NAME): $(SRC)
	@make -C libft/
	gcc $(CFLAGS) $(SRC) -o $(NAME) libft/libft.a
	@echo "OK"
all: $(NAME)
clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "OBJ deleted"
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "ALL Wiped"
re: fclean all
