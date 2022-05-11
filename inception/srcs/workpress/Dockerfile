FROM debian:buster

RUN apt-get update
RUN apt-get -y install php7.3 php-mysqli php-fpm mariadb-client wget

ADD https://wordpress.org/wordpress-5.9.3.tar.gz /var/www/
RUN cd /var/www && tar -xzvf wordpress-5.9.3.tar.gz
RUN rm -f /var/www/wordpress-5.9.3.tar.gz && rm -f /var/www/wordpress/wp-config-sample.php

COPY ./www.conf /etc/php/7.3/fpm/pool.d
COPY ./wp-config.php /var/www/html/wordpress/wp-config.php

RUN mkdir ./run/php/
CMD ./usr/sbin/php-fpm7.3 -F
