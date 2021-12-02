# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 22:49:51 by jmilhas           #+#    #+#              #
#    Updated: 2021/12/02 01:10:33 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	 fdf.a

CC = 	 gcc

SRC =    srcs/ft_fdf.c	\
	 srcs/ft_create_map.c	\
	 srcs/ft_init.c	\
	 srcs/ft_event.c	\
	 srcs/ft_event_utils.c	\
	 srcs/ft_draw.c \
	 srcs/ft_free.c	\
	 srcs/ft_mlx.c	\
	 srcs/ft_bresenham.c	\
	 srcs/ft_put_string_mlx.c	\
	 srcs/ft_new_tab_two.c	\
	 srcs/main.c

OBJS = $(SRC:.c=.o)

HEADER = includes/fdf.h\
	 includes/define.h\
	 includes/fdf_struct.h



FLAGS = -Wall -Werror -Wextra -ggdb

MLX = -Lminilibx -lmlx -framework OpenGL -framework AppKit

LIB= -lGnl -llibft

%.o : %.c $(HEADER)
	$(CC) -I ./includes -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@make -C Gnl
	@make -C minilibx
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@ar rc $(NAME) $(OBJS)
	@$(CC) $(MLX) $(NAME) Gnl/gnl.a libft/libft.a && ./a.out


all: $(NAME)

clean:	
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@make clean -C libft
	@make clean -C Gnl
	@/bin/rm -f $(OBJS) 

fclean: clean
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@make fclean -C libft
	@make fclean -C Gnl
	@/bin/rm -f $(NAME)
r:
	@rm ./a.out

re: fclean all 

