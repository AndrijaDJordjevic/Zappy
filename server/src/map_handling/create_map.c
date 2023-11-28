/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** create_map
*/

#include "map.h"
#include <stdlib.h>
#include "macros.h"

static void init_cell(cell_t *cell, int init_value)
{
    cell->nb_ressources = init_value;
    cell->ressources_elements = (inventory_t) {init_value, init_value,
init_value, init_value, init_value, init_value, init_value};
}

world create_map(size_t x, size_t y)
{
    world map = malloc(sizeof(cell_t *) * (y + 1));

    if (!map)
        return NULL;
    for (size_t i = 0; i < y; i++) {
        map[i] = calloc(x, sizeof(cell_t));
        if (!map[i]) {
            free_map(map, i);
            return NULL;
        }
        for (size_t j = 0; j < x; j++)
            init_cell(&map[i][j], 0);
    }
    map[y] = malloc(sizeof(cell_t));
    if (!map[y]) {
        free_map(map, y);
        return NULL;
    }
    init_cell(&map[y][0], -1);
    return map;
}
