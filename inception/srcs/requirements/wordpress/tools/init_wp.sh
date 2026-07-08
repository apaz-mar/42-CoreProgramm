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

# Wait until MariaDB is ready
until php -r "mysqli_connect('${WP_DB_HOST}', '${WP_DB_USER}', '${WP_DB_PASSWORD}', '${WP_DB_NAME}');" 2>/dev/null; do
    echo "Waiting for MariaDB..."
    sleep 2
done

# Install wp-cli if missing
if [ ! -f /usr/local/bin/wp ]; then
    wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
fi

# Install WordPress only once
if ! wp core is-installed --allow-root; then
    wp core install \
        --url="https://apaz-mar.42.fr" \
        --title="Inception's blog" \
        --admin_user="siteowner" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="siteowner@example.com" \
        --allow-root

    wp user create wp_user wp_user@example.com \
        --role=author \
        --user_pass="${WP_USER_PASSWORD}" \
        --allow-root
fi

# in order for nginx to use 9000
sed -i "s|listen = /run/php/php8.2-fpm.sock|listen = 0.0.0.0:9000|" /etc/php/8.2/fpm/pool.d/www.conf

exec php-fpm8.2 -F
#-F means foreground, life daemon off.