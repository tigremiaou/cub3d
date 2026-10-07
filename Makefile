# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 11:27:45 by nmeunier          #+#    #+#              #
#    Updated: 2026/10/07 14:03:34 by nmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL = src/gnl/get_next_line.c

LIBFT = src/libft/ft_lstadd_back.c src/libft/ft_lstadd_front.c src/libft/ft_lstdelone.c \
		src/libft/ft_strdup.c src/libft/ft_strchr.c src/libft/ft_split.c \
		src/libft/ft_strlen.c src/libft/ft_itoa.c src/libft/ft_bzero.c src/libft/ft_atoi.c\
		src/libft/ft_putnbr_fd.c src/libft/ft_putchar_fd.c src/libft/ft_putendl_fd.c \
		src/libft/ft_putstr_fd.c src/libft/ft_strrchr.c src/libft/ft_toupper.c \
		src/libft/ft_strmapi.c src/libft/ft_striteri.c src/libft/ft_strnstr.c \
		src/libft/ft_lstclear.c src/libft/ft_lstiter.c src/libft/ft_lstmap.c \
		src/libft/ft_strlcat.c src/libft/ft_strncmp.c src/libft/ft_strlcpy.c \
		src/libft/ft_isalnum.c src/libft/ft_isprint.c src/libft/ft_isdigit.c \
		src/libft/ft_strjoin.c src/libft/ft_strtrim.c src/libft/ft_tolower.c \
		src/libft/ft_lstnew.c src/libft/ft_lstsize.c src/libft/ft_lstlast.c \
		src/libft/ft_isalpha.c src/libft/ft_isascii.c src/libft/ft_memchr.c \
		src/libft/ft_memmove.c src/libft/ft_memset.c src/libft/ft_substr.c \
		src/libft/ft_calloc.c src/libft/ft_memcmp.c src/libft/ft_memcpy.c\

SRCS = $(GNL) $(LIBFT) src/main.c

INC_DIR = includes
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR)
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