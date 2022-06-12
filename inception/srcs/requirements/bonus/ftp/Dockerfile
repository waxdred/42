# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 22:07:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/12 07:53:12 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim

RUN apt update && pat install -y vsftpd

EXPOSE 21 21000-21010

VOLUME /ftp/ftp



