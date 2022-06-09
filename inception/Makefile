# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 20:43:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/09 13:35:22 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = inception

all:	$(NAME)

$(NAME):
	docker compose -v -f ./srcs/docker-compose.yml up --force-recreate --build 

clean:
	docker compose -f ./srcs/docker-compose.yml down

fclean: clean
	sudo rm -rf /home/jmilhas/data/wordpress/*
	sudo rm -rf /home/jmilhas/data/mariaDB/*
	docker rmi nginx
	docker rmi mariadb
	# docker rmi workpress
	docker system prune -a --force

re: fclean all
