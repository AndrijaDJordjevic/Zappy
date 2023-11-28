##
## EPITECH PROJECT, 2023
## macro
## File description:
## macro
##

from sys import argv

ARGC = len(argv)
EXIT_ERROR = 84
EXIT_SUCCESS = 0
BUFFER = 1024
RESOURCES = ["linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]
LEVELS = {1: {"linemate": 1},
        2: {"linemate": 1, "deraumere": 1, "sibur": 1},
        3: {"linemate": 2, "sibur": 1, "phiras": 2},
        4: {"linemate": 1, "deraumere": 1, "sibur": 2, "phiras": 1},
        5: {"linemate": 1, "deraumere": 2, "sibur": 1, "mendiane": 3},
        6: {"linemate": 1, "deraumere": 2, "sibur": 3, "phiras": 1},
        7: {"linemate": 2, "deraumere": 2, "sibur": 2, "mendiane": 2, "phiras": 2, "thystame": 1},
}

STARTING_FOOD = 10
STARTING_LEVEL = 1
MAX_LVL = 8
FULL = 0
STARVING = 1