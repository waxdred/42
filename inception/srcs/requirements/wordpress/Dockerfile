# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 22:07:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/09 13:02:06 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim 
	
ENV BUILDDIR=/tmp/build/

# install php mariadb-client and tool
RUN apt update && apt upgrade -y && \
		  apt install php-fpm php-mysql -y && \
		  apt install curl -y && \
		  apt install tar -y && \
		  apt install mariadb-client -y

RUN mkdir -p /var/www/wordpress /usr/local/bin/wp  

# https://wp-cli.org/ for install workpress by cli
RUN		curl https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
			--output /usr/bin/wp --silent

RUN		chmod +x ./usr/bin/wp

# download wordpress by wp
RUN		wp core download --allow-root --path=/var/www/wordpress
WORKDIR /var/www/wordpress

COPY	config/wp-config /config/wp-config
COPY	./script/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN		chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT [ "sh", "/usr/local/bin/entrypoint.sh" ]
