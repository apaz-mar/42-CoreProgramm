#!/bin/bash

set -e

cd /var/www/html

if [ ! -f "wp-config.php" ]; then
    wget https://wordpress.org/latest.tar.gz
    tar -xzf latest.tar.gz
    mv wordpress/* .
    rm -rf wordpress latest.tar.gz

    cp wp-config-sample.php wp-config.php

    sed -i "s/database_name_here/${WP_DB_NAME}/" wp-config.php
    sed -i "s/username_here/${WP_DB_USER}/" wp-config.php
    sed -i "s/password_here/${WP_DB_PASSWORD}/" wp-config.php
    sed -i "s/localhost/${WP_DB_HOST}/" wp-config.php
fi

# in order for nginx to use 9000
sed -i "s|listen = /run/php/php8.2-fpm.sock|listen = 0.0.0.0:9000|" /etc/php/8.2/fpm/pool.d/www.conf

exec php-fpm8.2 -F
#-F means foreground, life daemon off.