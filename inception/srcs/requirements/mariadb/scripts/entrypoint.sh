#!/bin/sh
# create file setting for mysql
cat << EOF > setting.sql
DELETE FROM	mysql.user WHERE User='';
DROP DATABASE test;
DELETE FROM mysql.db WHERE Db='test';
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');

SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$MARIADB_ROOT_PWD');

CREATE DATABASE IF NOT EXISTS $MARIADB_DB;
CREATE USER IF NOT EXISTS  '$MARIADB_USER'@'localhost' IDENTIFIED BY '$MARIADB_PWD';
GRANT ALL privileges ON $MARIADB_DB.* TO $MARIADB_USER@'localhost';
FLUSH PRIVILEGES;
EOF

rm .setup 2>/dev/null
if [ $? -ne 0 ]
then
	# check if mysql running if not start service
	services=$(service mysql status)
	if [[ ${services} = *stopped* ]]
	then
		service mysql start
	fi
	# Apply config
	sed -i "s|skip-networking|# skip-networking|g" /etc/my.cnf.d/mariadb.cnf
	sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0\nport=3306|g" /etc/my.cnf.d/mariadb.cnf

	# push setting in mysql
	echo "$(cat setting.sql)" | mariadb
	pkill mariadb
	touch .setup
fi

mysqld_safe --datadir=/var/lib/mysql

