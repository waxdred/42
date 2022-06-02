FROM debian:buster-slim
RUN apt-get update
RUN apt-get install -y mariadb-server
RUN apt-get install -y mariadb-client

LABEL version="1.0"
LABEL description="MariaDB Server"

RUN mkdir -p /run/mysqld
RUN chown -R mysql:mysql /run/mysqld
# RUN service mysql start && mariadb -u root < /tmp/mariadb/setup.sql

RUN ln -s usr/local/bin/docker-entrypoint.sh
HEALTHCHECK --start-period=5m \
  CMD mariadb -e 'SELECT @@datadir;' || exit 1
EXPOSE 3306
CMD ["mysqld"]
