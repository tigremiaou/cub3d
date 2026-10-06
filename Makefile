# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 11:27:45 by nmeunier          #+#    #+#              #
#    Updated: 2026/10/06 14:51:41 by nmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = 

SRCS = $(LIBFT) src/main.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
X11_LIB = -lXext -lX11 -lm -lz
MLXLIB = -Lmlx -lmlx

NAME = cub3d
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C mlx
	$(CC) $(CFLAGS) $(OBJS) $(MLXLIB) $(X11_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean