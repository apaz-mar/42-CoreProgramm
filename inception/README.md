*This project has been created as part of the 42 curriculum by
apaz-mar.*

# Inception

## Description

**Inception** is a system administration project whose objective is to
introduce containerization using Docker. Instead of installing multiple
services directly on the operating system, each service is isolated
inside its own container and the complete application stack is
orchestrated using Docker Compose.

The project implements a complete WordPress website composed of three
services:

-   **Nginx** as the HTTPS web server and reverse proxy.
-   **WordPress** running with **PHP-FPM**.
-   **MariaDB** as the database server.

Each service is built from its own custom Dockerfile, communicates
through a dedicated Docker network, and stores persistent data in Docker
volumes.

The project has been developed and tested inside a Debian virtual
machine, as required by the subject.

------------------------------------------------------------------------

# Project Design

## Architecture

``` text
                 HTTPS (443)
                       │
                       ▼               
                    NGINX      
                   TLS only    
                       │
                       ▼
                  WordPress     
                   PHP-FPM     
                       │
                       ▼
                   MariaDB     


           Docker Network
                 │
     Persistent Docker Volumes
```

The complete stack is started with Docker Compose from a single
Makefile.

Each service runs inside its own container and has a single
responsibility.

### Main Design Choices

-   One Dockerfile per service.
-   One container per service.
-   Containers communicate through a private Docker network.
-   Only Nginx is exposed to the outside world.
-   HTTPS is enforced using TLS.
-   Persistent data is stored in Docker volumes.
-   Configuration values are stored in environment variables, while
    sensitive information is stored as Docker secrets whenever
    appropriate.
-   All services restart automatically if a container exits
    unexpectedly.

# Design Comparisons

## Virtual Machines vs Docker

A virtual machine emulates an entire operating system, including its own
kernel, making it heavier in terms of disk space, RAM usage and startup
time.

Docker containers instead share the host kernel while isolating
processes, networks and filesystems. They are considerably lighter,
start almost instantly and are easier to reproduce.

## Secrets vs Environment Variables

Configuration values are loaded from a local .env file and injected into the containers as environment variables. To avoid exposing sensitive information, the local .env file is excluded from version control and a .env.example template is provided instead. For the scope of this educational project, this approach keeps the configuration simple while separating configuration from the application code.

## Docker Network vs Host Network

This project uses a dedicated Docker bridge network instead of the host
network.

Advantages include service isolation, internal name resolution and
exposing only the Nginx HTTPS endpoint.

## Docker Volumes vs Bind Mounts

Docker volumes provide managed persistent storage that survives
container recreation and is independent of the host directory layout.

# Instructions

## Requirements

-   Docker
-   Docker Compose
-   GNU Make
-   Debian/Linux virtual machine

### Build and start the stack

```bash
make
```

or equivalently

```bash
make all
```

### Start existing containers

```bash
make up
```

### Stop the stack

```bash
make down
```

### Display running services

```bash
make ps
```

### Display logs

```bash
make logs
```

### Remove containers and images

```bash
make clean
```

### Remove all Docker resources

```bash
make fclean
```

### Rebuild everything

```bash
make re
```

# Repository Structure

``` text
.
├── Makefile
├── README.md
├── USER_DOC.md
├── DEV_DOC.md
├── .gitignore
└── srcs
    ├── docker-compose.yml
    ├── .env.example
    └── requirements
        ├── mariadb
        ├── nginx
        └── wordpress
```

# Resources

## Documentation

-   Docker Documentation: https://www.youtube.com/watch?v=bKFMS5C4CG0
-   Docker Compose Documentation: https://www.educative.io/blog/docker-compose-tutorial
-   Nginx Documentation: https://docs.nginx.com/nginx/admin-guide/basic-functionality/managing-configuration-files/
-   MariaDB Documentation: https://mariadb.com/docs/server/server-management/automated-mariadb-deployment-and-administration/docker-and-mariadb/installing-and-using-mariadb-via-docker
-   WordPress Documentation: https://hub.docker.com/_/wordpress

## AI Usage

Artificial Intelligence (ChatGPT) was used as a learning and
documentation assistant for understanding Docker concepts, networking,
TLS, reviewing documentation and improving technical writing.

All implementation, configuration, Dockerfiles and shell scripts were
developed, tested and validated manually.
