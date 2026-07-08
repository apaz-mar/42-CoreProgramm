# DEV_DOC.md

# Developer Documentation

## Purpose

This document explains how to set up, build, maintain and troubleshoot
the Inception project from a developer's perspective.

------------------------------------------------------------------------

# Prerequisites

-   Debian/Linux virtual machine
-   Docker
-   Docker Compose
-   GNU Make
-   Git
-   Access to the Vogsphere repository

------------------------------------------------------------------------

# Repository Structure

    .
    ├── Makefile
    ├── README.md
    ├── USER_DOC.md
    ├── DEV_DOC.md
    └── srcs
        ├── docker-compose.yml
        ├── .env
        └── requirements
            ├── mariadb
            │   ├── Dockerfile
            │   └── tools/init_db.sh
            ├── nginx
            │   ├── Dockerfile
            │   └── conf/
            └── wordpress
                ├── Dockerfile
                └── tools/init_wp.sh

------------------------------------------------------------------------

# Environment Configuration

Project configuration is stored in `srcs/.env`.

Current variables:

  Variable           Description
  ------------------ ----------------------------------------
  `MYSQL_DATABASE`   Database created during initialization
  `MYSQL_USER`       WordPress database user
  `MYSQL_PASSWORD`   Database user password
  `WP_DB_HOST`       MariaDB service hostname
  `WP_DB_NAME`       WordPress database
  `WP_DB_USER`       WordPress database user
  `WP_DB_PASSWORD`   Password used by WordPress

For this educational project, credentials are provided through
environment variables. In production, Docker Secrets would be the
preferred mechanism for sensitive information.

------------------------------------------------------------------------

# Building and Launching

The project should be managed through the Makefile.

``` bash
make
make up
make down
make ps
make logs
make clean
make fclean
make re
```

------------------------------------------------------------------------

# Docker Architecture

The stack contains three custom-built containers:

-   **Nginx**: HTTPS reverse proxy.
-   **WordPress (PHP-FPM)**: Website application.
-   **MariaDB**: Database service.

Containers communicate through a private Docker bridge network.

------------------------------------------------------------------------

# Persistent Data

Persistent data is stored in Docker volumes.

This ensures that:

-   WordPress files survive container recreation.
-   MariaDB data survives container recreation.

------------------------------------------------------------------------

# Useful Docker Commands

``` bash
docker ps
docker images
docker volume ls
docker network ls
docker-compose -f srcs/docker-compose.yml logs
docker-compose -f srcs/docker-compose.yml exec <service> bash
```

------------------------------------------------------------------------

# Development Environment

The project was developed inside a Debian virtual machine.

## VirtualBox SSH Configuration

To allow cloning from Vogsphere directly inside the VM during peer
evaluations, VirtualBox port forwarding was configured:

-   Host port: **2222**
-   Guest port: **22**

After installing and enabling the OpenSSH server in the VM, files can be
copied from the host with:

``` bash
scp -P 2222 ~/.ssh/id_rsa ~/.ssh/id_rsa.pub apaz-mar@127.0.0.1:/home/apaz-mar/.ssh/
```

This allows the VM to use the same SSH key pair as the host, so both
authenticate successfully against the 42 Vogsphere repository.

------------------------------------------------------------------------

# Data Persistence

Project data persists through Docker volumes rather than bind mounts,
allowing containers to be rebuilt without losing the WordPress
installation or the database.

------------------------------------------------------------------------

# Troubleshooting

## SSH authentication

If cloning from Vogsphere fails inside the VM:

-   Verify that the VM uses the same SSH key pair as the host.
-   Test authentication with:

``` bash
ssh -T git@vogsphere.42berlin.de
```

## Containers fail to start

Inspect logs:

``` bash
make logs
```

or

``` bash
docker-compose -f srcs/docker-compose.yml logs
```

## Database connection errors

Verify the values in `srcs/.env` and confirm that the MariaDB container
is running before WordPress starts.
