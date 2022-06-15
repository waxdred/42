# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 20:43:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/15 16:54:43 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = inception

all:	$(NAME)

$(NAME):
	mkdir -p /home/jmilhas/data/database 2>/dev/null
	mkdir -p /home/jmilhas/data/wordpress 2>/dev/null
	mkdir -p /home/jmilhas/data/redis 2>/dev/null
	mkdir -p /home/jmilhas/data/adminer 2>/dev/null
	sed -i 's/ATTACK=1/ATTACK=0/g' ./srcs/.env
	docker compose -v -f ./srcs/docker-compose.yml up --force-recreate --build 

clean:
	docker compose -f ./srcs/docker-compose.yml down

fclean: clean
	@-docker rmi nginx
	@-docker rmi mariadb
	@-docker system prune -a --force

fdockervolume: fclean
	@-docker volume rm srcs_mariadb-volumes
	@-docker volume rm srcs_wordpress-volumes

fvolume: 
	@-sudo rm -rf /home/jmilhas/data

attack:
	sed -i 's/ATTACK=0/ATTACK=1/g' ./srcs/.env
	cat ./srcs/.env
	docker compose -v -f ./srcs/docker-compose.yml up --force-recreate --build 
	

full: fclean fvolume

re: full all
