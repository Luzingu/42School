FROM debian:12.9
RUN apt update && apt upgrade -y
RUN apt install mariadb-server -y
COPY ./50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./config.sh /config.sh
RUN chmod +x config.sh
CMD ["/config.sh"]

