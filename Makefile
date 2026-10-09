# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 11:27:45 by nmeunier          #+#    #+#              #
#    Updated: 2026/10/09 16:58:56 by nmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

GNL = src/gnl/get_next_line.c

LIBFT = src/libft/ft_lstadd_back.c src/libft/ft_lstadd_front.c src/libft/ft_lstdelone.c \
		src/libft/ft_strdup.c src/libft/ft_strchr.c src/libft/ft_split.c \
		src/libft/ft_strlen.c src/libft/ft_itoa.c src/libft/ft_bzero.c src/libft/ft_atoi.c \
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
		src/libft/ft_calloc.c src/libft/ft_memcmp.c src/libft/ft_memcpy.c

SRCS = $(GNL) $(LIBFT) src/main.c src/parser/read_lines.c \
					   src/parser/create_map.c src/free/free.c src/parser/parse_map.c \
					   src/parser/create_map_utils.c src/parser/handle_map.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INC_DIR = includes
MLX_DIR = src/mlx
X11_LIB = -lXext -lX11 -lm -lz
MLXLIB = -L$(MLX_DIR) -lmlx
OBJS = $(SRCS:.c=.o)
TOTAL := $(words $(SRCS))
CNT := 0
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RED = \033[0;31m
BOLD = \033[1m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) --no-print-directory -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(MLXLIB) $(X11_LIB) -o $(NAME)
	@printf "\n$(GREEN)$(BOLD)> $(NAME) compiled successfully.$(RESET)\n"

%.o: %.c
	@$(eval CNT := $(shell expr $(CNT) + 1))
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -O3 -c $< -o $@
	@printf "\r\033[K$(CYAN)[%3d%%]$(RESET) Compiling $(YELLOW)%s$(RESET)" \
		$$(( $(CNT) * 100 / $(TOTAL) )) "$<"

clean:
	@$(MAKE) --no-print-directory -C $(MLX_DIR) clean
	@$(RM) $(OBJS)
	@printf "$(YELLOW)> Object files cleaned.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)> $(NAME) removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
