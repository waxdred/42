# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 22:07:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/18 12:37:26 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim 

ARG PROXY_PASS

RUN apt update && apt install curl systemd -y 
RUN apt install -y debian-keyring debian-archive-keyring apt-transport-https
RUN curl -1sLf 'https://dl.cloudsmith.io/public/caddy/stable/gpg.key' \
	| gpg --dearmor -o /usr/share/keyrings/caddy-stable-archive-keyring.gpg
RUN curl -1sLf 'https://dl.cloudsmith.io/public/caddy/stable/debian.deb.txt' \
	| tee /etc/apt/sources.list.d/caddy-stable.list

RUN apt update
RUN apt install caddy

RUN rm -rf /etc/caddy/Caddyfile
COPY ./script/entrypoint.sh /

RUN echo ":80\nreverse_proxy ${PROXY_PASS}\nfile_server\n" > /etc/caddy/Caddyfile

WORKDIR /etc/caddy

ENTRYPOINT [ "caddy", "run" ]
