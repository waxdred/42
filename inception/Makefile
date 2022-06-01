# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 20:43:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/01 10:09:22 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	docker compose -v -f ./srcs/docker-compose.yml up 

clean:
	docker compose -f ./srcs/docker-compose.yml down

fclean: clean
	docker volume rm workpress
	docker volume rm mariadb
	docker rmi workpress
	docker system prune -a --force

re: fclean all
