FROM debian:buster-slim

RUN apt-get update && \
	apt-get upgrade -y

RUN apt-get install -y php-fpm php-mysql && apt install curl -y && apt install tar -y

ENV BUILDDIR=/tmp/build/
RUN mkdir ${BUILDDIR}
RUN mkdir -p /var/www/workpress

COPY srcs/* ${BUILDDIR}.

RUN mkdir -p /run/php

RUN tar xzvf ${BUILDDIR}wordpress-6.0.tar.gz 

RUN chmod -R 777 ${BUILDDIR}

RUN sed 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:9000/' -i /etc/php/7.3/fpm/pool.d/www.conf

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

RUN chmod 777 wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp-cli

EXPOSE 9000

CMD cp -a ${BUILDDIR}. /var/www/ && ls ${BUILDDIR} && \
	wp-cli core install --allow-root \
			    --title="Wordpress" \
			    --path="/var/www/workpress" \
			    --admin_name="jmilhas" \
			    --admin_password="workpress" \
			    --admin_email="jmilhas@student42lyon.fr" \
			    --url="https://jmilhas.42.fr/" \
			    && php-fpm7.3 -F -R, "--nodeemonize"
