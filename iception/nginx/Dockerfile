#nginx
FROM debian:12.9
RUN apt update && apt upgrade -y
RUN apt install nginx -y
COPY ./nginx/default /etc/nginx/sites-available/default
COPY ./nginx/ssl/nginx.crt /etc/nginx/ssl/nginx.crt 
COPY ./nginx/ssl/nginx.key /etc/nginx/ssl/nginx.key 
RUN apt install openssl
RUN mkdir -p /etc/nginx/ssl/
#CMD ["nginx" "-g", "daemon off"]
