# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/08 15:13:09 by alefebvr          #+#    #+#              #
#    Updated: 2018/04/17 13:57:02 by alefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

OBJ =  main.o fractal.o init.o error.o hook.o

SRC = $(OBJ:.o=.c)

LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror
FLAGMLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(SRC) fractol.h
	make -C libft
	make -C minilibx_macos
	gcc $(FLAGS) $(SRC) $(FLAGMLX) $(LIBFT) -o $(NAME)
	rm -rf $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
