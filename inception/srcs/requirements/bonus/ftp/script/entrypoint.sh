#!/bin/sh

RUN chmod 777 /var/www/wordpress

sleep 5
cat << EOF
	*************************************************
	*                                               *
	*    Docker image: vsftpd                       *
	*                                               *
	*************************************************
	* SERVER SETTINGS                               *
	* ----------------------------------------------*
	* . Hôte:     		student.42.fr           *
	* · FTP User: 		$FTP_USR                *
	* · FTP Password: 	$FTP_PWD                *
	* · Redirect vsftpd log to STDOUT: No.          *
	*************************************************
EOF

vsftpd /etc/vsftpd/vsftpd.conf
tail -f /dev/null
