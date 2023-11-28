/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** random_spawn_player
*/

#include "player.h"
#include <stdlib.h>

static int get_random_x(int max)
{
    int x = rand() % max;

    return x;
}

static int get_random_y(int max)
{
    int y = rand() % max;

    return y;
}

position_t get_random_position(int x, int y)
{
    position_t position;

    position.x = get_random_x(x);
    position.y = get_random_y(y);
    return position;
}
