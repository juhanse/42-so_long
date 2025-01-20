# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 17:16:52 by juhanse           #+#    #+#              #
#    Updated: 2025/01/20 13:40:44 by juhanse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra

PATH_SRCS = src/

GNL = gnl/get_next_line_utils.c gnl/get_next_line.c
SRCS = main.c utils.c parsing.c map.c $(GNL)
HEADERS = so_long.h

SRCS_OBJS = $(addprefix $(PATH_SRCS), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	$(CC) $(SRCS_OBJS) -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -o $(NAME)

$(PATH_SRCS)%.o: $(PATH_SRCS)%.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(SRCS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
