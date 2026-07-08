#!/bin/bash

#startup script for mariadb, since the mysqld does not yet create the db user

### #!/bin/bash is a shebang. It tells Linux to run this script using /bin/bash. Without it, the system may not know which interpreter should execute the file

#only initialize once
if [ ! -d "/var/lib/mysql/${MYSQL_DATABASE}" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    mysqld --user=mysql --skip-networking &
    pid="$!"

    sleep 5


    mariadb << EOF
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    kill "$pid"
    wait "$pid"
fi

# so that mariadb listens on all container interfaces
exec mysqld --user=mysql --bind-address=0.0.0.0