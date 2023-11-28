/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** free_map
*/

#include "map.h"
#include <stdlib.h>

void free_map(world map, size_t y)
{
    if (map == NULL)
        return;

    for (size_t i = 0; i <= y; i++) {
        if (map[i]) {
            free(map[i]);
        }
    }
    free(map);
}
