# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 22:07:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/17 22:58:03 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim 

# add arg pass from docker-compose args:
ARG ARG_URL
ARG ARG_STUD

# install nginx and openssl
RUN apt update && apt install nginx -y && apt install openssl -y
RUN rm /etc/nginx/sites-available/default
RUN rm /etc/nginx/sites-enabled/default
RUN mkdir -p /var/run/nginx
RUN mkdir -p /var/www/html/logo

COPY ./access/style.css /var/www/html
COPY ./access/index.html /var/www/html
COPY ./access/logo/* /var/www/html/logo
# add config nginx
COPY	./config/nginx.conf /etc/nginx/sites-available/default
RUN ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/default

# create symbolic link for catch log of nginx in file
RUN		ln -sf /dev/stdout /var/log/nginx/access.log \
			&& ln -sf /dev/stderr /var/log/nginx/error.log
RUN chmod 777 -R /var/www/html 
RUN chown -R www-data:www-data /var/www/html

CMD	[ "nginx", "-g", "daemon off;" ]
