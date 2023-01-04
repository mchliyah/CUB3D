# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 20:42:29 by mchliyah          #+#    #+#              #
#    Updated: 2023/01/04 21:26:20 by hsaidi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

minilib = minilibx/libmlx.a

NAME = cub3
NAME_bonus = cub3_bonus

CC = gcc
FLAGS =  -Wall -Werror -Wextra -c 

RM = rm -f

FILES = main.c\
 		parcing/parce.c\
		parcing/file_handling.c\
		parcing/map_utils.c\
		parcing/map_utils2.c\
		parcing/reading_file.c\
		parcing/colors.c\
		parcing/top_file.c\
		parcing/libft_2.c\
		parcing/libft.c\
		parcing/more_utils.c\
		parcing/textures_path.c\
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
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			parcing_bonus/parce.c\
			parcing_bonus/file_handling.c\
			parcing_bonus/map_utils.c\
			parcing_bonus/map_utils2.c\
			parcing_bonus/reading_file.c\
			parcing_bonus/colors.c\
			parcing_bonus/top_file.c\
			parcing_bonus/libft_2.c\
			parcing_bonus/libft.c\
			parcing_bonus/more_utils.c\
			parcing_bonus/textures_path.c\
			raycast_bonus/init.c\
			raycast_bonus/player.c\
			raycast_bonus/utils.c\
			raycast_bonus/keyhook.c\
			raycast_bonus/render.c\
			raycast_bonus/colision.c\
			raycast_bonus/events.c\
			raycast_bonus/mlx.c\
			raycast_bonus/raycast.c\
			raycast_bonus/get_intersect.c\

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

$(NAME) :  $(OBJECTS) $(minilib)
	@$(CC) $(OBJECTS) $(minilib) -lmlx -framework OpenGL -framework AppKit -o $(NAME) #-fsanitize=address -g
	@echo "$(C_GREEN)[CUB3D MANDATORY CREATED!]$(C_RES)"

$(minilib) :
	@make -s -C minilibx

bonus : $(NAME_bonus)

$(NAME_bonus) :  $(OBJECTS_bonus) $(minilib)
	@$(CC) $(OBJECTS_bonus) $(minilib) -lmlx -framework OpenGL -framework AppKit -o $(NAME_bonus) #-fsanitize=address -g
	@echo "$(C_GREEN)[CUB3D BONUS CREATED!]$(C_RES)"

clean : 
	@$(RM) $(OBJECTS)
	@$(RM) $(OBJECTS_bonus)
	@make -s clean -C minilibx
	@echo "$(C_RED)[CUB3D OBJECTS DELETED!]$(C_RES)"

fclean : clean
	@$(RM) $(NAME)	@$(RM) $(NAME_bonus) $(minilib)
	@echo "$(C_RED)[CUB3D && EXECUTABLES DELETED!]$(C_RES)"

re : fclean all