# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main2.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaz-mar <apaz-mar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 19:17:39 by apaz-mar          #+#    #+#              #
#    Updated: 2026/05/06 19:58:08 by apaz-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware

app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

players = [ # [] means list
    {"id": 1, "name": "Aaron", "score": 42},  # {} means dictionary
    {"id": 2, "name": "Bob", "score": 21}
]   # so this was a list of dictionaries

@app.get("/")
def root():
    return {"message": "API running"}

@app.get("/players")
def get_players():
    return players

@app.get("/players/{player_id}")
def get_player(player_id: int):
    for player in players:
        if (player["id"] == player_id):
            return player
    
    return {"error": "player not found"}