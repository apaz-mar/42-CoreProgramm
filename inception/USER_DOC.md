# USER_DOC.md

# User Documentation

## Overview

This project deploys a complete WordPress website using Docker
containers. The stack consists of three independent services:

-   **Nginx** -- HTTPS web server and reverse proxy.
-   **WordPress (PHP-FPM)** -- Content Management System.
-   **MariaDB** -- Database server used by WordPress.

The services communicate through a private Docker network and store
persistent data in Docker volumes.

------------------------------------------------------------------------

# Starting the Project

The project is intended to be managed through the provided **Makefile**.

Build the images (if necessary) and start the complete stack:

``` bash
make
```

Alternatively, start existing containers:

``` bash
make up
```

------------------------------------------------------------------------

# Stopping the Project

``` bash
make down
```

------------------------------------------------------------------------

# Useful Commands

``` bash
make ps      # Show running containers
make logs    # Display container logs
make clean   # Stop containers and remove images
make fclean  # Remove containers, images, volumes and unused networks
make re      # Rebuild the complete project
```

------------------------------------------------------------------------

# Services Provided

  -----------------------------------------------------------------------
  Service                               Purpose
  ------------------------------------- ---------------------------------
  Nginx                                 Serves the website over HTTPS and
                                        forwards PHP requests to PHP-FPM.

  WordPress                             Hosts the website and the
                                        administration panel.

  MariaDB                               Stores WordPress users, posts,
                                        media references and settings.
  -----------------------------------------------------------------------

------------------------------------------------------------------------

# Accessing the Website

Open your browser and navigate to:

``` text
https://apaz-mar.42.fr
```

The project only serves content over **HTTPS**.

------------------------------------------------------------------------

# Accessing the WordPress Administration Panel

``` text
https://apaz-mar.42.fr/wp-admin
```

Log in using the administrator credentials created during the WordPress
installation.

------------------------------------------------------------------------

# Credentials

Project configuration is stored in `srcs/.env`.

  Variable           Purpose
  ------------------ --------------------------------------------------
  `MYSQL_DATABASE`   MariaDB database created during initialization
  `MYSQL_USER`       Database user used by WordPress
  `MYSQL_PASSWORD`   Password for the WordPress database user
  `WP_DB_HOST`       Database hostname (`mariadb`)
  `WP_DB_NAME`       Database used by WordPress
  `WP_DB_USER`       WordPress database user
  `WP_DB_PASSWORD`   Password used by WordPress to connect to MariaDB

If any value is modified, rebuild or restart the affected containers.

------------------------------------------------------------------------

# Verifying the Services

Check that the containers are running:

``` bash
make ps
```

or

``` bash
docker ps
```

The stack is working correctly when:

-   All containers are in the **Up** state.
-   The website is reachable over HTTPS.
-   The WordPress administration panel is accessible.
-   Data persists after restarting the containers.

------------------------------------------------------------------------

# Troubleshooting

If a service fails to start or restarts repeatedly, inspect the logs:

``` bash
make logs
```

or

``` bash
docker-compose -f srcs/docker-compose.yml logs
```
