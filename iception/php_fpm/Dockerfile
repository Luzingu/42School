FROM debian:12.9
RUN apt update && apt upgrade -y
RUN apt install php php-fpm -y
RUN apt install php-mysql -y
RUN mkdir -p /etc/php/8.2/fpm/pool.d/
RUN apt install wget -y
RUN apt install curl -y

COPY ./www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY ./wp-config.php /wp-config.php
COPY ./config.sh /config.sh
RUN chmod +x config.sh
CMD ["/config.sh"]