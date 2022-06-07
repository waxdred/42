FROM debian:buster-slim

RUN apt-get update && \
	apt-get upgrade -y

RUN apt-get install -y php-fpm php-mysql && apt install curl -y && apt install tar -y
RUN apt install mariadb-client -y

ENV BUILDDIR=/tmp/build/
RUN mkdir ${BUILDDIR}
RUN mkdir -p /var/www

COPY srcs/* ${BUILDDIR}.

RUN mkdir -p /run/php

RUN cd ${BUILDDIR} && curl -O https://wordpress.org/latest.tar.gz && cd

RUN tar xzvf ${BUILDDIR}*tar.gz 

RUN chmod -R 777 ${BUILDDIR}

RUN mv wordpress /var/www/wordpress 

RUN chmod 777 /var/www/wordpress

RUN sed 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:9000/' -i /etc/php/7.3/fpm/pool.d/www.conf

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

RUN chmod 777 wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp-cli

EXPOSE 9000
WORKDIR /var/www/wordpress
CMD wp-cli config create --allow-root --path="/var/www/wordpress" --dbhost="mariadb" --dbname="jmilhas" --dbuser="jmilhas" --dbpass="jmilhas"

CMD sh ${BUILDDIR}run_cli.sh

