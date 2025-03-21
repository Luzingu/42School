FROM debian:12.9
RUN apt update && apt upgrade -y
RUN apt install redis-server -y
COPY redis.conf /etc/redis/redis.conf
CMD ["redis-server", "--daemonize", "no"]