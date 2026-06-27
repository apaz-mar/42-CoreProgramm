FROM debian:bookworm

RUN apt update && apt install -y mariadb-server

#mariadb needs a directory /run/mysqld to start the process and create a socket:
RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld /var/lib/mysql

COPY tools/init_db.sh /usr/local/bin/init_db.sh

RUN chmod +x /usr/local/bin/init_db.sh

CMD ["/usr/local/bin/init_db.sh"]
