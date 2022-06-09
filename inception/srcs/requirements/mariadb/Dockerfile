# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 22:07:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/09 10:53:43 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim 

# create arg
ARG datadir="/var/lib/mysql"
ARG runsql="/run/mysqld"

# install mariadb
RUN apt update && \
    apt upgrade -y && \
    apt install mariadb-client -y && \
    apt install mariadb-server -y && \
    apt install procps -y

# create dir for nginx
RUN mkdir -p ${datadir}} ${runsql}
RUN chmod -R 777 ${datadir}

# copy entrypoint and config of mysql
COPY ./config/create_db.sql /tmp/create_db.sql
COPY ./scripts/entrypoint.sh ./
COPY ./config/mariadb.conf /etc/my.cnf.d/mariadb.cnf

# install mariadb

RUN mysql_install_db --datadir=${datadir} --auth-root-authentication-method=normal

# change rights
RUN chown -R mysql:mysql ${datadir} ${runsql}

EXPOSE 3306

ENTRYPOINT [ "bash", "./entrypoint.sh" ]
