# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaz-mar <apaz-mar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 16:51:27 by apaz-mar          #+#    #+#              #
#    Updated: 2026/05/06 17:27:10 by apaz-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from fastapi import FastAPI

app = FastAPI()

@app.get("/")
def root():
    return {"message": "I changed the API"}

@app.get("/players")
def get_players():
    return [
        {"id": 1, "name": "Aaron", "score": 42},
        {"id": 2, "name": "Peer", "score": 21}
    ]
