# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 17:16:52 by juhanse           #+#    #+#              #
#    Updated: 2025/02/11 16:37:56 by juhanse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra

PATH_SRCS = src/

UTILS = utils/ft_isalnum.c utils/ft_strlen.c utils/ft_strlcpy.c utils/ft_printf.c
GNL = gnl/get_next_line_utils.c gnl/get_next_line.c
SRCS = main.c map.c parsing.c map_checker.c game.c move.c $(UTILS) $(GNL)
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
