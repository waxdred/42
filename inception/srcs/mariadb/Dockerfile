FROM debian:buster-slim

RUN apt-get update
RUN apt-get install -y mariadb-server
RUN apt-get install -y mariadb-client


RUN mkdir -p /run/mysqld
RUN chown -R mysql:mysql /run/mysqld
COPY ./setting.sh .

# RUN bash ./setting.sh

HEALTHCHECK --start-period=5m \
  CMD mariadb -e 'SELECT @@datadir;' || exit 1
ENTRYPOINT bash ./setting.sh

EXPOSE 3306
CMD ["mysqld"]
