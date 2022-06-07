#!/bin/sh

wp-cli config create --allow-root \
		     --path="/var/www/wordpress" \
		     --dbhost="mariadb" \
		     --dbname="jmilhas" \
		     --dbuser="jmilhas" \
		     --dbpass="jmilhas"

# wp-cli core install --allow-root \
# 		    --path="/var/www/wordpress" \
# 		    --title="Wordpress" \
# 		    --admin_name="jmilhas" \
# 		    --admin_password="wordpress" \
# 		    --admin_email="jmilhas@student42lyon.fr" \
# 		    --url="https://jmilhas.42.fr/" \
# 			    && php-fpm7.3 -F -R, "--nodeemonize"

while true; do echo 'to stdout'; echo 'to stderr' >&2; sleep 1; done


