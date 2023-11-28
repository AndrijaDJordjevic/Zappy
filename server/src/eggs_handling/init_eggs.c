/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** init_eggs
*/

#include "player.h"
#include "my_server.h"
#include <stdlib.h>
#include "macros.h"

egg_t init_new_egg(int team_index, int x, int y, int id)
{
    egg_t new_egg = (egg_t) {
        .id = id,
        .team_index = team_index,
        .position = (position_t) {x, y},
    };
    return new_egg;
}

egg_t **initialize_eggs(void)
{
    egg_t** eggs = (egg_t**)malloc(2 * sizeof(egg_t*));
    eggs[0] = NULL;
    return eggs;
}
