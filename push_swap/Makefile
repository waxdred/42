# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 22:49:51 by jmilhas           #+#    #+#              #
#    Updated: 2021/12/19 01:25:16 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCEND 		=   \033[0m
CCYAN 		=   \033[34m
CGREEN		=   \033[33m
CCRED 		=   \033[31m
CCPURPLE 	=   \033[35m

NAME = 	 push_swap.a

EXEC = 	 push_swap

CC = 	 gcc

SRC =    srcs/ft_clear_stack.c			\
	 srcs/ft_push.c				\
	 srcs/utils.c				\
	 srcs/push_swap.c                       \
	 srcs/swap/ft_sa.c			\
	 srcs/check_error.c			\
	 srcs/main.c

OBJS = $(SRC:.c=.o)

HEADER = includes/push_swap.h

MK	= Makefile

SAN = -fsanitize=address

FLAGS = -Wall -Werror -Wextra -ggdb 

LIB= -llibft

DEPEND= libft/libft.a

%.o : %.c $(HEADER) $(MK)
	@-$(CC) $(FLAGS) -I ./includes -c $< -o $@
	@printf "\r\t\033[K[✅]\t$(CCYAN)$< $(CCPURPLE)--> $(CCYAN)$@$(CCEND)"
	@sleep 0.1

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@printf "[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(NAME) $(OBJS)
	@$(CC) $(NAME) $(DEPEND) -o $(EXEC)

clean:
	@printf "[✅]\t$(CCRED)Removal of $(EXEC) Object...$(CCEND)\n"
	@make clean -C libft
	@-/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@printf "[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	@-/bin/rm -f $(NAME)
	@-/bin/rm -f $(EXEC)
norme:
	@echo "\033[33mNorme ..."
	@norminette $(SRC)
	@norminette $(HEADER)

re: fclean all
