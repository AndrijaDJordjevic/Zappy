/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** print_map
*/

#include "my_server.h"

void print_map(world map, size_t x, size_t y)
{
    if (!map)
        return;
    printf("Map:\n");
    for (size_t yi = 0; yi < y; yi++) {
        printf("Line %ld: ", yi);
        for (size_t xi = 0; xi < x; xi++)
            printf("%d ", map[yi][xi].nb_ressources);
        printf("\n");
    }
    if (map[y])
        printf("Line %ld: %d", y, map[y][0].nb_ressources);
    printf("\n");
}
