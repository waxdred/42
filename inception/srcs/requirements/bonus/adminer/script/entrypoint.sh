# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    entrypoint.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 17:57:46 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/15 20:04:56 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
target="/etc/php7/php-fpm.d/www.conf"
sed -i "s|.*listen = 127.0.0.1.*|listen = 8000|g" $target

if [ ! -f "./adminer/index.php" ]; then
	mkdir ./adminer
	curl -L https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1-mysql-en.php \
			--output ./adminer/index.php --silent
fi

php-fpm7 --nodaemonize
