# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 22:07:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/14 16:02:57 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim

RUN apt update && apt install -y vsftpd

RUN mkdir -p /etc/vsftpd

COPY ./script/entrypoint.sh /
COPY ./config/vsftpd.conf /etc/vsftpd/vsftpd.conf

EXPOSE 21 21000-21010
CMD ["bash", "/entrypoint.sh"]
