# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 22:49:51 by jmilhas           #+#    #+#              #
#    Updated: 2021/12/06 20:41:57 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	 push_swap.a

EXEC = 	 push_swap

CC = 	 gcc

SRC =    srcs/ft_clear_stack.c			\
	 srcs/ft_push.c				\
	 srcs/utils.c				\
	 srcs/check_error.c			\
	 srcs/main.c

OBJS = $(SRC:.c=.o)

HEADER = includes/push_swap.h

SAN = -fsanitize=address

FLAGS = -Wall -Werror -Wextra -ggdb 

LIB= -llibft

DEPEND= libft/libft.a

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -I ./includes -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@echo "\033[34mCreation of $(NAME) ..."
	@ar rc $(NAME) $(OBJS)
	@$(CC) $(NAME) $(DEPEND) -o $(EXEC)

clean:
	@echo "\033[33mRemoval of .o files of $(NAME) ..."
	@make clean -C libft
	@/bin/rm -f $(OBJS)

fclean: clean
	@echo "\033[33mRemoval of $(NAME)..."
	@make fclean -C libft
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(EXEC)
norme:
	@echo "\033[33mNorme ..."
	@norminette $(SRC)
	@norminette $(HEADER)

re: fclean all
