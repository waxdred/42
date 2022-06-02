FROM debian:buster-slim

RUN apt-get update && apt-get upgrade -y && apt-get install wget

RUN apt-get install -y php-fpm php-mysql
RUN wget -c https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz
RUN mv wordpress/ /var/www/html/
RUN chown -R www-data:www-data /var/www/html/wordpress/
RUN chmod 755 -R /var/www/html/wordpress/
COPY ./srcs/index.php /var/www/html/
