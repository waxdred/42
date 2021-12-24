# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 22:16:10 by rcuminal          #+#    #+#              #
#    Updated: 2021/12/22 21:32:33 by rcuminal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBS_PERSO = libft/libft.a \

SRCS =  push_swap.c       \
		utils.c \
		operations.c \
		check.c \
		castrois.c \
		index.c

OBJS = ${SRCS:.c=.o}

VERIF = -g3 -fsanitize=address

CC = gcc

RM = rm -f

%.o : %.c push_swap.h
	${CC} -I includes -c $< -o $@

$(NAME): ${OBJS}
	make bonus -C libft
	${CC}    $(LIBS_PERSO) $(OBJS) -o $(NAME)
	
all: ${NAME}

clean:
	${RM} ${OBJS} ${OBJSB}
	make -C libft fclean

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re