# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 23:27:08 by jmilhas           #+#    #+#              #
#    Updated: 2021/11/19 23:35:04 by jmilhas          ###   ########.fr        #
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
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	/bin/rm -f $(OBJS) 

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all 

