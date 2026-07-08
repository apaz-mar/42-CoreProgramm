NAME = inception

COMPOSE = docker-compose -f srcs/docker-compose.yml

all:
	$(COMPOSE) up -d --build

up:
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

re: fclean all

.PHONY: all up down build restart logs ps clean fclean re
