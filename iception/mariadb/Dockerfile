#maria_db
FROM debian:12.9
#RUN apt update && apt upgrade -y
#RUN apt install mariadb-server -y

RUN mysql -u root -e "CREATE USER '$userDb1'@'%' IDENTIFIED BY '$passDb1'";
RUN mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO '$userDb1'@'%' WITH GRANT OPTION";
RUN mysql -u root -e "CREATE USER '$userDb2'@'%' IDENTIFIED BY '$passDb2'";
RUN mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO '$userDb2'@'%' WITH GRANT OPTION";
RUN mysql -u root -e "FLUSH PRIVILEGES";
RUN mysql -u root -e "CREATE DATABASE $dbName";
COPY ./50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

#CMD ["mysqld", "-g", "daemon off"]