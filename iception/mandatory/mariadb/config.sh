#!/bin/bash
service mariadb start
sleep 3
mysql -u root -e "CREATE USER '$userDb1'@'%' IDENTIFIED BY '$passDb1'";
mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO '$userDb1'@'%' WITH GRANT OPTION";
mysql -u root -e "CREATE USER '$userDb2'@'%' IDENTIFIED BY '$passDb2'";
mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO '$userDb2'@'%' WITH GRANT OPTION";
mysql -u root -e "FLUSH PRIVILEGES";
mysql -u root -e "CREATE DATABASE $dbName";
service mariadb stop
mysqld_safe --user=mysql