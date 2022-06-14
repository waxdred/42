#!/bin/sh

adduser $FTP_USR --disabled-password
echo -e "${FTP_USR}\n${FTP_PWD}" > /etc/vsftpd/vsftpd.userlist

chown -R ${FTP_USR}:${FTP_PWD} /var/www/wordpress
cat << EOB
	*************************************************
	*                                               *
	*    Docker image: fauria/vsftpd                *
	*    https://github.com/fauria/docker-vsftpd    *
	*                                               *
	*************************************************
	SERVER SETTINGS
	---------------
	· FTP User: $FTP_USR
	· FTP Password: $FTP_PWD
	· Redirect vsftpd log to STDOUT: No.
EOB

vsftpd /etc/vsftpd/vsftpd.conf
tail -f /dev/null
