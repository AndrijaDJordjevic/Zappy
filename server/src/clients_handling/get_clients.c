/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** get_clients
*/

#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "macros.h"
#include "my_server.h"

client_t *get_client_by_fd(client_t *clients, int fd, size_t max_clients)
{
    if (!clients) {
        return NULL;
    }
    for (size_t i = 0; i < max_clients; ++i) {
        if (clients[i].fd == fd)
            return &clients[i];
    }
    return NULL;
}

static void add_client_to_team(client_t *team, client_t *client, size_t max)
{
    for (size_t i = 0; i < max; ++i)
        if (team[i].fd == client->fd)
            return;

    for (size_t i = 0; i < max; ++i)
        if (team[i].fd == -1) {
            team[i] = *client;
            return;
        }
}

client_t *get_client_by_team(client_t *clients, int team_id, serv_t *serv)
{
    client_t *team = malloc(sizeof(client_t) * (serv->param->clients + 1));

    for (int i = 0; i < serv->param->clients + 1; ++i)
        team[i].fd = -1;

    for (int i = 0; clients[i].fd != -1; ++i) {
        if (clients[i].team_index == team_id)
            add_client_to_team(team, &clients[i], serv->max_clients);
    }
    team[serv->param->clients].fd = -2;
    return team;
}
