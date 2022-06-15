# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 16:51:31 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/15 18:31:17 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
FROM	alpine:3.13

RUN		apk upgrade
RUN		apk add --no-cache --quiet --update curl
RUN		apk add --no-cache --quiet --update php7 \
	php7-session php7-fpm php7-mysqli

COPY	./script/entrypoint.sh /usr/bin/local/entrypoint.sh
RUN		chmod +x /usr/bin/local/entrypoint.sh

WORKDIR /var/www/wordpress
ENTRYPOINT [ "sh", "/usr/bin/local/entrypoint.sh" ]
