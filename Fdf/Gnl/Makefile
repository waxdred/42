# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 23:27:08 by jmilhas           #+#    #+#              #
#    Updated: 2021/12/06 19:54:34 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	 gnl.a

CC = 	 gcc

SRC =    srcs/get_next_line.c\
	 srcs/get_next_line_utils.c

OBJS = $(SRC:.c=.o)

HEADER = includes/get_next_line.h

FLAGS = -Wall -Werror -Wextra

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -I ./includes -c $< -o $@

$(NAME): $(OBJS)
	@echo "\033[34mCreation of $(NAME) ..."
	@ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	@echo "\033[33mRemoval of .o files of $(NAME) ..."
	@-/bin/rm -f $(OBJS) 

fclean: clean
	@echo "\033[33mRemoval of $(NAME) ..."
	@-/bin/rm -f $(NAME)

re: fclean all 

