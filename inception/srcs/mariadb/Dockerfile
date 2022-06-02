FROM debian:buster-slim

RUN apt update && apt upgrade -y           		# update debian buster-slim
RUN apt install mariadb-server mariadb-client -y	# install mariadb

expose 3306
CMD ["mariadbd"]

