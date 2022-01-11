# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 22:49:51 by jmilhas           #+#    #+#              #
#    Updated: 2021/12/15 17:54:56 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	 fdf.a

EXEC = 	 fdf

CC = 	 gcc

SRC =    srcs/ft_fdf.c			\
	 srcs/ft_bresenham.c		\
	 srcs/ft_calcul.c		\
	 srcs/ft_colors.c		\
	 srcs/ft_create_map.c		\
	 srcs/ft_create_map_utils.c	\
	 srcs/ft_draw.c 		\
	 srcs/ft_event.c		\
	 srcs/ft_event_utils.c		\
	 srcs/ft_free.c			\
	 srcs/ft_init.c			\
	 srcs/ft_mlx.c			\
	 srcs/ft_new_tab_two.c		\
	 srcs/ft_put_string_mlx.c	\
	 srcs/main.c

OBJS = $(SRC:.c=.o)

HEADER = includes/fdf.h\
	 includes/fdf_define.h\
	 includes/fdf_struct.h

SAN = -fsanitize=address

FLAGS = -Wall -Werror -Wextra -ggdb -O3 

MLX = -Lminilibx -lmlx -framework OpenGL -framework AppKit

LIB= -lGnl -llibft

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -I ./includes -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@make -C Gnl
	@make -C minilibx
	@echo "\033[34mCreation of $(NAME) ..."
	@ar rc $(NAME) $(OBJS)
	@$(CC) $(MLX) $(NAME) Gnl/gnl.a libft/libft.a -o $(EXEC)

clean:
	@echo "\033[33mRemoval of .o files of $(NAME) ..."
	@make clean -C libft
	@make clean -C Gnl
	@/bin/rm -f srcs/*.o

fclean: clean
	@echo "\033[33mRemoval of $(NAME)..."
	@make fclean -C libft
	@make fclean -C Gnl
	@/bin/rm -f srcs/*.o
	@/bin/rm -f $(EXEC)
norme:
	@echo "\033[33mNorme ..."
	@norminette $(SRC)
	@norminette $(HEADER)

re: fclean all
