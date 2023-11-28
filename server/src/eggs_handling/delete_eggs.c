/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** delete_eggs
*/

#include "player.h"
#include "my_server.h"
#include <stdlib.h>
#include "macros.h"

static bool check_and_delete_egg(egg_t **eggs, position_t pos, int *tmp, int i)
{
    if (eggs[i]->position.x == pos.x && eggs[i]->position.y == pos.y) {
        *tmp = eggs[i]->id;
        free(eggs[i]);
        for (int j = i; eggs[j] != NULL; j++) {
            eggs[j] = eggs[j + 1];
        }
        *tmp = i;
        return true;
    }
    return false;
}

int remove_egg_position(egg_t** eggs, int x, int y)
{
    int tmp = -1;

    if (eggs == NULL)
        return -1;
    for (int i = 0; eggs[i] != NULL; i++) {
        if (check_and_delete_egg(eggs, (position_t) {x, y},  &tmp, i))
            break;
    }
    return tmp;
}

void free_all_eggs(egg_t** eggs)
{
    if (eggs == NULL)
        return;
    for (int i = 0; eggs[i] != NULL; i++) {
        free(eggs[i]);
    }
    free(eggs);
}
