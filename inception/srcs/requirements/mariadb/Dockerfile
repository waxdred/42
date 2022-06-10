# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 22:07:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/11 00:12:29 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim 

# install mariadb
RUN apt update && \
    apt install mariadb-client -y && \
    apt install mariadb-server -y && \
    apt install procps -y

RUN rm /etc/mysql/mariadb.conf.d/50-server.cnf 
# copy entrypoint and config of mysql
COPY ./config/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./scripts/entrypoint.sh ./

EXPOSE 3306

ENTRYPOINT [ "bash", "./entrypoint.sh" ]
