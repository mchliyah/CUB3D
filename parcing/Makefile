# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 20:42:29 by mchliyah          #+#    #+#              #
#    Updated: 2022/12/15 11:35:52 by hsaidi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub

SRCS = main.c\

GNL = ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c

FLAGS2 = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): ${OBJS}
	gcc $(FLAGS) ${OBJS} $(GNL) ${FLAGS2} -o $(NAME)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re