FROM debian:12.9
RUN apt update && apt upgrade -y
RUN apt install nginx -y
RUN mkdir -p /etc/nginx/sites-available/
COPY ./default /etc/nginx/sites-available/default
RUN mkdir -p /etc/nginx/ssl/
COPY ./ssl/nginx.crt /etc/nginx/ssl/nginx.crt 
COPY ./ssl/nginx.key /etc/nginx/ssl/nginx.key 
RUN apt install openssl
CMD ["nginx", "-g", "daemon off;"]
