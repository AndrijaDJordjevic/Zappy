/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** handle_players_life
*/

#include "macros.h"
#include "my_server.h"
#include "player.h"
#include <time.h>
#include <stdio.h>
#include <unistd.h>

void lower_player_life(client_t *client, time_t current_time, int freq,
    int gui)
{
    int check = (current_time - client->survival_time) / (LIFE_UNIT /
    freq);

    if (client->fd == gui || client->fd == -1)
        return;

    if (client->inventory.food <= 0)
        return;

    if (current_time - client->survival_time >= LIFE_UNIT / freq) {
        client->inventory.food -= check;
        client->inventory.food = client->inventory.food < 0 ? 0 :
        client->inventory.food;
        client->survival_time = current_time;
    }
}

void set_player_dead(serv_t *serv, int gui)
{
    for (size_t i = 0; i < serv->max_clients; ++i) {
        if (serv->clients[i].fd == -1 || serv->clients[i].fd == gui)
            continue;
        if (serv->clients[i].inventory.food <= 0) {
            printf("Client %d, team %d just died\n", serv->clients[i].fd,
            serv->clients[i].team_index);
            clear_fd_sets(&serv->sets, serv->clients[i].fd);
            dprintf(serv->clients[i].fd, "dead\n");
            close(serv->clients[i].fd);
            free_cmd_queue(&serv->clients[i].client_cmd_queue);
            serv->clients[i] = init_new_client(-1, serv);
        }
    }
}

void handle_players_life(serv_t *serv)
{
    client_t *clients = serv->clients;
    time_t current_time = time(NULL);

    if (clients == NULL)
        return;
    int gui_fd = get_gui_fd(serv->clients, serv->max_clients);

    for (size_t i = 0; i < serv->max_clients; ++i) {
        if (clients[i].fd == -1 || clients[i].fd == gui_fd)
            continue;
        lower_player_life(&clients[i], current_time, serv->param->freq, gui_fd);
    }
    set_player_dead(serv, gui_fd);
}
