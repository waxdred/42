#!/bin/sh

if  [ ! -f /var/www/wordpress/wp-config.php ]; then 
    wp core --allow-root download --locale=fr_FR --force 
    sleep 5;
    while  [ ! -f /var/www/wordpress/wp-config.php ]; do   
        wp core config --allow-root --dbname=wordpress --dbuser=$MARIADB_USER --dbpass=$MARIADB_PWD --dbhost=mariadb:3306
    done 
    wp core install --allow-root --url=$WP_URL --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PWD  --admin_email=$WP_ADMIN_EMAIL --path='/var/www/wordpress';
    wp plugin install redis-cache --activate
    wp plugin update --all
    wp  user create --allow-root $WP_USER $WP_USER_EMAIL --user_pass=$WP_ADMIN_PWD --role=author
    wp theme install --allow-root dark-mode --activate    
fi 
php-fpm7.3 --nodaemonize
