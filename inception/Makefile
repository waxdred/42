# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 20:43:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/11 01:11:31 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = inception

all:	$(NAME)

$(NAME):
	docker compose -v -f ./srcs/docker-compose.yml up --force-recreate --build 

clean:
	docker compose -f ./srcs/docker-compose.yml down

fclean: clean
	docker rmi nginx
	docker rmi mariadb
	# docker rmi workpress
	docker system prune -a --force

fdockervolume: fclean
	docker volume rm srcs_mariadb-volumes
	docker volume rm srcs_wordpress-volumes

fvolume: 
	sudo rm -rf /home/jmilhas/data/wordpress/*
	sudo rm -rf /home/jmilhas/data/database/*

full: fclean fvolume

re: fclean all
