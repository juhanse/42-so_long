# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 17:16:52 by juhanse           #+#    #+#              #
#    Updated: 2024/11/26 12:43:11 by juhanse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra

PATH_LIB = lib/
PATH_SRCS = srcs/

LIB = ft_strlen.c ft_putstr.c ft_putchar.c ft_putnbr_base.c
SRCS = ft_convert.c ft_print_memory.c
HEADERS = ft_printf.h
MAIN_FILE = ft_printf.c

LIB_OBJS = $(addprefix $(PATH_LIB), $(LIB:.c=.o))
SRCS_OBJS = $(addprefix $(PATH_SRCS), $(SRCS:.c=.o))
MAIN_OBJECT = $(MAIN_FILE:.c=.o)
OBJS = $(LIB_OBJS) $(SRCS_OBJS) $(MAIN_OBJECT)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	ar -rsc $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
