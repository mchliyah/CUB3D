# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 20:42:29 by mchliyah          #+#    #+#              #
#    Updated: 2022/12/31 20:20:39 by hsaidi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3
CC = gcc
FLAGS =  -Wall -Werror -Wextra -c 

RM = rm -f

FILES = main.c\
 		parcing/parce.c\
		parcing/file_handling.c\
		parcing/map_utils.c\
		parcing/map_utils2.c\
		parcing/reading_file.c\
		parcing/top_file.c\
		parcing/libft.c\
		parcing/more_utils.c\
		parcing/texters_path.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		raycast/init.c\
		raycast/player.c\
		raycast/utils.c\
		raycast/keyhook.c\
		raycast/render.c\
		raycast/colision.c\
		raycast/events.c\
		raycast/mlx.c\
		raycast/raycast.c\
		raycast/get_intersect.c\
		

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