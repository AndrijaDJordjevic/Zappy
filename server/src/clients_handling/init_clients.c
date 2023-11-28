/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** init_clients
*/

#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
#include "my_server.h"

void overwrite_client(client_t *client, serv_t *serv, int fd)
{
    client->client_type = UNKNOWN;
    client->pos = get_random_position(serv->param->width, serv->param->height);
    client->orientation = N;
    client->fd = fd;
    client->level = 1;
    client->egg_nbr = 0;
    client->life = LIFE_UNIT * DEFAULT_LIFE;
    client->team_index = -1;
    client->time_unit = 0;
    client->client_cmd_queue.cmd_nbr = 0;
    client->client_cmd_queue.args_link = NULL;
    client->client_cmd_queue.time_unit[0] = NO;
    client->survival_time = time(NULL);
}

client_t init_new_client(int fd, serv_t *serv)
{
    client_t client;

    client.client_type = UNKNOWN;
    client.pos = get_random_position(serv->param->width, serv->param->height);
    client.inventory = (inventory_t) {10, 0, 0, 0, 0, 0, 0};
    client.orientation = N;
    client.fd = fd;
    client.level = 1;
    client.egg_nbr = 0;
    client.life = LIFE_UNIT * DEFAULT_LIFE;
    client.team_index = -1;
    client.time_unit = 0;
    client.client_cmd_queue.cmd_nbr = 0;
    client.client_cmd_queue.args_link = NULL;
    client.client_cmd_queue.time_unit[0] = NO;
    client.survival_time = time(NULL);
    return client;
}
