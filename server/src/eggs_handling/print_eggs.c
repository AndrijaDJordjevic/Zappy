/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** print_eggs
*/

#include "player.h"
#include "my_server.h"
#include <stdlib.h>

void print_eggs(const egg_t** eggs)
{
    if (eggs == NULL) {
        printf("No eggs found.\n");
        return;
    }
    printf("Eggs:\n");
    for (int i = 0; eggs[i] != NULL; i++) {
        printf("Egg %d: team_index = %d, position = (%d, %d)\n",
            eggs[i]->id, eggs[i]->team_index,
            eggs[i]->position.x, eggs[i]->position.y);
    }
}
