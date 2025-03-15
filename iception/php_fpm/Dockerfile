#php_fpm
FROM debian:12.9
RUN apt update && apt upgrade -y
#RUN apt install php php-fpm -y
#RUN apt install php-mysql -y
COPY ./php_fpm/www.conf /etc/php/8.2/fpm/pool.d/www.conf
RUN apt install wget -y
RUN cd /var/www/html && rm -f *
RUN wget https://wordpress.org/wordpress-6.7.2.zip
RUN apt install unzip
RUN unzip wordpress-6.7.2.zip &&  mv ./wordpress/* .
RUN rm -dr wordpress && rm wordpress-6.7.2.zip
COPY ./php_fpm/wp-config.php /var/www/html/wp-config.php
RUN  sed -i "s/localhost/mariadb/g" wp-config.php
RUN  sed -i "s/username_here/$userDb/g" wp-config.php
RUN  sed -i "s/database_name_here/$dbName/g" wp-config.php
RUN  sed -i "s/password_here/$passDb/g" wp-config.php
RUN apt instal curl
RUN cd && curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp
RUN cd /var/www/html
RUN wp core install --url=aluzingu.42.fr --title="$siteTile" --admin_user="$siteUserAdmin" --admin_password="$sitePassAdmin" --admin_email="$siteAdminEmail" --allow-root
RUN wp theme install astra --activate --allow-root
#CMD ["php8.2-fpm", "-g", "daemon off"]
