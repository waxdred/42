#!/bin/sh
# create file setting for mysql
if [ ! -d "/var/lib/mysql/wordpress" ]
then 
    	mysql_install_db
    	service mysql start
    	mysql -e "DROP DATABASE test"	
    	mysql -e "CREATE USER '${MARIADB_USER}'@'localhost' identified by '${MARIADB_PWD}';" &&\
	mysql -e "CREATE DATABASE wordpress;" &&\
	mysql -e "GRANT ALL PRIVILEGES ON *.* TO '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PWD}';" &&\
	mysql -e "FLUSH PRIVILEGES;"
	mysql -u root -e "alter user 'root'@'localhost' identified by '${MARIADB_ROOT_PWD}'";
    	service mysql stop 
fi
mysqld_safe --datadir=/var/lib/mysql
