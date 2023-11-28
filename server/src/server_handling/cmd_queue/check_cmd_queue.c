/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** check_cmd_queue
*/

#include "player.h"
#include "my_server.h"
#include "client_cmd_macros.h"
#include "client_cmd.h"
#include <time.h>
#include <stdlib.h>

args_link_t *pop_cmd_queue(args_link_t *args_link)
{
    args_link_t *tmp = NULL;

    if (args_link == NULL)
        return NULL;
    tmp = args_link;
    args_link = args_link->next;
    free_array(tmp->args);
    free(tmp);
    return args_link;
}

void pop_client_cmd_queue(client_cmd_queue_t *cmd_queue)
{
    for (int i = 0; i < cmd_queue->cmd_nbr - 1; i++) {
        cmd_queue->cmd[i] = cmd_queue->cmd[i + 1];
        cmd_queue->time_unit[i] = cmd_queue->time_unit[i + 1];
    }
    cmd_queue->cmd[cmd_queue->cmd_nbr - 1] = NULL;
    cmd_queue->time_unit[cmd_queue->cmd_nbr - 1] = 0;
}

void check_player_queue(client_t *client, serv_t *serv)
{
    client_cmd_queue_t *cmd_queue = NULL;
    long int elapsed_time = time(NULL) - client->action_time;
    int action_time_unit;

    if (client == NULL)
        return;
    cmd_queue = &client->client_cmd_queue;
    if (cmd_queue->cmd_nbr == 0)
        return;
    action_time_unit = cmd_queue->time_unit[0] / serv->param->freq;

    if (elapsed_time >= action_time_unit) {
        cmd_queue->cmd[0](client->fd, serv, cmd_queue->args_link->args);
        cmd_queue->args_link = pop_cmd_queue(cmd_queue->args_link);
        pop_client_cmd_queue(cmd_queue);
        cmd_queue->cmd_nbr--;
        client->action_time = time(NULL);
    }
}

void check_cmd_queue(serv_t *serv)
{
    client_t *clients = serv->clients;

    for (size_t i = 0; i < serv->max_clients; ++i) {
        if (clients[i].fd != -1 && clients[i].team_index != -1)
            check_player_queue(&clients[i], serv);
    }
}
