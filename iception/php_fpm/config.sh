#!/bin/bash
service php8.2-fpm start
sleep 2
cd /var/www/html
rm -rf * && wget https://wordpress.org/wordpress-6.7.2.zip && apt install unzip && unzip wordpress-6.7.2.zip
mv ./wordpress/* . && rm -rf wordpress && rm wordpress-6.7.2.zip
mv /wp-config.php /var/www/html/wp-config.php 
chmod 777 /var/www/html/
sed -i "s/localhost/mariadb/g" wp-config.php
sed -i "s/username_here/$userDb/g" wp-config.php
sed -i "s/database_name_here/$dbName/g" wp-config.php
sed -i "s/password_here/$passDb/g" wp-config.php
cd && curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp
wp core install --url=aluzingu.42.fr --title="$siteTile" --admin_user="$siteUserAdmin" --admin_password="$sitePassAdmin" --admin_email="$siteAdminEmail" --allow-root
wp theme install astra --activate --allow-root

service php8.2-fpm stop;
php-fpm8.2 --nodaemonize
