# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchliyah <mchliyah@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 20:42:29 by mchliyah          #+#    #+#              #
#    Updated: 2022/12/14 23:23:33 by mchliyah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3
CC = gcc
FLAGS =  -Wall -Werror -Wextra -c 

RM = rm -f

FILES = main.c\
		utils.c\
		keyhook.c\
		render.c\
		

OBJECTS = $(FILES:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $^ -o $@

# LIBFT = ./libft
# ARLIB = $(LIBFT)/libft.a
# ALLIBFT = make -C $(LIBFT)
# CLEANLIBFT = make clean -C $(LIBFT)
# FCLEANLIBFT = rm -f $(ARLIB)
# RELIBFT = make re -C $(LIBFT)

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