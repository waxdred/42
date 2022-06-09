-- https://stackoverflow.com/questions/10299148/mysql-error-1045-28000-access-denied-for-user-billlocalhost-using-passw
-- delete test install 
DELETE FROM	mysql.user WHERE User='';

-- remove DATABASE test
DROP DATABASE test;
DELETE FROM mysql.db WHERE Db='test';
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
--  set root pwd
SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$MARIADB_ROOT_PWD');

--  create wordpress assets
CREATE DATABASE $WP_DATABASE;
CREATE USER '$STUD'@'%' IDENTIFIED by '$STUD';
GRANT ALL PRIVILEGES ON $STUD.* TO $STUD@'%';

--  take effects
FLUSH PRIVILEGES;
