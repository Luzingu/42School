FROM debian:12.9

RUN apt update && apt upgrade -y
RUN apt install apache2 php php-mysql -y
RUN apt install wget
RUN mkdir -p /var/www/html/adminer
RUN cd /var/www/html/adminer && wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php -O index.php
CMD ["apache2ctl", "-D", "FOREGROUND"]