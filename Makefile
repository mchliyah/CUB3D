# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 20:42:29 by mchliyah          #+#    #+#              #
#    Updated: 2023/01/01 14:52:52 by mchliyah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3
NAME_bonus = cub3_bonus

CC = gcc
FLAGS =  -Wall -Werror -Wextra -c 

RM = rm -f

FILES = main.c\
 		parcing/parce.c\
		parcing/file_handling.c\
		parcing/map_utils.c\
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
		
FILES_bonus = main.c\
			bonus/parcing/parce.c\
			bonus/parcing/file_handling.c\
			bonus/parcing/map_utils.c\
			bonus/parcing/reading_file.c\
			bonus/parcing/top_file.c\
			bonus/parcing/libft.c\
			bonus/parcing/more_utils.c\
			bonus/parcing/texters_path.c\
			bonus/get_next_line/get_next_line.c\
			bonus/get_next_line/get_next_line_utils.c\
			bonus/raycast/init.c\
			bonus/raycast/player.c\
			bonus/raycast/utils.c\
			bonus/raycast/keyhook.c\
			bonus/raycast/render.c\
			bonus/raycast/colision.c\
			bonus/raycast/events.c\
			bonus/raycast/mlx.c\
			bonus/raycast/raycast.c\
			bonus/raycast/get_intersect.c\

OBJECTS = $(FILES:.c=.o)
OBJECTS_bonus = $(FILES_bonus:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $^ -o $@

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

.PHONY : all clean fclean rebonus

all : $(NAME)

$(NAME) :  $(OBJECTS)
	@$(CC) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o3 -o $(NAME) #-fsanitize=address -g
	@echo "$(C_GREEN)[CUB3D MANDATORY CREATED!]$(C_RES)"

bonus : $(NAME_bonus)

$(NAME_bonus) :  $(OBJECTS_bonus)
	@$(CC) $(OBJECTS_bonus) -lmlx -framework OpenGL -framework AppKit -o3 -o $(NAME_bonus) #-fsanitize=address -g
	@echo "$(C_GREEN)[CUB3D BONUS CREATED!]$(C_RES)"

clean : 
	@$(RM) $(OBJECTS)
	@$(RM) $(OBJECTS_bonus)
	@echo "$(C_RED)[CUB3D OBJECTS DELETED!]$(C_RES)"

fclean : clean
	@$(RM) $(NAME)	@$(RM) $(NAME_bonus)
	@echo "$(C_RED)[CUB3D && EXECUTABLES DELETED!]$(C_RES)"

re : fclean all