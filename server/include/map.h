/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** my_server
*/

#ifndef _MAP_H
    #define _MAP_H
    #include "player.h"
    #include <stdio.h>

    #define RESSOURCES_NBR 7
    #define FOOD_DENSITY 0.5
    #define LINEMATE_DENSITY 0.3
    #define DERAUMERE_DENSITY 0.15
    #define SIBUR_DENSITY 0.1
    #define MENDIANE_DENSITY 0.1
    #define PHIRAS_DENSITY 0.08
    #define THYSTAME_DENSITY 0.05

typedef struct {
    inventory_t ressources_elements;
    int nb_ressources;
} cell_t;

typedef cell_t **world;

world create_map(size_t x, size_t y);
world generate_world_ressources(world map, size_t x, size_t y);
void free_map(world map, size_t y);
void print_map(world map, size_t x, size_t y);

#endif
