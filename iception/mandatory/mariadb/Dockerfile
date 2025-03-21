FROM debian:12.9
RUN apt update && apt upgrade -y
RUN apt install mariadb-server -y
COPY ./config.sh /tmp/config.sh
RUN chmod +x /tmp/config.sh
RUN sed -i "s/127.0.0.1/0.0.0.0/" /etc/mysql/mariadb.conf.d/50-server.cnf 
EXPOSE 3306
CMD ["tmp/config.sh"]