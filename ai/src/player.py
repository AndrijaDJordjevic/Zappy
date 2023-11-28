##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-martin.petit
## File description:
## player
##

from macro import STARTING_FOOD, STARTING_LEVEL

class Player:
    def __init__(self):
        self.player = 1
        self.inventory = {
            'linemate': 0,
            'deraumere': 0,
            'sibur': 0,
            'mendiane': 0,
            'phiras': 0,
            'thystame': 0
        }
        self.food = STARTING_FOOD
        self.level = STARTING_LEVEL


def display_inventory(player):
    print("Inventory:", player.inventory)
    print("Food :", player.food)
