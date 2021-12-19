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

#Setting Color
CCEND 		=   	\033[0m
CCYAN 		=   	\033[34m
CGREEN		=   	\033[33m
CCRED 		=   	\033[31m
CCPURPLE 	=   	\033[35m

#Get arguments pass
ARGV		=	$(filter-out $@,$(MAKECMDGOALS))

NAME 		= 	 push_swap.a

EXEC 		= 	 push_swap

CC 		= 	 gcc

PATH_SRC	=	./srcs/

PATH_SWAP	=	./srcs/swap/

PATH_OBJ	=	./objs/

SRC 		=   	ft_clear_stack.c		\
			ft_push.c			\
			utils.c				\
			push_swap.c                     \
			check_error.c			\
			ft_sa.c				\
			main.c

OBJ_SRC		=	$(SRC:.c=.o)

SRC_O		=	$(addprefix $(PATH_SRC), $(SRC))
OBJ_S		=	$(addprefix $(PATH_OBJ), $(OBJ_SRC))

HEADER 		= 	includes/push_swap.h

MK		= 	Makefile

SAN 		= 	-g3 -fsanitize=address

FLAGS 		= 	-Wall -Werror -Wextra -ggdb 

LIB		= 	-llibft

DEPEND		= 	libft/libft.a

$(PATH_OBJ)%.o : $(PATH_SRC)%.c $(HEADER) $(MK)
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	@-$(CC) $(FLAGS) -I ./includes -o $@ -c $<
	@printf "\r\t\033[K$(CCYAN)[✅]\t$< $(CCPURPLE)--> $(CCYAN)$@ $(CCEND)"
	@sleep 0.1

.PHONY: all clean fclean re san
.SILENT :

all: $(NAME)

$(NAME): $(OBJ_S)
	@printf "\n[✅]\t$(CCPURPLE)Creation of Objs $(EXEC)...$(CCEND)\n"
	@make -C libft
	@printf "[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(NAME) $(OBJ_S)
	@$(CC) $(FLAGS) $(NAME) $(DEPEND) -o $(EXEC)
	@printf "[✅]\t$(CCPURPLE)Compilation ./$(EXEC)...$(CCEND)\n"

san: $(OBJ_S)
	@printf "\n[✅]\t$(CCPURPLE)Creation of Objs $(EXEC)...$(CCEND)\n"
	@make -C libft
	@printf "[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(NAME) $(OBJ_S)
	@$(CC) $(FLAGS) $(SAN) $(NAME) $(DEPEND) -o $(EXEC)
	@printf "[✅]\t$(CCPURPLE)Compilation with sanitize $(EXEC)...$(CCEND)\n"

clean:
	@printf "[✅]\t$(CCRED)Removal of $(EXEC) Object...$(CCEND)\n"
	@make clean -C libft
	@-/bin/rm -rf $(PATH_OBJ)

fclean: clean
	@make fclean -C libft
	@printf "[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	@-/bin/rm -f $(NAME)
	@-/bin/rm -f $(EXEC)
norme:
	@echo "\033[33mNorme ..."
	@norminette $(SRC)
	@norminette $(HEADER)

git:
	@git add .
	@git commit -m "$(filter-out $@,$(MAKECMDGOALS))"
	@git push

re: fclean all
