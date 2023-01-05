# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 20:42:29 by mchliyah          #+#    #+#              #
#    Updated: 2023/01/05 15:28:59 by mchliyah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

minilib = minilibx/libmlx.a

NAME = cub3
NAME_bonus = cub3_bonus

CC = gcc
FLAGS =  -Wall -Werror -Wextra -c 

RM = rm -f

FILES = mandatory/main.c\
 		mandatory/parcing/parce.c\
		mandatory/parcing/file_handling.c\
		mandatory/parcing/map_utils.c\
		mandatory/parcing/map_utils2.c\
		mandatory/parcing/reading_file.c\
		mandatory/parcing/colors.c\
		mandatory/parcing/top_file.c\
		mandatory/parcing/libft_2.c\
		mandatory/parcing/libft.c\
		mandatory/parcing/more_utils.c\
		mandatory/parcing/textures_path.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		mandatory/raycast/init.c\
		mandatory/raycast/player.c\
		mandatory/raycast/utils.c\
		mandatory/raycast/keyhook.c\
		mandatory/raycast/render.c\
		mandatory/raycast/colision.c\
		mandatory/raycast/events.c\
		mandatory/raycast/mlx.c\
		mandatory/raycast/raycast.c\
		mandatory/raycast/get_intersect.c\
		
FILES_bonus = bonus/main.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			bonus/parcing_bonus/parce.c\
			bonus/parcing_bonus/file_handling.c\
			bonus/parcing_bonus/map_utils.c\
			bonus/parcing_bonus/map_utils2.c\
			bonus/parcing_bonus/reading_file.c\
			bonus/parcing_bonus/colors.c\
			bonus/parcing_bonus/top_file.c\
			bonus/parcing_bonus/libft_2.c\
			bonus/parcing_bonus/libft.c\
			bonus/parcing_bonus/more_utils.c\
			bonus/parcing_bonus/textures_path.c\
			bonus/raycast_bonus/init.c\
			bonus/raycast_bonus/player.c\
			bonus/raycast_bonus/utils.c\
			bonus/raycast_bonus/keyhook.c\
			bonus/raycast_bonus/render.c\
			bonus/raycast_bonus/colision.c\
			bonus/raycast_bonus/events.c\
			bonus/raycast_bonus/mlx.c\
			bonus/raycast_bonus/raycast.c\
			bonus/raycast_bonus/get_intersect.c\

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