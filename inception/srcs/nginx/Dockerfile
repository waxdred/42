FROM debian:buster-slim

RUN apt update && apt upgrade -y && apt install nginx -y	# Update && install Nginx
RUN apt install openssl -y						# install openssl
RUN mkdir -p docker-web/www				# Webroot dans lequel sera stocké le contenu statique du site
RUN mkdir -p docker-web/log				# Pour enregistrer les Journaux de Nginx
RUN mkdir -p docker-web/log/{error,access}.log		# Journaux pour Nginx
RUN mkdir -p /etc/nginx/ssl				# certificats
RUN chmod a+rw docker-web/log/* 			# Droit de lecture/ecriture pour tous le monde

COPY default.conf /etc/nginx/sites-available/default

RUN openssl req\
	-newkey rsa:4096 \
	-x509 \
	-sha256 \
	-days 365 \
	-nodes \
	-subj "/C=FR/ST=RN/L=lyon/O=42/OU=jmilhas/CN=localhost" \
	-keyout /etc/nginx/ssl/inception.key \
	-out /etc/nginx/ssl/inception.cert
RUN apt install openrc -y && rc-update add nginx default


EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
