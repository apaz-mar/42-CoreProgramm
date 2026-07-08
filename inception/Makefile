NAME = inception

COMPOSE = docker-compose -f srcs/docker-compose.yml

all:
	mkdir -p /home/apaz-mar/data/dbdata
	mkdir -p /home/apaz-mar/data/wpdata
	$(COMPOSE) up -d --build

up:
	mkdir -p /home/apaz-mar/data/dbdata
	mkdir -p /home/apaz-mar/data/wpdata
	$(COMPOSE) up -d

down:
	$(COMPOSE) down

build:
	$(COMPOSE) build

restart: down up

logs:
	$(COMPOSE) logs -f

ps:
	$(COMPOSE) ps

clean:
	$(COMPOSE) down --rmi all

fclean: clean
	docker volume prune -f
	docker network prune -f
	rm -rf /home/apaz-mar/data/dbdata
	rm -rf /home/apaz-mar/data/wpdata

re: fclean all

.PHONY: all up down build restart logs ps clean fclean re
