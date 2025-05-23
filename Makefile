# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 17:16:52 by juhanse           #+#    #+#              #
#    Updated: 2025/05/16 01:48:09 by juhanse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

OBJDIR = objs/
GNL = gnl/get_next_line_utils.c gnl/get_next_line.c
UTILS = utils/ft_isalnum.c utils/ft_strlen.c utils/ft_strlcpy.c utils/ft_printf.c utils/ft_line_len.c
SRC = main.c map.c parsing.c map_checker.c game.c move.c
FILES = $(addprefix src/, $(SRC:.c=.o) $(UTILS:.c=.o) $(LIB:.c=.o))
OBJS = $(addprefix $(OBJDIR), $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -o $(NAME)
	@echo "$(COLOUR_GREEN)Compiled ✅$(COLOUR_END)"

$(OBJDIR)%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJDIR)
	@echo "$(COLOUR_RED)Cleaned 🧹$(COLOUR_END)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(COLOUR_RED)Cleaned all 🧹$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
