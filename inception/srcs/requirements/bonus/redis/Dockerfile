# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 22:07:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/11 17:07:41 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim 

RUN apt update && apt install -y redis-server \
	php-redis
		  

COPY ./script/entrypoint.sh /
COPY ./config/redis.conf /

EXPOSE 6379
CMD [ "bash", "/entrypoint.sh" ]
