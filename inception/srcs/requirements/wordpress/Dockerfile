FROM debian:bookworm

RUN apt update && apt install -y \
    php-fpm \
    php-mysql \
    wget \
    tar

RUN mkdir -p /run/php /var/www/html

COPY tools/init_wp.sh   /usr/local/bin/init_wp.sh

RUN chmod +x /usr/local/bin/init_wp.sh

CMD ["/usr/local/bin/init_wp.sh"]

