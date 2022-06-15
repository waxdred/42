# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 22:07:43 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/15 11:35:50 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim

ARG FTP_USR=${FTP_USR}
ARG FTP_PWD=${FTP_PWD}

RUN apt update && apt install -y vsftpd openssl

RUN mkdir -p /etc/vsftpd
RUN adduser $FTP_USR
RUN echo "$FTP_USR:$FTP_PWD" | chpasswd
RUN echo $FTP_USR | tee -a  /etc/vsftpd/vsftpd.userlist

RUN mkdir -p /var/run/vsftpd/empty

RUN mkdir -p /home/$FTP_USR/FTP
RUN chown $FTP_USR:$FTP_USR /home/$FTP_USR/FTP

RUN chmod 777 /home/$FTP_USR/FTP


COPY ./script/entrypoint.sh /
COPY ./config/vsftpd.conf /etc/vsftpd/vsftpd.conf

RUN mkdir /etc/cert
RUN echo -e "FR\nFR\njmilhas\n42\n42\nFTP\nstudent.42.fr\n" | \
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/cert/vsftpd.pem \
    -out /etc/cert/vsftpd.pem

EXPOSE 21 21000-21010
CMD ["bash", "/entrypoint.sh"]
