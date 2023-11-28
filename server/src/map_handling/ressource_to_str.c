/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ressource_to_str
*/
#include <stdio.h>
#include "map.h"

char *ressource_to_str(enum ressource item)
{
    switch (item) {
        case FOOD:
            return "food";
        case LINEMATE:
            return "linemate";
        case DERAUMERE:
            return "deraumere";
        case SIBUR:
            return "mendiane";
        case MENDIANE:
            return "mendiane";
        case PHIRAS:
            return "phiras";
        case THYSTAME:
            return "thystame";
        default:
            return "";
    }
}
