# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 22:49:51 by jmilhas           #+#    #+#              #
#    Updated: 2021/12/28 23:18:18 by jmilhas          ###   ########.fr        #
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
NAME 		= 	 philo.a
EXEC 		= 	 philo
CC 		= 	 gcc

PATH_SRC	=	./srcs/
PATH_OBJ	=	./objs/

SRC 		=   	main.c		\
			ft_routine.c	\
			thread.c	\
			ft_print.c	\
			utils.c

OBJ_SRC		=	$(SRC:.c=.o)

SRC_O		=	$(addprefix $(PATH_SRC), $(SRC))
OBJ_S		=	$(addprefix $(PATH_OBJ), $(OBJ_SRC))

HEADER 		= 	includes/philo.h
MK		= 	Makefile
SAN 		= 	-g3 -fsanitize=address
FLAGS 		= 	-Wall -Werror -Wextra -g3 

$(PATH_OBJ)%.o : $(PATH_SRC)%.c $(HEADER) $(MK)
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	@-$(CC) -I ./includes -o $@ -c $<
	@printf "\r\t\033[K$(CCYAN)\t$< $(CCPURPLE)--> $(CCYAN)$@ $(CCEND)"
	@sleep 0.1

all: $(NAME)

$(NAME): $(OBJ_S)
	@printf "\r\t\033[K$(CCYAN)[✅]\t$(EXEC) $(CCPURPLE)--> $(CCYAN) Gen Objs$(CCEND)"
	@printf "\n$(CCYAN)[✅]\t$(CCPURPLE)Creation of Objs $(EXEC)...$(CCEND)\n"
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(PATH_OBJ)$(NAME) $(OBJ_S)
	@$(CC) $(PATH_OBJ)$(NAME) -o $(EXEC)
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Compilation ./$(EXEC)...$(CCEND)\n"

clean:
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(EXEC) Object...$(CCEND)\n"
	@-/bin/rm -rf $(PATH_OBJ)*.o

fclean: clean
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	@-/bin/rm -f $(PATH_OBJ)*.a
	@-/bin/rm -rf $(PATH_OBJ)
	@-/bin/rm -f Tags
	@-/bin/rm -f $(EXEC)
norme:
	@echo "\033[33mNorme ..."
	@norminette $(SRC)
	@norminette $(HEADER)

start:
	@sleep 0.5
	@clear
	@printf "\n\n\n$(CCYAN)"
	@printf "\t\t$(EXEC)"
	@printf "\n\n\n"
	@printf "Execution make:\n$(CCEND)"

git:	fclean
	@git add .
	@git commit -m "$(filter-out $@,$(MAKECMDGOALS))"
	@git push

auto:	fclean
	@git add .
	@git commit -m "Autosave"
	@git push


.PHONY: all clean fclean re san
.SILENT :
re: fclean all
