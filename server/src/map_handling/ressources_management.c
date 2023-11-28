/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ressources_generations
*/

#include "player.h"
#include "map.h"
#include <stdlib.h>
#include "macros.h"
#include <time.h>

static int density(int x, int y, double density)
{
    return (int)(x * y * density);
}

static int *get_ressources_quant(size_t x, size_t y)
{
    static int ressources_quantity[RESSOURCES_NBR];

    ressources_quantity[FOOD] = density(x, y, FOOD_DENSITY);
    ressources_quantity[LINEMATE] = density(x, y, LINEMATE_DENSITY);
    ressources_quantity[DERAUMERE] = density(x, y, DERAUMERE_DENSITY);
    ressources_quantity[SIBUR] = density(x, y, SIBUR_DENSITY);
    ressources_quantity[MENDIANE] = density(x, y, MENDIANE_DENSITY);
    ressources_quantity[PHIRAS] = density(x, y, PHIRAS_DENSITY);
    ressources_quantity[THYSTAME] = density(x, y, THYSTAME_DENSITY);

    return ressources_quantity;
}

static void add_ressource(inventory_t *ressources, enum ressource ressource,
    int nb_ressources)
{
    int *ressources_list[RESSOURCES_NBR] = {
        (&ressources->food),
        (&ressources->linemate),
        (&ressources->deraumere),
        (&ressources->sibur),
        (&ressources->mendiane),
        (&ressources->phiras),
        (&ressources->thystame)
    };

    if (nb_ressources == -1)
        return;
    else {
        (*ressources_list[ressource])++;
        return;
    }
}

world generate_world_ressources(world map, size_t x, size_t y)
{
    int *ressources_quantity = get_ressources_quant(x, y);
    int x_rsrc;
    int y_rsrc;

    srand(time(NULL));

    for (int ressource = 0; ressource < RESSOURCES_NBR; ressource++) {
        for (int j = 0; j < ressources_quantity[ressource]; j++) {
            x_rsrc = rand() % x;
            y_rsrc = rand() % y;
            add_ressource(&map[y_rsrc][x_rsrc].ressources_elements,
                (enum ressource) ressource, map[y_rsrc][x_rsrc].nb_ressources);
            map[y_rsrc][x_rsrc].nb_ressources++;
        }
    }

    return map;
}
