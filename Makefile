# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 17:16:52 by juhanse           #+#    #+#              #
#    Updated: 2024/12/20 15:13:13 by juhanse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra

PATH_SRCS = src/

SRCS = main.c ft_utils.c
HEADERS = so_long.h

SRCS_OBJS = $(addprefix $(PATH_SRCS), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	$(CC) $(SRCS_OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(PATH_SRCS)%.o: $(PATH_SRCS)%.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(SRCS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
