FROM debian:bookworm

RUN apt update && apt install -y nginx openssl

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -days 365 \
    -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/server.key \
    -out /etc/nginx/ssl/server.crt \
    -subj "/C=DE/ST=Berlin/L=Berlin/O=42/OU=Inception/CN=apaz-mar.42.fr"

# req generates a certificate request; -x509 signs it ourselves isntead of a CA; -nodes for not needing a password to access the file server.key 
# newkey rsa:2048 generates a new rsa key pair with a 2048 bit key
# CN=localhost identifies the certificate subject

COPY conf/default.conf /etc/nginx/sites-available/default

CMD ["nginx", "-g", "daemon off;"]      
# -g passes a global nginx directive; daemon off keeps nginx in the foreground as PID1, so that the container does not exit
