# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 20:42:29 by mchliyah          #+#    #+#              #
#    Updated: 2022/12/28 07:15:05 by mchliyah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3
CC = gcc
FLAGS =  -Wall -Werror -Wextra -c 

RM = rm -f

FILES = main.c\
		init.c\
		player.c\
		utils.c\
		keyhook.c\
		render.c\
		colision.c\
		events.c\
		mlx.c\
		raycast.c\
		get_intersect.c\
		

OBJECTS = $(FILES:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $^ -o $@

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

.PHONY : all clean fclean rebonus

all : $(NAME)

$(NAME) :  $(OBJECTS)
	@$(CC) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) -fsanitize=address -g
	@echo "$(C_GREEN)[CUB3D MANDATORY CREATED!]$(C_RES)"

clean : 
	@$(RM) $(OBJECTS)
	@echo "$(C_RED)[CUB3D OBJECTS DELETED!]$(C_RES)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(C_RED)[CUB3D && EXECUTABLES DELETED!]$(C_RES)"

re : fclean all