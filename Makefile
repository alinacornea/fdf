# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcornea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/22 18:10:46 by alcornea          #+#    #+#              #
#    Updated: 2017/03/23 18:10:49 by alcornea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX = -L minilibx -lmlx -framework OpenGL -framework AppKit
LFT = -L libft -lft
SRC = read_main.c \
	  set_var.c \
	  display.c \
	  hook.c \
	  extra_functions.c \
	  get_next_line.c
OBJ = $(SRC:%.c=%.o)
INCL = fdf.h
all: $(NAME)

$(NAME):
	@echo "\033[1;33mFDF: Sources compiling... \033[0m"
	@make -C libft/
	@$(CC) $(FLAGS) -I $(INCL) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LFT) $(MLX)
	@echo "\033[1;34mFDF: Compiled with success..!\033[0m"

clean:
	@make -C libft/ clean
	@/bin/rm -rf $(OBJ)
	@echo "\033[0;36mObjects removed...\033[0m"

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[0;36mFDF binary removed...\033[0m"

re: fclean all
