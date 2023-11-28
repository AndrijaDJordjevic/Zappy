/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-martin.petit
** File description:
** check_take_set_args
*/

#include <stdbool.h>
#include <string.h>
#include "player.h"

enum ressource get_ressource_index(char *arg)
{
    static const char *ressources[] = {
        "food", "linemate", "deraumere", "sibur", "mendiane", "phiras",
        "thystame", NULL
    };
    for (int i = 0; ressources[i]; i++)
        if (strcmp(arg, ressources[i]) == 0)
            return (enum ressource) i;
    return (enum ressource) NONE;
}

bool check_take_set_args(char *arg)
{
    static const char *ressources[] = {
        "food", "linemate", "deraumere", "sibur", "mendiane", "phiras",
        "thystame", NULL
    };

    for (int i = 0; ressources[i]; i++)
        if (strcmp(arg, ressources[i]) == 0)
            return true;
    return false;
}
