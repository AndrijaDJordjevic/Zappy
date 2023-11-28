/*
** EPITECH PROJECT, 2023
** eggs
** File description:
** eggs
*/

#include "player.h"
#include "my_server.h"
#include <stdlib.h>
#include "macros.h"

int add_egg_to_team(egg_t ***eggs, const int team_index, int x, int y)
{
    int egg_size = 0;
    static int id = 1;
    egg_t* new_egg = (egg_t*)malloc(sizeof(egg_t));

    for (; (*eggs)[egg_size] != NULL; egg_size++);
    if (new_egg == NULL) {
        return -1;
    }
    *new_egg = init_new_egg(team_index, x, y, id);
    *eggs = (egg_t**)realloc(*eggs, (egg_size + 2) * sizeof(egg_t*));
    if (*eggs == NULL) {
        free(new_egg);
        return -1;
    }
    (*eggs)[egg_size] = new_egg;
    (*eggs)[egg_size + 1] = NULL;
    id++;
    return new_egg->id;
}

egg_t* find_egg(egg_t** eggs, int team_index)
{
    if (eggs == NULL)
        return NULL;
    for (int i = 0; eggs[i] != NULL; i++) {
        if (eggs[i]->team_index == team_index)
            return eggs[i];
    }
    return NULL;
}

int count_eggs_in_team(const egg_t** eggs, int team_index)
{
    int count = 0;

    if (eggs == NULL)
        return 0;
    for (int i = 0; eggs[i] != NULL; i++) {
        if (eggs[i]->team_index == team_index)
            count++;
    }
    return count;
}
