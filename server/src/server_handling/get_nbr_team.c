/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** get_nbr_team
*/

#include "player.h"

int get_nbr_team(client_t *clients, int team, size_t max_client)
{
    int count = 0;

    if (!clients)
        return 0;

    for (size_t i = 0; i < max_client; i++) {
        if (clients[i].fd != -1 && clients[i].team_index == team)
            count++;
    }
    return count;
}
