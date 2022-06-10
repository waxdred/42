# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 22:07:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/11 00:30:58 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim 

# add arg pass from docker-compose args:
ARG ARG_URL
ARG ARG_STUD

# install nginx and openssl
RUN apt update && apt install nginx -y && apt install openssl -y

# create dir for nginx
RUN mkdir -p /etc/nginx/ssl && mkdir -p /var/run/nginx

RUN rm /etc/nginx/sites-available/default
RUN rm /etc/nginx/sites-enabled/default

# generator de cartificat 
RUN openssl req -x509 -nodes \
		-out /etc/nginx/ssl/${ARG_URL}.crt \
		-keyout /etc/nginx/ssl/${ARG_URL}.key \
		-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=${ARG_URL}/UID=${ARG_STUD}"

# add config nginx
COPY	./config/nginx.conf /etc/nginx/sites-available/default
RUN ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/default

# create symbolic link for catch log of nginx in file
RUN		ln -sf /dev/stdout /var/log/nginx/access.log \
			&& ln -sf /dev/stderr /var/log/nginx/error.log
RUN chmod 777 /etc/nginx/ssl/*
RUN chmod 777 -R /var/www 
RUN chown -R www-data:www-data /var/www/
EXPOSE	443
CMD	[ "nginx", "-g", "daemon off;" ]
