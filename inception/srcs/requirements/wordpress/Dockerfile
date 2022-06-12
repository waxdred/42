# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 22:07:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/11 16:24:27 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim 
	
ENV BUILDDIR=/tmp/build/

# install php mariadb-client and tool
RUN apt update
RUN apt install -y php7.3-fpm \
	openssl \
	php7.3-mysql \
	mariadb-client \
	redis\
	redis-server\
	wget \
    	curl

RUN	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN	chmod +x wp-cli.phar
RUN	mv wp-cli.phar /usr/local/bin/wp 
RUN echo "listen = 9000" >> /etc/php/7.3/fpm/pool.d/www.conf
RUN echo "access.log = /var/log/$pool.access.log" >> /etc/php/7.3/fpm/pool.d/www.conf
RUN 	mkdir -p /var/www/wordpress 
RUN 	chown -R  www-data:www-data /var/www/wordpress/
RUN 	chmod 777 /var/www/wordpress/
RUN 	mkdir -p /run/php/

COPY 	./script/entrypoint.sh /
RUN chmod 777 /entrypoint.sh
WORKDIR /var/www/wordpress
EXPOSE 9000

ENTRYPOINT [ "sh", "/entrypoint.sh" ]
